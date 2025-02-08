#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASK_DESCRIPTION_LENGTH 256
#define MAX_TASKS 100

typedef struct {
    int id;
    char description[MAX_TASK_DESCRIPTION_LENGTH];
    int completed; // 1 for completed, 0 for not completed
} Task;

#endif