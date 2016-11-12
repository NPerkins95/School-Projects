##########################################################################
# Nathan Perkins, CS 2318-002 Assignment 2 Part 1 Program A
##########################################################################
			.data
StringBuffer:		.space 41		# uninit space for up-to-40-char null-term string
						# string can be big, so store it in RAM (not reg)
						# 1 extra byte for null terminator

IntPrompt:		.asciiz "Input Integer: "	
StringPrompt:		.asciiz "\n\nInput String (up to 40 characters): "
CharPrompt:		.asciiz "\nInput Char: "	

reportInt:		.asciiz "Output Integer: "
reportString:		.asciiz "Output String: "
reportChar:		.asciiz "\nOutput Character: "

			.text
			.globl main		
main:
#################################################
# Register usage:
#################################################
# $t1: Integer
# $t7: Character
#################################################
			li $v0, 4
			la $a0, IntPrompt
			syscall
			li $v0, 5		# read-integer service code in $v0
			syscall			
			add $t1, $v0, $0	# copy integer read (in $v0) to $t1
			
			li $v0, 4		################################
			la $a0, reportInt	# Output label for integer
			syscall			#
			li $v0, 1		# 
			move $a0, $t1		# Output value for user integer
			syscall			################################
			######################
			li $v0, 4					
			la $a0, StringPrompt
			syscall
			
			li $v0, 8		# read-string service code in $v0 
			la $a0, StringBuffer	# buffer address in $a0
			li $a1, 41		# buffer size in $a1
			syscall
			
			li $v0, 4		################################
			la $a0, reportString	# Output label for string
			syscall			#
			li $v0, 4		#
			la $a0, StringBuffer	# Output for user string
			syscall			################################
			######################
			li $v0, 4
			la $a0, CharPrompt
			syscall
			li $v0, 12		# read-character service code in $v0
			syscall			
			move $t7, $v0		# copy character read (in $v0) to $t7
			
			li $v0, 4		################################
			la $a0, reportChar	# Output label for character
			syscall			#
			li $v0, 11		# 
			move $a0, $t7		# Output for user character
			syscall			################################
			######################
			li $v0, 10
			syscall
