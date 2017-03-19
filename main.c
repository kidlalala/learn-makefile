#include "main.h"
#include "student.h"
#include "organization.h"
#include "relation.h"
#include "save.h"
void menu()
{
		printf("欢迎使用学生社团管理系统\n");
		printf("1.显示学生信息\n");
		printf("2.添加学生\n");
		printf("3.删除学生\n");
		printf("4.修改学生\n");
		printf("5.显示社团信息\n");
		printf("6.添加社团\n");
		printf("7.删除社团\n");
		printf("8.修改社团\n");
		printf("9.学生加入社团\n");
		printf("10.查看学生所加入的社团\n");
		printf("11.查看社团中的学生信息\n");
		printf("12.查看社团中相关职位的学生\n");
		printf("13.保存\n");
		printf("14.退出系统\n");
}
int main(int argc,char **args)
{
		STU *s=creat_s();
		ORG *o=creat_o();
		int index[MAX_O][MAX_S];
		creat_rela(index);
		while(1)
		{
				menu();
				int choose;
				printf("请选择想执行的选项\n");
				scanf("%d",&choose);
				switch(choose)
				{
						case 1:show_s(s);break;
						case 2:add_s(s);break;
						case 3:delete_s(s,o,index);break;
						case 4:change_s(s);break;
						case 5:show_o(o);break;
						case 6:add_o(o);break;
						case 7:delete_o(o,s,index);break;
						case 8:change_o(o);break;
						case 9:join(s,o,index);break;
						case 10:display(s,o,index);break;
						case 11:show(o,s,index);break;
						case 12:search_by_post(s,o,index);break;
						case 13:save(s,o,index);break;
						case 14:return 0;
						default:printf("请选择正确选项\n");
				}
				printf("\n是否继续使用系统?\n");
				if(!yesorno())
						return 0;
				system("clear");
		}
		return 0;
}
