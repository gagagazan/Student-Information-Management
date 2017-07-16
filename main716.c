#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define N 1001
struct student
{
	char num[15];
	char name[10];
	char sex[5];
	char age[15];
}s[N],d[N],r[N],d1[N],r1[N],cc[N],reg[N],*p;

struct account  //帐号密码结构体
{
	char acc[15];
	char pass[256];
}Reg[N],stu_acc;

struct opinion
{
	char acc[15];
	char op[100];
}opn[N];

int Menu1()	//打印一层菜单
{
    char cScan;                //cScan用于记录键盘的输入
    system("cls");
    printf("\n\n");
    printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	//使用的制表符： ┏ ━ ┓ ┃ ┛ ┗
    printf("\t┃           欢迎使用学生信息管理系统V1.0           ┃\n");
    printf("\t┃                                                  ┃\n");
    printf("\t┃      请选择功能：                                ┃\n");
    printf("\t┃                                                  ┃\n");
	printf("\t┃      1、管理员入口                               ┃\n");
    printf("\t┃      2、学生入口                                 ┃\n");
    printf("\t┃      3、退出系统                                 ┃\n");
    printf("\t┃                                                  ┃\n");
    printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
    cScan=getch();
    return cScan-48;
}

int Menu2()	//打印菜单2
{
    char cScan,c;                //cScan用于记录键盘的输入
    int k=0,i;
    system("cls");
	FILE*fp;
    if((fp=fopen("stu_opinion.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&opn[k],sizeof(struct opinion),1,fp);
		k++;
	}
	k--;
	printf("*****************************************************************************");
    printf("\n                      *********** 意 见 栏 ***********          \n");
	for(i=0;i<k;i++)
	{
		printf("%s %s\n",opn[i].acc,opn[i].op);
	}
    printf("\n\n*****************************************************************************\n\n");
    fclose(fp);
    printf("\n");
    printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	//使用的制表符： ┏ ━ ┓ ┃ ┛ ┗
    printf("\t┃                                                  ┃\n");
    printf("\t┃      请选择功能：                                ┃\n");
    printf("\t┃                                                  ┃\n");
	printf("\t┃      1、增加学生信息                             ┃\n");
    printf("\t┃      2、删除学生信息                             ┃\n");
    printf("\t┃      3、查询学生信息                             ┃\n");
    printf("\t┃      4、更改学生信息                             ┃\n");
    printf("\t┃      5、显示所有学生信息                         ┃\n");
    printf("\t┃      6、信息公告                                 ┃\n");
	printf("\t┃      7、退出系统                                 ┃\n");
    printf("\t┃                                                  ┃\n");
    printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
    cScan=getch();
    return cScan-48;
}

int Menu3()	//打印菜单3
{
    char cScan;                //cScan用于记录键盘的输入
    system("cls");
    printf("\n\n");
    printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	//使用的制表符： ┏ ━ ┓ ┃ ┛ ┗
    printf("\t┃                                                  ┃\n");
    printf("\t┃      请选择功能：                                ┃\n");
    printf("\t┃                                                  ┃\n");
	printf("\t┃      1、登录（初始密码111111）                   ┃\n");
    printf("\t┃      2、学号注册                                 ┃\n");
	printf("\t┃      3、退出系统                                 ┃\n");
    printf("\t┃                                                  ┃\n");
    printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
    cScan=getch();
    return cScan-48;
}

int Menu4()	//打印菜单4
{

    char cScan;                //cScan用于记录键盘的输入
    system("cls");
    int  i=0,j;
	char op[N];
	FILE*fp;
    if((fp=fopen("stu_announcement.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&op[i],4,1,fp);
		i++;
	}
	printf("*****************************************************************************");
    printf("\n                     ************公 告 栏 ***********          \n");

	printf("%s",op);
    printf("\n\n*****************************************************************************\n\n");
    printf("\n");
    printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");	//使用的制表符： ┏ ━ ┓ ┃ ┛ ┗
    printf("\t┃                                                  ┃\n");
    printf("\t┃      请选择功能：                                ┃\n");
    printf("\t┃                                                  ┃\n");
	printf("\t┃      1、查询个人信息                             ┃\n");
    printf("\t┃      2、修改个人信息                             ┃\n");
    printf("\t┃      3、修改登录密码                             ┃\n");
    printf("\t┃      4、意见投诉                                 ┃\n");
	printf("\t┃      5、退出系统                                 ┃\n");
    printf("\t┃                                                  ┃\n");
    printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
    cScan=getch();
    return cScan-48;
}

void IN(char*p,int type)//输入字符查错函数,调用方法类似scanf函数。参数说明：*p变量地址，如&d[i].num;type判断类型，对应本程序有1.num,2.name,3.sex,4.age,5.opinion五种
{
	int flag=1,i;
	char J[999];
gotoloop:while(flag)//flag=1表示有错
	{
        scanf("%s",&J);
 		if(type==1)
		{
			if(strlen(J)>=15)
			{
				printf("学号过长！请正确输入：\n");
				continue;
			}
			else
			{
				for(i=0;i<strlen(J);i++)
				{
					if((J[i]>='0')&&(J[i]<='9'));
					else
					{
						printf("学号不为纯数字！请正确输入：\n");
						goto gotoloop;
					}
				}
			}
			flag=0;
		}else if(type==2)
		{
			if(strlen(J)>=10)
			{
				printf("姓名过长！请正确输入：\n");
				continue;
			}
            flag=0;
		}else if(type==3)
		{
			if(((strcmp(J,"男"))==0)||((strcmp(J,"女"))==0))
			{
				flag=0;
			}
			else
			{
				printf("性别输入错误！请正确输入：\n");
			}
		}else if(type==4)
		{
			if(strlen(J)!=10)
			{
				printf("出生日期长度错误！请正确输入：\n");
				continue;
			}
			if((J[4]!='-')||(J[7]!='-'))
			{
				printf("出生日期格式错误！请正确输入：\n");
				continue;
			}
			for(i=0;i<10;i++)
			{
				if((i==4)||(i==7))
					continue;
				else
				{
					if((J[i]>='0')&&(J[i]<='9'));
					else
					{
						printf("出生日期输入错误！请正确输入：\n");
						goto gotoloop;
					}
				}
			}
			if((J[0]!='1')&&(J[0]!='2'))
			{
				printf("出生日期区间错误！请正确输入：\n");
				continue;
			}
			if((J[0]=='1')&&J[1]!='9')
			{
				printf("出生日期区间错误！请正确输入：\n");
				continue;
			}
			if((J[0]=='2')&&J[1]!='0')
			{
				printf("出生日期区间错误！请正确输入：\n");
				continue;
			}
			if((J[5]!='1')&&(J[5]!='0'))
			{
				printf("出生日期输入错误！请正确输入：\n");
				continue;
			}
			if((J[5]=='1')&&((J[6]!='0')&&(J[6]!='1')&&(J[6]!='2')))
			{
				printf("出生日期区间错误！请正确输入：\n");
				continue;
			}
			if(J[8]>='4')
			{
				printf("出生日期区间错误！请正确输入：\n");
				continue;
			}
			if((J[8]=='3')&&(J[9]>='2'))
			{
				printf("出生日期区间错误！请正确输入：\n");
				continue;
			}
			flag=0;
		}else if(type=5)
		{
			if(strlen(J)>=100)
			{
                printf("意见过长，请输入100字以内的意见：\n");
                continue;
			}
			flag=0;
		}
	}
    if(flag==0)
	{
		switch(type)
		{
			case 1:memcpy(p,J,15);break;
			case 2:memcpy(p,J,10);break;
			case 3:memcpy(p,J,5);break;
			case 4:memcpy(p,J,15);break;
			case 5:memcpy(p,J,100);break;
		}
    }
}

void popo()	//冒泡排序
{
	int i,j,k=0;
	struct student temp;
	FILE*fp;
	if((fp=fopen("stu_information.txt","r+"))==NULL)
	{
		printf("cannot open the file.\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&r[k],sizeof(struct student),1,fp);
		k++;
	}
	k--;
    for(i=0;i<k-1;i++)
        for(j=0;j<k-i-1;j++)
		{
            if(strcmp(r[j].num,r[j+1].num)>0)
			{
				memcpy(&temp,&r[j],sizeof(struct student));
				memcpy(&r[j],&r[j+1],sizeof(struct student));
				memcpy(&r[j+1],&temp,sizeof(struct student));
			}
		}
	rewind(fp);
	for(i=0;i<k;i++)
	{
        fwrite(&r[i],sizeof(struct student),1,fp);
	}
    fclose(fp);
}

int CK(struct student ck[N],char X[15],int Y)//学生学号查重
{
	int m,flag=0;

	for(m=0;m<Y;m++)
	{
		if(strcmp(ck[m].num,X)==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}

void CK1(struct account ck1[N],char X1[15],int Y1,int Z[2])//学生登陆账号查重
{
	int m1,flag1=0;
	for(m1=0;m1<Y1;m1++)
	{
		if(strcmp(ck1[m1].acc,X1)==0)
		{
			flag1=1;
			Z[0]=flag1;
			Z[1]=m1;
			break;
		}
		else
		{
			Z[0]=0;
		}
	}
 }

void F_ADD()//添加学生信息
{
	int i,j,n,k=0,res=0;
	FILE*fp;
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("无法打开文件！\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&cc[k],sizeof(struct student),1,fp);
		k++;
	}
	fseek(fp,0,SEEK_END);
	printf("输入要添加学生信息的人数: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++,p++)
	{
		printf("输入第%d个学生的学号:\n",i+1);
		IN(s[i].num,1);
		for(j=0;j<k;j++)
		{
			res=CK(cc,s[i].num,k);
			if(res==1)
			{
				printf("学号重复，请重新输入!!!\n");
				IN(s[i].num,1);
				j=0;
			}
		}
		printf("输入第%d个学生的姓名:\n",i+1);
		IN(s[i].name,2);
		printf("输入第%d个学生的性别:\n",i+1);
		IN(s[i].sex,3);
		printf("输入第%d个学生的出生日期(格式:2017-07-05):\n",i+1);
		IN(s[i].age,4);
		system("cls");
	}

	for(i=0;i<n;i++)
	{
		struct account Acc;
		FILE*fp1;
		if((fp1=fopen("stu_account.txt","a+"))==NULL)
		{
			printf("不能打开文件!!!\n");
			system("pause");
			exit(0);
		}
		memcpy(Acc.acc,s[i].num,15);
		strcpy(Acc.pass,"111111");
		fseek(fp1,0,SEEK_END);
		fwrite(&Acc,sizeof(struct account),1,fp1);
		fclose(fp1);
		fwrite(&s[i],sizeof(struct student),1,fp);
	}
	printf("学生信息录入完毕\n");
	fclose(fp);
	popo();
	system("pause");
}

void F_DEL()//删除学生信息
{
	int i=0,f,k=0,flag=0,j;
	char no[15];
	FILE*fp;
	if((fp=fopen("stu_information.txt","r+"))==NULL)
	{
		printf("无法打开文件！\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	printf("请输入要删除学生信息的学号：\n");
	IN(no,1);
	for(j=0;j<k;j++)
	{
		if(strcmp(d[j].num,no)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	printf("\n\n没有该学生的信息!!!\n");
	else
	{
		k--;
		f=k;
		fclose(fp);
		if(remove("stu_information.txt")!=0)
		{
			printf("删除文件操作失败!!!\n");
			system("pause");
			exit(0);
		}
		if((fp=fopen("stu_information.txt","a+"))==NULL)
		{
			printf("重建文件操作失败!!!\n");
			system("pause");
			exit(0);
		}
		rewind(fp);
		while((f>1)&&(i<k))
		{
			if((strcmp(d[i].num,no))!=0)
			{
				fwrite(&d[i],sizeof(struct student),1,fp);
				f--;
				i++;
			}
			else i++;
		}
		printf("\n删除学生信息成功!!!\n\n");
	}
	fclose(fp);
	system("pause");
}

void F_SEL()//查找学生信息
{
	int i,res=0,k=0;
	char no[15];
	FILE*fp;
	if((fp=fopen("stu_information.txt","r"))==NULL)
	{
		printf("无法打开文件！\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	printf("请输入要查找的学号:\n\n");
	IN(no,1);
	res=CK(d,no,k);
	if(res==0)
		printf("\n没有该学生的信息!!!\n\n");
	else
	{
		rewind(fp);
		struct student st_student;
		while(!feof(fp))
		{
			fread(&st_student,sizeof(struct student),1,fp);
			if(strcmp(st_student.num,no)==0)
			{
				printf("\n为您找到的学生信息：\n");
				printf("\n%s %s %s %s\n\n",st_student.num,st_student.name,st_student.sex,st_student.age);
				break;
			}
		}
	}
	fclose(fp);
	system("pause");
}

void F_SHO()//显示所有学生信息
{
	int i,k=0;
	FILE*fp;
	if((fp=fopen("stu_information.txt","r"))==NULL)
	{
		printf("无法打开文件！\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	k--;
	printf("\n所有学生的信息：\n");
	for(i=0;i<k;i++)
	{
		printf("%s %s %s %s\n",d[i].num,d[i].name,d[i].sex,d[i].age);
	}
	fclose(fp);
	system("pause");
}

void F_RES()//修改学生信息
{
	int i=0,k=0,j,res=0,RES=0;
	char no[15];
	struct student restd;
	FILE*fp;
	if((fp=fopen("stu_information.txt","r+"))==NULL)
	{
		printf("无法打开文件！\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	k--;
	printf("请输入要更改信息的学生的学号：\n");
	IN(no,1);
	RES=CK(d,no,k);
	if(RES==0)
	{
		printf("\n没有该学生的信息!!!\n\n");
	}
	else
	{
		printf("输入修改后的学号:\n");
		IN(restd.num,1);
		for(j=0;j<k;j++)
		{
			res=CK(d,restd.num,k);
			if(res==1)
			{
				printf("学号重复，请重新输入!!!\n");
				IN(restd.num,1);
				j=0;
			}
		}
		printf("输入修改后的姓名:\n");
		IN(restd.name,2);
		printf("输入修改后的性别:\n");
		IN(restd.sex,3);
		printf("输入修改后的出生日期(格式:2017-07-05):\n");
		IN(restd.age,4);
		system("cls");
		rewind(fp);
		while(i<k)
		{
			if((strcmp(d[i].num,no))!=0)
			{
				fwrite(&d[i],sizeof(struct student),1,fp);
				i++;
			}
			else
			{
				fwrite(&restd,sizeof(struct student),1,fp);
				i++;
			}
		}
		printf("更改学生信息成功!!!\n");
	}
	fclose(fp);
	popo();
	system("pause");
}

void F_REG()//学生注册
{
	int k=0,res=0;
	struct account Acc;
	FILE*fp;
	FILE*fp1;
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	if((fp1=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&reg[k],sizeof(struct student),1,fp);
		k++;
	}
	printf("请输入学号: \n");
	IN(reg[k].num,1);
	while(1)
	{
		res=CK(reg,reg[k].num,k);
		if(res==1)
		{
			printf("此学号已存在，请选择登录!:\n");
			system("pause");
			exit(0);
		}
		else
		break;
	}
	printf("请输入姓名: \n");
	IN(reg[k].name,2);
	printf("请输入性别: \n");
	IN(reg[k].sex,3);
	printf("请输入出生年月,格式（2017-07-05）；\n");
	IN(reg[k].age,4);
	printf("请输入注册密码: \n");
	scanf("%s",&Acc.pass);
	printf("注册成功!!!\n");
	strcpy(Acc.acc,reg[k].num);
	fseek(fp,0,SEEK_END);
	fseek(fp1,0,SEEK_END);
	fwrite(&reg[k],sizeof(struct student),1,fp);
	fwrite(&Acc,sizeof(struct account),1,fp1);
	fclose(fp);
	fclose(fp1);
	popo();
	system("pause");
}

int F_LOG()//学生登陆
{
	int i,k=0,f[2]={0,0},t=0,FLAG=0,ch,p=0;
	FILE*fp;
	if((fp=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&Reg[k],sizeof(struct account),1,fp);
		k++;
	}
	fclose(fp);
	printf("请输入登录帐号(学号): \n");
	IN(stu_acc.acc,1);
	while(1)
	{
		CK1(Reg,stu_acc.acc,k,f);
		t=f[1];
		if(f[0]==1)
		{
			printf("请输入密码: \n");
			while((ch=getch())!='\r')	//判断是否是回车
			{
				if(ch==8)	//实现backspace键的功能，其中backspace键的ascii码是8
				{
					if(p>0)	//最多只能删到没有字符
					{
					p--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
					}
				}
				if(!isdigit(ch)&&!isalpha(ch))	//判断是否是数字或字符
				continue;
				putchar('*');	//在屏幕上打印星号
				stu_acc.pass[p++]=ch;	//保存密码
			}
			stu_acc.pass[p]=0;	//结束字符串
			while(1)
			{
				if(strcmp(stu_acc.pass,Reg[t].pass)!=0)
				{
					printf("\n密码不正确,请重新输入: \n");
					p=0;
					while((ch=getch())!='\r')	//判断是否是回车
					{
						if(ch==8)	//实现backspace键的功能，其中backspace键的ascii码是8
						{
							if(p>0)	//最多只能删到没有字符
							{
							p--;
							putchar('\b');
							putchar(' ');
							putchar('\b');
							}
						}
						if(!isdigit(ch)&&!isalpha(ch))	//判断是否是数字或字符
						continue;
						putchar('*');	//在屏幕上打印星号
						stu_acc.pass[p++]=ch;	//保存密码
					}
					stu_acc.pass[p]=0;	//结束字符串
				}
				else
				{
					FLAG=1;
					break;
				}
			}
			break;
		}
		else
		{
			printf("没有该账号，请先注册!!!\n");
			system("pause");
			break;
		}
	}
	return FLAG;
}

void F_Sel()//学生端 信息查询
{
	int i,res=0,k=0;
	char no[15];
	FILE*fp;
	if((fp=fopen("stu_information.txt","r"))==NULL)
	{
		printf("无法打开文件！\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&r1[k],sizeof(struct student),1,fp);
		k++;
	}
    memcpy(no,stu_acc.acc,15);
	res=CK(r1,no,k);
	if(res==0)
		printf("\n没有该学生的信息!!!\n\n");
	else
	{
		rewind(fp);
		struct student st_student;
		while(!feof(fp))
		{
			fread(&st_student,sizeof(struct student),1,fp);
			if(strcmp(st_student.num,no)==0)
			{
				printf("\n您的信息：\n");
				printf("\n%s %s %s %s\n\n",st_student.num,st_student.name,st_student.sex,st_student.age);
				break;
			}
		}
	}
	fclose(fp);
	system("pause");
}

void F_Res()//学生端 信息修改
{
	int i,k=0;
	FILE*fp;
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d1[k],sizeof(struct student),1,fp);
		k++;
	}
	k--;
	for(i=0;i<k;i++)
	{
		if(strcmp(stu_acc.acc,d1[i].num)==0)
		{
			break;
		}
	}
	printf("请输入修改后的姓名: \n");
	IN(d1[i].name,2);
	printf("请输入修改后的性别: \n");
	IN(d1[i].sex,3);
	printf("请输入修改后的出生日期: \n");
	IN(d1[i].age,4);
	fclose(fp);
	if(remove("stu_information.txt")!=0)
	{
		printf("删除文件操作失败!!!\n");
		system("pause");
		exit(0);
	}
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("重建文件操作失败!!!\n");
		system("pause");
		exit(0);
	}
	for(i=0;i<k;i++)
	{
		fwrite(&d1[i],sizeof(struct student),1,fp);
	}
	fclose(fp);
	printf("信息修改成功!!!\n");
	system("pause");
 }

void F_Pre()//学生端 密码修改
{
	int i,k=0;
	struct account cod[N];
	FILE*fp;
	if((fp=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&cod[k],sizeof(struct account),1,fp);
		k++;
	}
	k--;
	fclose(fp);
	for(i=0;i<k;i++)
	{
		if(strcmp(cod[i].acc,stu_acc.acc)==0)
		break;
	}
	printf("请输入修改后的密码: \n");
	scanf("%s",&cod[i].pass);
	if(remove("stu_account.txt")!=0)
	{
		printf("删除文件操作失败!!!\n");
		system("pause");
		exit(0);
	}
	if((fp=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("重建文件操作失败!!!\n");
		system("pause");
		exit(0);
	}
	for(i=0;i<k;i++)
	{
		fwrite(&cod[i],sizeof(struct account),1,fp);
	}
	fclose(fp);
	printf("密码修改成功!\n");
	system("pause");
 }

void F_OPI()//学生端 意见投诉窗口
{
	int i;
	FILE*fp;
	if((fp=fopen("stu_opinion.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	printf("请您提出您的意见：\n");
	fseek(fp,0,SEEK_END);
	scanf("%s",&opn[0].op);
	strcpy(opn[0].acc,stu_acc.acc);
	fwrite(&opn[0],sizeof(struct opinion),1,fp);
    printf("意见或投诉已提交成功！！！\n");
	fclose(fp);
	system("pause");
}

void F_ANN()//管理员信息公告
{
	int  i;
	char op[N];
	FILE*fp;
	printf("请发布公告：\n");
	scanf("%s",op);
	if((remove("stu_announcement.txt"))!=0)
	{
		printf("不能删除文件!!!\n");
		system("pause");
		exit(0);
	}
	if((fp=fopen("stu_announcement.txt","a+"))==NULL)
	{
		printf("不能打开文件!!!\n");
		system("pause");
		exit(0);
	}
	rewind(fp);
	for(i=0;op[i]!='\0';i++)
	{
 	fwrite(&op[i],4,1,fp);
	}
    printf("信息公告发布成功！！！\n");
	fclose(fp);
	system("pause");
}

int main()	//主函数
{
	int cScan1,cScan2,cScan3,cScan4,ch,p=0,res=0;
	char passwd[256],pswd[256]={"123456"};
	while(1)
	{
		cScan1=Menu1();
		if(cScan1==1)
		{
			printf("\n\t请输入管理员密码:");
			while((ch=getch())!='\r')	//判断是否是回车
			{
				if(ch==8)	//实现backspace键的功能，其中backspace键的ascii码是8
				{
					if(p>0)	//最多只能删到没有字符
					{
					p--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
					}
				}
				if(!isdigit(ch)&&!isalpha(ch))	//判断是否是数字或字符
				continue;
				putchar('*');	//在屏幕上打印星号
				passwd[p++]=ch;	//保存密码
			}
			passwd[p]=0;	//结束字符串
			if((strcmp(passwd,"123456"))==0)//密码认证成功则进入二层菜单
			{
				while(1)
				{
					cScan2=Menu2();
					switch(cScan2)
					{
						case 1:F_ADD();break;
						case 2:F_DEL();break;
						case 3:F_SEL();break;
						case 4:F_RES();break;
						case 5:F_SHO();break;
						case 6:F_ANN();break;
						case 7:exit(0);
						default:printf("无此选项！请确认输入\n");
								system("pause");
					}
				}
			}
			else
			{
				printf("\n密码错误，请确认！");
				p=0;
				system("pause");
			}
        }
        else if(cScan1==2)
		{
			while(1)
			{
				cScan3=Menu3();
				if(cScan3==1)
				{
					res=F_LOG();
					if(res==1)
					{
						while(1)
						{
							cScan4=Menu4();
							switch(cScan4)
							{
								case 1:F_Sel();break;
								case 2:F_Res();break;
								case 3:F_Pre();break;
								case 4:F_OPI();break;
								case 5:exit(0);
								default:printf("无此选项！请确认输入\n");
										system("pause");
							}
						}
					}
				}else if(cScan3==2)
				{
					F_REG();
				}else if(cScan3==3)
				{
					exit(0);
				}
			}
		}else if(cScan1==3)
		{
			exit(0);
		}
		else
		{
			printf("无此选项！请确认输入\n");
			system("pause");
		}
		}
	return 0;
}
