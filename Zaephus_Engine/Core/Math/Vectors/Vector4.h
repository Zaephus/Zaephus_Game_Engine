
#pragma once

#include <cmath>
#include <string>

struct Vector4 {

    float x;
    float y;
    float z;
    float w;

    Vector4(float _x) : Vector4(_x, _x, _x, _x) {}
    Vector4(float _x, float _y, float _z, float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    inline float magnitude() {
        return sqrt(x*x + y*y + z*z + w*w);
    }

    inline float squaredMagnitude() {
        return x*x + y*y + z*z + w*w;
    }

    inline Vector4 normalized() {
        Vector4 norm = Vector4(x, y, z, w);
        norm.normalize();
        return norm;
    }

    inline void normalize() {
        *this /= magnitude();
    }

    static inline float distance(const Vector4& _lhs, const Vector4& _rhs) {
        return sqrt(((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x)) + ((_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)) + ((_rhs.z - _lhs.z) * (_rhs.z - _lhs.z)) + ((_rhs.w - _lhs.w) * (_rhs.w - _lhs.w)));
    }

    static inline float dot(const Vector4& _lhs, const Vector4& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
    }

    static inline float angle(Vector4& _from, Vector4& _to) {
        float d = dot(_from, _to);
        return acos(d / (_from.magnitude() * _to.magnitude()));
    }

    inline std::string toString() {
        return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
    }

    inline Vector4& operator+=(const Vector4& _v) {
        this->x += _v.x;
        this->y += _v.y;
        this->z += _v.z;
        this->w += _v.w;
        return *this;
    }
    friend Vector4 operator+(Vector4 _lhs, const Vector4& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    inline Vector4& operator-=(Vector4 _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        this->z -= _v.z;
        this->w -= _v.w;
        return *this;
    }
    friend Vector4 operator-(Vector4 _lhs, const Vector4& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    inline Vector4 operator-() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        this->w = -this->w;
        return *this;
    }

    inline Vector4& operator*=(float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        this->w *= _s;
        return *this;
    }
    friend Vector4 operator*(Vector4 _v, float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector4 operator*(float _s, Vector4 _v) {
        _v *= _s;
        return _v;
    }

    inline Vector4& operator/=(float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        this->w *= _s;
        return *this;
    }
    friend Vector4 operator/(Vector4 _v, float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector4& _lhs, const Vector4& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
    }
    friend bool operator!=(const Vector4& _lhs, const Vector4& _rhs) {
        return !(_lhs == _rhs);
    }

    static inline Vector4 zero()    { return Vector4(0.0f, 0.0f, 0.0f, 0.0f); }
    static inline Vector4 one()     { return Vector4(1.0f, 1.0f, 1.0f, 1.0f); }

};