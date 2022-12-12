
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

    }

}