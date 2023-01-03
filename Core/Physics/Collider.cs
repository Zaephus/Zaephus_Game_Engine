
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public abstract class Collider : Component {

        public Collider(GameObject _parent) : base(_parent) {}

        public abstract bool CheckCollision(params Collider[] _colliders);

        public abstract bool OverlapPoint(Vector2 _point);

    }

}