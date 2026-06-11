#include <iostream>
#include <vector>
#include <unordered_map>
#include <typeinfo>
using namespace std;

class Animal
{
public:
    virtual void speak() = 0;
    virtual int getFood() = 0;
    virtual ~Animal(){}
};

class Dog : public Animal
{
public:
    void speak() override { cout<<"Woof\n"; }
    int getFood() override { return 5; }
};

class Cat : public Animal
{
public:
    void speak() override { cout<<"Meow\n"; }
    int getFood() override { return 3; }
};

class Cow : public Animal
{
public:
    void speak() override { cout<<"Moo\n"; }
    int getFood() override { return 10; }
};

class Sheep : public Animal
{
public:
    void speak() override { cout<<"Baa\n"; }
    int getFood() override { return 7; }
};

int main()
{
    int n;
    cin>>n;

    vector<Animal*> zoo;
    unordered_map<string,int> cnt;

    long long totalFood=0;

    while(n--)
    {
        string op;
        cin>>op;

        if(op=="ADD")
        {
            string type;
            cin>>type;

            Animal* p=nullptr;

            if(type=="Dog") p=new Dog();
            else if(type=="Cat") p=new Cat();
            else if(type=="Cow") p=new Cow();
            else if(type=="Sheep") p=new Sheep();

            zoo.push_back(p);

            cnt[type]++;

            totalFood+=p->getFood();
        }
        else if(op=="COUNT")
        {
            string type;
            cin>>type;

            cout<<cnt[type]<<'\n';
        }
        else if(op=="FEED")
        {
            cout<<totalFood<<'\n';
        }
        else if(op=="SPEAK")
        {
            for(auto p:zoo)
                p->speak();
        }
        else if(op=="TYPECHECK")
        {
            int dog=0,cat=0,cow=0,sheep=0;

            for(auto p:zoo)
            {
                if(dynamic_cast<Dog*>(p)) dog++;
                else if(dynamic_cast<Cat*>(p)) cat++;
                else if(dynamic_cast<Cow*>(p)) cow++;
                else if(dynamic_cast<Sheep*>(p)) sheep++;
            }

            cout<<"Dog:"<<dog<<'\n';
            cout<<"Cat:"<<cat<<'\n';
            cout<<"Cow:"<<cow<<'\n';
            cout<<"Sheep:"<<sheep<<'\n';
        }
        else if(op=="EXIT")
        {
            break;
        }
    }

    for(auto p:zoo)
        delete p;

    return 0;
}
