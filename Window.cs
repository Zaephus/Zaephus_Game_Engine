
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;
using ZaephusEngine;

public static class Window {

    public static IntPtr window { get; private set; }

    public static IntPtr renderer { get; private set; }

    public static bool running { get; private set; }

    public static List<Shape> shapes = new List<Shape>();

    private const int WIDTH = 640;
    private const int HEIGHT = 480;

    /// <summary>
    /// Setup all of the SDL resources needed to display a window.
    /// </summary>
    public static void Setup() {

        running = true;

        //Initializes SDL.
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            Console.WriteLine($"There was an issue initializing SDL. {SDL_GetError()}");
        }

        //Create a new window given a title size and passes it a flag indicating it should be shown.
        window = SDL_CreateWindow(
            "Zaephus Game Engine",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIDTH,
            HEIGHT,
            SDL_WindowFlags.SDL_WINDOW_SHOWN |
            SDL_WindowFlags.SDL_WINDOW_ALLOW_HIGHDPI |
            SDL_WindowFlags.SDL_WINDOW_RESIZABLE
        );

        if(window == IntPtr.Zero) {
            Console.WriteLine($"There was an issue creating the window. {SDL_GetError()}");
        }

        renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RendererFlags.SDL_RENDERER_ACCELERATED |
            SDL_RendererFlags.SDL_RENDERER_PRESENTVSYNC
        );

        if(renderer == IntPtr.Zero) {
            Console.WriteLine($"There was an issue creating the renderer. {SDL_GetError()}");
        }

    }

    /// <summary>
    /// Checks to see if there are any events to be processed.
    /// </summary>
    public static void PollEvents() {
        //Check to see if ther are any events and continue to do so until the queue is empty.
        while(SDL_PollEvent(out SDL_Event e) == 1) {
            switch(e.type) {
                case SDL_EventType.SDL_QUIT:
                    running = false;
                    break;
            }
        }
    }

    /// <summary>
    /// Renders to the window.
    /// </summary>
    public static void Render() {

        //Sets the color that the screen will be cleared with.
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);

        //Clears the current render surface.
        SDL_RenderClear(renderer);

        foreach(Shape shape in shapes) {
            shape.Draw();
        }

        //Switches out the currently presented render surface with the one we just did work on.
        SDL_RenderPresent(renderer);

    }

    /// <summary>
    /// Cleans up the resources that were created.
    /// </summary>
    public static void CleanUp() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(renderer);
        SDL_Quit();
    }
    
}