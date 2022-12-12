
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Polygon : Shape {

        private List<Vector2> p = new List<Vector2>();

        public Polygon(float _x, float _y, params Vector2[] _points) {
            position = new Vector2(_x, _y);

            p.AddRange(_points);
            
            points = GenerateShape();
        }

        public Polygon(float _x, float _y, Colour _c, params Vector2[] _points) {
            position = new Vector2(_x, _y);
            colour = _c;

            p.AddRange(_points);
            
            points = GenerateShape();
        }

        protected override List<Vector2> GenerateShape() {
            List<Vector2> temp = new List<Vector2>();
            temp.AddRange(p);
            return temp;
        }

    }

}