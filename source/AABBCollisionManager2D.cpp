#include "AABBCollisionManager2D.h"
#include "AABBCollider2D.h"
#include "Vector2.h"
#include "WallCollider2D.h"
#include <iostream>
namespace Maths
{
	AABBCollisionManager2D *AABBCollisionManager2D::s_instance = 0;

	AABBCollisionManager2D::AABBCollisionManager2D()
	{

	}

	AABBCollisionManager2D::~AABBCollisionManager2D()
	{

	}

	AABBCollisionManager2D* AABBCollisionManager2D::instance()
	{
		if (!s_instance)
			s_instance = new AABBCollisionManager2D();
		return s_instance;
	}

	void AABBCollisionManager2D::UpdatePhysics(const bool DEBUG_MODE)
	{
		for (auto pNonStaticCollider : nonStaticColliders)
		{
			for (auto pCollider : colliders)
			{
				if (pNonStaticCollider != pCollider)
				{
					if (pNonStaticCollider->AABBvsAABB(*pCollider))
					{
						if (DEBUG_MODE)
							std::cout << pNonStaticCollider->GetName() << " has collided with " << pCollider->GetName() << std::endl;

						//a nonstatic has collided with a collider
						float distanceToNearestWall = (float)ULLONG_MAX;
						int iClosest = -1;

						for (unsigned int i = 0; i < 4; i++)
						{
							float distToWall = DistanceToWall(*pCollider->GetWall(i), pNonStaticCollider->GetPos());
							if (distToWall < distanceToNearestWall)
							{
								distanceToNearestWall = distToWall;
								iClosest = i;
							}
						}

						if (iClosest == 0 || iClosest == 2)
							return pNonStaticCollider->SetPos(pNonStaticCollider->GetPos() - pCollider->GetWall(iClosest)->GetNormal() * (distanceToNearestWall + pNonStaticCollider->GetHalfSize().x));
						if (iClosest == 1 || iClosest == 3)
							return pNonStaticCollider->SetPos(pNonStaticCollider->GetPos() - pCollider->GetWall(iClosest)->GetNormal() * (distanceToNearestWall + pNonStaticCollider->GetHalfSize().y));
						
						std::cout << distanceToNearestWall << std::endl;
					}
				}
			}
		}
	}

	int AABBCollisionManager2D::Add(AABBCollider2D& a_collider)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = colliders.begin(); iter != colliders.end(); ++iter)
		{
			if (*iter == &a_collider)
			{
				return iter - colliders.begin();
			}
		}
		colliders.push_back(&a_collider);
		if (!a_collider.IsStatic())
		{
			nonStaticColliders.push_back(&a_collider);
		}
		return colliders.size() - 1;
	}

	bool AABBCollisionManager2D::Remove(AABBCollider2D& a_collider)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = colliders.begin(); iter != colliders.end(); ++iter)
		{
			if (*iter == &a_collider)
			{
				colliders.erase(iter);
				if (!a_collider.IsStatic())
				{
					for (std::vector<AABBCollider2D*>::iterator iter2 = nonStaticColliders.begin(); iter2 != nonStaticColliders.end(); ++iter2)
					{
						if (*iter2 == &a_collider)
						{
							nonStaticColliders.erase(iter2);
							return true;
						}
					}
				}
				return true;
			}
		}
		return false;
	}

	int AABBCollisionManager2D::Size() const
	{
		return colliders.size();
	}

	int AABBCollisionManager2D::SizeNonStatic() const
	{
		return nonStaticColliders.size();
	}

	AABBCollider2D* AABBCollisionManager2D::ReturnAtIndexStatic(const int a_index)
	{
		return colliders[a_index];
	}

	AABBCollider2D* AABBCollisionManager2D::ReturnAtIndexNonStatic(const int a_index)
	{
		return nonStaticColliders[a_index];
	}

	int AABBCollisionManager2D::FindStatic(const AABBCollider2D& a_AABB)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = colliders.begin(); iter != colliders.end(); ++iter)
		{
			if (*iter == &a_AABB)
			{
				return iter - colliders.begin();
			}
		}
		return -1;
	}

	int AABBCollisionManager2D::FindNonStatic(const AABBCollider2D& a_AABB)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = nonStaticColliders.begin(); iter != nonStaticColliders.end(); ++iter)
		{
			if (*iter == &a_AABB)
			{
				return iter - nonStaticColliders.begin();
			}
		}
		return -1;
	}
}