
#include "SortingAlgorithms.h"

//Funkcja sprawdzająca kolizje

bool CheckMouseColision(sf::Vector2i mousePosition,sf::FloatRect bounds)
{
    if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        std::cout << "Mouse Position: (" << mousePosition.x << ", " << mousePosition.y << ")" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

//Funkcja odczytująca liste z pliku tekstowego
std::vector<int> GetList(std::string filePath) 
{
    std::ifstream inputFile(filePath); 
    if (!inputFile) 
    {
        return std::vector<int> {0};
    }

    std::vector<int> numbers; 

    int num;
    while (inputFile >> num) 
    { 
        numbers.push_back(num); 
    }

    inputFile.close(); 
    return numbers;

}
//To Do funkcja zapisująca posortowana liste do pliku tekstowego


int main()
{
    //zmienne
    bool Chose = false;

    //frontend
    //obiekt okna
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Program Sortujacy");

    window.setFramerateLimit(60);
    //Guziki
    sf::RectangleShape Guzik1(sf::Vector2f(300, 200));
    sf::RectangleShape Guzik2(sf::Vector2f(300, 200));
    sf::RectangleShape Guzik3(sf::Vector2f(300, 200));
    sf::RectangleShape Guzik4(sf::Vector2f(300, 200));

    Guzik1.setPosition(150, 100);
    Guzik2.setPosition(550, 100);
    Guzik3.setPosition(150, 350);
    Guzik4.setPosition(550, 350);

    Guzik1.setFillColor(sf::Color::Black);
    Guzik2.setFillColor(sf::Color::Black);
    Guzik3.setFillColor(sf::Color::Black);
    Guzik4.setFillColor(sf::Color::Black);

    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) //zaladuj czcionke
    {
        std::cout << "Nie zaladowano czcionki" << std::endl;
        return -1;
    }
    //Text
    sf::Text text1(L"Sortowanie\nBąbelkowe", font, 36);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(175, 125);

    sf::Text text2(L"Sortowanie\nPrzez \nScalanie", font, 36);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(575, 125);

    sf::Text text3(L"Sortowanie\nSzybkie", font, 36);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(175, 375);

    sf::Text text4(L"Sortowanie\nPrzez \nKopcowanie", font, 36);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(575, 375);

    sf::Text MainText(L"Wybierz Algorytm sortujący", font, 48);
    MainText.setFillColor(sf::Color::Black);
    MainText.setPosition(200, 10);


    


    
    //Okno
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            //Klikniecie na guziki 
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik1.getGlobalBounds()))
                {
                    Guzik1.setFillColor(sf::Color::Red);
                    Guzik2.setFillColor(sf::Color::Black);
                    Guzik3.setFillColor(sf::Color::Black);
                    Guzik4.setFillColor(sf::Color::Black);
                }
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik2.getGlobalBounds()))
                {
                    Guzik1.setFillColor(sf::Color::Black);
                    Guzik2.setFillColor(sf::Color::Red);
                    Guzik3.setFillColor(sf::Color::Black);
                    Guzik4.setFillColor(sf::Color::Black);
                }
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik3.getGlobalBounds()))
                {
                    Guzik1.setFillColor(sf::Color::Black);
                    Guzik2.setFillColor(sf::Color::Black);
                    Guzik3.setFillColor(sf::Color::Red);
                    Guzik4.setFillColor(sf::Color::Black);
                }
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik4.getGlobalBounds()))
                {
                    Guzik1.setFillColor(sf::Color::Black);
                    Guzik2.setFillColor(sf::Color::Black);
                    Guzik3.setFillColor(sf::Color::Black);
                    Guzik4.setFillColor(sf::Color::Red);
                }
                
            }
        }
        window.clear(sf::Color::White);//czysc okno

        //RysujObiekty
        window.draw(Guzik1);
        window.draw(text1);
        window.draw(Guzik2);
        window.draw(text2);
        window.draw(Guzik3);
        window.draw(text3);
        window.draw(Guzik4);
        window.draw(text4);
        window.draw(MainText);
        //Funkcje
        //CheckMouseColision(sf::Mouse::getPosition(window), Guzik1.getGlobalBounds());


        window.display();

    }

        
    

    return 0;
}
