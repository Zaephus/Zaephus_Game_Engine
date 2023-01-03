
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class BoxCollider : Collider {

        public Vector2 position;
        public Vector2 size;

        private Vector2 lastPosition = Vector2.zero;
        private bool isColliding = false;

        public BoxCollider(GameObject _parent) : base(_parent) {
            Game.colliders.Add(this);
        }

        public override void Start() {

        }

        public override void Update() {

            if(!isColliding) {
                lastPosition = new Vector2(position.x, position.y);
            }

            position = parent.transform.position;
            size = 100 * parent.transform.scale;

            if(CheckCollision()) {
                isColliding = true;
                parent.transform.position = lastPosition;
            }
            else {
                isColliding = false;
            }

        }

        public override void Exit() {

        }

        public override bool OverlapPoint(Vector2 _point) {

            //Reference for finding a point within a polygonal shape: 
            //https://stackoverflow.com/questions/2752725/finding-whether-a-point-lies-inside-a-rectangle-or-not#:~:text=In%20any%20case,%20for%20any,test%20-%20the%20point%20is%20inside.

            Vector2 pointA = new Vector2(size.x / 2, size.y / 2);
            pointA = new Vector2(
                pointA.x * MathF.Cos(parent.transform.rotation) - pointA.y * MathF.Sin(parent.transform.rotation),
                pointA.x * MathF.Sin(parent.transform.rotation) + pointA.y * MathF.Cos(parent.transform.rotation)
            );
            pointA += position;

            Vector2 pointB = new Vector2(-size.x / 2, size.y / 2);
            pointB = new Vector2(
                pointB.x * MathF.Cos(parent.transform.rotation) - pointB.y * MathF.Sin(parent.transform.rotation),
                pointB.x * MathF.Sin(parent.transform.rotation) + pointB.y * MathF.Cos(parent.transform.rotation)
            );
            pointB += position;

            Vector2 pointC = new Vector2(-size.x / 2, -size.y / 2);
            pointC = new Vector2(
                pointC.x * MathF.Cos(parent.transform.rotation) - pointC.y * MathF.Sin(parent.transform.rotation),
                pointC.x * MathF.Sin(parent.transform.rotation) + pointC.y * MathF.Cos(parent.transform.rotation)
            );
            pointC += position;

            Vector2 pointD = new Vector2(size.x / 2, -size.y / 2);
            pointD = new Vector2(
                pointD.x * MathF.Cos(parent.transform.rotation) - pointD.y * MathF.Sin(parent.transform.rotation),
                pointD.x * MathF.Sin(parent.transform.rotation) + pointD.y * MathF.Cos(parent.transform.rotation)
            );
            pointD += position;

            float dAB = (pointB.x - pointA.x) * (_point.y - pointA.y) - (_point.x - pointA.x) * (pointB.y - pointA.y);
            float dBC = (pointC.x - pointB.x) * (_point.y - pointB.y) - (_point.x - pointB.x) * (pointC.y - pointB.y);
            float dCD = (pointD.x - pointC.x) * (_point.y - pointC.y) - (_point.x - pointC.x) * (pointD.y - pointC.y);
            float dDA = (pointA.x - pointD.x) * (_point.y - pointD.y) - (_point.x - pointD.x) * (pointA.y - pointD.y);

            if(dAB >= 0 && dBC >= 0 && dCD >= 0 && dDA >= 0) {
                return true;
            }

            return false;

        }

        public override bool CheckCollision() {

            foreach(Collider c in Game.colliders) {
                if(c == this) {
                    continue;
                }
                if(c is BoxCollider) {
                    BoxCollider bc = c as BoxCollider;
                    if((position.x + size.x/2) >= (bc.position.x - bc.size.x/2) && (position.x - size.x/2) <= (bc.position.x + bc.size.x/2)) {
                        if((position.y + size.y/2) >= (bc.position.y - bc.size.y/2) && (position.y - size.y/2) <= (bc.position.y + bc.size.y/2)) {
                            return true;
                        }
                    }
                }
                
            }
            return false;

        }

    }

}