
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Circle : Shape {

        private float radius;

        public Circle(float _x, float _y, float _r) {
            position = new Vector2(_x, _y);
            radius = _r;
            
            points = GenerateShape();
        }

        public Circle(float _x, float _y, float _r, Colour _c) {
            position = new Vector2(_x, _y);
            radius = _r;
            colour = _c;
            
            points = GenerateShape();
        }

        public override void Draw() {
            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);
            foreach(Vector2 point in points) {
                SDL_RenderDrawPoint(Window.renderer, (int)(position.x + point.x), (int)(position.y + point.y));
            }
        }

        protected override List<Vector2> GenerateShape() {
            
            //Mid Point Circle Algorithm: https://en.wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example

            List<Vector2> p = new List<Vector2>();
            
            float x = radius - 1;
            float y = 0;
            float dx = 1;
            float dy = 1;
            float err = dx - radius * 2;

            while (x >= y) {

                p.Add(new Vector2(x, y));
                p.Add(new Vector2(y, x));
                p.Add(new Vector2(-y, x));
                p.Add(new Vector2(-x, y));
                p.Add(new Vector2(-x, -y));
                p.Add(new Vector2(-y, -x));
                p.Add(new Vector2(y, -x));
                p.Add(new Vector2(x, -y));

                if(err <= 0) {
                    y++;
                    err += dy;
                    dy += 2;
                }

                if(err > 0) {
                    x--;
                    dx += 2;
                    err += dx - radius * 2;
                }

            }

            return p;

        }

    }

}