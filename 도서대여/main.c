#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	
	while (1)
	{
		listload();
		printf("----------------------------------------\n");
		int a;
		printf("���� �뿩 �ý��ۿ� �����մϴ�\n");
		printf("�����Ͻ� �۾� ��带 �������ּ���\n");
		printf("0. ���α׷� ����\n");
		printf("1. �л�(����, �ݳ�, ���� �˻�)\n");
		printf("2. ������(���� list �߰�, ����)\n");
		printf("----------------------------------------\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			studentmenu();
			break;
		case 2:
			adminmenu();
			break;
		case 0:
			return 0;
		default:
			printf("�߸��Է��ϼ̽��ϴ�\n");
		}

	}
}