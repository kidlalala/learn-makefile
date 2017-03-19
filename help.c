#include "main.h"
//判断字符串是否为空
int isempty(char a[])
{
          if(!strcmp(a,""))
                  return 1;
          else
                  return 0;
}
//判断是否重新输入
int yesorno()
{
          char buf[MAX];
          printf("输入y或yes表示确定，其他任意输入表示返回\n");
          scanf("%s",buf);
          int flag=0;
          if((!strcmp("yes",buf))||(!strcmp("YES",buf)))
                  flag=1;
          if(!strcmp("Y",buf)||(!strcmp("y",buf)))
                  flag=1;
          if(flag) return 1;
          else return 0;
}
