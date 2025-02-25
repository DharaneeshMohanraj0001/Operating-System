#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", "/home", NULL};

    printf("Before execvp\n");

    // Replace the current process with the "ls" command
    if (execvp("ls", args) == -1)
    {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }

    // This line will not be executed if execvp is successful
    printf("After execvp\n");

    return 0;
}