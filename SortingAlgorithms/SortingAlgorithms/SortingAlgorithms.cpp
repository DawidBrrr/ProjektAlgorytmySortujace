
#include "SortingAlgorithms.h"

std::vector<int> GetList(std::string filePath) //Funkcja odczytująca liste z pliku tekstowego
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
    //Variables
    int ChoiceList, ChoiceAlgorithm, ChoiceWay,NumberOfElements;
    std::string filePath = "InputData/NotSortedList.txt";
    std::vector<int> List;
    

    //Text Interface
    std::cout << "Witaj w programie przedstawiajacym algorytmy sortujace" << std::endl;
    //Wprowadzanie Listy
    std::cout << "Wybierz jak chcesz wprowadzic liste do posortowania(1-z pliku,2-wpisac z klawiatury) :  ";
    do{
        std::cin >> ChoiceList;
        
        if (ChoiceList != 1 && ChoiceList != 2)
        {
            std::cout << "Wpisz liczbe 1 lub 2!! : ";
        }

    } while(ChoiceList != 1 && ChoiceList != 2);
    if (ChoiceList == 1)
    {
        List = GetList(filePath);
    }
    else if (ChoiceList == 2)
    {
        std::cout << "Ile elementow chcesz wprowadzic : ";
        do {
            std::cin >> NumberOfElements;
            
            if (NumberOfElements < 1)
            {
                std::cout << "Liczba elementow nie moze byc mniejsza od 1 : ";
            }

        } while (NumberOfElements < 1);
        for(int i = 0;i < NumberOfElements;i++)
        { 
            List.push_back(0);
        }
        std::cout << "Wprowadz elementy listy" << std::endl;
        for (int i = 0; i < NumberOfElements; i++)
        {
            std::cin >> List[i];
        }
    }
    //Wybor Algorytmu Sortujacego
    std::cout << "Wybierz rodzaj algorytmu Sortujacego" << std::endl;
    std::cout << "1.Sortowanie babelkowe/2.Sortowanie przez scalanie/3.Sortowanie szybkie/4.Sortowanie przez kopcowanie" << std::endl;
    std::cout << "Wpisz liczbe odpowiadajaca za wybrany algorytm : ";
    do {
        std::cin >> ChoiceAlgorithm;
        if (ChoiceAlgorithm > 4 && ChoiceAlgorithm < 1)
        {
            std::cout << "Wybierz liczbe odpowiadajaca algorytmowi: ";
        }

    } while (ChoiceAlgorithm > 4 && ChoiceAlgorithm < 1);
    
    switch (ChoiceAlgorithm)
    {
        case 1:
            //Bobelkowe
            break;
        case 2:
            //Merge
            break;
        case 3:
            //Quicksort
            break;
        case 4:
            //Heapsort
            break;
        default:
            std::cout << "Blad" << std::endl;
    }
    

        
    
    


}
