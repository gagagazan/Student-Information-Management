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

struct account  //�ʺ�����ṹ��
{
	char acc[15];
	char pass[256];
}Reg[N],stu_acc;

struct opinion
{
	char acc[15];
	char op[100];
}opn[N];

int Menu1()	//��ӡһ��˵�
{
    char cScan;                //cScan���ڼ�¼���̵�����
    system("cls");
    printf("\n\n");
    printf("\t������������������������������������������������������\n");	//ʹ�õ��Ʊ���� �� �� �� �� �� ��
    printf("\t��           ��ӭʹ��ѧ����Ϣ����ϵͳV1.0           ��\n");
    printf("\t��                                                  ��\n");
    printf("\t��      ��ѡ���ܣ�                                ��\n");
    printf("\t��                                                  ��\n");
	printf("\t��      1������Ա���                               ��\n");
    printf("\t��      2��ѧ�����                                 ��\n");
    printf("\t��      3���˳�ϵͳ                                 ��\n");
    printf("\t��                                                  ��\n");
    printf("\t������������������������������������������������������\n\n");
    cScan=getch();
    return cScan-48;
}

int Menu2()	//��ӡ�˵�2
{
    char cScan,c;                //cScan���ڼ�¼���̵�����
    int k=0,i;
    system("cls");
	FILE*fp;
    if((fp=fopen("stu_opinion.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
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
    printf("\n                      *********** �� �� �� ***********          \n");
	for(i=0;i<k;i++)
	{
		printf("%s %s\n",opn[i].acc,opn[i].op);
	}
    printf("\n\n*****************************************************************************\n\n");
    fclose(fp);
    printf("\n");
    printf("\t������������������������������������������������������\n");	//ʹ�õ��Ʊ���� �� �� �� �� �� ��
    printf("\t��                                                  ��\n");
    printf("\t��      ��ѡ���ܣ�                                ��\n");
    printf("\t��                                                  ��\n");
	printf("\t��      1������ѧ����Ϣ                             ��\n");
    printf("\t��      2��ɾ��ѧ����Ϣ                             ��\n");
    printf("\t��      3����ѯѧ����Ϣ                             ��\n");
    printf("\t��      4������ѧ����Ϣ                             ��\n");
    printf("\t��      5����ʾ����ѧ����Ϣ                         ��\n");
    printf("\t��      6����Ϣ����                                 ��\n");
	printf("\t��      7���˳�ϵͳ                                 ��\n");
    printf("\t��                                                  ��\n");
    printf("\t������������������������������������������������������\n\n");
    cScan=getch();
    return cScan-48;
}

int Menu3()	//��ӡ�˵�3
{
    char cScan;                //cScan���ڼ�¼���̵�����
    system("cls");
    printf("\n\n");
    printf("\t������������������������������������������������������\n");	//ʹ�õ��Ʊ���� �� �� �� �� �� ��
    printf("\t��                                                  ��\n");
    printf("\t��      ��ѡ���ܣ�                                ��\n");
    printf("\t��                                                  ��\n");
	printf("\t��      1����¼����ʼ����111111��                   ��\n");
    printf("\t��      2��ѧ��ע��                                 ��\n");
	printf("\t��      3���˳�ϵͳ                                 ��\n");
    printf("\t��                                                  ��\n");
    printf("\t������������������������������������������������������\n\n");
    cScan=getch();
    return cScan-48;
}

int Menu4()	//��ӡ�˵�4
{

    char cScan;                //cScan���ڼ�¼���̵�����
    system("cls");
    int  i=0,j;
	char op[N];
	FILE*fp;
    if((fp=fopen("stu_announcement.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&op[i],4,1,fp);
		i++;
	}
	printf("*****************************************************************************");
    printf("\n                     ************�� �� �� ***********          \n");

	printf("%s",op);
    printf("\n\n*****************************************************************************\n\n");
    printf("\n");
    printf("\t������������������������������������������������������\n");	//ʹ�õ��Ʊ���� �� �� �� �� �� ��
    printf("\t��                                                  ��\n");
    printf("\t��      ��ѡ���ܣ�                                ��\n");
    printf("\t��                                                  ��\n");
	printf("\t��      1����ѯ������Ϣ                             ��\n");
    printf("\t��      2���޸ĸ�����Ϣ                             ��\n");
    printf("\t��      3���޸ĵ�¼����                             ��\n");
    printf("\t��      4�����Ͷ��                                 ��\n");
	printf("\t��      5���˳�ϵͳ                                 ��\n");
    printf("\t��                                                  ��\n");
    printf("\t������������������������������������������������������\n\n");
    cScan=getch();
    return cScan-48;
}

void IN(char*p,int type)//�����ַ������,���÷�������scanf����������˵����*p������ַ����&d[i].num;type�ж����ͣ���Ӧ��������1.num,2.name,3.sex,4.age,5.opinion����
{
	int flag=1,i;
	char J[999];
gotoloop:while(flag)//flag=1��ʾ�д�
	{
        scanf("%s",&J);
 		if(type==1)
		{
			if(strlen(J)>=15)
			{
				printf("ѧ�Ź���������ȷ���룺\n");
				continue;
			}
			else
			{
				for(i=0;i<strlen(J);i++)
				{
					if((J[i]>='0')&&(J[i]<='9'));
					else
					{
						printf("ѧ�Ų�Ϊ�����֣�����ȷ���룺\n");
						goto gotoloop;
					}
				}
			}
			flag=0;
		}else if(type==2)
		{
			if(strlen(J)>=10)
			{
				printf("��������������ȷ���룺\n");
				continue;
			}
            flag=0;
		}else if(type==3)
		{
			if(((strcmp(J,"��"))==0)||((strcmp(J,"Ů"))==0))
			{
				flag=0;
			}
			else
			{
				printf("�Ա������������ȷ���룺\n");
			}
		}else if(type==4)
		{
			if(strlen(J)!=10)
			{
				printf("�������ڳ��ȴ�������ȷ���룺\n");
				continue;
			}
			if((J[4]!='-')||(J[7]!='-'))
			{
				printf("�������ڸ�ʽ��������ȷ���룺\n");
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
						printf("�������������������ȷ���룺\n");
						goto gotoloop;
					}
				}
			}
			if((J[0]!='1')&&(J[0]!='2'))
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			if((J[0]=='1')&&J[1]!='9')
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			if((J[0]=='2')&&J[1]!='0')
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			if((J[5]!='1')&&(J[5]!='0'))
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			if((J[5]=='1')&&((J[6]!='0')&&(J[6]!='1')&&(J[6]!='2')))
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			if(J[8]>='4')
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			if((J[8]=='3')&&(J[9]>='2'))
			{
				printf("�������������������ȷ���룺\n");
				continue;
			}
			flag=0;
		}else if(type=5)
		{
			if(strlen(J)>=100)
			{
                printf("���������������100�����ڵ������\n");
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

void popo()	//ð������
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

int CK(struct student ck[N],char X[15],int Y)//ѧ��ѧ�Ų���
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

void CK1(struct account ck1[N],char X1[15],int Y1,int Z[2])//ѧ����½�˺Ų���
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

void F_ADD()//���ѧ����Ϣ
{
	int i,j,n,k=0,res=0;
	FILE*fp;
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("�޷����ļ���\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&cc[k],sizeof(struct student),1,fp);
		k++;
	}
	fseek(fp,0,SEEK_END);
	printf("����Ҫ���ѧ����Ϣ������: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++,p++)
	{
		printf("�����%d��ѧ����ѧ��:\n",i+1);
		IN(s[i].num,1);
		for(j=0;j<k;j++)
		{
			res=CK(cc,s[i].num,k);
			if(res==1)
			{
				printf("ѧ���ظ�������������!!!\n");
				IN(s[i].num,1);
				j=0;
			}
		}
		printf("�����%d��ѧ��������:\n",i+1);
		IN(s[i].name,2);
		printf("�����%d��ѧ�����Ա�:\n",i+1);
		IN(s[i].sex,3);
		printf("�����%d��ѧ���ĳ�������(��ʽ:2017-07-05):\n",i+1);
		IN(s[i].age,4);
		system("cls");
	}

	for(i=0;i<n;i++)
	{
		struct account Acc;
		FILE*fp1;
		if((fp1=fopen("stu_account.txt","a+"))==NULL)
		{
			printf("���ܴ��ļ�!!!\n");
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
	printf("ѧ����Ϣ¼�����\n");
	fclose(fp);
	popo();
	system("pause");
}

void F_DEL()//ɾ��ѧ����Ϣ
{
	int i=0,f,k=0,flag=0,j;
	char no[15];
	FILE*fp;
	if((fp=fopen("stu_information.txt","r+"))==NULL)
	{
		printf("�޷����ļ���\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	printf("������Ҫɾ��ѧ����Ϣ��ѧ�ţ�\n");
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
	printf("\n\nû�и�ѧ������Ϣ!!!\n");
	else
	{
		k--;
		f=k;
		fclose(fp);
		if(remove("stu_information.txt")!=0)
		{
			printf("ɾ���ļ�����ʧ��!!!\n");
			system("pause");
			exit(0);
		}
		if((fp=fopen("stu_information.txt","a+"))==NULL)
		{
			printf("�ؽ��ļ�����ʧ��!!!\n");
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
		printf("\nɾ��ѧ����Ϣ�ɹ�!!!\n\n");
	}
	fclose(fp);
	system("pause");
}

void F_SEL()//����ѧ����Ϣ
{
	int i,res=0,k=0;
	char no[15];
	FILE*fp;
	if((fp=fopen("stu_information.txt","r"))==NULL)
	{
		printf("�޷����ļ���\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	printf("������Ҫ���ҵ�ѧ��:\n\n");
	IN(no,1);
	res=CK(d,no,k);
	if(res==0)
		printf("\nû�и�ѧ������Ϣ!!!\n\n");
	else
	{
		rewind(fp);
		struct student st_student;
		while(!feof(fp))
		{
			fread(&st_student,sizeof(struct student),1,fp);
			if(strcmp(st_student.num,no)==0)
			{
				printf("\nΪ���ҵ���ѧ����Ϣ��\n");
				printf("\n%s %s %s %s\n\n",st_student.num,st_student.name,st_student.sex,st_student.age);
				break;
			}
		}
	}
	fclose(fp);
	system("pause");
}

void F_SHO()//��ʾ����ѧ����Ϣ
{
	int i,k=0;
	FILE*fp;
	if((fp=fopen("stu_information.txt","r"))==NULL)
	{
		printf("�޷����ļ���\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	k--;
	printf("\n����ѧ������Ϣ��\n");
	for(i=0;i<k;i++)
	{
		printf("%s %s %s %s\n",d[i].num,d[i].name,d[i].sex,d[i].age);
	}
	fclose(fp);
	system("pause");
}

void F_RES()//�޸�ѧ����Ϣ
{
	int i=0,k=0,j,res=0,RES=0;
	char no[15];
	struct student restd;
	FILE*fp;
	if((fp=fopen("stu_information.txt","r+"))==NULL)
	{
		printf("�޷����ļ���\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&d[k],sizeof(struct student),1,fp);
		k++;
	}
	k--;
	printf("������Ҫ������Ϣ��ѧ����ѧ�ţ�\n");
	IN(no,1);
	RES=CK(d,no,k);
	if(RES==0)
	{
		printf("\nû�и�ѧ������Ϣ!!!\n\n");
	}
	else
	{
		printf("�����޸ĺ��ѧ��:\n");
		IN(restd.num,1);
		for(j=0;j<k;j++)
		{
			res=CK(d,restd.num,k);
			if(res==1)
			{
				printf("ѧ���ظ�������������!!!\n");
				IN(restd.num,1);
				j=0;
			}
		}
		printf("�����޸ĺ������:\n");
		IN(restd.name,2);
		printf("�����޸ĺ���Ա�:\n");
		IN(restd.sex,3);
		printf("�����޸ĺ�ĳ�������(��ʽ:2017-07-05):\n");
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
		printf("����ѧ����Ϣ�ɹ�!!!\n");
	}
	fclose(fp);
	popo();
	system("pause");
}

void F_REG()//ѧ��ע��
{
	int k=0,res=0;
	struct account Acc;
	FILE*fp;
	FILE*fp1;
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
		system("pause");
		exit(0);
	}
	if((fp1=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&reg[k],sizeof(struct student),1,fp);
		k++;
	}
	printf("������ѧ��: \n");
	IN(reg[k].num,1);
	while(1)
	{
		res=CK(reg,reg[k].num,k);
		if(res==1)
		{
			printf("��ѧ���Ѵ��ڣ���ѡ���¼!:\n");
			system("pause");
			exit(0);
		}
		else
		break;
	}
	printf("����������: \n");
	IN(reg[k].name,2);
	printf("�������Ա�: \n");
	IN(reg[k].sex,3);
	printf("�������������,��ʽ��2017-07-05����\n");
	IN(reg[k].age,4);
	printf("������ע������: \n");
	scanf("%s",&Acc.pass);
	printf("ע��ɹ�!!!\n");
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

int F_LOG()//ѧ����½
{
	int i,k=0,f[2]={0,0},t=0,FLAG=0,ch,p=0;
	FILE*fp;
	if((fp=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&Reg[k],sizeof(struct account),1,fp);
		k++;
	}
	fclose(fp);
	printf("�������¼�ʺ�(ѧ��): \n");
	IN(stu_acc.acc,1);
	while(1)
	{
		CK1(Reg,stu_acc.acc,k,f);
		t=f[1];
		if(f[0]==1)
		{
			printf("����������: \n");
			while((ch=getch())!='\r')	//�ж��Ƿ��ǻس�
			{
				if(ch==8)	//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8
				{
					if(p>0)	//���ֻ��ɾ��û���ַ�
					{
					p--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
					}
				}
				if(!isdigit(ch)&&!isalpha(ch))	//�ж��Ƿ������ֻ��ַ�
				continue;
				putchar('*');	//����Ļ�ϴ�ӡ�Ǻ�
				stu_acc.pass[p++]=ch;	//��������
			}
			stu_acc.pass[p]=0;	//�����ַ���
			while(1)
			{
				if(strcmp(stu_acc.pass,Reg[t].pass)!=0)
				{
					printf("\n���벻��ȷ,����������: \n");
					p=0;
					while((ch=getch())!='\r')	//�ж��Ƿ��ǻس�
					{
						if(ch==8)	//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8
						{
							if(p>0)	//���ֻ��ɾ��û���ַ�
							{
							p--;
							putchar('\b');
							putchar(' ');
							putchar('\b');
							}
						}
						if(!isdigit(ch)&&!isalpha(ch))	//�ж��Ƿ������ֻ��ַ�
						continue;
						putchar('*');	//����Ļ�ϴ�ӡ�Ǻ�
						stu_acc.pass[p++]=ch;	//��������
					}
					stu_acc.pass[p]=0;	//�����ַ���
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
			printf("û�и��˺ţ�����ע��!!!\n");
			system("pause");
			break;
		}
	}
	return FLAG;
}

void F_Sel()//ѧ���� ��Ϣ��ѯ
{
	int i,res=0,k=0;
	char no[15];
	FILE*fp;
	if((fp=fopen("stu_information.txt","r"))==NULL)
	{
		printf("�޷����ļ���\n");
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
		printf("\nû�и�ѧ������Ϣ!!!\n\n");
	else
	{
		rewind(fp);
		struct student st_student;
		while(!feof(fp))
		{
			fread(&st_student,sizeof(struct student),1,fp);
			if(strcmp(st_student.num,no)==0)
			{
				printf("\n������Ϣ��\n");
				printf("\n%s %s %s %s\n\n",st_student.num,st_student.name,st_student.sex,st_student.age);
				break;
			}
		}
	}
	fclose(fp);
	system("pause");
}

void F_Res()//ѧ���� ��Ϣ�޸�
{
	int i,k=0;
	FILE*fp;
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
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
	printf("�������޸ĺ������: \n");
	IN(d1[i].name,2);
	printf("�������޸ĺ���Ա�: \n");
	IN(d1[i].sex,3);
	printf("�������޸ĺ�ĳ�������: \n");
	IN(d1[i].age,4);
	fclose(fp);
	if(remove("stu_information.txt")!=0)
	{
		printf("ɾ���ļ�����ʧ��!!!\n");
		system("pause");
		exit(0);
	}
	if((fp=fopen("stu_information.txt","a+"))==NULL)
	{
		printf("�ؽ��ļ�����ʧ��!!!\n");
		system("pause");
		exit(0);
	}
	for(i=0;i<k;i++)
	{
		fwrite(&d1[i],sizeof(struct student),1,fp);
	}
	fclose(fp);
	printf("��Ϣ�޸ĳɹ�!!!\n");
	system("pause");
 }

void F_Pre()//ѧ���� �����޸�
{
	int i,k=0;
	struct account cod[N];
	FILE*fp;
	if((fp=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
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
	printf("�������޸ĺ������: \n");
	scanf("%s",&cod[i].pass);
	if(remove("stu_account.txt")!=0)
	{
		printf("ɾ���ļ�����ʧ��!!!\n");
		system("pause");
		exit(0);
	}
	if((fp=fopen("stu_account.txt","a+"))==NULL)
	{
		printf("�ؽ��ļ�����ʧ��!!!\n");
		system("pause");
		exit(0);
	}
	for(i=0;i<k;i++)
	{
		fwrite(&cod[i],sizeof(struct account),1,fp);
	}
	fclose(fp);
	printf("�����޸ĳɹ�!\n");
	system("pause");
 }

void F_OPI()//ѧ���� ���Ͷ�ߴ���
{
	int i;
	FILE*fp;
	if((fp=fopen("stu_opinion.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
		system("pause");
		exit(0);
	}
	printf("����������������\n");
	fseek(fp,0,SEEK_END);
	scanf("%s",&opn[0].op);
	strcpy(opn[0].acc,stu_acc.acc);
	fwrite(&opn[0],sizeof(struct opinion),1,fp);
    printf("�����Ͷ�����ύ�ɹ�������\n");
	fclose(fp);
	system("pause");
}

void F_ANN()//����Ա��Ϣ����
{
	int  i;
	char op[N];
	FILE*fp;
	printf("�뷢�����棺\n");
	scanf("%s",op);
	if((remove("stu_announcement.txt"))!=0)
	{
		printf("����ɾ���ļ�!!!\n");
		system("pause");
		exit(0);
	}
	if((fp=fopen("stu_announcement.txt","a+"))==NULL)
	{
		printf("���ܴ��ļ�!!!\n");
		system("pause");
		exit(0);
	}
	rewind(fp);
	for(i=0;op[i]!='\0';i++)
	{
 	fwrite(&op[i],4,1,fp);
	}
    printf("��Ϣ���淢���ɹ�������\n");
	fclose(fp);
	system("pause");
}

int main()	//������
{
	int cScan1,cScan2,cScan3,cScan4,ch,p=0,res=0;
	char passwd[256],pswd[256]={"123456"};
	while(1)
	{
		cScan1=Menu1();
		if(cScan1==1)
		{
			printf("\n\t���������Ա����:");
			while((ch=getch())!='\r')	//�ж��Ƿ��ǻس�
			{
				if(ch==8)	//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8
				{
					if(p>0)	//���ֻ��ɾ��û���ַ�
					{
					p--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
					}
				}
				if(!isdigit(ch)&&!isalpha(ch))	//�ж��Ƿ������ֻ��ַ�
				continue;
				putchar('*');	//����Ļ�ϴ�ӡ�Ǻ�
				passwd[p++]=ch;	//��������
			}
			passwd[p]=0;	//�����ַ���
			if((strcmp(passwd,"123456"))==0)//������֤�ɹ���������˵�
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
						default:printf("�޴�ѡ���ȷ������\n");
								system("pause");
					}
				}
			}
			else
			{
				printf("\n���������ȷ�ϣ�");
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
								default:printf("�޴�ѡ���ȷ������\n");
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
			printf("�޴�ѡ���ȷ������\n");
			system("pause");
		}
		}
	return 0;
}
