#define _CRT_SECURE_NO_WARNIGS
#include "Info.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 100
#define BooknumMax 30
#define StudentnumMax 10
#pragma warning(disable : 4996)
char* landinfo = "�뿩��\n";
char* landinfo2 = "�뿩����\n";
char* landinfo3 = "�뿩�Ұ�\n";
char* line = "\n";
bookinfo b[BooknumMax];
void clearBuffer(void) 
{
    while (getchar() != '\n');
}

int adminmenu()
{
    password();
    while (1)
    {
        int b;
        printf("----------------------------------------\n");
        printf("�����Ͻ� �۾��� �������ּ���\n");
        printf("0. ���� �޴��� ���ư���\n");
        printf("1. ���� �߰�\n");
        printf("2. ���� ����\n");
        printf("3. ���α׷� ����\n");
        printf("----------------------------------------\n");
        scanf("%d", &b);
        system("cls");
        switch (b)
        {
        case 1:
            listadd();
            break;
        case 2:
            listdelete();
            break;
        case 0:
            return 0;
        case 3:
            exit(1);
        default:
            printf("�޴� ��ȣ�� �߸� �Է��ϼ̽��ϴ�\n");
        }
    }
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
    printf("�ʱ�ȭ �� bookinfo.txt���� å ������ �������� ���Դϴ�\n");
    Sleep(1500);
    FILE* fp = fopen("bookinfo.txt", "rt");
    if (fp == NULL)
    {
        printf("������ �ҷ����µ� �����Ͽ����ϴ�\n");
        exit(1);
    }
    for (int i = 0; i < BooknumMax; i++)
    {
        fgets(b[i].title, 100, fp);
        fgets(b[i].ISBN, 10, fp);
        fgets(b[i].author, 50, fp);
        fgets(b[i].publishhouse, 40, fp);
        fgets(b[i].publishyear, 10, fp);
        fgets(b[i].category, 20, fp);
        fgets(b[i].land, 20, fp);
        fgets(b[i].studentnum, 12, fp);
        fgets(b[i].timestamp, 10, fp);
    }
    fclose(fp);
}

void listadd()
{
    int addcount = 0;
    for (int i = 0; i < BooknumMax; i++) {
        if (strlen(b[i].title) == 0)
        {
            int k;
            printf("���� �Է� : \n");
            clearBuffer();
            gets_s(b[i].title, sizeof(b[i].title));
            strcat(b[i].title, line);
            printf("ISBN �Է� : \n");
            gets_s(b[i].ISBN, sizeof(b[i].ISBN));
            strcat(b[i].ISBN, line);
            printf("�۰� �Է� : \n");
            gets_s(b[i].author, sizeof(b[i].author));
            strcat(b[i].author, line);
            printf("���ǻ� �Է� : \n");
            gets_s(b[i].publishhouse, sizeof(b[i].publishhouse));
            strcat(b[i].publishhouse, line);
            printf("���ǳ⵵ �Է� : \n");
            gets_s(b[i].publishyear, sizeof(b[i].publishyear));
            strcat(b[i].publishyear, line);
            printf("ī�װ� �Է� : \n");
            gets_s(b[i].category, sizeof(b[i].category));
            strcat(b[i].category, line);
            printf("�뿩���ɿ��� �Է�(�뿩����/�뿩�Ұ�) : \n");
            gets_s(b[i].land, sizeof(b[i].land));
            strcat(b[i].land, line);
            strcpy(b[i].studentnum, line);
            strcpy(b[i].timestamp, line);
            addcount++;
            printf("%d�ε����� å ����� �����߽��ϴ�. ������ �޴��� ���ư����� 1���� �Է����ּ���, ��� ����Ϸ��� 1���� ������ �ƹ� ���ڸ� �Է����ּ���\n", i + 1);
            scanf("%d", &k);
            if (k == 1)
                break;
            system("cls");
            clearBuffer();
        }
        else
            continue;
        
    }
    if (addcount == 0)
        printf("����Ʈ�� ���̻� å ����� �Ͻ� �� �����ϴ�.\n");
    else
    {
        printf("���� ����� ����մϴ�.\n");
        for (int i = 0; i < BooknumMax; i++)
        {
            printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
        }
        printf("�ùٸ��� �߰��ߴ��� Ȯ���Ͻʽÿ�.\n");
        printf("bookinfo.txt�� �߰��� å ������ �����մϴ�\n");
        listwrite();
    }
}

void listdelete()
{
    int* arr = (int*)malloc(sizeof(int) * 4);
    printf("ISBN�� �Է����ּ���(4�ڸ�) : ");
    scanf("%d", arr);
    system("cls");
    for (int i = 0; i < BooknumMax; i++)
    {
        while ((*arr) == atoi(b[i].ISBN))
        {
            memset(&b[i], 0, sizeof(bookinfo));
        }
    }
    printf("�����Ͽ����ϴ�\n");
    free(arr);
    printf("�ش� ���� ������ bookinfo.txt���� �����մϴ�.\n");
    printf("����Ʈ�� �ִ� ���� ����� ����մϴ�.\n");
    for (int i = 0; i < BooknumMax; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
    printf("�ùٸ��� �����ߴ��� Ȯ���Ͻʽÿ�.\n");
    listwrite();
}
void listwrite()
{
    FILE* fp = fopen("bookinfo.txt", "wt");
    for (int i = 0; i < BooknumMax; i++)
    {
        if (strlen(b[i].title) != 0) 
        {
            fprintf(fp, "%s%s%s%s%s%s%s%s%s", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land, b[i].studentnum, b[i].timestamp);
        }
        else
            continue;
    }
    fclose(fp);
}
int studentmenu()
{
    int studentnumber;
    int num_len = 0;
    int p = 1;
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

    for (int i = 0; i < StudentnumMax; i++)
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

    for (int i = 0; i < StudentnumMax; i++)
    {
        if (studentnumber != (atoi(n[i])))
            cnt++;
        else
            continue;
    }
    if (cnt == StudentnumMax)
        printf("�й��� �߸��Է��ϼ̽��ϴ�\n");
    while (cnt == StudentnumMax)
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
        for (int i = 0; i < StudentnumMax; i++)
        {
            if (studentnumber != (atoi(n[i])))
                cnt++;
            else
                continue;
        }
        if (cnt == 10)
            printf("�й��� �߸��Է��ϼ̽��ϴ�\n");
    }
    for (int i = 0; i < StudentnumMax; i++)
        free(n[i]);
    printf("�л���忡 �����߽��ϴ�\n");
    while (1) 
    {
        int choice;
        printf("----------------------------------------\n");
        printf("0. ���� �޴��� ���ư���\n");
        printf("1. ���� �˻�\n");
        printf("2. ���� ����\n");
        printf("3. ���� �ݳ�\n");
        printf("4. ���� ����Ʈ ���\n");
        printf("5. ���α׷� ����\n");
        printf("----------------------------------------\n");
        printf("�����Ͻ� �۾��� ����(�����Է�)���ּ���: ");
        clearBuffer();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            booksearch();
            break;
        case 2:
            bookrent(studentnumber);
            break;
        case 3:
            bookreturn(studentnumber);
            break;
        case 0:
            return 0;
        case 4:
            for (int i = 0; i < BooknumMax; i++)
            {
                printf("%s%s%s%s%s%s%s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
            }
            break;
        case 5:
            exit(1);
        default:
            printf("�޴� ��ȣ�� �߸� �Է��ϼ̽��ϴ�\n");
        }
    };
}

int booksearch()
{
    while (1)
    {
        int user_input;
        char user_search[30];
        printf("å �˻��ϱ�\n");
        printf("��� ������ �˻� �� ���ΰ���?\n");
        printf("1. å ���� �˻�\n");
        printf("2. ������ �˻�\n");
        printf("3. ���ǻ� �˻�\n");
        printf("4. �оߺ� �˻�\n");
        printf("5. ���� ���� ���κ� �˻�(�뿩����/�뿩��/�뿩�Ұ�)\n");
        printf("6. ���� �޴��� ���ư���\n");
        clearBuffer();
        scanf("%d", &user_input);
        switch (user_input)
        {
        case 1:
            printf("�˻��� �ܾ �Է����ּ���: ");
            scanf("%s", &user_search);
            allsearch(b[0].title, user_search);
            break;
        case 2:
            printf("�˻��� �ܾ �Է����ּ���: ");
            scanf("%s", &user_search);
            allsearch(b[0].author, user_search);
            break;
        case 3:
            printf("�˻��� �ܾ �Է����ּ���: ");
            scanf("%s", &user_search);
            allsearch(b[0].publishhouse, user_search);
            break;
        case 4:
            printf("�˻��� �ܾ �Է����ּ���: ");
            scanf("%s", &user_search);
            allsearch(b[0].category, user_search);
            break;
        case 5:
            printf("�˻��� �ܾ �Է����ּ���: ");
            scanf("%s", &user_search);
            allsearch(b[0].land, user_search);
            break;
        case 6:
            printf("���� �޴��� ���ư��ϴ�\n");
            Sleep(1000);
            system("cls");
            return 0;
        default:
            system("cls");
            printf("�߸��Է��ϼ̽��ϴ�\n");
            Sleep(2000);
            system("cls");
            break;
        }
    }
}

void allsearch(char* m, char* n)
{
    for (int i = 0; i < BooknumMax; i++)
    {
        char* ptr = strstr(m + i * sizeof(b[0]), n);
        if (ptr != NULL)
            printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
}

void bookrent(int studentnumber)
{
    int num;
    int p2 = 1;
    int isbnlen = 0;
    int booklistnum2 = 0;
    time_t start_t;
    start_t = time(NULL);
    int exeday = (int)start_t / 86400;
    printf("�뿩���� ���� ������ ������ �����ϴ�(������ ��µ��� �ʽ��ϴ�)\n");
    for (int i = 0; i < BooknumMax; i++)
    {
        if (strcmp(b[i].land, landinfo) == 0 && atoi(b[i].studentnum)==studentnumber)
        {
            if ((exeday - atoi(b[i].timestamp)) < 7)
            {
                printf("�̳� ������ å ������ ����մϴ�\n");
                printf("����: %s ISBN: %s ����: %s �ݳ��ϱ��� ���� �� ��: %d\n", b[i].title, b[i].ISBN, b[i].author, 7 - (exeday - atoi(b[i].timestamp)));
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) == 7)
            {
                printf("���� �ݳ� �ؾ��� å ������ ����մϴ�\n");
                printf("����: %s ISBN: %s ����: %s\n", b[i].title, b[i].ISBN, b[i].author);
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) > 7)
            {
                printf("��ä ������ å ������ ����մϴ�\n");
                printf("����: %s ISBN: %s ����: %s ��ä �� ��: %d\n", b[i].title, b[i].ISBN, b[i].author, exeday - atoi(b[i].timestamp)-7);
                printf("\n");
            }

        }
    }

    rentsection:
     printf("�����Ͻ� å�� �Ϸù�ȣ(ISBN)�� �Է����ּ���(0 �� �Է��ϸ� ���� �޴��� ���ư��ϴ�): ");
     scanf("%d", &num);
     if (num == 0)
         goto EXIT;
     while (num > p2)
     {
         p2 *= 10;
         isbnlen++;
     }
     while (isbnlen != 4)
     {
         p2 = 1;
         isbnlen = 0;
         printf("�Է��Ͻ� ���� �ڸ����� 4�ڸ����� ũ�ų� �۽��ϴ�.\n");
         printf("�Ϸù�ȣ(ISBN)�� �ٽ� �Է��� �ּ���(0 �� �Է��ϸ� ���� �޴��� ���ư��ϴ�): ");
         scanf("%d", &num);
         if (num == 0)
             goto EXIT;
         while (num > p2)
         {
             p2 *= 10;
             isbnlen++;
         }
     }

     for (int i = 0; i < BooknumMax; i++)
     {
         if (atoi(b[i].ISBN) != num)
             booklistnum2++;
     }
     if (booklistnum2 == BooknumMax)
     {
         printf("���� ����Ʈ�� ���� �Ϸù�ȣ(ISBN)�� �Է��ϼ̽��ϴ�\n");
         p2 = 1;
         isbnlen = 0;
         booklistnum2 = 0;
         goto rentsection;
     }
     int rentfail = 0;
     for (int i = 0; i < BooknumMax; i++)
     {
         if (atoi(b[i].ISBN) == num)
         {
             if (strcmp(b[i].land, landinfo) == 0 || strcmp(b[i].land, landinfo3) == 0)
             {
                 printf("���� �Ұ����� �����Դϴ�\n");
                 Sleep(1500);
                 system("cls");
                 rentfail = 1;
             }
             else 
             {
                 itoa(studentnumber, b[i].studentnum, 10);
                 strcat(b[i].studentnum, line);
                 time_t t;
                 t = time(NULL);
                 int daytime = (int)t / 86400;
                 itoa(daytime, b[i].timestamp, 10);
                 strcat(b[i].timestamp, line);
                 memset(&b[i].land, 0, sizeof(b[0].land));
                 strcpy(b[i].land, landinfo);
                 printf("%s���⿡ �����Ͽ����ϴ�\n", b[i].title);
             }
         }
     }
     if (rentfail != 1)
     {
         printf("bookinfo.txt�� �������Դϴ�\n");
         listwrite();
         printf("������ �Ϸ�Ǿ����ϴ�\n");
         Sleep(2000);
         system("cls");
         memset(b, 0, sizeof(b));
         listload();
     }
 EXIT:
     printf("\n");
}
void bookreturn(int studentnumber)
{
    int num;
    int p2 = 1;
    int isbnlen = 0;
    int returnnum;
    int checkcnt = 0;
    int booklistnum = 0;
    time_t start_t;
    start_t = time(NULL);
    int exeday = (int)start_t / 86400;
    printf("�뿩���� ���� ������ ������ �����ϴ�(������ ��µ��� �ʽ��ϴ�)\n");
    for (int i = 0; i < BooknumMax; i++)
    {
        if (strcmp(b[i].land, landinfo) == 0 && atoi(b[i].studentnum) == studentnumber)
        {
            if ((exeday - atoi(b[i].timestamp)) < 7)
            {
                printf("�̳� ������ å ������ ����մϴ�\n");
                printf("����: %s ISBN: %s ����: %s �ݳ��ϱ��� ���� �� ��: %d\n", b[i].title, b[i].ISBN, b[i].author, 7 - (exeday - atoi(b[i].timestamp)));
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) == 7)
            {
                printf("���� �ݳ� �ؾ��� å ������ ����մϴ�\n");
                printf("����: %s ISBN: %s ����: %s\n", b[i].title, b[i].ISBN, b[i].author);
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) > 7)
            {
                printf("��ä ������ å ������ ����մϴ�\n");
                printf("����: %s ISBN: %s ����: %s ��ä �� ��: %d\n", b[i].title, b[i].ISBN, b[i].author, exeday - atoi(b[i].timestamp) - 7);
                printf("\n");
            }

        }
    }
    //����ü�� ����� å �Ǽ��� count�ϴ� �ڵ�
    for (int i = 0; i < BooknumMax; i++)
    {
        if (strlen(b[i].title) != 0)
            booklistnum++;
    }
    intersection0:
    printf("�ݳ��Ͻ� å �Ǽ��� �Է����ּ���(0�� �Է��ϸ� �л����θ޴��� ���ư��ϴ�)\n");
    scanf("%d", &returnnum);
    if (returnnum >= booklistnum) 
    {
        printf("�Է��Ͻ� å �Ǽ��� ����Ʈ�� ����� å �Ǽ����� Ů�ϴ�\n");
        goto intersection0;
    }

    for (int i = 0; i < returnnum; i++) {
    intersection:
        printf("�ݳ��Ͻ� å�� �Ϸù�ȣ(ISBN)�� �Է����ּ���(1�� �Է��ϸ� ���� �Է�â���� ���ư��ϴ�): ");
        scanf("%d", &num);
        if (num == 1)
            goto intersection0;
        while (num >= p2)
        {
            p2 *= 10;
            isbnlen++;
        }
        while (isbnlen != 4)
        {
            p2 = 1;
            isbnlen = 0;
            printf("�Է��Ͻ� ���� �ڸ����� 4�ڸ����� ũ�ų� �۽��ϴ�.\n");
            printf("�Ϸù�ȣ(ISBN)�� �ٽ� �Է��� �ּ���(1�� �Է��ϸ� ���� �Է�â���� ���ư��ϴ�): ");
            scanf("%d", &num);
            if (num == 1)
                goto intersection0;
            while (num > p2)
            {
                p2 *= 10;
                isbnlen++;
            }
        }

        for (int i = 0; i < BooknumMax; i++)
        {
            if (atoi(b[i].ISBN) != num)
                checkcnt++;
        }
        if (checkcnt == BooknumMax)
        {
            printf("���� ����Ʈ�� ���� å�� �Ϸù�ȣ(ISBN)�� �Է��ϼ̽��ϴ�\n");
            p2 = 1;
            isbnlen = 0;
            checkcnt = 0;
            goto intersection;
        }

        for (int i = 0; i < BooknumMax; i++)
        {
            if (atoi(b[i].ISBN) == num && atoi(b[i].studentnum) != studentnumber)
            {
                printf("������ �뿩���� ���� �����Դϴ�\n");
                p2 = 1;
                isbnlen = 0;
                goto intersection;
            }
        }


        for (int i = 0; i < BooknumMax; i++)
        {
            if (atoi(b[i].ISBN) == num)
            {
                memset(&b[i].studentnum, 0, sizeof(b[0].studentnum));
                memset(&b[i].land, 0, sizeof(b[0].land));
                memset(&b[i].timestamp, 0, sizeof(b[0].timestamp));
                strcpy(b[i].land, landinfo2);
                printf("%s�ݳ��� �����Ͽ����ϴ�\n", b[i].title);
                printf("�Է��Ͻ� ������ ���������� �ݳ��Ǿ����ϴ�.\n");
            }
        }
    }
    if (returnnum != 0)
    {
        printf("bookinfo.txt�� �������Դϴ�\n");
        listwrite();
        printf("������ �Ϸ�Ǿ����ϴ�\n");
        Sleep(2000);
        system("cls");
        memset(b, 0, sizeof(b));
        listload();
    }
    else
    {
        printf("�ݳ��Ͻ� å�� ���°����� Ȯ���ϰ� �޴��� ���ư��ϴ�\n");
        Sleep(2000);
        system("cls");
    }
}