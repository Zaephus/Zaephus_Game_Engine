
using System;
using System.Collections;
using System.Collections.Generic;

namespace ZaephusEngine {

    public class GameObject {

        public Transform transform;

        private List<Component> components = new List<Component>();

        public GameObject() : this(0, 0, 0, 1, 1) {}
        public GameObject(float _x, float _y) : this(_x, _y, 0, 1, 1) {}
        public GameObject(float _x, float _y, float _r) : this(_x, _y, _r, 1, 1) {}
        public GameObject(float _x, float _y, float _r, float _w, float _h) {
            transform = new Transform(this);
            transform.position = new Vector2(_x, _y);
            transform.rotation = _r;
            transform.scale = new Vector2(_w, _h);
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

        public Component GetComponent(Type _type) {
            foreach(Component c in components) {
                if(c.GetType() == _type) {
                    return c;
                }
            }
            return null;
        }

        public List<Component> GetComponents(Type _type) {
            List<Component> foundComponents = new List<Component>();
            foreach(Component c in components) {
                if(c.GetType() == _type) {
                    foundComponents.Add(c);
                }
            }
            return foundComponents;
        }

    }

}