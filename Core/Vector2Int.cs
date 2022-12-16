
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public struct Vector2Int {

        public int x;
        public int y;

        public Vector2Int(int _x, int _y) {
            x = _x;
            y = _y;
        }

        public Vector2Int(float _x, float _y) {
            x = (int)_x;
            y = (int)_y;
        }

        public float magnitude {
            get {
                return (float)MathF.Sqrt(x*x + y*y);
            }
        }

        public Vector2Int normalized {
            get {
                Vector2Int norm = new Vector2Int(x, y);
                norm.Normalize();
                return norm;
            }
        }

        public void Normalize() {
            float mag = magnitude;
            this = this / (int)mag;
        }
        
        public static float Distance(Vector2Int _a, Vector2Int _b) {
            return MathF.Sqrt(((_b.x - _a.x) * (_b.x - _a.x)) + ((_b.y - _a.y) * (_b.y - _a.y)));
        }
        
        public static float Dot(Vector2Int _a, Vector2Int _b) {
            return _a.x * _b.x + _a.y * _b.y;
        }

        public static float Angle(Vector2Int _a, Vector2Int _b) {
            return MathF.Acos(Vector2Int.Dot(_a, _b) / _a.magnitude * _b.magnitude);
        }

        public override int GetHashCode() {
            return x.GetHashCode() ^ (y.GetHashCode() << 2);
        }

        public override bool Equals(object? _other) {
            if(!(_other is Vector2Int)) {
                return false;
            }
            return Equals((Vector2Int)_other);
        }

        public bool Equals(Vector2Int _other) {
            return x == _other.x && y == _other.y;
        }

        public static Vector2Int operator+(Vector2Int _a, Vector2Int _b) {
            return new Vector2Int(_a.x + _b.x, _a.y + _b.y);
        }

        public static Vector2Int operator-(Vector2Int _a, Vector2Int _b) {
            return new Vector2Int(_a.x - _b.x, _a.y - _b.y);
        }

        public static Vector2Int operator*(Vector2Int _a, Vector2Int _b) {
            return new Vector2Int(_a.x * _b.x, _a.y * _b.y);
        }

        public static Vector2Int operator*(Vector2Int _a, float _b) {
            return new Vector2Int(_a.x * _b, _a.y * _b);
        }

        public static Vector2Int operator*(float _b, Vector2Int _a) {
            return new Vector2Int(_a.x * _b, _a.y * _b);
        }

        public static Vector2Int operator/(Vector2Int _a, int _b) {
            return new Vector2Int(_a.x / _b, _a.y / _b);
        }

        public static bool operator==(Vector2Int _lhs, Vector2Int _rhs) {
            return _lhs.x == _rhs.x && _lhs.y == _rhs.y;
        }

        public static bool operator!=(Vector2Int _lhs, Vector2Int _rhs) {
            return !(_lhs == _rhs);
        }

        public static Vector2Int RandomVector(float _minInclusive, float _maxInclusive) {
            return new Vector2Int(Random.Range(_minInclusive, _maxInclusive),
                                  Random.Range(_minInclusive, _maxInclusive));
        }

        public static Vector2Int zero { get { return new Vector2Int(0, 0); } }
        public static Vector2Int one { get { return new Vector2Int(1, 1); } }
        public static Vector2Int right { get { return new Vector2Int(1, 0); } }
        public static Vector2Int up { get { return new Vector2Int(0, 1); } }

    }

}