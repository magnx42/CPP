#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _value;
	static const int _bits;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat();
	int toInt();
};

#endif