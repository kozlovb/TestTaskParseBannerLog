#ifndef _FilePrinter
#define _FilePrinter

#include "BannerInfo.h"
#include <string>
#include <iostream>
#include <fstream>

class FilePrinter {
public:
  FilePrinter(const std::string aFileName)
  : filename(aFileName)
  {}

  void print(const TBannerHashMap& aBannerHashMap) const;

  void printError(const std::string& aError) const;	
private:
  void printBanner(std::ofstream& aStream,const std::string& aBannerId, const BannerInfo& aBanner) const;

  std::string filename;
};

#endif
