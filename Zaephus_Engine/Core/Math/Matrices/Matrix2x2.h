
#pragma once

#include <iostream>
#include <format>
#include <stdexcept>
#include <string>

#include "../Vectors/Vector2.h"

struct Matrix2x2 {

    float m00 = 0, m01 = 0;
    float m10 = 0, m11 = 0;

    Matrix2x2() {
        *this = identity();
    }

    explicit Matrix2x2(const float _m[2][2]) {
        m00 = _m[0][0]; m01 = _m[0][1];
        m10 = _m[1][0]; m11 = _m[1][1];
    }

    Matrix2x2(
        const float _m00, const float _m01,
        const float _m10, const float _m11
    ) {
        m00 = _m00; m01 = _m01;
        m10 = _m10; m11 = _m11;
    }

    Matrix2x2(const Vector2& _row0, const Vector2& _row1) {
        m00 = _row0.x; m01 = _row0.y;
        m10 = _row1.x; m11 = _row1.y;
    }

    [[nodiscard]] Vector2 getRow(const size_t _index) const {
        switch(_index) {
            case 0:
                return { m00, m01 };
            case 1:
                return { m10, m11 };
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    void setRow(const size_t _index, const Vector2& _row) {
        switch(_index) {
            case 0:
                m00 = _row.x; m01 = _row.y;
                break;
            case 1:
                m10 = _row.x; m11 = _row.y;
                break;
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    [[nodiscard]] Vector2 getColumn(const size_t _index) const {
        switch(_index) {
            case 0:
                return { m00, m10 };
            case 1:
                return { m01, m11 };
            default:
                throw std::out_of_range("Invalid column index.");
        }
    }

    void setColumn(const size_t _index, const Vector2& _column) {
        switch(_index) {
            case 0:
                m00 = _column.x; m10 = _column.y;
                break;
            case 1:
                m01 = _column.x; m11 = _column.y;
                break;
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    [[nodiscard]] Matrix2x2 inverse() const {
        Matrix2x2 i = *this;
        i.invert();
        return i;
    }

    void invert() {

        if(determinant() == 0) {
            std::cout << "Determinant is zero, this matrix cannot be inverted." << std::endl;
            return;
        }

        const Matrix2x2 adjugate = {
            m11, -m01,
            -m10, m00
        };

        *this = adjugate / determinant();

    }

    [[nodiscard]] Matrix2x2 transposed() const {
        Matrix2x2 t = *this;
        t.transpose();
        return t;
    }

    void transpose() {
        *this = {
            m00, m10,
            m01, m11
        };
    }

    [[nodiscard]] float determinant() const {
        return m00 * m11 - m01 * m10;
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {},\n{}, {}", m00, m01, m10, m11);
    }

    Matrix2x2& operator+=(const Matrix2x2& _m) {
        this->m00 += _m.m00; this->m01 += _m.m01;
        this->m10 += _m.m10; this->m11 += _m.m11;
        return *this;
    }
    friend Matrix2x2 operator+(Matrix2x2 _lhs, const Matrix2x2& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Matrix2x2& operator-=(const Matrix2x2& _m) {
        this->m00 -= _m.m00; this->m01 -= _m.m01;
        this->m10 -= _m.m10; this->m11 -= _m.m11;
        return *this;
    }
    friend Matrix2x2 operator-(Matrix2x2 _lhs, const Matrix2x2& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Matrix2x2 operator-() const {
        return -1 * *this;
    }

    Matrix2x2 operator*=(const Matrix2x2& _m) const {
        return {
            this->m00 * _m.m00 + this->m01 * _m.m10,
            this->m00 * _m.m01 + this->m01 * _m.m11,

            this->m10 * _m.m00 + this->m11 * _m.m10,
            this->m10 * _m.m01 + this->m11 * _m.m11
        };
    }
    friend Matrix2x2 operator*(Matrix2x2 _lhs, const Matrix2x2& _rhs) {
        _lhs *= _rhs;
        return _lhs;
    }

    Vector2 operator*=(const Vector2& _v) const {
        return {
            this->m00 * _v.x + this->m01 * _v.y,
            this->m10 * _v.x + this->m11 * _v.y
        };
    }
    friend Matrix2x2 operator*(Matrix2x2 _m, const Vector2& _v) {
        _m *= _v;
        return _m;
    }

    Matrix2x2& operator*=(const float _s) {
        this->m00 *= _s; this->m01 *= _s;
        this->m10 *= _s; this->m11 *= _s;
        return *this;
    }
    friend Matrix2x2 operator*(Matrix2x2 _m, const float _s) {
        _m *= _s;
        return _m;
    }
    friend Matrix2x2 operator*(const float _s, Matrix2x2 _m) {
        _m *= _s;
        return _m;
    }

    Matrix2x2& operator/=(const float _s) {
        this->m00 /= _s; this->m01 /= _s;
        this->m10 /= _s; this->m11 /= _s;
        return *this;
    }
    friend Matrix2x2 operator/(Matrix2x2 _m, const float _s) {
        _m /= _s;
        return _m;
    }

    Matrix2x2& operator=(const Matrix2x2 _m) {
        this->m00 = _m.m00; this->m01 = _m.m01;
        this->m10 = _m.m10; this->m11 = _m.m11;
        return *this;
    }

    friend bool operator==(const Matrix2x2& _lhs, const Matrix2x2& _rhs) {
        for(size_t x = 0; x < 2; x++) {
            for(size_t y = 0; y < 2; y++) {
                if(_lhs[x][y] != _rhs[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }
    friend bool operator!=(const Matrix2x2& _lhs, const Matrix2x2& _rhs) {
        return !(_lhs == _rhs);
    }

    Vector2 operator[](const size_t _i) const {
        return getRow(_i);
    }

    static Matrix2x2 zero() {
        return {
            0, 0,
            0, 0
        };
    }

    static Matrix2x2 one() {
        return {
            1, 1,
            1, 1
        };
    }

    static Matrix2x2 identity() {
        return {
            1, 0,
            0, 1
        };
    }

};