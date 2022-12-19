
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;
using Random = ZaephusEngine.Random;

public class Flock {

    public List<Boid> boids = new List<Boid>();

    public float rightBound = Window.WIDTH;
    public float leftBound = 0;
    public float upperBound = 0;
    public float lowerBound = Window.HEIGHT;
    
    private float separationFactor = 0.08f;
    private float alignmentFactor = 0.05f;
    private float cohesionFactor = 0.008f;
    private float turnFactor = 0.2f;

    private float minSpeed = 0.3f;
    private float maxSpeed = 2f;

    private float viewDist = 100;
    private float protectedDist = 40;

    public Flock(int _boidAmount) {
        for(int i = 0; i < _boidAmount; i++) {
            boids.Add(new Boid(
                this,
                new Vector2(Random.Range(0, Window.WIDTH), Random.Range(0, Window.HEIGHT)),
                separationFactor,
                alignmentFactor,
                cohesionFactor,
                turnFactor,
                minSpeed,
                maxSpeed,
                viewDist,
                protectedDist
            ));
        }
    }

    public void Update() {
        foreach(Boid b in boids) {
            b.Update();
        }
    }

}