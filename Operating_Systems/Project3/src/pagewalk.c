#include <linux/init.h>             
#include <linux/module.h>           
#include <linux/kernel.h> 
#include <linux/errno.h> 
#include <linux/sched.h>
#include <asm/pgtable.h> 
#include <asm/page.h>   
#include <linux/proc_fs.h>
#include <linux/mm.h>     

MODULE_LICENSE("GPL");              
MODULE_AUTHOR("Kerem & Cansu");   
MODULE_DESCRIPTION("Module that does page walk through the given processid."); 
MODULE_VERSION("3.0");             
static int processid = 0;
module_param(processid, int, 0);

static unsigned long virtaddr = 0;
module_param(virtaddr, long, 0);


int count = 0; // Page counter

static void pte_table_lookup(pmd_t *pmd, unsigned long addr, unsigned long end) {
	pte_t *pte;
	unsigned long m = 0;
	unsigned long pfn;
	struct page *page = NULL;

	pte = pte_offset_map(pmd, addr);
	do {
		if (pte_none(*pte)) {
			//printk("Invalid Entry: %d\n",m++);
		}
		else {
			printk("Valid PTE entry: %lu\n", m++);   	
			pfn = pte_pfn(*pte);
			page = pte_page(*pte);
			count++;
			printk("Frame number is:# %lu\n", pfn);   	
			printk("Physical address is : 0x%p\n", page);   				  			  
		} 
		addr += PAGE_SIZE;
		pte++;
	} while(addr < end);
	pte_unmap(pte);
}

static void pmd_table_lookup(pud_t *pud, unsigned long addr, unsigned long end) {
	pmd_t *pmd;
	unsigned long k = 0;
	unsigned long next;

	pmd = pmd_offset(pud, addr);
	do {
		next = pmd_addr_end(addr, end);
		if (pmd_none(*pmd) || pmd_bad(*pmd)) {
			//printk("Invalid Entry: %d\n",k++);
		} 		
		else {
			printk("Valid PMD Entry: %lu\n",k++);
			pte_table_lookup(pmd ,addr, next); 
		}
		addr = next;
		pmd++;
	} while (addr < end);
}

static void pud_table_lookup(pgd_t *pgd, unsigned long addr, unsigned long end) {
	pud_t *pud;
	unsigned long j = 0;
	unsigned long next;

	pud = pud_offset(pgd, addr);
	do {
		next = pud_addr_end(addr, end);
		if (pud_none(*pud) || pud_bad(*pud)) {
			//printk("Invalid Entry: %d\n",j++);
		}
		else {
			printk("Valid PUD Entry: %lu\n",j++);
			pmd_table_lookup(pud, addr, next);
		} 
		addr = next;
		pud++;
	} while(addr < end);
}

static void pgd_table_lookup(struct task_struct *cur_task, unsigned long addr, unsigned long end) {
	pgd_t *pgd;
	unsigned long i = 0;
	unsigned long next;

	pgd = pgd_offset(cur_task->mm, addr);
	do {
		next = pgd_addr_end(addr, end);
		if (pgd_none(*pgd) || pgd_bad(*pgd)) {
			//printk("Invalid Entry: %d\n",i++);
		}
		else {
			printk("Valid PGD Entry: %lu\n",i++);
			pud_table_lookup(pgd, addr, next);
		}
		addr = next;
		pgd++;
	} while (addr < end);
}

static void page_walk(struct task_struct *cur_task) {
	unsigned long start, end;
	struct vm_area_struct *cur_vm;

	cur_vm = cur_task->mm->mmap;
	start = cur_vm->vm_start;
	 
	while(cur_vm->vm_next)
       	cur_vm = cur_vm->vm_next;

	end = cur_vm->vm_end;
	
	pgd_table_lookup(cur_task, start, end);
	printk("Page count: %d\n",count);
}

static void vm_area_information(struct task_struct *cur_task) {
	struct vm_area_struct *cur_vm;
	cur_vm = cur_task->mm->mmap; 
	while(cur_vm->vm_next){
       	cur_vm = cur_vm->vm_next;
	}

	printk("Code_start: 0x%lu Code_end: 0x%lu Code_size: %lu bytes\n", cur_task->mm->start_code,cur_task->mm->end_code,cur_task->mm->end_code-cur_task->mm->start_code);
	printk("Data_start: 0x%lu Data_end: 0x%lu Data_size: %lu bytes\n", cur_task->mm->start_data,cur_task->mm->end_data,cur_task->mm->end_data-cur_task->mm->start_data);
	printk("Stack_start: 0x%lu Stack_end: 0x%lu Stack_size: %lu bytes\n", cur_task->mm->start_stack,cur_vm->vm_end,cur_vm->vm_end-cur_task->mm->start_stack);
	printk("Heap_start: 0x%lu Heap_end: 0x%lu Heap_size: %lu bytes\n", cur_task->mm->start_brk,cur_task->mm->brk,cur_task->mm->brk-cur_task->mm->start_brk);
	printk("Argument_start: 0x%lu Argument_end: 0x%lu Argument_size: %lu bytes\n", cur_task->mm->arg_start,cur_task->mm->arg_end,cur_task->mm->arg_end-cur_task->mm->arg_start);
	printk("EV_start: 0x%lu EV_end: 0x%lu EV_size: %lu bytes\n", cur_task->mm->env_start,cur_task->mm->env_end,cur_task->mm->env_end-cur_task->mm->env_start);
	printk("RSS: %lu\n", cur_task->mm->hiwater_rss);
	printk("Total_VM: %lu pages\n", cur_task->mm->total_vm);
}

static void address_translation(struct task_struct *cur_task,unsigned long virtaddr) {
	pgd_t *pgd;
    pud_t *pud;
	pmd_t *pmd;
	pte_t *pte;
	
	struct page *page = NULL;

	pgd = pgd_offset(cur_task->mm,virtaddr);
	if (pgd_none(*pgd) || pgd_bad(*pgd)) 
		printk("Invalid Virtual Address");
	else {
		pud = pud_offset(pgd, virtaddr);
		if (pud_none(*pud) || pud_bad(*pud)) 
			printk("Invalid Virtual Address");	
		else {
			pmd = pmd_offset(pud,virtaddr);
			if (pmd_none(*pmd) || pmd_bad(*pmd)) 
				printk("Invalid Virtual Address");
			else {
				pte = pte_offset_map(pmd,virtaddr);
				if (pte_none(*pte)) 
					printk("Invalid Virtual Address");
				else {
					page = pte_page(*pte);
					printk("Physical Address: 0x%p\n", page);     				  
				} // else pte
			} // else pmd
		} // else pud
	} // else pgd
}

static int __init hello_init(void){
	struct task_struct *task = current;
  	struct task_struct *cur_task;

  	printk("Current process = %s, Current pid = %d\n",task->comm, task->pid);

  	for_each_process(cur_task) {
  		if (cur_task->pid == processid)
  			break;
    }
	printk("Given process: %s [%d]\n",cur_task->comm , cur_task->pid);

	// STEP 1
	vm_area_information(cur_task);

	// STEP 2
	page_walk(cur_task);
  	
  	// STEP 3

  	// STEP 4
  	address_translation(cur_task, cur_task->mm->start_code);
	
	// Done
  	printk("Hello by Kerem & Cansu %d\n", processid);
   	return 0;
}

static void __exit hello_exit(void){
	printk("Goodbye by Kerem & Cansu\n");
}

module_init(hello_init);
module_exit(hello_exit);