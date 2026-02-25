#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCRIPTION_LENGTH 256
#define INITIAL_CAPACITY 2

typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    bool completed;
} Task;

Task* tasks = NULL;
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

void ensure_capacity() {
    if(task_count >= task_capacity) {
        task_capacity *= 2;
        Task *temp = (Task*)realloc(tasks, sizeof(Task) * task_capacity);
        if(temp == NULL) {
            printf("Error: failed to reallocate memory!\n");
            exit(EXIT_FAILURE);
        }

        tasks = temp;
        printf("Info: resized task list to %d capacity \n", task_capacity);
    }
}

void add_task(const char* desc) {
    if(strlen(desc) == 0) {
        printf("Error: description cannot be empty \n");
        return;
    }

    ensure_capacity();

    tasks[task_count].id = next_id++;
    strcpy(tasks[task_count].description, desc);
    tasks[task_count].completed = false;

    task_count++;

    printf(
        "Success: Task added: ID %d - \"%s\"\n",
        tasks[task_count - 1].id,
        tasks[task_count - 1].description
    );
}

void view_task() {
    if(task_count == 0) {
        printf("The task list is empty \n");
        return;
    }

    printf("\n--- Current Task Items (%d items) ---\n", task_count);

    for(int i = 0; i < task_count; i++) {
        printf(
            "ID: %-4d | Status: %-8s | Description: %s\n",
            tasks[i].id,
            tasks[i].completed ? "COMPLETE" : "PENDING",
            tasks[i].description
        );
    }

    printf("---------------------------------------------\n");
}

void complete_task(const int task_id) {
    for(int i = 0; i < task_count; i++) {
        if(tasks[i].id == task_id) {
            if(tasks[i].completed) {
                printf("Info: Task ID %d is already complete \n", task_id);
            } else {
                tasks[i].completed = true;
                printf("Success: Task ID %d marked as COMPLETE \n", task_id);
            }

            return;
        }
    }

    printf("Error: Todo with ID %d not found \n", task_id);
}

int main() {

    initialize_task_list();

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

            add_task(temp_desc);
            break;
        case 2:
            view_task();
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