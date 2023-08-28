#include "Gui.h"

unsigned short GuiComponent::static_id = 0;

unsigned short GuiComponent::GetID()
{
    return this->ID;
}

///
///functions for alignment
///

void setPositionByAlignment(sf::Sprite& sprite, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& newposition)
{
    switch(newposition)
    {
    case GuiComponent::componentAlignment::Center:
        sprite.setPosition(renderwindow.getSize().x/2.0f, renderwindow.getSize().y/2.0f);
        break;
    case GuiComponent::componentAlignment::Left:
        sprite.setPosition(0, renderwindow.getSize().y/2.0f);
        break;
    case GuiComponent::componentAlignment::Right:
        sprite.setPosition(renderwindow.getSize().x, renderwindow.getSize().y/2.0f);
        break;
    case GuiComponent::componentAlignment::Top:
        sprite.setPosition(renderwindow.getSize().x/2.0f, 0);
        break;
    case GuiComponent::componentAlignment::Bottom:
        sprite.setPosition(renderwindow.getSize().x/2.0f, renderwindow.getSize().y);
        break;
    case GuiComponent::componentAlignment::TopLeft:
        sprite.setPosition(0, 0);
        break;
    case GuiComponent::componentAlignment::TopRight:
        sprite.setPosition(renderwindow.getSize().x, 0);
        break;
    case GuiComponent::componentAlignment::BottomLeft:
        sprite.setPosition(0, renderwindow.getSize().y);
        break;
    case GuiComponent::componentAlignment::BottomRight:
        sprite.setPosition(renderwindow.getSize().x, renderwindow.getSize().y);
        break;
    default:
        break;
    }
}

void setOriginByAlignment(sf::Sprite& sprite, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& neworigin)
{
    sf::FloatRect Rect = sprite.getLocalBounds();
    switch(neworigin)
    {
    case Label::componentAlignment::Center:
        sprite.setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height/2.0f);
        break;
    case Label::componentAlignment::Left:
        sprite.setOrigin(Rect.left, Rect.top + Rect.height/2.0f);
        break;
    case Label::componentAlignment::Right:
        sprite.setOrigin(Rect.left + Rect.width, Rect.top + Rect.height/2.0f);
        break;
    case Label::componentAlignment::Top:
        sprite.setOrigin(Rect.left + Rect.width/2.0f, Rect.top);
        break;
    case Label::componentAlignment::Bottom:
        sprite.setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height);
        break;
    case Label::componentAlignment::TopLeft:
        sprite.setOrigin(Rect.left, Rect.top);
        break;
    case Label::componentAlignment::TopRight:
        sprite.setOrigin(Rect.left + Rect.width, Rect.top);
        break;
    case Label::componentAlignment::BottomLeft:
        sprite.setOrigin(Rect.left, Rect.top + Rect.height);
        break;
    case Label::componentAlignment::BottomRight:
        sprite.setOrigin(Rect.left + Rect.width, Rect.top + Rect.height);
        break;
    default:
        break;
    }
}
void setPositionByAlignment(sf::RectangleShape& shape, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& newposition)
{
    switch(newposition)
    {
    case GuiComponent::componentAlignment::Center:
        shape.setPosition(static_cast<float>(renderwindow.getSize().x/2.0f), static_cast<float>(renderwindow.getSize().y/2.0f));
        break;
    case GuiComponent::componentAlignment::Left:
        shape.setPosition(0, static_cast<float>(renderwindow.getSize().y/2.0f));
        break;
    case GuiComponent::componentAlignment::Right:
        shape.setPosition(renderwindow.getSize().x, static_cast<float>(renderwindow.getSize().y/2.0f));
        break;
    case GuiComponent::componentAlignment::Top:
        shape.setPosition(static_cast<float>(renderwindow.getSize().x/2.0f), 0);
        break;
    case GuiComponent::componentAlignment::Bottom:
        shape.setPosition(static_cast<float>(renderwindow.getSize().x/2.0f), renderwindow.getSize().y);
        break;
    case GuiComponent::componentAlignment::TopLeft:
        shape.setPosition(0, 0);
        break;
    case GuiComponent::componentAlignment::TopRight:
        shape.setPosition(renderwindow.getSize().x, 0);
        break;
    case GuiComponent::componentAlignment::BottomLeft:
        shape.setPosition(0, renderwindow.getSize().y);
        break;
    case GuiComponent::componentAlignment::BottomRight:
        shape.setPosition(renderwindow.getSize().x, renderwindow.getSize().y);
        break;
    default:
        break;
    }
}

void setOriginByAlignment(sf::RectangleShape& shape, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& neworigin)
{
    sf::FloatRect Rect = shape.getLocalBounds();
    switch(neworigin)
    {
    case GuiComponent::componentAlignment::Center:
        shape.setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height/2.0f);
        break;
    case GuiComponent::componentAlignment::Left:
        shape.setOrigin(Rect.left, Rect.top + Rect.height/2.0f);
        break;
    case GuiComponent::componentAlignment::Right:
        shape.setOrigin(Rect.left + Rect.width, Rect.top + Rect.height/2.0f);
        break;
    case GuiComponent::componentAlignment::Top:
        shape.setOrigin(Rect.left + Rect.width/2.0f, Rect.top);
        break;
    case GuiComponent::componentAlignment::Bottom:
        shape.setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height);
        break;
    case GuiComponent::componentAlignment::TopLeft:
        shape.setOrigin(Rect.left, Rect.top);
        break;
    case GuiComponent::componentAlignment::TopRight:
        shape.setOrigin(Rect.left + Rect.width, Rect.top);
        break;
    case GuiComponent::componentAlignment::BottomLeft:
        shape.setOrigin(Rect.left, Rect.top + Rect.height);
        break;
    case GuiComponent::componentAlignment::BottomRight:
        shape.setOrigin(Rect.left + Rect.width, Rect.top + Rect.height);
        break;
    default:
        break;
    }
}

void setPositionByAlignment(sf::RectangleShape& shape, sf::View& view, const GuiComponent::componentAlignment& newposition)
{
    switch(newposition)
    {
    case GuiComponent::componentAlignment::Center:
        shape.setPosition(static_cast<float>(view.getSize().x/2.0f), static_cast<float>(view.getSize().y/2.0f));
        break;
    case GuiComponent::componentAlignment::Left:
        shape.setPosition(0, static_cast<float>(view.getSize().y/2.0f));
        break;
    case GuiComponent::componentAlignment::Right:
        shape.setPosition(view.getSize().x, static_cast<float>(view.getSize().y/2.0f));
        break;
    case GuiComponent::componentAlignment::Top:
        shape.setPosition(static_cast<float>(view.getSize().x/2.0f), 0);
        break;
    case GuiComponent::componentAlignment::Bottom:
        shape.setPosition(static_cast<float>(view.getSize().x/2.0f), view.getSize().y);
        break;
    case GuiComponent::componentAlignment::TopLeft:
        shape.setPosition(0, 0);
        break;
    case GuiComponent::componentAlignment::TopRight:
        shape.setPosition(view.getSize().x, 0);
        break;
    case GuiComponent::componentAlignment::BottomLeft:
        shape.setPosition(0, view.getSize().y);
        break;
    case GuiComponent::componentAlignment::BottomRight:
        shape.setPosition(view.getSize().x, view.getSize().y);
        break;
    default:
        break;
    }
}

void setOriginByAlignment(sf::RectangleShape& shape, sf::View& view, const GuiComponent::componentAlignment& neworigin)
{

}

void setPositionByAlignment(sf::Text& text, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& newposition)
{
    switch(newposition)
    {
    case GuiComponent::componentAlignment::Center:
        text.setPosition(renderwindow.getSize().x/2.0f, renderwindow.getSize().y/2.0f);
        break;
    case GuiComponent::componentAlignment::Left:
        text.setPosition(0, renderwindow.getSize().y/2.0f);
        break;
    case GuiComponent::componentAlignment::Right:
        text.setPosition(renderwindow.getSize().x, renderwindow.getSize().y/2.0f);
        break;
    case GuiComponent::componentAlignment::Top:
        text.setPosition(renderwindow.getSize().x/2.0f, 0);
        break;
    case GuiComponent::componentAlignment::Bottom:
        text.setPosition(renderwindow.getSize().x/2.0f, renderwindow.getSize().y);
        break;
    case GuiComponent::componentAlignment::TopLeft:
        text.setPosition(0, 0);
        break;
    case GuiComponent::componentAlignment::TopRight:
        text.setPosition(renderwindow.getSize().x, 0);
        break;
    case GuiComponent::componentAlignment::BottomLeft:
        text.setPosition(0, renderwindow.getSize().y);
        break;
    case GuiComponent::componentAlignment::BottomRight:
        text.setPosition(renderwindow.getSize().x, renderwindow.getSize().y);
        break;
    default:
        break;
    }
}

void setOriginByAlignment(sf::Text& text, sf::RenderTarget& renderwindow, const GuiComponent::componentAlignment& neworigin)
{
    sf::FloatRect Rect = text.getLocalBounds();
    switch(neworigin)
    {
    case GuiComponent::componentAlignment::Center:
        text.setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height/2.0f);
        break;
    case GuiComponent::componentAlignment::Left:
        text.setOrigin(Rect.left, Rect.top + Rect.height/2.0f);
        break;
    case GuiComponent::componentAlignment::Right:
        text.setOrigin(Rect.left + Rect.width, Rect.top + Rect.height/2.0f);
        break;
    case GuiComponent::componentAlignment::Top:
        text.setOrigin(Rect.left + Rect.width/2.0f, Rect.top);
        break;
    case GuiComponent::componentAlignment::Bottom:
        text.setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height);
        break;
    case GuiComponent::componentAlignment::TopLeft:
        text.setOrigin(Rect.left, Rect.top);
        break;
    case GuiComponent::componentAlignment::TopRight:
        text.setOrigin(Rect.left + Rect.width, Rect.top);
        break;
    case GuiComponent::componentAlignment::BottomLeft:
        text.setOrigin(Rect.left, Rect.top + Rect.height);
        break;
    case GuiComponent::componentAlignment::BottomRight:
        text.setOrigin(Rect.left + Rect.width, Rect.top + Rect.height);
        break;
    default:
        break;
    }
}

///
///
///class Label
///
///

Label::Label(const Label& other)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->fillcolor = other.GetFillColor();
    this->outlinecolor = other.GetOutLineColor();
    this->outlinethickness = other.GetOutLineThickness();
    this->pressedcolor = other.GetPressedColor();
    this->renderWindow = other.GetRenderWindow();

    this->text.setString(other.GetString());
    this->text.setCharacterSize(other.GetCharacterSize());
    this->text.setFillColor(fillcolor);
    this->text.setFont((*other.GetFont()));
    this->text.setOrigin(other.GetOrigin());
    this->text.setOutlineColor(outlinecolor);
    this->text.setOutlineThickness(outlinethickness);
    this->text.setPosition(other.GetPosition());
    this->text.setRotation(other.GetRotation());
}

Label::Label(sf::RenderTarget* _renderwindow)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->pressedcolor = sf::Color::Black;
    this->fillcolor = sf::Color::Black;
    this->outlinecolor = sf::Color::Black;
    this->outlinethickness = 0;
    this->text.setFillColor(fillcolor);
    this->text.setOutlineColor(outlinecolor);
    this->text.setOutlineThickness(outlinethickness);
    this->text.setString(sf::String("Label"));
    this->text.setPosition(0, 0);
}

Label::Label(sf::RenderTarget* _renderwindow, const sf::Font& _font)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->pressedcolor = sf::Color::Black;
    this->fillcolor = sf::Color::Black;
    this->outlinecolor = sf::Color::Black;
    this->outlinethickness = 0;
    this->text.setFillColor(fillcolor);
    this->text.setOutlineColor(outlinecolor);
    this->text.setOutlineThickness(outlinethickness);
    this->text.setString(sf::String("Label"));
    this->text.setFont(_font);
    this->text.setPosition(0, 0);
}

Label::Label(sf::RenderTarget* _renderwindow, sf::Text _text, sf::Vector2f _position, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness, sf::Color _pressedcolor)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->text = _text;
    this->fillcolor = _fillcolor;
    this->outlinecolor = _outlinecolor;
    this->outlinethickness = _outlinethickness;
    this->pressedcolor = _pressedcolor;

    text.setPosition(_position);
    text.setOutlineColor(outlinecolor);
    text.setOutlineThickness(outlinethickness);
    text.setFillColor(fillcolor);
    text.setStyle(sf::Text::Regular);
    text.setColor(fillcolor);
}

Label::Label(sf::RenderTarget* _renderwindow, sf::Text _text, sf::Vector2f _position, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness)
{
    GuiComponent::static_id++;
    this->ID = GuiComponent::static_id;

    this->renderWindow = _renderwindow;

    this->text = _text;
    this->fillcolor = _fillcolor;
    this->outlinecolor = _outlinecolor;
    this->outlinethickness = _outlinethickness;
    this->pressedcolor = sf::Color::Black;

    text.setPosition(_position);
    text.setOutlineColor(outlinecolor);
    text.setOutlineThickness(outlinethickness);
    text.setFillColor(fillcolor);
    text.setStyle(sf::Text::Regular);
    text.setColor(fillcolor);
}

Label::Label(sf::RenderTarget* _renderwindow, sf::Text _text, Label::componentAlignment _position, Label::componentAlignment _origin, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness, sf::Color _pressedcolor)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->text = _text;
    this->fillcolor = _fillcolor;
    this->outlinecolor = _outlinecolor;
    this->outlinethickness = _outlinethickness;
    this->pressedcolor = _pressedcolor;

    this->SetPosition(_position);
    this->SetOrigin(_origin);
    text.setOutlineColor(outlinecolor);
    text.setOutlineThickness(outlinethickness);
    text.setFillColor(fillcolor);
    text.setStyle(sf::Text::Regular);
    text.setColor(fillcolor);
}

Label::Label(sf::RenderTarget* _renderwindow, sf::Text _text, Label::componentAlignment _position, Label::componentAlignment _origin, sf::Color _fillcolor, sf::Color _outlinecolor, float _outlinethickness)
{
    GuiComponent::static_id++;
    this->ID = GuiComponent::static_id;

    this->renderWindow = _renderwindow;

    this->text = _text;
    this->fillcolor = _fillcolor;
    this->outlinecolor = _outlinecolor;
    this->outlinethickness = _outlinethickness;

    this->SetPosition(_position);
    this->SetOrigin(_origin);
    text.setOutlineColor(outlinecolor);
    text.setOutlineThickness(outlinethickness);
    text.setFillColor(fillcolor);
    text.setStyle(sf::Text::Regular);
    text.setColor(fillcolor);
}

/*void Label::Update(sf::RenderTarget& renderWindow)
{
    ///Empty
}*/

void Label::Render(sf::RenderTarget& renderWindow)
{
    renderWindow.draw(this->text);
}

bool Label::CheckIfPressed(sf::Vector2i& mpos, sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed)
        if(event.mouseButton.button == sf::Mouse::Left)
            if(this->text.getGlobalBounds().contains(mpos.x, mpos.y))
            {
                return true;
            }
    return false;
}

const sf::Font* Label::GetFont() const
{
    return this->text.getFont();
}
unsigned int Label::GetCharacterSize() const
{
    return this->text.getCharacterSize();
}
sf::Color Label::GetPressedColor() const
{
    return this->pressedcolor;
}
sf::Color Label::GetFillColor() const
{
    return this->fillcolor;
}
sf::Color Label::GetOutLineColor() const
{
    return this->outlinecolor;
}
float Label::GetOutLineThickness() const
{
    return this->outlinethickness;
}
sf::FloatRect Label::GetGlobalBounds() const
{
    return this->text.getGlobalBounds();
}
sf::FloatRect Label::GetLocalBounds() const
{
    return this->text.getLocalBounds();
}
const sf::String& Label::GetString() const
{
    return this->text.getString();
}
const sf::Vector2f& Label::GetPosition() const
{
    return this->text.getPosition();
}
const sf::Vector2f& Label::GetOrigin() const
{
    return this->text.getOrigin();
}
float Label::GetRotation() const
{
    return this->text.getRotation();
}
sf::RenderTarget* Label::GetRenderWindow() const
{
    return this->renderWindow;
}
/// /// ///
//const sf::Text& Label::GetText() const
//{
//    return this->text;
//}
/// /// ///
void Label::SetStyle(sf::Uint32 style)
{
    this->text.setStyle(style);
}

void Label::SetFont(const sf::Font& newfont)
{
    this->text.setFont(newfont);
}

void Label::SetFillColor(const sf::Color& newcolor)
{
    this->fillcolor = newcolor;
    this->text.setFillColor(newcolor);
}

void Label::SetOutLineColor(const sf::Color& newcolor)
{
    this->outlinecolor = newcolor;
    this->text.setOutlineColor(newcolor);
}

void Label::SetOutLineThickness(const float& newthickness)
{
    this->outlinethickness = newthickness;
    this->text.setOutlineThickness(newthickness);
}

void Label::SetString(const sf::String& newstring)
{
    this->text.setString(newstring);
}

void Label::SetCharacterSize(const unsigned int& newcharsize)
{
    this->text.setCharacterSize(newcharsize);
}

void Label::SetPosition(const sf::Vector2f& newposition)
{
    this->text.setPosition(newposition);
}

void Label::SetPosition(const float& x, const float& y)
{
    this->text.setPosition(x, y);
}

void Label::SetPosition(const Label::componentAlignment& newposition)
{
    switch(newposition)
    {
    case Label::componentAlignment::Center:
        this->text.setPosition(this->renderWindow->getSize().x/2.0f, this->renderWindow->getSize().y/2.0f);
        break;
    case Label::componentAlignment::Left:
        this->text.setPosition(0, this->renderWindow->getSize().y/2.0f);
        break;
    case Label::componentAlignment::Right:
        this->text.setPosition(this->renderWindow->getSize().x, this->renderWindow->getSize().y/2.0f);
        break;
    case Label::componentAlignment::Top:
        this->text.setPosition(this->renderWindow->getSize().x/2.0f, 0);
        break;
    case Label::componentAlignment::Bottom:
        this->text.setPosition(this->renderWindow->getSize().x/2.0f, this->renderWindow->getSize().y);
        break;
    case Label::componentAlignment::TopLeft:
        this->text.setPosition(0, 0);
        break;
    case Label::componentAlignment::TopRight:
        this->text.setPosition(this->renderWindow->getSize().x, 0);
        break;
    case Label::componentAlignment::BottomLeft:
        this->text.setPosition(0, this->renderWindow->getSize().y);
        break;
    case Label::componentAlignment::BottomRight:
        this->text.setPosition(this->renderWindow->getSize().x, this->renderWindow->getSize().y);
        break;
    default:
        break;
    }
}

void Label::SetRotation(const float& newangle)
{
    this->text.setRotation(newangle);
}

void Label::SetScale(const sf::Vector2f& newscale)
{
    this->text.setScale(newscale);
}

void Label::SetPressedColor(const sf::Color& newpressedcolor)
{
    this->pressedcolor = newpressedcolor;
}

void Label::SetOrigin(const sf::Vector2f& neworigin)
{
    this->text.setOrigin(neworigin);
}

void Label::SetOrigin(const Label::componentAlignment& neworigin)
{
    sf::FloatRect textRect = this->text.getLocalBounds();
    switch(neworigin)
    {
    case Label::componentAlignment::Center:
        this->text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
        break;
    case Label::componentAlignment::Left:
        this->text.setOrigin(textRect.left, textRect.top + textRect.height/2.0f);
        break;
    case Label::componentAlignment::Right:
        this->text.setOrigin(textRect.left + textRect.width, textRect.top + textRect.height/2.0f);
        break;
    case Label::componentAlignment::Top:
        this->text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top);
        break;
    case Label::componentAlignment::Bottom:
        this->text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height);
        break;
    case Label::componentAlignment::TopLeft:
        this->text.setOrigin(textRect.left, textRect.top);
        break;
    case Label::componentAlignment::TopRight:
        this->text.setOrigin(textRect.left + textRect.width, textRect.top);
        break;
    case Label::componentAlignment::BottomLeft:
        this->text.setOrigin(textRect.left, textRect.top + textRect.height);
        break;
    case Label::componentAlignment::BottomRight:
        this->text.setOrigin(textRect.left + textRect.width, textRect.top + textRect.height);
        break;
    default:
        break;
    }
}

void Label::Move(const sf::Vector2f& offset)
{
    this->text.move(offset);
}

void Label::Move(const float& x, const float& y)
{
    this->text.move(x, y);
}

///
///
///class Button
///
///

void Button::centralizeLabel()
{
    /*float prevoriginX = btn_shape.getOrigin().x;
    float prevoriginY = btn_shape.getOrigin().y;

    label->SetOrigin(GuiComponent::componentAlignment::Center);
    setOriginByAlignment(btn_shape, *renderWindow, GuiComponent::componentAlignment::Center);
    label->SetPosition(btn_shape.getPosition());

    btn_shape.setOrigin(prevoriginX, prevoriginY);*/

    label->SetOrigin(GuiComponent::componentAlignment::Center);

    sf::FloatRect Rect = this->btn_shape.getGlobalBounds();
    this->label->SetPosition(Rect.left + Rect.width/2.0f, Rect.top + Rect.height/2.0f);

}

Button::Button(sf::RenderTarget* _renderwindow)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->label = new Label(this->renderWindow);

    this->btn_shape.setSize(sf::Vector2f(100, 50));
    this->btn_shape.setFillColor(sf::Color::White);
    this->btn_shape.setOutlineColor(sf::Color::Black);
    this->btn_shape.setOutlineThickness(1.0f);
    this->pressedcolor = sf::Color::White;
    this->btn_shape.setPosition(0,0);

    centralizeLabel();
}

Button::Button(sf::RenderTarget* _renderwindow, const sf::Font& _font)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->label = new Label(this->renderWindow, _font);

    this->btn_shape.setSize(sf::Vector2f(100, 50));
    this->btn_shape.setFillColor(sf::Color::White);
    this->btn_shape.setOutlineColor(sf::Color::Black);
    this->btn_shape.setOutlineThickness(1.0f);
    this->pressedcolor = sf::Color::White;
    this->btn_shape.setPosition(0,0);

    centralizeLabel();
}

Button::Button(sf::RenderTarget* _renderwindow, const Label& label)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->label = new Label(label);

    this->btn_shape.setSize(sf::Vector2f(100, 50));
    this->btn_shape.setFillColor(sf::Color::White);
    this->btn_shape.setOutlineColor(sf::Color::Black);
    this->btn_shape.setOutlineThickness(1.0f);
    this->pressedcolor = sf::Color::White;
    this->btn_shape.setPosition(0,0);

    centralizeLabel();
}

Button::Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
       GuiComponent::componentAlignment _position, GuiComponent::componentAlignment _origin,
       const sf::Vector2f& newsize, const sf::Color& _fillcolor,
       const sf::Color& _outlinecolor, unsigned int _outlinethickness,
       sf::Color _pressedcolor)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->label = new Label(this->renderWindow, _text, sf::Vector2f(0,0), sf::Color::Black);

    this->btn_shape.setSize(newsize);
    this->btn_shape.setFillColor(_fillcolor);
    this->btn_shape.setOutlineColor(_outlinecolor);
    this->btn_shape.setOutlineThickness(_outlinethickness);
    this->pressedcolor = _pressedcolor;
    setOriginByAlignment(btn_shape, *renderWindow, _origin);
    setPositionByAlignment(btn_shape, *renderWindow, _position);

    centralizeLabel();
}

Button::Button(sf::RenderTarget* _renderwindow, const sf::Text& _text,
               const sf::Vector2f& _position, const sf::Vector2f& newsize,
               const sf::Color& _fillcolor, const sf::Color& _outlinecolor,
               unsigned int _outlinethickness, sf::Color _pressedcolor)
{
    GuiComponent::static_id++; ///update static ID counter
    this->ID = GuiComponent::static_id; ///equalization of the local ID with static ID counter

    this->renderWindow = _renderwindow;

    this->label = new Label(this->renderWindow, _text, sf::Vector2f(0,0), sf::Color::Black);

    this->btn_shape.setSize(newsize);
    this->btn_shape.setFillColor(_fillcolor);
    this->btn_shape.setOutlineColor(_outlinecolor);
    this->btn_shape.setOutlineThickness(_outlinethickness);
    this->pressedcolor = _pressedcolor;
    this->btn_shape.setPosition(_position);

    centralizeLabel();
}

Button::~Button()
{
    delete this->label;
}

/*void Button::Update(sf::RenderTarget& renderWindow)
{
    ///Empty
}*/

void Button::Render(sf::RenderTarget& renderWindow)
{
    renderWindow.draw(this->btn_shape);
    label->Render(renderWindow);
}

Label& Button::GetLabel()
{
    return *label;
}
sf::RectangleShape& Button::GetButtonRect()
{
    return btn_shape;
}

void Button::SetFillColor(const sf::Color& newcolor)
{
    btn_shape.setFillColor(newcolor);
}
void Button::SetOutLineColor(const sf::Color& newcolor)
{
    btn_shape.setOutlineColor(newcolor);
}
void Button::SetOutLineThickness(const float& newthickness)
{
    btn_shape.setOutlineThickness(newthickness);
}
void Button::SetSize(const sf::Vector2f& newsize)
{
    btn_shape.setSize(newsize);
}
void Button::SetScale(const sf::Vector2f& newscale)
{
    btn_shape.setScale(newscale);
}
void Button::SetPosition(const sf::Vector2f& newposition)
{
    btn_shape.setPosition(newposition);
    centralizeLabel();
}
void Button::SetPosition(const float& x, const float& y)
{
    btn_shape.setPosition(x, y);
    centralizeLabel();
}
void Button::SetPosition(const Button::componentAlignment& newposition)
{
    setPositionByAlignment(btn_shape, *renderWindow, newposition);
    centralizeLabel();
}
void Button::SetPositionByView(const GuiComponent::componentAlignment& newposition, sf::View& view)
{
    setPositionByAlignment(btn_shape, view, newposition);
    centralizeLabel();
}
void Button::SetRotation(float angle)
{
    btn_shape.setRotation(angle);
    centralizeLabel();
    label->SetRotation(angle);
}
void Button::SetOrigin(const sf::Vector2f& neworigin)
{
    btn_shape.setOrigin(neworigin);
}
void Button::SetOrigin(const Button::componentAlignment& neworigin)
{
    setOriginByAlignment(btn_shape, *renderWindow, neworigin);
}
void Button::Move(const sf::Vector2f& offset)
{
    btn_shape.move(offset);
    centralizeLabel();
}
void Button::Move(const float& x, const float& y)
{
    btn_shape.move(x,y);
    centralizeLabel();
}

