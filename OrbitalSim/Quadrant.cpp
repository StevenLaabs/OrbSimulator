#include "Quadrant.h"
#include <cassert>

Quadrant::Quadrant(double posX, double posY, double length) : _posX(posX), _posY(posY), _length(length)
{
	assert(length >= 0);
}

Quadrant::~Quadrant() {}

double Quadrant::getLength() const { return _length; }

double Quadrant::getposX() const { return _posX; }

double Quadrant::getposY() const { return _posY; }

bool Quadrant::contains(double posX, double posY) const
{
	return (posX <= this->_posX + _length / 2.0 && posX >= this->_posX - _length / 2.0 &&
		     posY <= this->_posY + _length / 2.0 && posY >= this->_posY - _length / 2.0);
}

Quadrant* Quadrant::makeNW()
{
	Quadrant* quad = new Quadrant(_posX - _length / 4.0, _posY + _length / 4.0, _length / 2.0);
	return quad;
}

Quadrant* Quadrant::makeNE()
{
	Quadrant* quad = new Quadrant(_posX + _length / 4.0, _posY + _length / 4.0, _length / 2.0);
	return quad;
}

Quadrant* Quadrant::makeSW()
{
	Quadrant* quad = new Quadrant(_posX - _length / 4.0, _posY - _length / 4.0, _length / 2.0);
	return quad;
}

Quadrant* Quadrant::makeSE()
{
	Quadrant* quad = new Quadrant(_posX + _length / 4.0, _posY - _length / 4.0, _length / 2.0);
	return quad;
}