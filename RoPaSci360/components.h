

#include <vector>

class Token {

private:
	char value;
	int r, q;

public:
	Token(int r, int q, char value);
};


class Hex {

private:
	int r, q;
	std::vector<Token> tokens;

public:
	Hex(int r, int q);
};

class Board {

private:
	Hex*** core;

public:
	Board(uint32_t radius);
};
