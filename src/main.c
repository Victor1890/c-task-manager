#include <stdio.h>
#include <string.h>
#include "task.h"

#define INITIAL_CAPACITY 2

int main() {

    initialize_task_list((int)INITIAL_CAPACITY);

    save_task_storage("todo_task.txt");

    char temp_desc[MAX_DESCRIPTION_LENGTH];
    int temp_id;

    int choice;

    do {
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Save Task in Disk\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number. \n");
            while(getchar() != '\n'); 
            continue;
        }

        while(getchar() != '\n');

        switch (choice)
        {
        case 1:
            printf("Enter the new todo description: ");
            fgets(temp_desc, sizeof(temp_desc), stdin);
            temp_desc[strcspn(temp_desc, "\n")];

            add_new_task(temp_desc);
            break;
        case 2:
            view_list_task();
            break;
        case 3:
            printf("Enter the ID of task to mark as completed: ");
            if(scanf("%d", &temp_id) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');
            complete_task(temp_id);
            break;
        case 4:
            printf("Enter the ID of task to delete: ");
            if(scanf("%d", &temp_id) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');
            delete_task(temp_id);
            break;
        case 6:
            printf("Exiting application.");
            break;
        
        default:
            printf("Invalid choice");
            break;
        }

    } while(choice != 6);

    free_task_list();

    return 0;
}