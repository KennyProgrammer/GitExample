#pragma once

#ifdef FORCEML_SUPPORT_GLM
#include "glm/vec2.hpp"
#endif

#ifdef FORCEML_SUPPORT_CONSTEXPR
#ifndef FE_CONSTEXPR
#define FE_CONSTEXPR constexpr
#endif
#endif

namespace Force::Math
{
	/*Represents a single two-dimensional vector.*/
	template<typename T>
	struct Vector2
	{
		/*The component of the vector.*/
		T x, y;

		//Basic constructors.

		/*Creates a two-dimensional vector.*/
		Vector2() = default;
		Vector2(Vector2 const& v) = default;
		//Vector2(const Vector2<T>& other);
		Vector2(T x, T y);
		Vector2(T scalar);
		Vector2(T* varr);

		//Template implicit constructors.

		//template<typename D>
		//Vector2(D x, D y) : x(static_cast<T>x), y(static_cast<T>y) {};
		//template<typename A, typename B>
		//Vector2(A x, B y) : x(static_cast<T>x), y(static_cast<T>y) {};
		//template<typename D>
		//Vector2(D scalar, D y) : x(static_cast<T>scalar), y(static_cast<T>scalar) {};
		//template<typename D>
		//Vector2(const Vector2<D>& other) : x(static_cast<T>other.x), y(static_cast<T>other.y) {};

		//Operator-accessor
		constexpr T& operator[](uint i) { assert(i >= 0 && i < 2); switch (i) { case 0: return x; case 1: return y; } }
		//Copy-assign operator
		constexpr Vector2<T>& operator=(const Vector2<T>& o) { x = static_cast<T>(o.x); y = static_cast<T>(o.y); return *this; }
		//Scalar operator
		const Vector2<T>& operator=(T scalar) { x = scalar; y = scalar; return *this; }

		static T    dot(const Vector2<T>& a, const Vector2<T>& b);
		T		    dot(const Vector2<T>& v);
		T           angle(const Vector2<T>& v);
		T           square();
		T           square(const Vector2<T>& v);
		T           length();
		T           length(const Vector2<T>& v);
		static T    distance(const Vector2<T>& v1, const Vector2<T>& v2);
		T           distance(const Vector2<T>& v);
		static T    distanceSquared(const Vector2<T>& v1, const Vector2<T>& v2);
		T           distanceSquared(const Vector2<T>& v);
		void        normalize();
		Vector2<T>& normalize(const Vector2<T>& dest);
		void        normalize(T length);
		Vector2<T>& normalize(T length, const Vector2<T>& dest);
		Vector2<T>& negate();
		Vector2<T>& negate(const Vector2<T>& dest);
		Vector2<T>& lerp(const Vector2<T>& other, T factor);
		Vector2<T>& lerp(const Vector2<T>& other, T factor, const Vector2<T>& dest);
		Vector2<T>& fma(T a, const Vector2<T>& b);
		Vector2<T>& fma(T a, const Vector2<T>& b, const Vector2<T>& desc);
		Vector2<T>& fma(const Vector2<T>& a, const Vector2<T>& b, const Vector2<T>& desc);
		int         min();
		Vector2<T>& min(const Vector2<T>& v);
		Vector2<T>& min(const Vector2<T>& v, const Vector2<T>& dest);
		int         max();
		Vector2<T>& max(const Vector2<T>& v);
		Vector2<T>& max(const Vector2<T>& v, const Vector2<T>& dest);
		Vector2<T>& floor();
		Vector2<T>& floor(const Vector2<T>& dest);
		Vector2<T>& ceil();
		Vector2<T>& ceil(const Vector2<T>& dest);
		Vector2<T>& round();
		Vector2<T>& round(const Vector2<T>& dest);
		Vector2<T>& absolute();
		Vector2<T>& absolute(const Vector2<T>& dest);
		Vector2<T>& perpendicular();
		Vector2<T>& zero();
		Vector2<T>& one();
		T* toPtr();

		Vector2<T>& set(T v);
		Vector2<T>& set(T* varr);
		Vector2<T>& set(T x, T y);
		Vector2<T>& set(uint32_t comp, T v);
		Vector2<T>& set(const Vector2<T>& other);
		Vector2<T>& set(Vector2<T>&& other);

		T		   get(uint32_t comp);
		T		   getX();
		T		   getY();

		//Construct this vector from glm::vec2
#ifdef FORCEML_SUPPORT_GLM
		Vector2(const glm::vec2& other) : x(other.x), y(other.y) {}
#endif
	};

	// +=+=+=+=+=+= Getters binary operations (+, -) +=+=+=+=+=+=+= 

	template<typename T>
	inline T operator+(const Vector2<T>& v) { return v.x; } //Gets the first vector value.

	template<typename T>
	inline Vector2<T>& operator-(const Vector2<T>& v) {     //Inverse the vector values.
		return Vector2<T>(-v.x, -v.y); 
	} 

	// +=+=+=+=+=+= Arithmetic binary operations (+, -, /, *, +=, -=, /=, *=) +=+=+=+=+=+=+=

	template<typename T>
	inline Vector2<T> operator+(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x + b.x, a.y + b.y);
	}
	template<typename T>
	inline Vector2<T> operator+(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x + scalar, v.y + scalar);
	}
	template<typename T>
	inline Vector2<T> operator+(T scalar, const Vector2<T>& v) {
		return operator+(v, scalar);
	}

	template<typename T>
	inline Vector2<T> operator-(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x - b.x, a.y - b.y);
	}
	template<typename T>
	inline Vector2<T> operator-(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x - scalar, v.y - scalar);
	}
	template<typename T>
	inline Vector2<T> operator-(T scalar, const Vector2<T>& v) {
		return operator-(v, scalar);
	}

	template<typename T>
	inline Vector2<T> operator*(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x * b.x, a.y * b.y);
	}
	template<typename T>
	inline Vector2<T> operator*(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x * scalar, v.y * scalar);
	}
	template<typename T>
	inline Vector2<T> operator*(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar * v.x, scalar * v.y);
	}

	template<typename T>
	inline Vector2<T> operator/(const Vector2<T>& a, const Vector2<T>& b) {
		return VeVector2ctor<T>(a.x / b.x, a.y / b.y);
	}
	template<typename T>
	inline Vector2<T> operator/(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x / scalar, v.y / scalar);
	}
	template<typename T>
	inline Vector2<T> operator/(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar / v.x, scalar / v.y);
	}

	template<typename T>
	inline Vector2<T> operator+=(const Vector2<T>& a, const Vector2<T>& b) {
		return a = a + b;
	}
	template<typename T>
	inline Vector2<T> operator+=(const Vector2<T>& v, T scalar) {
		return v = v + scalar;
	}
	template<typename T>
	inline Vector2<T> operator+=(T scalar, const Vector2<T>& v) {
		v = scalar + v;
	}

	template<typename T>
	inline Vector2<T> operator-=(const Vector2<T>& a, const Vector2<T>& b) {
		return a = a - b;
	}
	template<typename T>
	inline Vector2<T> operator-=(const Vector2<T>& v, T scalar) {
		return a = v + scalar;
	}
	template<typename T>
	inline Vector2<T> operator-=(T scalar, const Vector2<T>& v) {
		return a = scalar - v;
	}

	template<typename T>
	inline Vector2<T> operator*=(const Vector2<T>& a, const Vector2<T>& b) {
		return a = a * b;
	}
	template<typename T>
	inline Vector2<T> operator*=(const Vector2<T>& v, T scalar) {
		return v = v * scalar;
	}
	template<typename T>
	inline Vector2<T> operator*=(T scalar, const Vector2<T>& v) {
		return v = scalar * v;
	}

	template<typename T>
	inline Vector2<T> operator/=(const Vector2<T>& a, const Vector2<T>& b) {
		return a = a / b;
	}
	template<typename T>
	inline Vector2<T> operator/=(const Vector2<T>& v, T scalar) {
		return v = v / scalar;
	}
	template<typename T>
	inline Vector2<T> operator/=(T scalar, const Vector2<T>& v) {
		return v = scalar / v;
	}

	// +=+=+=+=+=+= Other binary operations (&, ^, |, <<, >>, ~) +=+=+=+=+=+=+=

	template<typename T>
	inline Vector2<T> operator~(const Vector2<T>& v) { return Vector2<T>(~v.x, ~v.y); }
	
	template<typename T>
	inline Vector2<T> operator&(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x & b.x, a.y & b.y);
	}
	template<typename T>
	inline Vector2<T> operator&(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x & scalar, v.y & scalar);
	}
	template<typename T>
	inline Vector2<T> operator&(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar & v.x, scalar & v.y);
	}

	template<typename T>
	inline Vector2<T> operator^(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x ^ b.x, a.y ^ b.y);
	}
	template<typename T>
	inline Vector2<T> operator^(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x ^ scalar, v.y ^ scalar);
	}
	template<typename T>
	inline Vector2<T> operator^(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar ^ v.x, scalar ^ v.y);
	}

	template<typename T>
	inline Vector2<T> operator|(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x | b.x, a.y | b.y);
	}
	template<typename T>
	inline Vector2<T> operator|(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x | scalar, v.y | scalar);
	}
	template<typename T>
	inline Vector2<T> operator|(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar | v.x, scalar | v.y);
	}

	template<typename T>
	inline Vector2<T> operator<<(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x << b.x, a.y << b.y);
	}
	template<typename T>
	inline Vector2<T> operator<<(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x << scalar, v.y << scalar);
	}
	template<typename T>
	inline Vector2<T> operator<<(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar << v.x, scalar << v.y);
	}

	template<typename T>
	inline Vector2<T> operator>>(const Vector2<T>& a, const Vector2<T>& b) {
		return Vector2<T>(a.x >> b.x, a.y >> b.y);
	}
	template<typename T>
	inline Vector2<T> operator>>(const Vector2<T>& v, T scalar) {
		return Vector2<T>(v.x >> scalar, v.y >> scalar);
	}
	template<typename T>
	inline Vector2<T> operator>>(T scalar, const Vector2<T>& v) {
		return Vector2<T>(scalar >> v.x, scalar >> v.y);
	}

	// +=+=+=+=+=+= Boolean operations (&&, ||, !=, ==, >, <) +=+=+=+=+=+=+=

	template<typename T>
	inline bool operator>(const Vector2<T>& a, const Vector2<T>& b) { 
		return a.x > b.x && a.y > b.y; 
	}
	template<typename T>
	inline bool operator>(const Vector2<T>& a, T scalar) { 
		return a.x > value && a.y > scalar; 
	}
	template<typename T>
	inline bool operator>(T scalar, const Vector2<T>& v) { 
		return scalar > v.x && scalar > v.y; 
	}
	
	template<typename T>
	inline bool operator<(const Vector2<T>& a, const Vector2<T>& b) { 
		return a.x < b.x&& a.y < b.y; 
	}
	template<typename T>
	inline bool operator<(const Vector2<T>& a, T scalar) { 
		return a.x < value&& a.y < scalar; 
	}
	template<typename T>
	inline bool operator<(T scalar, const Vector2<T>& v) { 
		return scalar < v.x&& scalar < v.y; 
	}

	template<typename T>
	inline bool operator==(const Vector2<T>& a, const Vector2<T>& b) { return a.x == b.x && a.y == b.y ? 1 : 0; }
	template<typename T>
	inline bool operator!=(const Vector2<T>& a, const Vector2<T>& b) { return !(a == b); }
	template<typename T>
	inline bool operator||(const Vector2<T>& a, const Vector2<T>& b) { return a.x == b.x || a.y == b.y; }
	template<typename T>
	inline bool operator&&(const Vector2<T>& a, const Vector2<T>& b) { return a.x == b.x && a.y == b.y; }

	// Print vector data to output stream.
	template<typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vector2<T> v) { return os << "x: " << v.x << ", y: " << v.y; }

	/*
		Create a two dimensional vector and initialize both of its components with the given
		value.

		@param scalar - the value of both components
	*/
	template<typename T>
	inline Vector2<T>::Vector2(T scalar) : x(scalar), y(scalar) {}

	/*
		Create a new two dimensional vector and initialize its two components from the first
		two elements of the given array.

		@param varr - the array containing at least two elements
	*/
	template<typename T>
	inline Vector2<T>::Vector2(T* varr) : x(varr[0]), y(varr[1]) {}

	/*
		Create a new two dimensional vector initialize its components to the given values.
	*/
	template<typename T>
	inline Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

	/*
		Create a new two dimensional vector and initialize its two components from the
		other reference of vector.

		@param other - to copy the values from other float two dimensional vector.
	*/
	//template<typename T>
	//inline Vector2<T>::Vector2(const Vector2<T>& other) : x(other.x), y(other.y) {}

	/*
		Return pointer to first element in vector.
	*/
	template<typename T>
	inline T* Vector2<T>::toPtr() { return &x; }

	/*
		Set the x, y components to the supplied value.
		@param scalar - the value of both components.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::set(T scalar)
	{
		return operator=(scalar);
	}

	/*
		Set the x, y components from the first two elements of the given array.
		@param varr - the array containing at least two elements
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::set(T* varr)
	{
		this->x = varr[0];
		this->y = varr[1];
		return *this;
	}

	/*
		Set the x, y components to the supplied values.
		@param x, y - components to set.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::set(T x, T y)
	{
		this->x = x; this->y = y;
		return *this;
	}

	/*
		Set the component of this vector from v.
		@param comp - if zero set x, if one set y.
		@param v - value to set.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::set(uint32_t comp, T v)
	{
		switch (comp)
		{
		case 0: this->x = v; break;
		case 1: this->y = v; break;
		}
		return *this;
	}

	/*
		Set the x, y components to the supplied value from integer vector.
		@param other - to copy the values from other integer two dimensional vector.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::set(const Vector2<T>& other)
	{
		this->x = (T)other.x;
		this->y = (T)other.y;
		return *this;
	}
	template<typename T>
	Vector2<T>& Vector2<T>::set(Vector2<T>&& other)
	{
		this->x = std::move(other.x);
		this->y = std::move(other.y);
		return *this;
	}

	/*
		Return the value from component.

		@param comp - if zero return x, if one return y.
	*/
	template<typename T>
	T Vector2<T>::get(uint32_t comp)
	{
		switch (comp)
		{
		case 0: return x;
		case 1: return y;
		default: return 0;
		}
	}

	/*
		Return the x component form this vector.
	*/
	template<typename T>
	inline T Vector2<T>::getX() { return x; }

	/*
		Return the y component form this vector.
	*/
	template<typename T>
	inline T Vector2<T>::getY() { return y; }

	/*
		Return the dot product of two vectors i.e, x[0] * y[0] + x[1] * y[1]... .

		@param a, b - vectors to calculate.
	*/
	template<typename T>
	inline T Vector2<T>::dot(const Vector2<T>& a, const Vector2<T>& b) { return a.x * b.x + a.y * b.y; }

	/*
		Return the dot product of two vectors i.e, x[0] * y[0] + x[1] * y[1]... .

		@param v - vector to calculate.
	*/
	template<typename T>
	inline T Vector2<T>::dot(const Vector2<T>& v) { return dot(*this, v); }

	/*
		Calcualte angle beetween two vectors using determinant, and dot product
		formulas.

		@param v - vector to calculate.
	*/
	template<typename T>
	inline T Vector2<T>::angle(const Vector2<T>& v) { return (T)Math::atan2(this->x * v.x + this->y * v.y, this->x * v.y - this->y * v.x); }

	/*
		Return square representation value from this vector.
	*/
	template<typename T>
	inline T Vector2<T>::square() { return x * x + y * y; };

	/*
		Return square representation value from v vector values.
	*/
	template<typename T>
	inline T Vector2<T>::square(const Vector2<T>& v) { return v.x * v.x + v.y * v.y; };

	/*
		Return the length of a two dimensional vector.
	*/
	template<typename T>
	inline T Vector2<T>::length() { return (T)Math::sqrt(x * x + y * y); };

	/*
		Return the length of a two dimensional vector.

		@param x - the vector to get x, y from.
	*/
	template<typename T>
	inline T Vector2<T>::length(const Vector2<T>& v) { return (T)Math::sqrt(x * v.x + y * v.y); };

	/*
		Return the distance between v1 and v2. /unsafe convertion

		@param v1 - the first vector.
		@param v2 - the second vector.
	*/
	template<typename T>
	T Vector2<T>::distance(const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return distance(v1.x, v1.y, v2.x, v2.y);
	}


	/*
		Return distance beetwen this vector and created vector from
		input x, y values.

		@param v - the vector component.
	*/
	template<typename T>
	T Vector2<T>::distance(const Vector2<T>& v)
	{
		T dx = this->x - v.x;
		T dy = this->y - v.y;
		return Math::sqrt(dx * dx + dy * dy);
	}

	/*
		Return the squared distance between v1 and v2.

		@param v1 - the first vector.
		@param v2 - the second vector.
	*/
	template<typename T>
	T Vector2<T>::distanceSquared(const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return distanceSquared(v1.x, v1.y, v2.x, v2.y);
	}

	/*
		Return distance squared beetwen this vector and created vector from
		input x, y values.

		@param v - the vector component.
	*/
	template<typename T>
	T Vector2<T>::distanceSquared(const Vector2<T>& v)
	{
		T dx = this->x - v.x;
		T dy = this->y - v.y;
		return dx * dx + dy * dy;
	}

	/*
		Normalize this vector.
	 */
	template<typename T>
	void Vector2<T>::normalize()
	{
		T invLength = Math::invsqrt(x * x + y * y);
		this->x = x * invLength;
		this->y = y * invLength;
	}

	/*
		Normalize dest vector use x, y of this vector, and return to dest.

		@param dest - vector to normalize.
	 */
	template<typename T>
	Vector2<T>& Vector2<T>::normalize(const Vector2<T>& dest)
	{
		T invLength = Math::invsqrt(x * x + y * y);
		dest.x = this->x * invLength;
		dest.y = this->y * invLength;
		return dest;
	}

	/*
		Normalized vector and scale it to have the given length.

		@param length - length to scale.
	*/
	template<typename T>
	void Vector2<T>::normalize(T length)
	{
		T invLength = Math::invsqrt(x * x + y * y) * length;
		this->x = x * invLength;
		this->y = y * invLength;
	}

	/*
		Normalized vector and scale it to have the given length.

		@param length - length to scale.
		@parmm dest - vector to return.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::normalize(T length, const Vector2<T>& dest)
	{
		T invLength = Math::invsqrt(x * x + y * y) * length;
		dest.x = x * invLength;
		dest.y = y * invLength;
	}

	/*
		Negate this vector.
	 */
	template<typename T>
	Vector2<T>& Vector2<T>::negate()
	{
		return Vector2<T>(this->x * -1, this->y * -1);
	}

	/*
		Negate this vector.

		@param dest - return negate vector to dest
	 */
	template<typename T>
	Vector2<T>& Vector2<T>::negate(const Vector2<T>& dest)
	{
		return Vector2<T>(dest.x * -1, dest.y * -1);
	}

	/*
		Linearly interpolate <this and 'other' using the given interpolation factor 'factor'
		and store the result in this.

		If 'factor' is 0 then the result is this. If the interpolation factor is 1
		then the result is other.

		@param other - vector to calculate.
		@param factor - the interpolation factor between 0 and 1.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::lerp(const Vector2<T>& other, T factor)
	{
		this->x = x + (other.x - x) * factor;
		this->y = y + (other.y - y) * factor;
		return *this;
	}

	/*
		Version with dest of lerp(const Vector2<T>& other, T factor).
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::lerp(const Vector2<T>& other, T factor, const Vector2<T>& dest)
	{
		dest.x = x + (other.x - x) * factor;
		dest.y = y + (other.y - y) * factor;
		return dest;
	}

	/*
		Add the component-wise multiplication of a * b to this vector.

		@param a - the first multiplicand
		@param b - the second multiplicand
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::fma(T a, const Vector2<T>& b)
	{
		this->x = x + a * b;
		this->y = y + a * b;
		return *this;
	}

	/*
		Add the component-wise multiplication of a * b to dest vector.

		@param a - the first multiplicand
		@param b - the second multiplicand
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::fma(const Vector2<T>& a, const Vector2<T>& b, const Vector2<T>& dest)
	{
		dest.x = this->x + a.x * b.x;
		dest.y = this->y + a.y * b.y;
		return dest;
	}

	/*
		Return min component.
	*/
	template<typename T>
	int Vector2<T>::min()
	{
		if (Math::abs(x) < Math::abs(y)) return 0;
		return 1;
	}

	/*
		Set the components of this vector to be the component-wise minimum of
		this and the other vector.

		@param v - the other vector
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::min(const Vector2<T>& v)
	{
		this->x = x < v.x ? x : v.x;
		this->y = y < v.y ? y : v.y;
		return *this;
	}

	/*
		Set the components of this vector to be the component-wise minimum of
		this and the other vector and return to dest.

		@param v - the other vector
		@param dest - destanation vector
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::min(const Vector2<T>& v, const Vector2<T>& dest)
	{
		dest.x = x < v.x ? x : v.x;
		dest.y = y < v.y ? y : v.y;
		return dest;
	}

	/*
		Set the components of this vector to be the component-wise maximum of
		this and the other vector.

		@param v - the other vector
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::max(const Vector2<T>& v)
	{
		this->x = x > v.x ? x : v.x;
		this->y = y > v.y ? y : v.y;
		return *this;
	}

	/*
		Set the components of this vector to be the component-wise maximum of
		this and the other vector and return to dest.

		@param v - the other vector
		@param dest - destanation vector
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::max(const Vector2<T>& v, const Vector2<T>& dest)
	{
		dest.x = x > v.x ? x : v.x;
		dest.y = y > v.y ? y : v.y;
		return dest;
	}

	/*
		Set each component of this vector to the largest (closest to positive
		infinity) value that is less than or equal to that component and is
		equal to a mathematical integer.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::floor()
	{
		this->x = Math::floor(x);
		this->y = Math::floor(y);
		return *this;
	}

	/*
		Dest version of Vector2<T>::floor().
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::floor(const Vector2<T>& dest)
	{
		dest.x = Math::floor(x);
		dest.y = Math::floor(y);
		return dest;
	}

	/*
		Ceil each component of this vector.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::ceil()
	{
		this->x = Math::ceil(x);
		this->y = Math::ceil(y);
		return *this;
	}

	/*
		Dest version of Vector2<T>::ceil().
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::ceil(const Vector2<T>& dest)
	{
		dest.x = Math::ceil(x);
		dest.y = Math::ceil(y);
		return dest;
	}

	/*
		Set each component of this vector to the closest float that is equal to
		a mathematical integer, with ties rounding to positive infinity.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::round()
	{
		this->x = Math::round(x);
		this->y = Math::round(y);
		return *this;
	}

	/*
		Dest version of Vector2<T>::round().
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::round(const Vector2<T>& dest)
	{
		dest.x = Math::round(x);
		dest.y = Math::round(y);
		return dest;
	}

	/*
		Set this vector's components to their respective absolute values.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::absolute()
	{
		this->x = Math::abs(x);
		this->y = Math::abs(y);
		return *this;
	}

	/*
		Set this vector's components to their respective absolute values.
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::absolute(const Vector2<T>& dest)
	{
		dest.x = Math::abs(x);
		dest.y = Math::abs(y);
		return dest;
	}

	/*
		Return max component.
	*/
	template<typename T>
	int Vector2<T>::max()
	{
		if (abs(x) >= Math::abs(y)) return 0;
		return 1;
	}

	/*
		Add the component-wise multiplication of a * b to dest vector.

		@param a - the first multiplicand
		@param b - the second multiplicand
	*/
	template<typename T>
	Vector2<T>& Vector2<T>::fma(T a, const Vector2<T>& b, const Vector2<T>& dest)
	{
		dest.x = this->x + a * b.x;
		dest.y = this->y + a * b.y;
		return dest;
	}

	/*
		Set this vector to be one of its perpendicular vectors.
	*/
	template<typename T>
	inline Vector2<T>& Vector2<T>::perpendicular() { return this->set(y, x * -1); }

	/*
		Reset this vector to zero.
	*/
	template<typename T>
	inline Vector2<T>& Vector2<T>::zero(){ return this->set(0, 0); }
	
	/*
		Reset this vector to one.
	*/
	template<typename T>
	inline Vector2<T>& Vector2<T>::one() {return this->set(1, 1); }
}

