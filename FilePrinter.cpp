#include "FilePrinter.h"

namespace {
  const std::string KfourSpaces = "    ";
  const std::string KendLine = "\n";
}
void FilePrinter::print(const TBannerHashMap& aBannerHashMap) const {
    std::ofstream outFile;
    outFile.open(filename);
    outFile<< "<Banners>"<<KendLine;
    for(const auto& banner : aBannerHashMap) {
        printBanner(outFile, banner.first, banner.second);
    }
    outFile<< "</Banners>";
    outFile.close();
}
  
void FilePrinter::printBanner(std::ofstream& aStream, const std::string& aBannerId, const BannerInfo& aBanner) const
{
    aStream<<KfourSpaces<<"<Banner id=\""<<aBannerId<<"\" revenues=\""<<aBanner.money_earned<<"\">"<<KendLine;
    aStream<<KfourSpaces<<KfourSpaces<<"<Events>"<<KendLine;
    for(const auto& eventInfo : aBanner.eventInfo_map) {
        //Note: looks like it should be /Event instead of /event, but that how it was written in the task
  	//example : <Banner id="Banner­71" revenues="6.449">  <Events>  <Event id="6">2</event> ...
        aStream<<KfourSpaces<<KfourSpaces<<KfourSpaces<<"<Event id=\""<<eventInfo.first<<"\">"<<eventInfo.second<<"</event>"<<KendLine;
    }  
    aStream<<KfourSpaces<<KfourSpaces<<"</Events>"<<KendLine;
}

void FilePrinter::printError(const std::string& aError) const {
    std::ofstream outFile;
    outFile.open(filename);
    outFile << "Exception occured: ";
    outFile << aError;
    outFile.close();
}


