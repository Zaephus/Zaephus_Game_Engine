
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class CircleCollider : Collider {

        public CircleCollider(GameObject _parent) : base(_parent) {
            Game.colliders.Add(this);
        }

        public override void Start() {

        }

        public override void Update() {

        }

        public override void Exit() {

        }

        public override bool OverlapPoint(Vector2 _point) {
            return false;
        }

        public override bool CheckCollision() {
            return false;
        }

    }

}