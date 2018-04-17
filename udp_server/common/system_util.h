#ifndef _SYSTEM_UTIL_H_
#define _SYSTEM_UTIL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <stdarg.h>
#include <string.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <signal.h>


int daemon_init_func(int nochdir,int noclose){
    pid_t pid = 0 ;
    if( (pid = fork() ) < 0 ) return -1 ;
    else if(pid != 0 )  _exit(0) ;
    
    setsid() ;

    // Ensure future opens won't allocate controlling TTYs
    struct sigaction sa ;
	memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SIG_IGN; 
    sigemptyset(&sa.sa_mask); 
    if (sigaction(SIGHUP, &sa, NULL) < 0) return -1 ;

    if( (pid = fork() ) < 0 ) return -1 ;
    else if(pid != 0 )  _exit(0) ;

    if((!nochdir) && (chdir("/")!=0) ) return -1 ;

    if(!noclose)
    {
        int fd =  open("/dev/null", O_RDWR);
        if(fd < 0 ) return -1 ;
        dup2(fd,0) ;
        dup2(fd,1) ;
        dup2(fd,2) ;
        close(fd);
    }

    return 0 ;
}


#endif
