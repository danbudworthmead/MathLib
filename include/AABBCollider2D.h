#ifndef __AABB_COLLIDER_2D_H_
#define __AABB_COLLIDER_2D_H_
#pragma warning(disable : 4201)
#include "mathLib.h"
namespace Maths
{
	class WallCollider2D;
	class DLLEXPORT AABBCollider2D
	{
		Vector2 pos_;
		Vector2 size_;
		Vector2 halfSize_;
		union
		{
			struct
			{
				WallCollider2D* left_;
				WallCollider2D* top_;
				WallCollider2D* right_;
				WallCollider2D* bottom_;
			};
			struct
			{
				WallCollider2D* walls_[4];
			};
		};
		bool isStatic_;

		const char* name_;
	public:
		AABBCollider2D(const char* a_name, const bool a_isStatic = true);
		AABBCollider2D(const char* a_name, const Vector2& a_pos, const Vector2& a_size, const bool a_isStatic = true);
		~AABBCollider2D();
		//Left = 0, Top = 1, Right = 2, Bottom = 3
		enum class WallsEnum
		{
			left, top, right, bottom
		};
		WallCollider2D* GetWall(const WallsEnum a_wall);
		WallCollider2D* GetWall(const int a_iWall);
		bool EncapsulatesPosition(const Vector2& a_point)const;
		bool IsStatic()const;
		void IsStatic(const bool a_isStatic);
		bool AABBvsAABB(const AABBCollider2D& a_other) const;

		Vector2 GetHalfSize()const;
		Vector2 GetSize()const;
		void SetSize(const Vector2& a_v2Size);
		void SetPos(Vector2& a_v2Pos);
		Vector2 GetPos()const;

		void UpdateWalls();

		const char* GetName()const;
		void SetName(const char* a_name);

		void GetCorners2D(float a_values[8]);
	};
}
#endif //__AABB_COLLIDER_2D_H_