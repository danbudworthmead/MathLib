#ifndef __VECTOR3_H_
#define __VECTOR3_H_
#include "mathLib.h"
namespace Maths
{
	class Vector2;
	class DLLEXPORT Vector3
	{
	public:
		//\===========================================================================================
		//\	Default Constructor
		//\===========================================================================================
		Vector3();

		//\===========================================================================================
		//\	Construct a vector from a reference to a Vector
		//\===========================================================================================
		Vector3(const Vector3& a_v3);
		Vector3(const Vector2& a_v2);

		//\===========================================================================================
		//\	Construct a vector from a reference to a 2DVector
		//\===========================================================================================
		//	HOW IS IT MISSING A TYPE SPECIFIER??? 
		//	Vector3(const Vector2& a_v2);

		//\===========================================================================================
		//\	Construct a Vector from a pointer to a Vector
		//\===========================================================================================
		Vector3(const Vector3* a_v3);

		//\===========================================================================================
		//\	Construct a Vector from three float values (x, y, z)
		//\===========================================================================================
		Vector3(const float& a_x, const float& a_y, const float& a_z);

		//\===========================================================================================
		//\	Default Destructor
		//\===========================================================================================
		~Vector3();

		static Vector3 ZERO;

		//\===========================================================================================
		//\	Addition Operator Overload
		//\===========================================================================================
		Vector3 operator+(const Vector3& a_v3d)const;
		Vector3& operator+=(const Vector3& a_v3d);
		Vector3 operator+(const float& a_f)const;
		Vector3& operator+=(const float& a_f);
		friend Vector3 operator+(const float& a_f, const Vector3& a_v3d);
		friend void operator+=(const float& a_f, Vector3 a_v3d);

		//\===========================================================================================
		//\	Subtraction Operator Overload
		//\===========================================================================================
		Vector3 operator-(const Vector3& a_v3d)const;
		Vector3& operator-=(const Vector3& a_v3d);
		Vector3 operator-(const float& a_f)const;
		Vector3& operator-=(const float& a_f);
		friend const Vector3 operator-(const Vector3& a_v3d);

		//\===========================================================================================
		//\	Multiplication Operator Overload
		//\===========================================================================================
		Vector3 operator*(const Vector3& a_v3d)const;
		Vector3& operator*=(const Vector3& a_v3d);
		Vector3 operator*(const float& a_f)const;
		Vector3& operator*=(const float& a_f);
		friend Vector3 operator*(const float& a_f, const Vector3& a_v3d);
		friend void operator*=(const float& a_f, Vector3 a_v3d);

		//\===========================================================================================
		//\	Division Operator Overload
		//\===========================================================================================
		Vector3 operator/(const Vector3& a_v3d)const;
		Vector3& operator/=(const Vector3& a_v3d);
		Vector3 operator/(const float& a_f)const;
		Vector3& operator/=(const float& a_f);

		//\===========================================================================================
		//\	Logical Gates Operator Overloads
		//\===========================================================================================
		bool operator==(const Vector3& a_v3d)const;
		bool operator!=(const Vector3& a_v3d)const;

		//\===========================================================================================
		//\	Dot Product
		//\===========================================================================================
		friend float DotProd(const Vector3& lhs, const Vector3& rhs);

		//\===========================================================================================
		//\	Cross Product
		//\===========================================================================================
		friend Vector3 CrossProd(const Vector3& lhs, const Vector3& rhs);
		void CrossProd(const Vector3& a_v3d);

		//\===========================================================================================
		//\	Magnitude
		//\===========================================================================================
		float Magnitude() const;

		//\===========================================================================================
		//\	Scale
		//\===========================================================================================
		void Scale(const float& a_fScale);

		//\===========================================================================================
		//\	Normalisation
		//\===========================================================================================
		void Normalise();
		Vector3 GetNormalised()const;

		//\===========================================================================================
		//\	Find the angle between two Vectors
		//\===========================================================================================
		friend float Angle(const Vector3& lhs, const Vector3& rhs);

		//\===========================================================================================
		//\	Find angle from self to destination Vector
		//\===========================================================================================
		float Angle(const Vector3& a_v3d) const;

		//\===========================================================================================
		//\	Find distance between two Vectors
		//\===========================================================================================
		friend float Distance(const Vector3& lhs, const Vector3& rhs);

		//\===========================================================================================
		//\	Find distance to destination Vector
		//\===========================================================================================
		float Distance(const Vector3& a_v3d) const;

		//\===========================================================================================
		//\	Find modulus of self
		//\===========================================================================================
		float Modulus() const;

		//\===========================================================================================
		//\	Linear Interpolate
		//\===========================================================================================
		Vector3 Lerp(const Vector3& destination, const float& a_value) const;
		void Lerp(const Vector3& destination, const float& a_value);

		//\===========================================================================================
		//\	Spherical Linear Interpolate
		//\===========================================================================================
		float Slerp(const Vector3& destination, const float& a_value);

		//\===========================================================================================
		//\	X, Y, and Z
		//\===========================================================================================
		union
		{
			struct
			{
				float x, y, z;
			};
			float xyz[3];
		};
	};
}
#endif //__VECTOR3_H_
