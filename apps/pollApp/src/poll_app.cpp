#include <unistd.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/select.h> 
 
#define NUMBER_OF_BYTE 100 
#define CHAR_DEVICE "/dev/pcmchar" 
 
char data[NUMBER_OF_BYTE]; 
 
int main(int argc, char **argv) 
{ 
    int fd, retval; 
    ssize_t read_count; 
    fd_set readfds; 
 
    fd = open(CHAR_DEVICE, O_RDONLY); 
    if(fd < 0) 
        /* Print a message and exit*/ 
        {printf("\nCan't open the PCM Device \n");}
 
    while(1){  
        FD_ZERO(&readfds); 
        FD_SET(fd, &readfds); 
 
        /* 
         * One needs to be notified of "read" events only, without timeout. 
         * This call will put the process to sleep until it is notified the 
         * event for which it registered itself 
         */ 
        int ret = select(fd + 1, &readfds, NULL, NULL, NULL); 
 
        /* From this line, the process has been notified already */ 
        if (ret == -1) { 
            printf("\nselect call on %s: an error ocurred\n", CHAR_DEVICE); 
            break; 
        } 
     
        /* 
         * file descriptor is now ready. 
         * This step assume we are interested in one file only. 
         */ 
        if (FD_ISSET(fd, &readfds)) { 
            read_count = read(fd, data, NUMBER_OF_BYTE); 
            if (read_count < 0 ) 
                /* An error occured. Handle this */ 
                {printf("\nRead failure on PCM Device \n");}
                else
                {
                    printf("\n %s \n", data);
                }
                
        } 
    }     
    close(fd); 
    return EXIT_SUCCESS; 
} 