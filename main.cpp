#include "Game.h"
#include "Window.h"

int main()
{
    Window window;
    Game game;
    sf::Clock clock;

    while (window.ProcessWindow())
    {
        sf::Time deltaTime = clock.restart();

        window.ClearFrame();
        game.Run(deltaTime.asSeconds(), window);
        window.DisplayFrame();
    }

    return 0;
}
