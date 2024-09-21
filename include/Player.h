// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>


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
                        std::cout << "shape down!" << std::endl;
}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
            getShape().scale(sf::Vector2f(1 - scaleFactor, 1 - scaleFactor)); 
                        std::cout << "shape up!" << getShape().getScale().x << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { 
            move(0, playerSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            move(0, -1 * playerSpeed);
        }   
    }
private:
    float playerSpeed = 0.5;
    float scaleFactor = 0.005;
};

#endif // PLAYER_H
