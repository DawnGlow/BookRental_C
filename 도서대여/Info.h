#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
typedef struct _bookinfo {
	char title[50];				//책 제목
	int ISBN;				//일련번호
	char author[20];				//저자
	char publishhouse[20];				//출판사
	int publishyear;				//출판년도
	int category;				//카테고리
	bool land;				//대출가능여부
} bookinfo;

typedef struct _studentinfo {
	int studentnum;				//학번
	struct _rentinfo {
		int ISBN;				//일련번호
		int returnday;				//반납일까지 남은 일수
		int timestamp;		//대출일 타임스탬프
	};

} studentinfo;

int selectmode();//관리자모드와 학생모드 중 하나를 입력 받아 메인함수에 리턴하는 함수
void adminmenu();//관리자모드에서 추가,삭제 메뉴를 출력하고 입력받는 함수
void listadd();//책 정보를 추가하는 함수
void listdelete();//책 정보를 삭제하는 함수
void s_rentinto(int a, char b);//학생 대여/반납/연체 정보를 출력하는 함수
int returnday();// 하루마다 반납까지 남은 일수(day)를 감소시키고 대여 정보(day)를 s_rentinfo함수에 전달하는 함수
char returntitle();//대여 정보(title)를 s_rentinfo함수에 전달하는 함수
void studentmenu();//검색, 대여, 반납 메뉴를 출력하고 입력받는 함수
void search();//책을 검색하는 함수
void bookrent();//책을 대여하는 함수
void bookreturn();//책을 반납하는 함수	
void password();//관리자 비밀번호를 검사하는 함수
