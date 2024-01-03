
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

void updateShapeAndText(sf::Shape& shape, sf::Text& text, float moveSpeedX, float moveSpeedY);

int main()
{
    const int wWidth = 800;
    const int wHeight = 600;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML Works!");
    window.setFramerateLimit(60);

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100.0f, 100.0f);
    float circleMoveSpeedX = -0.09f;
    float circleMoveSpeedY = 0.06f;

    sf::CircleShape circle2(100);
    circle2.setFillColor(sf::Color::Blue);
    circle2.setPosition(200.0f, 200.0f);
    float circle2MoveSpeedX = 0.06f;
    float circle2MoveSpeedY = 0.12f;

    sf::CircleShape circle3(75);
    circle3.setFillColor(sf::Color(255, 0, 255));
    circle3.setPosition(300.0f, 300.0f);
    float circle3MoveSpeedX = -0.06f;
    float circle3MoveSpeedY = -0.03f;

    sf::RectangleShape rect (sf::Vector2f(50, 25));
    rect.setPosition(200, 200);
    rect.setFillColor(sf::Color::Red);
    float rectMoveSpeedX = 0.3;
    float rectMoveSpeedY = 0.45;

    sf::RectangleShape rect2(sf::Vector2f(50, 100));
    rect2.setPosition(300, 250);
    rect2.setFillColor(sf::Color(100, 100, 100));
    float rect2MoveSpeedX = -0.06;
    float rect2MoveSpeedY = 0.06;

    sf::RectangleShape rect3(sf::Vector2f(100, 100));
    rect3.setPosition(25, 100);
    rect3.setFillColor(sf::Color(0, 255, 255));
    float rect3MoveSpeedX = -0.06;
    float rect3MoveSpeedY = -0.06;


    sf::Font myFont;

    if (!myFont.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
    {
        std::cerr << "Couldn't load font!";
        exit(-1);
    }

    sf::Text text("CGreen", myFont, 18);
    sf::Text text2("CBlue", myFont, 18);
    sf::Text text3("CPurple", myFont, 18);
    sf::Text text4("RRed", myFont, 18);
    sf::Text text5("RGrey", myFont, 18);
    sf::Text text6("RTeal", myFont, 18);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        /*circle.setPosition(circle.getPosition().x + circleMoveSpeedX, circle.getPosition().y + circleMoveSpeedY);
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text.setPosition(circle.getPosition().x + circle.getRadius(), circle.getPosition().y + circle.getRadius());*/ 

        if (circle.getPosition().y <= 0 || circle.getPosition().y + 2 * circle.getRadius() >= wHeight) {
            circleMoveSpeedY *= -1.0f;
        }

        if (circle.getPosition().x <= 0 || circle.getPosition().x + 2 * circle.getRadius() >= wWidth) {
            circleMoveSpeedX *= -1.0f;
        }
        if (circle2.getPosition().y <= 0 || circle2.getPosition().y + 2 * circle2.getRadius() >= wHeight) {
            circle2MoveSpeedY *= -1.0f;
        }

        if (circle2.getPosition().x <= 0 || circle2.getPosition().x + 2 * circle2.getRadius() >= wWidth) {
            circle2MoveSpeedX *= -1.0f;
        }
        if (circle3.getPosition().y <= 0 || circle3.getPosition().y + 2 * circle3.getRadius() >= wHeight) {
            circle3MoveSpeedY *= -1.0f;
        }

        if (circle3.getPosition().x <= 0 || circle3.getPosition().x + 2 * circle3.getRadius() >= wWidth) {
            circle3MoveSpeedX *= -1.0f;
        }

        //rectangles bounds

        if (rect.getPosition().y <= 0 || rect.getPosition().y + rect.getSize().y >= wHeight) {
            rectMoveSpeedY *= -1.0f;
        }

        if (rect.getPosition().x <= 0 || rect.getPosition().x + rect.getSize().x >= wWidth) {
            rectMoveSpeedX *= -1.0f;
        }
        if (rect2.getPosition().y <= 0 || rect2.getPosition().y + rect2.getSize().y >= wHeight) {
            rect2MoveSpeedY *= -1.0f;
        }

        if (rect2.getPosition().x <= 0 || rect2.getPosition().x + rect2.getSize().x >= wWidth) {
            rect2MoveSpeedX *= -1.0f;
        }
        if (rect3.getPosition().y <= 0 || rect3.getPosition().y + rect3.getSize().y >= wHeight) {
            rect3MoveSpeedY *= -1.0f;
        }

        if (rect3.getPosition().x <= 0 || rect3.getPosition().x + rect3.getSize().x >= wWidth) {
            rect3MoveSpeedX *= -1.0f;
        }
        
        window.clear();
        updateShapeAndText(circle, text, circleMoveSpeedX, circleMoveSpeedY);
        window.draw(circle);
        window.draw(text);
        updateShapeAndText(circle2, text2, circle2MoveSpeedX, circle2MoveSpeedY);
        window.draw(circle2);
        window.draw(text2);
        updateShapeAndText(circle3, text3, circle3MoveSpeedX, circle3MoveSpeedY);
        window.draw(circle3);
        window.draw(text3);
        updateShapeAndText(rect, text4, rectMoveSpeedX, rectMoveSpeedY);
        window.draw(rect);
        window.draw(text4);
        updateShapeAndText(rect2, text5, rect2MoveSpeedX, rect2MoveSpeedY);
        window.draw(rect2);
        window.draw(text4);
        updateShapeAndText(rect3, text6, rect3MoveSpeedX, rect3MoveSpeedY);
        window.draw(rect3);
        window.draw(text6);
        window.display();
    }

    return 0;
}

void updateShapeAndText(sf::Shape& shape, sf::Text& text, float moveSpeedX, float moveSpeedY)
{
    // Update the shape position
    shape.setPosition(shape.getPosition().x + moveSpeedX, shape.getPosition().y + moveSpeedY);

    // Calculate the text bounds and set its origin
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

    // Set the text position based on the shape's position and properties
    if (sf::CircleShape* circle = dynamic_cast<sf::CircleShape*>(&shape)) {
        text.setPosition(circle->getPosition().x + circle->getRadius(), circle->getPosition().y + circle->getRadius());
    }
    else if (sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(&shape)) {
        // Adjust the position based on the rectangle shape properties
        text.setPosition(rectangle->getPosition().x + rectangle->getSize().x / 2.0f,
            rectangle->getPosition().y + rectangle->getSize().y / 2.0f);
    }
}
