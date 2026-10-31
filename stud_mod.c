#include "header.h"
void stud_mod(ST *ptr)
{
    ST *last;
    char ch, field, name[50];
    float percentage;
    int roll, found = 0;

    printf("R/r : Search by Roll Number\n");
    printf("N/n : Search by Name\n");
    printf("P/p : Search by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if (ch == 'R' || ch == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
    }
    else if (ch == 'N' || ch == 'n')
    {
        printf("Enter Name: ");
        scanf(" %49[^\n]", name);

        for (last = ptr; last != NULL; last = last->next)
        {
            if (strcmp(last->name, name) == 0)
            {
                printf("%d %s %.2f\n", last->roll,
                       last->name, last->percentage);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Record not found\n");
            return;
        }

        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);
    }
    else if (ch == 'P' || ch == 'p')
    {
        printf("Enter Percentage: ");
        scanf("%f", &percentage);

        for (last = ptr; last != NULL; last = last->next)
        {
            if (last->percentage == percentage)
            {
                printf("%d %s %.2f\n", last->roll,
                       last->name, last->percentage);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Record not found\n");
            return;
        }

        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    found = 0;

    for (last = ptr; last != NULL; last = last->next)
    {
        if (last->roll == roll)
        {
            found = 1;
            break;
        }
    }

    if (last == NULL || !found)
    {
        printf("Record not found\n");
        return;
    }

    printf("N/n : Modify Name\n");
    printf("P/p : Modify Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &field);

    if (field == 'N' || field == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %49[^\n]", last->name);
    }
    else if (field == 'P' || field == 'p')
    {
        printf("Enter New Percentage: ");
        scanf("%f", &last->percentage);
    }
    else
    {
        printf("Invalid Choice\n");
        return;
    }

    printf("Record modified successfully\n");
}
