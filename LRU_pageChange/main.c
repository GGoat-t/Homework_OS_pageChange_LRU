//LRU ������ ��ġ �˰��� ����
//���� �����Ӽ��� ���ϴ� �ε��� ������ �ϳ��� ����� ����� ���ư��� ������ �߻���.
#include "lru.h"
#include "queue.h"
#include <stdlib.h>
#pragma warning(disable: 4996)

int main(int argc, const char** argv[]) {
	int* history = (int)malloc(sizeof(int)*MAX);
	int noPage = 0;

	//������, �����丮 �ʱ�ȭ
	lru_init(frame, history);

	int pageList[20] = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
	int pageListLength = (int)(sizeof(pageList) / sizeof(int));

	for (int j = 0; j < pageListLength; j++) {
		int tmp = 0;
		if (!lru_isThere(frame, pageList[j])) {
			noPage++;
			
			//�����ӿ� �ʿ� �������� �������� �ʰ� �������� �������� ������ �ʿ� ������ �����ϰ�
			//���Ե� �ε����� ���� ���� �����丮 �ε����� ���� 1 ����
			
			if (!(queue_isFull())) {
				tmp = queue_put(pageList[j]);
				history[tmp] += 1;
			}
			
			//�����ӿ� �ʿ� �������� �������� �ʰ� �������� ���������� �����丮�� ���ؼ�
			//���� ���� �����丮 ���� ������ �ε����� ������ ���� �ʿ� �������� ġȯ
			//ġȯ�� �ش� �� �����丮 0���� �ʱ�ȭ�ϱ�.
			
			else {
				int maxidx = lru_max_history_index(history);
				frame[maxidx] = pageList[j];
				history[maxidx] = 0;
			}
		}
		
		//�����ӿ� �ʿ� �������� �����ϸ� �Ѿ��
		else
			;
		//Ȯ�ο�.
		printf("���� �ʿ��� �������� %d�̴�.\n", pageList[j]);
		lru_print_status(history, frame);
		history[tmp] += 1;
		printf("--------------------------------------------------------------------\n");

	}

	printf("������ ���� �߻� Ƚ���� %dȸ\n", noPage);

	return 0;
}
