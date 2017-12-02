#include "queue.h"
//큐를 초기화함
void queue_init(void) {
	front = rear = 0;
	for (int i = 0; i < MAX; i++)
		frame[i] = -1;
}

//큐를 비움
void queue_clear(void) {
	front = rear;
}

//꽉차있으면 1, 아니면 0
//isFull에서 오류 발생
int queue_isFull(void) {
	if ((rear + 1) % MAX == front)
		return 1;
	else
		return 0;
}

//큐에 데이터를 삽입
int queue_put(int k) {
	int j = 0;
	if (queue_isFull()) {
		printf("Queue overflow.\n");
		return -1;
	}

	frame[rear] = k;
	j = rear;
	rear = ++rear % MAX;
	return j;
}

//큐에서 데이터를 뺌
int queue_get(void) {
	int i;
	if (front == rear) {
		printf("\n  Queue underflow.");
		return -1;
	}

	i = frame[front];
	front = ++front % MAX;
	return i;
}
