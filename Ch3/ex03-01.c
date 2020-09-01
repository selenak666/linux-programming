/* program ex03-01.c */
#include <stdio.h> 
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

        int filedes, fdnew1, fdnew2;
        ssize_t nread;  /* datatype; singed int */
        off_t newpos;   /* datatype; long int; for the offset bytes */

        char buffer[1024];  
        char content[] = "Hello my friend!!\n"; 
        
        /* open a file 'data.txt' for Read and Write*/ 
        /*return value <- file descriptor*/
        filedes = open("data.txt", O_RDWR);
        
        /*read max 1024 bytes from filedes into buffer  
        return value <- number of bytes read*/
        nread = read(filedes, buffer, 1024);
        
        /* print out buffer */
        printf("%s", buffer);
        
        /* write content to filedes from the position of the r/w pointer(the end of the filedes)*/
        write(filedes, content, strlen(content));
        
        /*reposition r/w pointer to the beginning of the file*/
        newpos = lseek(filedes, (off_t)0, SEEK_SET);
        
        /*read from the file, 1024 bytes*/
        nread = read(filedes, buffer, 1024);
        
        /*print out and then close the file*/
        printf("%s", buffer);
        close(filedes);

        fdnes1 = open("newdata1.txt", O_RDWR | O_CREAT, 0644);
        fdnew2 = create("newdata2.txt", 0644);

        close(fdnew1); close(fdnew2);
        unlink("newdata2.txt");

}
