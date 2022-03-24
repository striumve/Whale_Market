#include "basic.h"

//函数声明
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
	printf("1.用户ID登录 | 2.电话号码登录 | 3.用户名登录 | 4.返回");
	printf("\n请输入登录方式：");
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
		printf("错误选择，请重试。");
		Sleep(1250);
		userLogin();
		break;
	}
}

extern void userLogin_way1() {
	cls();
	printf("请输入用户ID(输入0以返回) ：");
	int enterUID = 0, i, flag = 0;
	scanf_s("%d", &enterUID);
	if (enterUID == 0) { userLogin(); }

	for (i = 0; i < user_count; i++) {
		if (enterUID == user[i].UID) {
			flag = 1;
			printf("请");
			ENTER_PASSWORD_1:
			printf("输入密码：");

			char enterPW[30];
			scanf_s("%s", enterPW, 30);
			if (strcmp(enterPW, user[i].password) == 0) {
				printf("\n成功登录");
				Sleep(1000);
				userMenu(i);
			}
			else {
				printf("密码错误，请重新");
				goto ENTER_PASSWORD_1;
			}
		}
	}
	if (flag == 0) {
		printf("无该用户，请重试");
		Sleep(1250);
		userLogin_way1();
	}
}

extern void userLogin_way2() {
	cls();
	printf("请输入电话号码：");
	char enterTel[30], is_exit[] = { "0" };
	int i, flag = 0;
	scanf_s("%s", enterTel, 30);
	if (strcmp(enterTel, is_exit) == 0) { userLogin(); }

	for (i = 0; i < user_count; i++) {
		if (strcmp(enterTel, user[i].tel) == 0) {
			flag = 1;
			printf("请");
			ENTER_PASSWORD_2:
			printf("输入密码：");

			char enterPW[30];
			scanf_s("%s", enterPW, 30);
			if (strcmp(enterPW, user[i].password) == 0) {
				printf("\n成功登录");
				Sleep(1000);
				userMenu(i);
			}
			else {
				printf("密码错误，请重新");
				goto ENTER_PASSWORD_2;
			}
		}
	}
	if (flag == 0) {
		printf("无该用户，请重新输入");
		Sleep(1250);
		userLogin_way2();
	}
}

extern void userLogin_way3() {
	cls();
	printf("请输入用户名：");
	char enterName[20], is_exit[] = { "0" };
	int i, flag = 0;
	scanf_s("%s", enterName, 20);
	if (strcmp(enterName, is_exit) == 0) { userLogin(); }

	for (i = 0; i < user_count; i++) {
		if (strcmp(enterName, user[i].name) == 0) {
			flag = 1;
			printf("请");
			ENTER_PASSWORD_3:
			printf("输入密码：");

			char enterPW[30];
			scanf_s("%s", enterPW, 30);
			if (strcmp(enterPW, user[i].password) == 0) {
				printf("\n成功登录");
				Sleep(1000);
				userMenu(i);
			}
			else {
				printf("密码错误，请重新");
				goto ENTER_PASSWORD_3;
			}
		}
	}
	if (flag == 0) {
		printf("无该用户，请重新输入");
		Sleep(1250);
		userLogin_way3();
	}
}

extern int userSignUp(int count) {
	cls();
	int i = count;
	int enterBos;
	//char enterName[20];

	printf("输入-1以返回\n");
	printf("\n您是：买家(0) 还是 卖家(1)？请输入: ");
	scanf_s("%d", &enterBos);
	if (enterBos == -1) { home(); }
	else { user[i].bos = enterBos; }

	printf("请输入您的用户名：");
	scanf_s("%s", &user[i].name, 20);
	if (strcmp(user[i].name, "-1") == 0) { home(); }

	printf("请输入您的联系方式（电话号码）：");
	scanf_s("%s", &user[i].tel, 15);
	if (strcmp(user[i].tel, "-1") == 0) { home(); }

	printf("请输入您的地址：");
	scanf_s("%s", &user[i].address, 50);
	if (strcmp(user[i].address, "-1") == 0) { home(); }

	user[i].UID = 10000 + i + 1;
	printf("\n您的用户ID(UID)为:  %d  ,请牢记。\n", user[i].UID);
	printf("\n输入0以继续：");
	int next = 0;
	scanf_s("%d", &next);

	cls();
	printf("请设置您的密码(6~18位，由数字、字母及下划线组成）：");
	scanf_s("%s", &user[i].password, 20);
	printf("\n请牢记您的密码。");
	printf("\n输入0以继续：");
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
				printf("无该操作码。请重选。\n");
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
				printf("无该操作码。请重选。\n");
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
	printf("|商品ID   |品名\t\t\t|价格 \t|描述       \t\t\t\t\t|状态\n");
	for (i = 0; i < count; i++)
	{
		printf("|%d    ", goods[i].GID);
		printf("|%.20s\t", goods[i].name);
		printf("|%.2f\t", goods[i].price);
		printf("|%.60s\t", goods[i].des);
		if (goods[i].condition == 0) { printf("|待售\n"); }
		if (goods[i].condition == 1) { printf("|已售罄\n"); }
		if (goods[i].condition == 2) { printf("|已下架\n"); }
	}
}

extern void buyGoods_show(int count, int bal) {
	int enterGID = -1;
	while (enterGID != 0) {
		cls();
		showGoods(goods_count);
		printf("\n请输入要购买的商品(输入商品ID)(输入0以返回) :");
		scanf_s("%d", &enterGID);
		if (enterGID == 0) { break; }
		int i, flag = 0, project = 0, is_exit = 0;
		//search goods
		for (i = 0; i < goods_count; i++) {
			if (enterGID == goods[i].GID) {
				while (is_exit != 5) {
					//show goods information
					cls();
					printf("该商品的信息:\n\n");
					printf("|商品ID   |品名\t\t\t|价格 \t|描述       \t\t\t\t\t|状态\n");
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
		printf("\n请输入要购买的商品(输入商品ID)(输入0以返回) :");
		scanf_s("%d", &enterGID);
		if (enterGID == 0) {
			cls();
			break;

			//enterGID = is_exit;
			//flag = 1;  //如果没有这句，for循环之后判断“flag == 0”后会提示“无该商品”
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
					printf("该商品的信息:\n\n");
					printf("|商品ID   |品名\t\t\t|价格 \t|描述       \t\t\t\t\t|状态\n");
					printf("|%d    ", goods[i].GID);
					printf("|%.20s\t", goods[i].name);
					printf("|%.2f\t", goods[i].price);
					printf("|%.60s\t", goods[i].des);
					if (goods[i].condition == 1) { 
						printf("|已售罄\n"); 
						printf("\n该商品已售罄，暂时无法购买。请选择其它商品。");
						Sleep(3000);
						buyGoods(goods_count, user[i].balance);
					}
					if (goods[i].condition == 2) { 
						printf("|已下架\n");
						printf("\n该商品已下架，暂时无法购买。请选择其它商品。");
						Sleep(3000);
						buyGoods(goods_count, user[i].balance);
					}
					if (goods[i].condition == 0) { 
						printf("|待售\n"); 
					}
					flag = 1;

					WRONG_CHOOSE:
					printf("\n您确定要购买该商品吗?(0:否, 1:是) :");
					scanf_s("%d", &isBuy);
					if (isBuy == 0) { buyGoods(goods_count, user[i].balance); }
					if (isBuy == 1) {
						printf("\n请输入购买数量：");
						int number = 1;
						scanf_s("%d", &number);
						printf("\n商品总价为：%.2f", goods[i].price * number);
						if (bal < goods[i].price * number) {
							printf("\n\n余额不足。");
							printf("\n充值入口：5.更多->3.充值");
							printf("\n输入0以继续: ");
							int next = 0;
							scanf_s("%d", &next);
							buyGoods(goods_count, user[i].balance);
						}
					}
					else {
						printf("错误选择，请重选。");
						Sleep(2000);
						goto WRONG_CHOOSE;
					}
				}
			}
		}
		if (flag == 0) {
			printf("\n无该商品，请重试。\n");
			Sleep(1250);
			cls();
		}
	}

	*/
}

extern int buyGoods() {

}