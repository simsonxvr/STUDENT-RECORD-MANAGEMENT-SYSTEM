#include"header.h"
int main(void)
{
    ST *head = NULL;
    char ch, choice;

    stud_load(&head);

    while (1)
    {
        printf("\n**** STUDENT RECORD MENU ****\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n");

        printf("Enter Your Choice: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'A':
            case 'a':
                stud_add(&head);
                break;

            case 'D':
            case 'd':
                stud_del(&head);
                break;

            case 'S':
            case 's':
                stud_show(head);
                break;

            case 'M':
            case 'm':
                stud_mod(head);
                break;

            case 'V':
            case 'v':
                stud_save(head);
                break;

            case 'T':
            case 't':
                stud_sort(&head);
                break;

            case 'E':
            case 'e':
                printf("S/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &choice);

                if (choice == 'S' || choice == 's')
                    stud_save(head);
                else if (choice != 'E' && choice != 'e')
                {
                    printf("Invalid Choice!\n");
                    break;
                }

                while (head != NULL)
                {
                    ST *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
