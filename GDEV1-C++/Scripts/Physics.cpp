#include "Physics.h"


Physics::Physics() {}

Physics& Physics::getInstance() {
    static Physics instance;
    return instance;
}

//Compare all colliders and check for collision.
void Physics::castCollider(Collider& collider)
{
    for (unsigned int i = 0; i < colliders.size(); ++i) {
        Collider& c = *colliders.at(i);
        float distance = (collider.position - c.position).magnitude() - (collider.getRadius() + c.getRadius());
        if (distance < 0) 
        {
            if (&c != &collider) 
            {
                c.onCollision(collider);
                collider.onCollision(c);
            }
        }
    }
}