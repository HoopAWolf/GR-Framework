#include "Collider.h"


Collision::Collision()
	: maxAABB(Vector3( 0, 0, 0))
	, minAABB(Vector3( 0, 0, 0))
{
}


Collision::~Collision()
{
}

// Set the maxAABB and minAABB
void Collision::SetAABB(Vector3 maxAABB, Vector3 minAABB)
{
	this->maxAABB = maxAABB;
	this->minAABB = minAABB;
}
// Set the maxAABB
void Collision::SetMaxAABB(Vector3 maxAABB)
{
	this->maxAABB = maxAABB;
}
// Get the maxAABB
Vector3 Collision::GetMaxAABB(void)
{
	return maxAABB;
}
// Set the minAABB
void Collision::SetMinAABB(Vector3 minAABB)
{
	this->minAABB = minAABB;
}
// Get the minAABB
Vector3 Collision::GetMinAABB(void)
{
	return minAABB;
}
