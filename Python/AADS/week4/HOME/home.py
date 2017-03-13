#
# Author: 		Babeanu Alexandru
# S-number:	s3004872
# Date:		12-03-2017
# Challenge:	Homework
# 
# Program description:
# 
# This program reads a positive integer n, followed by n + 1 positive integers
# representing the dimensions of n matrices: Matrix[i] has dimensions
# d[i] x d[i+1]. The program will then compute and display the minimum amount
# of scalar multiplications required to multiply all the matrices in the
# sequence (in the order in which they are given).
#  
# Complexity analysis:
# 
# Time complexity: The main program consists of 3 nested loops, each one scaling
# linearly with n. Therefore, the time cmplexity is O(n*n*n) = O(n^3).
# 
# Memory complexity: The vector used for storing the dimensions has size
# n + 1. The matrix used for storing the costs of the subsequences has size
# n^2. The total space complexity is O(n + 1 + n^2) = O(n^2).
#

from sys import stdin, maxsize

def minChainMatrixMulCost(dims):
	n = len(dims) - 1

	# costs[i][j] = minimum number of scalar multiplications needed to
	# compute A[i]A[i+1]...A[j], where A is the sequence of matrices
	costs = [[0] * n for i in range(n)]
	for length in range(1, n): # subsequence lengths
		endIdx = n - length # first index after last subsequence beginning
		for i in range(0, endIdx):
			j = i + length # last index in subsequence
			costs[i][j] = maxsize
			for k in range(i, j):
				curCost = costs[i][k] + costs[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1]
				if curCost < costs[i][j]:
					costs[i][j] = curCost

	return costs[0][n-1]

# main:

n = int (stdin.readline().strip())

# read matrix sequence dimensions
dims = list(map(int, stdin.readline().strip().split()))

print(minChainMatrixMulCost(dims))