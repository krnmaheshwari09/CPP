#include<iostream>
using namespace std;

class student {
    private:
    string name;
    int age;
    int height;

    public:
    string getname(){
        return name;
    }
    void setname(string name){
        this->name = name;
    }
    int getage(){
        return age;
    }
    void setage(int age){
        this->age = age;
    }
    int getheight(){
        return height;
    }
    void setheight(int height){
        this->height = height;
    }
};
int main()
{
    student first;
    first.setname("Karan");
    first.setage(19);
    first.setheight(171);
    cout<<first.getname()<<" "<<first.getage()<<" "<<first.getheight()<<endl;
}