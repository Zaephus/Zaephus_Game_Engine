
#pragma once

#include <cmath>
#include <string>

struct Vector4Int {

    int x;
    int y;
    int z;
    int w;

    Vector4Int(int _x) : Vector4Int(_x, _x, _x, _x) {}
    Vector4Int(int _x, int _y, int _z, int _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }
    Vector4Int(float _x, float _y, float _z, float _w) {
        x = std::lround(_x);
        y = std::lround(_y);
        z = std::lround(_z);
        w = std::lround(_w);
    }

    inline float magnitude() {
        return sqrt(x*x + y*y + z*z + w*w);
    }

    inline float squaredMagnitude() {
        return x*x + y*y + z*z + w*w;
    }

    inline Vector4Int normalized() {
        Vector4Int norm = Vector4Int(x, y, z, w);
        norm.normalize();
        return norm;
    }

    inline void normalize() {
        *this /= magnitude();
    }

    static inline float distance(const Vector4Int& _lhs, const Vector4Int& _rhs) {
        return sqrt(((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x)) + ((_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)) + ((_rhs.z - _lhs.z) * (_rhs.z - _lhs.z)) + ((_rhs.w - _lhs.w) * (_rhs.w - _lhs.w)));
    }

    static inline float dot(const Vector4Int& _lhs, const Vector4Int& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
    }

    static inline float angle(Vector4Int& _from, Vector4Int& _to) {
        float d = dot(_from, _to);
        return acos(d / (_from.magnitude() * _to.magnitude()));
    }

    inline std::string toString() {
        return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
    }

    inline Vector4Int& operator+=(const Vector4Int& _v) {
        this->x += _v.x;
        this->y += _v.y;
        this->z += _v.z;
        this->w += _v.w;
        return *this;
    }
    friend Vector4Int operator+(Vector4Int _lhs, const Vector4Int& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    inline Vector4Int& operator-=(Vector4Int _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        this->z -= _v.z;
        this->w -= _v.w;
        return *this;
    }
    friend Vector4Int operator-(Vector4Int _lhs, const Vector4Int& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    inline Vector4Int operator-() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        this->w = -this->w;
        return *this;
    }

    inline Vector4Int& operator*=(float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        this->w *= _s;
        return *this;
    }
    friend Vector4Int operator*(Vector4Int _v, float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector4Int operator*(float _s, Vector4Int _v) {
        _v *= _s;
        return _v;
    }

    inline Vector4Int& operator/=(float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        this->w *= _s;
        return *this;
    }
    friend Vector4Int operator/(Vector4Int _v, float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector4Int& _lhs, const Vector4Int& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
    }
    friend bool operator!=(const Vector4Int& _lhs, const Vector4Int& _rhs) {
        return !(_lhs == _rhs);
    }

    static inline Vector4Int zero() { return Vector4Int(0, 0, 0, 0); }
    static inline Vector4Int one()  { return Vector4Int(1, 1, 1, 1); }

};