
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>



int ascPosition(int *Arr, int len, int score) {
	int lowerBound = 0;
	int upperBound = len - 1;

	while (true) {
		int mid = (upperBound + lowerBound) / 2;
		if (len == 0) {
			return mid = 0;
		}
		if (lowerBound == mid) {
			if (Arr[mid] > score) {
				return mid;
			}
		}
		if (Arr[mid] < score) {
			lowerBound = mid + 1;          // its in the upper 
			if (lowerBound > upperBound) {
				return mid += 1;
			}
		}
		else if (lowerBound > upperBound) {
			return mid;
		}
		else {
			upperBound = mid - 1;          // its in the lower   
		}
	}
}

int decPosition(int *Arr, int len, int score) {
	int lowerBound = 0;
	int upperBound = len - 1;

	while (true) {
		int mid = (upperBound + lowerBound) / 2;
		if (len == 0) {
			return mid = 0;
		}
		if (lowerBound == mid) {
			if (Arr[mid] < score) {
				return mid;
			}
		}
		if (Arr[mid] > score) {
			lowerBound = mid + 1;          // its in the upper 
			if (lowerBound > upperBound) {
				return mid += 1;
			}
		}
		else if (lowerBound > upperBound) {
			return mid;
		}
		else {
			upperBound = mid - 1;          // its in the lower   
		}
	}
}


void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {

	int p;

	if (Arr == NULL)
		return NULL;
	
	if (len < 0)
		return NULL;

	else if (len == 1){
		if (Arr[0] < score){
			*lessCount = 1;
			*moreCount = 0;
		}
		
		else if (Arr[0] > score){
			*lessCount = 0;
			*moreCount = 1;
		}
		else{
			*lessCount = 0;
			*moreCount = 0;
		}
	}

	else{
		if (Arr[0] < Arr[len-1]){
			p = ascPosition(Arr, len, score);

			*lessCount = p;
			if (Arr[p] == score)
				*moreCount = len - p - 1;
			else
				*moreCount = len - p;
		}
		else if (Arr[0] > Arr[len-1]){
			p = decPosition(Arr, len, score);

			*lessCount = p;
			if (Arr[p] == score)
				*moreCount = len - p - 1;
			else
				*moreCount = len - p;
		}
		else {
			if (Arr[0] < score){
				*lessCount = len;
				*moreCount = 0;
			}
			else if (Arr[0] > score){
				*moreCount = len;
				*lessCount = 0;
			}
			else
				*lessCount = *moreCount = 0;

		}
	
	}
}
