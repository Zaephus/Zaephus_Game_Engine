
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

    }

}