// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

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
            move(-1 * playerSpeed, 0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
            move(playerSpeed, 0); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
            move(0, -1 * playerSpeed); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            move(0, playerSpeed); 
        }   
    }
private:
    float playerSpeed = 0.5;
};

#endif // PLAYER_H
