
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Hexagon : Shape {
        
        public float radius = 50;

        public Hexagon(GameObject _parent) : base(_parent) {

            drawType = DrawType.Lines;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        public Hexagon(GameObject _parent, Colour _c) : base(_parent) {
            colour = _c;

            drawType = DrawType.Lines;
            
            points = GenerateShape();
            basePoints = GenerateShape();
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