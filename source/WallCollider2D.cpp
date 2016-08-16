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
		normal_->Normalise();
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
		if (CloseEnough(normal_->x, 0))
			normal_->x = 0;
		if (CloseEnough(normal_->x, 1))
			normal_->x = 1;
		if (CloseEnough(normal_->x, -1))
			normal_->x = -1;
		if (CloseEnough(normal_->y, 0))
			normal_->y = 0;
		if (CloseEnough(normal_->y, 1))
			normal_->y = 1;
		if (CloseEnough(normal_->y, -1))
			normal_->y = -1;
	}

	Vector2 WallCollider2D::GetNormal() const
	{
		return normal_;
	}

	Vector2 WallCollider2D::GetStart() const
	{
		return start_;
	}

	Vector2 WallCollider2D::GetEnd() const
	{
		return end_;
	}

	void WallCollider2D::Set(Vector2 & a_start, Vector2 & a_end)
	{
		start_->x = a_start.x;
		start_->y = a_start.y;
		end_->x = a_end.x;
		end_->y = a_end.y;
		UpdateNormal();
	}

	float DistanceToWall(const WallCollider2D& wall, const Vector2& v2)
	{
		return DotProd(v2 - wall.start_, wall.normal_/*->GetNormalised()*/);
	}
}