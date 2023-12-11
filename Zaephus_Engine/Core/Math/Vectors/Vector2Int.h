
#pragma once

#include <cmath>
#include <string>

struct Vector2Int {

    int x;
    int y;

    Vector2Int(int _x) : Vector2Int(_x, _x) {}
    Vector2Int(int _x, int _y) {
        x = _x;
        y = _y;
    }
    Vector2Int(float _x, float _y) {
        x = std::lround(_x);
        y = std::lround(_y);
    }

    inline float magnitude() {
        return sqrt(x*x + y*y);
    }

    inline float squaredMagnitude() {
        return x*x + y*y;
    }

    inline Vector2Int normalized() {
        Vector2Int norm = Vector2Int(x, y);
        norm.normalize();
        return norm;
    }

    inline void normalize() {
        *this /= magnitude();
    }

    static inline float distance(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return sqrt(((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x)) + ((_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)));
    }

    static inline float dot(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y;
    }

    static inline float cross(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return _lhs.y * _rhs.x - _lhs.x * _rhs.y;
    }

    static inline float angle(Vector2Int& _from, Vector2Int& _to) {
        float d = dot(_from, _to);
        return acos(d / (_from.magnitude() * _to.magnitude()));
    }

    inline std::string toString() {
        return std::to_string(x) + ", " + std::to_string(y);
    }

    inline Vector2Int& operator+=(const Vector2Int& _v) {
        this->x += _v.x;
        this->y += _v.y;
        return *this;
    }
    friend Vector2Int operator+(Vector2Int _lhs, const Vector2Int& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    inline Vector2Int& operator-=(Vector2Int _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        return *this;
    }
    friend Vector2Int operator-(Vector2Int _lhs, const Vector2Int& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    inline Vector2Int operator-() {
        this->x = -this->x;
        this->y = -this->y;
        return *this;
    }

    inline Vector2Int& operator*=(float _s) {
        this->x *= _s;
        this->y *= _s;
        return *this;
    }
    friend Vector2Int operator*(Vector2Int _v, float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector2Int operator*(float _s, Vector2Int _v) {
        _v *= _s;
        return _v;
    }

    inline Vector2Int& operator/=(float _s) {
        this->x /= _s;
        this->y /= _s;
        return *this;
    }
    friend Vector2Int operator/(Vector2Int _v, float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
    }
    friend bool operator!=(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return !(_lhs == _rhs);
    }

    static inline Vector2Int zero()    { return Vector2Int(0, 0); }
    static inline Vector2Int one()     { return Vector2Int(1, 1); }
    static inline Vector2Int right()   { return Vector2Int(1, 0); }
    static inline Vector2Int left()    { return Vector2Int(-1, 0); }
    static inline Vector2Int up()      { return Vector2Int(0, 1); }
    static inline Vector2Int down()    { return Vector2Int(0, -1); }

};