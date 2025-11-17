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

}