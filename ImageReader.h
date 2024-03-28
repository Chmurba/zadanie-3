#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <iostream>

class ImageReader {
public:
    virtual void printImageInfo()  = 0;
    virtual int calculateNumberOfUniqueColors()  = 0;
    virtual void printMostFrequentColor()  = 0;
};

#endif // IMAGEREADER_H
