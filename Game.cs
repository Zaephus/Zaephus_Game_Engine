
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public class Game {

    Rectangle rect = new Rectangle(250, 400, 75, 75, Colour.blue);
    Hexagon hex = new Hexagon(100, 100, 50, Colour.yellow);
    Ellipse ellipse = new Ellipse(200, 100, 100, 80, Colour.magenta);
    Polygon poly = new Polygon(400, 200, Colour.red,
                               new Vector2(50, 0),
                               new Vector2(10, 10),
                               new Vector2(0, 50),
                               new Vector2(-10, 10),
                               new Vector2(-50, 0),
                               new Vector2(-10, -10),
                               new Vector2(0, -50),
                               new Vector2(10, -10));

    public void Setup() {
    }

    public void Update() {

        hex.position = new Vector2(hex.position.x+0.1f, hex.position.y+0.1f);
        hex.rotation = 1;
        rect.position = new Vector2(rect.position.x+1, rect.position.y-1);
        rect.rotation = 2;

        ellipse.rotation += 0.02f;

        poly.rotation += 0.005f;

    }

}