#ifndef RELATION_H
#define RELATION_H
#include "main.h"
extern void creat_rela(int index[][MAX_S]);
extern void show(ORG *a,STU *c,int index[][MAX_S]);
extern void search_by_post(STU *a,ORG *b,int index[][MAX_S]);
extern void join(STU *a,ORG *b,int inde[][MAX_S]);
extern void display(STU *a,ORG *b,int index[][MAX_S]);
extern STU * delete_s(STU *a,ORG *c,int index[][MAX_S]);
extern ORG * delete_o(ORG *a,STU *c,int index[][MAX_S]);

#endif
