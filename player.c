#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "player.h"

void Batters(Batter batters[]) {
	strcpy(batters[0].name, "송성문"); batters[0].batting = 92; 
	strcpy(batters[1].name, "최주환"); batters[1].batting = 78;
	strcpy(batters[2].name, "안현민"); batters[2].batting = 95; 
	strcpy(batters[3].name, "허경민"); batters[3].batting = 79;
	strcpy(batters[4].name, "구자욱"); batters[4].batting = 89; 
	strcpy(batters[5].name, "강민호"); batters[5].batting = 75; 
	strcpy(batters[6].name, "박성한"); batters[6].batting = 75; 
	strcpy(batters[7].name, "최지훈"); batters[7].batting = 81; 
	strcpy(batters[8].name, "양의지"); batters[8].batting = 95; 
	strcpy(batters[9].name, "정수빈"); batters[9].batting = 71; 
	strcpy(batters[10].name, "김주원"); batters[10].batting = 84; 
	strcpy(batters[11].name, "박민우"); batters[11].batting = 85; 
	strcpy(batters[12].name, "최형우"); batters[12].batting = 89;
	strcpy(batters[13].name, "박찬호"); batters[13].batting = 81;
	strcpy(batters[14].name, "문보경"); batters[14].batting = 82; 
	strcpy(batters[15].name, "신민재"); batters[15].batting = 86;
	strcpy(batters[16].name, "전준우"); batters[16].batting = 83; 
	strcpy(batters[17].name, "고승민"); batters[17].batting = 73; 
	strcpy(batters[18].name, "문현빈"); batters[18].batting = 87; 
	strcpy(batters[19].name, "노시환"); batters[19].batting = 76; 
}

void Pitchers(Pitcher pitchers[]) {
	strcpy(pitchers[0].name, "안우진"); pitchers[0].command = 90; pitchers[0].speed = 97;
	strcpy(pitchers[1].name, "원태인"); pitchers[1].command = 90; pitchers[1].speed = 87;
	strcpy(pitchers[2].name, "고영표"); pitchers[2].command = 88; pitchers[2].speed = 76;
	strcpy(pitchers[3].name, "김광현"); pitchers[3].command = 85; pitchers[3].speed = 87;
	strcpy(pitchers[4].name, "양현종"); pitchers[4].command = 85; pitchers[4].speed = 81;
	strcpy(pitchers[5].name, "임찬규"); pitchers[5].command = 85; pitchers[5].speed = 80;
	strcpy(pitchers[6].name, "박세웅"); pitchers[6].command = 82; pitchers[6].speed = 85;
	strcpy(pitchers[7].name, "곽빈"); pitchers[7].command = 80; pitchers[7].speed = 97;
	strcpy(pitchers[8].name, "구창모"); pitchers[8].command = 88; pitchers[8].speed = 82;
	strcpy(pitchers[9].name, "류현진"); pitchers[9].command = 88; pitchers[9].speed = 83;
}

void calculate_stats(Batter lineup[], Pitcher pitcher, int* avgbatting, int* pitch) {
	int totalbatting = 0;
	for (int i = 0; i < 9; i++) {
		totalbatting += lineup[i].batting;
	}
	*avgbatting = totalbatting / 9;
	*pitch = (pitcher.command + pitcher.speed) / 2; 
}