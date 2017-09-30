#include "FileParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

void FileParser::parseLine(std::string& aInput, DataContainer& aContainer) const
{
  if(aInput[3] != ':') {
    throw std::runtime_error("Bad format, there isnt : at 4th character"); 
  }
  aInput[3] = ' '; 
  std::stringstream str_stream(aInput);
  std::string tmp;
  str_stream >> tmp;
  aInput.erase(0,4);
  if(tmp == "sel")
  {
      parseSEL(aInput, aContainer);
  }
  else if(tmp == "cnt")
  {
      parseCNT(aInput, aContainer);
  }	 
}

void FileParser::parseCNT(const std::string& aInput, DataContainer& aContainer) const
{
  std::stringstream str_stream(aInput);
  std::string code;
  std::string id;
  std::getline(str_stream, id, ',');
  std::getline(str_stream, code, ',');
  aContainer.addCNT(code, id); 
}

void FileParser::parseSEL(const std::string& aInput, DataContainer& aContainer) const
{
  std::stringstream str_stream(aInput);
  std::string code;
  std::string id;
  std::string bannerID;
  std::string price_str;
  double price;
  std::getline(str_stream, code, ',');
  if(code != "6") {
    throw std::runtime_error("Bad format, event is not 6 or SEL");
  }
  std::getline(str_stream, id, ',');
  std::getline(str_stream, bannerID, ',');
  std::getline(str_stream, price_str, ',');
  std::stringstream price_ss(price_str);
  price_ss >> price;
  aContainer.addSEL(id, bannerID, price); 
}

void FileParser::parceData(DataContainer& aContainer) const{
  std::string line;
  std::ifstream infile;
  infile.open(iFilename);
  while(!infile.eof()) 
  {
    getline(infile,line);
	parseLine(line, aContainer);
  }
  infile.close();
}
