// Handong hw07 C programming
#include <stdio.h>
#include <stdlib.h>

int gen_rand(int a, int b) {
	return rand()%(b-a+1) + a;
}

int main() {
	srand(time(NULL));

	char input;
	int count = 1;

	while (1) {
		printf("Game: %d. Rock Paper Scissors <ex. S, R, P, Q>: \n", count);
		scanf(" %c", &input);

		int proper = 1;
		switch (input) {
			case 'S': case 's': printf("Player: Scissor\n");
			case 'r': case 'R': printf("Player: Rock\n");
			case 'p': case 'P': printf("Player: Paper\n");
			case 'q': case 'Q': break;
			default: printf("Input is improper.\n\n"); proper=0;
		}
		if (!proper) continue;

		int compNum = gen_rand(1,3);
		switch(compNum) {
			case 1: printf("Computer: Scissor\n");
			case 2: printf("Computer: Rock\n");
			case 3: printf("Computer: Paper\n");
		}

		
		
		count++;
	}

	return 0;
} 