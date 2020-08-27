#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	listload();
	if (selectmode() == 2) {
		password();
		printf("관리자 모드를 실행합니다\n");
		adminmenu();
		listwrite();
	}
	printf("학생 모드를 실행합니다\n");
	studentmenu();
	return 0;
}