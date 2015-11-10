/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>


void compress(int *num, int length){


	int tempIndex = 1;
	int i, j;


	for (i = 1; i < length; i++){

		for (j = 0; j < i; j++){
			if (num[i] == num[j]){
				break;

			}

		}
	
		if (j == i){
			num[tempIndex] = num[i];
			tempIndex++;
		}

	}

}


void * removeArrayDuplicates(int *Arr, int len)
{

	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;
	else{
		compress(Arr, len);
	}


}