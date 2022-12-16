
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

    private Polygon body;

    private Flock flock;

    public Boid(Flock _flock, Vector2 _pos, float _seperationFactor, float _alignmentFactor, float _cohesionFactor, float _viewDist, float _protectedDist) {
        
        flock = _flock;
        body = GenerateBody();
        
        position = _pos;
        //velocity = Vector2.random;

        separationFactor = _seperationFactor;
        alignmentFactor = _alignmentFactor;
        cohesionFactor = _cohesionFactor;

        viewDist = _viewDist;
        protectedDist = _protectedDist;
        
    }

    public void Update() {

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