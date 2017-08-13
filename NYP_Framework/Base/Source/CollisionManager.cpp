#include "CollisionManager.h"

bool CollisionManager::CheckPointToSphereCollision(Vector3 point, EntityBase * ThatEntity)
{
	if (!ThatEntity->HasCollider()) {
		std::cout << "Entity does not have Collider" << std::endl;
		return false;
	}

	GenericEntity* thatSphere = dynamic_cast<GenericEntity*>(ThatEntity);
	
	if (!thatSphere->HasSphere()) {
		std::cout << "Entity does not have Bounding Sphere" << std::endl;
		return false;
	}

	if (DistanceSquaredBetween(point, thatSphere->GetPosition() < thatSphere->GetRadius() * thatSphere->GetRadius()))
		return true;
	return false;
}

bool CollisionManager::CheckSphereCollision(EntityBase * ThisEntity, EntityBase * ThatEntity)
{
	if (!ThisEntity->HasCollider() || !ThatEntity->HasCollider()) {
		std::cout << "1 or more Entities does not have Collider" << std::endl;
		return false;
	}

	GenericEntity* thisSphere = dynamic_cast<GenericEntity*>(ThisEntity);
	GenericEntity* thatSphere = dynamic_cast<GenericEntity*>(ThatEntity);
	
	if (!thatSphere->HasSphere() || !thisSphere->HasSphere()) {
		std::cout << "1 or more Entities does not have Bounding Sphere" << std::endl;
		return false;
	}

	float totalRadius = thatSphere->GetRadius() + thisSphere->GetRadius();
	if (DistanceSquaredBetween(thatSphere->GetPosition(), thisSphere->GetPosition()) < totalRadius * totalRadius) {
		return true;
	}
	return false;
}

bool CollisionManager::CheckAABBCollision(EntityBase * ThisEntity, EntityBase * ThatEntity)
{
	if (!ThatEntity->HasCollider() || !ThisEntity->HasCollider()) {
		std::cout << "1 or more Entities does not have Collider" << std::endl;
		return false;
	}

	GenericEntity* thisHitbox = dynamic_cast<GenericEntity*>(ThisEntity);
	GenericEntity* thatHitbox = dynamic_cast<GenericEntity*>(ThatEntity);

	if (!thisHitbox->HasAABB() || !thatHitbox->HasAABB()){
		std::cout << "1 or more Entities does not have AABB" << std::endl;
		return false;
	}

	return (thisHitbox->GetMinAABB().x <= thatHitbox->GetMaxAABB().x && thisHitbox->GetMaxAABB().x >= thatHitbox->GetMinAABB().x) &&
		(thisHitbox->GetMinAABB().y <= thatHitbox->GetMaxAABB().y && thisHitbox->GetMaxAABB().y >= thatHitbox->GetMinAABB().y) &&
		(thisHitbox->GetMinAABB().z <= thatHitbox->GetMaxAABB().z && thisHitbox->GetMaxAABB().z >= thatHitbox->GetMinAABB().z);
}

bool CollisionManager::CheckPointToAABBCollision(Vector3 point, EntityBase * ThatEntity)
{
	if (!ThatEntity->HasCollider()) {
		std::cout << "Entity does not have Collider" << std::endl;
		return false;
	}

	GenericEntity* thatHitbox = dynamic_cast<GenericEntity*>(ThatEntity);

	if (!thatHitbox->HasAABB()) {
		std::cout << "Entity does not have AABB" << std::endl;
		return false;
	}

	return (point.x <= thatHitbox->GetMaxAABB().x && point.x >= thatHitbox->GetMinAABB().x) &&
		(point.y <= thatHitbox->GetMaxAABB().y && point.y >= thatHitbox->GetMinAABB().y) &&
		(point.z <= thatHitbox->GetMaxAABB().z && point.z >= thatHitbox->GetMinAABB().z);
}

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}
