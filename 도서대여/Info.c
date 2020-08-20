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
	printf("도서 대여 시스템에 접속합니다\n");
	printf("수행하실 작업 모드를 선택해주세요\n");
	printf("1. 학생(대출, 반납, 도서 검색)\n");
	printf("2. 관리자(도서 list 추가, 삭제)\n");
	scanf_s("%d", &a);
	return a;
}

void adminmenu()
{
	int b;
	printf("수행하실 작업을 선택해주세요\n");
	printf("1. 도서 추가\n");
	printf("2. 도서 삭제\n");
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
    FILE* fp = fopen("bookinfo.txt", "r");
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
    //아래 코드는 테스트용 코드입니다.
    for (int i = 0; i < 3; i++)
    {
        printf("%s %s %s %s %s %s %s\n", b[i].title, b[i].ISBN, b[i].author, b[i].publishhouse, b[i].publishyear, b[i].category, b[i].land);
    }
}