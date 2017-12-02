#include "lru.h"
#include "queue.h"

//히스토리, 프레임 초기화
void lru_init(int* frame, int* history) {
	for (int i = 0; i < MAX; i++) {
		*(frame + i) = -1;
		*(history + i) = 0;
	}
}

//해당 프레임에 필요한 페이지 번호가 존재하는지 찾아봄, 있으면 1 없으면 0
bool lru_isThere(int* frame, int pageNum) {
	for (int i = 0; i < MAX; i++) {
		if (*(frame + i) == pageNum) {
			return true;
		}
	}
	return false;
}
//히스토리에서 가장 오래된 인덱스 반환하는 함수
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

//히스토리와 프레임 상태 출력하는 함수
void lru_print_status(int* history, int* frame) {
	printf("현재 히스토리 상태 : ");
	for (int i = 0; i < MAX-1; i++) {
		printf("%d ", *(history + i));
	}
	printf("   ");
	printf("현재 프레임 상태 : ");
	for (int i = 0; i < MAX-1; i++) {
		printf("%d ", *(frame + i));
	}
	printf("\n");
}