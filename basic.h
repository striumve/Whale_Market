#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//分别定义用户、商品、订单最大数量
#define UserMaxSize 20
#define GoodsMaxSize 20
#define OrderMaxSize 30

//定义当前用户数量、商品数量、订单数量
int user_count;
int goods_count;
int order_count;

//颜色代码：
//0 = 黑色       8 = 灰色
//1 = 蓝色       9 = 淡蓝色
//2 = 绿色       A = 淡绿色
//3 = 浅绿色     B = 淡浅绿色
//4 = 红色       C = 淡红色
//5 = 紫色       D = 淡紫色
//6 = 黄色       E = 淡黄色
//7 = 白色       F = 亮白色
//注：来自cmd指令"help color"返回结果

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
\n\t\t 欢迎使用 Whale Market \n\n", \

//1.choose
"\
请选择操作码：", \
	
//2.home page
"\
+============+============+==============+========+\n\
| 1.用户登录 | 2.用户注册 | 3.管理员登录 | 4.退出 |\n\
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
| 1.(购买)商品 | 2.余额 | 3.搜索 | 4.订单 | 5.更多 | 6.返回 |\n\
+==============+========+========+========+========+========+\n", \

//6.seller menu
"\
+========+========+============+========+========+========+\n\
| 1.售卖 | 2.商品 | 3.管理商品 | 4.余额 | 5.订单 | 6.返回 |\n\
+========+========+============+========+========+========+\n", \

//7.buyer -> 5.more
"\
+============+============+========+========+\n\
| 1.个人信息 | 2.注销账号 | 3.充值 | 4.返回 |\n\
+============+============+========+========+\n", \

//8.buyer -> 5.more -> 1.information
"\
+============+============+========+========+\n\
| 1.修改密码 | 2.联系方式 | 3.地址 | 4.返回 |\n\
+============+============+========+========+\n", \

//9.seller -> 2.goods; 3.manage goods
//or: buyer -> 1.goods
"\
+============+========+========+========+========+\n\
| 1.商品名称 | 2.价格 | 3.描述 | 4.状态 | 5.返回 |\n\
+============+========+========+========+========+\n" };

struct users_info {
	int UID;
	//UID: User ID
	//value: 10000 + n (0 < n <= 9999 且n为整数)
	int bos; 
	//bos: buyer or seller
	//value: 0   or   1
	char password[20];
	char name[20];
	char tel[15];
	//tel: Telephone Number
	char address[50];
	float balance;
	//balance: 余额
} user[UserMaxSize], test_user;

struct goods_info {
	int GID;
	//GID: Goods ID
	//value: 20000 + n (0 < n <= 9999 且n为整数)
	int condition;
	//condition: 商品状态
	//value: 0:待售 1:已售罄 2:已下架
	float price;
	char name[20];
	char des[60];
	//des: description
} goods[GoodsMaxSize], test_goods[];

struct orders_info {
	int OID;
	//OID: Order ID
	//value: 30000 + n (0 < n <= 9999 且n为整数)
	int bid;
	//bid: Buyer ID
	//value: 10000 + n (0 < n <= 9999 且n为整数)
	int sid;
	//sid: Seller ID
	//value: 10000 + n (0 < n <= 9999 且n为整数)
	int gid;
	//gid: Goods ID
	//value: 20000 + n (0 < n <= 9999 且n为整数)
	char gn[20];
	//gn: Goods Name
	int number;
	float price;
	//total price
	char address[50];
	char time[30];
} order[OrderMaxSize], test_order[];


//函数声明
//函数体请见"basic.c"
//头文件中写函数体会导致错误：链接器工具错误 LNK2005：符号已定义多次。
void welcome();

void cls();

void cls_ad();

void shm(int i);

void loading();