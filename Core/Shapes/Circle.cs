
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Circle : Shape {

        private Vector2Int pos = new Vector2Int(0, 0);
        private int radius;

        private List<Vector2Int> points = new List<Vector2Int>();

        public Circle(int _x, int _y, int _r) {
            pos = new Vector2Int(_x, _y);
            radius = _r;

            GenerateCircle();
        }

        public Circle(int _x, int _y, int _r, Colour _c) {
            pos = new Vector2Int(_x, _y);
            radius = _r;
            colour = _c;

            GenerateCircle();
        }

        public override void Draw() {
            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);
            foreach(Vector2Int point in points) {
                SDL_RenderDrawPoint(Window.renderer, pos.x + point.x, pos.y + point.y);
            }
        }

        private void GenerateCircle() {
            
            //Mid Point Algorithm: https://en.wikipedia.org/w/index.php?title=Midpoint_circle_algorithm&oldid=889172082#C_example
            
            int x = radius - 1;
            int y = 0;
            int dx = 1;
            int dy = 1;
            int err = dx - radius * 2;

            while (x >= y) {

                points.Add(new Vector2Int(pos.x + x, pos.y + y));
                points.Add(new Vector2Int(pos.x + y, pos.y + x));
                points.Add(new Vector2Int(pos.x - y, pos.y + x));
                points.Add(new Vector2Int(pos.x - x, pos.y + y));
                points.Add(new Vector2Int(pos.x - x, pos.y - y));
                points.Add(new Vector2Int(pos.x - y, pos.y - x));
                points.Add(new Vector2Int(pos.x + y, pos.y - x));
                points.Add(new Vector2Int(pos.x + x, pos.y - y));

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

        }

    }

}