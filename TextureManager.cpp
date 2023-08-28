#include "TextureManager.h"

void TextureManager::LoadTexture(const sf::String& path, const sf::String& name)
{
    textures.emplace(std::make_pair(name, new sf::Texture));
    textures.at(name)->loadFromFile(path);
}

sf::Texture& TextureManager::GetTextureRef(const sf::String& name)
{
    return *textures.at(name);
}
