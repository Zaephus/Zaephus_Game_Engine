
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;
using Random = ZaephusEngine.Random;

public class Flock {

    public List<Boid> boids = new List<Boid>();

    public float rightBound = Window.WIDTH - 100;
    public float leftBound = 100;
    public float upperBound = 100;
    public float lowerBound = Window.HEIGHT - 100;
    
    private float separationFactor = 0.002f;
    private float alignmentFactor = 0.05f;
    private float cohesionFactor = 0.002f;
    private float turnFactor = 0.08f;

    private float minSpeed = 1f;
    private float maxSpeed = 4f;

    private float viewDist = 100;
    private float protectedDist = 30;

    private float viewRange = 2;

    public Flock(int _boidAmount) {

        new Rectangle(Window.WIDTH / 2, Window.HEIGHT / 2, (int)(rightBound - leftBound), (int)(lowerBound - upperBound), Colour.black);

        for(int i = 0; i < _boidAmount; i++) {
            boids.Add(new Boid(
                this,
                new Vector2(Random.Range(leftBound, rightBound), Random.Range(upperBound, lowerBound)),
                separationFactor,
                alignmentFactor,
                cohesionFactor,
                turnFactor,
                minSpeed,
                maxSpeed,
                viewDist,
                protectedDist,
                viewRange
            ));
        }

    }

    public void Update() {
        foreach(Boid b in boids) {
            b.Update();
        }
    }

}