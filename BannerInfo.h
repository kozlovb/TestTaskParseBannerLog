#ifndef _BannerInfo
#define _BannerInfo

#include <map>
#include <unordered_map>
#include <string>

struct BannerInfo {
  BannerInfo(const std::string& aEvent)
  : money_earned(0) { 	
    eventInfo_map = { {aEvent,1} };
  }
  double money_earned;
  //key event_id,value occurrences
  std::map<std::string,int> eventInfo_map;	 
};
  //const std::string BannerInfo::place_id="1";
  typedef std::unordered_map<std::string,BannerInfo> TBannerHashMap;
#endif
