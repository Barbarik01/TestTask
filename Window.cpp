#include "Window.h"

Window::Window()
{
    pWnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(ScreenWidth, ScreenHeight), wndName);
}

bool Window::ProcessWindow()
{
    if (pWnd->isOpen())
    {
        sf::Event event;

        while (pWnd->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pWnd->close();
        }

        return true;
    }
    else
        return false;
}
