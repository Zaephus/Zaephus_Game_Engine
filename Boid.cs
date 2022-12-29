
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

    //Using the following article for reference of the boid simulation:
    //https://vanhunteradams.com/Pico/Animal_Movement/Boids-algorithm.html

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

        velocity = Vector2.RandomVector(-maxSpeed, maxSpeed);

        viewDist = _viewDist;
        protectedDist = _protectedDist;
        
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

            if(Vector2.Distance(position, flock.boids[i].position) <= protectedDist) {
                    close += (position - flock.boids[i].position);
            }
            if(Vector2.Distance(position, flock.boids[i].position) <= viewDist) {
                velAvg += flock.boids[i].velocity;
                posAvg += flock.boids[i].position;
                neighbouringBoids++;
            }

        }

        if(position.x > flock.rightBound - protectedDist) {
            if(velocity.y < 0) {
                velocity.Rotate(-turnFactor);
            }
            else {
                velocity.Rotate(turnFactor);
            }
        }
        else if(position.x < flock.leftBound + protectedDist) {
            if(velocity.y < 0) {
                velocity.Rotate(turnFactor);
            }
            else {
                velocity.Rotate(-turnFactor);
            }
        }
        else if(position.y < flock.upperBound + protectedDist) {
            if(velocity.x < 0) {
                velocity.Rotate(-turnFactor);
            }
            else {
                velocity.Rotate(turnFactor);
            }
        }
        else if(position.y > flock.lowerBound - protectedDist) {
            if(velocity.x < 0) {
                velocity.Rotate(turnFactor);
            }
            else {
                velocity.Rotate(-turnFactor);
            }
        }

        velocity += close * separationFactor;

        if(neighbouringBoids > 0) {
            velAvg /= neighbouringBoids;
            posAvg /= neighbouringBoids;

            velocity += (velAvg - velocity) * alignmentFactor;
            velocity += (posAvg - position) * cohesionFactor;
        }

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