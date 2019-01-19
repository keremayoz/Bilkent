.data
prompt:	.asciiz "Enter the size of the array(max 20): "
message: .asciiz "Enter the numbers: "
newLine: .asciiz "\n"

.text		
.globl start

start:
	#Prompt message for array size
	la $a0,prompt
	li $v0, 4
	syscall
	
	#Get the array size
	li $v0, 5
	syscall
	
	#Store the size 
	move $s0, $v0
	#Create the array by choosing the base address
	li $s1, 0x10040000
	#Save base address to iterate in loop
	move $t0, $s1
	#Index for traversing
	addi $t1, $zero, 0
	#Register to keep sum of the numbers
	addi $s2, $zero, 0
	
LOOP:	#Prompt message for array contents
	la $a0,message
	li $v0, 4
	syscall
	
	#Get the array content
	li $v0, 5
	syscall
	#Update sum
	add $s2, $s2, $v0
	#Store the numbers in memory	
	sw $v0, 0($t0)
	   addi $t0, $t0, 4
	   addi $t1, $t1, 1
	bne $t1, $s0, LOOP
	
 	#Reset the temporary base address and index to traverse again
	move $t0, $s1
	addi $t1, $zero, 0

CALCULATE: div $s3, $s2, $s0 #Average stored in s3
		
DISPLAY: lw $t2, 0($t0)
	 #Display the array content
	 la $a0, ($t2)
	 li $v0, 1
	 syscall
	 
	 #To print space between elements
	 li $a0, 32
	 li $v0, 11  
	 syscall
	 
	 #Calculate the difference
	 sub $t3, $t2, $s3 
	 
	 #Display the differences
	 la $a0, ($t3)
	 li $v0, 1
	 syscall
	 
	 #Print new Line
	 la $a0, newLine
	 li $v0,4
	 syscall
	 
	 #Update indexes
	 addi $t0, $t0, 4
	 addi $t1, $t1, 1
	 bne $t1, $s0, DISPLAY
