//
// Created by stefan on 13.08.2022.
//

#ifndef PIPETEST_ERRORHANDLING_H
#define PIPETEST_ERRORHANDLING_H

#define MAX_MESSAGE_LENGTH 256

void openPipeError();
void closePipeError();
void fileCreateError( const char * fileName );
void removeFileError( const char * fileName );
void writePipeError();
void readPipeError();

#endif //PIPETEST_ERRORHANDLING_H
