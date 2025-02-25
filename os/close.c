// C program to illustrate close system Call
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd1 = open("foo.txt", O_WRONLY | O_CREAT);
    if (fd1 < 0)
    {
        perror("Error");
        exit(1);
    }
    printf("opened the fd = % d\n", fd1);
    sleep(5);

    // Using close system Call
    if (close(fd1) < 0)
    {
        perror("Error");
        exit(1);
    }
    printf("closed the fd.\n");
}
