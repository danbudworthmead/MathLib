#include "Vector2.h"
#include <math.h>
 
namespace Maths
{
	Vector2::Vector2() : x(0.f), y(0.f) {}
	Vector2::Vector2(const Vector2* a_v2) : x(a_v2->x), y(a_v2->y) {}
	Vector2::Vector2(const Vector2& a_v2) : x(a_v2.x), y(a_v2.y) {}
	Vector2::Vector2(const float& a_x, const float& a_y) : x(a_x), y(a_y) {}
	Vector2::Vector2(const float& radians) : x((float)sin(radians * PI)), y((float)cos(radians * PI)) {}
	Vector2::~Vector2() {}

	const Vector2 Vector2::ZERO = Vector2(0, 0);
	const Vector2 Vector2::UP = Vector2(0, 1);
	const Vector2 Vector2::DOWN = Vector2(0, -1);
	const Vector2 Vector2::LEFT = Vector2(-1, 0);
	const Vector2 Vector2::RIGHT = Vector2(1, 0);

	Vector2 Vector2::operator+(const Vector2& a_v2d)const
	{
		return Vector2(this->x + a_v2d.x, this->y + a_v2d.y);
	}

	Vector2& Vector2::operator+=(const Vector2& a_v2d)
	{
		x += a_v2d.x;
		y += a_v2d.y;
		return *this;
	}

	Vector2 Vector2::operator-(const Vector2& a_v2d)const
	{
		return Vector2(this->x - a_v2d.x, this->y - a_v2d.y);
	}

	Vector2& Vector2::operator-=(const Vector2& a_v2d)
	{
		x -= a_v2d.x;
		y -= a_v2d.y;
		return *this;
	}

	Vector2 Vector2::operator*(const Vector2& a_v2d)const
	{
		return Vector2(this->x * a_v2d.x, this->y * a_v2d.y);
	}

	Vector2& Vector2::operator*=(const Vector2& a_v2d)
	{
		x *= a_v2d.x;
		y *= a_v2d.y;
		return *this;
	}

	Vector2 Vector2::operator/(const Vector2& a_v2d)const
	{
		return Vector2(this->x / a_v2d.x, this->y / a_v2d.y);
	}

	Vector2& Vector2::operator/=(const Vector2& a_v2d)
	{
		x /= a_v2d.x;
		y /= a_v2d.y;
		return *this;
	}

	bool Vector2::operator!=(const Vector2& a_v2d)const
	{
		if (this->x == a_v2d.x && this->y == a_v2d.y)
			return false;
		return true;
	}

	bool Vector2::operator==(const Vector2& a_v2d)const
	{
		if (this->x == a_v2d.x && this->y == a_v2d.y)
			return true;
		return false;
	}

	Vector2 Vector2::operator+(const float& a_f)const
	{
		return Vector2(this->x + a_f, this->y + a_f);
	}

	Vector2& Vector2::operator+=(const float& a_f)
	{
		x += a_f;
		y += a_f;
		return *this;
	}

	Vector2 operator+(const float& a_f, const Vector2& a_v2d)
	{
		return Vector2(a_v2d.x + a_f, a_v2d.y + a_f);
	}

	void operator+=(const float& a_f, Vector2 a_v2d)
	{
		a_v2d.x += a_f;
		a_v2d.y += a_f;
	}

	Vector2 Vector2::operator-(const float& a_f)const
	{
		return Vector2(this->x - a_f, this->y - a_f);
	}

	Vector2& Vector2::operator-=(const float& a_f)
	{
		x -= a_f;
		y -= a_f;
		return *this;
	}

	//\===========================================================================================
	//\	Opposite Operator Overload
	//\===========================================================================================
	Vector2 Vector2::operator-()const
	{
		return *this * -1;
	}

	Vector2 Vector2::operator*(const float& a_f)const
	{
		return Vector2(this->x * a_f, this->y * a_f);
	}

	Vector2 operator*(const float& a_f, const Vector2& a_v2d)
	{
		return Vector2(a_v2d.x * a_f, a_v2d.y * a_f);
	}

	void operator*=(const float& a_f, Vector2 a_v2d)
	{
		a_v2d.x *= a_f;
		a_v2d.y *= a_f;
	}

	Vector2& Vector2::operator*=(const float& a_f)
	{
		x *= a_f;
		y *= a_f;
		return *this;
	}

	Vector2 Vector2::operator/(const float& a_f)const
	{
		return Vector2(this->x / a_f, this->y / a_f);
	}

	Vector2& Vector2::operator/=(const float& a_f)
	{
		x /= a_f;
		y /= a_f;
		return *this;
	}

	//Required Methods
	float DotProd(const Vector2& lhs, const Vector2& rhs)
	{
		return (lhs.x * rhs.x) + (lhs.y * rhs.y);
	}

	Vector2 Vector2::PerpCW() const
	{
		Vector2 v2 = *this;
		return v2.Rotate(90 * DEG2RAD);
	}

	Vector2 Vector2::PerpCCW() const
	{
		Vector2 v2 = *this;
		return v2.Rotate(-90 * DEG2RAD);
	}

	Vector2 Vector2::Rotate(const float& a_fRot)
	{
		Vector2 temp = *this;
		Vector2 temp2 = this;
		float sine = sinf(a_fRot);
		float cosine = cosf(a_fRot);
		temp2.x = temp.x * cosine - temp.y * sine;
		temp2.y = temp.y * cosine + temp.x * sine;
		return temp2;
	}


	float Magnitude(const Vector2& v2d)
	{
		return (float)sqrt(v2d.x * v2d.x + v2d.y * v2d.y);
	}

	float Vector2::Magnitude() const
	{
		return (float)sqrt(x * x + y * y);
	}

	float Bearing(const Vector2& v2d)
	{
		return atan2f(v2d.x, v2d.y);
	}

	float Vector2::Bearing() const
	{
		return atan2f(x, y);
	}

	void Vector2::Normalise()
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
	}

	Vector2 Vector2::GetNormalised() const
	{
		float mag = Magnitude();
		return Vector2(x / mag, y / mag);
	}

	void Vector2::Scale(const float& a_fScale)
	{
		x *= a_fScale;
		y *= a_fScale;
	}

	//Extra Methods
	float Angle(const Vector2& lhs, const Vector2& rhs)
	{
		return (float)acos((DotProd(lhs, rhs)) / (lhs.Modulus() * rhs.Modulus()));
	}

	float Vector2::Angle(const Vector2& a_v2d) const
	{
		return (float)acos((DotProd(Vector2(x, y), a_v2d)) / (Vector2(x, y).Modulus() * a_v2d.Modulus()));
	}

	float Distance(const Vector2& lhs, const Vector2& rhs)
	{
		return (float)sqrt(((lhs.x - rhs.x) * (lhs.x - rhs.x)) + ((lhs.y - rhs.y) * (lhs.y - rhs.y)));
	}

	float Vector2::Distance(const Vector2& a_v2d) const
	{
		return (float)sqrt(((x - a_v2d.x) * (x - a_v2d.x)) + ((y - a_v2d.y) * (y - a_v2d.y)));
	}

	float Vector2::Modulus() const
	{
		return (float)sqrt(x * x + y * y);
	}

	Vector2 Vector2::Lerp(const Vector2& destination, const float& a_value) const
	{
		return (Vector2(x, y) * (1 - a_value)) + (destination * a_value);
	}

	void Vector2::Lerp(const Vector2& destination, const float& a_value)
	{
		x = (x * (1 - a_value)) + (destination.x * a_value);
		y = (y * (1 - a_value)) + (destination.y * a_value);
	}

	float Vector2::Slerp(const Vector2& destination, const float& a_value)
	{
		float omega = (float)cos(DotProd(Vector2(this), destination));
		x = x * ((float)(sin(1 - a_value)*omega) / (float)sin(omega)) + destination.x * ((float)sin(a_value * omega)) / (float)sin(omega);
		y = y * ((float)(sin(1 - a_value)*omega) / (float)sin(omega)) + destination.y * ((float)sin(a_value * omega)) / (float)sin(omega);
		return omega;
	}

	std::ostream& operator<<(std::ostream& stream, Vector2& v2)
	{
		stream << "(" << v2.x << ", " << v2.y << ")";
		return stream;
	}

	bool CircleCollision(const Vector2& v2lhs, const float& radiuslhs, const Vector2& v2rhs, const float& radiusrhs)
	{
		if (Distance(v2lhs, v2rhs) <= powf(radiuslhs + radiusrhs, 2))
			return true;
		return false;
	}

	//\===============================================================================================================================
	//\	Distance to a wall with a counter clockwise rotated normal
	//\===============================================================================================================================
	float Vector2::DistToWallCCWNormal(const Vector2& start, const Vector2& end) const
	{
		Vector2 p = start - end;
		p.Normalise();
		Vector2 n = p.PerpCCW();
		Vector2 q = *this - start;
		float d = DotProd(q, n);
		return d;
	}

	Vector2 Vector2::WallCollisionCCWNormal(const Vector2& start, const Vector2& end, const Vector2& dir, const float& bounce) const
	{
		Vector2 p = start - end;
		p.Normalise();
		Vector2 n = p.PerpCCW();
		Vector2 q = *this - start;
		float d = DotProd(q, n);
		if (d < 0.f)
		{
			Vector2 v2 = dir - (1 + bounce) * (DotProd(dir, n) * n);
			v2.Normalise();
			return v2;
		}
		return *this + dir;
	}
}