
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public abstract class Shape : Component {

        protected Transform transform;

        protected enum DrawType {
            Points,
            Lines
        }
        protected DrawType drawType;

        protected List<Vector2> points = new List<Vector2>();
        protected List<Vector2> basePoints = new List<Vector2>();

        protected Colour colour;

        public Shape(GameObject _parent) : base(_parent) {
            transform = _parent.transform;
            Window.shapes.Add(this);
        }
        
        public override void Start() {}

        public override void Update() {

            if(drawType == DrawType.Points) {

                points = GenerateShape();
                basePoints = GenerateShape();

                for(int i = 0; i < points.Count; i++) {

                    points[i] = new Vector2(
                        basePoints[i].x * MathF.Cos(transform.rotation) - basePoints[i].y * MathF.Sin(transform.rotation),
                        basePoints[i].x * MathF.Sin(transform.rotation) + basePoints[i].y * MathF.Cos(transform.rotation)
                    );

                }

            }
            else {

                for(int i = 0; i < points.Count; i++) {

                    points[i] = new Vector2(
                        transform.scale.x * (basePoints[i].x * MathF.Cos(transform.rotation) - basePoints[i].y * MathF.Sin(transform.rotation)),
                        transform.scale.y * (basePoints[i].x * MathF.Sin(transform.rotation) + basePoints[i].y * MathF.Cos(transform.rotation))
                    );

                }

            }

        }
        
        public void Draw() {

            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);

            for(int i = 0; i < points.Count; i++) {

                switch(drawType) {

                    case DrawType.Points:
                        foreach(Vector2 point in points) {
                            SDL_RenderDrawPoint(Window.renderer, (int)(transform.position.x + point.x), (int)(transform.position.y + point.y));
                        }
                        break;

                    case DrawType.Lines:
                        SDL_RenderDrawLine(
                            Window.renderer,
                            (int)(transform.position.x + points[i].x),
                            (int)(transform.position.y + points[i].y),
                            (int)(transform.position.x + points[(i+1) % points.Count].x),
                            (int)(transform.position.y + points[(i+1) % points.Count].y)
                        );
                        break;

                }

            }

        }

        public override void Exit() {}

        protected abstract List<Vector2> GenerateShape();
        
    }

}