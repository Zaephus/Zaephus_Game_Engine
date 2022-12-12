
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {
    
    public class BoxCollider2D : Collider {

        public Vector4 rect;

        private Shape shape;

        public BoxCollider2D(Shape _shape, int _x, int _y, int _w, int _h) {
            rect = new Vector4(_x, _y, _w, _h);
            shape = _shape;
        }

    }

}