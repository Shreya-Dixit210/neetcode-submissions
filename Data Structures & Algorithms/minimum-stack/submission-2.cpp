class MinStack {
public:
    // stack<long long int>s;
    // int minVal;
    MinStack() {
        
    }
    
    // void push(int val) {
    //     if(s.empty()){
    //         s.push(val);
    //         minVal = val;
    //     }else{
    //         if(val < minVal){
    //             s.push((long long)2*val - minVal);
    //             minVal = val;
    //         }else{
    //             s.push(val);
    //         }
    //     } 
    // }
    
    // void pop() {
    //     if(s.top() < minVal){
    //         minVal = 2*minVal - s.top();
    //     }
    //     s.pop();
    // }
    
    // int top() {
    //     if(s.top() < minVal){
    //         return minVal;
    //     }
    //     return s.top();
    // }
    
    // int getMin() {
    //     return minVal;
    // }

stack<pair<int, int>> s;

void push (int val){
    if(s.empty()){
        s.push({val,val});
    }else{
        s.push({val,min(val, s.top().second)});
    }
}
void pop(){
    s.pop();
}

int top(){
    return s.top().first;
}

int getMin(){
    return s.top().second;
}

};