#include "PGMReader.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>


PGMReader::PGMReader(const std::string& filename) {

    name = filename;
    file.open(filename, std::ios::in); // U¿ywamy ifstream do otwarcia pliku
    if (!file.good()) { // Sprawdzamy czy plik zosta³ poprawnie otwarty
        std::cout << "Blad: Nie mozna otworzyc pliku" << filename << std::endl;
        return;
    }

    std::string formatIdentifier;
    std::getline(file, formatIdentifier);

    if (formatIdentifier != "P2") {
        std::cout << "Blad: Niewspierany format pliku: " << formatIdentifier << std::endl;
        file.close(); // Zamykamy plik przed wyjœciem
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == '#')
            continue;
        std::istringstream iss(line);
        if (!(iss >> width >> height))
            break;
        break;
    }

    int pixel;
    while (file >> pixel) {
        pixels.push_back(pixel);
    }

    file.close();
}

void PGMReader::printImageInfo()  {
    std::cout << "Image Width: " << width << std::endl;
    std::cout << "Image Height: " << height << std::endl;
    std::cout << "Total Pixels: " << width * height << std::endl;
}

int PGMReader::calculateNumberOfUniqueColors()  {
    std::map<int, int> colorCount;
    for (int pixel : pixels) {
        colorCount[pixel]++;
    }
    std::cout << "Number of Unique Colors: " << colorCount.size() << std::endl;
    return colorCount.size();
}

void PGMReader::printMostFrequentColor()  {
    std::map<int, int> colorCount;
    for (int pixel : pixels) {
        colorCount[pixel]++;
    }
    auto maxColor = std::max_element(colorCount.begin(), colorCount.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });
    std::cout << "Most Frequent Color: " << maxColor->first << " (Count: " << maxColor->second << ")" << std::endl;
}
