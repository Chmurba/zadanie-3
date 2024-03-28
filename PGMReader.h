#ifndef PGMREADER_H
#define PGMREADER_H

#include "ImageReader.h"
#include <vector>
#include <string>
#include <fstream>


class PGMReader : public ImageReader {
private:
    int width;
    int height;
    int maxVal;
    std::vector<int> pixels;
    std::string name;
    std::fstream file;

public:
    PGMReader(const std::string& filename);

   virtual void printImageInfo() override;
   virtual int calculateNumberOfUniqueColors() override;
   virtual void printMostFrequentColor()  override;
};

#endif // PGMREADER_H
