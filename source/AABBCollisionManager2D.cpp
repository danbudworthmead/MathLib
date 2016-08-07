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

	void AABBCollisionManager2D::UpdatePhysics()
	{
		for (auto pNonStaticCollider : nonStaticColliders_)
		{
			for (auto pCollider : colliders_)
			{
				if (pNonStaticCollider != pCollider)
				{
					if (pNonStaticCollider->AABBvsAABB(*pCollider))
					{
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
							return pNonStaticCollider->SetPos(pNonStaticCollider->GetPos() + pCollider->GetWall(iClosest)->GetNormal() * (distanceToNearestWall + pCollider->GetHalfSize().x));
						if (iClosest == 1 || iClosest == 3)
							return pNonStaticCollider->SetPos(pNonStaticCollider->GetPos() + pCollider->GetWall(iClosest)->GetNormal() * (distanceToNearestWall + pCollider->GetHalfSize().y));

					}
				}
			}
		}
	}

	int AABBCollisionManager2D::Add(AABBCollider2D& a_collider)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = colliders_.begin(); iter != colliders_.end(); ++iter)
		{
			if (*iter == &a_collider)
			{
				return iter - colliders_.begin();
			}
		}
		colliders_.push_back(&a_collider);
		if (!a_collider.IsStatic())
		{
			nonStaticColliders_.push_back(&a_collider);
		}
		return colliders_.size() - 1;
	}

	bool AABBCollisionManager2D::Remove(AABBCollider2D& a_collider)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = colliders_.begin(); iter != colliders_.end(); ++iter)
		{
			if (*iter == &a_collider)
			{
				colliders_.erase(iter);
				if (!a_collider.IsStatic())
				{
					for (std::vector<AABBCollider2D*>::iterator iter2 = nonStaticColliders_.begin(); iter2 != nonStaticColliders_.end(); ++iter2)
					{
						if (*iter2 == &a_collider)
						{
							nonStaticColliders_.erase(iter2);
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
		return colliders_.size();
	}

	int AABBCollisionManager2D::SizeNonStatic() const
	{
		return nonStaticColliders_.size();
	}

	AABBCollider2D* AABBCollisionManager2D::ReturnAtIndexStatic(const int a_index)
	{
		return colliders_[a_index];
	}

	AABBCollider2D* AABBCollisionManager2D::ReturnAtIndexNonStatic(const int a_index)
	{
		return nonStaticColliders_[a_index];
	}

	int AABBCollisionManager2D::FindStatic(const AABBCollider2D& a_AABB)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = colliders_.begin(); iter != colliders_.end(); ++iter)
		{
			if (*iter == &a_AABB)
			{
				return iter - colliders_.begin();
			}
		}
		return -1;
	}

	int AABBCollisionManager2D::FindNonStatic(const AABBCollider2D& a_AABB)
	{
		for (std::vector<AABBCollider2D*>::iterator iter = nonStaticColliders_.begin(); iter != nonStaticColliders_.end(); ++iter)
		{
			if (*iter == &a_AABB)
			{
				return iter - nonStaticColliders_.begin();
			}
		}
		return -1;
	}
}