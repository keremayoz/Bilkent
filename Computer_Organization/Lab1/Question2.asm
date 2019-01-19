.data
midterm: .asciiz "Enter your midterm grade: "
quiz: .asciiz "Enter your quiz average: "
lab: .asciiz "Enter your lab average: "
final: .asciiz "Enter your final grade: "
pfailed: .asciiz "You have failed from the course :'(("
pD: .asciiz "You get grade D :("
pC: .asciiz "You get grade C :I"
pB: .asciiz "You get grade B :)"
pA: .asciiz "You get grade A :D"

.text
	#Create the array
	addi $s0, $s0, 0x1004
	sll $s0, $s0, 16
	ori $s0, $s0, 0x0000
	
	#Prompt message for midterm,quiz,lab and final. And save as array
	la $a0,midterm
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	sw $v0, 0($s0)
	
	la $a0,quiz
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	sw $v0, 4($s0)
	
	la $a0,lab
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	sw $v0, 8($s0)
	
	la $a0,final
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	sw $v0, 12($s0)
	
	#Calculate the average grade. Load the values and calculate each.
	addi $t8, $t8, 10
	
	#Midterm
	lw $s1, 0($s0)
	sll $t0, $s1, 1
	add $t0, $t0, $s1
	div $t0, $t8
	mflo $t0
	#Quiz
	lw $s1, 4($s0)
	move $t1, $s1
	div $t1, $t8
	mflo $t1
	#Lab
	lw $s1, 8($s0)
	sll $t2, $s1, 1
	add $t2, $t2, $s1
	div $t2, $t8
	mflo $t2
	#Final
	lw $s1, 12($s0)
	sll $t3, $s1, 1
	add $t3, $t3, $s1
	div $t3, $t8
	mflo $t3
	
	#Calculating total
	add $s1, $t0, $t1
	add $s1, $s1, $t2
	add $s1, $s1, $t3
	
	li $s2, 0x00000037 #Curve 55
	li $s3, 0x00000041 #Grade D
	li $s4, 0x0000004B #Grade C
	li $s5, 0x00000055 #Grade B
	li $s6, 0x00000064 #Grade A
	
	slt $t5, $s1, $s2
	bne $t5, $zero, failed
	slt $t5, $s1, $s3
	bne $t5, $zero, D
	slt $t5, $s1, $s4
	bne $t5, $zero, C
	slt $t5, $s1, $s5
	bne $t5, $zero, B
	slt $t5, $s1, $s6
	bne $t5, $zero, A
	
	failed:
		la $a0,pfailed
		li $v0, 4
		syscall
		j end
	D:
		la $a0,pD
		li $v0, 4
		syscall
		j end
	C:
		la $a0,pC
		li $v0, 4
		syscall
		j end
	B:
		la $a0,pB
		li $v0, 4
		syscall
		j end
	A:
		la $a0,pA
		li $v0, 4
		syscall
		j end
	end:
 
