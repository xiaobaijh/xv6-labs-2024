#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int time = 0;
    if (argc <= 1)
    {
        fprintf(2, "Please input the time you want to sleep\n");
        exit(1);
    }
    time = atoi(argv[1]);
    sleep(time);
    fprintf(1, "(nothing happens for a little while)\n");
    exit(0);
}
