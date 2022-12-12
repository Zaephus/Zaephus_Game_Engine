
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public class Game {

    Rectangle rect = new Rectangle(250, 400, 75, 75, Colour.blue);
    Hexagon hex = new Hexagon(100, 100, 50, Colour.yellow);
    Circle circle = new Circle(100, 100, 60, Colour.magenta);


    public void Setup() {
    }

    public void Update() {
        hex.position = new Vector2(hex.position.x+1, hex.position.y+1);
        rect.rect = new Vector4(rect.rect.x+1, rect.rect.y-1, rect.rect.z, rect.rect.w);

    }

}