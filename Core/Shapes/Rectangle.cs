
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;

namespace ZaephusEngine {

    public class Rectangle : Shape {

        public Vector4 rect;

        public Rectangle(int _x, int _y, int _w, int _h) {
            rect = new Vector4(_x, _y, _w, _h);
        }

        public Rectangle(int _x, int _y, int _w, int _h, Colour _c) {
            rect = new Vector4(_x, _y, _w, _h);

            colour = _c;
        }

        public override void Draw() {
            SDL_Rect r = new SDL_Rect {
                x = (int)rect.x,
                y = (int)rect.y,
                w = (int)rect.z,
                h = (int)rect.w
            };
            SDL_SetRenderDrawColor(Window.renderer, colour.R, colour.G, colour.B, colour.A);
            SDL_RenderDrawRect(Window.renderer, ref r);
        }

    }

}