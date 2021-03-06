#ifndef __VECTOR2_H_
#define __VECTOR2_H_
#include "mathLib.h"

namespace Maths
{
	class DLLEXPORT Vector2
	{
	public:
		static const Vector2 ZERO;
		static const Vector2 UP;
		static const Vector2 DOWN;
		static const Vector2 LEFT;
		static const Vector2 RIGHT;

		//\===========================================================================================
		//\	Default Constructor
		//\===========================================================================================
		Vector2();

		//\===========================================================================================
		//\	Construct a vector from a reference to a Vector
		//\===========================================================================================
		Vector2(const Vector2& a_v2);

		//\===========================================================================================
		//\	Construct a Vector from a pointer to a Vector
		//\===========================================================================================
		Vector2(const Vector2* a_v2);

		//\===========================================================================================
		//\	Construct a Vector from two float values (x, y)
		//\===========================================================================================
		Vector2(const float& a_x, const float& a_y);

		//\===========================================================================================
		//\	Construct a directional Vector from a radian
		//\===========================================================================================
		Vector2(const float& radians);

		//\===========================================================================================
		//\	Default Destructor
		//\===========================================================================================
		~Vector2();

		//\===========================================================================================
		//\	Addition Operator Overload
		//\===========================================================================================
		Vector2 operator+(const Vector2& a_v2d)const;
		Vector2& operator+=(const Vector2& a_v2d);
		Vector2 operator+(const float& a_f)const;
		Vector2& operator+=(const float& a_f);
		friend Vector2 operator+(const float& a_f, const Vector2& a_v2d);
		friend void operator+=(const float& a_f, Vector2 a_v2d);

		//\===========================================================================================
		//\	Subtraction Operator Overload
		//\===========================================================================================
		Vector2 operator-(const Vector2& a_v2d)const;
		Vector2& operator-=(const Vector2& a_v2d);
		Vector2 operator-(const float& a_f)const;
		Vector2& operator-=(const float& a_f);

		//\===========================================================================================
		//\	Opposite Operator Overload
		//\===========================================================================================
		Vector2 operator-()const;

		//\===========================================================================================
		//\	Multiplication Operator Overload
		//\===========================================================================================
		Vector2 operator*(const Vector2& a_v2d)const;
		Vector2& operator*=(const Vector2& a_v2d);
		Vector2 operator*(const float& a_f)const;
		Vector2& operator*=(const float& a_f);
		friend Vector2 operator*(const float& a_f, const Vector2& a_v2d);
		friend void operator*=(const float& a_f, Vector2 a_v2d);

		//\===========================================================================================
		//\	Division Operator Overload
		//\===========================================================================================
		Vector2 operator/(const Vector2& a_v2d)const;
		Vector2& operator/=(const Vector2& a_v2d);
		Vector2 operator/(const float& a_f)const;
		Vector2& operator/=(const float& a_f);

		//\===========================================================================================
		//\	Logical Gates Operator Overloads
		//\===========================================================================================
		bool operator==(const Vector2& a_v2d)const;
		bool operator!=(const Vector2& a_v2d)const;

		//\===========================================================================================
		//\	Dot Product
		//\===========================================================================================
		friend float DotProd(const Vector2& lhs, const Vector2& rhs);

		//\===========================================================================================
		//\	Magnitude
		//\===========================================================================================
		friend float Magnitude(const Vector2& v2d);
		float Magnitude() const;

		//\===========================================================================================
		//\	Bearing
		//\===========================================================================================
		friend float Bearing(const Vector2& v2d);
		float Bearing() const;

		//\===========================================================================================
		//\	Scale
		//\===========================================================================================
		void Scale(const float& a_fScale);

		//\===========================================================================================
		//\	Normalisation
		//\===========================================================================================
		void Normalise();
		Vector2 GetNormalised() const;

		//\===========================================================================================
		//\	Find the angle between two Vectors
		//\===========================================================================================
		friend float Angle(const Vector2& lhs, const Vector2& rhs);

		//\===========================================================================================
		//\	Find angle from self to destination Vector
		//\===========================================================================================
		float Angle(const Vector2& a_v2d) const;

		//\===========================================================================================
		//\	Find distance between two Vectors
		//\===========================================================================================
		friend float Distance(const Vector2& lhs, const Vector2& rhs);

		//\===========================================================================================
		//\	Find distance to destination Vector
		//\===========================================================================================
		float Distance(const Vector2& a_v2d) const;

		//\===========================================================================================
		//\	Find modulus of self
		//\===========================================================================================
		float Modulus() const;

		//\===========================================================================================
		//\	Rotate self by a float
		//\===========================================================================================
		Vector2 Rotate(const float& a_fRot);

		//\===========================================================================================
		//\	Linear Interpolate
		//\===========================================================================================
		Vector2 Lerp(const Vector2& destination, const float& a_value)const;
		void Lerp(const Vector2& destination, const float& a_value);

		//\===========================================================================================
		//\	Spherical Linear Interpolate
		//\===========================================================================================
		float Slerp(const Vector2& destination, const float& a_value);

		//\===========================================================================================
		//\	Returns the perpedicular clock-wise Vector
		//\===========================================================================================
		Vector2 PerpCW() const;

		//\===========================================================================================
		//\	Returns the perpedicular counter-clock-wise Vector
		//\===========================================================================================
		Vector2 PerpCCW() const;

		//\===============================================================================================================================
		//\	Overload OStream << 
		//\===============================================================================================================================
		//friend std::ostream& operator<<(std::ostream& stream, Vector2& v2);

		//\===============================================================================================================================
		//\	Circle collision
		//\===============================================================================================================================
		friend bool CircleCollision(const Vector2& v2lhs, const float& radiuslhs, const Vector2& v2rhs, const float& radiusrhs);

		//\===============================================================================================================================
		//\	Distance to a wall with a counter clockwise rotated normal
		//\===============================================================================================================================
		float DistToWallCCWNormal(const Vector2& start, const Vector2& end) const;

		//\===============================================================================================================================
		//\	Returns a vector2 which doesn't cross the wall
		//\===============================================================================================================================
		Vector2 WallCollisionCCWNormal(const Vector2& start, const Vector2& end, const Vector2& dir, const float& bounce = 0.0f) const;

		//\===========================================================================================
		//\	X and Y
		//\===========================================================================================	
		union
		{
			struct
			{
				float x, y;
			};
			float xy[2];
		};
	};
}
#endif //__VECTOR2_H_