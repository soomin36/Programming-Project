#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "game2.h"

void print(int b1, int b2, int b3) {   //현재 베이스 상황을 출력하는 함수 정의
	printf("현재 베이스 상황: [1루: %d] [2루: %d] [3루: %d]\n", b1, b2, b3);
}

int hit(int type, int* b1, int* b2, int* b3) {   //주자 이동을 처리하는 함수 정의
	int run = 0;
	
	if (type == 1) {
		run += *b3;
		*b3 = *b2;
		*b2 = *b1;
		*b1 = 1;
	}
	else if (type == 2) {
		run += *b3 + *b2;
		*b3 = *b1;
		*b2 = 1;
		*b1 = 0;
	}
	else if (type == 3) {
		run += *b3 + *b2 + *b1;
		*b3 = 1;
		*b2 = 0;
		*b1 = 0;
	}
	else if (type == 4) {
		run += *b3 + *b2 + *b1 + 1;
		*b1 = *b2 = *b3 = 0;
	}
	return run;
}

int result(int pitch) {   //투수가 던지는 공에 따른 타격 결과 함수 정의
	int r = rand() % 100;

	if (pitch == 1) {
		if (r < 20) return 0;
		else if (r < 30) return 1;
		else if (r < 65) return 2;
		else if (r < 85) return 3;
		else if (r < 92) return 4;
		else return 5;
	}
	else {
		if (r < 40) return 0;
		else if (r < 60) return 1;
		else if (r < 80) return 2;
		else if (r < 90) return 3;
		else if (r < 95) return 4;
		else return 5;
	}
}