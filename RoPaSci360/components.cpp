#include "components.h"

Token::Token(int r, int q, char value)
{
	this->r = r;
	this->q = r;
	this->value = value;
}

Hex::Hex(int r, int q)
{
	_r = r;
	_q = q;
	tokens = new std::vector<Token>;
}

Hex::~Hex()
{
	delete tokens;
}

int Hex::r() const
{
	return _r;
}

int Hex::q() const
{
	return _q;
}

Board::Board(int radius)
{	
	if (radius < 0) 
	{
		throw std::domain_error(R"(radius must not be negative)");
	}
	_radius = radius;
	int64_t range = 1LL + (int64_t)2 * radius;
	core = new Hex**[range];
	for (int r = radius; r >= -radius; r--) 
	{
		core[radius - r] = new Hex * [range - abs(r)];

		// q = starts_from + j
		// int starts_from = -radius - r < 0 ? r : 0;
		int starts_from = r < 0 ? -radius - r : -radius;
		for (int j = 0; j < range - abs(r); j++)
		{			
			core[radius - r][j] = new Hex(r, starts_from + j);
		}
	}
}

Board::~Board()
{
	delete core;
}

bool Board::isValid(int r, int q)
{
	if (!utils::inRange(r, -_radius, _radius))
	{
		return false;
	}
	int q_start = r > 0 ? -_radius : -_radius - r;
	int q_count = 1 + 2 * _radius - abs(r);
	return utils::inRange(q, q_start, q_start + q_count);
}

int Board::radius() const
{
	return _radius;
}

Hex* Board::get(int r, int q)
{
	if (!utils::inRange(r, -_radius, _radius)
		|| !utils::inRange(q, -_radius, _radius)) 
	{
		std::domain_error(R"(Invalid domain)");
	}
	return core[_radius - r][r < 0 ? q + r + _radius : q + _radius];
}

int* utils::range(int start, int end)
{	
	if (end <= start) return nullptr;
	int *returnable = 
		new int[(int64_t) end - (int64_t) start];
	for (int i = start; i < end; i++) 
	{
		returnable[i - start] = i;
	}
	return returnable;
}

bool utils::inRange(int given, int start, int end)
{	
	return end > start && given >= start && given < end;
}
