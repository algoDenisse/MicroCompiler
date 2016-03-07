.data
    a: .word 0 
    Temp1: .word 0 
    b: .word 0 
    Temp2: .word 0 
    r: .word 0 
    Temp3: .word 0 
.text
    main:
    li $v0, 5
    syscall
    sw $v0, a
    li $v0, 5
    syscall
    sw $v0, b
    lw $a0, a
    li $a1, 12
    add $v0, $a0, $a1
    sw $v0, Temp1
    li $v0, 1
    lw $a0, Temp1 
    syscall 
    lw $a0, b
    li $a1, 23
    add $v0, $a0, $a1
    sw $v0, Temp2
    li $v0, 1
    lw $a0, Temp2 
    syscall 
    lw $a0, r
    li $a1, 98
    add $v0, $a0, $a1
    sw $v0, Temp3
    lw $a0, Temp3
    sw $a0, a
    li $v0, 1
    lw $a0, a 
    syscall 
    la $v0, 10
    syscall
