#include "Window.h"
#include "Game.h"

int main()
{
    Window window;
    Game game(window);

    while (window.ProcessWindow())
    {
        game.Run();
    }

    return 0;
}
