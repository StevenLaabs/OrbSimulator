#ifndef _QUADTREE_H
#define _QUADTREE_H

class Quadrant;
class Body;

class QuadTree
{

public:

	QuadTree(Quadrant* quad);
	~QuadTree();
	
	bool isLeaf(QuadTree* node);

	void insert(Body* body);

private:

	QuadTree* NW;
	QuadTree* NE;
	QuadTree* SW;
	QuadTree* SE;

	Quadrant* quad;
	Body* body;

};

#endif // !_QUADTREE_H
