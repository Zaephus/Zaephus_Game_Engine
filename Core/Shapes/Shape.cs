
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public abstract class Shape {

        public Vector2 position { get; set; }
        public float rotation { get; set; }
        public float scale { get; set; }

        protected List<Vector2> points = new List<Vector2>();
        protected List<Vector2> basePoints = new List<Vector2>();

        protected Colour colour;

        public Shape() {
            Window.shapes.Add(this);
        }
        
        public virtual void Draw() {

            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);

            for(int i = 0; i < points.Count; i++) {

                points[i] = new Vector2(
                    scale * (basePoints[i].x * MathF.Cos(rotation) - basePoints[i].y * MathF.Sin(rotation)),
                    scale * (basePoints[i].x * MathF.Sin(rotation) + basePoints[i].y * MathF.Cos(rotation))
                );

                SDL_RenderDrawLine(
                    Window.renderer,
                    (int)(position.x + points[i].x),
                    (int)(position.y + points[i].y),
                    (int)(position.x + points[(i+1) % points.Count].x),
                    (int)(position.y + points[(i+1) % points.Count].y)
                );
            }

        }

        protected abstract List<Vector2> GenerateShape();
        
    }

}