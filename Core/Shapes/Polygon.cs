
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Polygon : Shape {

        private List<Vector2> p = new List<Vector2>();

        public Polygon(Transform _transform, params Vector2[] _points) : base(_transform) {

            drawType = DrawType.Lines;

            p.AddRange(_points);
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        public Polygon(Transform _transform, Colour _c, params Vector2[] _points) : base(_transform) {
            colour = _c;

            drawType = DrawType.Lines;

            p.AddRange(_points);
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        protected override List<Vector2> GenerateShape() {
            List<Vector2> temp = new List<Vector2>();
            temp.AddRange(p);
            return temp;
        }

    }

}