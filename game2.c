#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "game2.h"

void printbass(int b1, int b2, int b3) {   //현재 베이스 상황을 출력하는 함수 정의
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

int hitresult(int pitch) {   //투수가 던지는 공에 따른 타격 결과 함수 정의
	int r = rand() % 100;

	if (pitch == 1) {   //직구를 던진 경우
		if (r < 20) return 0;   //헛스윙 확률
		else if (r < 45) return 1;   //파울 확률
		else if (r < 80) return 2;   //1루타 확률
		else if (r < 93) return 3;   //2루타 확률
		else if (r < 95) return 4;   //3루타 확률
		else return 5;   //홈런 확률
	}
	else {   //변화구를 던진 경우
		if (r < 40) return 0;
		else if (r < 70) return 1;
		else if (r < 90) return 2;
		else if (r < 95) return 3;
		else if (r < 96) return 4;
		else return 5;
	}
}