
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;
using Random = ZaephusEngine.Random;

public class Game {

    public Flock flock = new Flock(25);

    public void Setup() {}

    public void Update() {

        flock.Update();

    }

}