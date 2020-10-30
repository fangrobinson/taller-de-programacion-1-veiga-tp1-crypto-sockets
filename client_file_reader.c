#include "client_file_reader.h"

int file_reader_init(file_reader_t *self,
					const unsigned int buffer_size){
	self->fp = stdin;
	self->buffer_size = buffer_size;
	return 0;
}
int file_reader_uninit(file_reader_t *self){
	if (self->fp != stdin) {
		fclose(self->fp);
	}
	return 0;
}

int file_reader_next(file_reader_t *self, char *buffer){
	if (!feof(self->fp)) {
		size_t result = fread(buffer, 1, self->buffer_size, self->fp);
		return result;
	}
	return 0;
}
