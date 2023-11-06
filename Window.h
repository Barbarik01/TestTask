#pragma once
#include <SFML/Graphics.hpp>

class Window
{
  public:
    Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    bool ProcessWindow();
    void ClearFrame();
    void DisplayFrame();
    sf::RenderWindow* GetWindow() const;

  private:
    std::unique_ptr<sf::RenderWindow> pWnd = nullptr;

  public:
    static constexpr int ScreenWidth = 1280;
    static constexpr int ScreenHeight = 720;
    static constexpr const char* wndName = "Pong Game";
};
