#include "lru.h"
#include "queue.h"

//�����丮, ������ �ʱ�ȭ
void lru_init(int* frame, int* history) {
	for (int i = 0; i < MAX; i++) {
		*(frame + i) = -1;
		*(history + i) = 0;
	}
}

//�ش� �����ӿ� �ʿ��� ������ ��ȣ�� �����ϴ��� ã�ƺ�, ������ 1 ������ 0
bool lru_isThere(int* frame, int pageNum) {
	for (int i = 0; i < MAX; i++) {
		if (*(frame + i) == pageNum) {
			return true;
		}
	}
	return false;
}
//�����丮���� ���� ������ �ε��� ��ȯ�ϴ� �Լ�
int lru_max_history_index(int* history) {
	int max = -1;
	int maxidx = 0;
	for (int i = 0; i < MAX; i++) {
		if (*(history + i) > max) {
			max = *(history + i);
			maxidx = i;
		}
	}
	return maxidx;
}

//�����丮�� ������ ���� ����ϴ� �Լ�
void lru_print_status(int* history, int* frame) {
	printf("���� �����丮 ���� : ");
	for (int i = 0; i < MAX-1; i++) {
		printf("%d ", *(history + i));
	}
	printf("   ");
	printf("���� ������ ���� : ");
	for (int i = 0; i < MAX-1; i++) {
		printf("%d ", *(frame + i));
	}
	printf("\n");
}