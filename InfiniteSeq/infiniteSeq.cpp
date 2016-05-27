// infiniteSeq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>


int main()
{

	long long int a;
	long long int b;
	long long int c;
	long long int number = 0;

	scanf("%I64d", &a);
	scanf("%I64d", &b);
	scanf("%I64d", &c);

	number = a;

	if (a != b&&c != 0) {
		if (((a - b)>0 && c<0) || ((a - b)<0 && c>0)) {
			if ((a - b) % c == 0) {
				printf("YES");
				return 0;
			}
		}
	}
	else {
		if (a == b) {
			printf("YES");
			return 0;
		}
	}

	printf("NO");

	return 0;
}
