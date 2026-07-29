#pragma once

typedef float hkReal;
namespace RE
{
	class hkVector4f
	{
	public:
		__declspec(align(16)) hkReal x;
		hkReal y;
		hkReal z;
		hkReal w;
		hkVector4f()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		};
		hkVector4f(NiPoint3 p)
		{
			x = p.x;
			y = p.y;
			z = p.z;
			w = 0.0f;
		}
		hkVector4f(float _x, float _y, float _z, float _w = 0.0f)
		{
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}
		hkVector4f& operator=(const hkVector4f& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = v.w;
			return *this;
		}
		hkVector4f operator+(const hkVector4f& v)
		{
			return hkVector4f(x + v.x, y + v.y, z + v.z);
		}
		hkVector4f& operator+=(const hkVector4f& v)
		{
			this->x += v.x;
			this->y += v.y;
			this->z += v.z;
			this->w += v.w;
			return *this;
		}
		hkVector4f operator-(const hkVector4f& v)
		{
			return hkVector4f(x - v.x, y - v.y, z - v.z);
		}
		hkVector4f operator-()
		{
			return hkVector4f(x * -1.0f, y * -1.0f, z * -1.0f);
		}
		hkVector4f& operator-=(const hkVector4f& v)
		{
			this->x -= v.x;
			this->y -= v.y;
			this->z -= v.z;
			this->w -= v.w;
			return *this;
		}
		hkVector4f operator*(float a)
		{
			return hkVector4f(x * a, y * a, z * a, w * a);
		}
		hkVector4f& operator*=(float a)
		{
			this->x *= a;
			this->y *= a;
			this->z *= a;
			this->w *= a;
			return *this;
		}
		hkVector4f operator*(const hkVector4f& v)
		{
			return hkVector4f(x * v.x, y * v.y, z * v.z, w * v.w);
		}
		hkVector4f& operator*=(const hkVector4f& v)
		{
			this->x *= v.x;
			this->y *= v.y;
			this->z *= v.z;
			this->w *= v.w;
			return *this;
		}
		hkVector4f operator/(float a)
		{
			return hkVector4f(x / a, y / a, z / a);
		}
		hkVector4f& operator/=(float a)
		{
			this->x /= a;
			this->y /= a;
			this->z /= a;
			this->w /= a;
			return *this;
		}
		hkVector4f operator/(const hkVector4f& v)
		{
			return hkVector4f(x / v.x, y / v.y, z / v.z, w / v.w);
		}
		hkVector4f& operator/=(const hkVector4f& v)
		{
			this->x /= v.x;
			this->y /= v.y;
			this->z /= v.z;
			this->w /= v.w;
			return *this;
		}
		float Length()
		{
			return sqrt(x * x + y * y + z * z);
		}
		hkVector4f& Normalize()
		{
			float l = Length();
			if (l == 0) {
				this->x = 0;
				this->y = 0;
				this->z = 0;
				return *this;
			}
			this->x /= l;
			this->y /= l;
			this->z /= l;
			return *this;
		}
		hkVector4f GetNormalized()
		{
			hkVector4f norm = *this;
			norm.Normalize();
			return norm;
		}
		float Dot(const hkVector4f& v)
		{
			return this->x * v.x + this->y * v.y + this->z * v.z;
		}
		operator NiPoint3()
		{
			return NiPoint3(x, y, z);
		}
	};
	static_assert(sizeof(hkVector4f) == 0x10);
};
