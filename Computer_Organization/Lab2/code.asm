###################################################################
##	TODO: Kerem Ayoz
##
##	_Lab2main - a program that calls linked list utility functions,
##		 depending on user selection.  _Lab2main outputs a 
##		message, then lists the menu options and get the user
##		selection, then calls the chosen routine, and repeats
##
##	a0 - used for input arguments to syscalls and for passing the 
##		pointer to the linked list to the utility functions
##   

##	TODO: Add other registers and their description as needed!
##	s0 - used for storing the head pointer of the linked list. 
##	s1 - used for current pointer in traversals.
##	t0, t1, t2, t3, t4 - temporary registers used in functions
##	t0 - used to store the size of the array
##	v0 - used for syscalls and inputs
##	v1 - used for returning the starting address of the linked list in create_list

##      linked list consists of 0 or more elements, in 

##		dynamic memory segment (i.e. heap)

##	elements of the linked list contain 2 parts:

##		at address z: pointerToNext element (unsigned integer), 4 bytes

##		at address z+4: value of the element (signed integer), 4 bytes

##
##

###################################################################
#
#					 	
#
#		text segment			
#
#						
#
####################################################################


	
	.text		
 	
	.globl _Lab2main
 

_Lab2main:		# execution starts here

loop: 	la $a0,welcome
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	
	addi $sp, $sp, -16
	sw $t1, ($sp)
	sw $t2, 4($sp)
	sw $t3, 8($sp)
	sw $t4, 12($sp)

	beq $v0, 2, display
     	beq $v0, 1, create
	beq $v0, 3, lookup
	beq $v0, 4, insert
	beq $v0, 5, reverse
	
display:jal display_list
	j lookup
create: jal create_list
	j lookup 
insert: jal insertBeforeValue
	j lookup
reverse: jal reverse_list	
	
lookup:	
	lw $t1, ($sp)
	lw $t2, 4($sp)
	lw $t3, 8($sp)
	lw $t4, 12($sp)
	addi $sp, $sp, 16
	bne $v0, 3, loop
	j EXIT
	

##################################################################
#### insertBeforeValue - a linked list utility routine, 
##			which adds element to the beginning 
##	
## int n -- > head of the list
## int x -- > value that is inserted
################################################################# 
insertBeforeValue: 
	#Ask for the element
	la $a0,newElement
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	
	move $t4, $v0 #save the element to the $t0
	
	#Allocate new memory address
	li $v0, 9
	li $a0, 8
	syscall
	
	move $t2, $v1 #Create a temporary register for pointer manipulation
	addi $v1, $v0, 0 #Manipulate the head pointer. It now points new element
	
	sw $t2, ($v1) #Assign the new element's next pointer to the first element
	
	sw $t4, 4($v1) #Put the value inside the new element
	
	addi $t0, $t0, 1 #Increment the size
	jr $ra

###################################################################
##
#### reverse_list - a linked list utility routine, 
##			which reverses the list
##	
##
##	TODO: Add other registers and their description as needed!
##
##################################################################  
reverse_list:

	addi $t4, $zero, 2
	beq $t0, $t4, size2
	addi $t4, $zero, 1
	ble $t0, $t4, endd
	 
	move $t1, $v1 #prev pointer
	lw $t2, ($t1) #current pointer
	lw $t3, ($t2) #next pointer
	

rvrsl: 	sw $t1, ($t2)
	move $t1, $t2
	move $t2, $t3
	lw $t3, ($t3)
	
	bne $t3, $zero, rvrsl
	
	sw $t1, ($t2)
	move $t1, $t2
	move $t2, $t3
	
	#Must case for all
	sw $zero, ($v1) #Update the next of the last as 0
	move $v1, $t1 #Assign the new head which is old last element
	j end
size2: 
	#If size is equal to 2, just use 2 pointers and swap the values
	lw $t2, ($v1) #current pointer
	#Swap
	sw $v1, ($t2) 
	#Must case for all
	sw $zero, ($v1) #Update the next of the last as 0
	move $v1, $t2 #Assign the new head which is old last element
	
endd:	jr $ra
###################################################################
##
#### create_list - a linked list utility routine, 
##			which creates the contents, element 
##			by element, of a linked list
##
##	TODO: Add other registers and their description as needed!
##
##################################################################   


create_list:		# entry point for this utility routine
	addi $sp, $sp, -8  # make space on stack
  	sw  $s0, 0($sp) # save registers to stack because they are preserved
  	sw $s1, 4($sp)
  	
  	#Ask for the size
	la $a0,sizeQuery
	li $v0, 4
	syscall
	li $v0, 5
	syscall

	move $t0, $v0 #Size of the linked list
	addi $t1, $zero, 1 #Index for creation
	
	#Allocate the memory for the first element of the linked list
	li $v0, 9
	li $a0, 8
	syscall
	move $s0, $v0 #$s0 assigned as the head pointer of the Linked List
	move $s1, $s0 #current pointer for traversing
	
crt:	slt $t2, $t1, $t0
	beq $t2, $zero, med
	
	#Allocate memory for each and every element
	li $v0, 9
	li $a0, 8 # allocates 8 bytes: 4 bytes for the next pointer, 4 bytes for the next data
	syscall
	
	#Insert the next pointer of the current element	
	sw $v0, ($s1)
	move $s1, $v0
	addi $t1, $t1, 1
	j crt
	
	#Medium stage
med:	addi $t1, $zero, 0
	sw $zero, ($s1) #Set the last of the next to null
	move $s1, $s0
	
	#Data Insert Stage
di:	slt $t2, $t1, $t0
	beq  $t2, $zero, finish
	
	#Ask for the element
	la $a0,elementQuery
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	
	sw $v0, 4($s1) #Saving data to memory
	
	lw $t3, ($s1) #Updating the current pointer
	move $s1, $t3
		
	addi $t1, $t1, 1
	j di

finish:
	move $v1, $s0 #Returning the head of the pointer (Size is in $t0)
	lw  $s0, 0($sp) # restore $s0 from stack
	lw  $s1, 4($sp) 
 	addi $sp, $sp, 8   
	jr $ra
##################################################################
#### display_list - a linked list utility routine, 
##			which shows the contents, element 
##			by element, of a linked list
##
##	TODO: Add other registers and their description as needed!
##
################################################################# 
  


display_list:		# entry point for this utility routine
	
	addi $sp, $sp, -8  # make space on stack
  	sw  $s0, 0($sp) # save registers to stack because they are preserved
  	sw $s1, 4($sp)
  	
	move $t1, $zero #Index for traversing
	move $t3, $v1 #Current pointer in traverse
	
	#Displaying the Data
dl: 	slt $t2, $t1, $t0
	beq  $t2, $zero, end
	
	#Print the result
	lw $a0, 4($t3)
	li $v0, 1
	syscall
	
	#Print comma between elements
	la $a0, comma
	li $v0,4
	syscall
	
	lw $t4, ($t3) #Updating the current pointer
	move $t3, $t4
	addi $t1, $t1, 1 #Updating index
	j dl

end:
	#Print new line
	la $a0, newLine
	li $v0,4
	syscall
	lw  $s0, 0($sp) # restore $s0 from stack
	lw  $s1, 4($sp) 
 	addi $sp, $sp, 8  
	jr $ra
	
	
# EXIT of the program
EXIT: li $v0, 10
      syscall

################################################
#
#
#
#     	 	data segment			
#
#						
#
#
################################################


	 .data

msg1:    .asciiz "The linked list has been completely displayed. \n"
welcome: .asciiz "Welcome to the Linked List Program\nSelect the option\n1-) Create a Linked List\n2-) Display the Linked List\n3-) Exit\n4-) Insert to the beginning\n5-) Reverse the list\n"
sizeQuery: .asciiz "Enter the size of the Linked List you want to create: "
elementQuery: .asciiz "Enter the elements: "
newElement: .asciiz "Enter the new element to insert: "
newLine: .asciiz "\n"
comma: .asciiz", " 
##

## end of main
