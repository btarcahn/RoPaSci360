#include "utils.h"

uint32_t utils::sum(uint32_t n)
{
	if (n <= 0) {
		return 0;
	}

	return n + sum(n - 1);
}
