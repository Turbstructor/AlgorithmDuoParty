#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//               ( 1   2   3   4   5   6   7   8   9  10  11  12 month)
int day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//             ( year, month, day )
int curDay[3] = {2019,     4,  26};

int isYoonYear(int year) {
	return (year%400 == 0) || !(year%100 == 0) && (year%4 == 0);
}

int days(int y, int m, int d) {
	int ret = d; // days

	// year
	for (int i=0; i<y; i++) {
		if (isYoonYear(i)) ret++; // 윤년
		ret += 365;
	}

	int isYoon = isYoonYear(y); // check 윤년
	// month
	for (int i=1; i<m; i++) {
		if (i == 2 && isYoon) ret++;
		ret += day[i];
	}
	return ret;
}

int main() {
	int year, month, day;

	int cur_day = days(curDay[0], curDay[1], curDay[2]);
	printf("%d\n", cur_day);

	scanf("%d%d%d", &year, &month, &day);

	int input_day = days(year, month, day);
	printf("%d\n", input_day);

	if (cur_day == input_day) {
		printf("It is Today\n");
	}
	else if (cur_day < input_day) {
		printf("It has been %d days.\n", input_day - cur_day);
	} else {
		printf("We have %d days to go\n", cur_day - input_day);
	}
	return 0;
}