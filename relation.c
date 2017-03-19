#include "main.h"
#include "student.h"
#include "organization.h"
//创建关系表
void creat_rela(int index[][MAX_S])
{
		FILE *fp=fopen("relation.txt","r");
		for(int i=0;i<MAX_O;i++)
				for(int j=0;j<MAX_S;j++)
						fscanf(fp,"%d",&index[i][j]);
		fclose(fp);

}

//根据序号寻找学生
STU *search_by_order(STU *a,int order)
{
		STU *b=a->next;
		while(b)
		{
				if(b->order==order)
						return b;
				b=b->next;
		}
		return NULL;
}

//删除社团
ORG * delete_o(ORG *a,STU *c,int index[][MAX_S])
{
		int n;
		show_o(a);
		printf("请输入想要删除的社团编号\n");
		scanf("%d",&n);
		ORG *b=search_o(a,n);
		if(!b)
		{
				printf("未找到相关社团\n");
				return NULL;
		}
		ORG *d=search_o_pre(a,b);
		d->next=b->next;
		int t=getlength_s(c);
		for(int i=0;i<t;i++)
				index[n-1][i]=0;
		free(b);
		return a;
}

//删除学生
STU * delete_s(STU *a,ORG *c,int index[][MAX_S])
{
		char temp[MAX];
		show_s(a);
		printf("请输入想要删除的学生学号\n");
		scanf("%s",temp);
		STU *b=search_s(a,temp);
		if(!b)
		{
				printf("未找到相关用户!\n");
				return NULL;
		}
		STU *d=search_s_pre(a,b);
		d->next=b->next;
		int t=getlength_o(c);
		for(int i=0;i<t;i++)
				index[i][b->order-1]=0;
		free(b);
		return a;
}

//显示社团学生信息
void show(ORG *a,STU *c,int index[][MAX_S])
{
		int n;
		show_o(a);
		printf("请输入想查看的社团编号\n");
		scanf("%d",&n);
		ORG *b=search_o(a,n);
		if(!b)
		{
				printf("未找到相应社团!\n");
				return ;
		}
		int t=getlength_s(c);
		for(int i=0;i<t;i++)
		{
				if(index[n-1][i]==1)
				{
						STU *d=search_by_order(c,i+1);
						display_s(d);
						printf("职务:会员\n");
				}
				else if(index[n-1][i]==2)
				{
						STU *d=search_by_order(c,i+1);
						display_s(d);
						printf("职务:秘书\n");
				}
				else if(index[n-1][i]==3)
				{
						STU *d=search_by_order(c,i+1);
						display_s(d);
						printf("职务:会长\n");
				}
		}
		printf("是否修改学生职位信息?\n");
		if(!yesorno())
				return ;
		int flag=1;
		while(flag)
		{
				printf("请输入想修改的学生的学号\n");
				char temp[MAX];
				scanf("%s",temp);
				STU *m=search_s(c,temp);
				if(!m)
				{
						printf("未找到相应学生\n");
						return ;
				}
				printf("请输入修改后的职位(会员 秘书 会长)\n");
				printf("输入'无'表示将从社团中删除该学生\n");
				scanf("%s",temp);
				if(!strcmp(temp,"会员"))
						index[n-1][m->order-1]=1;
				else if(!strcmp(temp,"秘书"))
						index[n-1][m->order-1]=2;
				else if(!strcmp(temp,"会长"))
						index[n-1][m->order-1]=3;
				else if(!strcmp(temp,"无"))
						index[n-1][m->order-1]=0;
				printf("是否继续修改学生?\n");
				if(!yesorno()) flag=0;
		}
}

//通过职位在社团中查询学生信息
void search_by_post(STU *a,ORG *b,int index[][MAX_S])
{
		int n,p=0;
		char temp[MAX];
		show_o(b);
		printf("请输入想查看的社团编号\n");
		scanf("%d",&n);
		ORG *c=search_o(b,n);
		if(!c)
		{
				printf("未找到相关社团\n");
				return ;
		}
		printf("请输入想查找的职位信息\n");
		scanf("%s",temp);
		if(!strcmp(temp,"会员"))
				p=1;
		else if(!strcmp(temp,"秘书"))
				p=2;
		else if(!strcmp(temp,"会长"))
				p=3;
		else 
		{
				printf("输入职位有误!\n");
				return ;
		}
		int t=getlength_s(a);
		for(int i=0;i<t;i++)
				if(index[n-1][i]==p)
				{
						STU *d=search_by_order(a,i+1);
						display_s(d);
				}
}

//学生加入社团
void join(STU *a,ORG *b,int index[][MAX_S])
{
		char temp[MAX];
		int n;
		show_s(a);
		printf("请输入想操作学生的学号\n");
		scanf("%s",temp);
		STU *c=search_s(a,temp);
		if(!c)
		{
				printf("未找到相应学生\n");
				return ;
		}
		show_o(b);
		while(1)
		{
				printf("请输入想加入的社团编号\n");
				scanf("%d",&n);
				ORG *d=search_o(b,n);
				if(!d)
				{
						printf("未找到相应社团\n");
						return ;
				}
				printf("请输入学生职位(会员 秘书 会长)\n");
				scanf("%s",temp);
				if(!strcmp(temp,"会员"))
						index[n-1][c->order-1]=1;
				else if(!strcmp(temp,"秘书"))
						index[n-1][c->order-1]=2;
				else if(!strcmp(temp,"会长"))
						index[n-1][c->order-1]=3;
				else
				{
						printf("输入职务错误!\n");
						return ;
				}
				printf("是否继续加入社团\n");
				if(!yesorno())
						return ;
		}
}

//显示学生所加入的社团
void display(STU *a,ORG *b,int index[][MAX_S])
{
		char temp[MAX];
		show_s(a);
		printf("请输入想查看的学生学号\n");
		scanf("%s",temp);
		STU *c=search_s(a,temp);
		if(!c)
		{
				printf("未找到相应学生!\n");
				return ;
		}
		int t=getlength_o(b);
		for(int i=0;i<t;i++)
		{
				if(index[i][c->order-1]>0)
				{
						ORG *d=search_o(b,i+1);
						display_o(d);
				}
		}
		printf("\n是否退出社团?\n");
		if(!yesorno())
				return ;
		int flag=1;
		while(flag)
		{
				printf("请输入想退出的社团的编号\n");
				int n;
				scanf("%d",&n);
				ORG *m=search_o(b,n);
				if(!m)
				{
						printf("未找到相关社团\n");
						return ;
				}
				index[n-1][c->order-1]=0;
				printf("是否继续退出社团?\n");
				if(!yesorno()) flag=0;
		}
}
