/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>


int position(int *Arr, int len, int num) {
	int lowerBound = 0;
	int upperBound = len - 1;

	while (true) {
		int mid = (upperBound + lowerBound) / 2;
		if (len == 0) {
			return mid = 0;
		}
		if (lowerBound == mid) {
			if (Arr[mid] > num) {
				return mid;
			}
		}
		if (Arr[mid] < num) {
			lowerBound = mid + 1;           
			if (lowerBound > upperBound) {
				return mid += 1;
			}
		}
		else if (lowerBound > upperBound) {
			return mid;
		}
		else {
			upperBound = mid - 1;             
	
		}
	}
}


void insertPosition(int *Arr, int len, int num, int p){

	int i = len;

	for (i = len; i > p; i--){
		Arr[i] = Arr[i - 1];

	}
	Arr[p] = num;


}



int * sortedArrayInsertNumber(int *Arr, int len, int num){


	int p;

	if (Arr == NULL )
		return NULL;

	if (len < 0)
		return NULL;

	else{

		p = position(Arr, len, num);
		insertPosition(Arr, len, num, p);
		return Arr;
	}
}