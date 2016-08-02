#include "Vector4.h"
namespace Maths
{
	Vector4::Vector4() : x(0.f), y(0.f), z(0.f) {}
	Vector4::Vector4(const Vector4* a_v4) : x(a_v4->x), y(a_v4->y), z(a_v4->z) {}
	Vector4::Vector4(const Vector4& a_v4) : x(a_v4.x), y(a_v4.y), z(a_v4.z) {}
	//Vector4::Vector4(const Vector4& a_v4) : x(a_v4.x), y(a_v4.y), z(0) {}
	Vector4::Vector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w) : x(a_x), y(a_y), z(a_z), w(a_w) {}
	Vector4::~Vector4() {}

	const Vector4 Vector4::ZERO = Vector4(0, 0, 0, 0);

	Vector4 Vector4::operator+(const Vector4& b_v4d)const
	{
		return Vector4(this->x + b_v4d.x, this->y + b_v4d.y, this->z + b_v4d.z, this->w + b_v4d.w);
	}

	Vector4& Vector4::operator+=(const Vector4& a_v4d)
	{
		x += a_v4d.x;
		y += a_v4d.y;
		z += a_v4d.z;
		w += a_v4d.w;
		return *this;
	}

	Vector4 Vector4::operator-(const Vector4& b_v4d)const
	{
		return Vector4(this->x - b_v4d.x, this->y - b_v4d.y, this->z - b_v4d.z, this->w - b_v4d.w);
	}

	Vector4& Vector4::operator-=(const Vector4& a_v4d)
	{
		x -= a_v4d.x;
		y -= a_v4d.y;
		z -= a_v4d.z;
		w -= a_v4d.w;
		return *this;
	}

	Vector4 Vector4::operator*(const Vector4& b_v4d)const
	{
		return Vector4(this->x * b_v4d.x, this->y * b_v4d.y, this->z / b_v4d.z, this->w / b_v4d.w);
	}

	Vector4& Vector4::operator*=(const Vector4& a_v4d)
	{
		x *= a_v4d.x;
		y *= a_v4d.y;
		z *= a_v4d.z;
		w *= a_v4d.w;
		return *this;
	}

	Vector4 Vector4::operator/(const Vector4& b_v4d)const
	{
		return Vector4(this->x / b_v4d.x, this->y / b_v4d.y, this->z / b_v4d.z, this->w / b_v4d.w);
	}

	Vector4& Vector4::operator/=(const Vector4& a_v4d)
	{
		x /= a_v4d.x;
		y /= a_v4d.y;
		z /= a_v4d.z;
		w /= a_v4d.w;
		return *this;
	}

	bool Vector4::operator!=(const Vector4& b_v4d)const
	{
		if (this->x == b_v4d.x && this->y == b_v4d.y && this->z == b_v4d.z && this->w == b_v4d.w)
			return false;
		return true;
	}

	bool Vector4::operator==(const Vector4& b_v4d)const
	{
		if (this->x == b_v4d.x && this->y == b_v4d.y && this->z == b_v4d.z && this->w == b_v4d.w)
			return true;
		return false;
	}

	Vector4 Vector4::operator+(const float& a_f)const
	{
		return Vector4(this->x + a_f, this->y + a_f, this->z + a_f, this->w + a_f);
	}

	Vector4& Vector4::operator+=(const float& a_f)
	{
		x += a_f;
		y += a_f;
		z += a_f;
		w += a_f;
		return *this;
	}

	Vector4 Vector4::operator-(const float& a_f)const
	{
		return Vector4(this->x - a_f, this->y - a_f, this->z - a_f, this->w - a_f);
	}

	Vector4& Vector4::operator-=(const float& a_f)
	{
		x -= a_f;
		y -= a_f;
		z -= a_f;
		w -= a_f;
		return *this;
	}

	Vector4 Vector4::operator*(const float& a_f)const
	{
		return Vector4(this->x * a_f, this->y * a_f, this->z * a_f, this->w * a_f);
	}

	Vector4& Vector4::operator*=(const float& a_f)
	{
		x *= a_f;
		y *= a_f;
		z *= a_f;
		w *= a_f;
		return *this;
	}

	Vector4 Vector4::operator/(const float& a_f)const
	{
		return Vector4(this->x / a_f, this->y / a_f, this->z / a_f, this->w / a_f);
	}

	Vector4& Vector4::operator/=(const float& a_f)
	{
		x /= a_f;
		y /= a_f;
		z /= a_f;
		w /= a_f;
		return *this;
	}

	float DotProd(const Vector4& lhs, const Vector4& rhs)
	{
		return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
	}

	float Vector4::Magnitude() const
	{
		return (float)sqrt(x * x + y * y + z * z + w * w);
	}

	void Vector4::Normalise()
	{
		float length = this->Magnitude();
		x /= length;
		y /= length;
		z /= length;
		w /= length;
	}

	void Vector4::Scale(const float& a_fScale)
	{
		x *= a_fScale;
		y *= a_fScale;
		z *= a_fScale;
		w *= a_fScale;
	}

	//Extra Methods
	float Angle(const Vector4& lhs, const Vector4& rhs)
	{
		return (float)acos((DotProd(lhs, rhs)) / (lhs.Modulus() * rhs.Modulus()));
	}

	float Vector4::Angle(const Vector4& a_v4d) const
	{
		return (float)acos((DotProd(Vector4(x, y, z, w), a_v4d)) / (Vector4(x, y, z, w).Modulus() * a_v4d.Modulus()));
	}

	float Distance(const Vector4& lhs, const Vector4& rhs)
	{
		return (float)sqrt(((lhs.x - rhs.x) * (lhs.x - rhs.x)) + ((lhs.y - rhs.y) * (lhs.y - rhs.y)) + ((lhs.z - rhs.z) * (lhs.z - rhs.z)) + ((lhs.w - rhs.w) * (lhs.w - rhs.w)));
	}

	float Vector4::Distance(const Vector4& a_v4d) const
	{
		return (float)sqrt(((x - a_v4d.x) * (x - a_v4d.x)) + ((y - a_v4d.y) * (y - a_v4d.y)) + ((z - a_v4d.z) * (z - a_v4d.z)) + ((w - a_v4d.w) * (w - a_v4d.w)));
	}

	float Vector4::Modulus() const
	{
		return (float)sqrt(x * x + y * y + z * z + w * w);
	}

	Vector4 Vector4::Lerp(const Vector4& destination, const float& a_value) const
	{
		return (Vector4(x, y, z, w) * (1 - a_value)) + (destination * a_value);
	}

	void Vector4::Lerp(const Vector4& destination, const float& a_value)
	{
		x = (x * (1 - a_value)) + (destination.x * a_value);
		y = (y * (1 - a_value)) + (destination.y * a_value);
		z = (z * (1 - a_value)) + (destination.z * a_value);
		w = (w * (1 - a_value)) + (destination.w * a_value);
	}

	float Vector4::Slerp(const Vector4& destination, const float& a_value)
	{
		float omega = (float)cos(DotProd(Vector4(this), destination));
		float sineA = (float)(sin(1 - a_value)*omega) / (float)sin(omega);
		float sineB = ((float)sin(a_value * omega)) / (float)sin(omega);
		x = x * sineA + destination.x * sineB;
		y = y * sineA + destination.y * sineB;
		z = z * sineA + destination.z * sineB;
		w = w * sineA + destination.w * sineB;
		return omega;
	}
}