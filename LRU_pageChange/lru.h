#pragma once
#include <stdio.h>
#include <stdbool.h>

void lru_init(int* frame, int* history);
bool lru_isThere(int* frame, int pageNum);
int lru_max_history_index(int* history);
void lru_print_status(int* history, int* frame);