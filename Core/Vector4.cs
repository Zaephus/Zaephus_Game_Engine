
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public struct Vector4 {

        public float x;
        public float y;
        public float z;
        public float w;

        public Vector4(float _x, float _y, float _z, float _w) {
            x = _x;
            y = _y;
            z = _z;
            w = _w;
        }

        public float magnitude {
            get {
                return (float)MathF.Sqrt(x*x + y*y + z*z + w*w);
            }
        }

        public Vector4 normalized {
            get {
                Vector4 norm = new Vector4(x, y, z, w);
                norm.Normalize();
                return norm;
            }
        }

        public void Normalize() {
            float mag = magnitude;
            this = this / mag;
        }

        public override int GetHashCode() {
            return x.GetHashCode() ^ (y.GetHashCode() << 2) ^ (z.GetHashCode() >> 2) ^ (w.GetHashCode() >> 1);
        }

        public override bool Equals(object? _other) {
            if(!(_other is Vector4)) {
                return false;
            }
            return Equals((Vector4)_other);
        }

        public bool Equals(Vector4 _other) {
            return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
        }

        public static Vector4 operator+(Vector4 _a, Vector4 _b) {
            return new Vector4(_a.x + _b.x, _a.y + _b.y, _a.z + _b.z, _a.w + _b.w);
        }

        public static Vector4 operator-(Vector4 _a, Vector4 _b) {
            return new Vector4(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z, _a.w - _b.w);
        }

        public static Vector4 operator*(Vector4 _a, Vector4 _b) {
            return new Vector4(_a.x * _b.x, _a.y * _b.y, _a.z * _b.z, _a.w * _b.w);
        }

        public static Vector4 operator*(Vector4 _a, float _b) {
            return new Vector4(_a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b);
        }

        public static Vector4 operator*(float _b, Vector4 _a) {
            return new Vector4(_a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b);
        }

        public static Vector4 operator/(Vector4 _a, float _b) {
            return new Vector4(_a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b);
        }

        public static bool operator==(Vector4 _lhs, Vector4 _rhs) {
            return _lhs.x == _rhs.x && _lhs.y == _rhs.y && _lhs.z == _rhs.z && _lhs.w == _rhs.w;
        }

        public static bool operator!=(Vector4 _lhs, Vector4 _rhs) {
            return !(_lhs == _rhs);
        }

        public static Vector4 RandomVector(float _minInclusive, float _maxInclusive) {
            return new Vector4(Random.Range(_minInclusive, _maxInclusive),
                               Random.Range(_minInclusive, _maxInclusive),
                               Random.Range(_minInclusive, _maxInclusive),
                               Random.Range(_minInclusive, _maxInclusive));
        }

        public static Vector4 zero { get { return new Vector4(0, 0, 0, 0); } }
        public static Vector4 one { get { return new Vector4(1, 1, 1, 1); } }

    }

}