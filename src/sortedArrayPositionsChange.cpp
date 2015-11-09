/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>


void swap(int *a, int number1, int number2){

	int temp;
	temp = a[number1];
	a[number1] = a[number2];
	a[number2] = temp;

	return;
}


void * sortedArrayPositionsChange(int *Arr, int len)

{
	int i = 0;
	int index;


	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;

	else{

		while (Arr[i] < Arr[i + 1] && i < len){

			i++;

		}

		if (i == len){

		}

		

		else{

			index = i;
			i = len - 1;

			while (Arr[i]  > Arr[index])
				i--;


			swap(Arr, index, i);
		}
	

	}

}