
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public struct Vector2 {

        public float x;
        public float y;

        public Vector2(float _x, float _y) {
            x = _x;
            y = _y;
        }

        public float magnitude {
            get {
                return (float)MathF.Sqrt(x*x + y*y);
            }
        }

        public Vector2 normalized {
            get {
                Vector2 norm = new Vector2(x, y);
                norm.Normalize();
                return norm;
            }
        }

        public void Normalize() {
            float mag = magnitude;
            this = this / mag;
        }

        public void Rotate(float _rad) {
            float a = x * MathF.Cos(_rad) - y * MathF.Sin(_rad);
            float b = x * MathF.Sin(_rad) + y * MathF.Cos(_rad);

            x = a;
            y = b;
        }

        public static float Distance(Vector2 _a, Vector2 _b) {
            return MathF.Sqrt(((_b.x - _a.x) * (_b.x - _a.x)) + ((_b.y - _a.y) * (_b.y - _a.y)));
        }

        public static float Dot(Vector2 _a, Vector2 _b) {
            return _a.x * _b.x + _a.y * _b.y;
        }

        public static float Angle(Vector2 _from, Vector2 _to) {
            float dot = Vector2.Dot(_from, _to);
            return MathF.Acos(dot / (_from.magnitude * _to.magnitude));
        }

        public override int GetHashCode() {
            return x.GetHashCode() ^ (y.GetHashCode() << 2);
        }

        public override bool Equals(object? _other) {
            if(!(_other is Vector2)) {
                return false;
            }
            return Equals((Vector2)_other);
        }

        public bool Equals(Vector2 _other) {
            return x == _other.x && y == _other.y;
        }

        public static Vector2 operator+(Vector2 _a, Vector2 _b) {
            return new Vector2(_a.x + _b.x, _a.y + _b.y);
        }

        public static Vector2 operator-(Vector2 _a, Vector2 _b) {
            return new Vector2(_a.x - _b.x, _a.y - _b.y);
        }

        public static Vector2 operator*(Vector2 _a, Vector2 _b) {
            return new Vector2(_a.x * _b.x, _a.y * _b.y);
        }

        public static Vector2 operator*(Vector2 _a, float _b) {
            return new Vector2(_a.x * _b, _a.y * _b);
        }

        public static Vector2 operator*(float _b, Vector2 _a) {
            return new Vector2(_a.x * _b, _a.y * _b);
        }

        public static Vector2 operator/(Vector2 _a, float _b) {
            return new Vector2(_a.x / _b, _a.y / _b);
        }

        public static bool operator==(Vector2 _lhs, Vector2 _rhs) {
            return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
        }

        public static bool operator!=(Vector2 _lhs, Vector2 _rhs) {
            return !(_lhs == _rhs);
        }

        public static Vector2 RandomVector(float _minInclusive, float _maxInclusive) {
            return new Vector2(Random.Range(_minInclusive, _maxInclusive),
                               Random.Range(_minInclusive, _maxInclusive));
        }

        public static Vector2 zero { get { return new Vector2(0, 0); } }
        public static Vector2 one { get { return new Vector2(1, 1); } }
        public static Vector2 right { get { return new Vector2(1, 0); } }
        public static Vector2 up { get { return new Vector2(0, 1); } }

    }

}