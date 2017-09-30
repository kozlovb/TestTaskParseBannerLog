#include "DataContainer.h"
#include "FileParser.h"
#include "FilePrinter.h"

#include <iostream>
#include <exception>

int main(int argc, char** argv) {

    const std::string input_filename = argv[1];
    FilePrinter filePrinter("dataOut.txt");

    try {
        FileParser fileParser(input_filename);
        DataContainer dataContainer;
        fileParser.parceData(dataContainer);
        dataContainer.prepareToOutput();
        filePrinter.print(dataContainer.getResults());
    }
    catch(std::exception& e) {
      filePrinter.printError(e.what());
    }

    return 0;
}


