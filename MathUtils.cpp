#include "MathUtils.h"
#include <cmath>

namespace MathUtils
{
void NormalizeVector(sf::Vector2f& vector)
{
    float length = sqrt(vector.x * vector.x + vector.y * vector.y);

    vector.x /= length;
    vector.y /= length;
}

void RotateVectorOnAgle(sf::Vector2f& vector, float angle, bool clockwise)
{
    if (clockwise)
    {
        vector.x = vector.x * std::cos(angle) - vector.y * std::sin(angle);
        vector.y = vector.x * std::sin(angle) + vector.y * std::cos(angle);
    }
    else
    {
        vector.x = vector.x * std::cos(angle) + vector.y * std::sin(angle);
        vector.y = -vector.x * std::sin(angle) + vector.y * std::cos(angle);
    }
}
} // namespace MathUtils
