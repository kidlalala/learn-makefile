#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include "main.h"
extern const int O;
extern ORG * creat_o();
extern void display_o(ORG *a);
extern void show_o(ORG *a);
extern ORG * search_o(ORG *a,int t);
extern ORG * search_o_pre(ORG * a,ORG * b);
extern int getlength_o(ORG *a);
extern ORG * add_o(ORG *a);
extern void change_o(ORG *a); 

#endif
