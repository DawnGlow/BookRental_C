#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	listload();
	if (selectmode() == 2) {
		password();
		printf("������ ��带 �����մϴ�\n");
		adminmenu();
		listwrite();
	}
	printf("�л� ��带 �����մϴ�\n");
	studentmenu();
	return 0;
}