#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
// �Ķ����
#define LEN_MIN 15 // ���� ����
#define LEN_MAX 50
#define STM_MIN 0 // ������ ü��
#define STM_MAX 5
#define PROB_MIN 10 // Ȯ��
#define PROB_MAX 90
#define AGGRO_MIN 0 // ��׷� ����
#define AGGRO_MAX 5

// ������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0
// ������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
// ������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

void intro() { // ��Ʈ�� �ƽ�Ű ��Ʈ�� ����ϴ� intro�Լ�
	printf(" ____                                  _   _                        \n");
	printf("| __ )   _   _   ___    __ _   _ __   | | | |   ___   _ __     __ _ \n");
	printf("|  _ \\  | | | | / __|  / _` | | '_ \\  | |_| |  / _ \\ | '_ \\   / _` |\n");
	printf("| |_) | | |_| | \\__ \\ | (_| | | | | | |  _  | |  __/ | | | | | (_| |\n");
	printf("|____/   \\__,_| |___/  \\__,_| |_| |_| |_| |_|  \\___| |_| |_|  \\__, |\n");
	printf("                                                              |___/ \n");

	Sleep(3000);
	system("cls");
}

void outro() { // �ƿ�Ʈ�� �ƽ�Ű ��Ʈ�� ����ϴ� intro�Լ�
	printf(" ____                                  _   _                        \n");
	printf("| __ )   _   _   ___    __ _   _ __   | | | |   ___   _ __     __ _ \n");
	printf("|  _ \\  | | | | / __|  / _` | | '_ \\  | |_| |  / _ \\ | '_ \\   / _` |\n");
	printf("| |_) | | |_| | \\__ \\ | (_| | | | | | |  _  | |  __/ | | | | | (_| |\n");
	printf("|____/   \\__,_| |___/  \\__,_| |_| |_| |_| |_|  \\___| |_| |_|  \\__, |\n");
	printf("                                                              |___/ \n");


}


void train_ex(int len) { // ���� �ܺ��� ����ϴ� train_ex �Լ�
	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			printf("#\n");
			break;
		}
		printf("#");
	}
}

void train_init(int len) { // �ʱ� ������ ���θ� ����ϴ� train_init �Լ�
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

train_inter(int len, int civil, int zombie, int scene, int madong) { // 1�� ���� ������ ���� ���� ���θ� ������ִ� train_inter�Լ�
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
	// ��������, ������ ü��, Ȯ���� �Է¹��� ��, ������ ���� ����
	// �Է¹ޱ� ���ؼ� while���� �� ���̴�. �׷��� while���� ������ �ߵ���Ű����
	// ������(����, ü��, Ȯ��)�� ��� ���� �ٱ��� ������ �ʱ�ȭ �Ǿ�� �ϹǷ�
	// ó���� ��� -1�� �ʱ�ȭ �Ͽ���. �� ���� ������ ������� �Ǳ� �����̴�.
	int len = -1; // ���� ����
	int ma_stm = -1; // ������ ü��
	int p = -1; // Ȯ��

	intro();
	while (!(LEN_MIN <= len && len <= LEN_MAX)) { // ���� ���� �Է�
		printf("train lengh(%d ~ %d)>>> ", LEN_MIN, LEN_MAX);
		scanf_s("%d", &len);
	}

	while (!(STM_MIN <= ma_stm && ma_stm <= STM_MAX)) { // ������ ü�� �Է�
		printf("madongseok stamina(%d ~ %d)>>> ", STM_MIN, STM_MAX);
		scanf_s("%d", &ma_stm);
	}

	while (!(PROB_MIN <= p && p <= PROB_MAX)) { // Ȯ�� �Է�
		printf("percentile probability 'p'(%d ~ %d)>>> ", PROB_MIN, PROB_MAX);
		scanf_s("%d", &p);
	}

	system("cls");


	///�ʱ� ����
	train_ex(len);
	train_init(len);
	train_ex(len);
	printf("\n\n");
	Sleep(3000);

	
	int zombie = len - 3;
	int civil = len - 6;
	int madong = len - 2;
	
	int scene = 1; // ¦�� Ƚ���� ���� ���߱� ���� ��� �� 
	while (1) {
		int madong_move = -1; // �������� �̵��� ���� ����

		srand((unsigned int)time(NULL)); // ����ð��� �������� ��� ���� ����
		int r = rand() % 100 + 1;  // 1 ~ 100 ������ ���� ����
		if (r > p) { // ������ P ���� ũ�� �̵�, �� (1-p)�� Ȯ���� �̵�
			civil--;
		}
		else {
			if (scene % 2 != 0) {
				zombie--;
			}
		}

		train_ex(len);
		train_inter(len, civil, zombie, scene, madong);
		train_ex(len);
		printf("\n");

		// �ùΰ� ������ �̵� ���
		if (scene % 2 == 0) {
			if (r > p) {
				printf("Citizen : %d -> %d\n", civil + 1, civil );
				printf("Zombie : Stay %d (can not move)\n", zombie );
			}
			else {
				printf("Citizen : Stay %d\n", civil );
				printf("Zombie : Stay %d (can not move)\n", zombie );
			}
		}
		else {
			if (r > p) {
				printf("Citizen : %d -> %d\n", civil + 1, civil );
				printf("Zombie : Stay %d \n", zombie );
			}
			else {
				printf("Citizen : Stay %d\n", civil );
				printf("Zombie : %d -> %d\n", zombie + 1, zombie );
			}
		}

		// ������ �̵� �Է� �� ���
		while (!(madong_move == 0 || madong_move == 1)) {
			printf("madongseock move(0 : stay, 1 : move) >> ");
			scanf_s("%d", &madong_move);
		}
		
		if (madong_move == 0) {

		}



		// �ù��� Ż�� �����ϰų� �������� ���ݴ����� ���� ���â
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
		Sleep(4000);
	}

	outro();


	return 0;
}
