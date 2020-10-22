#include <SFML/Graphics.hpp>

int main() {
    const int windowWidth = 800, windowHeight = 400;
    const float step_time = 0.1, groundSpeed = 1.2;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Meu game");
    window.setFramerateLimit(60);

    sf::Clock clock;

    sf::Texture bgTexture;
    bgTexture.loadFromFile("assets/background.png");
    bgTexture.setRepeated(true);
    sf::IntRect bgRect(0, 0, windowWidth, windowHeight);
    sf::Sprite bgSprite(bgTexture);

    sf::IntRect grRect(0, 375, windowWidth, 25);
    sf::Sprite grSprite(bgTexture);

    sf::Texture tuxTexture;
    tuxTexture.loadFromFile("assets/supertux.png");
    sf::IntRect tuxRect(12, 786, 42, 67);
    sf::Sprite tuxSprite(tuxTexture);

    sf::Texture oilTexture;
    oilTexture.loadFromFile("assets/oil.png");
    sf::Sprite oilSprite(oilTexture);

    float tuxY = windowHeight - 90, oilX = windowWidth;
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
        bgRect.left++;
        bgSprite.setTextureRect(bgRect);
        
        grSprite.setPosition(0, 375);
        grRect.left -= groundSpeed;
        grSprite.setTextureRect(grRect);

        if(clock.getElapsedTime().asSeconds() >= step_time){
            tuxRect.left += 65;
            if(tuxRect.left >= 470) tuxRect.left = 12;
            clock.restart();
        }
        
        tuxSprite.setTextureRect(tuxRect);
        tuxSprite.setPosition(20, tuxY);

        oilX -= groundSpeed;
        if(oilX <= -65) oilX = windowWidth;
        oilSprite.setPosition(oilX, windowHeight-27);

    

        // Desenha o frame
        window.clear(sf::Color::White);
        window.draw(bgSprite);
        window.draw(grSprite);
        window.draw(tuxSprite);
        window.draw(oilSprite);
        window.display();
    }

    return 0;
}
