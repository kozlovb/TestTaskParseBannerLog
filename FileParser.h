#ifndef _FileParser
#define _FileParser

#include <iostream>
#include <fstream>
#include "DataContainer.h"

class FileParser {
public:
    
    FileParser(const std::string& aName)
    : iFilename(aName)
    {}

    void parceData(DataContainer& aContainer) const;

private:
    
    void parseLine(std::string& aInput, DataContainer& aContainer) const;
    
    void parseCNT(const std::string& aInput, DataContainer& aContainer) const;
    
    void parseSEL(const std::string& aInput, DataContainer& aContainer) const;

private:
    std::string iFilename; 	  
};

#endif
