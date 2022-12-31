
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;
using ZaephusEngine;

// SDL2 for CSharp via https://github.com/flibitijibibo/SDL2-CS
// Install package via https://www.nuget.org/packages/Sayers.SDL2.Core/
// Tutorial at https://jsayers.dev/c-sdl-tutorial-part-3-drawing-shapes/

Game game = new Game();

game.Start();
Window.Setup();

while(Window.running) {
    Window.PollEvents();
    game.Update();
    Window.Render();
}

game.Exit();
Window.CleanUp();