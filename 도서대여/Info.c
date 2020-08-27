#define _CRT_SECURE_NO_WARNIGS
#include "Info.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 100
#pragma warning(disable : 4996)
bookinfo b[3] = { 0, };

typedef struct tm tm;
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
        fgets(b[i].studentnum, 8, fp);
        fgets(b[i].timestamp, 10, fp);
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
    printf("���� ����� ����մϴ�.\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
    printf("�ùٸ��� �߰��ߴ��� Ȯ���Ͻʽÿ�.\n");

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
    printf("���� ����� ����մϴ�.\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
    printf("�ùٸ��� �����ߴ��� Ȯ���Ͻʽÿ�.\n");
}
void listwrite()
{
    FILE* fp = fopen("bookinfo.txt", "wt");
    for (int i = 0; i < 3; i++)
    {
        if (strlen(b[i].title) != 0)
            fwrite(&b[i], sizeof(b[i]), 1, fp);
        else
            continue;
    }
    fclose(fp);
}
void studentmenu()
{
    int studentnumber;
    int num_len = 0;
    int p = 1;
    int choice;
    int cnt = 0;
    char* studentnum;
    char* n[10];
    FILE* fp = NULL;

    fp = fopen("studentnum.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "������¿���!\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        studentnum = (char*)malloc(sizeof(char) * MAX);
        fgets(studentnum, MAX, fp);
        n[i] = studentnum;
    }

    fclose(fp);

    printf("�й��� �Է��� �ּ���: ");
    scanf("%d", &studentnumber);
    while (studentnumber > p)
    {
        p *= 10;
        num_len++;
    }
    while (num_len != 8)
    {
        p = 1;
        num_len = 0;
        printf("�Է��Ͻ� ���� �ڸ����� 8�ڸ����� ũ�ų� �۽��ϴ�.\n");
        printf("�й��� �ٽ� �Է��� �ּ���: ");
        scanf("%d", &studentnumber);
        while (studentnumber > p)
        {
            p *= 10;
            num_len++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (studentnumber != (atoi(n[i])))
            cnt++;
        else
            continue;
    }
    if (cnt == 10)
        printf("�й��� �߸��Է��ϼ̽��ϴ�\n");
    while (cnt == 10)
    {
        cnt = 0;
        printf("�й��� �ٽ� �Է����ּ���: ");
        scanf("%d", &studentnumber);
        p = 1;
        num_len = 0;
        while (studentnumber > p)
        {
            p *= 10;
            num_len++;
        }
        while (num_len != 8)
        {
            p = 1;
            num_len = 0;
            printf("�Է��Ͻ� ���� �ڸ����� 8�ڸ����� ũ�ų� �۽��ϴ�.\n");
            printf("�й��� �ٽ� �Է��� �ּ���: ");
            scanf("%d", &studentnumber);
            while (studentnumber > p)
            {
                p *= 10;
                num_len++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (studentnumber != (atoi(n[i])))
                cnt++;
            else
                continue;
        }
        if (cnt == 10)
            printf("�й��� �߸��Է��ϼ̽��ϴ�\n");
    }
    for (int i = 0; i < 10; i++)
        free(n[i]);
    printf("�л���忡 �����߽��ϴ�\n");
    printf("1. ���� �˻�\n");
    printf("2. ���� ����\n");
    printf("3. ���� �ݳ�\n");
    printf("�����Ͻ� �۾��� ����(�����Է�)���ּ���: ");
    scanf("%d", &choice);
    if (choice == 1)
        booksearch();
   /* else if (choice == 2)
        bookrent(studentnumber);
    else if (choice == 3)
        bookreturn(studentnumber);
    else
        printf("�޴� ��ȣ�� �߸� �Է��ϼ̽��ϴ�\n");
        */
}

void booksearch()
{
    int user_input;
    char user_search[30];

    system("cls");
    printf("å �˻��ϱ�\n");
    printf("��� ������ �˻� �� ���ΰ���?\n");
    printf("1. å ���� �˻�\n");
    printf("2. ������ �˻�\n");
    printf("3. ���ǻ� �˻�\n");
    printf("4. �оߺ� �˻�\n");
    printf("5. ���� ���� ���κ� �˻�(���Ⱑ��/����Ұ�)\n");

    scanf("%d", &user_input);
    system("cls");

    printf("�˻��� �ܾ �Է����ּ��� : ");
    scanf_s("%s", user_search, sizeof(user_search));
    system("cls");      //ȭ�� �����
    if (user_input == 1) 
    {
        allsearch(b[0].title, user_search);
    }
    else if (user_input == 2)
    {
        allsearch(b[0].author, user_search);
    }
    else if (user_input == 3)
    {
        allsearch(b[0].publishhouse, user_search);
    }
    else if (user_input == 4)
    {
        allsearch(b[0].category, user_search);
    }
    else if (user_input == 5)
    {
        allsearch(b[0].land, user_search);
    }
    else {
        system("cls");
        printf("�ٽ� �Է����ּ���");
        Sleep(2000);
        system("cls");   //ȭ�� �����
    }

}

void allsearch(char* m, char* n)
{
    for (int i = 0; i < 3; i++)
    {
        char* ptr = strstr(m + i * sizeof(b[0]), n);
        if (ptr != NULL)
            printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
}

void bookrent(int s_num)
{
    int bp;
    time_t ltime;
    tm* today;
    time(&ltime);
    today = (localtime(&ltime));

}
/*    printf("�����Ͻ� å�� �Ϸù�ȣ(ISBN)�� �Է����ּ���: ");
    scanf("%d", &num);
    for (int i = 0; i < 3; i++)
    {
        char* ptr1 = &b[i].studentnum;
        while (atoi(b[i].ISBN) == num)
        {

        }
    }
}*/
