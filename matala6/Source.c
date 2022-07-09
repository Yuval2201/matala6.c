#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int pack4Char2Int(char a, char b, char c, char d);
int checkEvenParity(short input);

void main()
{
	int result1 = pack4Char2Int('a', 'b', 'c', 'd');
	printf("the result is: %d\n", result1);

	int result2 = checkEvenParity(7);
	printf("the result is: %d \n", result2);
}

int pack4Char2Int(char a, char b, char c, char d) {
	int num = 0xFFFFFFFF;
	int y = 0xFFFFFFFF;
	int e = 0xFFFFFFFF;
	int f = 0xFFFFFFFF;
	num &= a;
	num <<= 24;
	y &= b;
	y <<= 16;
	e &= c;
	e <<= 8;
	f &= d;
	num = num | y;
	num = num | e;
	num = num | f;

	return num;
}


int checkEvenParity(short input)
{
	int sum = 0, i = 0;
	short subnetmask = 0x1;

	while (i < (sizeof(input) * 8)) // 16 bits size
	{
		if (subnetmask & input) // Testing of each bit separately (Checks if the bit is 1)
		{
			sum++;
			subnetmask <<= 1;
		}

		i++;
	}

	if (sum % 2 == 0) // Positive test
		return 1;

	else    // else Negative 
		return 0;
}

