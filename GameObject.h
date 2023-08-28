#ifndef GameObject_H
#define GameObject_H

#include <SFML/Graphics.hpp>

class GameObject : public sf::Transformable
{
protected:

    sf::RenderWindow* renderwindow;

public:

    sf::String NAME;

    virtual void Render(sf::RenderWindow& renderwindow) = 0;
};

#endif // GameObject_H



