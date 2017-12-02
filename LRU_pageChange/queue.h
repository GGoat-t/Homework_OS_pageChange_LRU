#pragma once
#include <stdio.h>
//필요 페이지보다 하나 높게 설정
#define MAX 4

int frame[MAX];
int front, rear;

void queue_init(void);
void queue_clear(void);
int queue_isFull(void);
int queue_put(int k);
int queue_get(void);