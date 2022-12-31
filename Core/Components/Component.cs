
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public abstract class Component {

        public abstract void Start();
        public abstract void Update();
        public abstract void Exit();

    }

}