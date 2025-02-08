#include "task_manager.h"

void display_menu() {
    printf("\nTask Manager Menu:\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Complete Task\n");
    printf("4. Delete Task\n");
    printf("5. Save Tasks\n");
    printf("6. Load Tasks\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void get_task_description(char *description) {
    printf("Enter task description: ");
    fgets(description, MAX_TASK_DESCRIPTION_LENGTH, stdin);
    description[strcspn(description, "\n")] = 0; // Remove trailing newline
}

int get_task_id() {
    int task_id;
    printf("Enter task ID: ");
    scanf("%d", &task_id);
    getchar(); // Clear the input buffer (important after scanf)
    return task_id;
}