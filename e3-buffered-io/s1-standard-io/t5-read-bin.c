#include "apue.h"

// size_t fread(void *buf , size_t size, size_t nr, FILE *stream);

/*
A call to fread() will read up to nr elements of data each of size bytes from stream into the buffer pointed at by buf.
The file pointer is advanced by the number of bytes read.


The number of elements read (not the number of bytes read!) is returned. The function
indicates failure or EOF via a return value less than nr. Unfortunately, it is impossible to know
which of the two conditions occurred without using ferror( ) and feof( ).
Because of differences in variable sizes, alignment, padding, and byte order, binary data
written with one application may not be readable by a different application, or even by the
same application on a different machine.
*/