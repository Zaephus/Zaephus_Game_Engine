
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Rectangle : Shape {

        private float width = 100;
        private float height = 100;

        public Rectangle(Transform _transform) : base(_transform) {

            drawType = DrawType.Lines;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        public Rectangle(Transform _transform, Colour _c) : base(_transform) {

            colour = _c;

            drawType = DrawType.Lines;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        protected override List<Vector2> GenerateShape() {

            List<Vector2> p = new List<Vector2>();

            p.Add(new Vector2(-width/2, -height/2));
            p.Add(new Vector2(width/2, -height/2));
            p.Add(new Vector2(width/2, height/2));
            p.Add(new Vector2(-width/2, height/2));

            return p;

        }

    }

}