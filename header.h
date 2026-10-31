#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
} ST;

void stud_add(ST **ptr);
void stud_del(ST **ptr);
void stud_show(ST *ptr);
void stud_mod(ST *ptr);
void stud_save(ST *ptr);
void stud_load(ST **ptr);
void stud_sort(ST **ptr);




