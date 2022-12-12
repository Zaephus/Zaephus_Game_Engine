
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Hexagon : Shape {
        
        public float radius;

        public Hexagon(float _x, float _y, float _r) {
            position = new Vector2(_x, _y);
            radius = _r;
            
            points = GenerateShape();
        }

        public Hexagon(float _x, float _y, float _r, Colour _c) {
            position = new Vector2(_x, _y);
            radius = _r;
            colour = _c;
            
            points = GenerateShape();
        }

        protected override List<Vector2> GenerateShape() {

            //https://www.quora.com/How-can-you-find-the-coordinates-in-a-hexagon

            List<Vector2> p = new List<Vector2>();
            
            p.Add(new Vector2(radius, 0));
            p.Add(new Vector2(radius / 2, (MathF.Sqrt(3) * radius) / 2));
            p.Add(new Vector2(-radius / 2, (MathF.Sqrt(3) * radius) / 2));
            p.Add(new Vector2(-radius, 0));
            p.Add(new Vector2(-radius / 2, -(MathF.Sqrt(3) * radius) / 2));
            p.Add(new Vector2(radius / 2, -(MathF.Sqrt(3) * radius) / 2));

            return p;

        }

    }

}