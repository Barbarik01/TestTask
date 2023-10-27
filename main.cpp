#include "Game.h"
#include "Window.h"

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
