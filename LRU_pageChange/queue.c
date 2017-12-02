#include "queue.h"
//ť�� �ʱ�ȭ��
void queue_init(void) {
	front = rear = 0;
	for (int i = 0; i < MAX; i++)
		frame[i] = -1;
}

//ť�� ���
void queue_clear(void) {
	front = rear;
}

//���������� 1, �ƴϸ� 0
//isFull���� ���� �߻�
int queue_isFull(void) {
	if ((rear + 1) % MAX == front)
		return 1;
	else
		return 0;
}

//ť�� �����͸� ����
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

//ť���� �����͸� ��
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
