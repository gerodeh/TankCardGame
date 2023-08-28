#ifndef Gui_H
#define Gui_H

#include <SFML/Graphics.hpp>

///class GuiComponent

class GuiComponent
{
protected:
    sf::RenderTarget* renderWindow; ///needed to always keep in the render window for using in alignment;

    static unsigned short static_id; ///needed to provided correct change of ID within child classes

    unsigned short ID = -1;

public:
    //virtual void Update(sf::RenderTarget& renderWindow) = 0; ///Honestly I don`t know what this is for. It just exists and that is all
    virtual void Render(sf::RenderTarget& renderWindow) = 0; ///function to draw the components

    unsigned short GetID();

    enum class componentAlignment ///for positioning and for origin of a component
    {
        Center,
        Right,
        Left,
        Top,
        TopRight,
        TopLeft,
        Bottom,
        BottomRight,
        BottomLeft

    };

};

///functions for alignment

void setPositionByAlignment(sf::Sprite& sprite, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& newposition);

void setOriginByAlignment(sf::Sprite& sprite, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& neworigin);

void setPositionByAlignment(sf::RectangleShape& shape, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& newposition);

void setOriginByAlignment(sf::RectangleShape& shape, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& neworigin);

void setPositionByAlignment(sf::RectangleShape& shape, sf::View& view, const GuiComponent::componentAlignment& newposition);

void setOriginByAlignment(sf::RectangleShape& shape, sf::View& view, const GuiComponent::componentAlignment& neworigin);

void setPositionByAlignment(sf::Text& text, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& newposition);

void setOriginByAlignment(sf::Text& text, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& neworigin);

///
///class Label
///

class Label : public GuiComponent
{
private:
    sf::Color fillcolor; ///fill colour of text
    sf::Color outlinecolor; ///outline colour of text
    sf::Color pressedcolor; ///colour for when the component is pressed
    float outlinethickness; ///outline thickness

    sf::Text text;
public:
    sf::String NAME;

    Label() = delete;

    Label(const Label& other);

    Label(sf::RenderTarget* _renderwindow);

    Label(sf::RenderTarget* _renderwindow, const sf::Font& _font);

    Label(sf::RenderTarget* _renderwindow, sf::Text _text, sf::Vector2f _position, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness, sf::Color _pressedcolor);

    Label(sf::RenderTarget* _renderwindow, sf::Text _text, sf::Vector2f _position, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness = 1);

    Label(sf::RenderTarget* _renderwindow, sf::Text _text, sf::Vector2f _position, sf::Color _fillcolor) :
        Label(_renderwindow, _text, _position, _fillcolor, sf::Color::Black, 0) {}

    Label(sf::RenderTarget* _renderwindow, sf::Text _text, Label::componentAlignment _position, Label::componentAlignment _origin, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness, sf::Color _pressedcolor);

    Label(sf::RenderTarget* _renderwindow, sf::Text _text, Label::componentAlignment _position, Label::componentAlignment _origin, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness = 1);

    Label(sf::RenderTarget* _renderwindow, sf::Text _text, Label::componentAlignment _position, Label::componentAlignment _origin, sf::Color _fillcolor) :
        Label(_renderwindow, _text, _position, _origin, _fillcolor, sf::Color::Black, 0) {};

    //void Update(sf::RenderTarget& renderWindow) override;
    void Render(sf::RenderTarget& renderWindow) override;
    bool CheckIfPressed(sf::Vector2i& mpos, sf::Event& event);

    const sf::Font* GetFont() const;
    unsigned int GetCharacterSize() const;
    sf::Color GetPressedColor() const;
    sf::Color GetFillColor() const;
    sf::Color GetOutLineColor() const;
    float GetOutLineThickness() const;
    sf::FloatRect GetGlobalBounds() const;
    sf::FloatRect GetLocalBounds() const;
    const sf::String& GetString() const;
    const sf::Vector2f& GetPosition() const;
    const sf::Vector2f& GetOrigin() const;
    float GetRotation() const;
    sf::RenderTarget* GetRenderWindow() const;

    /// ///
    ///const sf::Text& GetText() const;
    /// ///

    void SetStyle(sf::Uint32 style);
    void SetFont(const sf::Font& newfont);
    void SetFillColor(const sf::Color& newcolor);
    void SetOutLineColor(const sf::Color& newcolor);
    void SetOutLineThickness(const float& newthickness);
    void SetString(const sf::String& newstring);
    void SetCharacterSize(const unsigned int& newcharsize);
    void SetPosition(const sf::Vector2f& newposition);
    void SetPosition(const float& x, const float& y);
    void SetPosition(const Label::componentAlignment& newposition);
    void SetRotation(const float& newangle);
    void SetScale(const sf::Vector2f& newscale);
    void SetPressedColor(const sf::Color& newpressedcolor);
    void SetOrigin(const sf::Vector2f& neworigin);
    void SetOrigin(const Label::componentAlignment& neworigin);
    void Move(const sf::Vector2f& offset);
    void Move(const float& x, const float& y);
};

///
///class Button
///

class Button : public GuiComponent
{
    sf::Color pressedcolor; ///colour for when the component is pressed

    sf::RectangleShape btn_shape; ///??? is it supposed to be public ???

    Label* label; ///??? is it supposed to be public ???

public:

    void centralizeLabel(); ///function for alignment the label by center of button rectangle shape

    bool isActive = false;

public:
    sf::String NAME;
    int numero = -1;

    Button() = delete;

    Button(sf::RenderTarget* _renderwindow);

    Button(sf::RenderTarget* _renderwindow, const sf::Font& _font);

    Button(sf::RenderTarget* _renderwindow, const Label& label);

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text) :
           Button( _renderwindow, _text, GuiComponent::componentAlignment::TopLeft, GuiComponent::componentAlignment::TopLeft, sf::Vector2f(100, 50), sf::Color::White, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
           GuiComponent::componentAlignment _position) :
           Button( _renderwindow, _text, _position, GuiComponent::componentAlignment::TopLeft, sf::Vector2f(100, 50), sf::Color::White, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
           GuiComponent::componentAlignment _position,
           GuiComponent::componentAlignment _origin) :
           Button( _renderwindow, _text, _position, _origin, sf::Vector2f(100, 50), sf::Color::White, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
           GuiComponent::componentAlignment _position,
           GuiComponent::componentAlignment _origin,
           const sf::Vector2f& newsize) :
           Button( _renderwindow, _text, _position, _origin, newsize, sf::Color::White, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
           GuiComponent::componentAlignment _position, GuiComponent::componentAlignment _origin,
           const sf::Vector2f& newsize, const sf::Color& _fillcolor) :
           Button( _renderwindow, _text, _position, _origin, newsize, _fillcolor, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
           GuiComponent::componentAlignment _position, GuiComponent::componentAlignment _origin,
           const sf::Vector2f& newsize, const sf::Color& _fillcolor,
           const sf::Color& _outlinecolor) :
           Button( _renderwindow, _text, _position, _origin, newsize, _fillcolor, _outlinecolor, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
           GuiComponent::componentAlignment _position, GuiComponent::componentAlignment _origin,
           const sf::Vector2f& newsize, const sf::Color& _fillcolor,
           const sf::Color& _outlinecolor, unsigned int _outlinethickness,
           sf::Color _pressedcolor = sf::Color::White);

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text, const sf::Vector2f& _position) :
        Button(_renderwindow, _text, _position, sf::Vector2f(100, 50), sf::Color::White, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text, const sf::Vector2f& _position, const sf::Vector2f& newsize) :
        Button(_renderwindow, _text, _position, newsize, sf::Color::White, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text, const sf::Vector2f& _position, const sf::Vector2f& newsize, const sf::Color& _fillcolor) :
        Button(_renderwindow, _text, _position, newsize, _fillcolor, sf::Color::Black, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text, const sf::Vector2f& _position, const sf::Vector2f& newsize, const sf::Color& _fillcolor, const sf::Color& _outlinecolor) :
        Button(_renderwindow, _text, _position, newsize, _fillcolor, _outlinecolor, 1) {}

    Button(sf::RenderTarget* _renderwindow, const sf::Text& _text, const sf::Vector2f& _position, const sf::Vector2f& newsize, const sf::Color& _fillcolor,
            const sf::Color& _outlinecolor, unsigned int _outlinethickness, sf::Color _pressedcolor = sf::Color::White);

    ~Button();

    //void Update(sf::RenderTarget& renderWindow) override;
    void Render(sf::RenderTarget& renderWindow) override;

    Label& GetLabel();
    sf::RectangleShape& GetButtonRect();

    void SetFillColor(const sf::Color& newcolor);
    void SetOutLineColor(const sf::Color& newcolor);
    void SetOutLineThickness(const float& newthickness);
    void SetSize(const sf::Vector2f& newsize);
    void SetScale(const sf::Vector2f& newscale);
    void SetPosition(const sf::Vector2f& newposition);
    void SetPosition(const float& x, const float& y);
    void SetPosition(const GuiComponent::componentAlignment& newposition);
    void SetPositionByView(const GuiComponent::componentAlignment& newposition, sf::View& view);
    void SetRotation(float angle);
    void SetOrigin(const sf::Vector2f& neworigin);
    void SetOrigin(const GuiComponent::componentAlignment& neworigin);
    void Move(const sf::Vector2f& offset);
    void Move(const float& x, const float& y);
};

#endif // Gui_H
