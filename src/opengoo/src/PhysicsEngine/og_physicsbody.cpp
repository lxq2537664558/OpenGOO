#include "og_physicsbody.h"

OGPhysicsBody::OGPhysicsBody(float32 x, float32 y, bool dynamic)
{
    if (dynamic) { bodydef.type = b2_dynamicBody; }

    bodydef.position.Set(x, y);
}

OGPhysicsBody::OGPhysicsBody(float32 x, float32 y, bool dynamic, float32 angle)
{
    if (dynamic) { bodydef.type = b2_dynamicBody; }

    bodydef.position.Set(x, y);
    bodydef.angle = angle;
}

void OGPhysicsBody::CreateFixture(float32 density)
{
    fixture = body->CreateFixture(shape->shape, density);
}

void OGPhysicsBody::CreateFixture(float32 density, float32 friction
                                  , float32 restitution
                                  )
{
    b2FixtureDef fixtureDef;

    fixtureDef.shape = shape->shape;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.restitution = restitution;
    fixture = body->CreateFixture(&fixtureDef);
}

void OGPhysicsBody::CreateShape(Type type)
{
    switch(type)
    {
    case CIRCLE:
        shape = new OGPhysicsShape(b2Shape::e_circle);
        break;

    case POLYGON:
        shape = new OGPhysicsShape(b2Shape::e_polygon);
        break;

    case EDGE:
        shape = new OGPhysicsShape(b2Shape::e_edge);
        break;

    case CHAIN:
        shape = new OGPhysicsShape(b2Shape::e_chain);
        break;
    }
}
