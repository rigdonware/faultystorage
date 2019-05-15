#include "pch.h"
#include "Button.h"
#include <iostream>

Button::Button()
{

}

void Button::InitButton(int x, int y, int width, int height, std::string buttonText)
{
	m_Rect.left = x;
	m_Rect.top = y;
	m_Rect.width = width;
	m_Rect.height = height;

	sf::Vector2f size(width, height);
	m_GuiRect.setPosition(x, y);
	m_GuiRect.setSize(size);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Failed to load button font" << std::endl;

	m_Text.setFont(font);
	m_Text.setStyle(sf::Text::Bold);
	m_Text.setString(buttonText);
	m_Text.setFillColor(sf::Color::White);
	m_Text.setCharacterSize(m_Rect.width / buttonText.length());
	m_Text.setPosition(m_Rect.left, m_Rect.top);
}

bool Button::IsButtonPressed(int mouseX, int mouseY)
{
	return (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_Rect.contains(mouseX, mouseY));
}

bool Button::IsHoveringOver(int mouseX, int mouseY)
{
	return (m_Rect.contains(mouseX, mouseY));
}

void Button::Render(sf::RenderWindow& window)
{
	window.draw(m_GuiRect);
	window.draw(m_Text);
}