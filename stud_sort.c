#include "header.h"
void stud_sort(ST **ptr)
{
    ST *i, *j;
    int roll;
    char ch;
    char name[50];
    float percentage;

    if (*ptr == NULL || (*ptr)->next == NULL)
    {
        printf("Not enough records to sort\n");
        return;
    }

    printf("N/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if (ch == 'N' || ch == 'n' ||
        ch == 'P' || ch == 'p')
    {
        for (i = *ptr; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                int swap = 0;

                if ((ch == 'N' || ch == 'n') &&
                    strcmp(i->name, j->name) > 0)
                    swap = 1;

                if ((ch == 'P' || ch == 'p') &&
                    i->percentage > j->percentage)
                    swap = 1;

                if (swap)
                {
                    roll = i->roll;
                    i->roll = j->roll;
                    j->roll = roll;

                    strcpy(name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, name);

                    percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = percentage;
                }
            }
        }

        printf("Records sorted successfully\n");
    }
    else
        printf("Invalid Choice\n");
}
