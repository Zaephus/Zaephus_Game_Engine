
#pragma once

#include <cmath>
#include <string>

struct Vector3Int {

    int x;
    int y;
    int z;

    Vector3Int(int _x) : Vector3Int(_x, _x, _x) {}
    Vector3Int(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    Vector3Int(float _x, float _y, float _z) {
        x = std::lround(_x);
        y = std::lround(_y);
        z = std::lround(_z);
    }

    inline float magnitude() {
        return sqrt(x*x + y*y + z*z);
    }

    inline float squaredMagnitude() {
        return x*x + y*y + z*z;
    }

    inline Vector3Int normalized() {
        Vector3Int norm = Vector3Int(x, y, z);
        norm.normalize();
        return norm;
    }

    inline void normalize() {
        *this /= magnitude();
    }

    static inline float distance(const Vector3Int& _lhs, const Vector3Int& _rhs) {
        return sqrt(((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x)) + ((_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)) + ((_rhs.z - _lhs.z) * (_rhs.z - _lhs.z)));
    }

    static inline float dot(const Vector3Int& _lhs, const Vector3Int& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;
    }

    static inline Vector3Int cross(const Vector3Int& _lhs, const Vector3Int& _rhs) {
        return Vector3Int(
            _lhs.y * _rhs.z - _lhs.z * _rhs.y,
            _lhs.z * _rhs.x - _lhs.x * _rhs.z,
            _lhs.x * _rhs.y - _lhs.y * _rhs.x
        );
    }

    static inline float angle(Vector3Int& _from, Vector3Int& _to) {
        float d = dot(_from, _to);
        return acos(d / (_from.magnitude() * _to.magnitude()));
    }

    inline std::string toString() {
        return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
    }

    inline Vector3Int& operator+=(const Vector3Int& _v) {
        this->x += _v.x;
        this->y += _v.y;
        this->z += _v.z;
        return *this;
    }
    friend Vector3Int operator+(Vector3Int _lhs, const Vector3Int& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    inline Vector3Int& operator-=(Vector3Int _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        this->z -= _v.z;
        return *this;
    }
    friend Vector3Int operator-(Vector3Int _lhs, const Vector3Int& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    inline Vector3Int operator-() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        return *this;
    }

    inline Vector3Int& operator*=(float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        return *this;
    }
    friend Vector3Int operator*(Vector3Int _v, float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector3Int operator*(float _s, Vector3Int _v) {
        _v *= _s;
        return _v;
    }

    inline Vector3Int& operator/=(float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        return *this;
    }
    friend Vector3Int operator/(Vector3Int _v, float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector3Int& _lhs, const Vector3Int& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z;
    }
    friend bool operator!=(const Vector3Int& _lhs, const Vector3Int& _rhs) {
        return !(_lhs == _rhs);
    }

    static inline Vector3Int zero()    { return Vector3Int(0, 0, 0); }
    static inline Vector3Int one()     { return Vector3Int(1, 1, 1); }
    static inline Vector3Int right()   { return Vector3Int(1, 0, 0); }
    static inline Vector3Int left()    { return Vector3Int(-1, 0, 0); }
    static inline Vector3Int up()      { return Vector3Int(0, 1, 0); }
    static inline Vector3Int down()    { return Vector3Int(0, -1, 0); }
    static inline Vector3Int forward() { return Vector3Int(0, 0, 1); }
    static inline Vector3Int back()    { return Vector3Int(0, 0, -1); }

};