#ifndef STUDENT_H
#define STUDENT_H
#include "main.h"
extern const int S;
extern STU * creat_s();
extern void display_s(STU *a);
extern void show_s(STU *a);
extern STU *search_s(STU *a,char temp[]);
extern STU *search_s_pre(STU *a,STU *b);
extern int getlength_s(STU *a);
extern STU * add_s(STU *a);
extern void change_s(STU *a); 

#endif
