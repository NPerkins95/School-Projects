############################################################################
# Nathan Perkins, CS 2318-002, Assignment 2 Part 1 Program D
############################################################################
# Compute/display average score of 3 specified tests with different weights
# Formula: Avg = (512/2558)*e1 + (614/2048)*e2 + F/2
############################ data segment ##################################
			.data
promptExam1:		.asciiz "Enter score for Exam 1: "
promptExam2:		.asciiz "Enter score for Exam 2: "
promptFinal:		.asciiz "Enter score for Final Exam: "

outLab:			.asciiz "Avg score is: "
#testLab1:		.asciiz "Exam1: "
#testLab2:		.asciiz "Exam2: "
#testLab3:		.asciiz "Final: "
############################### code segment ###############################
			.text
			.globl main
main:
			###########################################################
			################# Prompt for Exam 1 value #################
			li $v0, 4		
			la $a0, promptExam1		
			syscall
			li $v0, 5
			syscall
			move $t1, $v0
			###########################################################
			################# Prompt for Exam 2 value #################
			li $v0, 4		
			la $a0, promptExam2		
			syscall
			li $v0, 5
			syscall
			move $t2, $v0
			###########################################################
			################# Prompt for Final value ##################
			li $v0, 4		
			la $a0, promptFinal		
			syscall
			li $v0, 5
			syscall
			move $t3, $v0
			li $v0, 11
			li $a0, '\n'
			syscall
			###########################################################
			#################### Weight for Exam 1 ####################
			
			sll $t1, $t1 9		# $t1 has 512*e1
			li $t7, 2558		# $t7 has 2558
			div $t1, $t7		# Lo has (512/2558)*e1
			mflo $t1
			
			#li $v0, 4
			#la $a0, testLab1
			#syscall
			#li $v0, 1
			#move $a0, $t1
			#syscall
			#li $v0, 11
			#li $a0, '\n'
			#syscall
			
			###########################################################
			#################### Weight for Exam 2 ####################
			
			li $t7, 614		# $t7 has 614
			mult $t2, $t7		# Lo has 614*e2
			mflo $t2		# $t2 has 614*e2
			srl $t2, $t2 11		# $t2 has (614/2048)*e2
			
			#li $v0, 4
			#la $a0, testLab2
			#syscall
			#li $v0, 1
			#move $a0, $t2
			#syscall
			#li $v0, 11
			#li $a0, '\n'
			#syscall
			
			###########################################################
			################## Weight for Final Exam ##################
			
			srl $t3, $t3 1		# $t3 has F/2
			
			#li $v0, 4
			#la $a0, testLab3
			#syscall
			#li $v0, 1
			#move $a0, $t3
			#syscall
			#li $v0, 11
			#li $a0, '\n'
			#syscall
			#li $v0, 11
			#li $a0, '\n'
			#syscall
			
			###########################################################
			#################### Add all 3 weights ####################
			
			add $t0, $t1, $t2	# $t0 has (512/2558)*e1 + (614/2048)*e2
			add $t0, $t0, $t3	# $t0 has (512/2558)*e1 + (614/2048)*e2 * F/2
			
			###########################################################	
    	   	        ######################### Display #########################
    	   	        
    	   	        li $v0, 4
			la $a0, outLab
			syscall
			li $v0, 1
			move $a0, $t0
			syscall
    	   	        
			###########################################################	
    	   	        ########################## exit ###########################
      	 	        li $v0, 10
       	   	      	syscall
