	.text		
 	
	.globl _Lab2main
 

_Lab2main:		# execution starts here

loop: 	
	add  $t0, $zero, $zero
	add  $t1, $zero, $zero
	add  $t2, $zero, $zero
	add  $t3, $zero, $zero
	add  $t4, $zero, $zero
	add  $t5, $zero, $zero
	add  $t6, $zero, $zero
	add  $t7, $zero, $zero
	add  $t8, $zero, $zero
	add  $t9, $zero, $zero
	add  $s0, $zero, $zero
	add  $s1, $zero, $zero
	add  $s3, $zero, $zero
	
	la $a0,inp1
	li $v0, 4
	syscall
	li $v0, 6
	syscall
	s.s $f0, num1
	mfc1 $s0, $f0
	
	la $a0,inp2
	li $v0, 4
	syscall
	li $v0, 6
	syscall
	s.s $f0, num2
	mfc1 $s1, $f0
		
	##########################################################################
	# For multiplying;
	# | 1 bit  | 8 bits     | 23 bits                 |
	# | sign   | exponent   | mantissa                |
	#
	# Xor the sign bits of 2 numbers, store in 31th bit of register1
	# Add the exponents of 2 numbers, store in [30:23] bits of register2
	# Multiply the mantissas of 2 numbers, store in [22:0] bits of register3
	# Add register1, register2 and register3 to get result
	##########################################################################
	
	
	#Get the sign bits of the num1 and num2 with masking others
	andi $t0, $s0, 0x80000000
	andi $t1, $s1, 0x80000000
	#Sign bit of the result is stored in msb
	xor $t0, $t0, $t1
	
	#Get the exponent bits of the num1 and num2 with masking
	andi $t1, $s0, 0x7F800000
	andi $t2, $s1, 0x7F800000
	#Exponent of the result is stored in [30:23],subtract one of the bias because there are 2 biases
	addi $t2, $t2, -0x3F800000
	add $t1, $t1, $t2
	addi $t1,$t1, 0x00800000  
	
	#Get the mantissas of the 2 numbers with masking
	andi $t2, $s0, 0x007FFFFF
	andi $t3, $s1, 0x007FFFFF
	addi $t2, $t2, 0x00800000
	addi $t3, $t3, 0x00800000

	#Multiply the mantissas, get the msb 32 bits and store the result
	mult $t2, $t3
	mfhi $t2 #hi
	mflo $t4 #lo
	
	#Counting the leading 0's 
	addi $t7, $0, -1 #Count how many 0 
	addi $t8, $0, 0x80000000 
loopi: 
	and $t9, $t2, $t8 
	srl $t8, $t8, 1 
	addi $t7, $t7, 1 
	beq $t9, $0, loopi 
	################################
	addi $t7, $t7, 1
	
	sllv $t2, $t2, $t7
	
	addi $s3, $s3, 32
	sub $t7, $s3, $t7
		
	srlv $t4, $t4, $t7
	
	add $t2, $t2, $t4
	
	srl $t2, $t2, 9

	##################################
	or $t0, $t1, $t0
	or $t2, $t0, $t2 #Now result is stored in $t2
	
	mtc1 $t2, $f0
	
	movf.s $f12, $f0
	li $v0,2 # Print the contents of register $f12.
	syscall
	
	la $a0,correct
	li $v0, 4
	syscall
	
	mtc1 $s0, $f1
	mtc1 $s1, $f2
	mul.s $f12, $f1, $f2
	li $v0, 2
	syscall
	
	
	j loop
	.data	
inp1: .asciiz "\nEnter the first input: "
inp2: .asciiz "Enter the second input: "
correct: .asciiz "\nCorrect result is: "
num1: .word 0
num2: .word 0
