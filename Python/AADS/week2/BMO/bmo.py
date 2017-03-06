#
# Author: 		Babeanu Alexandru
# S-number:	s3004872
# Date:		27-02-2017
# Challenge:	BMO
# 
# Program description:
# 
# This program reads a number n followed by an n by n matrix of 0's and 1's.
# It then outputs for every integer m in [1, n] the nuber of m by m partitions
# of the original matrix that ony contain 1's.
#  
# Complexity analysis:
# 
# Time complexity: Computing the histogram from the matrix is O(n^2), since
# the program has to go over every element in the n by n matrix. Finalizing
# the histogram (adding each element to the one before it) is linear in the
# size of the histogram, so O(n). Final time complexity: O(n^2 + n) = O(n^2),
# where n is the first integer read from input.
# 
# Memory complexity: The only data structures dependent of input size are
# the 3 vectors used for storing the previous line, the current line and
# the histogram. Their respective sizes are n + 1, n + 1 and n. The resulting
# space complexity is O(n + 1 + n + 1 + n) = O(3n + 2) = O(n), where n is the
# first integer read from input.
#

from sys import stdin

# main:

n = int (stdin.readline().strip())

countSq = [0] * n

# dimension after padding the matrix with 0s, on the left and top:
n += 1

prevLine = [0] * n

# read and process input
for y in range(1, n):
	curLine = list(map(int, stdin.readline().strip().split()))
	curLine.insert(0, 0)

	for x in range(1, n):
		if curLine[x]:
			# count the size of the sqare of 1's and store it in the bottom-left location
			curLine[x] += min(curLine[x - 1], prevLine[x], prevLine[x - 1]);
			countSq[curLine[x] - 1] += 1; # count the instances of each number

	# the current line becomes the previous line for the next line
	prevLine = curLine

# produce the count for each size, not just for each number
for i in reversed(range(0, n - 2)):
	countSq[i] += countSq[i + 1]

# write output
for c in countSq:
	print(c)
