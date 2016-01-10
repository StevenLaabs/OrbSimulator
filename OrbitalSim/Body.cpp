#include "Body.h"
#include <math.h>
#include "util.h"

Body::Body(double m, sf::Vector2<double> pos, sf::Vector2<double> vel, float radius, sf::Color color) : 
	mass(m), position(pos), velocity(vel), acceleration(0, 0), oldAcceleration(acceleration), shape(radius)
{
	shape.setFillColor(color);
	orbutil::centerOrigin(shape);
}

Body::~Body() {}

void Body::applyAcceleration(Body& other)
{
	// Avoid calculation with self
	if (&other != this)
	{
		double distance = bodyDist(other);

		sf::Vector2<double> accelDirection = other.position - position;
		orbutil::normalize(accelDirection);

		double accelMagnitude = (orbutil::G * other.mass) / (distance * distance);

		acceleration += (accelDirection * accelMagnitude);
	}
}

void Body::resetAcceleration()
{
	acceleration.x = 0;
	acceleration.y = 0;
}

void Body::updatePosition(double deltaTime)
{	
	oldAcceleration = acceleration;
	position += velocity * deltaTime + 0.5 * acceleration * deltaTime * deltaTime;
}

void Body::updateVelocity(double deltaTime)
{
	velocity += 0.5 * (oldAcceleration + acceleration) * deltaTime;
}

void Body::updateRender()
{
	float posX = position.x * (orbutil::SCREEN_WIDTH / 2) / orbutil::UNIVERSE_RADIUS;
	float posY = position.y * (orbutil::SCREEN_HEIGHT / 2) / orbutil::UNIVERSE_RADIUS;
	shape.setPosition(posX + (orbutil::SCREEN_WIDTH / 2), posY + (orbutil::SCREEN_HEIGHT / 2)); // origin of universe center of screen
}

double Body::bodyDist(Body& other)
{
	double x = position.x - other.position.x;
	double y = position.y - other.position.y;

	return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

double Body::getVelocity() const
{
	return std::sqrt(std::pow(velocity.x, 2) + std::pow(velocity.y, 2));
}

double Body::getAcceleration() const
{
	return std::sqrt(std::pow(acceleration.x, 2) + std::pow(acceleration.y, 2));
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}