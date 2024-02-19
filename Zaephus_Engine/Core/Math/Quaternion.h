
#pragma once

#include <cmath>
#include <format>
#include <string>
#include <stdexcept>

#include "Vectors/Vector3.h"
#include "MathHelper.h"

struct Quaternion {

    float x;
    float y;
    float z;
    float w;

    explicit Quaternion(const float _x) : Quaternion(_x, _x, _x, _x) {}
    Quaternion(const float _x, const float _y, const float _z, const float _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    [[nodiscard]] float magnitude() const {
        return dot(*this, *this);
    }

    [[nodiscard]] Quaternion normalized() const {
        Quaternion norm = Quaternion(x, y, z, w);
        norm.normalize();
        return norm;
    }

    void normalize() {
        const float mag = magnitude();
        if(mag == 0) {
            *this = identity();
            return;
        }
        *this /= mag;
    }

    static float dot(const Quaternion& _lhs, const Quaternion& _rhs) {
        return _lhs.x * _rhs.x + _lhs.y * _rhs.y + _lhs.z * _rhs.z + _lhs.w * _rhs.w;
    }

    static Quaternion fromAxisAngle(const Vector3& _axis, const float _angleRad) {
        const Vector3 axis = _axis.normalized();
        return {
            axis.x * std::sin(_angleRad * 0.5f),
            axis.y * std::sin(_angleRad * 0.5f),
            axis.z * std::sin(_angleRad * 0.5f),
            std::cos(_angleRad * 0.5f)
        };
    }

    static Quaternion fromEuler(const float _xDeg, const float _yDeg, const float _zDeg) {
        return fromEuler({ _xDeg, _yDeg, _zDeg });
    }

    static Quaternion fromEuler(const Vector3& _eulerDeg) {
        const Vector3 euler = _eulerDeg * Math::deg2rad;
        return {
            std::sin(euler.x * 0.5f) * std::cos(euler.y * 0.5f) * std::cos(euler.z * 0.5f) - std::cos(euler.x * 0.5f) * std::sin(euler.y * 0.5f) * std::sin(euler.z * 0.5f),
            std::cos(euler.x * 0.5f) * std::sin(euler.y * 0.5f) * std::cos(euler.z * 0.5f) - std::sin(euler.x * 0.5f) * std::cos(euler.y * 0.5f) * std::sin(euler.z * 0.5f),
            std::cos(euler.x * 0.5f) * std::cos(euler.y * 0.5f) * std::sin(euler.z * 0.5f) - std::sin(euler.x * 0.5f) * std::sin(euler.y * 0.5f) * std::cos(euler.z * 0.5f),
            std::cos(euler.x * 0.5f) * std::cos(euler.y * 0.5f) * std::cos(euler.z * 0.5f) - std::sin(euler.x * 0.5f) * std::sin(euler.y * 0.5f) * std::sin(euler.z * 0.5f)
        };
    }

    [[nodiscard]] Vector3 toEuler() const {
        return toEuler(*this);
    }

    static Vector3 toEuler(const Quaternion& _q) {

        float x = 0;
        const float y = std::asin(2 * (_q.w * _q.y - _q.x * _q.z));
        float z;

        if(y == std::numbers::pi * 0.5f) {
            z = -2 * std::atan2(_q.x, _q.w);
        }
        else if(y == -std::numbers::pi * 0.5f) {
            z = 2 * std::atan2(_q.x, _q.w);
        }
        else {
            x = std::atan2(2 * (_q.w * _q.x + _q.y * _q.z), _q.w * _q.w - _q.x * _q.x - _q.y * _q.y + _q.z * _q.z);
            z = std::atan2(2 * (_q.w * _q.z + _q.x * _q.y), _q.w * _q.w + _q.x * _q.x - _q.y * _q.y - _q.z * _q.z);
        }

        return Vector3(x, y, z) * Math::rad2deg;

    }

    static float angleBetween(const Quaternion& _lhs, const Quaternion& _rhs) {
        const float dot = Quaternion::dot(_lhs, _rhs);
        return std::acos(dot / (_lhs.magnitude() * _rhs.magnitude()));
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {}, {}, {}", x, y, z, w);
    }

    Quaternion& operator+=(const Quaternion& _v) {
        this->x += _v.x;
        this->y += _v.y;
        this->z += _v.z;
        this->w += _v.w;
        return *this;
    }
    friend Quaternion operator+(Quaternion _lhs, const Quaternion& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Quaternion& operator-=(const Quaternion _v) {
        this->x -= _v.x;
        this->y -= _v.y;
        this->z -= _v.z;
        this->w -= _v.w;
        return *this;
    }
    friend Quaternion operator-(Quaternion _lhs, const Quaternion& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Quaternion operator-() const {
        return -1 * *this;
    }

    friend Vector3 operator*(const Quaternion& _q, const Vector3& _v) {
        const Quaternion rotInverse = { -_q.x, -_q.y, -_q.z, _q.w };
        const Quaternion vecQ = { _v.x, _v.y, _v.z, 0.0f };

        const Quaternion result = _q * vecQ * rotInverse;

        return { result.x , result.y, result.z };
    }

    Quaternion operator*=(const Quaternion& _q) const {
        return {
            this->w * _q.x + this->x * _q.w + this->y * _q.z - this->z * _q.y,
            this->w * _q.y + this->y * _q.w + this->z * _q.x - this->x * _q.z,
            this->w * _q.z + this->z * _q.w + this->x * _q.y - this->y * _q.x,
            this->w * _q.w - this->x * _q.x - this->y * _q.y - this->z * _q.z
        };
    }

    friend Quaternion operator*(const Quaternion& _lhs, const Quaternion& _rhs) {
        return {
            _lhs.w * _rhs.x + _lhs.x * _rhs.w + _lhs.y * _rhs.z - _lhs.z * _rhs.y,
            _lhs.w * _rhs.y + _lhs.y * _rhs.w + _lhs.z * _rhs.x - _lhs.x * _rhs.z,
            _lhs.w * _rhs.z + _lhs.z * _rhs.w + _lhs.x * _rhs.y - _lhs.y * _rhs.x,
            _lhs.w * _rhs.w - _lhs.x * _rhs.x - _lhs.y * _rhs.y - _lhs.z * _rhs.z
        };
    }

    Quaternion& operator*=(const float _s) {
        this->x *= _s;
        this->y *= _s;
        this->z *= _s;
        this->w *= _s;
        return *this;
    }
    friend Quaternion operator*(Quaternion _v, const float _s) {
        _v *= _s;
        return _v;
    }
    friend Quaternion operator*(const float _s, Quaternion _v) {
        _v *= _s;
        return _v;
    }

    Quaternion& operator/=(const float _s) {
        this->x /= _s;
        this->y /= _s;
        this->z /= _s;
        this->w /= _s;
        return *this;
    }
    friend Quaternion operator/(Quaternion _v, const float _s) {
        _v /= _s;
        return _v;
    }

    Quaternion& operator=(const Quaternion _v) {
        this->x = _v.x;
        this->y = _v.y;
        this->z = _v.z;
        this->w = _v.w;
        return *this;
    }

    friend bool operator==(const Quaternion& _lhs, const Quaternion& _rhs) {
        return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
    }
    friend bool operator!=(const Quaternion& _lhs, const Quaternion& _rhs) {
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

    static Quaternion identity()    { return { 0.0f, 0.0f, 0.0f, 1.0f }; }

};