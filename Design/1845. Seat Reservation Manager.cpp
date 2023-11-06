class SeatManager {
public:
    int seat_marker;
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        seat_marker = 1;
    }
    
    int reserve() {
        if(!pq.empty()){
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        int seat = seat_marker;
        seat_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
