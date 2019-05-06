#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 50

int main() {
	int *array = (int *)malloc(ARRAY_SIZE*sizeof(int));
	if (array == NULL) {
		printf("ERROR: Memory Allocation\n");
		exit(1);
	}

	int posNum = 0;
	int zeroNum = 0;
	int minusNum=0;
	int totalSum=0;
	float avg = 0;

	int i, j;
	// init random generator
	srand(time(NULL));

	// generate random number
	for (i = 0; i < 40; i++) printf("=");
	printf("\n");
	for (i = 0; i < ARRAY_SIZE; i++) {
		array[i] = rand()%41 - 20; // (0~40)-20 = -20~20
		if (array[i] > 0) posNum++;
		if (array[i] == 0) zeroNum++;
		if (array[i] < 0) minusNum++;
		totalSum += array[i];
		printf("%7d", array[i]);
		if (i % 5 == 4) printf("\n");
	}
	for (i = 0; i < 40; i++) printf("=");
	printf("\n\n\n\n");

	avg = (float)totalSum/ARRAY_SIZE;

	printf("Average is %.2f\n\n", avg);
	printf("Positive data Number\t:%5d\n", posNum);
	printf("zero data Number\t:%5d\n", zeroNum);
	printf("negative data Number\t:%5d\n", minusNum);

	free(array);
	return 0;
}