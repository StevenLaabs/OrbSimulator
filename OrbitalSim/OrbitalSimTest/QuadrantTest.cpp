#include <gtest\gtest.h>
#include "..\Quadrant.h"

//-------------------------------------------------
// QuadrantTest runs tests for methods within the
// Quadrant class
//-------------------------------------------------
struct QuadrantTest : testing::Test
{

	Quadrant quadrant;
	Quadrant *NW, *NE, *SW, *SE;

	QuadrantTest() : quadrant(5, 10, 20)
	{
		NW = quadrant.makeNW();
		NE = quadrant.makeNE();
		SW = quadrant.makeSW();
		SE = quadrant.makeSE();
	}

	~QuadrantTest()
	{
		delete NW;
		delete NE;
		delete SW;
		delete SE;
	}

};

TEST_F(QuadrantTest, InitializeQuadrant)
{
	EXPECT_EQ(5, quadrant.getposX());
	EXPECT_EQ(10, quadrant.getposY());
	EXPECT_EQ(20, quadrant.getLength());
}

TEST_F(QuadrantTest, ContainsPointCenter)
{
	EXPECT_TRUE(quadrant.contains(5, 10));
}

TEST_F(QuadrantTest, ContainsPointBounds)
{
	// TODO: Rewrite test, should be radius of 10 not 20 (as 20 is the full length)
	EXPECT_TRUE(quadrant.contains(5, -10));
	EXPECT_TRUE(quadrant.contains(5, 30));
	EXPECT_TRUE(quadrant.contains(25, 20));
	EXPECT_TRUE(quadrant.contains(-15, 20));
}

TEST_F(QuadrantTest, ContainsPointOutside)
{
	EXPECT_FALSE(quadrant.contains(5, -20));
}

TEST_F(QuadrantTest, GenerateNW)
{
	EXPECT_EQ();
	EXPECT_EQ();
}

TEST_F(QuadrantTest, GenerateNE)
{

}

TEST_F(QuadrantTest, GenerateSW)
{

}

TEST_F(QuadrantTest, GenerateSE)
{

}