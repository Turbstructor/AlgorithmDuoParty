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

		int isMenu = 1;
		switch(c) {
			case 'a': case 'A': case 'b': case 'B': case 'c': case 'C': case 'd': case 'D': break;
			default: printf("Wrong Answer. Retry Choose menu...\n"), isMenu = 0;
		}
		if (isMenu == 0) continue;

		int money = 0, tax = 0;
		float tax_rate = 0;

		printf("Total Money <Unit/10000Won> : ");
		scanf(" %d", &money);
		printf("\n");

		switch(c) {
			case 'a': case 'A': tax_rate = (money > 200) ? 0.25 : 0.15; break;
			case 'b': case 'B': tax_rate = (money > 250) ? 0.20 : 0.10; break;
			case 'c': case 'C': tax_rate = (money > 300) ? 0.28 : 0.18; break;
			case 'd': case 'D': tax_rate = (money > 150) ? 0.15 : 0.12; break;
		}

		tax = money*tax_rate;
		printf("Total Tax is %d (10000Won).\n", tax);

		printf("Continue? <y/n>: ");
		scanf(" %c");
		if (c != 'y' && c != 'Y') break;
	}
	printf("Terminate Program\n");
	return 0;
}