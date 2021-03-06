#include <gtest\gtest.h>
#include "..\Body.h"
#include "..\util.h"
#include <vector>
#include <SFML\System.hpp>

//-------------------------------------------------
// BodyTest runs tests for methods within the
// Body class
//-------------------------------------------------
struct BodyTest : testing::Test
{

	std::vector<Body> bodies;

	BodyTest()
	{
		bodies.push_back(Body(1.989e30, sf::Vector2<double>(-orbutil::UNIVERSE_RADIUS / 2, 0)));
		bodies.push_back(Body(5.972e24, sf::Vector2<double>(orbutil::UNIVERSE_RADIUS / 2, 0)));
		bodies.push_back(Body(5.972e24, sf::Vector2<double>(0, orbutil::UNIVERSE_RADIUS / 2)));
	}

	~BodyTest() {}

};

TEST_F(BodyTest, InitializeBody)
{
	EXPECT_EQ(0, bodies[0].getVelocity());
	EXPECT_EQ(orbutil::UNIVERSE_RADIUS, bodies[0].bodyDist(bodies[1]));
}

TEST_F(BodyTest, AngledBodyDist)
{
	EXPECT_EQ(707106781186.54752440084436210485, bodies[0].bodyDist(bodies[2]));
	EXPECT_EQ(707106781186.54752440084436210485, bodies[1].bodyDist(bodies[2]));
}

// TODO: Fix Google Test error where test fails for matching values
TEST_F(BodyTest, ApplyAcceleration)
{
	bodies[0].applyAcceleration(bodies[1]);

	EXPECT_EQ(3.98571e-10, bodies[0].getAcceleration());
}

// TODO: Rewrite PhysicsStep test for new equation
//TEST_F(BodyTest, PhysicsStep)
//{
//	bodies[1].applyAcceleration(bodies[0]);
//	bodies[1].updatePosition(1); // 1 second step
//
//	EXPECT_EQ(132.746, bodies[1].getVelocity()) << "Bad velocity";
//}