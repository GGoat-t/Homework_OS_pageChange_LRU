#pragma once
#include <stdio.h>
//�ʿ� ���������� �ϳ� ���� ����
#define MAX 4

int frame[MAX];
int front, rear;

void queue_init(void);
void queue_clear(void);
int queue_isFull(void);
int queue_put(int k);
int queue_get(void);