#ifndef _BODYSYSTEM_H
#define _BODYSYSTEM_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Body.h"

//-------------------------------------------------------------
// A BodySystem contains a set of bodies which it updates
// according to a time step and simulates the forces of all
// of the bodies in the system on one another.
//-------------------------------------------------------------
class BodySystem : public sf::Drawable
{

public:
	// Default constructor initializes demo bodies
	BodySystem();

	// Default constructor releases the bodies in the system from memory
	~BodySystem();

	// Update the positions and velocities of the bodies in the system
	void update(sf::Time deltaTime);

	// Draw each of the bodies in the system
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	// Fixed physics time step
	double _timeStep = 1;

	std::vector<Body*> _bodies;

	// Initializes a set of demo bodies and sets the accelerations for the first step
	void initDemoBodies();
	
	// Returns a scalar for the tangent velocity required for a circular orbit at a distance
	// around the solar mass
	double createCircleOrbit(double dist);

	// Resets and computes the net accelerations on each body
	void computeAccelerations();
		
};

#endif // !_BODYSYSTEM_H
