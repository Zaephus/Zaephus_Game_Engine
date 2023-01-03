
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public abstract class Collider : Component {

        public Collider(GameObject _parent) : base(_parent) {}

        public abstract bool OverlapPoint(Vector2 _point);

        public abstract bool CheckCollision();


    }

}