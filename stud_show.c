#include "header.h"
void stud_show(ST *ptr)
{
    if (ptr == NULL)
    {
        printf("No records found\n");
        return;
    }

    printf("---------------------------------------------\n");
    printf("%-10s %-20s %-12s\n",
           "Roll No", "Name", "Percentage");
    printf("---------------------------------------------\n");

    while (ptr != NULL)
    {
        printf("%-10d %-20s %-12.2f\n",
               ptr->roll, ptr->name, ptr->percentage);

        ptr = ptr->next;
    }

    printf("---------------------------------------------\n");
}
