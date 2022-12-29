
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Ellipse : Shape {

        private float radiusX;
        private float radiusY;

        public Ellipse(float _x, float _y, float _w, float _h) {
            position = new Vector2(_x, _y);
            radiusX = _w/2;
            radiusY = _h/2;

            scale = 1f;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        public Ellipse(float _x, float _y, float _w, float _h, Colour _c) {
            position = new Vector2(_x, _y);
            radiusX = _w/2;
            radiusY = _h/2;
            colour = _c;

            scale = 1f;
            
            points = GenerateShape();
            basePoints = GenerateShape();
        }

        public override void Draw() {
            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);
            foreach(Vector2 point in points) {
                SDL_RenderDrawPoint(Window.renderer, (int)(position.x + point.x), (int)(position.y + point.y));
            }
        }

        protected override List<Vector2> GenerateShape() {
            
            //Mid Point Ellipse Algorithm: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/#:~:text=Midpoint%20ellipse%20algorithm%20plots(finds,x2ry2

            List<Vector2> p = new List<Vector2>();
            
            float x = 0;
            float y = radiusY;

            float dx = 2 * radiusY * radiusY * x;
            float dy = 2 * radiusX * radiusX * y;

            float d1 = (radiusY * radiusY) - (radiusX * radiusX * radiusY) + (0.25f * radiusX * radiusX);

            while (dx < dy) {

                p.Add(new Vector2(x, y));
                p.Add(new Vector2(-x, y));
                p.Add(new Vector2(x, -y));
                p.Add(new Vector2(-x, -y));

                if(d1 < 0) {
                    x++;
                    dx += (2 * radiusY * radiusY);
                    d1 += dx + (radiusY * radiusY);
                }
                else {
                    x++;
                    y--;
                    dx += 2 * radiusY * radiusY;
                    dy -= 2 * radiusX * radiusX;
                    d1 += dx - dy + (radiusY * radiusY);
                }

            }

            float d2 = ((radiusY * radiusY) * ((x + 0.5f) * (x + 0.5f))) + ((radiusX * radiusX) * ((y - 1) * (y - 1))) - (radiusX * radiusX * radiusY * radiusY);

            while(y >= 0) {

                p.Add(new Vector2(x, y));
                p.Add(new Vector2(-x, y));
                p.Add(new Vector2(x, -y));
                p.Add(new Vector2(-x, -y));

                if(d2 > 0) {
                    y--;
                    dy -= 2 * radiusX * radiusX;
                    d2 += radiusX * radiusX - dy;
                }
                else {
                    y--;
                    x++;
                    dx += 2 * radiusY * radiusY;
                    dy -= 2 * radiusX * radiusX;
                    d2 += dx - dy + radiusX * radiusX;
                }

            }
            
            return p;

        }

    }

}