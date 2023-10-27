#include "PlayerTablet.h"

PlayerTablet::PlayerTablet(sf::Vector2f& position)
    : BaseTablet(position)
{

}

void PlayerTablet::Update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  
        && mTablet.getPosition().y > 0)
    {
        mTablet.move(0, -tabletSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) 
        && mTablet.getPosition().y + tabletHeight < Window::ScreenHeight)
    {
        mTablet.move(0, tabletSpeed * dt);
    }
}
