#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	int selectmode();
	if (selectmode() == 2) {
		printf("������ ��带 �����մϴ�\n");
		adminmenu();
	}
	else {
		printf("�л� ��带 �����մϴ�\n");
		studentmenu();
	}

	return 0;
}