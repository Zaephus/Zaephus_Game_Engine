
using System;
using System.Collections;
using System.Collections.Generic;
using static SDL2.SDL;
using static SDL2.SDL_image;
using ZaephusEngine;

// SDL2 for CSharp via https://github.com/flibitijibibo/SDL2-CS
// Install package via https://www.nuget.org/packages/Sayers.SDL2.Core/
// Tutorial at https://jsayers.dev/c-sdl-tutorial-part-3-drawing-shapes/

public static class General {
    
    public static List<Shape> shapes = new List<Shape>();

    public static IntPtr window;
    public static IntPtr renderer;

    private static bool running = true;

    private const int WIDTH = 640;
    private const int HEIGHT = 480;

    static void Main(string[] args) {

        Setup();

        while(running) {
            PollEvents();
            Render();
        }

        CleanUp();

    }

    /// <summary>
    /// Setup all of the SDL resources needed to display a window.
    /// </summary>
    private static void Setup() {

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
    private static void PollEvents() {
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
    private static void Render() {

        //Sets the color that the screen will be cleared with.
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);

        //Clears the current render surface.
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        Rectangle test = new Rectangle(250, 400, 75, 75);
        //test.Draw();

        Hexagon hex = new Hexagon(100, 100, 50);
        //hex.Draw();

        foreach(Shape shape in shapes) {
            shape.Draw();
        }

        //Switches out the currently presented render surface with the one we just did work on.
        SDL_RenderPresent(renderer);

    }

    /// <summary>
    /// Cleans up the resources that were created.
    /// </summary>
    private static void CleanUp() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(renderer);
        SDL_Quit();
    }

}

public abstract class Shape {

    public Shape() {
        General.shapes.Add(this);
    }
    public abstract void Draw();
    
}

public class Rectangle : Shape {

    private SDL_Rect rect;

    public Rectangle(int _x, int _y, int _w, int _h) : base() {
        rect = new SDL_Rect {
            x = _x,
            y = _y,
            w = _w,
            h = _h
        };
    }

    public override void Draw() {
        SDL_RenderFillRect(General.renderer, ref rect);
    }

}

public class Hexagon : Shape {

    private Vector2Int[] points = new Vector2Int[6];

    public Hexagon(float _x, float _y, float _r) : base() {
        points[0] = new Vector2Int(_x + _r, _y);
        points[1] = new Vector2Int(_x + _r / 2, _y + (MathF.Sqrt(3) * _r) / 2);
        points[2] = new Vector2Int(_x - _r / 2, _y + (MathF.Sqrt(3) * _r) / 2);
        points[3] = new Vector2Int(_x - _r, _y);
        points[4] = new Vector2Int(_x - _r / 2, _y - (MathF.Sqrt(3) * _r) / 2);
        points[5] = new Vector2Int(_x + _r / 2, _y - (MathF.Sqrt(3) * _r) / 2);
    }

    public override void Draw() {
        for(int i = 0; i < points.Length - 1; i++) {
            SDL_RenderDrawLine(General.renderer, points[i].x, points[i].y, points[i+1].x, points[i+1].y);
        }
        SDL_RenderDrawLine(General.renderer, points[points.Length-1].x, points[points.Length-1].y, points[0].x, points[0].y);
    }

}