
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;
using Random = ZaephusEngine.Random;

public class Flock {
    
    private float separationFactor = 0.001f;
    private float alignmentFactor = 0.0005f;
    private float cohesionFactor = 0.00005f;

    private float viewDist = 150;
    private float protectedDist = 50;

    public List<Boid> boids = new List<Boid>();

    public Vector2[] rightBounds = new Vector2[] {
        new Vector2(Window.WIDTH, 0),
        new Vector2(Window.WIDTH, Window.HEIGHT)
    };
    public Vector2[] leftBounds = new Vector2 [] {
        new Vector2(0, 0),
        new Vector2(0, Window.HEIGHT)
    };
    public Vector2[] upperBounds = new Vector2 [] {
        new Vector2(0, 0),
        new Vector2(Window.WIDTH, 0)
    };
    public Vector2[] bottomBounds = new Vector2 [] {
        new Vector2(0, Window.HEIGHT),
        new Vector2(Window.WIDTH, Window.HEIGHT)
    };

    public Flock(int _boidAmount) {
        for(int i = 0; i < _boidAmount; i++) {
            boids.Add(new Boid(
                this,
                new Vector2(Random.Range(0, Window.WIDTH), Random.Range(0, Window.HEIGHT)),
                separationFactor,
                alignmentFactor,
                cohesionFactor,
                viewDist,
                protectedDist
            ));
        }
    }

    public void Update() {
        foreach(Boid b in boids) {
            b.Update();
            //b.body.rotation += 0.01f;
        }
    }

}