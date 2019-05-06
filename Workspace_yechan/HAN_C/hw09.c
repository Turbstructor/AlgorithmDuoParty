#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 30
#define TEST_SIZE 5

// Just Print Line consist of '='
void printLine() {
	int i;
	for (i = 0; i < 60; i++) printf("=");
	printf("\n");
}

// make float 2DArray: array[height][width], return float** array
float **make2DArray(int height, int width) {
	int i;

	float **array = NULL;
	array = (float **)malloc(height*sizeof(float *));
	if (array == NULL) {
		printf("ERROR: Memory Allocation\n");
		exit(1);
	}
	for (i = 0; i < height; i++) {
		array[i] = (float *)malloc(width*sizeof(float));
		if (array[i] == NULL) {
			printf("ERROR: Memory Allocation\n");
			exit(1);
		}
	}
	return array;
}

// free 2DArray
void free2DArray(float **array, int height) {
	int i;
	for (i = 0; i < height; i++)
		if (array[i] != NULL)
			free(array[i]);

	if (array != NULL)
		free(array);
}

// Print Menu
void menu() {
	int i;
	// print Menu Line
	for (i = 0; i<27; i++) printf("*");
	printf(" Menu ");
	for (i = 0; i<27; i++) printf("*");
	printf("\n");

	// print Menu Options
	printf("*** A. Print Score of All student \t\t\t***\n");
	printf("*** B. Print Distribute follows Grade of student \t***\n");
	printf("*** C. Print Score of student Number \t\t\t***\n");
	printf("*** D. Calculate Total Grade \t\t\t\t***\n");
	printf("*** E. Print Sorted Score\t\t\t\t***\n");
	printf("*** F. Quit \t\t\t\t\t\t***\n");

	// print Last Line
	for (i = 0; i < 60; i++) printf("*");
	printf("\n\n");
}

// generate Scores
void genScores(float **array, int height) {
	int i;

	// exchange seed value[init 1] to current time.
	srand(time(NULL));
	for (i = 0; i < height; i++) {
		array[i][0] = (int)(101 + i); // ID <101~130>
		array[i][1] = (int)(rand()%41 + 60); // 0~40 + 60 = 60~100 : Exam 1
		array[i][2] = (int)(rand()%41 + 60); // 0~40 + 60 = 60~100 : Exam 2
		array[i][3] = (int)(rand()%61 + 40); // 0~60 + 40 = 40~100 : Exam 3
		array[i][4] = (float)(array[i][1]*20 + array[i][2]*20 + array[i][3]*60)/100; // Score
	}
}

// Generate Grades using Scores
void genGrades(float **Scores, char *Grades, int height) {
	int i;

	for (i = 0; i < height; i++) {
		char grade;
		if 		(Scores[i][4] >= 90) grade = 'A';
		else if (Scores[i][4] >= 80) grade = 'B';
		else if (Scores[i][4] >= 70) grade = 'C';
		else if (Scores[i][4] >= 60) grade = 'D';
		else 						 grade = 'F';
		Grades[i] = grade;
	}
}

// Generate Numbers using Grades
void genNumbers(char *Grades, int *Numbers, int height) {
	int i;
	for (i = 0; i < 5; i++) Numbers[i] = 0;

	for (i = 0; i < height; i++) {
		if (Grades[i] == 'A') Numbers[0]++;
		if (Grades[i] == 'B') Numbers[1]++;
		if (Grades[i] == 'C') Numbers[2]++;
		if (Grades[i] == 'D') Numbers[3]++;
		if (Grades[i] == 'F') Numbers[4]++;
	}
}

// initizal Array such as Scores, Grades and Numbers
void initScores(float **Scores, char *Grades, int *Numbers) {
	genScores(Scores, ARRAY_SIZE);
	genGrades(Scores, Grades, ARRAY_SIZE);
	genNumbers(Grades, Numbers, ARRAY_SIZE);
}


// Option A. Print All Scores and Grades each line.
void printAllScores(float **Scores, char *Grades, int height) {
	int i, j;

	printf("ID\tExam1\tExam2\tExam3\tScore\tGrade\n");
	printLine();
	for (i = 0; i < height; i++) {
		for (j = 0; j < 4; j++)
			printf("%.0f\t", Scores[i][j]);
		printf("%.1f\t", Scores[i][j]);
		printf("%c\n", Grades[i]);
	}
	printLine();
}

// Option B. Print Distribution of Scores.
void printDistScores(int *Numbers) {
	int i, j;

	for (i = 0; i < 20; i++) printf("=");
	printf(" Distribution of Scores ");
	for (i = 0; i < 20; i++) printf("=");
	printf("\n");

	for (i = 0; i < 5; i++) {
		if (i == 4) printf("F : ");
		else printf("%c : ", 'A'+i);
		for (j = 0; j < Numbers[i]; j++)
			printf("* ");
		printf("\n");
	}
	printLine();
}

// Option C. Print Scores that accepted id that input terminal
void printFindScores(float **Scores, char *Grades) {
	int id;
	printf("Input ID <101~130> : ");
	scanf(" %d", &id);
	printf("\n");
	if (101 <= id && id <= 130) {
		printf(" Score of ID %d : %.1f\n", id, Scores[id-101][4]);
		printf(" Grade of ID %d : %c\n", id, Grades[id-101]);
	} else {
		printf("Wrong Input ID\n");
	}
}

// Option D. Print Total Average of Grade
void printAvgGrade(char *Grades, int height) {
	int i;
	float avg, total=0;
	for (i = 0; i < height; i++) {
		if (Grades[i] == 'A') total += 4;
		if (Grades[i] == 'B') total += 3;
		if (Grades[i] == 'C') total += 2;
		if (Grades[i] == 'D') total += 1;
		if (Grades[i] == 'F') total += 0;
	}
	avg = (float)total/ARRAY_SIZE;
	printf(" Total Average is %.1f\n", avg);
}

// swep Data that (Score[a], Grade[a]) <-> (Score[b], Grades[b])
void swapData(float **Scores, char *Grades, int a, int b) {
	if (a == b) return;
	int i;
	float tmpF[5];
	char tmpC;
	// copy a to tmp
	for (i = 0; i < 5; i++)
		tmpF[i] = Scores[a][i];
	tmpC = Grades[a];
	// copy b to a
	for (i = 0; i < 5; i++) 
		Scores[a][i] = Scores[b][i];
	Grades[a] = Grades[b];
	// copy tmp to b
	for (i = 0; i < 5; i++) 
		Scores[b][i] = tmpF[i];
	Grades[b] = tmpC;
}

// Option E. Print Score Descending Order
void printSortScore(float **Scores, char *Grades, int height){
	float **copyScores=NULL;
	char *copyGrades=NULL;
	copyScores = make2DArray(ARRAY_SIZE, TEST_SIZE);
	copyGrades = (char *)malloc(ARRAY_SIZE*sizeof(char));
	if (copyGrades == NULL) {
		printf("ERROR: Memory Allocation\n");
		exit(1);
	}

	int i, j;
	// Copy Data
	for (i = 0; i < height; i++) {
		for (j = 0; j < 5; j++) {
			copyScores[i][j] = Scores[i][j];
		}
		copyGrades[i] = Grades[i];
	}

	// insert Sort
	for (i = 0; i < height-1; i++) {
		float maxV = copyScores[i][4];
		int maxIdx = i;
		for (j = i+1; j < height; j++) {
			if (copyScores[j][4] > maxV) {
				maxV = copyScores[j][4];
				maxIdx = j;
			}
		}
		swapData(copyScores, copyGrades, i, maxIdx);
	}

	printAllScores(copyScores, copyGrades, height);

	free2DArray(copyScores, ARRAY_SIZE);
	if(copyGrades != NULL)
		free(copyGrades);
}

int main() {
	float **Scores = NULL;
	char *Grades = NULL;
	int *Numbers = NULL;

	// make Arrays such as Scores, Grades and Numbers
	Scores = (float **)make2DArray(ARRAY_SIZE, TEST_SIZE);

	Grades = (char *)malloc(ARRAY_SIZE*sizeof(char));
	if (Grades == NULL) {
		printf("ERROR: Memory Allocation\n");
		exit(1);
	}

	Numbers = (int *)malloc(TEST_SIZE*sizeof(int));
	if (Numbers == NULL) {
		printf("ERROR: Memory Allocation\n");
		exit(1);
	}

	// init Scores, Grades and Numbers
	initScores(Scores, Grades, Numbers);

	// Start Menu
	while (1) {
		menu();

		// Choose Menu
		char cmd;
		printf("Choose Menu : ");
		scanf(" %c", &cmd);
		printf("\n");

		// Excute input command
		int exit_flag = 0;
		switch(cmd) {
			case 'A': printAllScores(Scores, Grades, ARRAY_SIZE); 	break;
			case 'B': printDistScores(Numbers); 					break;
			case 'C': printFindScores(Scores, Grades); 				break;
			case 'D': printAvgGrade(Grades, ARRAY_SIZE); 			break;
			case 'E': printSortScore(Scores, Grades, ARRAY_SIZE); 	break;
			case 'F': printf("Quit Program\n"); exit_flag = 1; 		break;
			default : printf("Select Menu Propery\n");
		}
		if (exit_flag) break;
	}

	// free all element
	free2DArray(Scores, ARRAY_SIZE);
	if (Grades != NULL) free(Grades);
	if (Numbers != NULL) free(Numbers);
	return 0;
}