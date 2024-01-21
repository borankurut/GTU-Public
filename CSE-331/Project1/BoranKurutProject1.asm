.data
	# initial values
	grid_row_size:		.word	16				# changed in receive_input
	grid_column_size:	.word	16				# changed in receive_input
	n:					.word	3				# changed in receive_input
	grid:				.space	1024			# 32 * 32 is the max grid
	grid_buffer:		.space	1024			# this is used to store the grid before filling the bombs 
	input_grid:			.space  1024			# filled in receive_input
	empty_cell:			.byte 46  # empty cell value '.'
	bomb_cell:			.byte 79  # bomb cell value 'O'


	# messages
	newline:			.asciiz "\n"

	seconds_passed_message: .asciiz " second(s) passed" 
	grid_message: .asciiz "Grid: "

	# prompt messages
	row_size_prompt_message: .asciiz "Row size: "
	column_size_prompt_message: .asciiz "Column size: "
	n_prompt_message: .asciiz "N: "
	input_prompt_message: .asciiz "Input grid: "


.text
main:
	jal play		# play call 

	li $v0, 10      # syscall code for exit
    syscall
	
#prints new line
print_new_line:
	li $v0, 4			# to print strings
	la $a0, newline		# load newline string
	syscall				# print new line
	jr $ra				# return

# a0 is the grid to be setted
# a1 is the grid to set from
set_grid:
	subi $sp, $sp, 12    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	sw $s0, 4($sp)		#store s regs
	sw $s1, 8($sp)

	la $t0, 0($a0) # t0 address to set
	la $t1, 0($a1) # t1 address to set from

	lw $s0, grid_row_size
	lw $s1, grid_column_size

	mult $s0, $s1
	mflo $t2	#t2 is the size of the grid now

	move $t3, $zero		#t3 is the index
 
	set_grid_Loop:
		slt $t4, $t3, $t2
		beq $t4, $zero, set_grid_ExitLoop 

		lb $t5, 0($t1)  #t5 is the current character
		sb $t5, 0($t0)	#store it in t0

		addi $t0, $t0, 1	# increment addresses
		addi $t1, $t1, 1

		addi $t3, $t3, 1	# increment index
		j set_grid_Loop		# iterate loop
		
	set_grid_ExitLoop:
		lw $ra, 0($sp)      # Load return address from the stack
		lw $s0, 4($sp)      # restore s regs 
		lw $s1, 8($sp)      # 

		addi $sp, $sp, 12    # Deallocate space on the stack

		jr $ra

#prints the integer in a0
print_int:
	li $v0, 1	# to print integers
	syscall		# a0 already set
	jr $ra		# return

# a0 is the address of the grid.
# a1 is the row size of the grid.
# a2 is the column size of the grid.
print_grid:
	subi $sp, $sp, 20    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
    sw $s0, 4($sp)      # Save s0
    sw $s1, 8($sp)      # Save s1 
    sw $s2, 12($sp)      # Save s2
    sw $s3, 16($sp)      # Save s3
	
	la $s0, 0($a0)		#s0 is the address of the grid
	move $s1, $a1		#s1 is the row size
	move $s2, $a2		#s2 is the column size

	mult $s1, $s2		#this product gives size.
	mflo $t1			#t1 is the size of the grid

	move $s3, $zero		#s3 is the index 

	# print "grid":
	li $v0, 4
	la $a0, grid_message 
	syscall
	jal print_new_line

	print_grid_Loop:
		slt $t2, $s3, $t1	
		beq $t2, 0, print_grid_Exit_Loop # exit loop condition while(i < size).

		lb $t3, 0($s0)		# character to print

		li $v0, 11			# system call argument to print characters
		move $a0, $t3		# system call argument for printing the t3
		syscall				# print

		div $s3, $s2
		mfhi $t4	#t4 is the size % i 
		addi $t4, $t4, 1 # (size % i) + 1 now.

		#if (size % i) + 1 == columnsize, we are in the last element of the row. 
		beq $t4, $s2, print_grid_New_Line # branch printnewline if the index is at row end

		addi $s0, $s0, 1	# increment the address of grid to traverse
		addi $s3, $s3, 1	# increment index
		j print_grid_Loop	# loop

	print_grid_New_Line:
		jal print_new_line

		addi $s0, $s0, 1	# increment the address of grid to traverse
		addi $s3, $s3, 1	# increment index
		j print_grid_Loop	# jump back 
		
	print_grid_Exit_Loop:
		lw $ra, 0($sp)      # Load return address from the stack
		lw $s0, 4($sp)		# restore s registers
		lw $s1, 8($sp)
		lw $s2, 12($sp)
		lw $s3, 16($sp)
		addi $sp, $sp, 20    # Deallocate space on the stack
		
		jr $ra

# prints the buffer and secconds passed message.
# a0 is the seconds.
print_state:
	subi $sp, $sp, 4    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	
	jal print_int		# print second and seconds message

	li $v0, 4
	la $t7, seconds_passed_message
	move $a0, $t7
	syscall

	jal print_new_line

	# print grid
	la $a0, grid
	lw $a1, grid_row_size 
	lw $a2, grid_column_size 
	jal print_grid
	jal print_new_line

	lw $ra, 0($sp)      # Load return address from the stack
	addi $sp, $sp, 4    # Deallocate space on the stack

	jr $ra

# sets the grid from input
init_grid:
	subi $sp, $sp, 4    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack

	# sets grid to input grid
	la $a0, grid
	la $a1, input_grid
	jal set_grid

	lw $ra, 0($sp)      # Load return address from the stack
	addi $sp, $sp, 4    # Deallocate space on the stack

	jr $ra


# check if a given position is in the grid
    #   $a0: row $a1: column
    #   returns $v0: 1 if in grid, 0 otherwise
is_in_grid:
	li $v0, 1	# assume it is in grid

	# if row < 0 or column < 0, not in grid
	slt $t0, $a0, $zero
	bne $t0, $zero, is_in_grid_Not
	slt $t0, $a1, $zero
	bne $t0, $zero, is_in_grid_Not

	#if row >= grid_row_size, not in grid
	lw $t1, grid_row_size
	slt $t0, $a0, $t1		# t0 = row < grid_row_size
	bne $t0, 1, is_in_grid_Not

	#if column >=grid_column_size, not in grid
	lw $t1, grid_column_size
	slt $t0, $a1, $t1		# t0 = column < grid_column_size 
	bne $t0, 1, is_in_grid_Not 

	# v0 already set to 1 so return
	jr $ra

	is_in_grid_Not:
		li $v0, 0 # set v0 to false and return
		jr $ra

# returns correct index for grid by row * grid_column_size + column;
	# a0 = row
	# a1 = column
grid_ix:
	lw $t0, grid_column_size	# t0 is the colunn size now
	mult $a0, $t0				# a0 is row so multiplies row and column
	mflo $t0	#t0 is row * grid_column_size
	add $t0, $t0, $a1	# t0 is row * grid_column_size + column (this is the index in my implementation)
	move $v0, $t0	#set return val

	jr $ra

save_buffer:
	subi $sp, $sp, 4    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	
	la $a0, grid_buffer	# sets gridbuffer to grid
	la $a1, grid
	jal set_grid

	lw $ra, 0($sp)      # Load return address from the stack
	addi $sp, $sp, 4    # Deallocate space on the stack

	jr $ra

#   a0 is the grid address.
#	a1 is the index to set in grid,
#	a2 is the element to set(char)
set_grid_element:
	move $t0, $a0
	add $t0, $t0, $a1 # increment the address by index

	sb $a2, 0($t0)	# set character to address

	jr $ra	#return

#	a0 is the address of the grid
#	a1 is the index to get in grid,
#	v0 is the char that is in that index
get_grid_element:
	move $t0, $a0 
	add $t0, $t0, $a1	# increment the address by ix

	lb $v0, 0($t0)		# load character at index to return val

	jr $ra	# return

# fills bombs in grid
fill_bombs:
	subi $sp, $sp, 4    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack

	la $t0, grid		#t0 is the address of the grid now

	lw $t1, grid_row_size	#t1 is the row size of grid
	lw $t2, grid_column_size #t2 is the column size of grid

	mult $t1, $t2		# mult col and row to find size
	mflo $t3	#t3 is the size of the grid now

	move $t4, $zero # t4 is index

	lb $t5, bomb_cell	# t5 is the bomb value

	fill_bombs_Loop:
		sb $t5, 0($t0)		# t5 is the bomb value so set address to bomb
		addi $t0, $t0, 1	# increment address and index by 1 
		addi $t4, $t4, 1

		slt $t6, $t4, $t3		# we reached the end if index < size is 0
		beq $t6, $zero, fill_bombs_Loop_Exit

		j fill_bombs_Loop		# iterate loop

	fill_bombs_Loop_Exit:
		lw $ra, 0($sp)      # Load return address from the stack
		addi $sp, $sp, 4    # Deallocate space on the stack

		jr $ra		# return


# a0: grid address,
# a1: row value,
# a2: column value
print_element_in_grid:
	subi $sp, $sp, 8    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	sw $s0, 4($sp)		# store s0

	move $s0, $a0	# grid address is in s0 now
	move $a0, $a1	# row value is in a0 now (to call grid_ix)
	move $a1, $a2	# column value is in a1 now (to call grid_ix)

	jal grid_ix # v0 is the index 
	
	move $a0, $s0 # a0 is the address of the grid to call grid element
	move $a1, $v0 # a1 is the index now
	
	jal get_grid_element # v0 is the element in index now

	move $a0, $v0	 # print the character
	li $v0, 11
	syscall

	lw $ra, 0($sp)      # Load return address from the stack
	lw $s0, 4($sp)		# restore s0 register
	addi $sp, $sp, 8    # Deallocate space on the stack

	jr $ra

# a0 row value
# a1 column vlaue
# this function explodes the bomb at given index by setting the related cells to '.'
explode:
	subi $sp, $sp, 12    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	sw $s0, 4($sp)		# store s0
	sw $s1, 8($sp)		# store s1

	move $s0, $a0		# s0 is the row value
	move $s1, $a1		# s1 is the column value

	## bomb is the empty cell after explode
	move $a0, $s0		# set empty argument set
	move $a1, $s1 

	jal set_empty

	# cells to be affected:
	# row -1, column
	# row +1, column
	# row, column - 1
	# row, column + 1
################################################################ (row -1, column)
	addi $s0, $s0, -1		# (row -1, column) cell
	move $a0, $s0			# set empty arguments	
	move $a1, $s1 

	jal set_empty
################################################################ (row + 1, column)
	addi $s0, $s0, 2			# revert -1 and add + 1 for (row + 1, column)
	move $a0, $s0		# set empty argument set
	move $a1, $s1 

	jal set_empty
################################################################ (row, column - 1)
	addi $s0, $s0, -1			# revert +1 
	addi $s1, $s1, -1		# (row, column - 1)
	move $a0, $s0		# set_empty argument set
	move $a1, $s1 

	jal set_empty 
################################################################ (row, column + 1)
	addi $s1, $s1, 2			# revert -1 and add + 1 to column 
	move $a0, $s0		# set_empty argument set
	move $a1, $s1 

	jal set_empty
################################################################ function end

	lw $ra, 0($sp)      # Load return address from the stack
	lw $s0, 4($sp)      # restore s0 
	lw $s1, 8($sp)      #  restore s1 
	addi $sp, $sp, 12    # Deallocate space on the stack

	jr $ra

# sets the row, column cell to empty.
# a0: row,
# a1: column
set_empty:
	subi $sp, $sp, 4    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack

	jal is_in_grid					# v0 is whether in grid now
	beq $v0, $zero set_empty_Exit	# exit if it is not in grid

	jal grid_ix			# v0 is the index of affected

	la $t0, grid		# t0 is the grid address
	lb $t1, empty_cell	# t1 is the empty cell


	move $a0, $t0		# grid address to set character
	move $a1, $v0		# index to set
	move $a2, $t1		# character to set
	jal set_grid_element

	set_empty_Exit:
		lw $ra, 0($sp)      # Load return address from the stack
		addi $sp, $sp, 4    # Deallocate space on the stack

		jr $ra

# explodes all cells in grid that stores bomb in buffer
explode_all:
	subi $sp, $sp, 20    # Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	sw $s0, 4($sp)		# store s0
	sw $s1, 8($sp)		# store s1
	sw $s2, 12($sp)		# store s2
	sw $s3, 16($sp)		# store s3

	lw $s2, grid_row_size
	lw $s3, grid_column_size

	move $s0, $zero		# s0 is the index i
	move $s1, $zero		# s1 is the index j

	explode_all_Outer_Loop:
		slt $t0, $s0, $s2		# when i < row size is false, loop should end
		beq $t0, $zero, explode_all_Exit

		move $s1, $zero # s1 is j
		explode_all_Inner_Loop:
			slt $t0, $s1, $s3
			beq $t0, $zero, explode_all_Inner_Loop_Exit		# when j < column size is false, inner loop should end

			move $a0, $s0	# to call explode cell if buffer
			move $a1, $s1

			jal explode_cell_if_buffer

			addi $s1, $s1, 1	#increment j

			j explode_all_Inner_Loop # iterate
					
		explode_all_Inner_Loop_Exit:
			addi $s0, $s0, 1		# increment i in outer loop end(inner loop exit)
			j explode_all_Outer_Loop	# iterate

	explode_all_Exit:
		lw $ra, 0($sp)      # Load return address from the stack
		lw $s0, 4($sp)		# restore s0, s1, s2, s3
		lw $s1, 8($sp)
		lw $s2, 12($sp)
		lw $s3, 16($sp)
		addi $sp, $sp, 20	# Deallocate space on the stack

		jr $ra

# explodes the bomb in the cell in grid if the cell in the grid_buffer is bomb
# a0: row,
# a1: column
explode_cell_if_buffer:
	subi $sp, $sp, 12	# Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	sw $s0, 4($sp)		# store s0
	sw $s1, 8($sp)		# store s1

	move $s0, $a0		# s0 is the row value 
	move $s1, $a1		# s1 is the column value

	lb $t1, bomb_cell	# t1 is the bomb char

	jal	grid_ix			#v0 is the cell value now

	la $t0, grid_buffer		# t0 is the address of grid buffer
	add $t0, $t0, $v0		# t0 is the cell address of the grid buffer

	lb $t2, 0($t0)			# t2 is the character at the address now

	bne $t1, $t2, explode_cell_if_buffer_Not_Bomb # it is not bomb so go to not bomb

	explode_cell_if_buffer_Bomb:	# explodes the bomb and exits
		move $a0, $s0
		move $a1, $s1
		jal explode			# explode the bomb

		lw $ra, 0($sp)      # Load return address from the stack
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		addi $sp, $sp, 12	# Deallocate space on the stack
		jr $ra

	explode_cell_if_buffer_Not_Bomb:	# deallocates and exits
		lw $ra, 0($sp)      # Load return address from the stack
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		addi $sp, $sp, 12	# Deallocate space on the stack
		jr $ra

play:
	subi $sp, $sp, 12	# Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack
	sw $s0, 4($sp)		# store s0
	sw $s1, 8($sp)		# store s1
	
	#take the input
	jal receive_input
	#init grid
	jal init_grid

	move $s0, $zero		# s0 is the current second
	lw $s1, n			# s1 is the n now

	slt $t0, $s0, $s1
	beq $t0, $zero, play_Exit	# n < 1 so exit
	# don't do anything in 1. second
	move $a0, $zero		# print the state second is 1
	addi $a0, $a0, 1
	jal print_state		

	addi $s0, $s0, 1	# increment the state
	slt $t0, $s0, $s1
	beq $t0, $zero, play_Exit	# n < 2 so exit
	
	# fill bombs in 2. second
	jal save_buffer		# save the buffer before filling bombs
	jal fill_bombs	

	move $a0, $zero
	addi $a0, $a0, 2	# second is 2 now so print the state
	jal print_state

	addi $s0, $s0, 1
	slt $t0, $s0, $s1
	beq $t0, $zero, play_Exit	# n < 3 so exit

	# explode the bombs previously placed
	jal explode_all

	move $a0, $zero
	addi $a0, $a0, 3
	jal print_state		# second is 3 now, print the state

	addi $s0, $s0, 1
	slt $t0, $s0, $s1
	beq $t0, $zero, play_Exit	# n < 4 so exit

	play_Loop:	# iterates from current state to n and explodes and fills repatedly by calculating current state %2 == 0 or not
		move $t0, $zero
		addi $t0, $t0, 2	# t0 is 2 now
		div $s0, $t0 
		mfhi $t0	#t0 is the current % 2  now
		beq $t0, $zero, play_Loop_Explode	
		j play_Loop_Fill	
		
		play_Loop_Explode:
			jal explode_all

			move $a0, $s0
			addi $a0, $a0, 1	# calculate correct current second
			jal print_state
		
			j play_Loop_End
		play_Loop_Fill:
			jal save_buffer
			jal fill_bombs

			move $a0, $s0
			addi $a0, $a0, 1	# calculate correct current second

			jal print_state

			j play_Loop_End

		play_Loop_End:	# increment the state and goto loop again
			addi $s0, $s0, 1
			slt $t0, $s0, $s1
			beq $t0, $zero, play_Exit	# n < current, so exit
			j play_Loop

	play_Exit:
		lw $ra, 0($sp)      # Load return address from the stack
		lw $s0, 4($sp)		# load s regs
		lw $s1, 8($sp)
		addi $sp, $sp, 12	# Deallocate space on the stack
		jr $ra

# receives row size, column size, n and input grid from user
receive_input:
	subi $sp, $sp, 4	# Allocate space on the stack
    sw $ra, 0($sp)      # Save return address on the stack

	# print row prompt
	li $v0, 4
	la $a0, row_size_prompt_message 
	syscall

	li $v0, 5 
	syscall			# v0 is the row now

	sw $v0, grid_row_size 

	# print column prompt
	li $v0, 4
	la $a0, column_size_prompt_message 
	syscall

	li $v0, 5 
	syscall			# v0 is the column now

	sw $v0, grid_column_size

	# print n prompt
	li $v0, 4
	la $a0, n_prompt_message 
	syscall

	li $v0, 5 
	syscall			# v0 is the n now

	sw $v0, n 

	# print prompt of grid
	li $v0, 4
	la $a0, input_prompt_message 
	syscall
	
	lw $t0, grid_row_size
	lw $t1, grid_column_size
	
	mult $t0, $t1
	mflo $a1		#a1 is the size of the grid now
	addi $a1, $a1, 1		# it was not reading the last input, maybe because c style string, so I added 1
	li $v0, 8				# system call code for reading a string
    la $a0, input_grid		# load the address of the inputgridk into $a0

	syscall
	
	lw $ra, 0($sp)      # Load return address from the stack
	addi $sp, $sp, 4	# Deallocate space on the stack
	jr $ra

