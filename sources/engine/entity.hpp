#pragma once
#include <Box2D/Box2D.h>
#include "raylib.h"

constexpr double pi = 3.14159265358979323846;

class Entity
{
protected:
	Vector2 m_position;
	float m_angle;

public:
	Entity() 
		: m_position(Vector2{ 0,0 }), m_angle(180) {};
	Entity(int positionX, int positionY, float angle)
		:m_position{ Vector2{ (float)positionX, (float)positionY } }, m_angle{ angle  } {};
	virtual void draw() {};
	Vector2 getPosition() {
		return m_position;
	};
	void setPosition(Vector2 position) {
		m_position = position;
	};
};

class PhysicsEntity : public Entity
{
	using Entity::Entity;

protected:
	b2Body* m_body;

public:
	PhysicsEntity(int positionX, int positionY, float angle, b2Body* body)
		: m_body{ body }{};

	void applyPhysicsPosition() {
		m_position = Vector2{ (float)m_body->GetPosition().x * SCALE, (float)m_body->GetPosition().y * SCALE};
	};

	float getBodyAngle() {
		return m_body->GetAngle() * 180 / pi;
	}

	void applyForce(b2Vec2 directionVector) {
		m_body->ApplyForce(directionVector, m_body->GetWorldCenter(), true);
	}
};