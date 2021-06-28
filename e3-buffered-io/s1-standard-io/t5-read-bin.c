#include "apue.h"

// size_t fread(void *buf , size_t size, size_t nr, FILE *stream);

/*
A call to fread() will read up to nr elements of data each of size bytes from stream into the buffer pointed at by buf.
The file pointer is advanced by the number of bytes read.
*/