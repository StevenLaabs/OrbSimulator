#ifndef _BODY_H
#define _BODY_H

#include <SFML\Graphics.hpp>

//---------------------------------------------------------
// A Body represents a single body in an N-body simulation
// which is moved according to its velocity and by the
// forces of other bodies in the same system
//---------------------------------------------------------
class Body : public sf::Drawable
{

public:
	// Normal constructor requires the mass, position, and velocity of the body
	Body(double m, sf::Vector2<double> pos, sf::Vector2<double> vel = sf::Vector2<double>(0, 0), 
		  float radius = 20, sf::Color color = sf::Color::Blue);
	
	// Default constructor, currently unused
	~Body();

	// Applies an acceleration to the body brought about by the force of another body in the system
	void applyAcceleration(Body& other);

	// Resets the body acceleration to 0
	void resetAcceleration();

	// Sets the old acceleration and updates the position of the body according
	// to the velocity, acceleration, and time step
	void updatePosition(double deltaTime);

	// Updates the velocity of the body using the old and new acceleration and time step
	void updateVelocity(double deltaTime);

	// Updates the SFML shape to the proper screen position relative to the body position
	void updateRender();

	// Returns the scalar value of the distance between two bodies
	double bodyDist(Body& other);

	// Sets exact velocity vector for the body
	void setVelocity(sf::Vector2<double> velocity);

	// Returns the scalar magnitude of the velocity
	double getVelocity() const;

	// Returns the scalar magnitude of the acceleration
	double getAcceleration() const;

	// Renders the body's shape on to the window
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// debugging output
	friend std::ostream& operator<<(std::ostream& os, const Body& obj)
	{
		return os << "Velocity: " << obj._velocity.x << " " << obj._velocity.y
			<< " Acceleration: " << obj._acceleration.x << " " << obj._acceleration.y
			<< " Position: " << obj._position.x << " " << obj._position.y
			<< " Mass: " << obj._mass;
	}


private:
	sf::Vector2<double> _position;
	sf::Vector2<double> _velocity;
	sf::Vector2<double> _acceleration;
	sf::Vector2<double> _oldAcceleration;
	double _mass;

	sf::CircleShape _shape;
};

#endif // !_BODY_H
