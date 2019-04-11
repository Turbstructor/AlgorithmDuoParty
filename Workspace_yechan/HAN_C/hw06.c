// HGU hw06 yechan
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	while (1) {
		printf("********************************\n");
		printf("* A|a. Single                  *\n");
		printf("* B|b. Head of Household       *\n");
		printf("* C|c. Married, Joint          *\n");
		printf("* D|d. Married, Separate       *\n");
		printf("********************************\n\n");

		char c;
		printf("Choose Status<A~D> : ");
		scanf(" %c", &c);
		printf("\n");
		int correct_menu = 1;
		int money = 0;
		int tax = 0;
		switch(c) {
			case 'a':
			case 'A':
				printf("Total Money <Unit/10000Won> : ");
				scanf(" %d", &money);
				printf("\n");
				if (money > 200) tax = money*0.25;
				else tax = money*0.15;
				printf("Total Tax is %d (10000Won).\n", tax);
				break;
			case 'b':
			case 'B':
				printf("Total Money <Unit/10000Won> : ");
				scanf(" %d", &money);
				printf("\n");
				if (money > 250) tax = money*0.20;
				else tax = money*0.10;
				printf("Total Tax is %d (10000Won).\n", tax);
				break;
			case 'c':
			case 'C':
				printf("Total Money <Unit/10000Won> : ");
				scanf(" %d", &money);
				printf("\n");
				if (money > 300) tax = money*0.28;
				else tax = money*0.18;
				printf("Total Tax is %d (10000Won).\n", tax);
				break;
			case 'd':
			case 'D':
				printf("Total Money <Unit/10000Won> : ");
				scanf(" %d", &money);
				printf("\n");
				if (money > 150) tax = money*0.15;
				else tax = money*0.12;
				printf("Total Tax is %d (10000Won).\n", tax);
				break;
			default: 
				printf("Wrong Answer. Retry Choose menu...\n");
				correct_menu = 0;
		}
		if (correct_menu) {
			printf("Continue? <y/n>: ");
			scanf(" %c");
			if (c != 'y' && c != 'Y') break;
		}
	}
	printf("Terminate Program\n");
	return 0;
}