#include "Body.h"
#include <math.h>
#include "util.h"

Body::Body(double m, sf::Vector2<double> pos, sf::Vector2<double> vel, float radius, sf::Color color) : 
	_mass(m), _position(pos), _velocity(vel), _acceleration(0, 0), _oldAcceleration(_acceleration), _shape(radius)
{
	_shape.setFillColor(color);
	orbutil::centerOrigin(_shape);
}

Body::~Body() {}

void Body::applyAcceleration(Body& other)
{
	// Avoid calculation with self
	if (&other != this)
	{
		double distance = bodyDist(other);

		sf::Vector2<double> accelDirection = other._position - _position;
		orbutil::normalize(accelDirection);

		double accelMagnitude = (orbutil::G * other._mass) / (distance * distance);

		_acceleration += (accelDirection * accelMagnitude);
	}
}

void Body::resetAcceleration()
{
	_acceleration.x = 0;
	_acceleration.y = 0;
}

void Body::updatePosition(double deltaTime)
{	
	_oldAcceleration = _acceleration;
	_position += _velocity * deltaTime + 0.5 * _acceleration * deltaTime * deltaTime;
}

void Body::updateVelocity(double deltaTime)
{
	_velocity += 0.5 * (_oldAcceleration + _acceleration) * deltaTime;
}

void Body::updateRender()
{
	float posX = _position.x * (orbutil::SCREEN_WIDTH / 2) / orbutil::UNIVERSE_RADIUS;
	float posY = _position.y * (orbutil::SCREEN_HEIGHT / 2) / orbutil::UNIVERSE_RADIUS;
	_shape.setPosition(posX + (orbutil::SCREEN_WIDTH / 2), posY + (orbutil::SCREEN_HEIGHT / 2)); // origin of universe center of screen
}

double Body::bodyDist(Body& other)
{
	double x = _position.x - other._position.x;
	double y = _position.y - other._position.y;

	return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

void Body::setVelocity(sf::Vector2<double> velocity)
{
	_velocity = velocity;
}

double Body::getVelocity() const
{
	return std::sqrt(std::pow(_velocity.x, 2) + std::pow(_velocity.y, 2));
}

double Body::getAcceleration() const
{
	return std::sqrt(std::pow(_acceleration.x, 2) + std::pow(_acceleration.y, 2));
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape);
}