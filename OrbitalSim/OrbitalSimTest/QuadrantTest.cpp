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
	EXPECT_TRUE(quadrant.contains(5, 0));
	EXPECT_TRUE(quadrant.contains(5, 20));
	EXPECT_TRUE(quadrant.contains(15, 10));
	EXPECT_TRUE(quadrant.contains(-5, 10));
}

TEST_F(QuadrantTest, ContainsPointOutside)
{
	EXPECT_FALSE(quadrant.contains(5, -20));
}

TEST_F(QuadrantTest, GenerateNW)
{
	EXPECT_EQ(10, NW->getLength());
	EXPECT_EQ(0, NW->getposX());
	EXPECT_EQ(15, NW->getposY());
}

TEST_F(QuadrantTest, GenerateNE)
{
	EXPECT_EQ(10, NE->getLength());
	EXPECT_EQ(10, NE->getposX());
	EXPECT_EQ(15, NE->getposY());
}

TEST_F(QuadrantTest, GenerateSW)
{
	EXPECT_EQ(10, SW->getLength());
	EXPECT_EQ(0, SW->getposX());
	EXPECT_EQ(5, SW->getposY());
}

TEST_F(QuadrantTest, GenerateSE)
{
	EXPECT_EQ(10, SE->getLength());
	EXPECT_EQ(10, SE->getposX());
	EXPECT_EQ(5, SW->getposY());
}