#include<bits/stdc++.h>
using namespace std;
class Player{
    private:
        string name;
        int h;
        int xp;
    public:
        Player(std::string name_val="None",int h_val=0,int xp_val=0);    
};
Player::Player(std::string name_val,int h_val,int xp_val)
    :name{name_val},h{h_val},xp{xp_val}{
        cout<<"Constructor"<<endl;
    }

double mpg(int miles,int gallons){
    if(gallons==0){
        throw 0;
    }
    if(miles<0 || gallons<0){
        throw string("negative number not allowed");
    }
    return static_cast<double>(miles/gallons);
}
void func_c(){
    cout<<"Starting c"<<endl;
    throw 0;
    cout<<"Ending c"<<endl;
}

void func_b(){
    cout<<"Starting b"<<endl;
    func_c();
    
    cout<<"Ending b"<<endl;
}

void func_a(){
    cout<<"Starting a"<<endl;
    try{
        func_b();
    }
    catch(int &ex){
        cerr<<"Giving error in a"<<endl;
    }
    cout<<"Ending a"<<endl;
}

int main()
{
    // map<string,int>mp;
    // mp["one"]=1;
    // mp["two"]=2;
    // mp["three"]=3;
    // cout<<mp.size()<<endl;
    // map<string, int>::iterator it=mp.begin();
    // while(it!=mp.end()){
    //     cout<<"Key:"<<mp[it->first]--<<endl;
    //     cout<<"Value:"<<it->second<<endl;
    //     it++;
    // }
    // unique_ptr<int> p1{new int{100}};
    // cout<<*p1<<endl;
    // *p1=0;
    // cout<<p1.get()<<endl;
    // unique_ptr<Player> p2{new Player{"Kunal",100,16}};
    // unique_ptr<Player> p3{new Player{"Sanskar"}};
    // shared_ptr<int> p4{new int{200}};
    // cout<<*p4<<endl;
    // *p4=0;
    // cout<<p4.get()<<endl;
    // shared_ptr<int> p5{p4};
    // cout<<*p5<<endl;
    // p5.reset();
    // cout<<"Counting:"<<p4.use_count()<<endl;
    // shared_ptr<int> p7=make_shared<int>(100);
    // shared_ptr<int> p6;
    // p6=p7;
    // p6.reset();
    // cout<<"Counting:"<<p7.use_count()<<endl;
    // auto a=6;
    // auto b=9.876;
    // cout<<b<<" "<<typeid(b).name()<<endl;print.cpp

    // int arr[]{1,2,3,4,5,6,7};
    // vector<int> a{1,7,6,5,4,3,2};
    // for(auto b:a){
    //     cout<<b<<" ";
    // }

    // Player Kunal;
    // Player Hero{"Hero"};
    // Player Harsh{"Harsh",100};
    // Player Slayer{"Slayer",100,100};

    // int a=130;
    // int b=0;
    // try{
    //     if(b==0){
    //         throw 0;
    //     }
    //     cout<<a/b<<endl;
    // }
    // catch(int &x){
    //     cerr<<"Giving error";
    // }


    // try{
    //     int miles=120;
    //     int gallons=-10;
    //     cout<<mpg(miles,gallons)<<endl;
    // }
    // catch(int &ex){
    //     cerr<<"dividing by zero";
    // }
    // catch(string &ex){
    //     cerr<<ex<<endl;
    // }

    // try{
    //     func_a();
    // }
    // catch(int &ex){
    //     cerr<<"Giving error in main"<<endl;
    // }

    // [] () {
    //     cout<<"Hi";
    // }();

    // auto l=[] (int x) {
    //     cout<<x+10<<endl;
    // };
    // l(10);
    
    // auto l=[] (int x,int y){
    //     return x*y;
    // };

    // cout<<l(2,8)<<endl;

    
}
 