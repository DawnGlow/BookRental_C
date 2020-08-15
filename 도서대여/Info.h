#pragma once
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
typedef struct _bookinfo {
	char title[50];				//å ����
	int ISBN;				//�Ϸù�ȣ
	char author[20];				//����
	char publishhouse[20];				//���ǻ�
	int publishyear;				//���ǳ⵵
	int category;				//ī�װ�
	bool land;				//���Ⱑ�ɿ���
} bookinfo;

typedef struct _studentinfo {
	int studentnum;				//�й�
	struct _rentinfo {
		int ISBN;				//�Ϸù�ȣ
		int returnday;				//�ݳ��ϱ��� ���� �ϼ�
		int timestamp;		//������ Ÿ�ӽ�����
	};

} studentinfo;

int selectmode();//�����ڸ��� �л���� �� �ϳ��� �Է� �޾� �����Լ��� �����ϴ� �Լ�
void adminmenu();//�����ڸ�忡�� �߰�,���� �޴��� ����ϰ� �Է¹޴� �Լ�
void listadd();//å ������ �߰��ϴ� �Լ�
void listdelete();//å ������ �����ϴ� �Լ�
void s_rentinto(int a, char b);//�л� �뿩/�ݳ�/��ü ������ ����ϴ� �Լ�
int returnday();// �Ϸ縶�� �ݳ����� ���� �ϼ�(day)�� ���ҽ�Ű�� �뿩 ����(day)�� s_rentinfo�Լ��� �����ϴ� �Լ�
char returntitle();//�뿩 ����(title)�� s_rentinfo�Լ��� �����ϴ� �Լ�
void studentmenu();//�˻�, �뿩, �ݳ� �޴��� ����ϰ� �Է¹޴� �Լ�
void search();//å�� �˻��ϴ� �Լ�
void bookrent();//å�� �뿩�ϴ� �Լ�
void bookreturn();//å�� �ݳ��ϴ� �Լ�	
void password();//������ ��й�ȣ�� �˻��ϴ� �Լ�
