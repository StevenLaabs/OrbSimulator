#include "BodySystem.h"
#include "util.h"

BodySystem::BodySystem()
{
	initDemoBodies();
}

BodySystem::~BodySystem()
{
	for (unsigned int i = 0; i < _bodies.size(); i++)
		delete _bodies[i];
}

void BodySystem::initDemoBodies()
{
	// units in kg, m, m/s
	_bodies.push_back(new Body(1.989e30, sf::Vector2<double>(0, 0), sf::Vector2<double>(0, 0), 30, sf::Color::Yellow)); // sun

	_bodies.push_back(new Body(5.972e24, sf::Vector2<double>(149600000000, 0), // earth
										sf::Vector2<double>(0, 30000), 7));

	_bodies.push_back(new Body(6.39e23, sf::Vector2<double>(227900000000, 0),
		sf::Vector2<double>(0, 24408), 5, sf::Color::Red)); // mars

	_bodies.push_back(new Body(1.89813e27, sf::Vector2<double>(778500000000, 0),
		sf::Vector2<double>(0, 13069), 10, sf::Color::White)); // jupiter

	// init the accelerations for the first step
	computeAccelerations();
}

void BodySystem::update(sf::Time deltaTime)
{
	// scale the time step with the deltaTime
	double dt = TIME_STEP * deltaTime.asSeconds();

	// update each body position
	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		Body* body = _bodies[i];
		body->updatePosition(dt);
		body->updateRender();
	}

	// Recalculate accelerations and update body velocities
	computeAccelerations();

	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		Body* body = _bodies[i];
		body->updateVelocity(dt);
	}
}

void BodySystem::computeAccelerations()
{
	// reset old accelerations
	for (unsigned int i = 0; i < _bodies.size(); i++)
		_bodies[i]->resetAcceleration();

	// compute new net accelerations
	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		for (unsigned int j = 0; j < _bodies.size(); j++)
			_bodies[i]->applyAcceleration(*_bodies[j]);
	}
}

void BodySystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < _bodies.size(); i++)
	{
		target.draw(*_bodies[i]);
	}
}

double BodySystem::createCircleOrbit(double dist)
{
	// TODO: Remove magic number for the sun's mass
	double centralMass = 1.989e30;
	double numerator = (6.67e-11) * 1e6 * centralMass;

	return std::sqrt(numerator / dist);
}