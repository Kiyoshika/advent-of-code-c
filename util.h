#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

// read entire file contents and return pointer to (dynamically-allocated) buffer.
// returns NULL if a problem occurs opening file or allocating memory.
char* util_read_file_buffer(
		const char* filename);

/*
 * read char_buffer until a newline (or end of buffer) is found and write the contents
 * into dest_buffer (assumes you have pre-allocated the space).
 *
 * returns true if char_buffer still has contents and moves char_iter pointer to the
 * next available location to read from (useful for subsequent calls).
 *
 * returns false when char_buffer has reached the end (still writes any contents into
 * dest_buffer)
 */
bool util_tokenize_newline(
		const char* char_buffer,
		size_t* char_iter,
		char* dest_buffer);

/*
 * a wrapper around util_tokenize_newline which converts the token into
 * a 64-bit signed integer.
 *
 * WARNING: no validation checks are performed, this assumes the token can
 * successfully be converted.
 *
 * returns the same value as util_tokenize_newline - true if char_buffer still
 * contains readable contents, false if char_buffer has reached the end.
 */
bool util_tokenize_newline_toint(
		const char* char_buffer,
		size_t* char_iter,
		int64_t* dest_int);
		
#endif
