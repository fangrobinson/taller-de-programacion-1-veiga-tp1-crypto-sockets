#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include <stdio.h>


typedef struct {
	FILE *fp;
	unsigned int buffer_size;
} file_reader_t;


int file_reader_init(file_reader_t *self,
	const char *file_name, const unsigned int buffer_size);

int file_reader_uninit(file_reader_t *self);

int file_reader_next(file_reader_t *self, char *buffer);

#endif