#include <stdio.h>
#include <stdlib.h>

void print_with_disorder(float disorder, int n)
{
	long long max_inv;
	long long target;
	int *out;
	int left;
	int right;
	int low;
	int high;

	max_inv = (long long)n * (n - 1) / 2;
	target = (long long)(disorder * max_inv + 0.5);

	out = malloc(sizeof(int) * n);

	left = 0;
	right = n - 1;

	low = 1;
	high = n;

	while (low <= high)
	{
		if (target >= high - low)
		{
			out[left++] = high;
			target -= (high - low);
			high--;
		}
		else
		{
			out[right--] = high;
			high--;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d%c", out[i], i == n - 1 ? '\n' : ' ');

	free(out);
}

int main(int argc, char **argv)
{
	if (argc == 1 || argc > 3)
		return 0;
	print_with_disorder(strtof(argv[1], NULL), atoi(argv[2]));
	return 0;
}
