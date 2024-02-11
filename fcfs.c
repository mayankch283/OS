#include <stdio.h>
struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int turnaround_time;
  int waiting_time;
};
void calculateTimes(struct Process processes[], int n) {
  int current_time = 0;
  for (int i = 0; i < n; i++) {
    if (processes[i].arrival_time > current_time) {
      current_time = processes[i].arrival_time;
    }
  processes[i].waiting_time = current_time - processes[i].arrival_time;
  processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
  current_time += processes[i].burst_time;
    }
}
int main() {
  int n = 4; // Number of processes
  struct Process processes[n];
  // Initialize processes (you can modify these values)
  processes[0] = (struct Process){1, 0, 6, 0, 0};
  processes[1] = (struct Process){2, 1, 8, 0, 0};
  processes[2] = (struct Process){3, 2, 7, 0, 0};
  processes[3] = (struct Process){4, 3, 3, 0, 0};
  calculateTimes(processes, n);
  printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
    processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
  }
}
return 0;
