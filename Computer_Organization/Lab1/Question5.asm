.data
prompt:	.asciiz "Enter the x: "
prompt2:.asciiz "Enter the y: "
prompt3:.asciiz "The result 'a' is equal to: "

.text	
	#Prompt message for x
	la $a0,prompt
	li $v0, 4
	syscall
	#Get the x
	li $v0, 5
	syscall
	move $s0, $v0
	#Prompt message for y
	la $a0, prompt2
	li $v0, 4
	syscall
	#Get the y
	li $v0, 5
	syscall
	move $s1, $v0
	
	#Subtract
	sub $t0, $s0, $s1
	#Store 4 in register t1
	addi $t1, $t1, 4
	
	#Euclid Algorithm for finding the modulo of the 2 numbers.
LOOP:	slt $t2, $t0, $t1
	bne $t2, $zero, EXIT
	sub $t0, $t0, $t1
	j LOOP
	
EXIT: 	#Prompt message for result
	la $a0, prompt3
	li $v0, 4
	syscall
	#Print the result
	la $a0, ($t0)
	li $v0, 1
	syscall
	



