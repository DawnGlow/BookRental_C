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
char* landinfo = "대여중\n";
char* landinfo2 = "대여가능\n";
char* landinfo3 = "대여불가\n";
typedef struct tm tm;
void clearBuffer(void) 
{
    while (getchar() != '\n');
}

int adminmenu()
{
    while (1)
    {
        int b;
        printf("----------------------------------------\n");
        printf("수행하실 작업을 선택해주세요\n");
        printf("0. 메인 메뉴로 돌아가기\n");
        printf("1. 도서 추가\n");
        printf("2. 도서 삭제\n");
        printf("3. 프로그램 종료\n");
        printf("----------------------------------------\n");
        scanf("%d", &b);
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
            printf("메뉴 번호를 잘못 입력하셨습니다\n");
        }
    }
}

void password()
{
    int temppassword;
    int password;
    int i;
    printf("비밀번호를 입력해주세요\n");
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
        printf("비밀번호가 8자리를 초과하였습니다\n");
    while (password != 12345678)
    {
        printf("비밀번호가 일치하지 않습니다\n");
        printf("비밀번호를 입력해주세요\n");
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
            printf("비밀번호가 8자리를 초과하였습니다\n");
    }
}

void listload()
{
    printf("bookinfo.txt에서 책 정보를 가져오는 중입니다\n");
    FILE* fp = fopen("bookinfo.txt", "rt");
    if (fp == NULL)
    {
        printf("파일을 불러오는데 실패하였습니다\n");
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
        fgets(b[i].studentnum, 12, fp);
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
            printf("제목 입력 : \n");
            gets_s(b[i].title, sizeof(b[i].title));
            printf("ISBN 입력 : \n");
            gets_s(b[i].ISBN, sizeof(b[i].ISBN));
            printf("작가 입력 : \n");
            gets_s(b[i].author, sizeof(b[i].author));
            printf("출판사 입력 : \n");
            gets_s(b[i].publishhouse, sizeof(b[i].publishhouse));
            printf("출판년도 입력 : \n");
            gets_s(b[i].publishyear, sizeof(b[i].publishyear));
            printf("카테고리 입력 : \n");
            gets_s(b[i].category, sizeof(b[i].category));
            printf("대출가능여부 입력 : \n");
            gets_s(b[i].land, sizeof(b[i].land));

            printf("%d번째 책 등록에 성공했습니다. 관리자 메뉴로 돌아가려면 1번을 입력해주세요, 계속 등록하려면 1번을 제외한 아무 문자를 입력해주세요\n", i + 1);
            scanf("%d", &k);
            if (k == 1)
                break;
            clearBuffer();
        }
        else
            continue;
        
    }
    printf("도서 목록을 출력합니다.\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
    printf("올바르게 추가했는지 확인하십시오.\n");
    printf("bookinfo.txt에 추가된 책 정보를 저장합니다\n");
    listwrite();
}

void listdelete()
{
    int* arr = (int*)malloc(sizeof(int) * 4);
    printf("ISBN을 입력해주세요(4자리) : ");
    scanf("%d", arr);
    for (int i = 0; i < 3; i++)
    {
        while ((*arr) == atoi(b[i].ISBN))
        {
            memset(&b[i], 0, sizeof(bookinfo));
        }
    }
    printf("삭제하였습니다\n");
    free(arr);
    printf("해당 도서 정보를 bookinfo.txt에서 삭제합니다.\n");
    printf("도서 목록을 출력합니다.\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
    printf("올바르게 삭제했는지 확인하십시오.\n");
    listwrite();
}
void listwrite()
{
    FILE* fp = fopen("bookinfo.txt", "wt");
    for (int i = 0; i < 3; i++)
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
        fprintf(stderr, "파일출력에러!\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        studentnum = (char*)malloc(sizeof(char) * MAX);
        fgets(studentnum, MAX, fp);
        n[i] = studentnum;
    }

    fclose(fp);

    printf("학번을 입력해 주세요: ");
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
        printf("입력하신 수의 자리수가 8자리보다 크거나 작습니다.\n");
        printf("학번을 다시 입력해 주세요: ");
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
        printf("학번을 잘못입력하셨습니다\n");
    while (cnt == 10)
    {
        cnt = 0;
        printf("학번을 다시 입력해주세요: ");
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
            printf("입력하신 수의 자리수가 8자리보다 크거나 작습니다.\n");
            printf("학번을 다시 입력해 주세요: ");
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
            printf("학번을 잘못입력하셨습니다\n");
    }
    for (int i = 0; i < 10; i++)
        free(n[i]);
    printf("학생모드에 접속했습니다\n");
    while (1) 
    {
        int choice;
        printf("----------------------------------------\n");
        printf("0. 메인 메뉴로 돌아가기\n");
        printf("1. 도서 검색\n");
        printf("2. 도서 대출\n");
        printf("3. 도서 반납\n");
        printf("4. 프로그램 종료\n");
        printf("----------------------------------------\n");
        printf("수행하실 작업을 선택(숫자입력)해주세요: ");
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
            exit(1);
        default:
            printf("메뉴 번호를 잘못 입력하셨습니다\n");
        }
    };
}

void booksearch()
{
    int user_input;
    char user_search[30];

    system("cls");
    printf("책 검색하기\n");
    printf("어느 것으로 검색 할 것인가요?\n");
    printf("1. 책 제목 검색\n");
    printf("2. 지은이 검색\n");
    printf("3. 출판사 검색\n");
    printf("4. 분야별 검색\n");
    printf("5. 대출 가능 여부별 검색(대여가능/대여중/대여불가)\n");

    scanf("%d", &user_input);
    system("cls");

    printf("검색할 단어를 입력해주세요 : ");
    scanf_s("%s", user_search, sizeof(user_search));
    system("cls");      //화면 지우기
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
        printf("다시 입력해주세요");
        Sleep(2000);
        system("cls");   //화면 지우기
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

void bookrent(int studentnumber)
{
    int num;
    int p2 = 1;
    int isbnlen = 0;
    time_t start_t;
    start_t = time(NULL);
    int exeday = (int)start_t / 86400;
    printf("대여중인 도서 정보는 다음과 같습니다(없으면 출력되지 않습니다)\n");
    for (int i = 0; i < 3; i++) 
    {
        if (strcmp(b[i].land, landinfo) == 0 && atoi(b[i].studentnum)==studentnumber)
        {
            if ((exeday - atoi(b[i].timestamp)) < 7)
            {
                printf("미납 상태인 책 정보를 출력합니다\n");
                printf("제목: %s ISBN: %s 저자: %s 반납일까지 남은 일 수: %d\n", b[i].title, b[i].ISBN, b[i].author, 7 - (exeday - atoi(b[i].timestamp)));
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) == 7)
            {
                printf("오늘 반납 해야할 책 정보를 출력합니다\n");
                printf("제목: %s ISBN: %s 저자: %s\n", b[i].title, b[i].ISBN, b[i].author);
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) > 7)
            {
                printf("연채 상태인 책 정보를 출력합니다\n");
                printf("제목: %s ISBN: %s 저자: %s 연채 일 수: %d\n", b[i].title, b[i].ISBN, b[i].author, exeday - atoi(b[i].timestamp)-7);
                printf("\n");
            }

        }
    }


     printf("대출하실 책의 일련번호(ISBN)를 입력해주세요: ");
     scanf("%d", &num);
     while (num > p2)
     {
         p2 *= 10;
         isbnlen++;
     }
     while (isbnlen != 4)
     {
         p2 = 1;
         isbnlen = 0;
         printf("입력하신 수의 자리수가 4자리보다 크거나 작습니다.\n");
         printf("일련번호(ISBN)를 다시 입력해 주세요: ");
         scanf("%d", &num);
         while (num > p2)
         {
             p2 *= 10;
             isbnlen++;
         }
     }
     int rentfail;
     for (int i = 0; i < 3; i++)
     {
         if (atoi(b[i].ISBN) == num)
         {
             if (strcmp(b[i].land, landinfo) == 0 || strcmp(b[i].land, landinfo3) == 0)
             {
                 printf("대출 불가능한 도서입니다\n");
                 rentfail = 1;
             }
             else 
             {
                 itoa(studentnumber, b[i].studentnum, 10);
                 time_t t;
                 t = time(NULL);
                 int daytime = (int)t / 86400;
                 itoa(daytime, b[i].timestamp, 10);
                 memset(&b[i].land, 0, sizeof(b[0].land));
                 strcpy(b[i].land, landinfo);
                 printf("%s대출에 성공하였습니다\n", b[i].title);
             }
         }
     }
     if (rentfail != 1)
     {
         printf("bookinfo.txt에 저장중입니다\n");
         listwrite();
         printf("저장이 완료되었습니다\n");
     }
}
void bookreturn(int studentnumber)
{
    int num;
    int p2 = 1;
    int isbnlen = 0;
    int returnnum;
    time_t start_t;
    start_t = time(NULL);
    int exeday = (int)start_t / 86400;
    printf("대여중인 도서 정보는 다음과 같습니다(없으면 출력되지 않습니다)\n");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(b[i].land, landinfo) == 0 && atoi(b[i].studentnum) == studentnumber)
        {
            if ((exeday - atoi(b[i].timestamp)) < 7)
            {
                printf("미납 상태인 책 정보를 출력합니다\n");
                printf("제목: %s ISBN: %s 저자: %s 반납일까지 남은 일 수: %d\n", b[i].title, b[i].ISBN, b[i].author, 7 - (exeday - atoi(b[i].timestamp)));
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) == 7)
            {
                printf("오늘 반납 해야할 책 정보를 출력합니다\n");
                printf("제목: %s ISBN: %s 저자: %s\n", b[i].title, b[i].ISBN, b[i].author);
                printf("\n");
            }
            else if ((exeday - atoi(b[i].timestamp)) > 7)
            {
                printf("연채 상태인 책 정보를 출력합니다\n");
                printf("제목: %s ISBN: %s 저자: %s 연채 일 수: %d\n", b[i].title, b[i].ISBN, b[i].author, exeday - atoi(b[i].timestamp) - 7);
                printf("\n");
            }

        }
    }
    printf("반납하실 책 권수를 입력해주세요\n");
    scanf("%d", &returnnum);
    for (int i = 0; i < returnnum; i++) {
        intersection:
        printf("반납하실 책의 일련번호(ISBN)를 입력해주세요: ");
        scanf("%d", &num);
        while (num > p2)
        {
            p2 *= 10;
            isbnlen++;
        }
        while (isbnlen != 4)
        {
            p2 = 1;
            isbnlen = 0;
            printf("입력하신 수의 자리수가 4자리보다 크거나 작습니다.\n");
            printf("일련번호(ISBN)를 다시 입력해 주세요: ");
            scanf("%d", &num);
            while (num > p2)
            {
                p2 *= 10;
                isbnlen++;
            }
        }
        for (int i = 0; i < 3; i++) 
        {
            if (atoi(b[i].ISBN) == num && atoi(b[i].studentnum) != studentnumber)
            {
                printf("본인이 대여하지 않은 도서입니다\n");
                goto intersection;
            }
        }
        
        for (int i = 0; i < 3; i++)
        {
            if (atoi(b[i].ISBN) == num)
            {
                memset(&b[i].studentnum, 0, sizeof(b[0].studentnum));
                memset(&b[i].land, 0, sizeof(b[0].land));
                memset(&b[i].timestamp, 0, sizeof(b[0].timestamp));
                strcpy(b[i].land, landinfo2);
                printf("%s반납에 성공하였습니다\n", b[i].title);
                printf("입력하신 도서가 정상적으로 반납되엇습니다.\n");
            }
        }
    }
    printf("bookinfo.txt에 저장중입니다\n");
    listwrite();
    printf("저장이 완료되었습니다\n");
}