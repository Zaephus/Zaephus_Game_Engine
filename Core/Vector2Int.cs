
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public struct Vector2Int {

        public int x;
        public int y;

        public Vector2Int(int _x, int _y) {
            x = _x;
            y = _y;
        }

        public Vector2Int(float _x, float _y) {
            x = (int)_x;
            y = (int)_y;
        }


    }

}