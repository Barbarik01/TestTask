#include "BaseTablet.h"

BaseTablet::BaseTablet(const sf::Vector2f& position)
{
    mTablet.setPosition(position);
    mTablet.setSize(sf::Vector2f(tabletWidth, tabletHeight));
    mTablet.setFillColor(sf::Color::White);
}

sf::FloatRect BaseTablet::getGlobalBouds() const
{
    return mTablet.getGlobalBounds();
}


bool BaseTablet::CheckCollision() const
{
    return false;
}

void BaseTablet::Render(Window& window)
{
    window.pWnd->draw(mTablet);
}
