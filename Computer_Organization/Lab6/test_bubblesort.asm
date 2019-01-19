################################################

##

##  Main program to create an array of random integers,

##   then sort them using bubble sort

##

##   $s0 contains the address of the array

##   $s1 is the number of integers in the array

##

################################################


	.text

start:	la $t0, size		# put address 'size' into reg $t0

	lw $s1, 0($t0)		# reg $s1 = value from 'size'



## get allocation of dynamic memory from operating system

	move $a0, $s0		# amount of words to allocate

	sll $a0, $a0, 2		# amount of bytes to allocate

	li $v0, 9		# 9 means sbrk (allocate heap memory)

	syscall

	move $s0, $v0		# reg $s0 = address of the memory allocated



## set up the pseudo-random number generator with intial seed

	li $a0, 1		# choose pseudo-random generator #1

	li $a1, 13		# seed = 13

	li $v0,40		# 40 means set seed

	syscall



## fill allocated memory array with random integer values

## for (i=0; i<size; i++) array[i] = random_integer


	li $t0, 0		# i = 0

fill_top:
 li $a0, 1		# choose pseudo-random generator #1
	
li $v0,41		# 41 means random int (reg $a0 will contain the

	syscall			#   next pseudo-random integer)

	sll $t1, $t0, 2		# reg $t1 = i*4 (byte offset)

	add $t1, $s0, $t1	# reg $t1 = address of array[i]

	sw $a0, 0($t1)		# store random integer to array[i]

	addi $t0, $t0, 1	# i++

	slt $t1, $t0, $s1	# reg $t1=1 if $t0<$s1 (if i<size)

	bne $t1, $zero, fill_top # if $t1=1 (if i<size), continue to fill the array



## output the message "The array has been filled with random integers."

	la $a0, msg1		# put address 'msg1' into reg $a0

	li $v0,4		# 4 means print string

	syscall			



## sort the arrray using bubble sort

	move $a0, $s0		# load 1st parameter with address of array

	move $a1, $s1		# load 2nd parameter with number of elements

	jal bubblesort		# call the sort routine



## output the message "The array of integers is sorted. I'm done!", and exit

	la $a0, msg2		# put address 'msg2' into reg $a0

	li $v0,4		# 4 means print string

	syscall
	li $v0, 10		# 10 means exit

	syscall			# Good bye !




########################################
## bubble sort program in MIPS
## 
## implements this C algorithm:
##	void bubblesort (int v[], int n)
##	{
##	    int i, j;
##	    for (i = 0; i < n; i += 1)
##		for (j = i-1; j >= 0 && v[j] > v[j+1]; j-=1)
##		    swap (v,j);
##	}
##
## which uses this swap routine:
##	void swap (ont v[], int k)
##	{
##	    int temp;
##	    temp = v[k];
##	    v[k] = v[k+1];
##	    v[k+1] = temp;
##	}
##
########################################

bubblesort: 	
	addi $sp, $sp, -20	# make room on stack for 5 register values
	sw $ra, 16($sp)		# save $ra on stack
	sw $s3, 12($sp)		# save $s3 on stack
	sw $s2,  8($sp)		# save $s2 on stack
	sw $s1,  4($sp)		# save $s1 on stack
	sw $s0,  0($sp)		# save $s0 on stack

	move $s2, $a0		# save $a0 into $s2
	move $s3, $a1		# save $a1 into $s3

## outer loop
	li $s0, 0		# i = 0
for1tst:slt $t0, $s0, $s3	# reg $t0=0 if $s0 >= $s3 (i < n)
	beq $t0, $zero, exit1	# go to exit1 if $s0 >= $s3 (i < n)

## inner loop
	addi $s1, $s0, -1	# j = j - 1
for2tst:slti $t0, $s1, 0	# reg $t0=1  if $s1 < 0 (j < 0)
	bne $t0, $zero, exit2	# go to exit2 if $s1 < 0 (j < 0)
	sll $t1, $s1, 2		# reg $t1 = j * 4
	add $t2, $s2, $t1	# reg $t2 = v + (j * 4)
	lw $t3, 0($t2)		# reg $t3 = v[j]
	lw $t4, 4($t2)		# reg $t4 = v[j+1]
	slt $t0, $t4, $t3	# reg $t0 = 0 if $t4 >= $t3
	beq $t0, $zero, exit2	# go to exit2 if $t4 >= $t3

## pass parameters and call swap
	move $a0, $s2		# 1st parameter of swap is v (old $a0)
	move $a1, $s1		# 2nd parameter of swap is j
	jal swap		# swap code is given below

## inner loop bottom
	addi $s1, $s1, -1	# j -= 1
	j for2tst		# jump to test as top of inner loop

## outer loop bottom
exit2:	addi $s0, $s0, 1	# i += 1
	j for1tst		# jump to test as top of outer loop

## restore stack and return
exit1:	lw $ra, 16($sp)		# restore $ra from stack
	lw $s3, 12($sp)		# restore $s3 from stack
	lw $s2,  8($sp)		# restore $s2 from stack
	lw $s1,  4($sp)		# restore $s1 from stack
	lw $s0,  0($sp)		# restore $s0 from stack
	addi $sp, $sp, 20	# restore stack pointer
	jr $ra			# return to calling routine


swap:	sll $t1, $a1, 2		# reg $t1 = k * 4
	add $t1, $a0, $t1	# reg $t1 = v + (k * 4) the address of v[k]
	lw $t0, 0($t1)		# reg $t0 has v[k]
	lw $t2, 4($t1)		# reg $t2 has v[k+1]
	sw $t2, 0($t1)		# v[k] has value of $t2 (v[k+1])
	sw $t0, 4($t1)		# v[k+1] has value of $t0 (v[k])
	jr $ra			# return to calling routine




	.data

size:	.word 750		# size of the array is given here in this constant

msg1:	.asciiz "The array has been filled with random integers.\n"

msg2:	.asciiz "The array of integers is sorted. I'm done!\n"

		
