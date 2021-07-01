// RoPaSci360.cpp : Defines the entry point for the application.
//

#include "RoPaSci360.h"
#include "components.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	int radius = 4;
	Board board = Board(radius);

	cout << "Board created with radius " << radius << endl;

	int64_t range = 1LL + (int64_t)2 * radius;
	
	uint32_t count = 0;

	for (int r = -radius; r <= radius; r++) 
	{
		int starts_from = r < 0 ? -radius - r : -radius;
		for (int q = starts_from; q < range - abs(r) + starts_from; q++)
		{
			Hex* test_hex = board.get(r, q);
			printf("(r, q) = (%d, %d).\n", test_hex->r(), test_hex->q());

			if (r == test_hex->r() && q == test_hex->q())
			{
				std::cout << "Passed: " << count++ << std::endl;
			}
		}
	}

	return 0;
}
