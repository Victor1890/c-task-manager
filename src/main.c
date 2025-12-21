#include <stdio.h>
#include "view.h"

int main(void)
{
    view_print_menu();

    int option;
    scanf("%d", &option);

    view_clean_screen();

    switch (option)
    {
        case 1:
            printf("Add new task selected.\n");
            break;
        
        case 2:
            printf("View all tasks selected.\n");
            break;

        case 3:
            printf("View pending tasks selected.\n");
            break;

        case 4:
            printf("View completed tasks selected.\n");
            break;
        
        case 5:
            printf("Mark task as completed selected.\n");
            break;

        case 6:
            printf("Edit task selected.\n");
            break;

        case 7:
            printf("Delete task selected.\n");
            break;
        
        case 8:
            printf("Save tasks selected.\n");
            break;

        case 0:
            printf("Exiting the program.\n");
            break;
        
        default:
            break;
    }

    return 0;
}