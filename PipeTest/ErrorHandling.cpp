//
// Created by stefan on 13.08.2022.
//
#include "ErrorHandling.h"
#include <stdio.h>
#include <stdlib.h>

void openPipeError()
{
    printf("The pipe couldn't be open! \n");
    exit( 904 );
}
void closePipeError()
{
    printf( "The pipe couldn't be closed! \n");
    exit( 905 );
}
void fileCreateError( const char * fileName )
{
    printf( "%s couldn't be created. Please check if the file is already created. \n", fileName );
    exit( 404 );
}
void removeFileError( const char * fileName )
{
    printf( "An error has occurred when trying to remove %s. \n", fileName );
    exit( 405 );
}
void writePipeError()
{
    printf(" THe information couldn't be written into the pipe! \n" );
    exit( 980 );
}
void readPipeError()
{
    printf( "The information couldn't be read from the pipe! \n" );
    exit( 981 );
}