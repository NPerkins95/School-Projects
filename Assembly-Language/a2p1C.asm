##########################################################################
# Nathan Perkins, CS 2318-002, Assignment 2 Part 1 Program C
##########################################################################
# Loads into registers, Swaps content, and Displays Array
############################ data segment ################################
		.data
intArr:		.word 7, 9, 3, 8, 5
origLab:	.asciiz ": Is the original array"
editLab:	.asciiz ": Is the array with swapped content(elements 1&3, 2&5) in decending order"
############################ code segment ################################
		.text
		.globl main
main:
		###########################################################
		############## Load intArr to registers (1-5) #############
		la $t0, intArr
		lw $t1, 0($t0)
		lw $t2, 4($t0)
		lw $t3, 8($t0)
		lw $t4, 12($t0)
		lw $t5, 16($t0)
		###########################################################
		################## Print original intArr ##################
		li $v0, 1
		move $a0, $t1
		syscall
		move $a0, $t2
		syscall
		move $a0, $t3
		syscall
		move $a0, $t4
		syscall
		move $a0, $t5
		syscall
		li $v0, 4		
		la $a0, origLab		
		syscall
		###########################################################
		
		li $v0, 11
		li $a0, '\n'
		syscall
		
		sw $t1, 8($t0)		#stores contents of $t1 into 3rd element of intArr 
		sw $t3, 0($t0)		#stores contents of $t3 into 1st element of intArr
		
		sw $t2, 16($t0)		#stores contents of $t2 into 5th element of intArr
		sw $t5, 4($t0)		#stores contents of $t5 into 2nd element of intArr
		
		###########################################################
		############## Load intArr to registers (5-1) #############
		la $t0, intArr
		lw $t5, 0($t0)
		lw $t4, 4($t0)
		lw $t3, 8($t0)
		lw $t2, 12($t0)
		lw $t1, 16($t0)
		###########################################################
		######### Print swapped $ 5th to 1st order intArr #########
		li $v0, 1
		move $a0, $t1
		syscall
		move $a0, $t2
		syscall
		move $a0, $t3
		syscall
		move $a0, $t4
		syscall
		move $a0, $t5
		syscall
		li $v0, 4		
		la $a0, editLab		
		syscall
		###########################################################	
                ########################## exit ###########################
                li $v0, 10
                syscall
