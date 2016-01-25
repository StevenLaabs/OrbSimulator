#include "QuadTree.h"
#include "Body.h"

QuadTree::QuadTree(Quadrant* quad) : quad(quad), NW(nullptr), NE(nullptr), SW(nullptr), SE(nullptr), body(nullptr)
{

}

QuadTree::~QuadTree()
{
//	delete body;
//	delete quad;
	delete NW;
	delete NE;
	delete SW;
	delete SE;
}

bool QuadTree::isLeaf(QuadTree* node)
{
	return (node->NW == nullptr && node->NE == nullptr && node->SW == nullptr && node->SE == nullptr);
}

void QuadTree::insert(Body* body)
{
	/*if (this->body == nullptr)
		this->body = body;

	else if (isLeaf(this) == false)
	{
		this->body = 
	}*/
}