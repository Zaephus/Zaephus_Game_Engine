
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public class Game {

    GameObject gameObject = new GameObject(200, 200);
    GameObject test = new GameObject(200, 200);
    GameObject test2 = new GameObject(200, 200);

    public void Start() {
        gameObject.Initialize(new Hexagon(gameObject, Colour.black));
        gameObject.Start();
        test.Initialize(new Ellipse(test, Colour.red));
        test.Start();
        test.transform.scale = new Vector2(0.2f, 0.2f);
        test2.Initialize(new Ellipse(test2, Colour.red));
        test2.Start();
        test2.transform.scale = new Vector2(0.2f, 0.2f);
    }

    public void Update() {
        gameObject.Update();
        gameObject.transform.rotation += 0.001f;
        test.transform.position = gameObject.transform.position + (gameObject.transform.up * 50);
        test.Update();
        test2.transform.position = gameObject.transform.position + (gameObject.transform.right * 50);
        test2.Update();
    }

    public void Exit() {
        gameObject.Exit();
        test.Exit();
        test2.Exit();
    }

}