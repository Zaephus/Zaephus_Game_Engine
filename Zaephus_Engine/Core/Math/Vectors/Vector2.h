
#pragma once

#include <cmath>
#include <string>

struct Vector2 {

    float x;
    float y;

    Vector2(float _x) : Vector2(_x, _x) {}
    Vector2(float _x, float _y) {
        x = _x;
        y = _y;
    }

    inline float magnitude() {
        return sqrt(x*x + y*y);
    }

    inline float squaredMagnitude() {
        return x*x + y*y;
    }

    inline Vector2 normalized() {
        Vector2 norm = Vector2(x, y);
        norm.normalize();
        return norm;
    }

    inline void normalize() {
        *this /= magnitude();
    }

    static inline float distance(const Vector2& _lhs, const Vector2& _rhs) {
        return sqrt(((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x)) + ((_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)));
    }

    static inline float dot(const Vector2& _lhs, const Vector2& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y;
    }

    static inline float cross(const Vector2& _lhs, const Vector2& _rhs) {
        return _lhs.y * _rhs.x - _lhs.x * _rhs.y;
    }

    static inline float angle(Vector2& _from, Vector2& _to) {
        float d = dot(_from, _to);
        return acos(d / (_from.magnitude() * _to.magnitude()));
    }

    inline std::string toString() {
        return std::to_string(x) + ", " + std::to_string(y);
    }

    inline Vector2& operator+=(const Vector2& _v) {
        this->x += _v.x;
        this->y += _v.y;
        return *this;
    }
    friend Vector2 operator+(Vector2 _lhs, const Vector2& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    inline Vector2& operator-=(Vector2 _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        return *this;
    }
    friend Vector2 operator-(Vector2 _lhs, const Vector2& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    inline Vector2 operator-() {
        this->x = -this->x;
        this->y = -this->y;
        return *this;
    }

    inline Vector2& operator*=(float _s) {
        this->x *= _s;
        this->y *= _s;
        return *this;
    }
    friend Vector2 operator*(Vector2 _v, float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector2 operator*(float _s, Vector2 _v) {
        _v *= _s;
        return _v;
    }

    inline Vector2& operator/=(float _s) {
        this->x /= _s;
        this->y /= _s;
        return *this;
    }
    friend Vector2 operator/(Vector2 _v, float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector2& _lhs, const Vector2& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
    }
    friend bool operator!=(const Vector2& _lhs, const Vector2& _rhs) {
        return !(_lhs == _rhs);
    }

    static inline Vector2 zero()    { return Vector2(0.0f, 0.0f); }
    static inline Vector2 one()     { return Vector2(1.0f, 1.0f); }
    static inline Vector2 right()   { return Vector2(1.0f, 0.0f); }
    static inline Vector2 left()    { return Vector2(-1.0f, 0.0f); }
    static inline Vector2 up()      { return Vector2(0.0f, 1.0f); }
    static inline Vector2 down()    { return Vector2(0.0f, -1.0f); }

};