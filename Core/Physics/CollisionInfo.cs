
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class CollisionInfo {

        public Collider otherCollider;

        public List<Vector2> collidedPoints;

        public CollisionInfo(Collider _collider, params Vector2[] _points) {
            otherCollider = _collider;
            collidedPoints.AddRange(_points);
        }

    }

}