
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;
using static SDL2.SDL;

public static class Game {

    public static List<Collider> colliders = new List<Collider>();

    private static GameObject box = new GameObject(100, 200);

    private static GameObject leftBound = new GameObject(550, 240, 0 , 0.2f, 3);

    private static BoxCollider bc;

    public static void Start() {

        box.Initialize(new Rectangle(box, Colour.yellow),
                       new BoxCollider(box));
        box.Start();

        bc = box.GetComponent(typeof(BoxCollider)) as BoxCollider;

        //leftBound.Initialize(new Rectangle(leftBound, Colour.black),
                            // new BoxCollider(leftBound));
        //leftBound.Start();

        Console.WriteLine(colliders.Count);

    }

    public static void Update() {

        Vector2Int mousePos;

        SDL_GetMouseState(out mousePos.x, out mousePos.y);

        //bc.Update();

        box.transform.rotation += 0.05f;

        box.Update();
        Console.WriteLine(bc.OverlapPoint(new Vector2(mousePos.x, mousePos.y)));
        //box.transform.position += new Vector2(1.6f, 0);
        //leftBound.Update();

    }

    public static void Exit() {

        box.Exit();
        //leftBound.Exit();

    }

}