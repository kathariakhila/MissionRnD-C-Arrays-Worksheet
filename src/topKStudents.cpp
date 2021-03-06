/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};


void highest(struct student *students, int len, int k, struct student *res){

	struct student max;

	max.score = 0;

	int i;
	int j;

	for (i = 0; i<len; i++){

		if (students[i].score > max.score){
			max.name = students[i].name;
			max.score = students[i].score;
		}

		res[k-1].name = max.name;
		res[k-1].score = max.score;
	}

	for (i = k-2; i>=0; i--){

		max.score = 0;

		for (j = 0; j<len; j++){

			if (students[j].score > max.score && students[j].score < res[i + 1].score){
				max.name = students[j].name;
				max.score = students[j].score;

			}
		}

		res[i].name = max.name;
		res[i].score = max.score;
	}

}


struct student ** topKStudents(struct student *students, int len, int K) {
	
	struct student res[20] ;

	struct student **topK = (struct student**)calloc(K, sizeof(struct student));
	int i,j;
	int index;


	if (students == NULL)
		return NULL;
	
	if (len < 0)
		return NULL;

	if (K <= 0)
		return NULL;
	
	else if (K > len){

		highest(students, len, len, res);
		for (i = 0; i < K; i++){
			students[i].name = res[i].name;
			students[i].score = res[i].score;
			//topK[i] = &res[i];
		}
		for (i = 0; i < K; i++)
			topK[i] = &students[i];

		return topK;
	}
	else{
		highest(students, len, K, res);
		

		for (i = 0; i < K; i++){
			students[i].name = res[i].name;
			students[i].score = res[i].score;
			//topK[i] = &res[i];
		}
		for (i = 0; i < K; i++)
			topK[i] = &students[i];

		return topK;
	}



}