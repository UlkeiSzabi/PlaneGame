// GameObject.h
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>

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

    void setTexture(int resourceID) {
        this->texture = loadTextureFromResource(resourceID);
        shape.setTexture(texture);
    }

    void setPosition(float x, float y) {
        shape.setPosition(sf::Vector2f(x, y));
    }

    void move(float x, float y) {
        shape.move(x, y);
    }

    private:
    // Function to load texture from a resource
    sf::Texture loadTextureFromResource(int resourceId) {
        // Get a handle to the current module
        HMODULE hModule = GetModuleHandle(nullptr);
        if (!hModule) {
            std::cerr << "Failed to get module handle." << std::endl;
            throw std::runtime_error("Failed to get module handle");
        }

        // Find the resource by ID
        HRSRC hResource = FindResourceA(hModule, MAKEINTRESOURCE(resourceId), MAKEINTRESOURCE(301));
        if (!hResource) {
            std::cerr << "Failed to find resource ID: " << resourceId << std::endl;
            throw std::runtime_error("Failed to find resource");
        }

        // Load the resource
        HGLOBAL hLoadedResource = LoadResource(hModule, hResource);
        if (!hLoadedResource) {
            std::cerr << "Failed to load resource ID: " << resourceId << std::endl;
            throw std::runtime_error("Failed to load resource");
        }

        // Lock the resource to get a pointer to the data
        void* pResourceData = LockResource(hLoadedResource);
        DWORD resourceSize = SizeofResource(hModule, hResource);

        // Check if the resource size is valid
        if (resourceSize == 0) {
            std::cerr << "Resource size is zero for ID: " << resourceId << std::endl;
            throw std::runtime_error("Resource size is zero");
        }

        // Load the texture from the resource data
        sf::Texture texture;
        if (!texture.loadFromMemory(pResourceData, resourceSize)) {
            std::cerr << "Failed to load texture from resource data for ID: " << resourceId << std::endl;
            throw std::runtime_error("Failed to load texture from resource data");
        }

        return texture;
    }

    private:
    sf::Sprite shape;
    sf::Texture texture;
};

#endif // GAMEOBJECT_H
