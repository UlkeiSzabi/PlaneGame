#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include <iostream>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Simple 2D Game");

    // Create player object
    Player player;
    player.setPosition(100, 300); // Start in the center of the window
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("resources/enemy.png")) {
        std::cerr << "Error loading texture!" << std::endl;
        return -1;
    }
    player.setTexture(playerTexture);

    // Create a second object (obstacle)
    GameObject obstacle;
    obstacle.setPosition(500, 300); // Position the obstacle
    obstacle.setTexture(playerTexture);

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput();

        // Check for collision
        if (player.checkCollision(obstacle)) {
            // Handle collision (for now, just print to console)
            std::cout << "Collision detected!" << std::endl;
        }

        // Clear the window
        window.clear(sf::Color(173, 216, 230));
        // Draw the player and obstacle
        window.draw(player.getShape());
        window.draw(obstacle.getShape());
        // Display the contents of the window
        window.display();
    }

    return 0;
}
