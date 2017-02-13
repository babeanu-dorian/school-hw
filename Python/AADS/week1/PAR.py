# Author: 		Babeanu Alexandru
# S-number:		s3004872
# Date:			12-02-2017
# Challenge:	Paranthesis
# 
# Program description:
# 
# This program reads a number c, followed by c lines of characters.
# These characters are right and left sided round and square brackets,
# and '*'s, representing backspaces. This program checks if the opening
# and closing brackets match in the right sequence, outputing 'YES' or
# 'NO' to the standard output accordingly.
# 
# Complexity analysis:
# 
# Time complexity: O(n), where n is the amount of input characters. The algorithm
# performs a fixed amount of operations for every input character (the pop and
# append list functions are in O(1)). Hence, the complexity is linear.
# 
# Memory complexity: O(m), where m is the maximum length among the inputed c lines
# of characters. Each of the 2 lists used in the algorithm have a maximum length
# equal to the length of one input line. After one line is processed, the momory
# used for it is discarded, so the maximum amount of memory used at any given time
# during runtime is linear in the greatest length of an input line.

from sys import stdin

# check if the provided equation is balanced bracket-wise
def isBalanced(eq):
	backspace = 0; # count of characters to delete
	stack = []
	leftBr = ['(', '[']
	rightBr = [')', ']']

	# reverse doesn't actually reverse the list, it returns a backwards iterator
	for cur in reversed(eq):
		if cur == '*':
			backspace += 1 # increase count of characters to delete
		elif backspace:
			backspace -= 1 # ignore current character, decrement delete count
		else:
			# push right brackets on the stack
			if cur in rightBr:
				stack.append(cur)
			# left bracket should find its pair at the top of the stack
			elif (cur in leftBr) and ((not stack) or (rightBr[leftBr.index(cur)] != stack.pop())):
				return False

	# stack should be empty if all the brackets matched
	return not stack

# main:

c = int (stdin.readline().strip())

for i in range (0, c):
	if isBalanced(stdin.readline().strip()):
		print "YES"
	else:
		print "NO"