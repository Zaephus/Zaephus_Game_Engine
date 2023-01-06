
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;
using static SDL2.SDL;

public static class Game {

    public static List<Collider> colliders = new List<Collider>();

    private static BouncyCube bouncyCube = new BouncyCube(200, 500);
    private static BouncyCube bouncyCube2 = new BouncyCube(600, 350);
    private static BouncyCube bouncyCube3 = new BouncyCube(300, 400);
    private static BouncyCube bouncyCube4 = new BouncyCube(580, 580);

    private static GameObject rightBound = new GameObject(700, 400, 0 , 0.2f, 7);
    private static GameObject leftBound = new GameObject(100, 400, 0 , 0.2f, 7);
    private static GameObject upperBound = new GameObject(400, 100, 0 , 7, 0.2f);
    private static GameObject bottomBound = new GameObject(400, 700, 0 , 7, 0.2f);

    public static void Start() {

        bouncyCube.Start();
        bouncyCube2.Start();
        bouncyCube3.Start();
        bouncyCube4.Start();

        rightBound.Initialize(new Rectangle(rightBound, Colour.black),
                            new BoxCollider(rightBound));
        rightBound.Start();

        leftBound.Initialize(new Rectangle(leftBound, Colour.black),
                            new BoxCollider(leftBound));
        leftBound.Start();

        upperBound.Initialize(new Rectangle(upperBound, Colour.black),
                            new BoxCollider(upperBound));
        upperBound.Start();

        bottomBound.Initialize(new Rectangle(bottomBound, Colour.black),
                            new BoxCollider(bottomBound));
        bottomBound.Start();

    }

    public static void Update() {

        bouncyCube.Update();
        bouncyCube2.Update();
        bouncyCube3.Update();
        bouncyCube4.Update();
        
        rightBound.Update();
        leftBound.Update();
        upperBound.Update();
        bottomBound.Update();

    }

    public static void Exit() {

        bouncyCube.Exit();
        bouncyCube2.Exit();
        bouncyCube3.Exit();
        bouncyCube4.Exit();

        rightBound.Exit();
        leftBound.Exit();
        upperBound.Exit();
        bottomBound.Exit();

    }

}