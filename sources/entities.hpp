#include "./engine/entity.hpp"

class Shape : public Entity {
    using Entity::Entity;
public:
    void draw() {
        Rectangle rec = { m_position.x, m_position.y, 120, 60 };
        DrawRectanglePro(rec, { 60, 30 }, m_angle, RED);
    }
};

class Box : public PhysicsEntity {
    using PhysicsEntity::PhysicsEntity;
public:
    void draw() {
        Rectangle rec = { m_position.x, m_position.y, 120, 60 };
        DrawRectanglePro(rec, { 60, 30 }, m_body->GetAngle(), RED);
    }
};

class Ground : public PhysicsEntity {
    using PhysicsEntity::PhysicsEntity;
public:
    void draw() {
        Rectangle rec = { m_position.x, m_position.y, Settings::screenWidth, 60 };
        DrawRectanglePro(rec, { Settings::screenWidth / 2, 30 }, m_body->GetAngle(), BLACK);
    }
};