#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 1024

int main() {
	FILE *fp;
	char file_name[MAX_LEN], line[MAX_LEN];
	int i, len, countc[26] = {0}, countn[10] = {0};

	printf("Input file name: ");
	scanf("%s", file_name);
  
	fp = fopen(file_name, "r");
	if(fp == NULL) {
		fprintf(stderr, "ERROR: file open has failed.");
		return -1;
	}

	while(fgets(line, sizeof(line), fp)) {
		printf("%s", line);
		for (i=0; line[i]; i++) { 
			char c = line[i];
			if (isdigit(c)) countn[c-'0']++;
			if (isalpha(c)) countc[toupper(c) - 'A']++;
		}
	}
	for (i=0 ; i<26; i++) printf("\n%c : %d", i+'A', countc[i]);
	for (i=0 ; i<10; i++) printf("\n%c : %d", i+'0', countn[i]);
	fclose(fp);
	return 0;
}