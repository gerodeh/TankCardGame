#ifndef TextureManager_H
#define TextureManager_H

#include "SFML/Graphics.hpp"
#include <map>
#include <iostream>
#include <memory>
#include <iterator>

class TextureManager
{
    std::map<sf::String, std::unique_ptr<sf::Texture>> textures;
public:

    void LoadTexture(const sf::String& path, const sf::String& name);

    sf::Texture& GetTextureRef(const sf::String& name);
};

#endif // TextureManager_H
