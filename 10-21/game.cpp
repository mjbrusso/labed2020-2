#include <SFML/Graphics.hpp>

int main() {
    const int windowWidth = 800, windowHeight = 400;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Meu game");
    window.setFramerateLimit(60);

    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Green);
    float x=0;

    // game loop
    while (window.isOpen()) {
        // Tratamento dos eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        // Atualização do estado do jogo
        x++;
        shape.setPosition(x, 200);

        // Desenha o frame
        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }

    return 0;
}
