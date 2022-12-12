
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Rectangle : Shape {

        public Vector2 size;

        public Rectangle(int _x, int _y, int _w, int _h) {
            position = new Vector2(_x, _y);
            size = new Vector2(_w, _h);
            
            points = GenerateShape();
        }

        public Rectangle(int _x, int _y, int _w, int _h, Colour _c) {
            position = new Vector2(_x, _y);
            size = new Vector2(_w, _h);

            colour = _c;
            
            points = GenerateShape();
        }

        protected override List<Vector2> GenerateShape() {

            List<Vector2> p = new List<Vector2>();

            p.Add(new Vector2(-size.x/2, -size.y/2));
            p.Add(new Vector2(size.x/2, -size.y/2));
            p.Add(new Vector2(size.x/2, size.y/2));
            p.Add(new Vector2(-size.x/2, size.y/2));

            return p;

        }

    }

}