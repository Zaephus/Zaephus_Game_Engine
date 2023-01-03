
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class BoxCollider : Collider {

        private Vector2 position;
        private float rotation;
        private Vector2 size;

        private Vector2 lastPosition;
        private float lastRotation;

        private bool isColliding = false;

        public BoxCollider(GameObject _parent) : base(_parent) {
            Game.colliders.Add(this);
        }

        public override void Start() {
            position = parent.transform.position;
            rotation = parent.transform.rotation;
            size = 100 * parent.transform.scale;
        }

        public override void Update() {

            if(!isColliding) {
                lastPosition = new Vector2(position.x, position.y);
                lastRotation = rotation;
            }

            position = parent.transform.position;
            rotation = parent.transform.rotation;
            size = 100 * parent.transform.scale;

            if(CheckCollision(Game.colliders.ToArray())) {
                isColliding = true;
                parent.transform.position = lastPosition;
                parent.transform.rotation = lastRotation;
            }
            else {
                isColliding = false;
            }

        }

        public override void Exit() {}

        public override bool CheckCollision(params Collider[] _colliders) {

            int resolution = 2;

            List<Vector2> points = new List<Vector2>();
            Vector2[] verteces = GetVerteces();

            for(int i = 0; i < verteces.Length; i++) {
                Vector2 pointA = verteces[i];
                Vector2 diff = verteces[(i + 1) % verteces.Length] - pointA;

                points.Add(pointA);

                for(int j = 1; j <= resolution; j++) {
                    Vector2 intermediate = pointA + (diff.normalized * ((diff.magnitude / (resolution + 1)) * j));
                    points.Add(intermediate);
                }

            }

            foreach(Collider c in _colliders) {
                if(c == this) {
                    continue;
                }

                foreach(Vector2 point in points) {
                    if(c.OverlapPoint(point)) {
                        return true;
                    }
                }
            }

            return false;

        }

        public override bool OverlapPoint(Vector2 _point) {

            //Reference for finding a point within a polygonal shape: 
            //https://stackoverflow.com/questions/2752725/finding-whether-a-point-lies-inside-a-rectangle-or-not#:~:text=In%20any%20case,%20for%20any,test%20-%20the%20point%20is%20inside.

            Vector2[] points = GetVerteces();

            float dAB = (points[1].x - points[0].x) * (_point.y - points[0].y) - (_point.x - points[0].x) * (points[1].y - points[0].y);
            float dBC = (points[2].x - points[1].x) * (_point.y - points[1].y) - (_point.x - points[1].x) * (points[2].y - points[1].y);
            float dCD = (points[3].x - points[2].x) * (_point.y - points[2].y) - (_point.x - points[2].x) * (points[3].y - points[2].y);
            float dDA = (points[0].x - points[3].x) * (_point.y - points[3].y) - (_point.x - points[3].x) * (points[0].y - points[3].y);

            if(dAB >= 0 && dBC >= 0 && dCD >= 0 && dDA >= 0) {
                return true;
            }

            return false;

        }

        private Vector2[] GetVerteces() {

            Vector2[] verteces = new Vector2[4];

            verteces[0] = (new Vector2(size.x / 2, size.y / 2));
            verteces[1] = (new Vector2(-size.x / 2, size.y / 2));
            verteces[2] = (new Vector2(-size.x / 2, -size.y / 2));
            verteces[3] = (new Vector2(size.x / 2, -size.y / 2));

            for(int i = 0; i < verteces.Length; i++) {
                verteces[i] = new Vector2(
                    verteces[i].x * MathF.Cos(rotation) - verteces[i].y * MathF.Sin(rotation),
                    verteces[i].x * MathF.Sin(rotation) + verteces[i].y * MathF.Cos(rotation)
                );
                verteces[i] += position;
            }

            return verteces;

        }

    }

}