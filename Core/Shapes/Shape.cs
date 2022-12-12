
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public abstract class Shape {

        public Vector2 position;
        private float rot;
        public float rotation {
            get {
                return rot;
            }
            set {
                rot = value;
                for(int i = 0; i < points.Count; i++) {
                    points[i] = new Vector2(
                        GenerateShape()[i].x * MathF.Cos(rot) - GenerateShape()[i].y * MathF.Sin(rot),
                        GenerateShape()[i].x * MathF.Sin(rot) + GenerateShape()[i].y * MathF.Cos(rot)
                    );
                }
            }
        }

        protected List<Vector2> points = new List<Vector2>();

        protected Colour colour;

        public Shape() {
            Window.shapes.Add(this);
        }
        
        public virtual void Draw() {

            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);

            for(int i = 0; i < points.Count; i++) {
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