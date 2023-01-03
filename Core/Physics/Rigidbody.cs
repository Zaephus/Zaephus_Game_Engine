
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class Rigidbody : Component {

        private Transform transform;

        public Rigidbody(GameObject _parent) : base(_parent) {
            transform = _parent.transform;
        }

        public override void Start() {

        }

        public override void Update() {

        }

        public override void Exit() {

        }

    }

}