﻿
#include "SortingAlgorithms.h"
//TODO czas pracy procesora czas pracy programu metryki tego typu

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
void SaveToFile(const std::vector<int>& list, const std::string& filepath) {
    // Open the file
    std::ofstream outFile(filepath);

    // Check if the file was opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Nie udalo sie otworzyc pliku zapisu " << filepath << std::endl;
        return;
    }

    // Write each element of the vector to the file
    for (int num : list) {
        outFile << num << " ";
    }

    // Close the file
    outFile.close();
}

int main()
{
    //zmienne
    bool Chose = false;
    bool ChoseBubbleSort = false;
    bool ChoseMergeSort = false;
    bool ChoseQuickSort = false;
    bool ChoseHeapSort = false;

    

    std::vector<int> NotSortedList = GetList("InputData/NotSortedList.txt");
    std::vector<int> SortedList;

    //frontend
    //obiekt okna
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Program Sortujacy");

    window.setFramerateLimit(60);
    //Guziki
    sf::RectangleShape Guzik1(sf::Vector2f(300, 200));//BubbleSort
    sf::RectangleShape Guzik2(sf::Vector2f(300, 200));//Mergesort
    sf::RectangleShape Guzik3(sf::Vector2f(300, 200));//QuickSort
    sf::RectangleShape Guzik4(sf::Vector2f(300, 200));//HeapSort
    sf::RectangleShape Guzik5(sf::Vector2f(300, 100));

    Guzik1.setPosition(150, 100);
    Guzik2.setPosition(550, 100);
    Guzik3.setPosition(150, 350);
    Guzik4.setPosition(550, 350);
    Guzik5.setPosition(350, 600);

    Guzik1.setFillColor(sf::Color::Black);
    Guzik2.setFillColor(sf::Color::Black);
    Guzik3.setFillColor(sf::Color::Black);
    Guzik4.setFillColor(sf::Color::Black);
    Guzik5.setFillColor(sf::Color::Black);

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

    sf::Text text5(L"Sortuj", font, 36);
    text5.setFillColor(sf::Color::White);
    text5.setPosition(450, 625);

    sf::Text MainText(L"Wybierz Algorytm sortujący", font, 48);
    MainText.setFillColor(sf::Color::Black);
    MainText.setPosition(200, 10);

    sf::Text TimeReal("Czas rzeczywisty:  ms", font, 20);
    TimeReal.setFillColor(sf::Color::Black);
    TimeReal.setPosition(20, 710);

    sf::Text TimeCPU("Czas Procesora: ms", font, 20);
    TimeCPU.setFillColor(sf::Color::Black);
    TimeCPU.setPosition(20, 740);



    
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
                //Wybor algorytmu Sortującego
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik1.getGlobalBounds()))//BubbleSort
                {
                    Guzik1.setFillColor(sf::Color::Red);
                    Guzik2.setFillColor(sf::Color::Black);
                    Guzik3.setFillColor(sf::Color::Black);
                    Guzik4.setFillColor(sf::Color::Black);

                    ChoseBubbleSort = true;
                    ChoseMergeSort = false;
                    ChoseQuickSort = false;
                    ChoseHeapSort = false;
                    
                }
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik2.getGlobalBounds()))//MergeSort
                {
                    Guzik1.setFillColor(sf::Color::Black);
                    Guzik2.setFillColor(sf::Color::Red);
                    Guzik3.setFillColor(sf::Color::Black);
                    Guzik4.setFillColor(sf::Color::Black);

                    ChoseBubbleSort = false;
                    ChoseMergeSort = true;
                    ChoseQuickSort = false;
                    ChoseHeapSort = false;
                }
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik3.getGlobalBounds()))//QuickSort
                {
                    Guzik1.setFillColor(sf::Color::Black);
                    Guzik2.setFillColor(sf::Color::Black);
                    Guzik3.setFillColor(sf::Color::Red);
                    Guzik4.setFillColor(sf::Color::Black);

                    ChoseBubbleSort = false;
                    ChoseMergeSort = false;
                    ChoseQuickSort = true;
                    ChoseHeapSort = false;
                }
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik4.getGlobalBounds()))//HeapSort
                {
                    Guzik1.setFillColor(sf::Color::Black);
                    Guzik2.setFillColor(sf::Color::Black);
                    Guzik3.setFillColor(sf::Color::Black);
                    Guzik4.setFillColor(sf::Color::Red);

                    ChoseBubbleSort = false;
                    ChoseMergeSort = false;
                    ChoseQuickSort = false;
                    ChoseHeapSort = true;
                }
                //Przycisk Sortowania Realese i Wywolywanie funkcji
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik5.getGlobalBounds()))
                {
                    Guzik5.setFillColor(sf::Color::Black);//Posortuj po wcisnieciu guzika
                    if (ChoseBubbleSort)
                    {
                        // Mierzenie czasu ściennego (rzeczywistego)
                        auto start_real = std::chrono::high_resolution_clock::now();

                        // Mierzenie czasu procesora
                        std::clock_t start_cpu = std::clock();

                        //Sortowanie
                        SortedList = Sorts::BubbleSort(NotSortedList);
                        //Zapis do pliku
                        SaveToFile(SortedList, "OutputData/SortedList1.txt");

                        // Zakończenie mierzenia czasu ściennego (rzeczywistego)
                        auto end_real = std::chrono::high_resolution_clock::now();

                        // Zakończenie mierzenia czasu procesora
                        std::clock_t end_cpu = std::clock();

                        //Czasy dzialania
                        // Obliczenie czasu ściennego (rzeczywistego) w milisekundach
                        auto elapsed_real = std::chrono::duration_cast<std::chrono::milliseconds>(end_real - start_real).count();

                        // Obliczenie czasu procesora w milisekundach
                        auto elapsed_cpu = 1000.0 * (end_cpu - start_cpu) / CLOCKS_PER_SEC;

                        TimeReal.setString("Czas rzeczywisty: " + std::to_string(elapsed_real) + " ms");
                        TimeCPU.setString("Czas procesora: " + std::to_string(elapsed_cpu) + " ms");


                    }
                    if (ChoseMergeSort)
                    {
                        // Mierzenie czasu ściennego (rzeczywistego)
                        auto start_real = std::chrono::high_resolution_clock::now();

                        // Mierzenie czasu procesora
                        std::clock_t start_cpu = std::clock();

                        SortedList = Sorts::MergeSort(NotSortedList);

                        SaveToFile(SortedList, "OutputData/SortedList2.txt");

                        // Zakończenie mierzenia czasu ściennego (rzeczywistego)
                        auto end_real = std::chrono::high_resolution_clock::now();

                        // Zakończenie mierzenia czasu procesora
                        std::clock_t end_cpu = std::clock();

                        //Czasy dzialania
                        // Obliczenie czasu ściennego (rzeczywistego) w milisekundach
                        auto elapsed_real = std::chrono::duration_cast<std::chrono::milliseconds>(end_real - start_real).count();

                        // Obliczenie czasu procesora w milisekundach
                        auto elapsed_cpu = 1000.0 * (end_cpu - start_cpu) / CLOCKS_PER_SEC;

                        TimeReal.setString("Czas rzeczywisty: " + std::to_string(elapsed_real) + " ms");
                        TimeCPU.setString("Czas procesora: " + std::to_string(elapsed_cpu) + " ms");
                    }
                    if (ChoseQuickSort)
                    {
                        // Mierzenie czasu ściennego (rzeczywistego)
                        auto start_real = std::chrono::high_resolution_clock::now();

                        // Mierzenie czasu procesora
                        std::clock_t start_cpu = std::clock();

                        SortedList = Sorts::QuickSort(NotSortedList);

                        SaveToFile(SortedList, "OutputData/SortedList3.txt");

                        // Zakończenie mierzenia czasu ściennego (rzeczywistego)
                        auto end_real = std::chrono::high_resolution_clock::now();

                        // Zakończenie mierzenia czasu procesora
                        std::clock_t end_cpu = std::clock();

                        //Czasy dzialania
                        // Obliczenie czasu ściennego (rzeczywistego) w milisekundach
                        auto elapsed_real = std::chrono::duration_cast<std::chrono::milliseconds>(end_real - start_real).count();

                        // Obliczenie czasu procesora w milisekundach
                        auto elapsed_cpu = 1000.0 * (end_cpu - start_cpu) / CLOCKS_PER_SEC;

                        TimeReal.setString("Czas rzeczywisty: " + std::to_string(elapsed_real) + " ms");
                        TimeCPU.setString("Czas procesora: " + std::to_string(elapsed_cpu) + " ms");
                    }
                    if (ChoseHeapSort)
                    {
                        // Mierzenie czasu ściennego (rzeczywistego)
                        auto start_real = std::chrono::high_resolution_clock::now();

                        // Mierzenie czasu procesora
                        std::clock_t start_cpu = std::clock();

                        SortedList = Sorts::heapSort(NotSortedList);

                        SaveToFile(SortedList, "OutputData/SortedList4.txt");

                        // Zakończenie mierzenia czasu ściennego (rzeczywistego)
                        auto end_real = std::chrono::high_resolution_clock::now();

                        // Zakończenie mierzenia czasu procesora
                        std::clock_t end_cpu = std::clock();

                        //Czasy dzialania
                        // Obliczenie czasu ściennego (rzeczywistego) w milisekundach
                        auto elapsed_real = std::chrono::duration_cast<std::chrono::milliseconds>(end_real - start_real).count();

                        // Obliczenie czasu procesora w milisekundach
                        auto elapsed_cpu = 1000.0 * (end_cpu - start_cpu) / CLOCKS_PER_SEC;

                        TimeReal.setString("Czas rzeczywisty: " + std::to_string(elapsed_real) + " ms");
                        TimeCPU.setString("Czas procesora: " + std::to_string(elapsed_cpu) + " ms");


                    }
                    
                }
                
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                //Przycisk Sortowanai OnClick
                if (CheckMouseColision(sf::Mouse::getPosition(window), Guzik5.getGlobalBounds()))
                {
                    Guzik5.setFillColor(sf::Color::Red);

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
        window.draw(Guzik5);
        window.draw(text5);
        window.draw(TimeReal);
        window.draw(TimeCPU);
        //Funkcje
        //CheckMouseColision(sf::Mouse::getPosition(window), Guzik1.getGlobalBounds());


        window.display();

    }

        
    

    return 0;
}
