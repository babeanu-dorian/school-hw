/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		18-02-2017
 * Challenge:	Sort
 * 
 * Program description:
 * 
 * This program reads 4 pozitive integer numbers n, a, b and c. It then generates
 * an unsorted array by using the following formula:
 * v[i] = b, for i = 0
 * v[i] = (a * v[i - 1] + b) % c, for 0 < i < n
 * The program then sorts this array by using counting sort and then outputs
 * every 100th element (starting from the first one) of the sorted array. 
 *  
 * Complexity analysis:
 * 
 * Time complexity: Generating the array takes n itterations. Preparing the
 * histogram takes c itterations. Counting element instances with the histogram
 * takes n itterations. Generating the sorted array from the histogram takes
 * n + c itterations in the worst case scenario. O(n + c + n + n + c) =
 * = O(3n + 2c) = O(n + c), where n and c are the first and last inputed numbers.
 * 
 * Memory complexity: The most memory used at any given time is when executing
 * the counting sort algorithm, where the memory is occupied by the histogram of
 * length c, the array to be sorted, of length n, and some variables that do not
 * depend on the input. Theresore the space complexity is O(n + c), where n and c
 * are the first and last inputed numbers.
 */

#include "main.ih"

int main(int argc, char **argv)
{
	size_t n, a, b, c;

	std::cin >> n >> a >> b >> c;

	std::vector<size_t> arr;
	generateArr(n, a, b, c, arr);

	// since b < c and all the other elements are remainders
	// of division by c: arr[i] < c, for all i in [0, n)
	countingSort(arr, c);

	jumpPrint(arr, 100);

	return 0;
}