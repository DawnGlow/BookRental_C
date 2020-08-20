#define _CRT_SECURE_NO_WARNIGS
#include "Info.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
bookinfo b[30] = { 0, };

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
    printf("bookinfo.txt���� å ������ �������� ���Դϴ�\n");
    FILE* fp = fopen("bookinfo.txt", "r");
    if (fp == NULL)
    {
        printf("������ �ҷ����µ� �����Ͽ����ϴ�\n");
        exit(1);
    }
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

void listadd()
{
    for (int i = 0; i < 3; i++) {
        if (strlen(b[i].title) == 0)
        {
            int k;
            printf("���� �Է� : \n");
            gets_s(b[i].title, sizeof(b[i].title));
            printf("ISBN �Է� : \n");
            gets_s(b[i].ISBN, sizeof(b[i].ISBN));
            printf("�۰� �Է� : \n");
            gets_s(b[i].author, sizeof(b[i].author));
            printf("���ǻ� �Է� : \n");
            gets_s(b[i].publishhouse, sizeof(b[i].publishhouse));
            printf("���ǳ⵵ �Է� : \n");
            gets_s(b[i].publishyear, sizeof(b[i].publishyear));
            printf("ī�װ� �Է� : \n");
            gets_s(b[i].category, sizeof(b[i].category));
            printf("���Ⱑ�ɿ��� �Է� : \n");
            gets_s(b[i].land, sizeof(b[i].land));

            printf("%d��° å ��Ͽ� �����߽��ϴ�. ������ �޴��� ���ư����� 1���� �Է����ּ���, ��� ����Ϸ��� 1���� ������ �ƹ� ���ڸ� �Է����ּ���\n", i + 1);
            scanf("%d", &k);
            if (k == 1)
                break;
            clearBuffer();
        }
        else
            continue;
    }

}

void listdelete()
{
    int* arr = (int*)malloc(sizeof(int) * 4);
    printf("ISBN�� �Է����ּ���(4�ڸ�) : ");
    scanf("%d", arr);
    for (int i = 0; i < 3; i++)
    {
        while ((*arr) == atoi(b[i].ISBN))
        {
            memset(&b[i], 0, sizeof(bookinfo));
        }
    }
    printf("�����Ͽ����ϴ�\n");
    free(arr);
    //�Ʒ� �ڵ�� �׽�Ʈ�� �ڵ��Դϴ�.
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
}