
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Ellipse : Shape {

        private float horRadius = 50;
        private float verRadius = 50;

        public Ellipse(Transform _transform) : base(_transform) {

            drawType = DrawType.Points;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        public Ellipse(Transform _transform, Colour _c) : base(_transform) {
            colour = _c;

            drawType = DrawType.Points;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        protected override List<Vector2> GenerateShape() {
            
            //Mid Point Ellipse Algorithm: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/#:~:text=Midpoint%20ellipse%20algorithm%20plots(finds,x2ry2

            Console.WriteLine("Generated a shape");

            float shapeWidth = horRadius * transform.scale.x;
            float shapeHeight = verRadius * transform.scale.y;

            List<Vector2> p = new List<Vector2>();
            
            float x = 0;
            float y = shapeHeight;

            float dx = 2 * shapeHeight * shapeHeight * x;
            float dy = 2 * shapeWidth * shapeWidth * y;

            float d1 = (shapeHeight * shapeHeight) - (shapeWidth * shapeWidth) + (0.25f * shapeWidth * shapeWidth);

            while (dx < dy) {

                p.Add(new Vector2(x, y));
                p.Add(new Vector2(-x, y));
                p.Add(new Vector2(x, -y));
                p.Add(new Vector2(-x, -y));

                if(d1 < 0) {
                    x++;
                    dx += (2 * shapeHeight * shapeHeight);
                    d1 += dx + (shapeHeight * shapeHeight);
                }
                else {
                    x++;
                    y--;
                    dx += 2 * shapeHeight * shapeHeight;
                    dy -= 2 * shapeWidth * shapeWidth;
                    d1 += dx - dy + (shapeHeight * shapeHeight);
                }

            }

            float d2 = ((shapeHeight * shapeHeight) * ((x + 0.5f) * (x + 0.5f))) + ((shapeWidth * shapeWidth) * ((y - 1) * (y - 1))) - (shapeWidth * shapeWidth * shapeHeight * shapeHeight);

            while(y >= 0) {

                p.Add(new Vector2(x, y));
                p.Add(new Vector2(-x, y));
                p.Add(new Vector2(x, -y));
                p.Add(new Vector2(-x, -y));

                if(d2 > 0) {
                    y--;
                    dy -= 2 * shapeWidth * shapeWidth;
                    d2 += shapeWidth * shapeWidth - dy;
                }
                else {
                    y--;
                    x++;
                    dx += 2 * shapeHeight * shapeHeight;
                    dy -= 2 * shapeWidth * shapeWidth;
                    d2 += dx - dy + shapeWidth * shapeWidth;
                }

            }
            
            return p;

        }

    }

}