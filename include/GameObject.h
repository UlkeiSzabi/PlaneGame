// GameObject.h
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject(){}

    sf::Sprite& getShape() {
        return shape;
    }

    const sf::Sprite& getShape() const {
        return shape; // For read-only access
    }

    void setTexture(const sf::Texture& texture) {
        this->texture = texture;
        shape.setTexture(texture);
    }

    void setPosition(float x, float y) {
        shape.setPosition(sf::Vector2f(x, y));
    }

    void move(float x, float y) {
        shape.move(x, y);
    }

    private:
    sf::Sprite shape;
    sf::Texture texture;
};

#endif // GAMEOBJECT_H
