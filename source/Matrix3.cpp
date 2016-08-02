#include "Matrix3.h"
namespace Maths
{
	Matrix3::Matrix3()
	{
		for (float f : values_)
			f = 0;
	}

	Matrix3::Matrix3(const float a_values[9])
	{
		for (int i = 0; i < 9; i++)
			values_[i] = a_values[i];
	}

	Matrix3::Matrix3(
		const float& a_11, const float& a_12, const float& a_13,
		const float& a_21, const float& a_22, const float& a_23,
		const float& a_31, const float& a_32, const float& a_33)
	{
		values_[0] = a_11;
		values_[1] = a_12;
		values_[2] = a_13;
		values_[3] = a_21;
		values_[4] = a_22;
		values_[5] = a_23;
		values_[6] = a_31;
		values_[7] = a_32;
		values_[8] = a_33;
	}

	//\===============================================================================================================================
	//\	Create Rotation Matrix from a bearing
	//\===============================================================================================================================
	Matrix3::Matrix3(const float& a_bearingInRadiansZ)
	{
		//Translation
		values_[0] = 0;
		values_[1] = 0;
		values_[2] = 0;

		//Rotation
		values_[3] = cos(a_bearingInRadiansZ); //x
		values_[4] = sin(a_bearingInRadiansZ); //y
		values_[5] = 0; //z

		//Scale
		values_[6] = 1;
		values_[7] = 1;
		values_[8] = 1;
	}

	//\===============================================================================================================================
	//\	Create Rotation Matrix from a bearing
	//\===============================================================================================================================
	Matrix3::Matrix3(const Vector3& a_v3d)
	{
		//Translation
		values_[0] = a_v3d.x;
		values_[1] = a_v3d.y;
		values_[2] = a_v3d.z;

		//Rotation
		values_[3] = 0;
		values_[4] = 0;
		values_[5] = 0;

		//Scale
		values_[6] = 1;
		values_[7] = 1;
		values_[8] = 1;
	}

	//\===============================================================================================================================
	//\	Create Translation Matrix from a Vector2
	//\===============================================================================================================================
	Matrix3::Matrix3(const Vector2& a_v2d) : Matrix3(Vector3(a_v2d.x, a_v2d.y, 0.f)) {}

	Matrix3::~Matrix3() {}

	Matrix3 Matrix3::IDENTITY = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	Matrix3 Matrix3::ZERO = Matrix3(0, 0, 0, 0, 0, 0, 0, 0, 0);

	//\===============================================================================================================================
	//\
	//\	OPERATOR OVERLOADS
	//\
	//\===============================================================================================================================

	//\===============================================================================================================================
	//\	Addition Operator Overload
	//\===============================================================================================================================
	Matrix3 Matrix3::operator+(Matrix3& a_m3) const
	{
		return Matrix3(
			values_[0] + a_m3.values_[0], values_[1] + a_m3.values_[1], values_[2] + a_m3.values_[2],
			values_[3] + a_m3.values_[3], values_[4] + a_m3.values_[4], values_[5] + a_m3.values_[5],
			values_[6] + a_m3.values_[6], values_[7] + a_m3.values_[7], values_[8] + a_m3.values_[8]);
	}
	Matrix3& Matrix3::operator+=(Matrix3& a_m3)
	{
		*this = *this + a_m3;
		return *this;
	}

	//\===============================================================================================================================
	//\	Multiplication Operator Overload
	//\===============================================================================================================================
	Matrix3 Matrix3::operator*(Matrix3& a_m3) const
	{
		//Optimised
		return Matrix3(
			values_[0] * a_m3.values_[0] + values_[1] * a_m3.values_[3],
			values_[0] * a_m3.values_[1] + values_[1] * a_m3.values_[4],
			0,
			values_[3] * a_m3.values_[0] + values_[4] * a_m3.values_[3],
			values_[3] * a_m3.values_[1] + values_[4] * a_m3.values_[4],
			0,
			values_[6] * a_m3.values_[0] + values_[7] * a_m3.values_[3] + a_m3.values_[6],
			values_[6] * a_m3.values_[1] + values_[7] * a_m3.values_[4] + a_m3.values_[7],
			1
			);

		//return Matrix3(
		//	values_[0] * a_m3.values_[0] + values_[1] * a_m3.values_[3] + values_[2] * a_m3.values_[6],
		//	values_[0] * a_m3.values_[1] + values_[1] * a_m3.values_[4] + values_[2] * a_m3.values_[7],
		//	values_[0] * a_m3.values_[2] + values_[1] * a_m3.values_[5] + values_[2] * a_m3.values_[8],
		//	values_[3] * a_m3.values_[0] + values_[4] * a_m3.values_[3] + values_[5] * a_m3.values_[6],
		//	values_[3] * a_m3.values_[1] + values_[4] * a_m3.values_[4] + values_[5] * a_m3.values_[7],
		//	values_[3] * a_m3.values_[2] + values_[4] * a_m3.values_[5] + values_[5] * a_m3.values_[8],
		//	values_[6] * a_m3.values_[0] + values_[7] * a_m3.values_[3] + values_[8] * a_m3.values_[6],
		//	values_[6] * a_m3.values_[1] + values_[7] * a_m3.values_[4] + values_[8] * a_m3.values_[7],
		//	values_[6] * a_m3.values_[2] + values_[7] * a_m3.values_[5] + values_[8] * a_m3.values_[8]
		//	);
	}
	Matrix3& Matrix3::operator*=(Matrix3& a_m3)
	{
		*this = *this * a_m3;
		return *this;
	}

	Vector3 Matrix3::operator*(Vector3& a_v3) const
	{
		return Vector3(
			values_[0] * a_v3.x + values_[1] * a_v3.y + values_[2] * a_v3.z,
			values_[3] * a_v3.x + values_[4] * a_v3.y + values_[5] * a_v3.z,
			values_[6] * a_v3.x + values_[7] * a_v3.y + values_[8] * a_v3.z
			);
	}
	Vector3 Matrix3::operator*=(Vector3& a_v3)
	{
		return *this * a_v3;
	}

	//\===============================================================================================================================
	//\	Overload OStream << 
	//\===============================================================================================================================
	std::ostream& operator<<(std::ostream& stream, Matrix3& a_matrix)
	{
		stream << a_matrix(1, 1) << "\t" << a_matrix(1, 2) << "\t" << a_matrix(1, 3) << "\n";
		stream << a_matrix(2, 1) << "\t" << a_matrix(2, 2) << "\t" << a_matrix(2, 3) << "\n";
		stream << a_matrix(3, 1) << "\t" << a_matrix(3, 2) << "\t" << a_matrix(3, 3);
		return stream;
	}

	//\===============================================================================================================================
	//\	Access Individual Elements in the Matrix
	//\===============================================================================================================================
	float& Matrix3::operator()(const unsigned& row, const unsigned& col)
	{
		if (row > 3 || col > 3)
			return values_[-1];
		return values_[((row - 1) * 3) + col - 1];
	}

	//\===============================================================================================================================
	//\
	//\	GETTERS
	//\
	//\===============================================================================================================================

	//\===============================================================================================================================
	//\	Returns the translation as a 2D Vector 
	//\===============================================================================================================================
	Vector2 Matrix3::GetTranslation2D() const
	{
		return Vector2(values_[0], values_[1]);
	}

	//\===============================================================================================================================
	//\	Returns the translation as a 3D Vector 
	//\===============================================================================================================================
	Vector3 Matrix3::GetTranslation3D() const
	{
		return Vector3(values_[0], values_[1], values_[2]);
	}

	//\===============================================================================================================================
	//\	Returns the rotation as a 2D Vector 
	//\===============================================================================================================================
	Vector2 Matrix3::GetRotation2D() const
	{
		return Vector2(values_[3], values_[4]);
	}

	//\===============================================================================================================================
	//\	Returns the rotation as a 3D Vector 
	//\===============================================================================================================================
	Vector3 Matrix3::GetRotation3D() const
	{
		return Vector3(values_[3], values_[4], values_[5]);
	}

	//\===============================================================================================================================
	//\	Returns the rotation about the Z axis as a float
	//\===============================================================================================================================
	float Matrix3::GetBearingInRadiansZ() const
	{
		return GetRotation2D().Bearing();
	}

	//\===============================================================================================================================
	//\	Returns the scale as a 2D Vector 
	//\===============================================================================================================================
	Vector2 Matrix3::GetScale2D() const
	{
		return Vector2(values_[6], values_[7]);
	}

	//\===============================================================================================================================
	//\	Returns the scale as a 3D Vector 
	//\===============================================================================================================================
	Vector3 Matrix3::GetScale3D() const
	{
		return Vector3(values_[6], values_[7], values_[8]);
	}

	//\===========================================================================================
	//\ Inverse - Get the inverse of the matrix
	//\===========================================================================================
	float Matrix3::Determinant() const
	{
		return (float)(
			(1, 1) * ((2, 2) * (3, 3) - (2, 3) * (3, 2) +
				(1, 2) * ((2, 3) * (3, 1) - (2, 1) * (3, 3)) +
				(1, 3) * ((2, 1) * (3, 2) - (2, 2) * (3, 1))));
	}
	//Ask Jamie about Recipf(fDeterminant);
	bool Matrix3::Inverse()
	{
		float fDeterminant = Determinant();
		if (fDeterminant != 0.0f)
		{
			//const float fInvDet = Recipf(fDeterminant);
			const float fInvDet = 0;
			Matrix3 mat = *this;
			this->operator()(1, 1) = (mat(2, 2) * mat(3, 3) - mat(2, 3) * mat(3, 2)) * fInvDet;
			this->operator()(1, 2) = (mat(1, 3) * mat(3, 2) - mat(1, 2) * mat(3, 3)) * fInvDet;
			this->operator()(1, 3) = (mat(1, 2) * mat(2, 3) - mat(1, 3) * mat(2, 2)) * fInvDet;

			this->operator()(2, 1) = (mat(2, 3) * mat(3, 1) - mat(2, 1) * mat(3, 3)) * fInvDet;
			this->operator()(2, 2) = (mat(1, 1) * mat(3, 3) - mat(1, 3) * mat(3, 1)) * fInvDet;
			this->operator()(2, 3) = (mat(1, 3) * mat(2, 1) - mat(1, 1) * mat(2, 3)) * fInvDet;

			this->operator()(3, 1) = (mat(2, 1) * mat(3, 2) - mat(2, 2) * mat(3, 1)) * fInvDet;
			this->operator()(3, 2) = (mat(1, 2) * mat(3, 1) - mat(1, 1) * mat(3, 2)) * fInvDet;
			this->operator()(3, 3) = (mat(1, 1) * mat(2, 2) - mat(1, 2) * mat(2, 1)) * fInvDet;

			return true;
		}
		return false;
	}

	//\===============================================================================================================================
	//\
	//\	SETTERS
	//\
	//\===============================================================================================================================

	//\===============================================================================================================================
	//\	Set the translation with a 3D Vector
	//\===============================================================================================================================
	void Matrix3::SetTranslation(const Vector3& a_v3d)
	{
		//Translation
		values_[0] = a_v3d.x;
		values_[1] = a_v3d.y;
		values_[2] = a_v3d.z;
	}

	//\===============================================================================================================================
	//\	Set the translation with a 2D Vector
	//\===============================================================================================================================
	void Matrix3::SetTranslation(const Vector2& a_v2d)
	{
		//Translation
		values_[0] = a_v2d.x;
		values_[1] = a_v2d.y;
	}

	//\===============================================================================================================================
	//\	Set the rotation with a 2D Vector
	//\===============================================================================================================================
	void Matrix3::SetRotation(const Vector2& a_v2d)
	{
		values_[3] = a_v2d.x;
		values_[4] = a_v2d.y;
	}

	//\===============================================================================================================================
	//\	Set the rotation with a 3D Vector
	//\===============================================================================================================================
	void Matrix3::SetRotation(const Vector3& a_v3d)
	{
		values_[3] = a_v3d.x;
		values_[4] = a_v3d.y;
		values_[5] = a_v3d.z;
	}

	//\===============================================================================================================================
	//\	Set the rotation with a bearing in radians
	//\===============================================================================================================================
	void Matrix3::SetRotation(const float& a_bearingInRadiansZ)
	{
		//Rotation
		values_[3] = cos(a_bearingInRadiansZ); //x
		values_[4] = sin(a_bearingInRadiansZ); //y
		values_[5] = 0; //z
	}

	//\===============================================================================================================================
	//\
	//\	VOID METHODS
	//\
	//\===============================================================================================================================

	//\===============================================================================================================================
	//\	Rotate the matrix by a radian about the Z-axis
	//\===============================================================================================================================
	void Matrix3::RotateZ(const float& a_fAngle)
	{
		*this = CreateRotationMatrix3AboutZ(a_fAngle) * *this;
	}

	Matrix3 CreateRotationMatrix3AboutZ(const float fAngleRadians)
	{
		float c = cos(fAngleRadians);
		float s = sin(fAngleRadians);

		if (closeEnough(c, 0.f))
			c = 0.f;
		if (closeEnough(c, 1.f))
			c = 1.f;
		if (closeEnough(c, -1.f))
			c = -1.f;
		if (closeEnough(s, 0.f))
			s = 0.f;
		if (closeEnough(s, 1.f))
			s = 1.f;
		if (closeEnough(s, -1.f))
			s = -1.f;

		Matrix3 m3;

		m3.values2D_[0][0] = c;		m3.values2D_[0][1] = -s;	m3.values2D_[0][2] = 0;
		m3.values2D_[1][0] = s;		m3.values2D_[1][1] = c;		m3.values2D_[1][2] = 0;
		m3.values2D_[2][0] = 0;		m3.values2D_[2][1] = 0;		m3.values2D_[2][2] = 1;

		return m3;
	}

	Matrix3 CreateTranslationMatrix3(const Vector2& a_v2)
	{
		return Matrix3(
			1, 0, a_v2.x,
			0, 1, a_v2.y,
			0, 0, 1
			);
	}

	//\===============================================================================================================================
	//\	Scale the Matrix by a float
	//\===============================================================================================================================
	void Matrix3::Scale(const float& a_scale)
	{
		values_[6] *= a_scale;
		values_[7] *= a_scale;
		values_[8] *= a_scale;
	}
}