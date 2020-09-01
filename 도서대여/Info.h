#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
typedef struct _bookinfo {
	char title[100];				//책 제목
	char ISBN[10];				//일련번호
	char author[50];				//저자
	char publishhouse[40];				//출판사
	char publishyear[10];				//출판년도
	char category[20];				//카테고리
	char land[20];				//대출가능여부
	char studentnum[12];
	char timestamp[10];
} bookinfo;

/*typedef struct _studentinfo {
	int studentnum;				//학번
	struct _rentinfo {
		int ISBN;				//일련번호
		int returnday;				//반납일까지 남은 일수
		int timestamp;		//대출일 타임스탬프
	};

} studentinfo;*/

int adminmenu();//관리자모드에서 추가,삭제 메뉴를 출력하고 입력받는 함수
void listadd();//책 정보를 추가하는 함수
void listdelete();//책 정보를 삭제하는 함수
int studentmenu();//검색, 대여, 반납 메뉴를 출력하고 입력받는 함수
int booksearch();//책을 검색하는 함수
void bookrent(int studentnumber);//책을 대여하는 함수
void bookreturn(int studentnumber);//책을 반납하는 함수	
void password();//관리자 비밀번호를 검사하는 함수
void clearBuffer();
void listload();
void listwrite();
void allsearch(char *m, char *n);// 구조체 배열포인터를 받아서 비교하는 함수