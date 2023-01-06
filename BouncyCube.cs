
using System;
using System.Collections;
using System.Collections.Generic;
using ZaephusEngine;

public class BouncyCube : GameObject {

    private Rectangle body;
    private BoxCollider collider;

    private float horSpeed = 2;
    private float verSpeed = 1.8f;

    public BouncyCube(float _x, float _y) : base(_x, _y) {
        body = new Rectangle(this, Colour.magenta);
        collider = new BoxCollider(this);
        collider.OnCollision += HandleCollision;
    }

    public override void Start() {
        base.Initialize(body, collider);
        base.Start();
    }

    public override void Update() {
        base.Update();

        transform.position += new Vector2(horSpeed, verSpeed);

    }

    public override void Exit() {
        base.Exit();
    }

    private void HandleCollision(CollisionInfo _info) {

        Vector2 pointAvg = Vector2.zero;

        foreach(Vector2 point in _info.collidedPoints) {
            pointAvg += point;
        }

        pointAvg /= _info.collidedPoints.Count;
        Vector2 diff = pointAvg - transform.position;

        if(diff.x >= 50 || diff.x <= -50) {
            horSpeed = -horSpeed;
        } 
        if(diff.y >= 50 || diff.y <= -50) {
            verSpeed = -verSpeed;
        }

    }

}