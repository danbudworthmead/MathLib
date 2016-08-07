#include "AABBCollider2D.h"
#include "WallCollider2D.h"
#include "Vector2.h"

namespace Maths
{
	AABBCollider2D::AABBCollider2D(const char* a_name, const bool a_isStatic)
	{
		left_ = new WallCollider2D();
		top_ = new WallCollider2D();
		right_ = new WallCollider2D();
		bottom_ = new WallCollider2D();
		pos_ = new Vector2();
		size_ = new Vector2();
		halfSize_ = new Vector2();
		isStatic_ = a_isStatic;
		name_ = a_name;
		AABBCollisionManager2D::instance()->Add(*this);
	}

	AABBCollider2D::AABBCollider2D(const char* a_name, const Vector2& a_pos, const Vector2& a_size, const bool a_isStatic)
	{
		//Setting the start and size vectors
		pos_ = new Vector2(a_pos);
		size_ = new Vector2(a_size);

		//Calculating the halfsize of the collider
		halfSize_ = size_ * 0.5f;

		//Calculating the position of the four corners, we can use the x's and y's of points already calculated to save processor cycles ;)
		Vector2 botleft = a_pos - halfSize_;
		Vector2 topleft = Vector2(botleft.x, pos_.y + halfSize_.y);
		Vector2 topright = Vector2(pos_.x + halfSize_.x, topleft.y);
		Vector2 botright = Vector2(topright.x, botleft.y);

		//Calculating the four walls
		left_ = new WallCollider2D(botleft, topleft);
		top_ = new WallCollider2D(topleft, topright);
		right_ = new WallCollider2D(topright, botright);
		bottom_ = new WallCollider2D(botright, botleft);

		//Set the isStatic value
		isStatic_ = a_isStatic;

		//Set the name
		name_ = a_name;
		AABBCollisionManager2D::instance()->Add(*this);
	}

	AABBCollider2D::~AABBCollider2D()
	{
		AABBCollisionManager2D::instance()->Remove(*this);
		//Hoping this will delete all the four walls because I'm using struct unions
		delete left_;
		delete top_;
		delete right_;
		delete bottom_;
	}

	WallCollider2D* AABBCollider2D::GetWall(const WallsEnum a_wall)
	{
		return walls_[(int)a_wall];
	}

	WallCollider2D* AABBCollider2D::GetWall(const int a_iWall)
	{
		return walls_[a_iWall];
	}

	bool AABBCollider2D::EncapsulatesPosition(const Vector2& a_point)const
	{
		if (a_point.x < pos_.x - halfSize_.x)
			return false;
		if (a_point.x > pos_.x + halfSize_.x)
			return false;
		if (a_point.y < pos_.y - halfSize_.y)
			return false;
		if (a_point.y > pos_.y + halfSize_.y)
			return false;
		return true;
	}

	bool AABBCollider2D::IsStatic() const
	{
		return isStatic_;
	}

	void AABBCollider2D::IsStatic(const bool a_isStatic)
	{
		isStatic_ = a_isStatic;
	}

	bool AABBCollider2D::AABBvsAABB(const AABBCollider2D& a_other) const
	{
		if (a_other.pos_.x - a_other.halfSize_.x > pos_.x + halfSize_.x)
			return false;
		if (a_other.pos_.x + a_other.halfSize_.x < pos_.x - halfSize_.x)
			return false;
		if (a_other.pos_.y - a_other.halfSize_.y > pos_.y + halfSize_.y)
			return false;
		if (a_other.pos_.y + a_other.halfSize_.y < pos_.y - halfSize_.y)
			return false;
		return true;
	}

	Vector2 AABBCollider2D::GetHalfSize() const
	{
		return halfSize_;
	}

	Vector2 AABBCollider2D::GetSize() const
	{
		return size_;
	}

	void AABBCollider2D::SetSize(const Vector2 & a_v2Size)
	{
		size_ = a_v2Size;
	}

	void AABBCollider2D::SetPos(Vector2& a_v2Pos)
	{
		pos_ = &a_v2Pos;
	}

	Vector2 AABBCollider2D::GetPos() const
	{
		return pos_;
	}
	const char * AABBCollider2D::GetName() const
	{
		return name_;
	}
	void AABBCollider2D::SetName(const char* a_name)
	{
		name_ = a_name;
	}
}