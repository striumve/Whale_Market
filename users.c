#include "basic.h"

//��������
extern void userMenu(int i);
extern void userLogin_way1();
extern void userLogin_way2();
extern void userLogin_way3();
extern void home();
extern void showGoods(int count);
extern void buyGoods_show(int count, int bal);
extern int  buyGoods();

extern void userLogin() {
	cls();
	printf("1.�û�ID��¼ | 2.�绰�����¼ | 3.�û�����¼ | 4.����");
	printf("\n�������¼��ʽ��");
	int way = 0;
	scanf_s("%d", &way);
	switch (way) {
	case 1:
		userLogin_way1();
		break;
	case 2:
		userLogin_way2();
		break;
	case 3:
		userLogin_way3();
		break;
	case 4:
		home();
		break;
	default:
		printf("����ѡ�������ԡ�");
		Sleep(1250);
		userLogin();
		break;
	}
}

extern void userLogin_way1() {
	cls();
	printf("�������û�ID(����0�Է���) ��");
	int enterUID = 0, i, flag = 0;
	scanf_s("%d", &enterUID);
	if (enterUID == 0) { userLogin(); }

	for (i = 0; i < user_count; i++) {
		if (enterUID == user[i].UID) {
			flag = 1;
			printf("��");
			ENTER_PASSWORD_1:
			printf("�������룺");

			char enterPW[30];
			scanf_s("%s", enterPW, 30);
			if (strcmp(enterPW, user[i].password) == 0) {
				printf("\n�ɹ���¼");
				Sleep(1000);
				userMenu(i);
			}
			else {
				printf("�������������");
				goto ENTER_PASSWORD_1;
			}
		}
	}
	if (flag == 0) {
		printf("�޸��û���������");
		Sleep(1250);
		userLogin_way1();
	}
}

extern void userLogin_way2() {
	cls();
	printf("������绰���룺");
	char enterTel[30], is_exit[] = { "0" };
	int i, flag = 0;
	scanf_s("%s", enterTel, 30);
	if (strcmp(enterTel, is_exit) == 0) { userLogin(); }

	for (i = 0; i < user_count; i++) {
		if (strcmp(enterTel, user[i].tel) == 0) {
			flag = 1;
			printf("��");
			ENTER_PASSWORD_2:
			printf("�������룺");

			char enterPW[30];
			scanf_s("%s", enterPW, 30);
			if (strcmp(enterPW, user[i].password) == 0) {
				printf("\n�ɹ���¼");
				Sleep(1000);
				userMenu(i);
			}
			else {
				printf("�������������");
				goto ENTER_PASSWORD_2;
			}
		}
	}
	if (flag == 0) {
		printf("�޸��û�������������");
		Sleep(1250);
		userLogin_way2();
	}
}

extern void userLogin_way3() {
	cls();
	printf("�������û�����");
	char enterName[20], is_exit[] = { "0" };
	int i, flag = 0;
	scanf_s("%s", enterName, 20);
	if (strcmp(enterName, is_exit) == 0) { userLogin(); }

	for (i = 0; i < user_count; i++) {
		if (strcmp(enterName, user[i].name) == 0) {
			flag = 1;
			printf("��");
			ENTER_PASSWORD_3:
			printf("�������룺");

			char enterPW[30];
			scanf_s("%s", enterPW, 30);
			if (strcmp(enterPW, user[i].password) == 0) {
				printf("\n�ɹ���¼");
				Sleep(1000);
				userMenu(i);
			}
			else {
				printf("�������������");
				goto ENTER_PASSWORD_3;
			}
		}
	}
	if (flag == 0) {
		printf("�޸��û�������������");
		Sleep(1250);
		userLogin_way3();
	}
}

extern int userSignUp(int count) {
	cls();
	int i = count;
	int enterBos;
	//char enterName[20];

	printf("����-1�Է���\n");
	printf("\n���ǣ����(0) ���� ����(1)��������: ");
	scanf_s("%d", &enterBos);
	if (enterBos == -1) { home(); }
	else { user[i].bos = enterBos; }

	printf("�����������û�����");
	scanf_s("%s", &user[i].name, 20);
	if (strcmp(user[i].name, "-1") == 0) { home(); }

	printf("������������ϵ��ʽ���绰���룩��");
	scanf_s("%s", &user[i].tel, 15);
	if (strcmp(user[i].tel, "-1") == 0) { home(); }

	printf("���������ĵ�ַ��");
	scanf_s("%s", &user[i].address, 50);
	if (strcmp(user[i].address, "-1") == 0) { home(); }

	user[i].UID = 10000 + i + 1;
	printf("\n�����û�ID(UID)Ϊ:  %d  ,���μǡ�\n", user[i].UID);
	printf("\n����0�Լ�����");
	int next = 0;
	scanf_s("%d", &next);

	cls();
	printf("��������������(6~18λ�������֡���ĸ���»�����ɣ���");
	scanf_s("%s", &user[i].password, 20);
	printf("\n���μ��������롣");
	printf("\n����0�Լ�����");
	scanf_s("%d", &next);

	count++;
	return count;
}

extern void userMenu(int i) {
	cls();
	int choose = -1;
	if (user[i].bos == 0) {
		while (choose != 6) {
			shm(5);
			shm(1);
			scanf_s("%d", &choose);
			switch (choose) {
			case 1:
				buyGoods_show(goods_count, user[i].balance);
				break;
			case 2:

			case 3:

			case 4:

			case 5:

			case 6:
				break;
			default:
				printf("�޸ò����롣����ѡ��\n");
				Sleep(750);
				cls();
				break;
			}
		}
	}
	if (user[i].bos == 1) {
		while (choose != 6) {
			shm(6);
			shm(1);
			scanf_s("%d", &choose);
			switch (choose) {
			case 1:

			case 2:

			case 3:

			case 4:

			case 5:

			case 6:
				break;
			default:
				printf("�޸ò����롣����ѡ��\n");
				Sleep(750);
				cls();
				break;
			}
		}
	}
}

extern void showGoods(int count) {
	int i;
	cls_ad();
	printf("|��ƷID   |Ʒ��\t\t\t|�۸� \t|����       \t\t\t\t\t|״̬\n");
	for (i = 0; i < count; i++)
	{
		printf("|%d    ", goods[i].GID);
		printf("|%.20s\t", goods[i].name);
		printf("|%.2f\t", goods[i].price);
		printf("|%.60s\t", goods[i].des);
		if (goods[i].condition == 0) { printf("|����\n"); }
		if (goods[i].condition == 1) { printf("|������\n"); }
		if (goods[i].condition == 2) { printf("|���¼�\n"); }
	}
}

extern void buyGoods_show(int count, int bal) {
	int enterGID = -1;
	while (enterGID != 0) {
		cls();
		showGoods(goods_count);
		printf("\n������Ҫ�������Ʒ(������ƷID)(����0�Է���) :");
		scanf_s("%d", &enterGID);
		if (enterGID == 0) { break; }
		int i, flag = 0, project = 0, is_exit = 0;
		//search goods
		for (i = 0; i < goods_count; i++) {
			if (enterGID == goods[i].GID) {
				while (is_exit != 5) {
					//show goods information
					cls();
					printf("����Ʒ����Ϣ:\n\n");
					printf("|��ƷID   |Ʒ��\t\t\t|�۸� \t|����       \t\t\t\t\t|״̬\n");
					printf("|%d    ", goods[i].GID);
					printf("|%.20s\t", goods[i].name);
					printf("|%.2f\t", goods[i].price);
					printf("|%.60s\t", goods[i].des);
					printf("|%d\n\n", goods[i].condition);
					flag = 1;
					is_exit = admin_chgdinfo(project, i);
					//function "admin(chgdinfo)" returns "project", project 5 refers to coming back(exit)
					if (is_exit == 5) { break; }
				}
			}
		}
		if (flag == 0) {
			printf("\nUndefined GID.Please try again.\n");
			Sleep(1500);
			cls();
		}
	}






















	/*
	//bal: balance
	int enterGID = -1;
	while (enterGID != 0) {
		int i = 0, flag = 0, is_exit = -1;
		cls();
		showGoods(goods_count);
		printf("\n������Ҫ�������Ʒ(������ƷID)(����0�Է���) :");
		scanf_s("%d", &enterGID);
		if (enterGID == 0) {
			cls();
			break;

			//enterGID = is_exit;
			//flag = 1;  //���û����䣬forѭ��֮���жϡ�flag == 0�������ʾ���޸���Ʒ��
			//cls();
			//buyGoods(goods_count, user[i].balance);
		}
		//search goods
		for (i = 0; i < goods_count; i++) {
			if (enterGID == goods[i].GID) {
				int isBuy = 1;
				while (isBuy != 0) {
					//show goods information
					cls();
					printf("����Ʒ����Ϣ:\n\n");
					printf("|��ƷID   |Ʒ��\t\t\t|�۸� \t|����       \t\t\t\t\t|״̬\n");
					printf("|%d    ", goods[i].GID);
					printf("|%.20s\t", goods[i].name);
					printf("|%.2f\t", goods[i].price);
					printf("|%.60s\t", goods[i].des);
					if (goods[i].condition == 1) { 
						printf("|������\n"); 
						printf("\n����Ʒ����������ʱ�޷�������ѡ��������Ʒ��");
						Sleep(3000);
						buyGoods(goods_count, user[i].balance);
					}
					if (goods[i].condition == 2) { 
						printf("|���¼�\n");
						printf("\n����Ʒ���¼ܣ���ʱ�޷�������ѡ��������Ʒ��");
						Sleep(3000);
						buyGoods(goods_count, user[i].balance);
					}
					if (goods[i].condition == 0) { 
						printf("|����\n"); 
					}
					flag = 1;

					WRONG_CHOOSE:
					printf("\n��ȷ��Ҫ�������Ʒ��?(0:��, 1:��) :");
					scanf_s("%d", &isBuy);
					if (isBuy == 0) { buyGoods(goods_count, user[i].balance); }
					if (isBuy == 1) {
						printf("\n�����빺��������");
						int number = 1;
						scanf_s("%d", &number);
						printf("\n��Ʒ�ܼ�Ϊ��%.2f", goods[i].price * number);
						if (bal < goods[i].price * number) {
							printf("\n\n���㡣");
							printf("\n��ֵ��ڣ�5.����->3.��ֵ");
							printf("\n����0�Լ���: ");
							int next = 0;
							scanf_s("%d", &next);
							buyGoods(goods_count, user[i].balance);
						}
					}
					else {
						printf("����ѡ������ѡ��");
						Sleep(2000);
						goto WRONG_CHOOSE;
					}
				}
			}
		}
		if (flag == 0) {
			printf("\n�޸���Ʒ�������ԡ�\n");
			Sleep(1250);
			cls();
		}
	}

	*/
}

extern int buyGoods() {

}