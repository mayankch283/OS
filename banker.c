#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int resources[MAX_RESOURCES]; // Available resources
int max[MAX_PROCESSES][MAX_RESOURCES]; // Maximum needs of each process
int allocated[MAX_PROCESSES][MAX_RESOURCES]; // Resources allocated to each process
int need[MAX_PROCESSES][MAX_RESOURCES]; // Remaining needs of each process

int is_safe(int processes, int resources[]) {
    int work[MAX_RESOURCES]; // Available work vector
    int finish[MAX_PROCESSES]; // Process completion flag
    int work_copy[MAX_RESOURCES];

    // Initialize work with available resources
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = resources[i];
        work_copy[i] = resources[i];
    }

    // Initialize finish to false
    for (int i = 0; i < processes; i++) {
        finish[i] = 0;
    }

    // Safety check loop
    int found = 0;
    for (int k = 0; k < processes; k++) {
        found = 0;
        for (int i = 0; i < processes; i++) {
            if (finish[i] == 0 && need[i][0] <= work[0] && need[i][1] <= work[1] && need[i][2] <= work[2]) {
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    work[j] += allocated[i][j];
                }
                finish[i] = 1;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            return 0; // System is not in safe state
        }
    }

    // Check if all processes are finished
    for (int i = 0; i < processes; i++) {
        if (finish[i] == 0) {
            return 0; // System is not safe
        }
    }

    // Restore work vector
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = work_copy[i];
    }

    return 1; // System is in safe state
}

int main() {
    int processes, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the available resources (R1, R2, R3): ");
    scanf("%d %d %d", &resources[0], &resources[1], &resources[2]);

    printf("Enter the maximum needs of each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d:\n", i + 1);
        for (j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources to each process:\n");
    for (i = 0; i < processes; i++) {
        printf("Process %d:\n", i + 1);
        for (j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &allocated[i][j]);
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    if (is_safe(processes, resources)) {
        printf("System is in safe state\n");
    } else {
        printf("System is not in safe state\n");
    }

    return 0;
}
