#pragma once

struct CursorPos : COORD
{
public:

	CursorPos() noexcept{ X = 0; Y = 0; };

	explicit CursorPos(SHORT _x, SHORT _y)
	{
		X = _x;
		Y = _y;
	}
	explicit CursorPos(const COORD& F) 
	{
		this->X = F.X; 
		this->Y = F.Y; 
	}
	//explicit CursorPos(const CursorPos& Pos)
	//{
	//	X += Pos.X;
	//	Y += Pos.Y;
	//}
	operator COORD() const { return CursorPos(*this); }
public:
	CursorPos operator+(const CursorPos& pos)
	{
		return CursorPos(X + pos.X, Y + pos.Y);
	}
	CursorPos operator-(const CursorPos& pos)
	{
		return CursorPos(X - pos.X, Y - pos.Y);
	}
	CursorPos operator*(const CursorPos& pos)
	{
		return CursorPos(X * pos.X, Y * pos.Y);
	}
	CursorPos operator/(const CursorPos& pos)
	{
		return CursorPos(X / pos.X, Y / pos.Y);
	}
	//-----------------------------------------------
	void operator+=(const CursorPos& pos)
	{
		X += pos.X;
		Y += pos.Y;
	}
	void operator-=(const CursorPos& pos)
	{
		X -= pos.X;
		Y -= pos.Y;
	}
	void operator*=(const CursorPos& pos)
	{
		X *= pos.X;
		Y *= pos.Y;
	}
	void operator/=(const CursorPos& pos)
	{
		X /= pos.X;
		Y /= pos.Y;
	}
	//-----------------------------------------------
	void operator++(int)
	{
		++X;
		++Y;
	}
	void operator--(int)
	{
		--X;
		--Y;
	}
	void operator++()
	{
		++X;
		++Y;
	}
	void operator--()
	{
		--X;
		--Y;
	}
	//-----------------------------------------------
	CursorPos& operator=(const CursorPos& pos)
	{
		this->X = pos.X;
		this->Y = pos.Y;

		return *this;
	}
	CursorPos& operator=(const COORD& pos)
	{
		this->X = pos.X;
		this->Y = pos.Y;
		return *this;
	}
	CursorPos& operator=(std::initializer_list<int> values)
	{
		auto it = values.begin();
		if (values.size() >= 2)
		{ // Ensure the initializer list has at least two elements
			this->X = (SHORT)*it;
			this->Y = (SHORT)*(it + 1);
		}
		return *this;
	}
	CursorPos& operator=(std::initializer_list<SHORT> values)
	{
		auto it = values.begin();
		if (values.size() >= 2) 
		{ // Ensure the initializer list has at least two elements
			this->X = *it;
			this->Y = *(it + 1);
		}
		return *this;
	}
	//-----------------------------------------------
	CursorPos operator+() const { return CursorPos(*this); }
	CursorPos operator-() const { return CursorPos(-X, -Y); }
	//-----------------------------------------------
	bool operator == (const CursorPos& Pos) const { return X == Pos.X && Y == Pos.Y; }
	bool operator != (const CursorPos& Pos) const { return X != Pos.X || Y != Pos.Y; }
	//-----------------------------------------------
};