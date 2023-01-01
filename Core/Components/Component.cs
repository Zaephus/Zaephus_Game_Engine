
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public abstract class Component {

        protected GameObject parent;

        public Component(GameObject _parent) {
            parent = _parent;
        }

        public abstract void Start();
        public abstract void Update();
        public abstract void Exit();

    }

}