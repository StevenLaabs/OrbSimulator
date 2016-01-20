#include "Quadrant.h"
#include <cassert>

Quadrant::Quadrant(double posX, double posY, double length) : posX(posX), posY(posY), length(length)
{
	assert(length >= 0);
}

double Quadrant::getLength() const { return length; }

double Quadrant::getposX() const { return posX; }

double Quadrant::getposY() const { return posY; }

bool Quadrant::contains(double posX, double posY) const
{
	return (posX <= this->posX + length / 2.0 && posX >= this->posX - length / 2.0 &&
		     posY <= this->posY + length / 2.0 && posY >= this->posY - length / 2.0);
}

Quadrant* Quadrant::makeNW()
{
	Quadrant* quad = new Quadrant(posX - length / 4.0, posY + length / 4.0, length / 2.0);
	return quad;
}

Quadrant* Quadrant::makeNE()
{
	Quadrant* quad = new Quadrant(posX + length / 4.0, posY + length / 4.0, length / 2.0);
	return quad;
}

Quadrant* Quadrant::makeSW()
{
	Quadrant* quad = new Quadrant(posX - length / 4.0, posY - length / 4.0, length / 2.0);
	return quad;
}

Quadrant* Quadrant::makeSE()
{
	Quadrant* quad = new Quadrant(posX + length / 4.0, posY - length / 4.0, length / 2.0);
	return quad;
}