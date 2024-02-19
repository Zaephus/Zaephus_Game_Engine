
#pragma once

#include <cmath>
#include <format>
#include <string>

struct Vector3 {

    float x;
    float y;
    float z;

    Vector3() {
        *this = zero();
    }

    explicit Vector3(const float _x) : Vector3(_x, _x, _x) {}
    Vector3(const float _x, const float _y, const float _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vector3(const Vector3 &_v) {
        x = _v.x;
        y = _v.y;
        z = _v.z;
    }

    [[nodiscard]] float magnitude() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    [[nodiscard]] float squaredMagnitude() const {
        return x*x + y*y + z*z;
    }

    [[nodiscard]] Vector3 normalized() const {
        Vector3 norm = Vector3(x, y, z);
        norm.normalize();
        return norm;
    }

    void normalize() {
        *this /= magnitude();
    }

    static float distance(const Vector3& _lhs, const Vector3& _rhs) {
        return std::sqrt((_rhs.x - _lhs.x) * (_rhs.x - _lhs.x) + (_rhs.y - _lhs.y) * (_rhs.y - _lhs.y) + (_rhs.z - _lhs.z) * (_rhs.z - _lhs.z));
    }

    static float dot(const Vector3& _lhs, const Vector3& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z;
    }

    static Vector3 cross(const Vector3& _lhs, const Vector3& _rhs) {
        return {
            _lhs.y * _rhs.z - _lhs.z * _rhs.y,
            _lhs.z * _rhs.x - _lhs.x * _rhs.z,
            _lhs.x * _rhs.y - _lhs.y * _rhs.x
        };
    }

    static float angle(Vector3 const& _from, Vector3 const& _to) {
        const float delta = dot(_from, _to);
        return std::acos(delta / (_from.magnitude() * _to.magnitude()));
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {}, {}", x, y, z);
    }

    Vector3& operator+=(const Vector3& _v) {
        this->x += _v.x;
        this->y += _v.y;
        this->z += _v.z;
        return *this;
    }
    friend Vector3 operator+(Vector3 _lhs, const Vector3& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Vector3& operator-=(const Vector3& _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        this->z -= _v.z;
        return *this;
    }
    friend Vector3 operator-(Vector3 _lhs, const Vector3& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Vector3 operator-() const {
        return -1 * *this;
    }

    Vector3& operator*=(const float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        return *this;
    }
    friend Vector3 operator*(Vector3 _v, const float _s) {
        _v *= _s;
        return _v;
    }
    friend Vector3 operator*(const float _s, Vector3 _v) {
        _v *= _s;
        return _v;
    }

    Vector3& operator/=(const float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        return *this;
    }
    friend Vector3 operator/(Vector3 _v, const float _s) {
        _v /= _s;
        return _v;
    }

    Vector3& operator=(const Vector3& _v) = default;

    friend bool operator==(const Vector3& _lhs, const Vector3& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z;
    }
    friend bool operator!=(const Vector3& _lhs, const Vector3& _rhs) {
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
            default:
                throw std::out_of_range("Invalid index.");
        }
    }

    static Vector3 zero()    { return { 0.0f,  0.0f,  0.0f  }; }
    static Vector3 one()     { return { 1.0f,  1.0f,  1.0f  }; }
    static Vector3 right()   { return { 1.0f,  0.0f,  0.0f  }; }
    static Vector3 left()    { return { -1.0f, 0.0f,  0.0f  }; }
    static Vector3 up()      { return { 0.0f,  1.0f,  0.0f  }; }
    static Vector3 down()    { return { 0.0f,  -1.0f, 0.0f  }; }
    static Vector3 forward() { return { 0.0f,  0.0f,  1.0f  }; }
    static Vector3 back()    { return { 0.0f,  0.0f,  -1.0f }; }

};