#include "Info.h"
#include <stdio.h>
#include <time.h>

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