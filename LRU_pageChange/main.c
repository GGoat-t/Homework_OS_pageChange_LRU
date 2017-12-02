//LRU 페이지 대치 알고리즘 구현
//현재 프레임수를 원하는 인덱스 수보다 하나를 더줘야 제대로 돌아가는 문제가 발생함.
#include "lru.h"
#include "queue.h"
#include <stdlib.h>
#pragma warning(disable: 4996)

int main(int argc, const char** argv[]) {
	int* history = (int)malloc(sizeof(int)*MAX);
	int noPage = 0;

	//프레임, 히스토리 초기화
	lru_init(frame, history);

	int pageList[20] = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
	int pageListLength = (int)(sizeof(pageList) / sizeof(int));

	for (int j = 0; j < pageListLength; j++) {
		int tmp = 0;
		if (!lru_isThere(frame, pageList[j])) {
			noPage++;
			
			//프레임에 필요 페이지가 존재하지 않고 프레임이 꽉차있지 않으면 필요 페이지 삽입하고
			//삽입된 인덱스와 같은 값의 히스토리 인덱스의 값을 1 증가
			
			if (!(queue_isFull())) {
				tmp = queue_put(pageList[j]);
				history[tmp] += 1;
			}
			
			//프레임에 필요 페이지가 존재하지 않고 프레임이 꽉차있으면 히스토리를 비교해서
			//가장 높은 히스토리 값을 가지는 인덱스의 프레임 값과 필요 페이지를 치환
			//치환시 해당 값 히스토리 0으로 초기화하기.
			
			else {
				int maxidx = lru_max_history_index(history);
				frame[maxidx] = pageList[j];
				history[maxidx] = 0;
			}
		}
		
		//프레임에 필요 페이지가 존재하면 넘어가기
		else
			;
		//확인용.
		printf("현재 필요한 페이지는 %d이다.\n", pageList[j]);
		lru_print_status(history, frame);
		history[tmp] += 1;
		printf("--------------------------------------------------------------------\n");

	}

	printf("페이지 부재 발생 횟수는 %d회\n", noPage);

	return 0;
}
