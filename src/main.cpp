#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main() {
    // Create a window with a title and dimensions (800x600)
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simple SFML Game");

    // Set the frame rate limit to make the movement smooth
    window.setFramerateLimit(60);

    // Create a player (rectangle)
    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setFillColor(sf::Color::Blue);
    player.setPosition(375, 500); // Start at the bottom center of the window

    // Create an enemy (circle)
    sf::CircleShape enemy(30);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(100, 0); // Start at the top-left corner

    // Set the movement speed for player and enemy
    float playerSpeed = 5.0f;
    float enemySpeed = 3.0f;

    // Main game loop
    while (window.isOpen()) {
        // Process events (keyboard, window close, etc.)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Move the player with arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-playerSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(playerSpeed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0, -playerSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move(0, playerSpeed);
        }

        // Move the enemy downwards
        enemy.move(0, enemySpeed);

        // Reset enemy position if it goes off screen
        if (enemy.getPosition().y > 600) {
            enemy.setPosition(rand() % 750, 0); // Random horizontal reset position
        }

        // Check for collision between player and enemy
        if (player.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
            // Reset player and enemy position on collision
            player.setPosition(375, 500);
            enemy.setPosition(100, 0);
        }

        // Clear the window with a black background
        window.clear(sf::Color::Black);

        // Draw the player and enemy
        window.draw(player);
        window.draw(enemy);

        // Display the content of the window
        window.display();
    }

    return 0;
}
