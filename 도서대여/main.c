#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	listload();
	int selectmode();
	if (selectmode() == 2) {
		password();
		printf("������ ��带 �����մϴ�\n");
		adminmenu();
	}
	else {
		printf("�л� ��带 �����մϴ�\n");
		studentmenu();
	}

	return 0;
}