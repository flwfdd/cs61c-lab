.globl factorial

.data
n: .word 8

.text
# Don't worry about understanding the code in main
# You'll learn more about function calls in lecture soon
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

# factorial takes one argument:
# a0 contains the number which we want to compute the factorial of
# The return value should be stored in a0
factorial:
    # YOUR CODE HERE
    addi t0 x0 1 # ans
    addi t1 x0 0 # i
    main_loop:
        addi t1 t1 1 # i=i+1
        addi t3 x0 0
        mv t2 t1 # m
        mul_loop:
            add t3 t3 t0
            addi t2 t2 -1 # m--
            bne t2 x0 mul_loop # m!=0
        mv t0 t3
        blt t1 a0 main_loop # if i<n
    mv a0 t0
    
    # This is how you return from a function. You'll learn more about this later.
    # This should be the last line in your program.
    jr ra
