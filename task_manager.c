#include "task.h"

Task tasks[MAX_TASKS];
int num_tasks = 0;
int next_task_id = 1; // Start task IDs from 1

// Function to add a task
void add_task(const char *description) {
    if (num_tasks < MAX_TASKS) {
        tasks[num_tasks].id = next_task_id++;
        strncpy(tasks[num_tasks].description, description, MAX_TASK_DESCRIPTION_LENGTH - 1);
        tasks[num_tasks].completed = 0;
        num_tasks++;
        printf("Task added successfully.\n");
    } else {
        printf("Maximum number of tasks reached.\n");
    }
}

// Function to list all tasks
void list_tasks() {
    if (num_tasks == 0) {
        printf("No tasks found.\n");
        return;
    }

    printf("\nTasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s [%s]\n", tasks[i].id, tasks[i].description, tasks[i].completed ? "Completed" : "Pending");
    }
    printf("\n");
}

// Function to mark a task as complete
void complete_task(int task_id) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            tasks[i].completed = 1;
            printf("Task marked as complete.\n");
            return;
        }
    }
    printf("Task with ID %d not found.\n", task_id);
}

// Function to delete a task
void delete_task(int task_id) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            num_tasks--;
            printf("Task deleted.\n");
            return;
        }
    }
    printf("Task with ID %d not found.\n", task_id);
}

// Function to save tasks to a file
void save_tasks(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for saving");
        return;
    }
    for (int i = 0; i < num_tasks; i++) {
        fprintf(file, "%d,%s,%d\n", tasks[i].id, tasks[i].description, tasks[i].completed);
    }
    fclose(file);
}

// Function to load tasks from a file
void load_tasks(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return; // Just return if the file doesn't exist yet.
    }

    char buffer[MAX_TASK_DESCRIPTION_LENGTH + 20]; // Increased buffer size
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int id, completed;
        char description[MAX_TASK_DESCRIPTION_LENGTH];
        if (sscanf(buffer, "%d,%[^,],%d", &id, description, &completed) == 3) {
            tasks[num_tasks].id = id;
            strncpy(tasks[num_tasks].description, description, MAX_TASK_DESCRIPTION_LENGTH - 1);
            tasks[num_tasks].completed = completed;
            num_tasks++;
            if (id >= next_task_id) next_task_id = id + 1; // Update next_task_id
        }
    }
    fclose(file);
}