#include "Info.h"
#include <stdio.h>
#include <time.h>

int selectmode()
{
	int a;
	printf("���� �뿩 �ý��ۿ� �����մϴ�\n");
	printf("�����Ͻ� �۾� ��带 �������ּ���\n");
	printf("1. �л�(����, �ݳ�, ���� �˻�)\n");
	printf("2. ������(���� list �߰�, ����)\n");
	scanf_s("%d", &a);
	return a;
}

void adminmenu()
{
	int b;
	printf("�����Ͻ� �۾��� �������ּ���\n");
	printf("1. ���� �߰�\n");
	printf("2. ���� ����\n");
	scanf_s("%d", &b);
	if (b == 1)
		listadd();
	else
		listdelete();
}