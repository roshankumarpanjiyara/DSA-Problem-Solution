class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkin;
    unordered_map<string, pair<double, int>> distance; 

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = checkin[id];
        checkin.erase(id);

        string route = it.first+"_"+stationName;
        distance[route].first += (1.0 * abs(t-it.second));
        distance[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"_"+endStation;

        return distance[route].first/distance[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
