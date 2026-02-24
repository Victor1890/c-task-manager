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
int task_capacity = 0;
int next_id = 1;

void initialize_task_list() {
    task_capacity = INITIAL_CAPACITY;
    tasks = (Task*)malloc(sizeof(Task) * task_capacity);

    if(tasks == NULL) {
        printf("Error failed to allocate memory! bad!");
        exit(EXIT_FAILURE);
    }

    task_count = 0;
    next_id = 1;
}

void free_task_list() {
    if(tasks != NULL) {
        free(tasks);
        tasks = NULL;
    }

    task_count = 0;
}

int main() {

    initialize_task_list();

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

    free_task_list();

    return 0;
}