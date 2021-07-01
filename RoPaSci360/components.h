
#include <stdint.h>
#include <vector>
#include <iostream>

class Token 
{

private:
	char value;
	int r, q;

public:
	Token(int r, int q, char value);

};


class Hex 
{

private:
	int _r, _q;
	std::vector<Token> *tokens;

public:
	Hex(int r, int q);
	~Hex();
	int r() const;
	int q() const;
};

class Board 
{

private:
	int _radius;
	Hex*** core;

public:
	Board(int radius);
	~Board();

	bool isValid(int r, int q);

	int radius() const;
	Hex* get(int r, int q);
};

namespace utils {
	/* Create an int array [start, end].
	This creates a new memory block in heap. */
	int* range(int start, int end);
	/* Return true if a given int is within [start, end) */
	bool inRange(int given, int start, int end);
}
