#ifndef _DataContainer
#define _DataContainer

#include "BannerInfo.h"

#include <string>
#include <unordered_map>
#include <map>
#include <list>

class DataContainer {

public:
    void addCNT(const std::string& aCode, const std::string& aEvent_id);

    void addSEL(const std::string& aCode, const std::string& aBanner_id, double aPrice);

    void prepareToOutput();	

    const TBannerHashMap& getResults() const;

private:
    static const std::string place_id;

    static const std::string sell_id;
 
    struct PriceInfo {
        PriceInfo(const std::string& aBanner_id, double aPrice):banner_id(aBanner_id),price(aPrice){}
        std::string banner_id;
        double price;
    };
  
    struct EventInfo {
        EventInfo(const std::string& aCode,const std::string& aEvent):code(aCode),event_id(aEvent){}
        std::string code;
        std::string event_id;
    };
  
    TBannerHashMap banner_hashmap; //key is banner_id
    std::unordered_map<std::string, PriceInfo> price_hashmap; //code of event 6 is the key
    std::list<EventInfo> event_list; //Event list is needed, cause it wasn't specified that events occure after event "6"
    //for a given code, otherwise the incoming events could be treated on the fly and there would be no need for this container
};


#endif
