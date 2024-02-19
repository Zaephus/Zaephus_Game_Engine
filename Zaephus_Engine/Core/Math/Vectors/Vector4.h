
#pragma once

#include <cmath>
#include <format>
#include <string>
#include <stdexcept>

struct Vector4 {

    float x;
    float y;
    float z;
    float w;

    Vector4() {
        *this = zero();
    }

    explicit Vector4(const float _x) : Vector4(_x, _x, _x, _x) {}
    Vector4(const float _x, const float _y, const float _z, const float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    Vector4(const Vector4& _v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
        w = _v.w;
    }

    [[nodiscard]] float magnitude() const {
        return std::sqrt(x*x + y*y + z*z + w*w);
    }

    [[nodiscard]] float squaredMagnitude() const {
        return x*x + y*y + z*z + w*w;
    }

    [[nodiscard]] Vector4 normalized() const {
        Vector4 norm = Vector4(x, y, z, w);
        norm.normalize();
        return norm;
    }

    void normalize() {
        *this /= magnitude();
    }

    static float distance(const Vector4& _lhs, const Vector4& _rhs) {
        return std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y) + (_rhs.z - _lhs.z) * (_rhs.z - _lhs.z) + (_rhs.w - _lhs.w) * (_rhs.w - _lhs.w));
    }

    static float dot(const Vector4& _lhs, const Vector4& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
    }

    static float angle(const Vector4& _from, const Vector4& _to) {
        const float delta = dot(_from, _to);
        return std::acos(delta / (_from.magnitude() * _to.magnitude()));
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {}, {}, {}", x, y, z, w);
    }

    Vector4& operator+=(const Vector4& _v) {
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

    Vector4& operator-=(const Vector4& _v) {
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
    Vector4 operator-() const {
        return -1 * *this;
    }

    Vector4& operator*=(const float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        this->w *= _s;
        return *this;
    }
    friend Vector4 operator*(Vector4 _v, const float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector4 operator*(const float _s, Vector4 _v) {
        _v *= _s;
        return _v;
    }

    Vector4& operator/=(const float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        this->w /= _s;
        return *this;
    }
    friend Vector4 operator/(Vector4 _v, const float _s) {
        _v /= _s;
        return _v;
    }

    Vector4& operator=(const Vector4& _v) = default;

    friend bool operator==(const Vector4& _lhs, const Vector4& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
    }
    friend bool operator!=(const Vector4& _lhs, const Vector4& _rhs) {
        return !(_lhs == _rhs);
    }

    float operator[](const size_t _i) const {
        switch(_i) {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
            default:
                throw std::out_of_range("Invalid index.");
        }
    }

    static Vector4 zero()    { return { 0.0f, 0.0f, 0.0f, 0.0f }; }
    static Vector4 one()     { return { 1.0f, 1.0f, 1.0f, 1.0f }; }

};