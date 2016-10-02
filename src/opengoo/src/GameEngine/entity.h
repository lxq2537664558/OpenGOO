#pragma once

#include <memory>

#include <QPainter>
#include <QVector2D>

#include "graphic.h"

#include "og_types.h"
#include "Colliders/collider.h"

namespace og
{
class Scene;

class Entity
{
    GraphicPtr m_graphic;
    QVector2D m_position;
    bool m_visible;
    Scene* m_scene;
    std::shared_ptr<Collider> m_collider;

    Entity(const Entity&);
    Entity& operator=(const Entity&);

public:
    Entity(const QVector2D& a_position, GraphicPtr a_graphic)
        : m_position(a_position)
    {
        m_graphic = a_graphic;
        m_visible = true;
        m_scene = nullptr;
    }

    Entity(float a_x, float a_y, GraphicPtr a_graphic)
        : m_position(a_x, a_y)
    {
        m_graphic = a_graphic;
        m_visible = true;
    }

    Entity(float a_x, float a_y)
        : m_position(a_x, a_y)
    {
        m_visible = false;
        m_scene = nullptr;
    }

    virtual ~Entity()
    {
    }

    virtual void Update()
    {
    }

    virtual void Render(QPainter& a_painter)
    {
        if (m_visible)
            m_graphic->Render(a_painter, m_position);
    }

    void SetGraphic(GraphicPtr a_g)
    {
        SetVisible(true);
        m_graphic = a_g;
    }

    void SetVisible(float a_flag)
    {
        m_visible = a_flag;
    }

    virtual void Added()
    {
    }

    virtual void Removed()
    {
    }

    virtual void OnTriggerEnter(Fixture* /*a_fixture*/)
    {
    }

    virtual void OnTriggerExit(Fixture* /*a_fixture*/)
    {
    }

    virtual void OnMouseDown()
    {
    }

    virtual void OnMouseUp()
    {
    }

    void SetScene(Scene* a_scene)
    {
        m_scene = a_scene;
    }

    Scene* GetScene() const
    {
        return m_scene;
    }

    const Collider* GetCollider() const
    {
        return m_collider.get();
    }

    void SetCollider(std::shared_ptr<Collider> a_collider)
    {
        m_collider = a_collider;
    }

    void SetPosition(const QVector2D& a_position)
    {
        m_position = a_position;
    }

    const QVector2D& GetPosition() const
    {
        return m_position;
    }
};
}

typedef std::shared_ptr<og::Entity> EntityPtr;

