#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "player.h"

void play_game(Batter lineup[], Pitcher pitcher) {
	int teambat, pitch;
	calculate_stats(lineup, pitcher, &teambat, &pitch);

	int enemybat = rand() % (95 - 70 + 1) + 70;   //상태 팀의 타격 능력 랜덤 생성(70~95)
	int enemypitch = rand() % (95 - 75 + 1) + 75;   //상대 팀의 투수 능력 랜덤 생성(75~95)

	printf("======경기 시작======\n");
	printf("우리 팀 타격 능력: %d   투수 능력: %d\n", teambat, pitch);
	printf("상대 팀 타격 능력: %d   투수 능력: %d\n", enemybat, enemypitch);

	int myscore = rand() % 3 + (teambat - enemypitch) / 10;
	int enemyscore = rand() % 3 + (enemybat - pitch) / 10;

	if (myscore < 0)
		myscore = 0;
	if (enemyscore < 0)
		enemyscore = 0;

	printf("\n최종 점수: 우리 팀  %d : 상대 팀 %d \n", myscore, enemyscore);

	if (myscore > enemyscore)
		printf("승리했습니다!\n");
	else if (myscore == enemyscore)
		printf("무승부입니다!\n");
	else
		printf("패배했습니다.\n");
}