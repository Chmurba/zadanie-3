#ifndef PPMREADER_H
#define PPMREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include "ImageReader.h"
#include <set>

class PPMReader : public ImageReader
{
public:
    PPMReader(std::string imagePath);

    void printImageInfo() override;
    void printMostFrequentColor() override;
    int calculateNumberOfUniqueColors() override;

private:
    std::fstream imageFile;
    std::vector<std::tuple<int, int, int>> imageData;

    int width;
    int height;
    std::tuple<int, int, int> getMostFrequentColor();
    std::map<std::tuple<int, int, int>, int> colorFrequency; 

};

#endif // PPMREADER_HP