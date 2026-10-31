#include "header.h"
void stud_save(ST *ptr)
{
    FILE *fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        perror("student.dat");
        return;
    }

    while (ptr != NULL)
    {
        if (fwrite(ptr, sizeof(ST), 1, fp) != 1)
        {
            printf("Error saving records\n");
            fclose(fp);
            return;
        }

        ptr = ptr->next;
    }

    fclose(fp);
    printf("Records saved successfully\n");
}

void stud_load(ST **ptr)
{
    FILE *fp = fopen("student.dat", "rb");
    ST data, *new, *last = NULL;

    if (fp == NULL)
        return;

    while (fread(&data, sizeof(ST), 1, fp) == 1)
    {
        new = malloc(sizeof(ST));

        if (new == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        *new = data;
        new->next = NULL;

        if (*ptr == NULL)
            *ptr = new;
        else
            last->next = new;

        last = new;
    }

    fclose(fp);
}
