#include "Vector3.h"
namespace Maths
{
	Vector3::Vector3() : x(0.f), y(0.f), z(0.f) {}
	Vector3::Vector3(const Vector3* a_v3) : x(a_v3->x), y(a_v3->y), z(a_v3->z) {}
	Vector3::Vector3(const Vector3& a_v3) : x(a_v3.x), y(a_v3.y), z(a_v3.z) {}
	Vector3::Vector3(const Vector2& a_v2) : x(a_v2.x), y(a_v2.y), z(0) {}
	//Vector3::Vector3(const Vector3& a_v3) : x(a_v3.x), y(a_v3.y), z(0) {}
	Vector3::Vector3(const float& a_x, const float& a_y, const float& a_z) : x(a_x), y(a_y), z(a_z) {}
	Vector3::~Vector3() {}

	Vector3 Vector3::ZERO = Vector3(0, 0, 0);

	Vector3 Vector3::operator+(const Vector3& b_v3d)const
	{
		return Vector3(this->x + b_v3d.x, this->y + b_v3d.y, this->z + b_v3d.z);
	}

	Vector3& Vector3::operator+=(const Vector3& a_v3d)
	{
		x += a_v3d.x;
		y += a_v3d.y;
		z += a_v3d.z;
		return *this;
	}

	Vector2 operator+(const float& a_f, Vector3 a_v3d)
	{
		return (a_v3d.x + a_f, a_v3d.y + a_f, a_v3d.z + a_f);
	}

	void operator+=(const float& a_f, Vector3 a_v3d)
	{
		a_v3d.x += a_f;
		a_v3d.y += a_f;
		a_v3d.z += a_f;
	}

	const Vector3 operator-(const Vector3& a_v3d)
	{
		return Vector3(-a_v3d.x, -a_v3d.y, -a_v3d.z);
	}

	Vector3 Vector3::operator-(const Vector3& b_v3d)const
	{
		return Vector3(this->x - b_v3d.x, this->y - b_v3d.y, this->z - b_v3d.z);
	}

	Vector3& Vector3::operator-=(const Vector3& a_v3d)
	{
		x -= a_v3d.x;
		y -= a_v3d.y;
		z -= a_v3d.z;
		return *this;
	}

	Vector3 Vector3::operator*(const Vector3& b_v3d)const
	{
		return Vector3(this->x * b_v3d.x, this->y * b_v3d.y, this->z * b_v3d.z);
	}

	Vector3& Vector3::operator*=(const Vector3& a_v3d)
	{
		x *= a_v3d.x;
		y *= a_v3d.y;
		z *= a_v3d.z;
		return *this;
	}

	Vector3 operator*(const float& a_f, const Vector3& a_v3d)
	{
		return Vector3(a_v3d.x * a_f, a_v3d.y * a_f, a_v3d.z * a_f);
	}

	void operator*=(const float& a_f, Vector3 a_v3d)
	{
		a_v3d.x *= a_f;
		a_v3d.y *= a_f;
		a_v3d.z *= a_f;
	}

	Vector3 Vector3::operator/(const Vector3& b_v3d)const
	{
		return Vector3(this->x / b_v3d.x, this->y / b_v3d.y, this->z / b_v3d.z);
	}

	Vector3& Vector3::operator/=(const Vector3& a_v3d)
	{
		x /= a_v3d.x;
		y /= a_v3d.y;
		z /= a_v3d.z;
		return *this;
	}

	bool Vector3::operator!=(const Vector3& b_v3d)const
	{
		if (this->x == b_v3d.x && this->y == b_v3d.y && this->z == b_v3d.z)
			return false;
		return true;
	}

	bool Vector3::operator==(const Vector3& b_v3d)const
	{
		if (this->x == b_v3d.x && this->y == b_v3d.y && this->z == b_v3d.z)
			return true;
		return false;
	}

	Vector3 Vector3::operator+(const float& a_f)const
	{
		return Vector3(this->x + a_f, this->y + a_f, this->z + a_f);
	}

	Vector3& Vector3::operator+=(const float& a_f)
	{
		x += a_f;
		y += a_f;
		z += a_f;
		return *this;
	}

	Vector3 Vector3::operator-(const float& a_f)const
	{
		return Vector3(this->x - a_f, this->y - a_f, this->z - a_f);
	}

	Vector3& Vector3::operator-=(const float& a_f)
	{
		x -= a_f;
		y -= a_f;
		z -= a_f;
		return *this;
	}

	Vector3 Vector3::operator*(const float& a_f)const
	{
		return Vector3(this->x * a_f, this->y * a_f, this->z * a_f);
	}

	Vector3& Vector3::operator*=(const float& a_f)
	{
		x *= a_f;
		y *= a_f;
		z *= a_f;
		return *this;
	}

	Vector3 Vector3::operator/(const float& a_f)const
	{
		return Vector3(this->x / a_f, this->y / a_f, this->z / a_f);
	}

	Vector3& Vector3::operator/=(const float& a_f)
	{
		x /= a_f;
		y /= a_f;
		z /= a_f;
		return *this;
	}

	float DotProd(const Vector3& lhs, const Vector3& rhs)
	{
		return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
	}

	float Vector3::Magnitude() const
	{
		return (float)sqrt(x * x + y * y + z * z);
	}

	Vector3 CrossProd(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x);
	}

	void Vector3::CrossProd(const Vector3& a_v3d)
	{
		Vector3 temp = *this;
		x = temp.y * a_v3d.z - temp.z * a_v3d.y;
		y = temp.z * a_v3d.x - temp.x * a_v3d.z;
		z = temp.y * a_v3d.x - temp.x * a_v3d.y;
	}

	void Vector3::Normalise()
	{
		float length = this->Magnitude();
		x /= length;
		y /= length;
		z /= length;
	}

	Vector3 Vector3::GetNormalised() const
	{
		float length = this->Magnitude();
		return Vector3(x / length, y / length, z / length);
	}

	void Vector3::Scale(const float& a_fScale)
	{
		x *= a_fScale;
		y *= a_fScale;
		z *= a_fScale;
	}

	//Extra Methods
	float Angle(const Vector3& lhs, const Vector3& rhs)
	{
		return (float)acos((DotProd(lhs, rhs)) / (lhs.Modulus() * rhs.Modulus()));
	}

	float Vector3::Angle(const Vector3& a_v3d) const
	{
		return (float)acos((DotProd(Vector3(x, y, z), a_v3d)) / (Vector3(x, y, z).Modulus() * a_v3d.Modulus()));
	}

	float Distance(const Vector3& lhs, const Vector3& rhs)
	{
		return (float)sqrt(((lhs.x - rhs.x) * (lhs.x - rhs.x)) + ((lhs.y - rhs.y) * (lhs.y - rhs.y)) + ((lhs.z - rhs.z) * (lhs.z - rhs.z)));
	}

	float Vector3::Distance(const Vector3& a_v3d) const
	{
		return (float)sqrt(((x - a_v3d.x) * (x - a_v3d.x)) + ((y - a_v3d.y) * (y - a_v3d.y)) + ((z - a_v3d.z) * (z - a_v3d.z)));
	}

	float Vector3::Modulus() const
	{
		return (float)sqrt(x * x + y * y + z * z);
	}

	Vector3 Vector3::Lerp(const Vector3& destination, const float& a_value) const
	{
		return (Vector3(x, y, z) * (1 - a_value)) + (destination * a_value);
	}

	void Vector3::Lerp(const Vector3& destination, const float& a_value)
	{
		x = (x * (1 - a_value)) + (destination.x * a_value);
		y = (y * (1 - a_value)) + (destination.y * a_value);
		z = (z * (1 - a_value)) + (destination.z * a_value);
	}

	float Vector3::Slerp(const Vector3& destination, const float& a_value)
	{
		float omega = (float)cos(DotProd(Vector3(this), destination));
		x = x * ((float)(sin(1 - a_value)*omega) / (float)sin(omega)) + destination.x * ((float)sin(a_value * omega)) / (float)sin(omega);
		y = y * ((float)(sin(1 - a_value)*omega) / (float)sin(omega)) + destination.y * ((float)sin(a_value * omega)) / (float)sin(omega);
		z = z * ((float)(sin(1 - a_value)*omega) / (float)sin(omega)) + destination.z * ((float)sin(a_value * omega)) / (float)sin(omega);
		return omega;
	}
}