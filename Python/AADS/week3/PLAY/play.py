#
# Author: 		Babeanu Alexandru
# S-number:		s3004872
# Date:			06-03-2017
# Challenge:	Playlist
# 
# Program description:
# 
# This program reads 7 positive integers n, m, a, b, c, d and e,
# from standard input. It then reads n more positive integers and computes
# the cardinality of the intersection between these n values and the m
# values generated after the rule:
# s[0] = a, s[1] = b, s[i] = c * s[i - 1] + d * s[i - 2].
#  
# Complexity analysis:
# 
# Time complexity: Inserting a value into a set is O(1) on average,
# so inserting n values is O(n). Finding and erasing are both O(1) on average,
# so finding and erasing m values is O(2 * m) = O(m). Therefore the total time
# complexity is O(n + m).
# 
# Memory complexity: The only data strucure with input dependent size is the
# set, which should grow linearly with the number of inserted
# elements. Therefore the total space complexity is O(n).
#

from sys import stdin

# this function returns 0 if the value was not found and 1
# if it was, and removes the value from the set if it was found
def findAndErase(val, set):
	if val in set:
		set.remove(val)
		return 1
	return 0

# main:
n, m = map(int, stdin.readline().strip().split())
a, b, c, d, e = map(int, stdin.readline().strip().split())

songRequests = set(list(map(int, stdin.readline().strip().split())))

# number of songs requested which are in the playlist
sCount = findAndErase(a, songRequests) + findAndErase(b, songRequests)

for i in range(2, m):
	nextSong = (c * b + d * a) % e
	a = b
	b = nextSong
	sCount += findAndErase(nextSong, songRequests)

print(sCount)