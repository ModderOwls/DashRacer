#include "Physics.h"


vector<shared_ptr<Collider>> colliders;

void castCollider(Collider& collider)
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