#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

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

	Sleep(2000);
	system("cls");
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
	Sleep(3000);
	system("cls");
	Sleep(3000);


	int zombie = len - 3;
	int civil = len - 6;

	while (1) {
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
				printf("Z");
				zombie--;
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
		train_ex(len);











		Sleep(4000);
	}




	return 0;
}