class StockPrice {
public:
    int latest_time;
    unordered_map<int,int> timestamp_price;
    map<int,int> pricefreq;
    StockPrice() {
        latest_time=0;
    }
    
    void update(int timestamp, int price) {
        latest_time=max(latest_time,timestamp);
        if(timestamp_price.find(timestamp)!=timestamp_price.end()){
            int oldPrice=timestamp_price[timestamp];
            pricefreq[oldPrice]--;
            if(pricefreq[oldPrice]==0)
                pricefreq.erase(oldPrice);
        }
        timestamp_price[timestamp]=price;
        pricefreq[price]++;
    }
    
    int current() {
        return timestamp_price[latest_time];
    }
    
    int maximum() {
        return pricefreq.rbegin()->first;
    }
    
    int minimum() {
        return pricefreq.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */