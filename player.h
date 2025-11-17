
#ifndef PLAYER_H
#define PLAYER_H

typedef struct {   //타자 구조체 정의
	char name[20];   //타자 이름을 저장할 배열 선언
	int batting;   //타격 능력치를 저장할 변수 선언
}Batter;

typedef struct {   //투수 구조체 정의
	char name[20];   //투수 이름을 저장할 배열 선언
	int speed;   //구속을 저장할 변수 선언
	int command;   //제구력을 저장할 변수 선언
}Pitcher;

void Batters(Batter batters[]);   //타자 후보 목록 함수 선언
void Pitchers(Pitcher pitchers[]);   //투수 후보 목록 함수 선언
//라인업을 입력받아 평균 타격력과 투수 점수를 계산하여 포인터로 반환하는 함수 선언
void calculate_stats(Batter lineup[], Pitcher pitcher, int* avgbatting, int* picth);

#endif
