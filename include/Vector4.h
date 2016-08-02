#ifndef __VECTOR4_H_
#define __VECTOR4_H_
#include "mathLib.h"

namespace Maths
{
	class DLLEXPORT Vector4
	{
	public:
		//\===========================================================================================
		//\	Default Constructor
		//\===========================================================================================
		Vector4();

		//\===========================================================================================
		//\	Construct a vector from a reference to a Vector
		//\===========================================================================================
		Vector4(const Vector4& a_v4);

		//\===========================================================================================
		//\	Construct a vector from a reference to a 2DVector
		//\===========================================================================================
		//	HOW IS IT MISSING A TYPE SPECIFIER??? 
		//	Vector4(const Vector2& a_v2);

		//\===========================================================================================
		//\	Construct a Vector from a pointer to a Vector
		//\===========================================================================================
		Vector4(const Vector4* a_v4);

		//\===========================================================================================
		//\	Construct a Vector from three float values (x, y, z)
		//\===========================================================================================
		Vector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w);

		//\===========================================================================================
		//\	Default Destructor
		//\===========================================================================================
		~Vector4();

		static const Vector4 ZERO;

		//\===========================================================================================
		//\	Addition Operator Overload
		//\===========================================================================================
		Vector4 operator+(const Vector4& a_v4d)const;
		Vector4& operator+=(const Vector4& a_v4d);
		Vector4 operator+(const float& a_f)const;
		Vector4& operator+=(const float& a_f);

		//\===========================================================================================
		//\	Subtraction Operator Overload
		//\===========================================================================================
		Vector4 operator-(const Vector4& a_v4d)const;
		Vector4& operator-=(const Vector4& a_v4d);
		Vector4 operator-(const float& a_f)const;
		Vector4& operator-=(const float& a_f);

		//\===========================================================================================
		//\	Multiplication Operator Overload
		//\===========================================================================================
		Vector4 operator*(const Vector4& a_v4d)const;
		Vector4& operator*=(const Vector4& a_v4d);
		Vector4 operator*(const float& a_f)const;
		Vector4& operator*=(const float& a_f);

		//\===========================================================================================
		//\	Division Operator Overload
		//\===========================================================================================
		Vector4 operator/(const Vector4& a_v4d)const;
		Vector4& operator/=(const Vector4& a_v4d);
		Vector4 operator/(const float& a_f)const;
		Vector4& operator/=(const float& a_f);

		//\===========================================================================================
		//\	Logical Gates Operator Overloads
		//\===========================================================================================
		bool operator==(const Vector4& a_v4d)const;
		bool operator!=(const Vector4& a_v4d)const;

		//\===========================================================================================
		//\	Dot Product
		//\===========================================================================================
		friend float DotProd(const Vector4& lhs, const Vector4& rhs);

		//\===========================================================================================
		//\	Cross Product
		//\===========================================================================================
		friend Vector4 CrossProd(const Vector4& lhs, const Vector4& rhs);
		void CrossProd(const Vector4& a_v4d);

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

		//\===========================================================================================
		//\	Find the angle between two Vectors
		//\===========================================================================================
		friend float Angle(const Vector4& lhs, const Vector4& rhs);

		//\===========================================================================================
		//\	Find angle from self to destination Vector
		//\===========================================================================================
		float Angle(const Vector4& a_v4d) const;

		//\===========================================================================================
		//\	Find distance between two Vectors
		//\===========================================================================================
		friend float Distance(const Vector4& lhs, const Vector4& rhs);

		//\===========================================================================================
		//\	Find distance to destination Vector
		//\===========================================================================================
		float Distance(const Vector4& a_v4d) const;

		//\===========================================================================================
		//\	Find modulus of self
		//\===========================================================================================
		float Modulus() const;

		//\===========================================================================================
		//\	Linear Interpolate
		//\===========================================================================================
		Vector4 Lerp(const Vector4& destination, const float& a_value) const;
		void Lerp(const Vector4& destination, const float& a_value);

		//\===========================================================================================
		//\	Spherical Linear Interpolate
		//\===========================================================================================
		float Slerp(const Vector4& destination, const float& a_value);

		//\===========================================================================================
		//\	X, Y, Z, and W
		//\===========================================================================================
		union
		{
			struct
			{
				float x, y, z, w;
			};
			float xyzw[4];
		};
	};
}
#endif //__VECTOR4_H_
