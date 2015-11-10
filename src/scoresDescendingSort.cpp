/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void merge(struct student *students, int min, int mid, int max){

	struct student tmp[30];
	int i, j, k, m;

	j = min;

	int index = 0;

	m = mid + 1;

	for (i = min; j <= mid && m <= max; i++){

		if (students[j].score >= students[m].score)
		{
			index = 0;
			while (students[j].name[index] != '\0'){

				tmp[i].name[index] = students[j].name[index];
				index++;
			}
			tmp[i].name[index] = '\0';
			tmp[i].score = students[j].score;
			j++;
		}
		else
		{
			index = 0;
			while (students[m].name[index] != '\0'){

				tmp[i].name[index] = students[m].name[index];
				index++;
			}
			tmp[i].name[index] = '\0';
			tmp[i].score = students[m].score;

			m++;
		}
	}
	if (j>mid){
		for (k = m; k <= max; k++){

			index = 0;
			while (students[k].name[index] != '\0'){

				tmp[i].name[index] = students[k].name[index];
				index++;
			}
			tmp[i].name[index] = '\0';
			tmp[i].score = students[k].score;

			i++;
		}
	}
	else{

		for (k = j; k <= mid; k++){


			index = 0;
			while (students[k].name[index] != '\0'){

				tmp[i].name[index] = students[k].name[index];
				index++;
			}
			tmp[i].name[index] = '\0';
			tmp[i].score = students[k].score;

			i++;
		}
	}
	for (k = min; k <= max; k++){

		index = 0;
		while (tmp[k].name[index] != '\0'){
			students[k].name[index] = tmp[k].name[index];
			index++;
		}

		students[k].name[index] = '\0';
		students[k].score = tmp[k].score;
	}
}


void mergeSort(struct student *students, int min, int max){

	int mid;

	if (min<max)
	{
		mid = (min + max) / 2;
		mergeSort(students, min, mid);
		mergeSort(students, mid + 1, max);

		merge(students, min, mid, max);
	}
}






void * scoresDescendingSort(struct student *students, int len) {
	
	if (students == NULL)
		return NULL;
	
	if (len < 0)
		return NULL;

	else{
		mergeSort(students, 0, len-1);
	}

}