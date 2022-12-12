
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public abstract class Shape {

        protected Colour colour;

        public Shape() {
            Window.shapes.Add(this);
        }
        public abstract void Draw();
        
    }

}