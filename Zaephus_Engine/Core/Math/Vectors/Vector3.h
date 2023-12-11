
#pragma once

#include <cmath>
#include <string>

struct Vector3 {

    float x;
    float y;
    float z;

    Vector3(float _x) : Vector3(_x, _x, _x) {}
    Vector3(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    inline float magnitude() {
        return sqrt(x*x + y*y + z*z);
    }

    inline float squaredMagnitude() {
        return x*x + y*y + z*z;
    }

    inline Vector3 normalized() {
        Vector3 norm = Vector3(x, y, z);
        norm.normalize();
        return norm;
    }

    inline void normalize() {
        *this /= magnitude();
    }

    static inline float distance(const Vector3& _lhs, const Vector3& _rhs) {
        return sqrt(((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x)) + ((_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)) + ((_rhs.z - _lhs.z) * (_rhs.z - _lhs.z)));
    }

    static inline float dot(const Vector3& _lhs, const Vector3& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;
    }

    static inline Vector3 cross(const Vector3& _lhs, const Vector3& _rhs) {
        return Vector3(
            _lhs.y * _rhs.z - _lhs.z * _rhs.y,
            _lhs.z * _rhs.x - _lhs.x * _rhs.z,
            _lhs.x * _rhs.y - _lhs.y * _rhs.x
        );
    }

    static inline float angle(Vector3& _from, Vector3& _to) {
        float d = dot(_from, _to);
        return acos(d / (_from.magnitude() * _to.magnitude()));
    }

    inline std::string toString() {
        return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
    }

    inline Vector3& operator+=(const Vector3& _v) {
        this->x += _v.x;
        this->y += _v.y;
        this->z += _v.z;
        return *this;
    }
    friend Vector3 operator+(Vector3 _lhs, const Vector3& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    inline Vector3& operator-=(Vector3 _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        this->z -= _v.z;
        return *this;
    }
    friend Vector3 operator-(Vector3 _lhs, const Vector3& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    inline Vector3 operator-() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        return *this;
    }

    inline Vector3& operator*=(float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        return *this;
    }
    friend Vector3 operator*(Vector3 _v, float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector3 operator*(float _s, Vector3 _v) {
        _v *= _s;
        return _v;
    }

    inline Vector3& operator/=(float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        return *this;
    }
    friend Vector3 operator/(Vector3 _v, float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector3& _lhs, const Vector3& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z;
    }
    friend bool operator!=(const Vector3& _lhs, const Vector3& _rhs) {
        return !(_lhs == _rhs);
    }

    static inline Vector3 zero()    { return Vector3(0.0f, 0.0f, 0.0f); }
    static inline Vector3 one()     { return Vector3(1.0f, 1.0f, 1.0f); }
    static inline Vector3 right()   { return Vector3(1.0f, 0.0f, 0.0f); }
    static inline Vector3 left()    { return Vector3(-1.0f, 0.0f, 0.0f); }
    static inline Vector3 up()      { return Vector3(0.0f, 1.0f, 0.0f); }
    static inline Vector3 down()    { return Vector3(0.0f, -1.0f, 0.0f); }
    static inline Vector3 forward() { return Vector3(0.0f, 0.0f, 1.0f); }
    static inline Vector3 back()    { return Vector3(0.0f, 0.0f, -1.0f); }

};