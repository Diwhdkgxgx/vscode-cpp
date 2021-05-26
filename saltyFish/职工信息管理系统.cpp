#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct teach
{
	int number;
	char name[10];
	char sex[4];
	char job[10];
	char edu[10];
	char birth[15];
	char phone[12];
	char address[15];
	float salary;
	struct teach *next;
} teach;
teach *head = NULL;
FILE *fp;
teach *number();
teach *name();
teach *edu();
void show(teach *pr);
void show_all();
void read_file();
void kill(teach *pr);
void save();
void menu();
void add();
void change(teach *pr);
void revise();
void search();
void dele();
void sort();
int test_number(int a);
int main()
{
	read_file();
	menu();
}
int test_number(int a)
{
	int t = 1, f = 0;
	teach *p;
	if (head == NULL)
	{
		return f;
	}
	else
	{
		p = head;
		while (p->number != a)
		{
			p = p->next;
			if (p == NULL)
				return f;
		}
		printf("职工已存在,请重新输入\n");
		return t;
	}
}

void save() //存档
{
	char filename[] = "employee.txt";
	fp = fopen(filename, "w");
	if (head == NULL)
	{
	}
	else
	{
		teach *p = head;
		while (p != NULL)
		{
			fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%d,%lf\n", p->name, p->sex, p->job, p->edu, p->birth, p->phone, p->address, p->number, p->salary);
			p = p->next;
		}
	}
	fclose(fp);
}
void read_file() //文件读取
{
	char filename[] = "employee.txt";
	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		fp = fopen(filename, "w");
		if (fp == NULL)
			printf("\n\t文件创建失败");
	}
	else
	{
		int k, l = 0, c = 0;
		while ((k = fgetc(fp)) != EOF)
		{
			if (k == '\n')
			{
				if (c != 1)
					l++;
			}
			c++;
		}

		int number;
		char name[10];
		char sex[4];
		char job[10];
		char edu[10];
		char birth[15];
		char phone[12];
		char address[15];
		float salary;
		teach *p = (teach *)malloc(sizeof(teach));
		rewind(fp);
		int i;
		for (i = 0; i < l; i++)
		{
			fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%f\n", name, sex, job, edu, birth, phone, address, &number, &salary);
			teach *pn = (teach *)malloc(sizeof(teach));
			pn->number = number;
			strcpy(pn->name, name);
			strcpy(pn->sex, sex);
			strcpy(pn->address, address);
			strcpy(pn->phone, phone);
			strcpy(pn->job, job);
			strcpy(pn->edu, edu);
			strcpy(pn->birth, birth);
			pn->salary = salary;
			pn->next = NULL;
			p->next = pn;
			p = pn;
			if (head == NULL)
			{
				head = p;
			}
		}
	}
	fclose(fp);
}

void menu()
{
	system("cls");
	char n;
	int x;
	printf("\t***************欢迎使用职工信息管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]职工信息添加-----------------------\n");
	printf("\t------------------[2]职工信息浏览-----------------------\n");
	printf("\t------------------[3]修改职工信息-----------------------\n");
	printf("\t------------------[4]按工资排序-----------------------\n");
	printf("\t------------------[5]职工信息查询-----------------------\n");
	printf("\t------------------[6]职工信息删除-----------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		switch (n)
		{
			x = 0;
		case '1':
			add();
			break;
		case '2':
			show_all();
			break;
		case '3':
			revise();
			break;
		case '4':
			sort();
			break;
		case '5':
			search();
			break;

		case '6':
			dele();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
void add() //添加职工信息
{
	system("cls");
	teach *pnew;
	pnew = (teach *)malloc(sizeof(teach));
	printf("\n");
	printf("请输入职工信息:");
	printf("\n");
	do
	{
		printf("请输入职工号:");
		scanf("%d", &pnew->number);
	} while (test_number(pnew->number));
	printf("请输入职工姓名:");
	scanf("%s", &pnew->name);
	getchar();
	printf("请输入职工性别:");
	scanf("%s", &pnew->sex);
	getchar();
	printf("请输入职工工作岗位:");
	scanf("%s", &pnew->job);
	getchar();
	printf("请输入职工学历:");
	scanf("%s", &pnew->edu);
	getchar();
	printf("请输入职工出生年月:");
	scanf("%s", &pnew->birth);
	getchar();
	printf("请输入职工家庭住址:");
	scanf("%s", &pnew->address);
	getchar();
	printf("请输入职工的电话号码:");
	scanf("%s", &pnew->phone);
	getchar();
	printf("请输入职工基本工资:");
	scanf("%f", &pnew->salary);

	printf("\n\t职工号:%d", pnew->number);
	printf("\n\t姓名:%s", pnew->name);
	printf("\n\t性别:%s", pnew->sex);
	printf("\n\t工作岗位:%s", pnew->job);
	printf("\n\t学历:%s", pnew->edu);
	printf("\n\t出生年月:%s", pnew->birth);
	printf("\n\t家庭住址:%s", pnew->address);
	printf("\n\t电话号码:%s", pnew->phone);
	printf("\n\t基本工资:%.5f", pnew->salary);
	printf("\n确认录入该职工的信息吗?  y/n");
	if (getch() == 'y')
	{
		if (head == NULL)
		{
			head = pnew;
			head->next = NULL;
			printf("录入成功!\n");
			save();
			printf("按任意键回到主菜单");
			getch();
			getchar();
			menu();
			return;
		}
		if (head->number > pnew->number)
		{
			teach *pr = head;
			head = pnew;
			head->next = pr;
		}
		else
		{
			teach *p;
			teach *bf;
			p = head;
			while (p->number < pnew->number)
			{
				bf = p;
				p = p->next;
				if (p == NULL)
				{
					bf->next = pnew;
					pnew->next = NULL;
					printf("录入成功!\n");
					save();
					printf("\n-------按任意键回到主菜单--------");
					getch();
					getchar();
					menu();
					return;
				}
			}
			pnew->next = p;
			bf->next = pnew;
		}
		printf("录入成功!\n");
		save();
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
	}
	else
	{
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return;
	}
}
void revise() //修改职工信息
{
	getchar();
	system("cls");
	int x;
	int n;
	printf("\t***************欢迎使用职工工资管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]根据职工号修改---------------------\n");
	printf("\t------------------[2]职工姓名修改-------------------\n");
	printf("\t------------------[3]回到主菜单-------------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		getchar();
		switch (n)
		{
			teach *find;
			x = 0;
		case '1':
			find = number();
			if (find != NULL)
				change(find);
			break;
		case '2':
			find = name();
			if (find != NULL)
				change(find);
			break;
		case '3':
			menu();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
teach *number() //职工号查询
{
	int a;
	printf("请输入职工号:\n");
	scanf("%d", &a);
	if (head == NULL)
	{
		printf("系统中没有该职工号的信息\n");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return NULL;
	}
	else
	{
		teach *p = head;
		while (a != p->number)
		{
			p = p->next;
			if (p == NULL)
			{
				printf("系统中没有该职工号的信息\n");
				printf("\n-------按任意键回到主菜单--------");
				getch();
				getchar();
				menu();
				return NULL;
			}
		}
		return p;
	}
}
teach *name() //职工姓名查询
{
	char id[10] = "\0";
	printf("请输入职工姓名:\n");
	gets(id);
	if (head == NULL)
	{
		printf("系统中没有找到此职工\n");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return NULL;
	}
	else
	{
		teach *p = head;
		while ((strcmp(id, p->name)) != 0)
		{
			p = p->next;
			if (p == NULL)
			{
				printf("系统中没有找到此职工\n");
				printf("\n-------按任意键回到主菜单--------");
				getch();
				getchar();
				menu();
				return NULL;
			}
		}
		return p;
	}
}
teach *edu() //职工学历查询
{
	char id[10] = "\0";
	printf("请输入职工学历:\n");
	gets(id);
	if (head == NULL)
	{
		printf("系统中没有找到此职工\n");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
		return NULL;
	}
	else
	{
		teach *p = head;
		while ((strcmp(id, p->edu)) != 0)
		{
			p = p->next;
			if (p == NULL)
			{
				printf("系统中没有找到此职工\n");
				printf("\n-------按任意键回到主菜单--------");
				getch();
				getchar();
				menu();
				return NULL;
			}
		}
		return p;
	}
}
void change(teach *pr)
{
	teach *p;
	printf("\n\t******以下是你要修改的职工信息******\n");

	printf("\n\t职工号:%d", pr->number);
	printf("\n\t姓名:%s", pr->name);
	printf("\n\t性别:%s", pr->sex);
	printf("\n\t工作岗位:%s", pr->job);
	printf("\n\t学历:%s", pr->edu);
	printf("\n\t出生年月:%s", pr->birth);
	printf("\n\t家庭住址:%s", pr->address);
	printf("\n\t电话号码:%s", pr->phone);
	printf("\n\t基本工资:%.5f", pr->salary);
	printf("\n\t\t是否修改？(y/n)");
	if (getch() == 'y')
	{
		printf("\n\t请重新输入以下信息:\n");
		printf("请输入职工姓名:");
		scanf("%s", &pr->name);
		getchar();
		printf("请输入职工性别:");
		scanf("%s", &pr->sex);
		getchar();
		printf("请输入职工工作岗位:");
		scanf("%s", &pr->job);
		getchar();
		printf("请输入职工学历:");
		scanf("%s", &pr->edu);
		getchar();
		printf("请输入职工出生年月:");
		scanf("%s", &pr->birth);
		getchar();
		printf("请输入职工家庭住址:");
		scanf("%s", &pr->address);
		getchar();
		printf("请输入职工的电话号码:");
		scanf("%s", &pr->phone);
		getchar();
		printf("请输入职工基本工资:");
		scanf("%f", &pr->salary);
		pr->number = pr->number;

		save();
		printf("--------修改成功!-------");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
	}
	else
	{
		printf("\n-------按任意键回到主菜单--------");
		getch();
		getchar();
		menu();
	}
}
void dele()
{
	getchar();
	system("cls");
	int x;
	char n;
	printf("\t***************欢迎使用职工管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]根据职工号删除---------------------\n");
	printf("\t------------------[2]根据职工姓名删除-------------------\n");
	printf("\t------------------[3]回到主菜单-------------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		getchar();
		switch (n)
		{
			teach *find;
			x = 0;
		case '1':
			find = number();
			if (find != NULL)
				kill(find);
			break;
		case '2':
			find = name();
			if (find != NULL)
				kill(find);
			break;
		case '3':
			menu();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
void kill(teach *pr)
{
	printf("\n\t******以下是你要删除的职工信息******\n");

	printf("\n\t职工号:%d", pr->number);
	printf("\n\t姓名:%s", pr->name);
	printf("\n\t性别:%s", pr->sex);
	printf("\n\t工作岗位:%s", pr->job);
	printf("\n\t学历:%s", pr->edu);
	printf("\n\t出生年月:%s", pr->birth);
	printf("\n\t家庭住址:%s", pr->address);
	printf("\n\t电话号码:%s", pr->phone);
	printf("\n\t基本工资:%.5f", pr->salary);
	printf("\n\t\t是否删除？(y/n)");
	if (getch() == 'y')
	{
		if (pr->number == head->number)
		{
			head = head->next;
			free(pr);
		}
		else if (pr->next == NULL)
		{
			teach *k;
			k = head;
			while (k->next != pr)
			{
				k = k->next;
			}
			k->next = NULL;
		}
		else
		{
			teach *d = head;
			while (d->next != pr)
			{
				d = d->next;
			}
			d->next = pr->next;
		}
		save();
		printf("\n---------删除成功!---------------");
		printf("\n-------按任意键回到主菜单--------");
		getch();
		menu();
		return;
	}
	else
	{
		printf("\n-------按任意键回到主菜单--------");
		getch();
		menu();
		return;
	}
}
void search()
{
	getchar();
	system("cls");
	int x;
	int n;
	printf("\t***************欢迎使用职工工资管理系统*****************\n\n");
	printf("\t-----------------------菜单列表-------------------------\n");
	printf("\t------------------[1]根据职工号查询---------------------\n");
	printf("\t------------------[2]根据职工姓名查询-------------------\n");
	printf("\t------------------[3]根据职工学历查询-------------------\n");
	printf("\t------------------[4]显示所有职工信息-------------------\n");
	printf("\t------------------[5]回到主菜单-------------------------\n");
	printf("\t------------------[0]退出程序---------------------------\n\n");
	printf("\t***********************welcome**************************\n");
	do
	{
		printf("请选择:");
		n = getchar();
		getchar();
		switch (n)
		{
			teach *find;
			x = 0;
		case '1':
			find = number();
			if (find != NULL)
				show(find);
			break;
		case '2':
			find = name();
			if (find != NULL)
				show(find);
			break;
		case '3':
			find = edu();
			if (find != NULL)
				show(find);
		case '4':
			show_all();
			break;
		case '5':
			menu();
			break;
		case '0':
			exit(0);
			break;
		default:
			printf("没有符合您选择的功能，请重新输入!");
			x = 1;
		}
	} while (x == 1);
}
void show(teach *pr)
{
	printf("\n\t******以下是你要查询的职工工资信息******\n");

	printf("\n\t职工号:%d", pr->number);
	printf("\n\t姓名:%s", pr->name);
	printf("\n\t性别:%s", pr->sex);
	printf("\n\t工作岗位:%s", pr->job);
	printf("\n\t学历:%s", pr->edu);
	printf("\n\t出生年月:%s", pr->birth);
	printf("\n\t家庭住址:%s", pr->address);
	printf("\n\t电话号码:%s", pr->phone);
	printf("\n\t基本工资:%.5f", pr->salary);
	printf("\n-------按任意键回到主菜单--------");
	getch();
	getchar();
	menu();
}
void show_all()
{
	teach *pnew;
	pnew = head;
	if (head == NULL)
	{
		printf("系统中没有录入职工的数据\n");
	}
	while (pnew != NULL)
	{
		printf("职工号\t姓名\t性别\t工作岗位\t学历\t 出生年月\t 家庭住址  \t 电话号\t  \t基本工资    \n");
		printf("%-04d\t%-6s\t%-2s\t%-6s\t\t%-6s\t %-10s\t %-8s\t %-10s\t%f\t\n", pnew->number, pnew->name,
			   pnew->sex, pnew->job, pnew->edu, pnew->birth, pnew->address, pnew->phone, pnew->salary);
		pnew = pnew->next;
	}
	printf("\n-------按任意键回到主菜单--------");
	getch();
	menu();
}
void sort()
{
	teach *p = head;
	teach *pr = head;
	int num = 1; // 总人数
	int i = 0, j = 0;
	if (head->next == NULL)
	{
		num = 0;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
			num++;
		}
	}

	char workman_name[100][10];
	double workman_money[100];

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < 10; j++)
		{
			workman_name[i][j] = pr->name[j];
		}

		workman_money[i] = pr->salary;
		pr = pr->next;
	}

	double temp_money = 0;
	char temp_name[10];

	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (workman_money[j] < workman_money[j + 1])
			{
				temp_money = workman_money[j];
				strcpy(temp_name, workman_name[j]);

				workman_money[j] = workman_money[j + 1];
				strcpy(workman_name[j], workman_name[j + 1]);

				workman_money[j + 1] = temp_money;
				strcpy(workman_name[j + 1], temp_name);
			}
		}
	}

	printf("按工资排序如下：\n");

	for (i = 0; i < num; i++)
	{
		printf("%d. ", i + 1);
		printf("%5.f  ", workman_money[i]);
		printf("%s\n", workman_name[i]);
	}
	printf("\n-------按任意键回到主菜单--------");
	getch();
	getchar();
	menu();
}
