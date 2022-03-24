#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//�ֱ����û�����Ʒ�������������
#define UserMaxSize 20
#define GoodsMaxSize 20
#define OrderMaxSize 30

//���嵱ǰ�û���������Ʒ��������������
int user_count;
int goods_count;
int order_count;

//��ɫ���룺
//0 = ��ɫ       8 = ��ɫ
//1 = ��ɫ       9 = ����ɫ
//2 = ��ɫ       A = ����ɫ
//3 = ǳ��ɫ     B = ��ǳ��ɫ
//4 = ��ɫ       C = ����ɫ
//5 = ��ɫ       D = ����ɫ
//6 = ��ɫ       E = ����ɫ
//7 = ��ɫ       F = ����ɫ
//ע������cmdָ��"help color"���ؽ��

static const char* banner = "\
\t__          ___           _          __  __            _        _\n\
\t\\ \\        / / |         | |        |  \\/  |          | |      | |\n\
\t \\ \\  /\\  / /| |__   __ _| | ___    | \\  / | __ _ _ __| | _____| |_\n\
\t  \\ \\/  \\/ / | '_ \\ / _` | |/ _ \\   | |\\/| |/ _` | '__| |/ / _ \\ __|\n\
\t   \\  /\\  /  | | | | (_| | |  __/   | |  | | (_| | |  |   <  __/ |_\n\
\t    \\/  \\/   |_| |_|\\__,_|_|\\___|   |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|\n\
";

static const char* menu[] = {
//0.welcome(top of every page)
"\
\n\t\t ��ӭʹ�� Whale Market \n\n", \

//1.choose
"\
��ѡ������룺", \
	
//2.home page
"\
+============+============+==============+========+\n\
| 1.�û���¼ | 2.�û�ע�� | 3.����Ա��¼ | 4.�˳� |\n\
+============+============+==============+========+\n", \

//3.admin menu
"\
+================+==========+=========+==========+========+\n\
| 1.manage goods | 2.orders | 3.users | 4.logout | 5.back |\n\
+================+==========+=========+==========+========+\n", \

//4.admin -> 1.manage goods
"\
+========+=========+===============+=============+========+\n\
| 1.name | 2.price | 3.description | 4.condition | 5.back |\n\
+========+=========+===============+=============+========+\n", \

//5.buyer menu
"\
+==============+========+========+========+========+========+\n\
| 1.(����)��Ʒ | 2.��� | 3.���� | 4.���� | 5.���� | 6.���� |\n\
+==============+========+========+========+========+========+\n", \

//6.seller menu
"\
+========+========+============+========+========+========+\n\
| 1.���� | 2.��Ʒ | 3.������Ʒ | 4.��� | 5.���� | 6.���� |\n\
+========+========+============+========+========+========+\n", \

//7.buyer -> 5.more
"\
+============+============+========+========+\n\
| 1.������Ϣ | 2.ע���˺� | 3.��ֵ | 4.���� |\n\
+============+============+========+========+\n", \

//8.buyer -> 5.more -> 1.information
"\
+============+============+========+========+\n\
| 1.�޸����� | 2.��ϵ��ʽ | 3.��ַ | 4.���� |\n\
+============+============+========+========+\n", \

//9.seller -> 2.goods; 3.manage goods
//or: buyer -> 1.goods
"\
+============+========+========+========+========+\n\
| 1.��Ʒ���� | 2.�۸� | 3.���� | 4.״̬ | 5.���� |\n\
+============+========+========+========+========+\n" };

struct users_info {
	int UID;
	//UID: User ID
	//value: 10000 + n (0 < n <= 9999 ��nΪ����)
	int bos; 
	//bos: buyer or seller
	//value: 0   or   1
	char password[20];
	char name[20];
	char tel[15];
	//tel: Telephone Number
	char address[50];
	float balance;
	//balance: ���
} user[UserMaxSize], test_user;

struct goods_info {
	int GID;
	//GID: Goods ID
	//value: 20000 + n (0 < n <= 9999 ��nΪ����)
	int condition;
	//condition: ��Ʒ״̬
	//value: 0:���� 1:������ 2:���¼�
	float price;
	char name[20];
	char des[60];
	//des: description
} goods[GoodsMaxSize], test_goods[];

struct orders_info {
	int OID;
	//OID: Order ID
	//value: 30000 + n (0 < n <= 9999 ��nΪ����)
	int bid;
	//bid: Buyer ID
	//value: 10000 + n (0 < n <= 9999 ��nΪ����)
	int sid;
	//sid: Seller ID
	//value: 10000 + n (0 < n <= 9999 ��nΪ����)
	int gid;
	//gid: Goods ID
	//value: 20000 + n (0 < n <= 9999 ��nΪ����)
	char gn[20];
	//gn: Goods Name
	int number;
	float price;
	//total price
	char address[50];
	char time[30];
} order[OrderMaxSize], test_order[];


//��������
//���������"basic.c"
//ͷ�ļ���д������ᵼ�´������������ߴ��� LNK2005�������Ѷ����Ρ�
void welcome();

void cls();

void cls_ad();

void shm(int i);

void loading();