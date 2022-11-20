#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<set>
#include<string>

using namespace std;
set<string> res;

void search(int quantity, queue<string> out, queue<string> trains, stack<string> station)
{
    if(trains.empty() && station.empty() || out.size() == quantity ){ 
            string res_str="";
            while (!out.empty())
            {
                cout << out.front() << " ";
                res_str+=out.front();
                res_str+=" ";
                out.pop();
            }
            cout << endl;
            res.insert(res_str);
        return;
    }

  
    
  
    

    stack<string>station_copy = station;
    queue<string>trains_copy = trains;
    queue<string>out_copy = out;

    while(!trains.empty()){
        // 火车入站
        station.push(trains.front());
        trains.pop();
        search(quantity,out,trains,station);
        
    }

    while(!station_copy.empty()){
        // 火车出站
        out.push(station_copy.top());
        station_copy.pop();
        search(quantity,out,trains_copy,station_copy);
    }


}


int main()
{
    int quantity=0;
    cin>>quantity;
    string num;
    queue<string> trians; 
    for (int i=0;i<quantity;i++){
        cin >> num;
        // getline(cin,num);
        trians.push(num);
    }

    stack<string> station;
    queue<string> out;

    search(quantity,out,trians,station);
    // int len = int(out.size());
   
 
    for(auto it=res.begin();it!=res.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}

