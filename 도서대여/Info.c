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