#define _CRT_SECURE_NO_WARNIGS
#include "Info.h"
#include <stdio.h>
#include <time.h>

void clearBuffer(void) {
    while (getchar() != '\n');
}

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

void password()
{
    int temppassword;
    int password;
    int i;
    printf("��й�ȣ�� �Է����ּ���\n");
    scanf_s("%d", &password);
    i = 0;
    temppassword = password;
    while (1)
    {
        temppassword /= 10;
        i++;
        if (!temppassword)
        {
            break;
        }
    }
    if ((i) > 8)
        printf("��й�ȣ�� 8�ڸ��� �ʰ��Ͽ����ϴ�\n");
    while (password != 12345678)
    {
        printf("��й�ȣ�� ��ġ���� �ʽ��ϴ�\n");
        printf("��й�ȣ�� �Է����ּ���\n");
        scanf_s("%d", &password);
        i = 0;
        temppassword = password;
        while (1)
        {
            temppassword /= 10;
            i++;
            if (!temppassword)
            {
                break;
            }
        }
        if ((i) > 8)
            printf("��й�ȣ�� 8�ڸ��� �ʰ��Ͽ����ϴ�\n");
    }
}

void listload()
{
    bookinfo b[30] = { 0, };
    FILE* fp = fopen("bookinfo.txt", "r");
    for (int i = 0; i < 3; i++)
    {
        fgets(b[i].title, 50, fp);
        fgets(b[i].ISBN, 10, fp);
        fgets(b[i].author, 20, fp);
        fgets(b[i].publishhouse, 20, fp);
        fgets(b[i].publishyear, 20, fp);
        fgets(b[i].category, 10, fp);
        fgets(b[i].land, 10, fp);
    }
    fclose(fp);

}