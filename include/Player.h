// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define IS_IN_RANGE(value, min, max) ((value) >= (min) && (value) <= (max))

class Player : public GameObject {
public:
    Player(){
        angle = 0;
        tilt = 0;
    }

    bool checkCollision(const GameObject& other) const {
        return other.getShape().getGlobalBounds().intersects(getShape().getGlobalBounds());
    }

    void handleInput() {
        // Handle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            tilt -= scaleFactor;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            tilt += scaleFactor;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && angle < 45) { 
            angle -= angleFactor;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && angle > -45) { 
            angle += angleFactor;
        }

        getShape().setRotation(angle);

        setScaleWithBoundaries();

        equalize();
    }

    void setScaleWithBoundaries()
    {
        if (getShape().getScale().x > maxScale)
            getShape().setScale(sf::Vector2f(maxScale, maxScale));
        else if (getShape().getScale().x < minScale)
            getShape().setScale(sf::Vector2f(minScale, minScale));
        else
            getShape().scale(sf::Vector2f(1 + tilt, 1 + tilt));
    }

    void equalize()
    {
        float xComponent = cos(angle * (M_PI / 180.0f));
        float yComponent = sin(angle * (M_PI / 180.0f));

        move(0, yComponent * playerSpeed);

        if (angle > 0)
            angle -= angleReturnFactor;
        if (angle < 0)
            angle += angleReturnFactor;

        if (tilt > 0)
            tilt -= tiltReturnFactor;
        if (tilt < 0)
            tilt += tiltReturnFactor;
    }

private:
    float playerSpeed = 0.5;
    float scaleFactor = 0.00000015;
    float angleFactor = 0.015;

    float angleReturnFactor = 0.005;
    float tiltReturnFactor = 0.00000001;

    float angle;
    float tilt;

    const float maxScale = 1.2f;
    const float minScale = 0.15f;
};

#endif // PLAYER_H
