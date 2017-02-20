#
# Author: 		Babeanu Alexandru
# S-number:	    s3004872
# Date:		    18-02-2017
# Challenge:	Fractal
# 
# Program description:
# 
# This program reads an integer t corresponding to the number of following input
# lines. It then reads t lines containing 3 integers, k (representing the order
# of the Hilbert Curve) and x and y (the coordinates of a point on the 2^k by 2^k
# matrix with origin in (1,1), the top-left corner). For each line of input,
# the program outputs the number of edges on the Hilbert Curve between the origin
# and the (x, y) point.
#  
# Complexity analysis:
# 
# Time complexity: The program recursively iterates over the k orders of the
# Hilbert Curve, decreasing k by 1 every iteration. Therefore, the complexity
# for one input line is O(k) and the total complexity is O(sumk), where sumk is
# the sum of all k's in the t lines of input.
# 
# Memory complexity: The only data structure with a size dependent on the input is
# the recursive stack, which grows linerly with k. Therefore, the space complexity
# is O(maxk), where maxk is the breatest value of k in all t input lines.
#

from sys import stdin

# order = k = order of the hilbert curve
# middle = 2^k = x and y coordinate of the origin of the bottom-right quarter
# x and y = coordinates of the point (origin has moved to (0, 0))
def hilbertDist(order, middle, x, y):
	if order == 0:
		return 0

	if x < middle:
		if y < middle: # top-left quarter, flip on the 1st diagonal
			return hilbertDist(order - 1, middle >> 1, y, x)
		else: # bottom-left quarter, add 4^(k-1) , shift vertically by 2^(k-1)
			return middle * middle + hilbertDist(order - 1, middle >> 1, x, y - middle)
	else:
		if y < middle:
			# top-right quarter, add 3*4^(k-1), shift horizontally by 2^(k-1),
			# flip on the 2nd diagonal
			return 3 * middle * middle + hilbertDist(order - 1, middle >> 1, middle - y - 1,(middle << 1) - x - 1)
		else:
			# bottom-right quarter, add 3*4^(k-1),
			# shift both horizontally and vertically by 2^(k-1)
			return 2 * middle * middle + hilbertDist(order - 1, middle >> 1, x - middle, y - middle)

# main:

t = int (stdin.readline().strip())

for i in range(0, t):
	k, x, y = map(int, stdin.readline().strip().split())
	print(hilbertDist( k, 1 << (k - 1), x - 1, y - 1))