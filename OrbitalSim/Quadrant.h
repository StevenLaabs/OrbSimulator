#ifndef _QUADRANT_H
#define _QUADRANT_H

class Quadrant
{

public:

	// Default constructor for quadrant, initialize with position and length of quadrant
	Quadrant(double posX, double posY, double length);

	~Quadrant();

	// Return the length of the quadrant
	double getLength() const;

	// Return positions of the quadrant
	double getposX() const;
	double getposY() const;

	// Return true if the point is contained within the quadrant, false otherwise
	bool contains(double posX, double posY) const;

	// Methods to subdivide new quadrants in the 4 quarters of this quadrant
	Quadrant* makeNW();
	Quadrant* makeNE();
	Quadrant* makeSW();
	Quadrant* makeSE();

private:

	double _posX, _posY;
	double _length;

};

#endif // !_QUADRANT_H
