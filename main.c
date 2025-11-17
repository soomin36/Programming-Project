#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "game.h"
#include "game2.h"

int main(void) {
	srand((unsigned int)time(NULL));

	Batter all_batters[20];
	Pitcher all_pitchers[10];
	Batter lineup[9];
	Pitcher selected_pitcher;

	Batters(all_batters);
	Pitchers(all_pitchers);

	printf("======감독 모드를 선택하셨습니다! 팀을 구성하세요======\n");
	printf("타자 목록: \n");
	for (int i = 0; i < 20; i++) {
		printf("%d. %s - 타격: %d\n", i + 1, all_batters[i].name, all_batters[i].batting);
	}

	printf("라인업에 넣을 9명의 타자 번호를 입력하세요: \n");
	for (int i = 0; i < 9; i++) {
		int num;
		printf("%d번째 타자 번호: ", i + 1);
		scanf("%d", &num);
		if (num < 1 || num>20) {
			printf("잘못된 번호입니다. 다시 입력하세요.\n");
			i--;
			continue;
		}
		lineup[i] = all_batters[num - 1];
	}
	printf("투수 목록: \n");
	for (int i = 0; i < 10; i++) {
		printf("%d. %s - 제구력: %d, 구속: %d\n", i+1, all_pitchers[i].name, all_pitchers[i].command, all_pitchers[i].speed);
	}
	int num2;
	printf("라인업에 넣을 투수 1명의 번호를 입력하세요: \n");
	scanf("%d", &num2);
	while (num2 < 1 || num2>10) {
		printf("잘못된 번호입니다. 다시 입력하세요: ");
		scanf("%d", &num2);
	}
	selected_pitcher = all_pitchers[num2 - 1];

	printf("======최종 라인업======\n");
	for (int i = 0; i < 9; i++) {
		printf("%d번 타자: %s\n", i + 1, lineup[i].name);
	}
	printf("선발 투수: %s\n", selected_pitcher.name);

	play_game(lineup, selected_pitcher);


}