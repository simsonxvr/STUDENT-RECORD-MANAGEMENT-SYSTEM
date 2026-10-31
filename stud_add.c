#include "header.h"
void stud_add(ST **ptr)
{
    ST *new = malloc(sizeof(ST));
    ST *last;
    int roll = 1;

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", new->name);

    printf("Enter Percentage: ");
    scanf("%f", &new->percentage);

    while (1)
    {
        int found = 0;

        for (last = *ptr; last != NULL; last = last->next)
        {
            if (last->roll == roll)
            {
                found = 1;
                break;
            }
        }

        if (!found)
            break;

        roll++;
    }

    new->roll = roll;
    new->next = NULL;

    if (*ptr == NULL)
        *ptr = new;
    else
    {
        last = *ptr;

        while (last->next != NULL)
            last = last->next;

        last->next = new;
    }

    printf("Student added successfully!\n");
    printf("Assigned Roll Number: %d\n", new->roll);
}
