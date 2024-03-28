#include "PGMReader.h"
#include "PPMReader.h"

int main() {
    PGMReader pgmReader("dd.pgm");
    PPMReader ppmReader("f.ppm");

    ImageReader* reader = &pgmReader;
    reader->printImageInfo();
    reader->calculateNumberOfUniqueColors();
    reader->printMostFrequentColor();

   reader = &ppmReader;
   reader->printImageInfo();
   reader->calculateNumberOfUniqueColors();
   reader->printMostFrequentColor();

    return 0;
}
