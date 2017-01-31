#include <iostream>

#include "semaphore/semaphore.h"

using namespace std;

int main(){
	Semaphore sem(2);
	sem.wait(
		[](int x) -> bool
		{
			return x > 0;
		}, 2);
}