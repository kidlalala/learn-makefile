#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "student.h"
const int S = sizeof(STU);
//创建学生信息表
STU * creat_s()
{
         int i=1;
         FILE *fp;
         fp=fopen("student.txt","r");
         STU *head,*tail,*p;
         head=(STU *)malloc(S);
         strcpy(head->number,"");
         strcpy(head->name,"");
         strcpy(head->major,"");
         head->sex='N';
         head->grade=0;
         head->order=0;
         head->next=NULL;
         char number[MAX],name[MAX],major[MAX];
         int grade;
         char sex;
         while(fscanf(fp,"%s %s %c %d %s",number,name,&sex,&grade,major)!=EOF)
         {
                 p=(STU *)malloc(S);
                 strcpy(p->number,number);
                 strcpy(p->name,name);
                 strcpy(p->major,major);
                 p->grade=grade;
                 p->sex=sex;
                 p->order=i;
                 if(!(head->next))
                 {
                         head->next=p;
                         tail=p;
                 }
                 else
                 {
                         tail->next=p;
                         tail=p;
                 }
                 i++;
         }
         fclose(fp);
         return head;
}
//学生个人信息显示
void display_s(STU *a)
{
         printf("%s %s %c %d %s\n",a->number,a->name,a->sex,a->grade,a->major);
}
//整体学生信息表显示
void show_s(STU * a)
{
         STU *b=a->next;
         printf("学生信息为:\n学号 姓名 性别 年级 专业\n");
         while(b)
         {
                 display_s(b);
                 b=b->next;
         }
 }
//根据学号寻找对应学生
STU * search_s(STU * a,char temp[])
{
         STU *b=a->next;
         while(b)
         {
                 if(!strcmp(temp,b->number))
                         return b;
                 b=b->next;
         }
         return NULL;
} 
//根据当前学生指针寻找前驱指针
STU * search_s_pre(STU *a,STU *b)
{
         STU *c=a;
         while(c)
         {
                 if(c->next==b)
                         return c;
                 c=c->next;
         }
         return NULL;
}
//检验输入学号的合法性 空 不是数字 长度超过12位
int isnumber(char s[])
{ 
         if(strlen(s)>12)
                 return 0;
         if(isempty(s))
                 return 0;
         int flag=0;
         for(int i=0;i<strlen(s);i++)
         {
                 if(s[i]-'0'>9||s[i]-'0'<0)
                 {
                         flag=1;
                         break;
                 }
         }
         if(flag) return 0;
         else return 1;
} 
//学生数量统计
int getlength_s(STU *a)
{
         STU *b=a->next;
         int s=0;
         while(b)
         {
                 b=b->next;
                 s++;
         }
         return s;
}
//添加学生
STU * add_s(STU *a)
{
         STU *b=a->next,*c;
         while(b->next) b=b->next;
         c=(STU *)malloc(S);
         b->next=c;
         c->next=NULL;
         b=a;
         printf("请输入学生学号:\n");
         scanf("%s",c->number);
         while(!isnumber(c->number))
         {
                 printf("学号格式错误!是否重新输入?\n");
                 if(!yesorno())
                 {
                         free(c);
                         return NULL;
                 }
                 printf("请输入学生学号\n");
                 scanf("%s",c->number);
         }
         while(b!=c)
         {
                 if(!strcmp(b->number,c->number))
                 {
                         free(c);
                         printf("请勿添加重复的学生!\n");
                         return NULL;
                 }
                 b=b->next;
         }
         printf("请输入学生姓名\n");
         scanf("%s",c->name);
         while(isempty(c->name))
         {
                 printf("姓名不为空!是否重新输入?\n");
                 if(!yesorno())
                 {
                         free(c);
                         return NULL;
                 }
                 printf("请输入学生姓名\n");
                 scanf("%s",c->name);
         }
         printf("请输入学生性别(男性为M，女性为F)\n");
         scanf("%*c%c",&(c->sex));
         while(c->sex!='F'&&c->sex!='M')
         {
                 printf("性别格式错误,是否重新输入?\n");
                 if(!yesorno())
                 {
                         free(c);
                         return NULL;
                 }
                 printf("请输入学生性别\n");
                 scanf("%*c%c",&(c->sex));
         }
         printf("请输入学生年级(入学年份)\n");
         scanf("%d",&(c->grade));
		 printf("请输入学生年级(入学年份)\n");
		 scanf("%d",&(c->grade));
		 while(c->grade>2017||c->grade<0)
		 {
	 			printf("未输入正确学生年级(0~2017),是否重新输入?\n");
	 			if(!yesorno())
				{
						free(c);
						return NULL;
				}
				printf("请输入学生年级\n");
				scanf("%d",&(c->grade));
		 }
		 printf("请输入学生专业\n");
		 scanf("%s",c->major);
		 while(isempty(c->major))
		 {
			 	printf("专业不为空!是否重新输入?\n");
			 	if(!yesorno())
			 	{
						free(c);
						return NULL;
			 	}
			 	printf("请输入学生专业\n");
			 	scanf("%s",c->major);
		 }
		 int t=getlength_s(a);
		 c->order=t;
		 return a;
}

//修改学生信息
void change_s(STU * a)
{
		system("clear");
		show_s(a);
		char temp[MAX];
		printf("请选择想修改学生的学号:\n");
		scanf("%s",temp);
		STU *b=search_s(a,temp);
		if(!b)
		{
				printf("查找不到此人！\n");
				return ; 
		}
		system("clear");
		display_s(b);
		int choose,n;
		char t;
		while(1)
		{
				printf("请输入想修改的数据序号\n");
				printf("1.学号 2.姓名 3.性别 4.年级 5.专业\n");
				scanf("%d",&choose);
				switch(choose)
				{
						case 1: printf("请输入修改后的学号\n");
							    scanf("%s",temp);
							    strcpy(b->number,"");
								if(isnumber(temp)&&(!search_s(a,temp))) 
							   			strcpy(b->number,temp);
							    else
								{
										printf("输入学号有误或重复\n");
										return ;
								}
								break;
			    case 2: printf("请输入修改后的姓名\n");
								scanf("%s",temp);
								if(!isempty(temp))
										strcpy(b->name,temp);
								else
								{
									    printf("姓名不为空\n");
						 				return ;
						    	}
								break;
					    case 3: printf("请输入修改后的性别\n");
							 	scanf("%*c%c",&t);
								if(t=='F'||t=='M')
										b->sex=t;
							else
								{
										printf("输入性别有误\n");
										return ;
								}
								break;
					    case 4: printf("请输入修改后的年级\n");
							 	scanf("%d",&n);
								if(n>0&&n<2017)
										b->grade=n;
								else
								{
										printf("输入年份有误\n");
										return ;
								}
								break;
						case 5: printf("请输入修改后的专业\n");
								scanf("%s",temp);
								if(!isempty(temp))
										strcpy(b->major,temp);
								else
								{
						     			printf("专业不为空\n");
										return ;
								}
								break;
						default:printf("请输入正确的操作项\n");
					}
					printf("是否继续修改?\n");
					if(!yesorno())
							return ;
					system("clear");
		}
}

