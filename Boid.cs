
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

    public Polygon body;

    private Flock flock;

    public Boid(Flock _flock, Vector2 _pos, float _seperationFactor, float _alignmentFactor, float _cohesionFactor, float _turnFactor, float _minSpeed, float _maxSpeed, float _viewDist, float _protectedDist) {
        
        flock = _flock;
        body = GenerateBody();
        
        position = _pos;

        separationFactor = _seperationFactor;
        alignmentFactor = _alignmentFactor;
        cohesionFactor = _cohesionFactor;
        turnFactor = _turnFactor;

        minSpeed = _minSpeed;
        maxSpeed = _maxSpeed;

        velocity = Vector2.RandomVector(-minSpeed, minSpeed);

        viewDist = _viewDist;
        protectedDist = _protectedDist;
        
    }

    public void Update() {

        Vector2 close = Vector2.zero;
        Vector2 velAvg = Vector2.zero;
        Vector2 posAvg = Vector2.zero;
        int neighbouringBoids = 0;

        foreach(Boid b in flock.boids) {
            if(b != this) {
                if(Vector2.Distance(position, b.position) <= protectedDist) {
                    close += (position - b.position);
                }
                if(Vector2.Distance(position, b.position) <= viewDist) {
                    velAvg += b.velocity;
                    posAvg += b.position;
                    neighbouringBoids++;
                }
            }
        }

        if(position.x > flock.rightBound - protectedDist) {
            velocity.x -= turnFactor;
        }
        if(position.x < flock.leftBound + protectedDist) {
            velocity.x += turnFactor;
        }
        if(position.y < flock.upperBound + protectedDist) {
            velocity.y += turnFactor;
        }
        if(position.y > flock.lowerBound - protectedDist) {
            velocity.y -= turnFactor;
        }

        if(neighbouringBoids > 0) {
            velAvg /= neighbouringBoids;
            posAvg /= neighbouringBoids;
        }

        velocity += close * separationFactor;
        velocity += (velAvg - velocity) * alignmentFactor;
        velocity += (posAvg - position) * cohesionFactor;

        if(velocity.magnitude < minSpeed) {
            velocity = velocity.normalized * minSpeed;
        }
        else if(velocity.magnitude > maxSpeed) {
            velocity = velocity.normalized * maxSpeed;
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