#include "Game.h"
#include "Window.h"
#include <Windows.h>

int main()
{
    Window window;

    try
    {
        Game game;
        sf::Clock clock;

        while (window.ProcessWindow())
        {
            sf::Time deltaTime = clock.restart();

            window.ClearFrame();
            game.Run(deltaTime.asSeconds(), window);
            window.DisplayFrame();
        }
    }
    catch (const std::exception& e)
    {
        const std::string whatMsg(e.what());
        const std::wstring eMsg = std::wstring(whatMsg.begin(), whatMsg.end());

        MessageBox(nullptr, eMsg.c_str(), L"exception in game loop", MB_ICONERROR);
    }
    catch (...)
    {
        MessageBox(nullptr, L"Unhandled Non-STL Exception", L"exception in game loop", MB_ICONERROR);
    }

    return 0;
}
