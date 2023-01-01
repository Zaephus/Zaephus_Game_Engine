
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class Transform : Component {

        public Vector2 position { get; set; }
        public float rotation { get; set; }
        public Vector2 scale { get; set; }

        public override void Start() {}

        public override void Update() {}

        public override void Exit() {}

        public Vector2 up {
            get {
                Vector2 upVector = new Vector2(
                        Vector2.up.x * MathF.Cos(rotation) - Vector2.up.y * MathF.Sin(rotation),
                        Vector2.up.x * MathF.Sin(rotation) + Vector2.up.y * MathF.Cos(rotation)
                );
                return upVector.normalized;
            }
        }

        public Vector2 right {
            get {
                Vector2 rightVector = new Vector2(
                        Vector2.right.x * MathF.Cos(rotation) - Vector2.right.y * MathF.Sin(rotation),
                        Vector2.right.x * MathF.Sin(rotation) + Vector2.right.y * MathF.Cos(rotation)
                );
                return rightVector.normalized;
            }
        }

    }

}