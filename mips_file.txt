.data
    A: .word 0 
    B: .word 0 
    Temp&1: .word 0 
.text
    main:
    li $a0, 2
    sw $a0, A
    li $a0, 3
    lw $a1, A
    sub $v0, $a0, $a1
    sw $v0, Temp&1
    lw $a0, Temp&1
    sw $a0, B
    la $v0, 10
    syscall
