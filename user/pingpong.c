#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    char b1[10], b2[10];
    int p1[2]; //父进程写，子进程读的管道
    int p2[2]; //子进程写，父进程读的管道
    pipe(p1);
    pipe(p2);
    if (fork() == 0)
    {
        close(p1[1]); //关闭父进程写子进程
        close(p2[0]); //关闭子进程写父进程
        read(p1[0], b1, 1);
        if (b1[0] == 'c')
        {
            fprintf(1, "%d: received ping\n", getpid());
            write(p2[1], "p", 1);
        }

        close(p1[0]);
        close(p2[1]);
        exit(0);
    }
    else
    {
        close(p1[0]); //关闭父进程写子进程
        close(p2[1]); //管别子进程读父进程
        write(p1[1], "c", 1);
        read(p2[0], b2, 1);
        if (b2[0] == 'p')
        {
            fprintf(1, "%d: received pong\n", getpid());
        }
        close(p1[1]);
        close(p2[0]);
        exit(0);
    }
    exit(0);
}