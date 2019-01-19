.text
addi $v0, $zero, 0x0005
addi $v1, $zero, 0x000C
addi $a3, $v1, 0xFFF7
or $a0, $a3, $v0
and $a1, $v1, $a0
add $a1, $a1, $a0
beq $a1, $a3, jump1
slt $a0, $v1, $a0
beq $a0, $zero, jump2
addi $a1, $zero, 0
jump2: slt $a0, $a3, $v0
add $a3, $a0, $a1
sub $a3, $a3, $v0
sw $a3, 68 ($v1)
lw $v0, 80 ($zero)
j jump1
addi $v0, $zero, 1
jump1: sw $v0, 84 ($zero)
here: j here

lui $t0, 0x2222