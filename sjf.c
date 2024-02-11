#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int turnaround_time;
  int waiting_time;
};
// Function to calculate turnaround time and waiting time using SJF
void SJF(struct Process processes[], int n) {
  int remaining_time[n];
  int completed_processes = 0;
  int current_time = 0;
  // Initialize remaining_time array
  for (int i = 0; i < n; i++) {
    remaining_time[i] = processes[i].burst_time;
  }
  while (completed_processes < n) {
    int shortest_job = -1;
    int shortest_time = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (processes[i].arrival_time <= current_time && remaining_time[i] < shortest_time && remaining_time[i] > 0) {
      shortest_job = i;
      shortest_time = remaining_time[i];
  }
}
if (shortest_job == -1) {
  current_time++;
} else {
  remaining_time[shortest_job]--;
  if (remaining_time[shortest_job] == 0) {
    completed_processes++;
    processes[shortest_job].turnaround_time = current_time - processes[shortest_job].arrival_time + 1;
    processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time -
    processes[shortest_job].burst_time;
  }
  current_time++;
  }
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
SJF(processes, n);
printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (int i = 0; i < n; i++) {
printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
}

return 0;
}
