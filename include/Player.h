// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define IS_IN_RANGE(value, min, max) ((value) >= (min) && (value) <= (max))

class Player : public GameObject {
public:
    Player(){
    }

    bool checkCollision(const GameObject& other) const {
        return other.getShape().getGlobalBounds().intersects(getShape().getGlobalBounds());
    }

    void handleInput() {
        // Handle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {  
            getShape().scale(sf::Vector2f(1 + scaleFactor, 1 + scaleFactor));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
            getShape().scale(sf::Vector2f(1 - scaleFactor, 1 - scaleFactor)); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
            move(0, -1 * playerSpeed);
            getShape().rotate(angleFactor);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            move(0, playerSpeed);
            getShape().rotate(-angleFactor);
        }   
    }
private:
    float playerSpeed = 0.1;
    float scaleFactor = 0.005;
    float angleFactor = 0.05;
};

#endif // PLAYER_H
