#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t child_pid;
    int status;
    // Create a child process using fork()
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Fork failed");
        exit(1);
    }
    if (child_pid == 0)
    {
        // This code is executed by the child process
        printf("Child process: My PID is %d\n", getpid());
        // Execute a program in the child process using exec()
        char *args[] = {"ls", "-l", NULL};
        if (execvp("ls", args) == -1)
        {
            perror("Exec failed");
            exit(1);
        }
    }
    else
    {
        // This code is executed by the parent process
        printf("Parent process: My PID is %d\n", getpid());
        // Wait for the child process to terminate using wait()
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("Child process terminated with status %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child process terminated due to signal %d\n", WTERMSIG(status));
        }
    }
    return 0;
}
