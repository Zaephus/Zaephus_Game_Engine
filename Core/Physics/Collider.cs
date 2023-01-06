
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public abstract class Collider : Component {

        public Action<CollisionInfo> OnCollision;

        public Collider(GameObject _parent) : base(_parent) {}

        public abstract void CheckCollision(params Collider[] _colliders);

        public abstract bool OverlapPoint(Vector2 _point);

    }

}