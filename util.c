#include "util.h"

char* util_read_file_buffer(
		const char* filename)
{
	FILE* input_file = fopen(filename, "r");
	if (!input_file)
		return NULL;

	// get total size of file (in bytes)
	if (fseek(input_file, 0, SEEK_END) == -1)
		return NULL;

	size_t n_bytes = ftell(input_file);

	rewind(input_file);

	char* file_buffer = calloc(n_bytes + 1, sizeof(char));
	if (!file_buffer)
		return NULL;

	size_t read_bytes = fread(file_buffer, sizeof(char), n_bytes, input_file);
	
	if (read_bytes < n_bytes)
	{
		free(file_buffer);
		return NULL;
	}

	file_buffer[read_bytes] = '\0';

	fclose(input_file);

	return file_buffer;
}

bool util_tokenize_newline(
		const char* char_buffer,
		size_t* char_iter,
		char* dest_buffer)
{
	size_t char_buffer_len = strlen(char_buffer);
	if (*char_iter >= char_buffer_len)
		return false;

	memset(dest_buffer, 0, strlen(dest_buffer));

	// keep reading characters from buffer until newline
	// or end of buffer
	size_t dest_buffer_idx = 0;
	while (*char_iter < char_buffer_len
			&& char_buffer[*char_iter] != '\n')
	{
		dest_buffer[dest_buffer_idx++] = char_buffer[(*char_iter)++];
	}

	(*char_iter)++; // move past newline after tokenizing
	return true;
}

bool util_tokenize_newline_toint(
		const char* char_buffer,
		size_t* char_iter,
		int64_t* dest_int)
{
	char dest_buffer[51];
	memset(dest_buffer, 0, 51);
	bool ret_value = util_tokenize_newline(char_buffer, char_iter, dest_buffer);
	char* endptr = NULL;
	*dest_int = strtoll(dest_buffer, &endptr, 10);

	return ret_value;
}
