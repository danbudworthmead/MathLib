#include "WallCollider2D.h"
#include "Vector2.h"
namespace Maths
{
	WallCollider2D::WallCollider2D()
	{
		start_ = new Vector2();
		end_ = new Vector2();
		normal_ = new Vector2();
	}

	WallCollider2D::WallCollider2D(const Vector2& a_start, const Vector2& a_end, const bool a_isEnabled)
	{
		start_ = new Vector2(a_start);
		end_ = new Vector2(a_end);
		normal_ = new Vector2((a_end - a_start).PerpCCW());
	}

	WallCollider2D::~WallCollider2D()
	{
		delete start_;
		delete end_;
		delete normal_;
	}

	void WallCollider2D::UpdateNormal()
	{
		normal_ = &Vector2(end_ - start_).PerpCCW();
	}

	Vector2 WallCollider2D::GetNormal() const
	{
		return normal_;
	}

	float DistanceToWall(const WallCollider2D& wall, const Vector2& v2)
	{
		return DotProd(v2 - wall.start_, wall.normal_);
	}
}