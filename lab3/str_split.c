#include <string.h>
#include <stdio.h>

void split(const char* Expression, char* Dest,
	const char* Delimiter, unsigned int Index) {

	size_t expLen = strlen(Expression);
	size_t delLen = strlen(Delimiter);

	if (expLen == 0 || delLen == 0) {
		memset(Dest, 0, 1);
		return;
	}

	for (unsigned int i = 0, count = 0, prev = 0; i < expLen; i++) {
		if (strncmp(Expression + i, Delimiter, delLen) == 0) {
			if (count == Index) {
				if (count == 0) {
					strncpy(Dest, Expression, i);
					memset(Dest + i, 0, 1);
				}
				else {
					strncpy(Dest, Expression + prev + delLen, i - prev - delLen);
					memset(Dest + i - prev - delLen, 0, 1);
				}
				return;
			}
			prev = i;
			count++;
		}
		if (i == expLen - 1 && count == Index) {
			if (count == 0) {
				strcpy(Dest, Expression);
			}
			else {
				strncpy(Dest, Expression + prev + delLen, expLen - prev - delLen);
				memset(Dest + expLen - prev - delLen, 0, 1);
			}
			return;
		}
	}
	memset(Dest, 0, 1);
}


void main()
{	
	char tmp1[30];
	char tmp2[30];
	char tmp3[30];
	char tmp4[30];
	char tmp5[30];

	split("Hi my name is Taeho Lee", tmp1, " ", 0);
	split("Hi my name is Taeho Lee", tmp2, " ", 1);
	split("Hi my name is Taeho Lee", tmp3, " ", 2);
	split("Hi my name is Taeho Lee", tmp4, " ", 3);
	split("Hi my name is Taeho Lee", tmp5, " ", 4);

	printf("%s\n", tmp1);
	printf("%s\n", tmp2);
	printf("%s\n", tmp3);
	printf("%s\n", tmp4);
	printf("%s\n", tmp5);

}
