#pragma once
#include <SFML/Graphics.hpp>

namespace MathUtils
{
void NormalizeVector(sf::Vector2f& vector);
void RotateVectorOnAgle(sf::Vector2f& vector, float angle, bool clockwise);
} // namespace MathUtils
