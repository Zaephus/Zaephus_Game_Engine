
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

    private float viewDist;
    private float protectedDist;

    public Polygon body;

    private Flock flock;

    public Boid(Flock _flock, Vector2 _pos, float _seperationFactor, float _alignmentFactor, float _cohesionFactor, float _viewDist, float _protectedDist) {
        
        flock = _flock;
        body = GenerateBody();
        
        position = _pos;
        velocity = Vector2.RandomVector(-0.5f, 0.5f);

        body.position = _pos;
        body.rotation = -2*Vector2.Angle(velocity, Vector2.right);

        separationFactor = _seperationFactor;
        alignmentFactor = _alignmentFactor;
        cohesionFactor = _cohesionFactor;

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

        if(MathF.Abs((flock.rightBounds[1].x - flock.rightBounds[0].x) * (flock.rightBounds[0].y - position.y) - (flock.rightBounds[0].x - position.x) * (flock.rightBounds[1].y - flock.rightBounds[0].y)) / Vector2.Distance(flock.rightBounds[0], flock.rightBounds[1]) <= protectedDist) {
            close -= Vector2.right;
        }
        if(MathF.Abs((flock.leftBounds[1].x - flock.leftBounds[0].x) * (flock.leftBounds[0].y - position.y) - (flock.leftBounds[0].x - position.x) * (flock.leftBounds[1].y - flock.leftBounds[0].y)) / Vector2.Distance(flock.leftBounds[0], flock.leftBounds[1]) <= protectedDist) {
            close += Vector2.right;
        }
        if(MathF.Abs((flock.upperBounds[1].x - flock.upperBounds[0].x) * (flock.upperBounds[0].y - position.y) - (flock.upperBounds[0].x - position.x) * (flock.upperBounds[1].y - flock.upperBounds[0].y)) / Vector2.Distance(flock.upperBounds[0], flock.upperBounds[1]) <= protectedDist) {
            close -= Vector2.up;
        }
        if(MathF.Abs((flock.bottomBounds[1].x - flock.bottomBounds[0].x) * (flock.bottomBounds[0].y - position.y) - (flock.bottomBounds[0].x - position.x) * (flock.bottomBounds[1].y - flock.bottomBounds[0].y)) / Vector2.Distance(flock.bottomBounds[0], flock.bottomBounds[1]) <= protectedDist) {
            close += Vector2.up;
        }

        if(neighbouringBoids > 0) {
            velAvg /= neighbouringBoids;
            posAvg /= neighbouringBoids;
        }

        velocity += close * separationFactor;
        velocity += (velAvg - velocity) * alignmentFactor;
        velocity += (posAvg - position) * cohesionFactor;

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