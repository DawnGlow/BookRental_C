#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
typedef struct _bookinfo {
	char title[100];				//å ����
	char ISBN[10];				//�Ϸù�ȣ
	char author[50];				//����
	char publishhouse[40];				//���ǻ�
	char publishyear[10];				//���ǳ⵵
	char category[20];				//ī�װ�
	char land[20];				//���Ⱑ�ɿ���
	char studentnum[12];
	char timestamp[10];
} bookinfo;

/*typedef struct _studentinfo {
	int studentnum;				//�й�
	struct _rentinfo {
		int ISBN;				//�Ϸù�ȣ
		int returnday;				//�ݳ��ϱ��� ���� �ϼ�
		int timestamp;		//������ Ÿ�ӽ�����
	};

} studentinfo;*/

int adminmenu();//�����ڸ�忡�� �߰�,���� �޴��� ����ϰ� �Է¹޴� �Լ�
void listadd();//å ������ �߰��ϴ� �Լ�
void listdelete();//å ������ �����ϴ� �Լ�
int studentmenu();//�˻�, �뿩, �ݳ� �޴��� ����ϰ� �Է¹޴� �Լ�
int booksearch();//å�� �˻��ϴ� �Լ�
void bookrent(int studentnumber);//å�� �뿩�ϴ� �Լ�
void bookreturn(int studentnumber);//å�� �ݳ��ϴ� �Լ�	
void password();//������ ��й�ȣ�� �˻��ϴ� �Լ�
void clearBuffer();
void listload();
void listwrite();
void allsearch(char *m, char *n);// ����ü �迭�����͸� �޾Ƽ� ���ϴ� �Լ�