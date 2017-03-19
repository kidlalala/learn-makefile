#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define MAX_S 30
#define MAX_O 20
typedef struct student{
         char number[MAX];
         char name[MAX];
         char sex;
         int grade;
         char major[MAX];
         struct student *next;
         int order;
}STU;
typedef struct organization{
		int number;
		char name[MAX];
		char time[MAX];
		struct organization *next;
}ORG;
extern int isempty(char a[]);
extern int yesorno();

#endif
