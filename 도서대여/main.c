#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	
	while (1)
	{
		listload();
		printf("----------------------------------------\n");
		int a;
		printf("도서 대여 시스템에 접속합니다\n");
		printf("수행하실 작업 모드를 선택해주세요\n");
		printf("0. 프로그램 종료\n");
		printf("1. 학생(대출, 반납, 도서 검색)\n");
		printf("2. 관리자(도서 list 추가, 삭제)\n");
		printf("----------------------------------------\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			studentmenu();
			break;
		case 2:
			adminmenu();
			break;
		case 0:
			return 0;
		default:
			printf("잘못입력하셨습니다\n");
		}

	}
}