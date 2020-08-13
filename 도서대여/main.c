#include <stdio.h>
#include <time.h>
#include "Info.h"

int main(void)
{
	int selectmode();
	if (selectmode() == 2) {
		printf("관리자 모드를 실행합니다\n");
		adminmenu();
	}
	else {
		printf("학생 모드를 실행합니다\n");
		studentmenu();
	}

	return 0;
}