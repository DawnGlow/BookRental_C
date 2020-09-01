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
char* landinfo = "대여중\n";
char* landinfo2 = "대여가능\n";
char* landinfo3 = "대여불가\n";
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
        printf("수행하실 작업을 선택해주세요\n");
        printf("0. 메인 메뉴로 돌아가기\n");
        printf("1. 도서 추가\n");
        printf("2. 도서 삭제\n");
        printf("3. 프로그램 종료\n");
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
    printf("초기화 후 bookinfo.txt에서 책 정보를 가져오는 중입니다\n");
    Sleep(1500);
    FILE* fp = fopen("bookinfo.txt", "rt");
    if (fp == NULL)
    {
        printf("파일을 불러오는데 실패하였습니다\n");
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
            printf("제목 입력 : \n");
            clearBuffer();
            gets_s(b[i].title, sizeof(b[i].title));
            strcat(b[i].title, line);
            printf("ISBN 입력 : \n");
            gets_s(b[i].ISBN, sizeof(b[i].ISBN));
            strcat(b[i].ISBN, line);
            printf("작가 입력 : \n");
            gets_s(b[i].author, sizeof(b[i].author));
            strcat(b[i].author, line);
            printf("출판사 입력 : \n");
            gets_s(b[i].publishhouse, sizeof(b[i].publishhouse));
            strcat(b[i].publishhouse, line);
            printf("출판년도 입력 : \n");
            gets_s(b[i].publishyear, sizeof(b[i].publishyear));
            strcat(b[i].publishyear, line);
            printf("카테고리 입력 : \n");
            gets_s(b[i].category, sizeof(b[i].category));
            strcat(b[i].category, line);
            printf("대여가능여부 입력(대여가능/대여불가) : \n");
            gets_s(b[i].land, sizeof(b[i].land));
            strcat(b[i].land, line);
            strcpy(b[i].studentnum, line);
            strcpy(b[i].timestamp, line);
            addcount++;
            printf("%d인덱스에 책 등록을 성공했습니다. 관리자 메뉴로 돌아가려면 1번을 입력해주세요, 계속 등록하려면 1번을 제외한 아무 문자를 입력해주세요\n", i + 1);
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
        printf("리스트에 더이상 책 등록을 하실 수 없습니다.\n");
    else
    {
        printf("도서 목록을 출력합니다.\n");
        for (int i = 0; i < BooknumMax; i++)
        {
            printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
        }
        printf("올바르게 추가했는지 확인하십시오.\n");
        printf("bookinfo.txt에 추가된 책 정보를 저장합니다\n");
        listwrite();
    }
}

void listdelete()
{
    int* arr = (int*)malloc(sizeof(int) * 4);
    printf("ISBN을 입력해주세요(4자리) : ");
    scanf("%d", arr);
    system("cls");
    for (int i = 0; i < BooknumMax; i++)
    {
        while ((*arr) == atoi(b[i].ISBN))
        {
            memset(&b[i], 0, sizeof(bookinfo));
        }
    }
    printf("삭제하였습니다\n");
    free(arr);
    printf("해당 도서 정보를 bookinfo.txt에서 삭제합니다.\n");
    printf("리스트에 있는 도서 목록을 출력합니다.\n");
    for (int i = 0; i < BooknumMax; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
    printf("올바르게 삭제했는지 확인하십시오.\n");
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
        fprintf(stderr, "파일출력에러!\n");
        exit(1);
    }

    for (int i = 0; i < StudentnumMax; i++)
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

    for (int i = 0; i < StudentnumMax; i++)
    {
        if (studentnumber != (atoi(n[i])))
            cnt++;
        else
            continue;
    }
    if (cnt == StudentnumMax)
        printf("학번을 잘못입력하셨습니다\n");
    while (cnt == StudentnumMax)
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
        for (int i = 0; i < StudentnumMax; i++)
        {
            if (studentnumber != (atoi(n[i])))
                cnt++;
            else
                continue;
        }
        if (cnt == 10)
            printf("학번을 잘못입력하셨습니다\n");
    }
    for (int i = 0; i < StudentnumMax; i++)
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
        printf("4. 도서 리스트 출력\n");
        printf("5. 프로그램 종료\n");
        printf("----------------------------------------\n");
        printf("수행하실 작업을 선택(숫자입력)해주세요: ");
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
            printf("메뉴 번호를 잘못 입력하셨습니다\n");
        }
    };
}

int booksearch()
{
    while (1)
    {
        int user_input;
        char user_search[30];
        printf("책 검색하기\n");
        printf("어느 것으로 검색 할 것인가요?\n");
        printf("1. 책 제목 검색\n");
        printf("2. 지은이 검색\n");
        printf("3. 출판사 검색\n");
        printf("4. 분야별 검색\n");
        printf("5. 대출 가능 여부별 검색(대여가능/대여중/대여불가)\n");
        printf("6. 이전 메뉴로 돌아가기\n");
        clearBuffer();
        scanf("%d", &user_input);
        switch (user_input)
        {
        case 1:
            printf("검색할 단어를 입력해주세요: ");
            scanf("%s", &user_search);
            allsearch(b[0].title, user_search);
            break;
        case 2:
            printf("검색할 단어를 입력해주세요: ");
            scanf("%s", &user_search);
            allsearch(b[0].author, user_search);
            break;
        case 3:
            printf("검색할 단어를 입력해주세요: ");
            scanf("%s", &user_search);
            allsearch(b[0].publishhouse, user_search);
            break;
        case 4:
            printf("검색할 단어를 입력해주세요: ");
            scanf("%s", &user_search);
            allsearch(b[0].category, user_search);
            break;
        case 5:
            printf("검색할 단어를 입력해주세요: ");
            scanf("%s", &user_search);
            allsearch(b[0].land, user_search);
            break;
        case 6:
            printf("이전 메뉴로 돌아갑니다\n");
            Sleep(1000);
            system("cls");
            return 0;
        default:
            system("cls");
            printf("잘못입력하셨습니다\n");
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
    printf("대여중인 도서 정보는 다음과 같습니다(없으면 출력되지 않습니다)\n");
    for (int i = 0; i < BooknumMax; i++)
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

    rentsection:
     printf("대출하실 책의 일련번호(ISBN)를 입력해주세요(0 을 입력하면 이전 메뉴로 돌아갑니다): ");
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
         printf("입력하신 수의 자리수가 4자리보다 크거나 작습니다.\n");
         printf("일련번호(ISBN)를 다시 입력해 주세요(0 을 입력하면 이전 메뉴로 돌아갑니다): ");
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
         printf("도서 리스트에 없는 일련번호(ISBN)을 입력하셨습니다\n");
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
                 printf("대출 불가능한 도서입니다\n");
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
                 printf("%s대출에 성공하였습니다\n", b[i].title);
             }
         }
     }
     if (rentfail != 1)
     {
         printf("bookinfo.txt에 저장중입니다\n");
         listwrite();
         printf("저장이 완료되었습니다\n");
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
    printf("대여중인 도서 정보는 다음과 같습니다(없으면 출력되지 않습니다)\n");
    for (int i = 0; i < BooknumMax; i++)
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
    //구조체에 저장된 책 권수를 count하는 코드
    for (int i = 0; i < BooknumMax; i++)
    {
        if (strlen(b[i].title) != 0)
            booklistnum++;
    }
    intersection0:
    printf("반납하실 책 권수를 입력해주세요(0을 입력하면 학생메인메뉴로 돌아갑니다)\n");
    scanf("%d", &returnnum);
    if (returnnum >= booklistnum) 
    {
        printf("입력하신 책 권수가 리스트에 저장된 책 권수보다 큽니다\n");
        goto intersection0;
    }

    for (int i = 0; i < returnnum; i++) {
    intersection:
        printf("반납하실 책의 일련번호(ISBN)를 입력해주세요(1을 입력하면 이전 입력창으로 돌아갑니다): ");
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
            printf("입력하신 수의 자리수가 4자리보다 크거나 작습니다.\n");
            printf("일련번호(ISBN)를 다시 입력해 주세요(1을 입력하면 이전 입력창으로 돌아갑니다): ");
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
            printf("도서 리스트에 없는 책의 일련번호(ISBN)을 입력하셨습니다\n");
            p2 = 1;
            isbnlen = 0;
            checkcnt = 0;
            goto intersection;
        }

        for (int i = 0; i < BooknumMax; i++)
        {
            if (atoi(b[i].ISBN) == num && atoi(b[i].studentnum) != studentnumber)
            {
                printf("본인이 대여하지 않은 도서입니다\n");
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
                printf("%s반납에 성공하였습니다\n", b[i].title);
                printf("입력하신 도서가 정상적으로 반납되엇습니다.\n");
            }
        }
    }
    if (returnnum != 0)
    {
        printf("bookinfo.txt에 저장중입니다\n");
        listwrite();
        printf("저장이 완료되었습니다\n");
        Sleep(2000);
        system("cls");
        memset(b, 0, sizeof(b));
        listload();
    }
    else
    {
        printf("반납하실 책이 없는것으로 확인하고 메뉴로 돌아갑니다\n");
        Sleep(2000);
        system("cls");
    }
}