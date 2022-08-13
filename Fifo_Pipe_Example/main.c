

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <wait.h>
#include <string.h>
#include <stdio.h>
#include "ErrorHandling.h"

void childTask()
{
    int writeIntoTheChannel = open( "ReadFromConsole", O_WRONLY );
    if( writeIntoTheChannel == -1 )
    {
        openPipeError();
    }
    else
    {
        char message[ MAX_MESSAGE_LENGTH ];

        scanf("%s", message );
        unsigned long int bufferSize = strlen( message );

        write( writeIntoTheChannel, & bufferSize, sizeof ( int ) );
        long int canBeWritten =  write( writeIntoTheChannel , message, strlen(message ) );

        if( canBeWritten == -1 )
        {
            writePipeError();
        }
        int canBeClosed = close(writeIntoTheChannel );
        if( canBeClosed == -1 )
        {
            closePipeError();
        }
    }
}
void parentTask()
{
    int readFromTheChannel = open( "ReadFromConsole", O_RDONLY );

    if( readFromTheChannel == -1 )
    {
        openPipeError();
    }
    else
    {
        char message[ MAX_MESSAGE_LENGTH ];
        int bufferSize;

        wait( nullptr );
        /*
         * before doing any operations on the fifo file the parent must wait for the child to
         * write all the necessary data into it, otherwise the read() call will block the program ( starving effect will occur )
         */

        read( readFromTheChannel, & bufferSize, sizeof ( int ) );
        long int canBeRead = read( readFromTheChannel, message, bufferSize );

        if( canBeRead == -1 )
        {
            readPipeError();
        }
        else
        {
            printf( "The message received from the child is: %s \n", message);
        }

        int canBeClosed =  close( readFromTheChannel );
        if( canBeClosed == -1 )
        {
            closePipeError();
        }
    }
}
int main()
{
    int createFifo = mkfifo("ReadFromConsole", 0666);

    if( createFifo == -1 )
    {
        fileCreateError( "ReadFromConsole" );
    }
    else
    {
        pid_t processId = fork();
        if( processId == 0 )
        {
            // do the child task
            childTask();
        }
        else
        {
            // do the parent task
            parentTask();
        }

       remove( "ReadFromConsole" );    /// after finishing using the fifo file it must be removed in order to create it again when rerunning the program
    }
    return 0;
}