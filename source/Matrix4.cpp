#include "Matrix4.h"
//\============================================================================
///	Constructors
//\============================================================================
//Default Constructor
namespace Maths {
	Matrix4::Matrix4() { *this = IDENTITY; }
	//Copy Constructor
	Matrix4::Matrix4(const Matrix4& other)
	{
		for (int i = 0; i < 16; i++)
		{
			values_[i] = other.values_[i];
		}
	}
	//Construct with values
	Matrix4::Matrix4(
		const float& a_xx, const float& a_xy, const float& a_xz,
		const float& a_yx, const float& a_yy, const float& a_yz,
		const float& a_zx, const float& a_zy, const float& a_zz,
		const float& a_tx, const float& a_ty, const float& a_tz)
	{
		values_[0] = a_xx;
		values_[1] = a_xy;
		values_[2] = a_xz;
		values_[3] = 0;
		values_[4] = a_yx;
		values_[5] = a_yy;
		values_[6] = a_yz;
		values_[7] = 0;
		values_[8] = a_zx;
		values_[9] = a_zy;
		values_[10] = a_zz;
		values_[11] = 0;
		values_[12] = a_tx;
		values_[13] = a_ty;
		values_[14] = a_tz;
		values_[15] = 1;
	}
	//Construct with all 16 values
	Matrix4::Matrix4(
		const float& a_xx, const float& a_xy, const float& a_xz, const float& a_xw,
		const float& a_yx, const float& a_yy, const float& a_yz, const float& a_yw,
		const float& a_zx, const float& a_zy, const float& a_zz, const float& a_zw,
		const float& a_tx, const float& a_ty, const float& a_tz, const float& a_tw)
	{
		values_[0] = a_xx;
		values_[1] = a_xy;
		values_[2] = a_xz;
		values_[3] = a_xw;
		values_[4] = a_yx;
		values_[5] = a_yy;
		values_[6] = a_yz;
		values_[7] = a_yw;
		values_[8] = a_zx;
		values_[9] = a_zy;
		values_[10] = a_zz;
		values_[11] = a_zw;
		values_[12] = a_tx;
		values_[13] = a_ty;
		values_[14] = a_tz;
		values_[15] = a_tw;
	}
	Matrix4::Matrix4(const Vector3& a_vecForward, const Vector3& a_vecUp, const Vector3& a_vecRight, const Vector3& a_vecPos)
	{
		values_[0] = a_vecRight.x;
		values_[1] = a_vecRight.y;
		values_[2] = a_vecRight.z;
		values_[3] = 0;
		values_[4] = a_vecUp.x;
		values_[5] = a_vecUp.y;
		values_[6] = a_vecUp.z;
		values_[7] = 0;
		values_[8] = a_vecRight.x;
		values_[9] = a_vecRight.y;
		values_[10] = a_vecRight.z;
		values_[11] = 0;
		values_[12] = a_vecPos.x;
		values_[13] = a_vecPos.y;
		values_[14] = a_vecPos.z;
		values_[15] = 1;
	}
	Matrix4::Matrix4(const float a_values[16])
	{
		for (int i = 0; i < sizeof(values_) / sizeof(values_[0]); i++)
		{
			values_[i] = a_values[i];
		}
	}
	//Default Destructor
	Matrix4::~Matrix4() {}

	//\============================================================================
	///	Constants
	//\============================================================================
	//Identity Matrix4
	Matrix4 Matrix4::IDENTITY = Matrix4(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f);

	//\============================================================================
	///	Operator Overloads
	//\============================================================================
	//Access Individual Elements in the Matrix
	float Matrix4::operator()(unsigned row, unsigned col) const
	{
		if (row > 4 || col > 4 || row < 1 || col < 1)
		{
			return values_[-1];
		}
		return values_[4 * (row - 1) + col - 1];
	}
	float& Matrix4::operator()(unsigned row, unsigned col)
	{
		if (row > 4 || col > 4 || row < 1 || col < 1)
		{
			return values_[-1];
		}
		return values_[4 * (row - 1) + col - 1];
	}
	//Multiply Matrix4 by a Matrix4
	Matrix4 Matrix4::operator*(Matrix4& a_m4)
	{
		return Matrix4(
			m_11 * a_m4.m_11 + m_12 * a_m4.m_21 + m_13 * a_m4.m_31 + m_14 * a_m4.m_41,
			m_11 * a_m4.m_12 + m_12 * a_m4.m_22 + m_13 * a_m4.m_32 + m_14 * a_m4.m_42,
			m_11 * a_m4.m_13 + m_12 * a_m4.m_23 + m_13 * a_m4.m_33 + m_14 * a_m4.m_43,
			m_11 * a_m4.m_14 + m_12 * a_m4.m_24 + m_13 * a_m4.m_34 + m_14 * a_m4.m_44,

			m_21 * a_m4.m_11 + m_22 * a_m4.m_21 + m_23 * a_m4.m_31 + m_24 * a_m4.m_41,
			m_21 * a_m4.m_12 + m_22 * a_m4.m_22 + m_23 * a_m4.m_32 + m_24 * a_m4.m_42,
			m_21 * a_m4.m_13 + m_22 * a_m4.m_23 + m_23 * a_m4.m_33 + m_24 * a_m4.m_43,
			m_21 * a_m4.m_14 + m_22 * a_m4.m_24 + m_23 * a_m4.m_34 + m_24 * a_m4.m_44,

			m_31 * a_m4.m_11 + m_32 * a_m4.m_21 + m_33 * a_m4.m_31 + m_34 * a_m4.m_41,
			m_31 * a_m4.m_12 + m_32 * a_m4.m_22 + m_33 * a_m4.m_32 + m_34 * a_m4.m_42,
			m_31 * a_m4.m_13 + m_32 * a_m4.m_23 + m_33 * a_m4.m_33 + m_34 * a_m4.m_43,
			m_31 * a_m4.m_14 + m_32 * a_m4.m_24 + m_33 * a_m4.m_34 + m_34 * a_m4.m_44,

			m_41 * a_m4.m_11 + m_42 * a_m4.m_21 + m_43 * a_m4.m_31 + m_44 * a_m4.m_41,
			m_41 * a_m4.m_12 + m_42 * a_m4.m_22 + m_43 * a_m4.m_32 + m_44 * a_m4.m_42,
			m_41 * a_m4.m_13 + m_42 * a_m4.m_23 + m_43 * a_m4.m_33 + m_44 * a_m4.m_43,
			m_41 * a_m4.m_14 + m_42 * a_m4.m_24 + m_43 * a_m4.m_34 + m_44 * a_m4.m_44
			);
	}
	void Matrix4::operator*=(Matrix4& other)
	{
		*this = *this * other;
	}
	//\===========================================================================================
	//\ Component Access
	//\===========================================================================================
	//Vector4 Matrix4::x()
	//{
	//	return Vector4(values_[0], values_[1], values_[2], values_[3]);
	//}
	//Vector4 Matrix4::y()
	//{
	//	return Vector4(values_[4], values_[5], values_[6], values_[7]);
	//}
	//Vector4 Matrix4::z()
	//{
	//	return Vector4(values_[8], values_[9], values_[10], values_[11]);
	//}
	//Vector4 Matrix4::t()
	//{
	//	return Vector4(values_[12], values_[13], values_[14], values_[15]);
	//}
	//const Vector4 Matrix4::x() const
	//{
	//	return Vector4(values_[0], values_[1], values_[2], values_[3]);
	//}
	//const Vector4 Matrix4::y() const
	//{
	//	return Vector4(values_[4], values_[5], values_[6], values_[7]);
	//}
	//const Vector4 Matrix4::z() const
	//{
	//	return Vector4(values_[8], values_[9], values_[10], values_[11]);
	//}
	//const Vector4 Matrix4::t() const
	//{
	//	return Vector4(values_[12], values_[13], values_[14], values_[15]);
	//}

	//\===========================================================================================
	//\ Component Access/ Retreival As Vector4
	//\===========================================================================================
	void Matrix4::SetX(const Vector4& a_v4)
	{
		values_[0] = a_v4.x;
		values_[1] = a_v4.y;
		values_[2] = a_v4.z;
		values_[3] = a_v4.w;
	}
	void Matrix4::SetY(const Vector4& a_v4)
	{
		values_[4] = a_v4.x;
		values_[5] = a_v4.y;
		values_[6] = a_v4.z;
		values_[7] = a_v4.w;
	}
	void Matrix4::SetZ(const Vector4& a_v4)
	{
		values_[8] = a_v4.x;
		values_[9] = a_v4.y;
		values_[10] = a_v4.z;
		values_[11] = a_v4.w;
	}
	void Matrix4::SetT(const Vector3& a_v3)
	{
		values_[12] = a_v3.x;
		values_[13] = a_v3.y;
		values_[14] = a_v3.z;
		values_[15] = 0;
	}
	void Matrix4::SetT(const Vector4& a_v4)
	{
		values_[12] = a_v4.x;
		values_[13] = a_v4.y;
		values_[14] = a_v4.z;
		values_[15] = a_v4.w;
	}
	Vector4 Matrix4::GetX() const
	{
		return Vector4(values_[0], values_[1], values_[2], values_[3]);
	}
	Vector4 Matrix4::GetY() const
	{
		return Vector4(values_[4], values_[5], values_[6], values_[7]);
	}
	Vector4 Matrix4::GetZ() const
	{
		return Vector4(values_[8], values_[9], values_[10], values_[11]);
	}
	Vector4 Matrix4::GetT() const
	{
		return Vector4(values_[12], values_[13], values_[14], values_[15]);
	}

	//\===========================================================================================
	//\ Translate the Matrix4
	//\===========================================================================================
	void Matrix4::Translate(Vector2& a_v2)
	{
		values_[12] += a_v2.x;
		values_[13] += a_v2.y;
	}
	void Matrix4::Translate(Vector3& a_v3)
	{
		values_[12] += a_v3.x;
		values_[13] += a_v3.y;
		values_[14] += a_v3.z;
	}

	//\===========================================================================================
	//\ Component Row/Column Access Operators
	//\===========================================================================================
	void Matrix4::SetCol(int iCol, const Vector3& vCol)
	{
		this->operator()(1, iCol) = vCol.x;
		this->operator()(2, iCol) = vCol.y;
		this->operator()(3, iCol) = vCol.z;
	}
	void Matrix4::SetCol(int iCol, const Vector4& vCol)
	{
		this->operator()(1, iCol) = vCol.x;
		this->operator()(2, iCol) = vCol.y;
		this->operator()(3, iCol) = vCol.z;
		this->operator()(4, iCol) = vCol.w;
	}
	void Matrix4::GetCol(int iCol, Vector3& vCol) const
	{
		vCol.x = this->operator()(1, iCol);
		vCol.y = this->operator()(2, iCol);
		vCol.z = this->operator()(3, iCol);
	}
	void Matrix4::GetCol(int iCol, Vector4& vCol) const
	{
		vCol.x = this->operator()(1, iCol);
		vCol.y = this->operator()(2, iCol);
		vCol.z = this->operator()(3, iCol);
		vCol.w = this->operator()(4, iCol);
	}
	void Matrix4::SetRow(int iRow, const Vector3& vRow)
	{
		this->operator()(iRow, 1) = vRow.x;
		this->operator()(iRow, 2) = vRow.y;
		this->operator()(iRow, 3) = vRow.z;
	}
	void Matrix4::SetRow(int iRow, const Vector4& vRow)
	{
		this->operator()(iRow, 1) = vRow.x;
		this->operator()(iRow, 2) = vRow.y;
		this->operator()(iRow, 3) = vRow.z;
		this->operator()(iRow, 4) = vRow.w;
	}
	void Matrix4::GetRow(int iRow, Vector3& vRow) const
	{
		vRow.x = this->operator()(iRow, 1);
		vRow.y = this->operator()(iRow, 2);
		vRow.z = this->operator()(iRow, 3);
	}
	void Matrix4::GetRow(int iRow, Vector4& vRow) const
	{
		vRow.x = this->operator()(iRow, 1);
		vRow.y = this->operator()(iRow, 2);
		vRow.z = this->operator()(iRow, 3);
		vRow.w = this->operator()(iRow, 4);
	}

	//\===========================================================================================
	//\ Equivalence operators
	//\===========================================================================================
	bool Matrix4::operator == (const Matrix4& a_m4) const
	{
		for (int i = 0; i < sizeof(values_) / sizeof(values_[0]); i++)
		{
			if (values_[i] != a_m4.values_[i])
			{
				return false;
			}
		}
		return true;
	}
	bool Matrix4::operator != (const Matrix4& a_m4) const
	{
		for (int i = 0; i < sizeof(values_) / sizeof(values_[0]); i++)
		{
			if (values_[i] == a_m4.values_[i])
			{
				return true;
			}
		}
		return false;
	}

	//\===========================================================================================
	//\ Operator overloads for Addition
	//\===========================================================================================
	const Matrix4 Matrix4::operator + (const Matrix4& a_m4) const
	{
		float answer[16];
		for (int i = 0; i < sizeof(values_) / sizeof(values_[0]); i++)
		{
			answer[i] = values_[i] + a_m4.values_[i];
		}
		return Matrix4(answer);
	}
	const Matrix4& Matrix4::operator += (const Matrix4& a_m4)
	{
		*this = *this + a_m4;
		return *this;
	}
	//\===========================================================================================
	//\ Operator overloads for Subtraction
	//\===========================================================================================
	const Matrix4 Matrix4::operator - (const Matrix4& a_m4) const
	{
		float answer[16];
		for (int i = 0; i < sizeof(values_) / sizeof(values_[0]); i++)
		{
			answer[i] = values_[i] - a_m4.values_[i];
		}
		return Matrix4(answer);
	}
	const Matrix4& Matrix4::operator -= (const Matrix4& a_m4)
	{
		*this = *this - a_m4;
		return *this;
	}
	//\===========================================================================================
	//\ Operator overloads for multiplication
	//\=========================================================================================== 
	const Matrix4 Matrix4::operator * (float a_fScalar) const
	{
		float answer[16];
		for (int i = 0; i < sizeof(values_) / sizeof(values_[0]); i++)
		{
			answer[i] = values_[i] * a_fScalar;
		}
		return Matrix4(answer);
	}
	const Matrix4 operator * (float a_fScalar, const Matrix4& a_m4)
	{
		float answer[16];
		for (int i = 0; i < sizeof(a_m4.values_) / sizeof(a_m4.values_[0]); i++)
		{
			answer[i] = a_m4.values_[i] * a_fScalar;
		}
		return Matrix4(answer);
	}
	const Matrix4& Matrix4::operator *= (float a_fScalar)
	{
		*this = *this * a_fScalar;
		return *this;
	}
	const Vector2 Matrix4::operator*(const Vector2& a_v2) const
	{
		return Vector2(
			values2D_[0][0] * a_v2.x + values2D_[0][1] * a_v2.y,
			values2D_[1][0] * a_v2.x + values2D_[1][1] * a_v2.y
			);
	}
	const Vector2 operator*(const Vector2& a_v2, const Matrix4 a_m4)
	{
		return a_m4 * a_v2;
	}
	const Vector3 Matrix4::operator * (const Vector3& a_v3) const
	{
		return Vector3(
			values2D_[0][0] * a_v3.x + values2D_[0][1] * a_v3.y + values2D_[0][2] * a_v3.z,
			values2D_[1][0] * a_v3.x + values2D_[1][1] * a_v3.y + values2D_[1][2] * a_v3.z,
			values2D_[2][0] * a_v3.x + values2D_[2][1] * a_v3.y + values2D_[2][2] * a_v3.z
			);
	}
	const Vector3 operator * (const Vector3& a_v3, const Matrix4& a_m4)
	{
		return a_m4 * a_v3;
	}
	const Vector4 Matrix4::operator * (const Vector4& a_v4) const
	{
		return Vector4(
			values2D_[0][0] * a_v4.x + values2D_[0][1] * a_v4.y + values2D_[0][2] * a_v4.z + values2D_[0][3] * a_v4.w,
			values2D_[1][0] * a_v4.x + values2D_[1][1] * a_v4.y + values2D_[1][2] * a_v4.z + values2D_[1][3] * a_v4.w,
			values2D_[2][0] * a_v4.x + values2D_[2][1] * a_v4.y + values2D_[2][2] * a_v4.z + values2D_[2][3] * a_v4.w,
			values2D_[3][0] * a_v4.x + values2D_[3][1] * a_v4.y + values2D_[3][2] * a_v4.z + values2D_[3][3] * a_v4.w
			);
	}
	const Vector4 operator * (const Vector4& a_v4, const Matrix4& a_m4)
	{
		return a_m4 * a_v4;
	}
	const Matrix4 Matrix4::operator * (const Matrix4& a_m4) const
	{
		//Optimised
		return Matrix4(
			values_[0] * a_m4.values_[0] + values_[1] * a_m4.values_[4] + values_[2] * a_m4.values_[8],
			values_[0] * a_m4.values_[1] + values_[1] * a_m4.values_[5] + values_[2] * a_m4.values_[9],
			values_[0] * a_m4.values_[2] + values_[1] * a_m4.values_[6] + values_[2] * a_m4.values_[10],
			0,
			0 + values_[5] * a_m4.values_[4] + values_[6] * a_m4.values_[8],
			0 + values_[5] * a_m4.values_[5] + values_[6] * a_m4.values_[9],
			0 + values_[5] * a_m4.values_[6] + values_[6] * a_m4.values_[10],
			0,
			values_[8] * a_m4.values_[0] + values_[9] * a_m4.values_[4] + values_[10] * a_m4.values_[8],
			values_[8] * a_m4.values_[1] + values_[9] * a_m4.values_[5] + values_[10] * a_m4.values_[9],
			values_[8] * a_m4.values_[2] + values_[9] * a_m4.values_[6] + values_[10] * a_m4.values_[10],
			0,
			values_[12] * a_m4.values_[0] + values_[13] * a_m4.values_[4] + values_[14] * a_m4.values_[8] + a_m4.values_[12],
			values_[12] * a_m4.values_[1] + values_[13] * a_m4.values_[5] + values_[14] * a_m4.values_[9] + a_m4.values_[13],
			values_[12] * a_m4.values_[2] + values_[13] * a_m4.values_[6] + values_[14] * a_m4.values_[10] + a_m4.values_[14],
			1
			);
		//return Matrix4(
		//	values_[0] * a_m4.values_[0] + values_[1] * a_m4.values_[4] + values_[2] * a_m4.values_[8] + values_[3] * a_m4.values_[12],
		//	values_[0] * a_m4.values_[1] + values_[1] * a_m4.values_[5] + values_[2] * a_m4.values_[9] + values_[3] * a_m4.values_[13],
		//	values_[0] * a_m4.values_[2] + values_[1] * a_m4.values_[6] + values_[2] * a_m4.values_[10] + values_[3] * a_m4.values_[14],
		//	values_[0] * a_m4.values_[3] + values_[1] * a_m4.values_[7] + values_[2] * a_m4.values_[11] + values_[3] * a_m4.values_[15],
		//	values_[3] * a_m4.values_[0] + values_[5] * a_m4.values_[4] + values_[6] * a_m4.values_[8] + values_[7] * a_m4.values_[12],
		//	values_[3] * a_m4.values_[1] + values_[5] * a_m4.values_[5] + values_[6] * a_m4.values_[9] + values_[7] * a_m4.values_[13],
		//	values_[3] * a_m4.values_[2] + values_[5] * a_m4.values_[6] + values_[6] * a_m4.values_[10] + values_[7] * a_m4.values_[14],
		//	values_[3] * a_m4.values_[3] + values_[5] * a_m4.values_[7] + values_[6] * a_m4.values_[11] + values_[7] * a_m4.values_[15],
		//	values_[8] * a_m4.values_[0] + values_[9] * a_m4.values_[4] + values_[10] * a_m4.values_[8] + values_[11] * a_m4.values_[12],
		//	values_[8] * a_m4.values_[1] + values_[9] * a_m4.values_[5] + values_[10] * a_m4.values_[9] + values_[11] * a_m4.values_[13],
		//	values_[8] * a_m4.values_[2] + values_[9] * a_m4.values_[6] + values_[10] * a_m4.values_[10] + values_[11] * a_m4.values_[14],
		//	values_[8] * a_m4.values_[3] + values_[13] * a_m4.values_[7] + values_[14] * a_m4.values_[11] + values_[15] * a_m4.values_[15],
		//	values_[12] * a_m4.values_[0] + values_[13] * a_m4.values_[4] + values_[14] * a_m4.values_[8] + values_[15] * a_m4.values_[12],
		//	values_[12] * a_m4.values_[1] + values_[13] * a_m4.values_[5] + values_[14] * a_m4.values_[9] + values_[15] * a_m4.values_[13],
		//	values_[12] * a_m4.values_[2] + values_[13] * a_m4.values_[6] + values_[14] * a_m4.values_[10] + values_[15] * a_m4.values_[14],
		//	values_[12] * a_m4.values_[3] + values_[13] * a_m4.values_[7] + values_[14] * a_m4.values_[11] + values_[15] * a_m4.values_[15]
		//	);
	}
	const Matrix4& Matrix4::operator *= (const Matrix4& a_m4)
	{
		*this = *this * a_m4;
		return *this;
	}

	//\=========================================================================================== 
	//\ Transpose Matrix
	//\===========================================================================================
	void Matrix4::Transpose()
	{
		*this = GetTranspose();
	}

	Matrix4 Matrix4::GetTranspose() const
	{
		return Matrix4(
			values_[0], values_[4], values_[8], values_[12],
			values_[1], values_[5], values_[9], values_[13],
			values_[2], values_[6], values_[10], values_[14],
			values_[3], values_[7], values_[11], values_[15]
			);
	}

	//\=========================================================================================== 
	// Inverse Matrix Functions
	//\===========================================================================================
	float Matrix4::Determinant() const
	{
		return (float)(
			values_[0] * (values_[5] * values_[10] - values_[6] * values_[9] +
				values_[1] * (values_[6] * values_[8] - values_[4] * values_[10]) +
				values_[2] * (values_[4] * values_[9] - values_[5] * values_[8])));
	}
	bool Matrix4::Inverse()
	{
		float fDeterminant = Determinant();
		if (fDeterminant != 0.0f)
		{
			//const float fInvDet = Recipf(fDeterminant);
			const float fInvDet = 0;
			Matrix4 mat = *this;
			values_[0] = (mat.values_[5] * mat.values_[10] - mat.values_[6] * mat.values_[9]) * fInvDet;
			values_[1] = (mat.values_[2] * mat.values_[9] - mat.values_[1] * mat.values_[10]) * fInvDet;
			values_[2] = (mat.values_[1] * mat.values_[6] - mat.values_[2] * mat.values_[5]) * fInvDet;
			values_[3] = 0;

			values_[4] = (mat.values_[6] * mat.values_[8] - mat.values_[4] * mat.values_[10]) * fInvDet;
			values_[5] = (mat.values_[0] * mat.values_[10] - mat.values_[2] * mat.values_[8]) * fInvDet;
			values_[6] = (mat.values_[2] * mat.values_[4] - mat.values_[0] * mat.values_[6]) * fInvDet;
			values_[7] = 0;

			values_[8] = (mat.values_[4] * mat.values_[9] - mat.values_[5] * mat.values_[8]) * fInvDet;
			values_[9] = (mat.values_[1] * mat.values_[8] - mat.values_[0] * mat.values_[9]) * fInvDet;
			values_[10] = (mat.values_[0] * mat.values_[5] - mat.values_[1] * mat.values_[4]) * fInvDet;
			values_[11] = 0;

			return true;
		}
		return false;
	}
	//\=========================================================================================== 
	// Matrix Rotation functions
	//\===========================================================================================
	void Matrix4::RotateAboutX(const float fAngle)
	{
		*this = CreateRotationMatrix4AboutX(fAngle) * *this;
	}
	void Matrix4::RotateAboutY(const float fAngle)
	{
		*this = CreateRotationMatrix4AboutY(fAngle) * *this;
	}
	void Matrix4::RotateAboutZ(const float fAngle)
	{
		*this = CreateRotationMatrix4AboutZ(fAngle) * *this;
	}
	//\=========================================================================================== 
	// Matrix Rotation functions
	//\===========================================================================================
	Matrix4 CreateRotationMatrix4AboutX(const float fAngleRadians)
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

		Matrix4 m4;

		m4.values_[0] = 1;  m4.values_[1] = 0;  m4.values_[2] = 0;  m4.values_[3] = 0;
		m4.values_[4] = 0;  m4.values_[5] = c;  m4.values_[6] = s;  m4.values_[7] = 0;
		m4.values_[8] = 0;  m4.values_[9] = -s; m4.values_[10] = c; m4.values_[11] = 0;
		m4.values_[12] = 0; m4.values_[13] = 0; m4.values_[14] = 0; m4.values_[15] = 1;

		return m4;
	}
	Matrix4 CreateRotationMatrix4AboutY(const float fAngleRadians)
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

		Matrix4 m4;

		m4.values_[0] = c;  m4.values_[1] = 0;  m4.values_[2] = -s; m4.values_[3] = 0;
		m4.values_[4] = 0;  m4.values_[5] = 1;  m4.values_[6] = 0;  m4.values_[7] = 0;
		m4.values_[8] = s;  m4.values_[9] = 0;  m4.values_[10] = c;  m4.values_[11] = 0;
		m4.values_[12] = 0; m4.values_[13] = 0; m4.values_[14] = 0;  m4.values_[15] = 1;

		return m4;
	}
	Matrix4 CreateRotationMatrix4AboutZ(const float fAngleRadians)
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

		Matrix4 m4;

		m4.values_[0] = c;  m4.values_[1] = -s;   m4.values_[2] = 0;  m4.values_[3] = 0;
		m4.values_[4] = s; m4.values_[5] = c;   m4.values_[6] = 0;  m4.values_[7] = 0;
		m4.values_[8] = 0;  m4.values_[9] = 0;   m4.values_[10] = 1; m4.values_[11] = 0;
		m4.values_[12] = 0; m4.values_[13] = 0;  m4.values_[14] = 0; m4.values_[15] = 1;

		return m4;
	}

	void Matrix4::MoveForwards(const float a_f)
	{
		Vector4 v4 = GetY();
		Translate(Vector2(v4.x, v4.y) * a_f);
	}

	void Matrix4::MoveBackwards(const float a_f)
	{
		Vector4 v4 = GetY();
		Translate(Vector2(v4.x, v4.y) * -a_f);
	}

	void Matrix4::SetPosition2D(const Vector2 & a_v2Pos)
	{
		values_[12] = a_v2Pos.x;
		values_[13] = a_v2Pos.y;
	}

	Vector2 Matrix4::GetPosition2D() const
	{
		return Vector2(values_[12], values_[13]);
	}

	Matrix4 Matrix4::ConstructCameraView(const Vector3& vecPosition, const Vector3& vecDirection, const Vector3& vecUp) const
	{
		Vector3 vecCamRight = CrossProd(vecDirection, vecUp).GetNormalised();
		Vector3 vecCamUp = CrossProd(vecCamRight, vecDirection);

		Matrix4 R(vecCamRight, vecCamUp, -vecDirection, vecPosition);
		Matrix4 T;
		T.SetT(vecPosition);
		T.Inverse();
		//this doesn't work i need to do invertedTR or some shit
		return(T*R);
	}
}