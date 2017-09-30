#include "DataContainer.h"
#include <exception>

const std::string DataContainer::place_id = "6";
const std::string DataContainer::sell_id = "1";

void DataContainer::addCNT(const std::string& aCode, const std::string& aEvent_id) {
  event_list.push_back(EventInfo(aCode, aEvent_id));
}

void DataContainer::addSEL(const std::string& aCode, const std::string& aBanner_id, double aPrice) {
    if( !price_hashmap.insert({aCode, PriceInfo(aBanner_id, aPrice)}).second) {
        throw std::runtime_error("Bad data: same code twice for event 6");
    }
    auto banner_it = banner_hashmap.find(aBanner_id);
    if(banner_it!=banner_hashmap.end())
    {
        auto place_it = banner_it->second.eventInfo_map.find(place_id);
	place_it->second++;
    }
    else {
        banner_hashmap.insert({aBanner_id,BannerInfo(place_id)});
    }	
}

void DataContainer::prepareToOutput(){
    for(const auto& event:event_list){
	auto it_priceInfo = price_hashmap.find(event.code);
	if(it_priceInfo != price_hashmap.end()) {
    	    auto it_banner = banner_hashmap.find(it_priceInfo->second.banner_id);
    	    if(it_banner != banner_hashmap.end()) {
    	       BannerInfo& banner = it_banner->second;
    	       if(event.event_id == sell_id) {
    	          banner.money_earned += it_priceInfo->second.price;
               }
    	       auto it_event = banner.eventInfo_map.find(event.event_id);
    	       if(it_event != banner.eventInfo_map.end()){
    	           it_event->second++;    	       	     	
	       }
	       else {
	           banner.eventInfo_map.insert(std::make_pair(event.event_id,1)); 
	       }
	
	    }  
	}
    }
}
const TBannerHashMap& DataContainer::getResults() const { 
  return banner_hashmap; 
}
