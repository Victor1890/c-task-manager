#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "task.h"

typedef struct {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    bool completed;
} Task;

Task* tasks = NULL;
int task_count = 0;
int task_capacity = 0;
int next_id = 1;

void initialize_task_list(int capacity) {

    if(!capacity) {
        printf("Error: Initial capacity must be greater then zero. \n");
        exit(EXIT_FAILURE);
    }

    task_capacity = capacity;

    tasks = (Task*)malloc(sizeof(Task) * task_capacity);
    if(tasks == NULL) {
        printf("Error: failed to allocate memory, it's really bad!");
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
            printf("Error: failed to reallicate memory! \n");
            exit(EXIT_FAILURE);
        }

        tasks = temp;
        printf("Info: resized task list to %d capacity \n", task_capacity);
    }
}

void add_new_task(const char* desc) {

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

void view_list_task() {
    if(task_count == 0) {
        printf("The task list is empty \n");
        return;
    }

    printf("\n--- Current Task Items (%d items) ---\n", task_count);

    for(int i = 0; i < task_count; i++) {

        Task task = tasks[i];

        printf(
            "ID: %-4d | Status: %-8s | Description: %s",
            task.id,
            task.completed ? "COMPLETE" : "PENDING",
            task.description
        );
    }

    printf("---------------------------------------------\n");
}

void complete_task(int task_id) {

    for(int i = 0; i < task_count; i++) {

        if(tasks[i].id == task_id) {

            if(tasks[i].completed) {
                printf("Info: Task ID %d is already completed.\n", task_id);
            } else {
                tasks[i].completed = true;
                printf("Success: Task ID %d marked as completed. \n", task_id);
            }

            return;

        }
    }

    printf("Error: Todo with ID %d not found. \n", task_id);

}