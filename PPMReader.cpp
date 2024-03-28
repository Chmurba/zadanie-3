#include "PPMReader.h"

PPMReader::PPMReader(std::string imagePath)
{
    imageFile.open(imagePath, std::ios::in);

    if (imageFile.good())
    {
        std::string fileType;
        std::string comment;
        int red, green, blue;
        try
        {
            // Wczytanie typu pliku
            std::getline(imageFile, fileType);
            // Wczytanie linii z komentarzem
            std::getline(imageFile, comment);
            // Wczytanie szerokoœci i wysokoœci
            imageFile >> width >> height;
            // Pomiñ maksymaln¹ wartoœæ koloru
            imageFile >> std::ws; // Pominiêcie bia³ych znaków przed czytaniem danych pikseli

            while (imageFile >> red >> green >> blue)
            {
                imageData.push_back(std::make_tuple(red, green, blue));
            }
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << "\n";
        }
    }
    else
    {
        std::cout << "Nie uda³o siê otworzyæ pliku " << imagePath << "\n";
    }
}

void PPMReader::printImageInfo()
{
    std::cout << "Wielkosc obrazu: " << height << "\n";
    std::cout << "Szerokosc obrazu " << width << "\n";
    auto mostFrequentColor = getMostFrequentColor();
    std::cout << "Najczêstszy kolor: RGB(" << std::get<0>(mostFrequentColor) << ", " << std::get<1>(mostFrequentColor) << ", " << std::get<2>(mostFrequentColor) << ")\n";
    std::cout << "Unikalnych kolorów: " << calculateNumberOfUniqueColors() << "\n";
}

void PPMReader::printMostFrequentColor()
{
    auto mostFrequentColor = getMostFrequentColor();
    std::cout << "Najczêstszy kolor: RGB(" << std::get<0>(mostFrequentColor) << ", " << std::get<1>(mostFrequentColor) << ", " << std::get<2>(mostFrequentColor) << ")\n";
}

int PPMReader::calculateNumberOfUniqueColors()
{
    std::set<std::tuple<int, int, int>> uniqueColors(imageData.begin(), imageData.end());
    return uniqueColors.size();
}

std::tuple<int, int, int> PPMReader::getMostFrequentColor()
{
    // Inicjacja mapy colorFrequency
    std::map<std::tuple<int, int, int>, int> colorFrequency;

    // Obliczenie czêstotliwoœci wystêpowania ka¿dego koloru
    for (const auto& color : imageData)
    {
        colorFrequency[color]++;
    }

    // Znalezienie koloru o najwiêkszej czêstotliwoœci wystêpowania
    auto mostFrequent = std::max_element(colorFrequency.begin(), colorFrequency.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    return mostFrequent->first;
}

