#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCRIPTION_LENGTH 256
#define INITIAL_CAPACITY 10

typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    bool completed;
} Task;

Task** tasks = NULL;
int task_count = 0;
int capacity = 0;
int next_id = 1;

int main() {

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
        case 6:
            printf("Exiting application.");
            break;
        
        default:
            printf("Invalid choice");
            break;
        }

    } while(choice != 6);

    return 0;
}