
#pragma once

#include <cmath>
#include <format>
#include <string>

struct Vector2 {

    float x;
    float y;

    Vector2() {
        *this = zero();
    }

    explicit Vector2(const float _x) : Vector2(_x, _x) {}
    Vector2(const float _x, const float _y) {
        x = _x;
        y = _y;
    }

    Vector2(const Vector2& _v) {
        x = _v.x;
        y = _v.y;
    }

    [[nodiscard]] float magnitude() const {
        return std::sqrt(x*x + y*y);
    }

    [[nodiscard]] float squaredMagnitude() const {
        return x*x + y*y;
    }

    [[nodiscard]] Vector2 normalized() const {
        Vector2 norm = Vector2(x, y);
        norm.normalize();
        return norm;
    }

    void normalize() {
        *this /= magnitude();
    }

    static float distance(const Vector2& _lhs, const Vector2& _rhs) {
        return std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y));
    }

    static float dot(const Vector2& _lhs, const Vector2& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y;
    }

    static float cross(const Vector2& _lhs, const Vector2& _rhs) {
        return _lhs.y * _rhs.x - _lhs.x * _rhs.y;
    }

    static float angle(const Vector2& _from, const Vector2& _to) {
        const float delta = dot(_from, _to);
        return std::acos(delta / (_from.magnitude() * _to.magnitude()));
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {}", x, y);
    }

    Vector2& operator+=(const Vector2& _v) {
        this->x += _v.x;
        this->y += _v.y;
        return *this;
    }
    friend Vector2 operator+(Vector2 _lhs, const Vector2& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Vector2& operator-=(const Vector2& _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        return *this;
    }
    friend Vector2 operator-(Vector2 _lhs, const Vector2& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Vector2 operator-() {
        this->x = -this->x;
        this->y = -this->y;
        return *this;
    }

    Vector2& operator*=(const float _s) {
        this->x *= _s;
        this->y *= _s;
        return *this;
    }
    friend Vector2 operator*(Vector2 _v, const float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector2 operator*(const float _s, Vector2 _v) {
        _v *= _s;
        return _v;
    }

    Vector2& operator/=(const float _s) {
        this->x /= _s;
        this->y /= _s;
        return *this;
    }
    friend Vector2 operator/(Vector2 _v, const float _s) {
        _v /= _s;
        return _v;
    }

    Vector2& operator=(const Vector2& _v) = default;

    friend bool operator==(const Vector2& _lhs, const Vector2& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
    }
    friend bool operator!=(const Vector2& _lhs, const Vector2& _rhs) {
        return !(_lhs == _rhs);
    }

    float operator[](const size_t _i) const {
        switch(_i) {
            case 0:
                return x;
            case 1:
                return y;
            default:
                throw std::out_of_range("Invalid index.");
        }
    }

    static Vector2 zero()    { return { 0.0f,  0.0f }; }
    static Vector2 one()     { return { 1.0f,  1.0f }; }
    static Vector2 right()   { return { 1.0f,  0.0f }; }
    static Vector2 left()    { return { -1.0f, 0.0f }; }
    static Vector2 up()      { return { 0.0f,  1.0f }; }
    static Vector2 down()    { return { 0.0f, -1.0f }; }

};