#pragma once
#include "SFML/Graphics.hpp"

class Button
{
public:
	Button();
	void InitButton(int x, int y, int width, int height, std::string buttonText);
	void Render(sf::RenderWindow& window);
	bool IsButtonPressed(int mouseX, int mouseY);
	bool IsHoveringOver(int mouseX, int mouseY);

	sf::IntRect m_Rect;
	sf::RectangleShape m_GuiRect;
	sf::Text m_Text;
	sf::Font m_Font;
};