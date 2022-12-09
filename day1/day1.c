#include "util.h"

// maintain a sorted array of top three items
// replace the appropriate value and shift others down
// (the last element is "popped" off)
static void _set_max(
		int64_t* current_sum,
		int64_t* top_three)
{
	for (size_t i = 0; i < 3; ++i)
	{
		if (*current_sum > top_three[i])
		{
			for (size_t k = 2; k > i; k--)
				top_three[k] = top_three[k - 1];
			top_three[i] = *current_sum;
			break;
		}
	}
}

int main()
{
	char* file_buffer = util_read_file_buffer("day1.txt");
	if (!file_buffer)
	{
		fprintf(stderr, "There was a problem reading the file.\n");
		return -1;
	}

	int64_t top_three[3] = { 0, 0, 0 };
	int64_t current_sum = 0;

	size_t line_idx = 0;
	int64_t token_value = 0;
	while (util_tokenize_newline_toint(file_buffer, &line_idx, &token_value))
	{
		if (token_value == 0) // new line
		{
			if (current_sum > top_three[2])
				_set_max(&current_sum, top_three);
			current_sum = 0;
		}
		current_sum += token_value;
	}

	if (current_sum > top_three[2])
		_set_max(&current_sum, top_three);

	// reusing variable because I'm lazy
	current_sum = top_three[0] + top_three[1] + top_three[2];

	printf("SUM OF TOP THREE MAX VALUES: %ld\n", current_sum);

	free(file_buffer);

	return 0;
}
