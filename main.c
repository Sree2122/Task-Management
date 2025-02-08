#include "task_manager.h"
#include "ui.h"

#define SAVE_FILENAME "tasks.txt" // Filename for saving/loading

int main() {
    load_tasks(SAVE_FILENAME); // Load tasks at start

    int choice;
    char description[MAX_TASK_DESCRIPTION_LENGTH];

    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Clear the input buffer

        switch (choice) {
            case 1:
                get_task_description(description);
                add_task(description);
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                complete_task(get_task_id());
                break;
            case 4:
                delete_task(get_task_id());
                break;
            case 5:
                save_tasks(SAVE_FILENAME);
                break;
            case 6:
                load_tasks(SAVE_FILENAME);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}