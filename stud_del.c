#include "header.h"
void stud_del(ST **ptr)
{
    ST *last, *prev;
    char ch, name[50];
    int roll, found = 0;

    if (*ptr == NULL)
    {
        printf("No records found\n");
        return;
    }

    printf("R/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if (ch == 'R' || ch == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
    }
    else if (ch == 'N' || ch == 'n')
    {
        printf("Enter Student Name: ");
        scanf(" %49[^\n]", name);

        printf("\nRoll No\tName\tPercentage\n");

        for (last = *ptr; last != NULL; last = last->next)
        {
            if (strcmp(last->name, name) == 0)
            {
                printf("%d\t%s\t%.2f\n",
                       last->roll, last->name,
                       last->percentage);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Record not found\n");
            return;
        }

        printf("Enter Roll Number to delete: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    last = *ptr;
    prev = NULL;

    while (last != NULL && last->roll != roll)
    {
        prev = last;
        last = last->next;
    }

    if (last == NULL)
    {
        printf("Roll Number not found\n");
        return;
    }

    if (prev == NULL)
        *ptr = last->next;
    else
        prev->next = last->next;

    free(last);
    printf("Student record deleted successfully!\n");
}
