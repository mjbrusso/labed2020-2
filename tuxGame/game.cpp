#include <SFML/Graphics.hpp>
#include <string>

enum tuxStatus {
    Walking,
    JumpingUp,
    FallingDown,
    Dead
};

int main() {
    const int windowWidth = 800, windowHeight = 400;
    const float step_time = 0.1, groundSpeed = 2;

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

    sf::Texture menuTexture;
    menuTexture.loadFromFile("assets/menu.png");
    sf::Sprite menuSprite(menuTexture);
    menuSprite.setColor(sf::Color(255, 255, 255, 100));

    sf::Font font;
    font.loadFromFile("assets/pixelart.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setPosition(10, 10);
    text.setString("0");

    float tuxY = windowHeight - 90, oilX = windowWidth;
    bool gameOver = false;
    int steps = 0;
    tuxStatus tuxCurrentStatus = tuxStatus::Walking;
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
                else if (event.key.code == sf::Keyboard::F2){
                    gameOver = false;
                    bgRect = {0, 0, windowWidth, windowHeight};
                    grRect = {0, 375, windowWidth, 25};
                    tuxRect = {12, 786, 42, 67};
                    text.setString("0");
                    tuxY = windowHeight - 90;
                    oilX = windowWidth;
                    steps = 0;
                    tuxCurrentStatus = tuxStatus::Walking;
                }
            }
        }
        // Atualização do estado do jogo

        if (!gameOver) {
            bgRect.left++;
            bgSprite.setTextureRect(bgRect);

            grSprite.setPosition(0, 375);
            grRect.left -= groundSpeed;
            grSprite.setTextureRect(grRect);

            if (clock.getElapsedTime().asSeconds() >= step_time) {
                if (tuxCurrentStatus == tuxStatus::Walking) {
                    tuxRect.left += 65;
                    if (tuxRect.left >= 470) {
                        tuxRect.left = 12;
                    }
                    steps++;
                    text.setString(std::to_string(steps/8));
                }
                clock.restart();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                tuxCurrentStatus = tuxStatus::JumpingUp;
                tuxRect = {9, 608, 47, 49};
            }

            if (tuxCurrentStatus == tuxStatus::JumpingUp) {
                tuxY--;
                if (tuxY <= windowHeight - 119)
                    tuxCurrentStatus = tuxStatus::FallingDown;
            }
            if (tuxCurrentStatus == tuxStatus::FallingDown) {
                tuxY++;
                if (tuxY >= windowHeight - 90){
                    tuxCurrentStatus = tuxStatus::Walking;
                    tuxRect = {12, 786, 42, 67};
                }
            }
            tuxSprite.setTextureRect(tuxRect);
            tuxSprite.setPosition(20, tuxY);

            oilX -= groundSpeed;
            if (oilX <= -65) oilX = windowWidth;
            oilSprite.setPosition(oilX, windowHeight - 27);

            if (tuxSprite.getGlobalBounds().intersects(oilSprite.getGlobalBounds())) {
                gameOver = true;
                tuxRect.top = 123;
                tuxRect.left = 74;
                tuxSprite.setTextureRect(tuxRect);
                text.setString("Game over!");
            }
        }
        // Desenha o frame
        window.clear();
        window.draw(bgSprite);
        window.draw(grSprite);
        window.draw(tuxSprite);
        window.draw(oilSprite);
        window.draw(text);
        if(gameOver) window.draw(menuSprite);
        window.display();
    }

    return 0;
}
