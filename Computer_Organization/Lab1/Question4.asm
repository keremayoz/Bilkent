.data
prompt: .asciiz "String to be checked: "
string: .space 80
true: .asciiz "Yes it is palindrome"
false: .asciiz "No it is not palindrome"

.text

	#Prompt message for string
	la $a0,prompt
	li $v0, 4
	syscall
	
	#Taking string input
	la $a0, string
	li $a1, 50
	li $v0, 8
        syscall

	addi $t1, $a0, 0
	#For counting size
	addi $t5, $zero, 0
	
LOOP:	
	lb $t0, 0($t1)
	beq $t0, $zero, continue #check if it is last
	addi $t5, $t5, 1 #increment counter
	addi $t1, $t1, 1 #increment address
	j LOOP
	
continue: 
	move $a1, $t5 #Assign the new size
        #Function call
	jal isPalindrome
	
isPalindrome:
	#Base case: length less than 2
	slti $t0, $a1, 2
	bne $t0, $zero, exitTrue
	#Checking the equality of the first and the last character
	lb $t1, 0($a0)
	add $t2, $a0, $a1
	lb $t2, -2($t2)
	bne $t2, $t1, exitFalse
	#Move pointers
	addi $a0, $a0, 1
	addi $a1, $a1, -2
	j isPalindrome
	 
#Returning true
exitTrue:
	la $a0,true
	li $v0, 4
	syscall
	j end
	
#Returning false
exitFalse: 
	la $a0,false
	li $v0, 4
	syscall
	
#Program ending
end:
	