#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
// 파라미터
#define LEN_MIN 15 // 기차 길이
#define LEN_MAX 50
#define STM_MIN 0 // 마동석 체력
#define STM_MAX 5
#define PROB_MIN 10 // 확률
#define PROB_MAX 90
#define AGGRO_MIN 0 // 어그로 범위
#define AGGRO_MAX 5

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0
// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
// 마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

void intro() { // 인트로 아스키 아트를 출력하는 intro함수
	printf(" ____                                  _   _                        \n");
	printf("| __ )   _   _   ___    __ _   _ __   | | | |   ___   _ __     __ _ \n");
	printf("|  _ \\  | | | | / __|  / _` | | '_ \\  | |_| |  / _ \\ | '_ \\   / _` |\n");
	printf("| |_) | | |_| | \\__ \\ | (_| | | | | | |  _  | |  __/ | | | | | (_| |\n");
	printf("|____/   \\__,_| |___/  \\__,_| |_| |_| |_| |_|  \\___| |_| |_|  \\__, |\n");
	printf("                                                              |___/ \n");

	Sleep(3000);
	system("cls");
}

void outro() { // 아웃트로 아스키 아트를 출력하는 intro함수
	printf(" ____                                  _   _                        \n");
	printf("| __ )   _   _   ___    __ _   _ __   | | | |   ___   _ __     __ _ \n");
	printf("|  _ \\  | | | | / __|  / _` | | '_ \\  | |_| |  / _ \\ | '_ \\   / _` |\n");
	printf("| |_) | | |_| | \\__ \\ | (_| | | | | | |  _  | |  __/ | | | | | (_| |\n");
	printf("|____/   \\__,_| |___/  \\__,_| |_| |_| |_| |_|  \\___| |_| |_|  \\__, |\n");
	printf("                                                              |___/ \n");


}


void train_ex(int len) { // 기차 외벽을 출력하는 train_ex 함수
	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			printf("#\n");
			break;
		}
		printf("#");
	}
}

void train_init(int len) { // 초기 열차의 내부를 출력하는 train_init 함수
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			printf("#");
			continue;
		}
		if (i == len - 6) {
			printf("C");
			continue;
		}
		if (i == len - 3) {
			printf("Z");
			continue;
		}
		if (i == len - 2) {
			printf("M");
			continue;
		}
		if (i == len - 1) {
			printf("#\n");
			break;
		}
		printf(" ");
	}
}

train_inter(int len, int civil, int zombie, int scene, int madong) { // 1턴 부터 끝날떄 까지 기차 내부를 출력해주는 train_inter함수
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			printf("#");
			continue;
		}
		if (i == civil) {
			printf("C");
			continue;

		}
		if (i == zombie) {
			if (scene % 2 == 0) {
				printf("Z");
				continue;
			}
			else {
				printf("Z");
				continue;
			}
		}
		if (i == madong) {
			printf("M");
			continue;
		}
		if (i == len - 1) {
			printf("#\n");
			break;
		}
		printf(" ");
	}
}






int main() {
	// 열차길이, 마동석 체력, 확률을 입력받을 때, 범위에 맍는 값을
	// 입력받기 위해서 while문을 쓸 것이다. 그런데 while문의 조건을 발동시키려면
	// 변수들(길이, 체력, 확률)이 모두 범위 바깥의 값으로 초기화 되어야 하므로
	// 처음에 모두 -1로 초기화 하였다. 세 값은 무조건 양수여야 되기 때문이다.
	int len = -1; // 열차 길이
	int ma_stm = -1; // 마동석 체력
	int p = -1; // 확률

	intro();
	while (!(LEN_MIN <= len && len <= LEN_MAX)) { // 열차 길이 입력
		printf("train lengh(%d ~ %d)>>> ", LEN_MIN, LEN_MAX);
		scanf_s("%d", &len);
	}

	while (!(STM_MIN <= ma_stm && ma_stm <= STM_MAX)) { // 마동석 체력 입력
		printf("madongseok stamina(%d ~ %d)>>> ", STM_MIN, STM_MAX);
		scanf_s("%d", &ma_stm);
	}

	while (!(PROB_MIN <= p && p <= PROB_MAX)) { // 확률 입력
		printf("percentile probability 'p'(%d ~ %d)>>> ", PROB_MIN, PROB_MAX);
		scanf_s("%d", &p);
	}

	system("cls");


	///초기 상태
	train_ex(len);
	train_init(len);
	train_ex(len);
	printf("\n\n");
	Sleep(3000);

	
	int zombie = len - 3;
	int civil = len - 6;
	int madong = len - 2;

	int aggro_civil = 1; // 시민 어그로
	int aggro_madon = 1; // 마동석 어그로

	
	int scene = 1; // 짝수 횟수에 좀비가 멈추기 위한 장면 수 
	while (1) {
		int madong_move = -1; // 마동석의 이동에 쓰일 변수

		srand((unsigned int)time(NULL)); // 현재시간을 기준으로 계속 난수 생성
		int r = rand() % 100 + 1;  // 1 ~ 100 까지의 난수 생성
		if (r > p) { // 난수가 P 보다 크면 이동, 즉 (1-p)의 확률로 이동
			civil--;
			aggro_civil++;
			if (aggro_civil > 5) {
				aggro_civil = 5;
			}
		}
		else {
			if (scene % 2 != 0) {
				zombie--;  // 어그로가 높은 쪽을 선택해서 가려면 이 부분을 수정해야 한다. ------------------------------------------ 아마 이중 조건문으로 작성해야 될 듯 
				aggro_civil--;
				if (aggro_civil < 0) {
					aggro_civil = 0;
				}
			}
		}

		train_ex(len);
		train_inter(len, civil, zombie, scene, madong);
		train_ex(len);
		printf("\n");

		// 시민과 좀비의 이동 결과
		if (scene % 2 == 0) { // 짝수 번째 장면 (좀비가 못움직이는 장면)
			if (r > p) {
				printf("Citizen : %d -> %d (aggro : %d)\n", civil + 1, civil, aggro_civil);
				printf("Zombie : Stay %d (can not move)\n", zombie );
			}
			else {
				printf("Citizen : Stay %d (aggro : %d)\n", civil, aggro_civil);
				printf("Zombie : Stay %d (can not move)\n", zombie );
			}
		}
		else { // 홀 수 번째 장면 (좀비가 움직일 수 없는 장면)
			if (r > p) {
				printf("Citizen : %d -> %d (aggro : %d)\n", civil + 1, civil, aggro_civil);
				printf("Zombie : Stay %d \n", zombie );
			}
			else {
				printf("Citizen : Stay %d (aggro : %d)\n", civil,aggro_civil);
				printf("Zombie : %d -> %d\n", zombie + 1, zombie );
			}
		}

		printf("\n");

		// 마동석 이동 입력 및 결과
		while (!(madong_move == MOVE_LEFT || madong_move == MOVE_STAY)) {
			printf("madongseock move(0 : stay, 1 : move) >> ");
			scanf_s("%d", &madong_move);
		}
		printf("\n");

		if (madong_move == MOVE_LEFT) {
			printf("madong move");
		}
		else if (madong_move == MOVE_STAY) {
			printf("modong doesnt move");
		}



		// 시민이 탈출 성공하거나 좀비한테 공격당했을 때의 출력창
		if (civil == 1) {
			printf("\nSUCCESS!\n");
			printf("citizen(s) escaped to the next train\n");
			break;
		}
		if (zombie - civil == 1) {
			printf("\nGAME OVER!\n");
			printf("Citizen(s) has(have) been attacked by a zombie\n");
			break;
		}

		printf("\n\n");
		scene++;
	}

	outro();


	return 0;
}
