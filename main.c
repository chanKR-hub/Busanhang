#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define LEN_MIN 15
#define LEN_MAX 90
#define PROB_MIN 10
#define PROB_MAX 90


void intro() {
	printf(" ____                                  _   _                        \n");
	printf("| __ )   _   _   ___    __ _   _ __   | | | |   ___   _ __     __ _ \n");
	printf("|  _ \\  | | | | / __|  / _` | | '_ \\  | |_| |  / _ \\ | '_ \\   / _` |\n");
	printf("| |_) | | |_| | \\__ \\ | (_| | | | | | |  _  | |  __/ | | | | | (_| |\n");
	printf("|____/   \\__,_| |___/  \\__,_| |_| |_| |_| |_|  \\___| |_| |_|  \\__, |\n");
	printf("                                                              |___/ \n");

	Sleep(3000);
	system("cls");
}

void outro() {
	printf(" ____                                  _   _                        \n");
	printf("| __ )   _   _   ___    __ _   _ __   | | | |   ___   _ __     __ _ \n");
	printf("|  _ \\  | | | | / __|  / _` | | '_ \\  | |_| |  / _ \\ | '_ \\   / _` |\n");
	printf("| |_) | | |_| | \\__ \\ | (_| | | | | | |  _  | |  __/ | | | | | (_| |\n");
	printf("|____/   \\__,_| |___/  \\__,_| |_| |_| |_| |_|  \\___| |_| |_|  \\__, |\n");
	printf("                                                              |___/ \n");


}


void train_ex(int len) {
	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			printf("#\n");
			break;
		}
		printf("#");
	}
}

void train_in(int len) {
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




int main() {
	intro();
	int len; // ���� ����
	printf("train lengh(%d ~ %d)>>> ", LEN_MIN, LEN_MAX);
	scanf_s("%d", &len);
	if (len < LEN_MIN || LEN_MAX < len) {
		printf("\n\n���̸� �߸� �Է��ϼ̽��ϴ�.\n\n");
		printf("\n\n��ȭ�� �����մϴ�\n\n");

		return 0;
	}


	int p; // Ȯ��
	printf("percentile probability 'p'(%d ~ %d)>>> ", PROB_MIN, PROB_MAX);
	scanf_s("%d", &p);
	if (p < PROB_MIN || PROB_MAX < p) {
		printf("\n\nȮ���� �߸� �Է��ϼ̽��ϴ�.\n\n");
		printf("\n\n��ȭ�� �����մϴ�\n\n");

		return 0;
	}
	
	system("cls");


	///�ʱ� ����
	train_ex(len);
	train_in(len);
	train_ex(len);
	printf("\n\n");
	Sleep(3000);

	
	int zombie = len - 3;
	int civil = len - 6;
	
	int phase = 1; // ¦�� Ƚ���� ���� ���߱� ���� ��� �� 
	while (1) {
		srand((unsigned int)time(NULL)); // ����ð��� �������� ��� ���� ����
		int r = rand() % 100 + 1;  // 1 ~ 100 ������ ���� ����
		if (r > p) { // ������ P ���� ũ�� �̵�, �� (1-p)�� Ȯ���� �̵�
			civil--;
		}
		else {
			if (phase % 2 != 0) {
				zombie--;
			}
		}

		train_ex(len);
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
				if (phase % 2 == 0) {
					printf("Z");
					continue;
				}
				else {
					printf("Z");
					continue;
				}
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
		train_ex(len);
		printf("\n");

		if (phase % 2 == 0) {
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
		/*
		if (r > p) { 
			if (phase % 2 == 0) {
				printf("Citizen : %d -> %d\n", civil + 2, civil + 1);
				printf("Zombie : Stay %d (can not move)\n", zombie + 1);
			}
			else {
				printf("Citizen : %d -> %d\n", civil + 2, civil + 1);
				printf("Zombie : Stay %d\n", zombie + 1);
			}
		}
		else {
			printf("Citizen : Stay %d\n", civil+1);
			printf("Zombie : %d -> %d\n", zombie + 2, zombie + 1);
		}
		*/

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
		phase++;
		Sleep(4000);
	}

	outro();


	return 0;
}
