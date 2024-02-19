
#pragma once

#include <cmath>
#include <string>

struct Vector2Int {

    int x;
    int y;

    Vector2Int() {
        *this = zero();
    }

    explicit Vector2Int(const int _x) : Vector2Int(_x, _x) {}
    Vector2Int(const int _x, const int _y) {
        x = _x;
        y = _y;
    }
    Vector2Int(const float _x, const float _y) {
        x = std::lround(_x);
        y = std::lround(_y);
    }

    Vector2Int(const Vector2Int& _v) {
        x = _v.x;
        y = _v.y;
    }

    [[nodiscard]] float magnitude() const {
        return std::sqrt(static_cast<float>(x * x + y * y));
    }

    [[nodiscard]] float squaredMagnitude() const {
        return static_cast<float>(x*x + y*y);
    }

    [[nodiscard]] Vector2Int normalized() const {
        Vector2Int norm = Vector2Int(x, y);
        norm.normalize();
        return norm;
    }

    void normalize() {
        *this /= magnitude();
    }

    static float distance(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return std::sqrt(static_cast<float>((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y)));
    }

    static float dot(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return static_cast<float>(_lhs.x * _rhs.x + _lhs.y * _rhs.y);
    }

    static float cross(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return static_cast<float>(_lhs.y * _rhs.x - _lhs.x * _rhs.y);
    }

    static float angle(const Vector2Int& _from, const Vector2Int& _to) {
        const float d = dot(_from, _to);
        return std::acos(d / (_from.magnitude() * _to.magnitude()));
    }

    [[nodiscard]] std::string toString() const {
        return std::to_string(x) + ", " + std::to_string(y);
    }

    Vector2Int& operator+=(const Vector2Int& _v) {
        this->x += _v.x;
        this->y += _v.y;
        return *this;
    }
    friend Vector2Int operator+(Vector2Int _lhs, const Vector2Int& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Vector2Int& operator-=(const Vector2Int& _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        return *this;
    }
    friend Vector2Int operator-(Vector2Int _lhs, const Vector2Int& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Vector2Int operator-() {
        this->x = -this->x;
        this->y = -this->y;
        return *this;
    }

    Vector2Int& operator*=(const float _s) {
        this->x *= _s;
        this->y *= _s;
        return *this;
    }
    friend Vector2Int operator*(Vector2Int _v, const float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector2Int operator*(const float _s, Vector2Int _v) {
        _v *= _s;
        return _v;
    }

    Vector2Int& operator/=(const float _s) {
        this->x /= _s;
        this->y /= _s;
        return *this;
    }
    friend Vector2Int operator/(Vector2Int _v, const float _s) {
        _v /= _s;
        return _v;
    }

    friend bool operator==(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
    }
    friend bool operator!=(const Vector2Int& _lhs, const Vector2Int& _rhs) {
        return !(_lhs == _rhs);
    }

    static Vector2Int zero()    { return { 0, 0 }; }
    static Vector2Int one()     { return { 1, 1 }; }
    static Vector2Int right()   { return { 1, 0 }; }
    static Vector2Int left()    { return { -1, 0 }; }
    static Vector2Int up()      { return { 0, 1 }; }
    static Vector2Int down()    { return { 0, -1 }; }

};