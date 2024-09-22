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
            getShape().scale(sf::Vector2f(1 - scaleFactor, 1 - scaleFactor));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            getShape().scale(sf::Vector2f(1 + scaleFactor, 1 + scaleFactor)); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
            if(angle < 45){
                angle += angleFactor;
                // getShape().rotate(angleFactor);
                // std::cout << angle << std::endl;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
             if(angle > -45){
                angle -= angleFactor;
                // getShape().rotate(-1 * angleFactor);
            }
        }

        getShape().setRotation(angle);

        float xComponent = cos(angle * (M_PI / 180.0f));
        float yComponent = sin(angle * (M_PI / 180.0f));
        
        move(0, yComponent * playerSpeed);

        if(angle > 0)
            angle -= returnFactor;
        if(angle < 0)
            angle += returnFactor;
    }
private:
    float playerSpeed = 0.5;
    float scaleFactor = 0.0005;
    float angleFactor = 0.015;
    float returnFactor = 0.005;

    float angle;
    float tilt;
};

#endif // PLAYER_H
