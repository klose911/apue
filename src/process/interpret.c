#include <sys/types.h>
#include <sys/wait.h>
#include "apue.h"

int main(void)
{
        pid_t pid;

        if( (pid = fork()) < 0 )
                err_sys("fork error");
        else if ( 0 == pid )
                if(execl("/home/klose/bin/testinterp",
                         "testinterp", "myarg1", "MY ARG2", (char *) 0 ) < 0 )
                        err_sys("execl error");

        if (waitpid(pid, NULL, 0) != pid )
                err_sys("waitpid error");

        exit(0);
        
}
