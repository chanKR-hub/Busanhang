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

	printf("\n\n");
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

void aggro_dec(int aggro) { // ���� �ȿ��� ��׷� ���� �����ִ� �Լ� -- 0���� �۾����� �ּڰ��� 0���� �ʱ�ȭ
	aggro--;
	if (aggro < 0) {
		aggro == 0;
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

	int aggro_civil = 1; // �ù� ��׷�
	int aggro_madon = 1; // ������ ��׷�

	int action_ma = 0; // ������ �ൿ

	int aggro_temp = 0;
	int stm_temp = 0;

	
	int scene = 1; // ¦�� Ƚ���� ���� ���߱� ���� ��� �� 
	boolean flag = 0; // ó������ �������� ���񿷿��־ �׶� ���� ü���� ������ ���� �ʹ� ���� ���� �� ���Ƽ�, ���� ����ϸ� �� flag������ TRUE�� ���� �� ���� ���� �������� �����ϸ� ü���� ���̰� �������.
	boolean flag_pulled = 0; // �������� PULL�� �����ϸ� TRUE, �����ϸ� FALSE �� �ʱ�ȭ �Ͽ� TRUE�̸� ���� ��������.
	while (1) {
		int madong_move = -1; // �������� �̵��� ���� ����

		srand((unsigned int)time(NULL)); // ����ð��� �������� ��� ���� ����
		int r = rand() % 100 + 1;  // 1 ~ 100 ������ ���� ����
		if (r > p) { // ������ P ���� ũ�� �̵�, �� (1-p)�� Ȯ���� �̵�
			civil--;
			aggro_civil++;
			if (aggro_civil > 5) {
				aggro_civil = 5;
			}
		}
		else {
			if (scene % 2 != 0 && flag_pulled == 0) {
				if ((madong - zombie) > 1 && (aggro_madon > aggro_civil)) {
					zombie++;
					aggro_civil--;
					if (aggro_civil < 0) {
						aggro_civil = 0;
					}
					if (madong - zombie == 1 && flag == 1) {
						ma_stm--;
					}

				}
				else {
					zombie--;
					flag = 1;
					aggro_civil--;
					if (aggro_civil < 0) {
						aggro_civil = 0;
					}
				}

			}
		}

		train_ex(len);
		train_inter(len, civil, zombie, scene, madong);
		train_ex(len);
		printf("\n");


		// 2-3 <�̵�>
		// �ùΰ� ������ �̵� ���
		if (scene % 2 == 0 || flag_pulled == 1) { // ¦�� ��° ��� (���� �������̴� ���)
			if (r > p) {
				printf("Citizen : %d -> %d (aggro : %d)\n", civil + 1, civil, aggro_civil);
				printf("Zombie : Stay %d (can not move)\n", zombie );
			}
			else {
				printf("Citizen : Stay %d (aggro : %d)\n", civil, aggro_civil);
				printf("Zombie : Stay %d (can not move)\n", zombie );
			}
		}
		else { // Ȧ �� ��° ��� (���� ������ �� �ִ� ���)
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

		// ������ �̵� �Է� �� ���
		while (!(madong_move == MOVE_LEFT || madong_move == MOVE_STAY)) {
			printf("madongseock move(0 : stay, 1 : move) >> ");
			scanf_s("%d", &madong_move);
		}
		printf("\n");



		if (madong_move == MOVE_LEFT) {
			madong--;
			aggro_madon++;
			if (aggro_madon > 5) {
				aggro_madon = 5;
			}


			train_ex(len);
			train_inter(len, civil, zombie, scene, madong);
			train_ex(len);
			printf("\n");

			printf("madongseok: %d --> %d (aggro : %d, stamina : %d)\n", madong+1, madong, aggro_madon, ma_stm);
			printf("citizen does nothing\n");
			if ((zombie - civil == 1) || (madong - zombie == 1)) {
				if (zombie - civil == 1) {
					printf("zombie attcks citizen\n");
				}
				else {
					if (flag == 1) {
						printf("zombie attcks madongseock\n");
					}


				}
			}
			else {
				printf("zombie attcks nobody\n");

			}
			printf("....\n");
		}
		else if (madong_move == MOVE_STAY) {
			aggro_madon--;
			ma_stm++;
			if (ma_stm > 5) {
				ma_stm = 5;
			}

			if (aggro_madon < 0) {
				aggro_madon = 0;
			}
			train_ex(len);
			train_inter(len, civil, zombie, scene, madong);
			train_ex(len);
			printf("\n");

			printf("madongseok: stay %d (aggro : %d -- > %d, stamina : %d)\n", madong, aggro_madon+1,aggro_madon, ma_stm);
			printf("citizen does nothing\n");
			if ((zombie - civil == 1) || ((madong - zombie == 1)&&flag==1)) {
				if (zombie - civil == 1) {
					printf("zombie attcks citizen\n");
				}
				else {
					
					printf("zombie attcks madongseock\n");
					ma_stm--;
					


				}
			}
			else {
				
				printf("zombie attcks nobody\n");

			}
			printf("....\n");
			

		}

		//2-4 <�ൿ>
		printf("madongseokaction(0.rest, 1.provoke, 2. pull)>> ");
		scanf_s("%d", &action_ma);
		switch (action_ma)
		{
		case 0: // rest ........
			printf("madongseck rest...........\n");
			stm_temp = ma_stm;
			aggro_temp = aggro_madon;
			aggro_madon--;
			if (aggro_madon < 0) {
				aggro_madon = 0;
			}
			ma_stm++;
			if (ma_stm > 5) {
				ma_stm = 5;
			}
			aggro_dec(aggro_madon);
			printf("madongseok: 7 (aggro : %d -- > %d, stamina : %d -- > %d)\n",aggro_temp, aggro_madon, stm_temp,ma_stm);

			break;

		
		case 1: // 1. revoke
			aggro_temp = aggro_madon;
			aggro_madon = AGGRO_MAX;
			aggro_civil = AGGRO_MIN;
			printf("madongseok provoked zombie...!!!\n");
			printf("madongseok: 7 (aggro : %d --> %d)\n", aggro_temp,aggro_madon);
			break;

		case 2: // 2. pull
			printf("madongseok pulled zombie...!!!\n");
			if (r > p) {
				printf("madongseokpulled zombie... Next turn, it can't move\n");
				flag_pulled = 1;
				aggro_temp = aggro_madon;
				aggro_madon += 2;
				if (aggro_madon > 5) {
					aggro_madon = 5;
				}
				stm_temp = ma_stm;
				ma_stm--;
				printf("madongseok: 7 (aggro : %d --> %d, stamina : %d -- > %d)\n", aggro_temp, aggro_madon, stm_temp, ma_stm);
			}
			else {
				aggro_temp = aggro_madon;
				aggro_madon += 2;
				if (aggro_madon > 5) {
					aggro_madon = 5;
				}
				stm_temp = ma_stm;
				ma_stm--;
				flag_pulled = 0;
				printf("madongseok failed to pull zombie\n");
				printf("madongseok: 7 (aggro : %d -- >%d, stamina : %d -- > %d)\n", aggro_temp, aggro_madon, stm_temp, ma_stm);

			}
		default:
			break;
		}




		// �ù��� Ż�� �����ϰų� �������� ���ݴ����� ���� ���â
		if (civil == 1) {
			printf("\nSUCCESS!\n");
			printf("citizen(s) escaped to the next train\n");
			break;
		}
		if (zombie - civil == 1 || ma_stm == STM_MIN) {
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
