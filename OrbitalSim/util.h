#ifndef _UTIL_H
#define _UTIL_H
#include <SFML\Graphics.hpp>

namespace orbutil
{
	// Window constants
	static const int SCREEN_WIDTH = 1000;
	static const int SCREEN_HEIGHT = 700;

	// Universe constants
	static const double G = 6.674e-11;
	static const double UNIVERSE_RADIUS = 1e12;

	//---------------------------
	// Utility methods
	//---------------------------

	// Centers the origin of an SFML CircleShape
	static void centerOrigin(sf::CircleShape& shape)
	{
		float radius = shape.getRadius();

		shape.setOrigin(radius, radius);
	}

	// Normalizes (unit vector of magnitude 1) an SFML Vector2 of any type
	template<typename T>
	static void normalize(sf::Vector2<T>& vec)
	{
		T length = std::sqrt((vec.x * vec.x) + (vec.y * vec.y));

		if (length != 0)
		{
			vec.x = vec.x / length;
			vec.y = vec.y / length;
		}
	}

}


#endif // !_UTIL_H