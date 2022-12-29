
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public class Boid {

    private Vector2 position;
    private Vector2 velocity;

    private float separationFactor;
    private float alignmentFactor;
    private float cohesionFactor;
    private float turnFactor;

    private float minSpeed;
    private float maxSpeed;

    private float viewDist;
    private float protectedDist;

    private float viewRange;

    public Polygon body;

    private Flock flock;

    public Boid(Flock _flock, Vector2 _pos, float _seperationFactor, float _alignmentFactor, float _cohesionFactor, float _turnFactor, float _minSpeed, float _maxSpeed, float _viewDist, float _protectedDist, float _viewRange) {
        
        flock = _flock;
        body = GenerateBody();
        
        position = _pos;

        separationFactor = _seperationFactor;
        alignmentFactor = _alignmentFactor;
        cohesionFactor = _cohesionFactor;
        turnFactor = _turnFactor;

        minSpeed = _minSpeed;
        maxSpeed = _maxSpeed;

        velocity = Vector2.RandomVector(-maxSpeed, maxSpeed);
        Console.WriteLine(velocity.x + " " + velocity.y);

        viewDist = _viewDist;
        protectedDist = _protectedDist;

        viewRange = _viewRange;
        
    }

    public void Update() {

        Vector2 close = Vector2.zero;
        Vector2 velAvg = Vector2.zero;
        Vector2 posAvg = Vector2.zero;
        int neighbouringBoids = 0;

        for(int i = 0; i < flock.boids.Count; i++) {

            if(flock.boids[i] == this) {
                continue;
            }

            Vector2 diff = position - flock.boids[i].position;
            if(Vector2.Angle(velocity, diff) > viewRange) {
                continue;
            }

            if(Vector2.Distance(position, flock.boids[i].position) <= protectedDist) {
                    close += (position - flock.boids[i].position);
            }
            if(Vector2.Distance(position, flock.boids[i].position) <= viewDist) {
                velAvg += flock.boids[i].velocity;
                posAvg += flock.boids[i].position;
                neighbouringBoids++;
            }

        }

        //Maybe it is possible to rotate the boids with the following equation:
        //https://www.quora.com/If-a-vector-of-magnitude-A-is-rotated-through-certain-degree-than-what-is-change-in-that-vector

        if(position.x > flock.rightBound - protectedDist) {
            Console.WriteLine("Right");
            velocity.x -= turnFactor;
        }
        if(position.x < flock.leftBound + protectedDist) {
            Console.WriteLine("Left");
            velocity.x += turnFactor;
        }
        if(position.y < flock.upperBound + protectedDist) {
            Console.WriteLine("Upper");
            velocity.y += turnFactor;
        }
        if(position.y > flock.lowerBound - protectedDist) {
            Console.WriteLine("Lower");
            velocity.y -= turnFactor;
        }

        if(neighbouringBoids > 0) {
            velAvg /= neighbouringBoids;
            posAvg /= neighbouringBoids;
        }

        velocity += close * separationFactor;
        //velocity += (velAvg - velocity) * alignmentFactor;
        //velocity += (posAvg - position) * cohesionFactor;

        if(velocity.magnitude < minSpeed) {
            velocity *= (minSpeed / velocity.magnitude);
        }
        else if(velocity.magnitude > maxSpeed) {
            velocity *= (maxSpeed / velocity.magnitude);
        }

        position += velocity;

        body.position = position;
        if(velocity.y < 0) {
            body.rotation = -Vector2.Angle(Vector2.right, velocity);
        }
        else {
            body.rotation = Vector2.Angle(Vector2.right, velocity);
        }

    }

    private Polygon GenerateBody() {
        
        Polygon poly = new Polygon(position.x, position.y, Colour.white,
                                   new Vector2(8, 0),
                                   new Vector2(-10, 6),
                                   new Vector2(-6, 0),
                                   new Vector2(-10, -6));

        return poly;

    }

}