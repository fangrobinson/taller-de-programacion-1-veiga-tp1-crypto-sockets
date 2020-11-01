#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include <stdio.h>


typedef struct {
	FILE *fp;
	unsigned int buffer_size;
} file_reader_t;


int file_reader_init(file_reader_t *self,
	const unsigned int buffer_size);

int file_reader_uninit(file_reader_t *self);

// mueve al buffer los contenidos del FILE de a chunks con buffer_size
// devuelve la cantidad de bytes escritos en buffer
// o 0 en feof
int file_reader_next(file_reader_t *self, char *buffer);

#endif
