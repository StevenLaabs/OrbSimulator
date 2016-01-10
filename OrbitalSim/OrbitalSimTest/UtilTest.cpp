#include <gtest\gtest.h>
#include <SFML\Graphics.hpp>
#include "..\util.h"

//-------------------------------------------------
// UtilTest runs tests for utility methods
//-------------------------------------------------

TEST(CenterOriginTest, CenterOrigin)
{
	sf::CircleShape shape(20);

	orbutil::centerOrigin(shape);

	EXPECT_EQ(20, shape.getOrigin().x);
	EXPECT_EQ(20, shape.getOrigin().y);
}

TEST(NormalizeTest, NormalizeVector)
{
	sf::Vector2<double> vector(2, 2);

	orbutil::normalize(vector);

	EXPECT_EQ(0.707107, vector.x);
	EXPECT_EQ(0.707107, vector.y);
}		