
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public struct Colour {

    public byte R;
    public byte G;
    public byte B;
    public byte A;

    public Colour() {
        R = 255;
        G = 255;
        B = 255;
        A = 255;
    }

    public Colour(byte _r, byte _g, byte _b) {
        R = _r;
        G = _g;
        B = _b;
        A = 255;
    }

    public Colour(byte _r, byte _g, byte _b, byte _a) {
        R = _r;
        G = _g;
        B = _b;
        A = _a;
    }

    public override int GetHashCode() {
        return ((Vector4)this).GetHashCode();
    }

    public override bool Equals(object? _other) {
        if(!(_other is Colour)) {
            return false;
        }
        return Equals((Colour)_other);
    }

    public bool Equals(Colour _other) {
        return R.Equals(_other.R) && G.Equals(_other.G) && B.Equals(_other.B) && A.Equals(_other.A);
    } 

    public static Colour operator+(Colour _a, Colour _b) {
        return new Colour((byte)(_a.R + _b.R), (byte)(_a.G + _b.G), (byte)(_a.B + _b.B), (byte)(_a.A + _b.A));
    }

    public static Colour operator-(Colour _a, Colour _b) {
        return new Colour((byte)(_a.R - _b.R), (byte)(_a.G - _b.G), (byte)(_a.B - _b.B), (byte)(_a.A - _b.A));
    }

    public static Colour operator*(Colour _a, Colour _b) {
        return new Colour((byte)(_a.R * _b.R), (byte)(_a.G * _b.G), (byte)(_a.B * _b.B), (byte)(_a.A * _b.A));
    }

    public static Colour operator*(Colour _a, float _b) {
        return new Colour((byte)(_a.R * _b), (byte)(_a.G * _b), (byte)(_a.B * _b), (byte)(_a.A * _b));
    }

    public static Colour operator*(float _b, Colour _a) {
        return new Colour((byte)(_a.R * _b), (byte)(_a.G * _b), (byte)(_a.B * _b), (byte)(_a.A * _b));
    }

    public static Colour operator/(Colour _a, float _b) {
        return new Colour((byte)(_a.R / _b), (byte)(_a.G / _b), (byte)(_a.B / _b), (byte)(_a.A / _b));
    }

    public static bool operator==(Colour _lhs, Colour _rhs) {
        return _lhs.R == _rhs.R && _lhs.G == _rhs.G && _lhs.B == _rhs.B && _lhs.A == _rhs.A;
    }

    public static bool operator!=(Colour _lhs, Colour _rhs) {
        return !(_lhs == _rhs);
    }

    public static implicit operator Vector4(Colour _c) {
        return new Vector4(_c.R, _c.G, _c.B, _c.A);
    }

    public static implicit operator Colour(Vector4 _v) {
        return new Colour((byte)_v.x, (byte)_v.y, (byte)_v.z, (byte)_v.w);
    }

    public static Colour red { get { return new Colour(255, 0, 0, 255); } }
    public static Colour green { get { return new Colour(0, 255, 0, 255); } }
    public static Colour blue { get { return new Colour(0, 0, 255, 255); } }
    public static Colour white { get { return new Colour(255, 255, 255, 255); } }
    public static Colour black { get { return new Colour(0, 0, 0, 255); } }
    public static Colour yellow { get { return new Colour(255, 235, 4, 255); } }
    public static Colour cyan { get { return new Colour(0, 255, 255, 255); } }
    public static Colour magenta { get { return new Colour(255, 0, 255, 255); } }
    public static Colour grey { get { return new Colour(128, 128, 128, 255); } }

}