
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class GameObject {

        public Transform transform = new Transform();

        private List<Component> components = new List<Component>();

        public GameObject(float _x, float _y) {
            transform.position = new Vector2(_x, _y);
            transform.scale = Vector2.one;
        }

        public void Initialize(params Component[] _components) {
            components.Add(transform);
            components.AddRange(_components);
        }

        public virtual void Start() {
            foreach(Component c in components) {
                c.Start();
            }
        }

        public virtual void Update() {
            foreach(Component c in components) {
                c.Update();
            }
        }

        public virtual void Exit() {
            foreach(Component c in components) {
                c.Exit();
            }
        }

    }

}