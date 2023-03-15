#pragma once
#include <stdio.h>
#include <Box2D/Box2D.h>
#include "settings.hpp"

struct BodyOptions
{
    BodyOptions(float desnity, float friction, float restitution) :density(desnity), friction(friction), restitution(restitution) {}
    float density;
    float friction;
    float restitution;
};

extern const float SCALE = 30.f;

class Physics {
private:
	b2Vec2 m_gravity;
	b2World m_world;
    std::vector<b2Body*> m_bodies;

public:
    Physics(b2Vec2 gravity = b2Vec2({0,0}))
        :m_gravity{ gravity }, m_world{ gravity } {};

    void makeWorldStep() {
        m_world.Step(1 / 60.f, 16, 6);
    }
    b2Body* getBody(
        int positionX, 
        int positionY, 
        int width, 
        int height, 
        bool dynamic,
        BodyOptions options
    ) {
        b2BodyDef BodyDef;
        BodyDef.position = b2Vec2(positionX / SCALE, positionY / SCALE);
        BodyDef.type = dynamic ? b2_dynamicBody : b2_staticBody;
        b2Body* Body = m_world.CreateBody(&BodyDef);

        b2PolygonShape Shape;
        Shape.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE);
        b2FixtureDef FixtureDef;

        FixtureDef.density = options.density;
        FixtureDef.friction = options.friction;
        FixtureDef.restitution = options.restitution;
        FixtureDef.shape = &Shape;
        
        Body->CreateFixture(&FixtureDef);
        return Body;
    }
    b2World* getWorld() {
        return &m_world;
    }
};