// baekjoon 11723 reference Fast Code
#define _CRT_SECURE_NO_WARNINGS
#define __STDC_LIMIT_MACROS
#define __STDC_FORMAT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#ifdef _MSC_VER
	#include <time.h>
#endif

__inline void real();
int main(void)
{
#ifdef _MSC_VER
	clock_t s = clock();
#endif
	real();
#ifdef _MSC_VER
	clock_t e = clock();
	printf( "\n\n%10.5f\n", (double)(e-s) / CLOCKS_PER_SEC );
#endif
	return 0;
}


class FastIO {
    int fd, bufsz;
    char *buf, *cur, *end;
public:
    FastIO(int _fd = 0, int _bufsz = 1 << 20) : fd(_fd), bufsz(_bufsz) {
        buf = cur = end = new char[bufsz];
    }
    ~FastIO() {
        delete[] buf;
    }
    bool readbuf() {
        cur = buf;
        end = buf + bufsz;
        while (true) {
            size_t res = fread(cur, sizeof(char), end - cur, stdin);
            if (res == 0) break;
            cur += res;
        }
        end = cur;
        cur = buf;
        return buf != end;
    }
    int readint() {
        while (true) {
            if (cur == end) readbuf();
            if (isdigit(*cur) || *cur == '-') break;
            ++cur;
        }
        int sign = 1;
        if (*cur == '-') {
            sign = -1;
            ++cur;
        }
        int ret = 0;
        while (true) {
            if (cur == end && !readbuf()) break;
            if (!isdigit(*cur)) break;
            ret = ret * 10 + (*cur - '0');
            ++cur;
        }
        return sign * ret;
    }

    char* readstr(char* ret) {
        while (true) {
            if (cur == end) readbuf();
            if (!isspace(*cur)) break;
            ++cur;
        }

		char* pos = ret;
       
        while (true) {
            if (cur == end && !readbuf()) break;
            if (isspace(*cur)) break;
			*(pos++) = *(cur++);
        }
		*pos = '\0';
        return ret;
    }
};


__inline void real()
{
	FastIO fio(0, 16384);
	int n = fio.readint();

	int uni[21] = { false, };

	char* buf = new char[(1+1) * 1400000 + 1];
	char* pos = buf;

	char s[7];
	int num;

	int i;
	int n_max;
	while( n > 0 )
	{
		n_max = 1400000 < n ? 1400000 : n;
		n -= n_max;
		for(i=0; i<n_max; i++)
		{
			fio.readstr(s);

			switch(s[0])
			{
			case 'a' :
				if( s[1] == 'd' )
				{
					num = fio.readint();
					if( !uni[num] ) uni[num] = 1;
				}
				else
				{
					memset( uni, 1, sizeof(uni) );
				}
				break;

			case 'r' :
				num = fio.readint();
				if( uni[num] ) uni[num] = 0;
				break;

			case 't' :
				num = fio.readint();
				uni[num] = !uni[num];
				break;

			case 'c' :
				num = fio.readint();				
				*(pos++) = uni[num] ? '1' : '0';
				*(pos++) = '\n';				
				break;

			case 'e' :
				memset( uni, 0, sizeof(uni) );
				break;
			}
		}

		*pos = '\0';
		fputs( buf, stdout );
		pos = buf;
	}
}
