
#pragma once

#include <iostream>
#include <format>
#include <stdexcept>
#include <string>

#include "../Vectors/Vector3.h"

struct Matrix3x3 {

    float m00 = 0, m01 = 0, m02 = 0;
    float m10 = 0, m11 = 0, m12 = 0;
    float m20 = 0, m21 = 0, m22 = 0;

    Matrix3x3() {
        *this = identity();
    }

    explicit Matrix3x3(const float _m[3][3]) {
        m00 = _m[0][0]; m01 = _m[0][1]; m02 = _m[0][2];
        m10 = _m[1][0]; m11 = _m[1][1]; m12 = _m[1][2];
        m20 = _m[2][0]; m21 = _m[2][1]; m22 = _m[2][2];
    }

    Matrix3x3(
        const float _m00, const float _m01, const float _m02,
        const float _m10, const float _m11, const float _m12,
        const float _m20, const float _m21, const float _m22
    ) {
        m00 = _m00; m01 = _m01; m02 = _m02;
        m10 = _m10; m11 = _m11; m12 = _m12;
        m20 = _m20; m21 = _m21; m22 = _m22;
    }

    Matrix3x3(const Vector3& _row0, const Vector3& _row1, const Vector3& _row2) {
        m00 = _row0.x; m01 = _row0.y; m02 = _row0.z;
        m10 = _row1.x; m11 = _row1.y; m12 = _row1.z;
        m20 = _row2.x; m21 = _row2.y; m22 = _row2.z;
    }

    [[nodiscard]] Vector3 getRow(const size_t _index) const {
        switch(_index) {
            case 0:
                return { m00, m01, m02 };
            case 1:
                return { m10, m11, m12 };
            case 2:
                return { m20, m21, m22 };
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    void setRow(const size_t _index, const Vector3& _row) {
        switch(_index) {
            case 0:
                m00 = _row.x; m01 = _row.y; m02 = _row.z;
                break;
            case 1:
                m10 = _row.x; m11 = _row.y; m12 = _row.z;
                break;
            case 2:
                m20 = _row.x; m21 = _row.y; m22 = _row.z;
                break;
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    [[nodiscard]] Vector3 getColumn(const size_t _index) const {
        switch(_index) {
            case 0:
                return { m00, m10, m20 };
            case 1:
                return { m01, m11, m21 };
            case 2:
                return { m02, m12, m22 };
            default:
                throw std::out_of_range("Invalid column index.");
        }
    }

    void setColumn(const size_t _index, const Vector3& _column) {
        switch(_index) {
            case 0:
                m00 = _column.x; m10 = _column.y; m20 = _column.z;
                break;
            case 1:
                m01 = _column.x; m11 = _column.y; m21 = _column.z;
                break;
            case 2:
                m02 = _column.x; m12 = _column.y; m22 = _column.z;
                break;
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    [[nodiscard]] Matrix3x3 inverse() const {
        Matrix3x3 i = *this;
        i.invert();
        return i;
    }

    void invert() {

        if(determinant() == 0) {
            std::cout << "Determinant is zero, this matrix cannot be inverted." << std::endl;
            return;
        }

        const float a00 = m11*m22 - m12*m21;
        const float a01 = m10*m22 - m12*m20;
        const float a02 = m10*m21 - m11*m20;

        const float a10 = m01*m22 - m02*m21;
        const float a11 = m00*m22 - m02*m20;
        const float a12 = m00*m21 - m01*m20;

        const float a20 = m01*m12 - m02*m11;
        const float a21 = m00*m12 - m02*m10;
        const float a22 = m00*m11 - m01*m10;

        Matrix3x3 adjugate = {
            a00, -a01, a02,
            -a10, a11, -a12,
            a20, -a21, a22
        };
        adjugate.transpose();

        *this = adjugate / determinant();

    }

    [[nodiscard]] Matrix3x3 transposed() const {
        Matrix3x3 t = *this;
        t.transpose();
        return t;
    }

    void transpose() {
        *this = {
            m00, m10, m20,
            m01, m11, m21,
            m02, m12, m22
        };
    }

    [[nodiscard]] float determinant() const {
        const float d1 = m11*m22 - m12*m21;
        const float d2 = m10*m22 - m12*m20;
        const float d3 = m10*m21 - m11*m20;

        return m00*d1 - m01*d2 + m02*d3;
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {}, {},\n{}, {}, {},\n{}, {}, {}", m00, m01, m02, m10, m11, m12, m20, m21, m22);
    }

    Matrix3x3& operator+=(const Matrix3x3& _m) {
        this->m00 += _m.m00; this->m01 += _m.m01; this->m02 += _m.m02;
        this->m10 += _m.m10; this->m11 += _m.m11; this->m12 += _m.m12;
        this->m20 += _m.m20; this->m21 += _m.m21; this->m22 += _m.m22;
        return *this;
    }
    friend Matrix3x3 operator+(Matrix3x3 _lhs, const Matrix3x3& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Matrix3x3& operator-=(const Matrix3x3& _m) {
        this->m00 -= _m.m00; this->m01 -= _m.m01; this->m02 -= _m.m02;
        this->m10 -= _m.m10; this->m11 -= _m.m11; this->m12 -= _m.m12;
        this->m20 -= _m.m20; this->m21 -= _m.m21; this->m22 -= _m.m22;
        return *this;
    }
    friend Matrix3x3 operator-(Matrix3x3 _lhs, const Matrix3x3& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Matrix3x3 operator-() const {
        return -1 * *this;
    }

    Matrix3x3 operator*=(const Matrix3x3& _m) const {
        return {
            this->m00 * _m.m00 + this->m01 * _m.m10 + this->m02 * _m.m20,
            this->m00 * _m.m01 + this->m01 * _m.m11 + this->m02 * _m.m21,
            this->m00 * _m.m02 + this->m01 * _m.m12 + this->m02 * _m.m22,

            this->m10 * _m.m00 + this->m11 * _m.m10 + this->m12 * _m.m20,
            this->m10 * _m.m01 + this->m11 * _m.m11 + this->m12 * _m.m21,
            this->m10 * _m.m02 + this->m11 * _m.m12 + this->m12 * _m.m22,

            this->m20 * _m.m00 + this->m21 * _m.m10 + this->m22 * _m.m20,
            this->m20 * _m.m01 + this->m21 * _m.m11 + this->m22 * _m.m21,
            this->m20 * _m.m02 + this->m21 * _m.m12 + this->m22 * _m.m22
        };
    }
    friend Matrix3x3 operator*(Matrix3x3 _lhs, const Matrix3x3& _rhs) {
        _lhs *= _rhs;
        return _lhs;
    }

    Vector3 operator*=(const Vector3& _v) const {
        return {
            this->m00 * _v.x + this->m01 * _v.y + this->m02 * _v.z,
            this->m10 * _v.x + this->m11 * _v.y + this->m12 * _v.z,
            this->m20 * _v.x + this->m21 * _v.y + this->m22 * _v.z
        };
    }
    friend Matrix3x3 operator*(Matrix3x3 _m, const Vector3& _v) {
        _m *= _v;
        return _m;
    }

    Matrix3x3& operator*=(const float _s) {
        this->m00 *= _s; this->m01 *= _s; this->m02 *= _s;
        this->m10 *= _s; this->m11 *= _s; this->m12 *= _s;
        this->m20 *= _s; this->m21 *= _s; this->m22 *= _s;
        return *this;
    }
    friend Matrix3x3 operator*(Matrix3x3 _m, const float _s) {
        _m *= _s;
        return _m;
    }
    friend Matrix3x3 operator*(const float _s, Matrix3x3 _m) {
        _m *= _s;
        return _m;
    }

    Matrix3x3& operator/=(const float _s) {
        this->m00 /= _s; this->m01 /= _s; this->m02 /= _s;
        this->m10 /= _s; this->m11 /= _s; this->m12 /= _s;
        this->m20 /= _s; this->m21 /= _s; this->m22 /= _s;
        return *this;
    }
    friend Matrix3x3 operator/(Matrix3x3 _m, const float _s) {
        _m /= _s;
        return _m;
    }

    Matrix3x3& operator=(const Matrix3x3 _m) {
        this->m00 = _m.m00; this->m01 = _m.m01; this->m02 = _m.m02;
        this->m10 = _m.m10; this->m11 = _m.m11; this->m12 = _m.m12;
        this->m20 = _m.m20; this->m21 = _m.m21; this->m22 = _m.m22;
        return *this;
    }

    friend bool operator==(const Matrix3x3& _lhs, const Matrix3x3& _rhs) {
        for(size_t x = 0; x < 3; x++) {
            for(size_t y = 0; y < 3; y++) {
                if(_lhs[x][y] != _rhs[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }
    friend bool operator!=(const Matrix3x3& _lhs, const Matrix3x3& _rhs) {
        return !(_lhs == _rhs);
    }

    Vector3 operator[](const size_t _i) const {
        return getRow(_i);
    }

    static Matrix3x3 zero() {
        return {
            0, 0, 0,
            0, 0, 0,
            0, 0, 0
        };
    }

    static Matrix3x3 one() {
        return {
            1, 1, 1,
            1, 1, 1,
            1, 1, 1
        };
    }

    static Matrix3x3 identity() {
        return {
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };
    }

};