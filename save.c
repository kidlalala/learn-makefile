#include "main.h"
//将学生信息写回文件
void save_s(STU *a)
{
		FILE *fp=fopen("student.txt","w");
		STU *b=a->next;
		while(b)
		{
				fprintf(fp,"%s %s %c %d %s\n",b->number,b->name,b->sex,b->grade,b->major);
				b=b->next;
		}
		fclose(fp);
}

//将设团信息写回文件
void save_o(ORG *a)
{
		FILE *fp=fopen("organization.txt","w");
		ORG *b=a->next;
		while(b)
		{
				fprintf(fp,"%s %s\n",b->name,b->time);
				b=b->next;
		}
		fclose(fp);
}

//将关系表写入文件
void save(STU *a,ORG *b,int index[][MAX_S])
{
		FILE *fp=fopen("relation.txt","w");
		for(int i=0;i<MAX_O;i++)
		{
				for(int j=0;j<MAX_S;j++)
						fprintf(fp,"%d ",index[i][j]);
				fprintf(fp,"\n");
		}
		fclose(fp);
		save_s(a);
		save_o(b);
}
