#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "organization.h"
const int O = sizeof(ORG);
//创建社团表
ORG * creat_o()
{
		FILE *fp;
		fp=fopen("organization.txt","r");
		ORG *head,*tail,*p;
		head=(ORG *)malloc(O);
		head->number=0;
		strcpy(head->name,"");
		strcpy(head->time,"");
		head->next=NULL;
		int i=1;
		char name[MAX],time[MAX];
		while(fscanf(fp,"%s %s",name,time)!=EOF)
		{
 				p=(ORG *)malloc(O);
				p->next=NULL;
				p->number=i;
				strcpy(p->name,name);
				strcpy(p->time,time);
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

//显示单个社团信息
void display_o(ORG * a)
{
		printf("%d %s %s\n",a->number,a->name,a->time);
}
//显示整个社团表信息
void show_o(ORG * a)
{
		ORG *b=a->next;
		printf("社团信息为:\n社团编号 社团名称 社团创建时间\n");
		while(b)
		{
				display_o(b);
				b=b->next;
		}
}

//查找社团
ORG * search_o(ORG * a,int t)
{
		ORG * b=a->next;
		while(b)
		{
				if(b->number==t)
						return b;
				b=b->next;
		}
		return NULL;
}
//通过已知社团指针，查找前驱指针
ORG * search_o_pre(ORG * a,ORG * b)
{
		ORG *c=a;
		while(c)
		{
				if(c->next==b)
						return c;
				c=c->next;
		}
		return NULL;
}

//统计社团数量
int getlength_o(ORG * a)
{
		ORG *b=a->next;
		int s=0;
		while(b)
		{
				b=b->next;
				s++;
		}
		return s;
}

//添加社团
ORG * add_o(ORG * a)
{
		ORG *b=a->next,*c;
		while(b->next)
				b=b->next;
		c=(ORG *)malloc(O);
		c->next=NULL;
		b->next=c;
		int t=getlength_o(a);
		c->number=t;
		printf("请输入社团名称\n");
		scanf("%s",c->name);
		while(isempty(c->name))
		{
				printf("名称不可为空!是否重新输入?\n");
				if(!yesorno())
				{
						free(c);
						return NULL;
				}
				printf("请输入社团名称\n");
				scanf("%s",c->name);
		}
		printf("请输入社团创建时间\n");
		int year,month,date,n;
		printf("请输入年份(2000~2017):\n");
		scanf("%d",&year);
		while(year<2000||year>2017)
		{
				printf("请重新输入正确的年份!\n");
				scanf("%d",&year);
		}
		printf("请输入月份(1~12):\n");
		scanf("%d",&month);
		while(month<1||month>12)
		{
				printf("请重新输入正确的月份!\n");
				scanf("%d",&month);
		}
		switch(month)
		{
				case 1:case 3:
				case 5:case 7:
				case 8:case 10:
				case 12:n=31;break;
				case 4:case 6:
				case 9:case 11:n=30;break;
				default:n=28;
		}
		if(((!year%100)||(year%100!=0&&year%4==0))&&n==28)
				n++;
		printf("请输入日期:\n");
		scanf("%d",&date);
		while(date<1||date>n)
		{
				printf("请重新输入正确的日期!\n");
				scanf("%d",&date);
		}
		char y[MAX]={0},m[MAX]={0},d[MAX]={0};
		sprintf(y,"%d",year);
		sprintf(m,"%d",month);
		sprintf(d,"%d",date);
		y[strlen(y)]='-';
		y[strlen(y)+1]='\0';
		strcat(y,m);
		y[strlen(y)]='-';
		y[strlen(y)+1]='\0';
		strcat(y,d);
		y[strlen(y)]='\0';
		strcpy(c->time,y);
		return a;
}

//修改社团信息
void change_o(ORG *a)
{
		system("clear");
		show_o(a);
		printf("请输入想要修改的社团编号\n");
		int t;
		scanf("%d",&t);
		ORG *b=search_o(a,t);
		if(!b)
		{
				printf("未找到相应社团\n");
				return ;
		}
		display_o(b);
		int choose;
		char temp[MAX];
		while(1)
		{
				printf("请输入想修改的数据项\n");
				printf("1.社团名称 2.社团创建时间\n");
				scanf("%d",&choose);
				switch(choose)
				{
						case 1: printf("请输入修改后的社团名称\n");
								scanf("%s",temp);
								if(!isempty(temp))
										strcpy(b->name,temp);
								else
								{
										printf("名称不为空\n");
										return ;
								}
							    break;
						case 2: printf("请输入修改后的创建时间\n");
								int year,month,date,n;
								printf("请输入年份(2000~2017):\n");
								scanf("%d",&year);
								while(year<2000||year>2017)
								{
										printf("请重新输入正确的年份!\n");
										scanf("%d",&year);
								}	
								printf("请输入月份(1~12):\n");
								scanf("%d",&month);
								while(month<0||month>12)
								{
										printf("请重新输入正确的月份!\n");
										scanf("%d",&month);
								}
								switch(month)
								{
										case 1:case 3:
										case 5:case 7:
										case 8:case 10:
										case 12:n=31;break;
										case 4:case 6:
										case 9:case 11:n=30;break;
										default:n=28;
								}
								if(((!year%100)||(year%100!=0&&year%4==0))&&n==28)
										n++;
								printf("请输入日期:\n");
								scanf("%d",&date);
								while(date<0||date>n)
								{
										printf("请重新输入正确的日期!\n");
										scanf("%d",&date);
								}
								char y[MAX]={0},m[MAX]={0},d[MAX]={0};
								sprintf(y,"%d",year);
								sprintf(m,"%d",month);
								sprintf(d,"%d",date);
								y[strlen(y)]='-';
								strcat(y,m);
								y[strlen(y)]='-';
								strcat(y,d);
								strcpy(b->time,y);
							    break;
						default:printf("请输入正确的操作项\n");
				}
				printf("是否继续修改?\n");
				if(!yesorno())
						return ;
		}
}

