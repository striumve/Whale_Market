#include "basic.h"

//��������
extern void userLogin();
extern int userSignUp(int count);
extern void adminLogin();
extern void userMenu(int i);

extern void home() {
	int choose = 0;
	while (choose != 4) {
		cls();
		shm(2);
		shm(1);
		scanf_s("%d", &choose); 
		switch (choose)
		{
		case 1:
			userLogin();
			break;
		case 2:
			user_count = userSignUp(user_count);
			userMenu(user_count - 1);
			break;
		case 3:
			adminLogin();
			break;
		case 4:
			break;
		default:
			printf("�޸ò����롣����ѡ��\n");
			Sleep(750);
			cls();
			break; 
		}
	}
}
