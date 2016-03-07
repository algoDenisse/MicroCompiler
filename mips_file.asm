.data
    A: .word 0 
    B: .word 0 
    B: .word 0 
    Temp1: .word 0 
.text
    main:
    li $a0, 2
    sw $a0, A
    li $a0, 3
    sw $a0, B
    lw $a0, A
    lw $a1, B
    add $v0, $a0, $a1
    sw $v0, Temp1
    li $v0, 1
    lw $a0, Temp1 
    syscall 
    la $v0, 10
    syscall
