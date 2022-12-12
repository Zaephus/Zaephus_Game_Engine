
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Hexagon : Shape {

        public Vector2 position;
        public float radius;

        private Vector2Int[] points = new Vector2Int[6];

        public Hexagon(float _x, float _y, float _r) {
            position = new Vector2(_x, _y);
            radius = _r;

            GenerateHexagon();
        }

        public Hexagon(float _x, float _y, float _r, Colour _c) {
            position = new Vector2(_x, _y);
            radius = _r;
            colour = _c;

            GenerateHexagon();
        }

        public override void Draw() {
            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);
            for(int i = 0; i < points.Length - 1; i++) {
                SDL_RenderDrawLine(Window.renderer, (int)position.x + points[i].x, (int)position.y + points[i].y, (int)position.x + points[i+1].x, (int)position.y + points[i+1].y);
            }
            SDL_RenderDrawLine(Window.renderer, (int)position.x + points[points.Length-1].x, (int)position.y + points[points.Length-1].y, (int)position.x + points[0].x, (int)position.y + points[0].y);
        }

        private void GenerateHexagon() {

            //https://www.quora.com/How-can-you-find-the-coordinates-in-a-hexagon
            
            points[0] = new Vector2Int(radius, 0);
            points[1] = new Vector2Int(radius / 2, (MathF.Sqrt(3) * radius) / 2);
            points[2] = new Vector2Int(-radius / 2, (MathF.Sqrt(3) * radius) / 2);
            points[3] = new Vector2Int(-radius, 0);
            points[4] = new Vector2Int(-radius / 2, -(MathF.Sqrt(3) * radius) / 2);
            points[5] = new Vector2Int(radius / 2, -(MathF.Sqrt(3) * radius) / 2);
        }

    }

}