#include "Window.h"

Window::Window()
{
    pWnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(ScreenWidth, ScreenHeight), wndName);
}

bool Window::ProcessWindow()
{
    if (!pWnd->isOpen())
    {
        return false;
    }

    sf::Event event;

    while (pWnd->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            pWnd->close();
        }
    }

    return true;
}

void Window::ClearFrame()
{
    pWnd->clear();
}

void Window::DisplayFrame()
{
    pWnd->display();
}

sf::RenderWindow* Window::GetWindow() const
{
    return pWnd.get();
}
