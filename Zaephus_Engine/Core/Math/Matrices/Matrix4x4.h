
#pragma once

#include <iostream>
#include <format>
#include <stdexcept>
#include <string>

#include "../Quaternion.h"
#include "../Vectors/Vector4.h"

struct Matrix4x4 {

    float m00 = 0, m01 = 0, m02 = 0, m03 = 0;
    float m10 = 0, m11 = 0, m12 = 0, m13 = 0;
    float m20 = 0, m21 = 0, m22 = 0, m23 = 0;
    float m30 = 0, m31 = 0, m32 = 0, m33 = 0;

    Matrix4x4() {
        *this = identity();
    }

    explicit Matrix4x4(const float _m[4][4]) {
        m00 = _m[0][0]; m01 = _m[1][0]; m02 = _m[2][0]; m03 = _m[3][0];
        m10 = _m[0][1]; m11 = _m[1][1]; m12 = _m[2][1]; m13 = _m[3][1];
        m20 = _m[0][2]; m21 = _m[1][2]; m22 = _m[2][2]; m23 = _m[3][2];
        m30 = _m[0][3]; m31 = _m[1][3]; m32 = _m[2][3]; m33 = _m[3][3];
    }

    Matrix4x4(
        const float _m00, const float _m01, const float _m02, const float _m03,
        const float _m10, const float _m11, const float _m12, const float _m13,
        const float _m20, const float _m21, const float _m22, const float _m23,
        const float _m30, const float _m31, const float _m32, const float _m33
    ) {
        m00 = _m00; m01 = _m01; m02 = _m02; m03 = _m03;
        m10 = _m10; m11 = _m11; m12 = _m12; m13 = _m13;
        m20 = _m20; m21 = _m21; m22 = _m22; m23 = _m23;
        m30 = _m30; m31 = _m31; m32 = _m32; m33 = _m33;
    }

    Matrix4x4(const Vector4& _row0, const Vector4& _row1, const Vector4& _row2, const Vector4& _row3) {
        m00 = _row0.x; m01 = _row0.y; m02 = _row0.z; m03 = _row0.w;
        m10 = _row1.x; m11 = _row1.y; m12 = _row1.z; m13 = _row1.w;
        m20 = _row2.x; m21 = _row2.y; m22 = _row2.z; m23 = _row2.w;
        m30 = _row3.x; m31 = _row3.y; m32 = _row3.z; m33 = _row3.w;
    }

    [[nodiscard]] Vector4 getRow(const size_t _index) const {
        switch(_index) {
            case 0:
                return { m00, m01, m02, m03 };
            case 1:
                return { m10, m11, m12, m13 };
            case 2:
                return { m20, m21, m22, m23 };
            case 3:
                return { m30, m31, m32, m33 };
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    void setRow(const size_t _index, const Vector4& _row) {
        switch(_index) {
            case 0:
                m00 = _row.x; m01 = _row.y; m02 = _row.z; m03 = _row.w;
                break;
            case 1:
                m10 = _row.x; m11 = _row.y; m12 = _row.z; m13 = _row.w;
                break;
            case 2:
                m20 = _row.x; m21 = _row.y; m22 = _row.z; m23 = _row.w;
                break;
            case 3:
                m30 = _row.x; m31 = _row.y; m32 = _row.z; m33 = _row.w;
                break;
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    [[nodiscard]] Vector4 getColumn(const size_t _index) const {
        switch(_index) {
            case 0:
                return { m00, m10, m20, m30 };
            case 1:
                return { m01, m11, m21, m31 };
            case 2:
                return { m02, m12, m22, m32 };
            case 3:
                return { m03, m13, m23, m33 };
            default:
                throw std::out_of_range("Invalid column index.");
        }
    }

    void setColumn(const size_t _index, const Vector4& _column) {
        switch(_index) {
            case 0:
                m00 = _column.x; m10 = _column.y; m20 = _column.z; m30 = _column.w;
                break;
            case 1:
                m01 = _column.x; m11 = _column.y; m21 = _column.z; m31 = _column.w;
                break;
            case 2:
                m02 = _column.x; m12 = _column.y; m22 = _column.z; m32 = _column.w;
                break;
            case 3:
                m03 = _column.x; m13 = _column.y; m23 = _column.z; m33 = _column.w;
                break;
            default:
                throw std::out_of_range("Invalid row index.");
        }
    }

    [[nodiscard]] Matrix4x4 inverse() const {
        Matrix4x4 i = *this;
        i.invert();
        return i;
    }

    void invert() {

        if(determinant() == 0) {
            std::cout << "Determinant is zero, this matrix cannot be inverted." << std::endl;
            return;
        }

        Matrix3x3 a00 = {
            m11, m12, m13,
            m21, m22, m23,
            m31, m32, m33
        };
        Matrix3x3 a01 = {
            m10, m12, m13,
            m20, m22, m23,
            m30, m32, m33
        };
        Matrix3x3 a02 = {
            m10, m11, m13,
            m20, m21, m23,
            m30, m31, m33
        };
        Matrix3x3 a03 = {
            m10, m11, m12,
            m20, m21, m22,
            m30, m31, m32
        };
        Matrix3x3 a10 = {
            m01, m02, m03,
            m21, m22, m23,
            m31, m32, m33
        };
        Matrix3x3 a11 = {
            m00, m02, m03,
            m20, m22, m23,
            m30, m32, m33
        };
        Matrix3x3 a12 = {
            m00, m01, m03,
            m20, m21, m23,
            m30, m31, m33
        };
        Matrix3x3 a13 = {
            m00, m01, m02,
            m20, m21, m22,
            m30, m31, m32
        };
        Matrix3x3 a20 = {
            m01, m02, m03,
            m11, m12, m13,
            m31, m32, m33
        };
        Matrix3x3 a21 = {
            m00, m02, m03,
            m10, m12, m13,
            m30, m32, m33
        };
        Matrix3x3 a22 = {
            m00, m01, m03,
            m10, m11, m13,
            m30, m31, m33
        };
        Matrix3x3 a23 = {
            m00, m01, m02,
            m10, m11, m12,
            m30, m31, m32
        };
        Matrix3x3 a30 = {
            m01, m02, m03,
            m11, m12, m13,
            m21, m22, m23
        };
        Matrix3x3 a31 = {
            m00, m02, m03,
            m10, m12, m13,
            m20, m22, m23
        };
        Matrix3x3 a32 = {
            m00, m01, m03,
            m10, m11, m13,
            m20, m21, m23
        };
        Matrix3x3 a33 = {
            m00, m01, m02,
            m10, m11, m12,
            m20, m21, m22
        };

        Matrix4x4 adjugate = {
            a00.determinant(), -a01.determinant(), a02.determinant(), -a03.determinant(),
            -a10.determinant(), a11.determinant(), -a12.determinant(), a13.determinant(),
            a20.determinant(), -a21.determinant(), a22.determinant(), -a23.determinant(),
            -a30.determinant(), a31.determinant(), -a32.determinant(), a33.determinant()
        };
        adjugate.transpose();

        *this = adjugate / determinant();

    }

    [[nodiscard]] Matrix4x4 transposed() const {
        Matrix4x4 t = *this;
        t.transpose();
        return t;
    }

    void transpose() {
        *this = {
            m00, m10, m20, m30,
            m01, m11, m21, m31,
            m02, m12, m22, m32,
            m03, m13, m23, m33
        };
    }

    [[nodiscard]] float determinant() const {
        const float d1 = m11*m22*m33 + m12*m23*m31 + m13*m21*m32 - m13*m22*m31 - m12*m21*m33 - m11*m23*m32;
        const float d2 = m01*m22*m33 + m02*m23*m31 + m03*m21*m32 - m03*m22*m31 - m02*m21*m33 - m01*m23*m32;
        const float d3 = m01*m12*m33 + m02*m13*m31 + m03*m11*m32 - m03*m12*m31 - m02*m11*m33 - m01*m13*m32;
        const float d4 = m01*m12*m23 + m02*m13*m21 + m03*m11*m33 - m03*m12*m21 - m02*m11*m23 - m01*m13*m22;

        return m00*d1 - m10*d2 + m20*d3 - m30*d4;
    }

    static Matrix4x4 scaleMatrix(Vector3 _v) {
        return {
            _v.x, 0, 0, 0,
            0, _v.y, 0, 0,
            0, 0, _v.z, 0,
            0, 0, 0, 1
        };
    }

    static Matrix4x4 translateMatrix(Vector3 _v) {
        return {
            1, 0, 0, _v.x,
            0, 1, 0, _v.y,
            0, 0, 1, _v.z,
            0, 0, 0, 1
        };
    }

    static Matrix4x4 rotateMatrix(const Quaternion& _q) {

        if(_q == Quaternion(0, 0, 0, 0)) {
            return identity();
        }

        return {
            _q.w * _q.w + _q.x * _q.x - _q.y * _q.y - _q.z * _q.z,
            2 * _q.x * _q.y - 2 * _q.w * _q.z,
            2 * _q.x * _q.z + 2 * _q.w * _q.y,
            0.0f,

            2 * _q.x * _q.y + 2 * _q.w * _q.z,
            _q.w * _q.w - _q.x * _q.x + _q.y * _q.y - _q.z * _q.z,
            2 * _q.y * _q.z - 2 * _q.w * _q.x,
            0.0f,

            2 * _q.x * _q.z - 2 * _q.w * _q.y,
            2 * _q.y * _q.z + 2 * _q.w * _q.x,
            _q.w * _q.w - _q.x * _q.x - _q.y * _q.y + _q.z * _q.z,
            0.0f,

            0.0f,
            0.0f,
            0.0f,
            1.0f
        };
    }

    // TODO: Lookat and perspective matrices are temporary.

    static Matrix4x4 lookAt(const Vector3& _pos, const Vector3& _up, const Vector3& _center) {

        const Vector3 f = (_center - _pos).normalized();
        const Vector3 r = Vector3::cross(f, _up).normalized();
        const Vector3 u = Vector3::cross(r, f);

        const Matrix4x4 d = {
            r.x, r.y, r.z, 0.0f,
            u.x, u.y, u.z, 0.0f,
            -f.x, -f.y, -f.z, 0.0f,  // TODO: -forward is temporary.
            _pos.x, _pos.y, _pos.z, 1.0f
        };

        return d.inverse();

    }

    static Matrix4x4 perspective(const float _fovY, const float _aspect, const float _near, const float _far) {

        const float f = std::tan(0.5f * _fovY);

        const float a = _aspect / f;
        const float b = 1.0f / f;

        const float c = _far / (_far - _near);
        const float d = -(_far * _near / (_far - _near));

        return {
            a, 0.0f, 0.0f, 0.0f,
            0.0f, -b, 0.0f, 0.0f,
            0.0f, 0.0f, -c, -1.0f,
            0.0f, 0.0f, d, 0.0f
        };
    }

    [[nodiscard]] std::string toString() const {
        return std::format("{}, {}, {}, {},\n{}, {}, {}, {},\n{}, {}, {}, {},\n{}, {}, {}, {}", m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33);
    }

    Matrix4x4& operator+=(const Matrix4x4& _m) {
        this->m00 += _m.m00; this->m01 += _m.m01; this->m02 += _m.m02; this->m03 += _m.m03;
        this->m10 += _m.m10; this->m11 += _m.m11; this->m12 += _m.m12; this->m13 += _m.m13;
        this->m20 += _m.m20; this->m21 += _m.m21; this->m22 += _m.m22; this->m23 += _m.m23;
        this->m30 += _m.m30; this->m31 += _m.m31; this->m32 += _m.m32; this->m33 += _m.m33;
        return *this;
    }
    friend Matrix4x4 operator+(Matrix4x4 _lhs, const Matrix4x4& _rhs) {
        _lhs += _rhs;
        return _lhs;
    }

    Matrix4x4& operator-=(const Matrix4x4& _m) {
        this->m00 -= _m.m00; this->m01 -= _m.m01; this->m02 -= _m.m02; this->m03 -= _m.m03;
        this->m10 -= _m.m10; this->m11 -= _m.m11; this->m12 -= _m.m12; this->m13 -= _m.m13;
        this->m20 -= _m.m20; this->m21 -= _m.m21; this->m22 -= _m.m22; this->m23 -= _m.m23;
        this->m30 -= _m.m30; this->m31 -= _m.m31; this->m32 -= _m.m32; this->m33 -= _m.m33;
        return *this;
    }
    friend Matrix4x4 operator-(Matrix4x4 _lhs, const Matrix4x4& _rhs) {
        _lhs -= _rhs;
        return _lhs;
    }
    Matrix4x4 operator-() const {
        return -1 * *this;
    }

    Matrix4x4 operator*=(const Matrix4x4& _m) const {
        return {
            this->m00 * _m.m00 + this->m01 * _m.m10 + this->m02 * _m.m20 + this->m03 * _m.m30,
            this->m00 * _m.m01 + this->m01 * _m.m11 + this->m02 * _m.m21 + this->m03 * _m.m31,
            this->m00 * _m.m02 + this->m01 * _m.m12 + this->m02 * _m.m22 + this->m03 * _m.m32,
            this->m00 * _m.m03 + this->m01 * _m.m13 + this->m02 * _m.m23 + this->m03 * _m.m33,

            this->m10 * _m.m00 + this->m11 * _m.m10 + this->m12 * _m.m20 + this->m13 * _m.m30,
            this->m10 * _m.m01 + this->m11 * _m.m11 + this->m12 * _m.m21 + this->m13 * _m.m31,
            this->m10 * _m.m02 + this->m11 * _m.m12 + this->m12 * _m.m22 + this->m13 * _m.m32,
            this->m10 * _m.m03 + this->m11 * _m.m13 + this->m12 * _m.m23 + this->m13 * _m.m33,

            this->m20 * _m.m00 + this->m21 * _m.m10 + this->m22 * _m.m20 + this->m23 * _m.m30,
            this->m20 * _m.m01 + this->m21 * _m.m11 + this->m22 * _m.m21 + this->m23 * _m.m31,
            this->m20 * _m.m02 + this->m21 * _m.m12 + this->m22 * _m.m22 + this->m23 * _m.m32,
            this->m20 * _m.m03 + this->m21 * _m.m13 + this->m22 * _m.m23 + this->m23 * _m.m33,

            this->m30 * _m.m00 + this->m31 * _m.m10 + this->m32 * _m.m20 + this->m33 * _m.m30,
            this->m30 * _m.m01 + this->m31 * _m.m11 + this->m32 * _m.m21 + this->m33 * _m.m31,
            this->m30 * _m.m02 + this->m31 * _m.m12 + this->m32 * _m.m22 + this->m33 * _m.m32,
            this->m30 * _m.m03 + this->m31 * _m.m13 + this->m32 * _m.m23 + this->m33 * _m.m33
        };
    }
    friend Matrix4x4 operator*(Matrix4x4 _lhs, const Matrix4x4& _rhs) {
        _lhs *= _rhs;
        return _lhs;
    }

    Vector4 operator*=(const Vector4& _v) const {
        return {
            this->m00 * _v.x + this->m01 * _v.y + this->m02 * _v.z + this->m03 * _v.w,
            this->m10 * _v.x + this->m11 * _v.y + this->m12 * _v.z + this->m13 * _v.w,
            this->m20 * _v.x + this->m21 * _v.y + this->m22 * _v.z + this->m23 * _v.w,
            this->m30 * _v.x + this->m31 * _v.y + this->m32 * _v.z + this->m33 * _v.w
        };
    }

    Vector3 operator*=(const Vector3& _v) const {
        return {
            this->m00 * _v.x + this->m01 * _v.y + this->m02 * _v.z + this->m03,
            this->m10 * _v.x + this->m11 * _v.y + this->m12 * _v.z + this->m13,
            this->m20 * _v.x + this->m21 * _v.y + this->m22 * _v.z + this->m23
        };
    }
    friend Matrix4x4 operator*(Matrix4x4 _m, const Vector3& _v) {
        _m *= _v;
        return _m;
    }

    Matrix4x4& operator*=(const float _s) {
        this->m00 *= _s; this->m01 *= _s; this->m02 *= _s; this->m03 *= _s;
        this->m10 *= _s; this->m11 *= _s; this->m12 *= _s; this->m13 *= _s;
        this->m20 *= _s; this->m21 *= _s; this->m22 *= _s; this->m23 *= _s;
        this->m30 *= _s; this->m31 *= _s; this->m32 *= _s; this->m33 *= _s;
        return *this;
    }
    friend Matrix4x4 operator*(Matrix4x4 _m, const float _s) {
        _m *= _s;
        return _m;
    }
    friend Matrix4x4 operator*(const float _s, Matrix4x4 _m) {
        _m *= _s;
        return _m;
    }

    Matrix4x4& operator/=(const float _s) {
        this->m00 /= _s; this->m01 /= _s; this->m02 /= _s; this->m03 /= _s;
        this->m10 /= _s; this->m11 /= _s; this->m12 /= _s; this->m13 /= _s;
        this->m20 /= _s; this->m21 /= _s; this->m22 /= _s; this->m23 /= _s;
        this->m30 /= _s; this->m31 /= _s; this->m32 /= _s; this->m33 /= _s;
        return *this;
    }
    friend Matrix4x4 operator/(Matrix4x4 _m, const float _s) {
        _m /= _s;
        return _m;
    }

    Matrix4x4& operator=(const Matrix4x4 _m) {
        this->m00 = _m.m00; this->m01 = _m.m01; this->m02 = _m.m02; this->m03 = _m.m03;
        this->m10 = _m.m10; this->m11 = _m.m11; this->m12 = _m.m12; this->m13 = _m.m13;
        this->m20 = _m.m20; this->m21 = _m.m21; this->m22 = _m.m22; this->m23 = _m.m23;
        this->m30 = _m.m30; this->m31 = _m.m31; this->m32 = _m.m32; this->m33 = _m.m33;
        return *this;
    }

    friend bool operator==(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
        for(size_t x = 0; x < 4; x++) {
            for(size_t y = 0; y < 4; y++) {
                if(_lhs[x][y] != _rhs[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }
    friend bool operator!=(const Matrix4x4& _lhs, const Matrix4x4& _rhs) {
        return !(_lhs == _rhs);
    }

    Vector4 operator[](const size_t _i) const {
        return getRow(_i);
    }

    static Matrix4x4 zero() {
        return {
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0
        };
    }

    static Matrix4x4 one() {
        return {
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1,
            1, 1, 1, 1
        };
    }

    static Matrix4x4 identity() {
        return {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

};
