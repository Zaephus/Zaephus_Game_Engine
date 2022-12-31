
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public class Game {

    GameObject gameObject = new GameObject(200, 200);

    public void Start() {
        gameObject.Initialize(new Rectangle(gameObject.transform, Colour.magenta),
                              new Ellipse(gameObject.transform, Colour.green),
                              new Hexagon(gameObject.transform, Colour.black));
        gameObject.Start();
    }

    public void Update() {
        gameObject.Update();
        gameObject.transform.scale *= 1.001f;
        gameObject.transform.rotation += 0.001f;
    }

    public void Exit() {
        gameObject.Exit();
    }

}