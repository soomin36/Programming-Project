#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "game.h"
#include "game2.h"

void manager_mode();
void player_mode();

int main(void) {
	int mode;
	srand((unsigned int)time(NULL));

	printf("야구 게임 프로그램을 시작합니다. 플레이할 모드를 선택하세요.\n");
	printf("1. 감독 모드\n");
	printf("2. 선수 모드\n");
	scanf("%d", &mode);

	if (mode == 1)
		manager_mode();
	else if (mode == 2)
		player_mode();
	else
		printf("다시 선택하세요.\n");

	return 0;
}
void manager_mode() {

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

void player_mode() {

	int inning, out, strike, ball;
	int b1, b2, b3;
	int swing, pitch, result;
	int user_score = 0;
	int enemy_score = 0;
	int player = 1;

	for (inning = 1; inning <= 3; inning++) {
		printf("\n======%d 이닝 시작 ======\n", inning);

		while (1) {
			out = 0;
			b1 = b2 = b3 = 0;

			while (out < 3) {
				strike = 0;
				ball = 0;

				while (strike < 3 && ball < 4) {
					printbass(b1, b2, b3);
					printf("스트라이크:%d  볼:%d  아웃:%d\n", strike, ball, out);

					if (player) {
						printf("1. 스윙한다  2. 스윙하지 않는다 : ");
						scanf("%d", &swing);

						pitch = rand() % 2 + 1;

						if (pitch == 1)
							printf("투수가 직구를 던졌습니다!\n");
						else
							printf("투수가 변화구를 던졌습니다!\n");

						if (swing == 1) {   //스윙을 한 경우
							result = hitresult(pitch);

							if (result == 0) {
								printf("헛스윙!\n");
								strike++;
							}
							else if (result == 1) {
								if (strike < 2) strike++;
								printf("파울!\n");
							}
							else {
								const char* hitname[] = { "", "1루타", "2루타", "3루타", "홈런!" };
								printf("%s\n", hitname[result - 1]);
								user_score += hit(result - 1, &b1, &b2, &b3);
								printbass(b1, b2, b3);
								printf("점수: %d\n", user_score);
								printf("\n");
								break;
							}
						}
						else {
							int r = rand() % 2;
							if (r == 0) {
								printf("스트라이크!\n");
								strike++;
							}
							else {
								printf("볼!\n");
								ball++;
							}
						}
					}
					else {
						printf("1. 직구 던지기   2. 변화구 던지기: ");
						scanf("%d", &pitch);
						swing = rand() % 2 + 1;

						if (swing == 1) {
							result = hitresult(pitch);

							if (result == 0) {
								printf("상대 헛스윙!\n");
								strike++;
							}
							else if (result == 1) {
								printf("상대 파울!\n");
								if (strike < 2)strike++;
							}
							else {
								const char* hitname[] = { "", "1루타", "2루타", "3루타", "홈런!" };
								printf("상대 %s!\n", hitname[result - 1]);
								enemy_score += hit(result - 1, &b1, &b2, &b3);
								printbass(b1, b2, b3);
								printf("점수:%d\n", enemy_score);
								break;
							}
						}
						else {
							int r = rand() % 2;
							if (r == 0) {
								printf("상대 스트라이크!\n");
								strike++;
							}
							else {
								printf("상대 볼!\n");
								ball++;
							}
						}
					}
				}

				if (strike == 3) {
					printf("삼진 아웃!\n");
					out++;
				}
				else if (ball == 4) {
					printf("볼넷!\n");

					if (b1 == 0) b1 = 1;
					else if (b2 == 0) b2 = 1;
					else if (b3 == 0) b3 = 1;
					else {
						if (player) {
							user_score++;
							printf("밀어내기 득점!\n");
						}
						else {
							enemy_score++;
							printf("밀어내기 득점!\n");
						}
					}
				}
			}
			player = !player;   //공수교대
			if (player) {
				printf("\n====== %d이닝   공수교대 후 사용자 타자 ======\n");
			}
			else {
				printf("\n====== %d이닝   공수교대 후 상대 타자 ======\n");
			}
		}
		printf("\n======%d 이닝 종료 - 사용자 점수: %d , 상대 점수: %d ======\n", inning, user_score, enemy_score);
	}
	printf("\n====== 경기 종료! 최종 점수: 사용자 %d : 상대 %d ======\n", user_score, enemy_score);
}