#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Automobile;
class Park;

class Park
{
private:
    float income;
    int park_num;
    int count;
    Automobile **spaces;

public:
    // Park() {}
    Park(int n);

    void offerPark(Automobile *cars);
    void showInfo();
    void leavePark(Automobile *cars, float price);
};

class Automobile
{
private:
    string car_number;

public:
    // Automobile() {}
    Automobile(string new_number);

    void enter(Park *park1);
    void leave(Park *park1); // 重写稍后
    string getCarNumber();
};


Park::Park(int n)
{
    spaces = new Automobile *[n];
    for (int i = 0; i < n; i++)
    {
        spaces[i] = NULL;
    }
    income = 0;
    count = 0;
    park_num = n;
}

void Park::offerPark(Automobile *cars)
{
    if (count >= park_num)
    {
        // cout << "车位已满，无法为" << car1->getCarNumber() << "分配停车位" << endl;
        cout << "车位已满，无法为" << (*cars).getCarNumber() << "分配停车位" << endl;
    }
    else
    {
        // 车位没满安排车位
        for (int i = 0; i < park_num; i++)
        {
            if (spaces[i] == NULL)
            {
                spaces[i] = cars;
                count++;
                cout << cars->getCarNumber() << "进入停车场，分配停车位" << endl;
                break;
            }
        }
    }
}
void Park::showInfo()
{
    cout << "停车场目前停放了" << count << "辆汽车";
    if (count == 0)
    {
        cout << "，";
    }
    else
    {
        cout << "：";
    }

    for (int i = 0; i < park_num; i++)
    {
        if (spaces[i] != NULL)
        {
            cout << spaces[i]->getCarNumber() << ",";
        }
    }
    cout << "共收入" << income << "元停车费" << endl;
}
void Park::leavePark(Automobile *cars, float price)
{
    // 计算收入
    income += price;
    for (int i = 0; i < park_num; i++)
    {
        if (spaces[i] == cars)
        {
            spaces[i] = NULL;
            cout << cars->getCarNumber() << "离开停车场，缴纳停车费" << price << "元" << endl;
            count--;
        }
    }
}


Automobile::Automobile(string new_number)
{
    car_number = new_number;
}
void Automobile::enter(Park *park1)
{
    park1->offerPark(this);
}
void Automobile::leave(Park *park1)
{

}
string Automobile::getCarNumber()
{
    return car_number;
}

// 在设计派生类时，对继承过来的成员变量的初始化工作也要由派生类的构造函数完成，
// 但是大部分基类都有 private 属性的成员变量，它们在派生类中无法访问，更不能使用派生类的构造函数来初始化。
// 这种矛盾在C++继承中是普遍存在的，解决这个问题的思路是：在派生类的构造函数中调用基类的构造函数。
class Truck : public Automobile
{
private:
    float weight;

public:
    // Truck();
    Truck(string new_num, float new_weight);
    void leave(Park *park1);
};

// Truck::Truck() : weight(0) {}
Truck::Truck(string new_num, float new_weight) : Automobile(new_num), weight(new_weight) {}
void Truck::leave(Park *park1)
{
    park1->leavePark(this, 3);
}

class Car : public Automobile
{
private:
    string brand;

public:
    // Car();
    Car(string new_num, string new_brand);
    void leave(Park *park1);
};

// Car::Car() : brand("unknow") {}
Car::Car(string new_num, string new_brand) : Automobile(new_num), brand(new_brand) {}
void Car::leave(Park *park1)
{
    park1->leavePark(this, 1);
}
class Bus : public Automobile
{
private:
    int carry_num;

public:
    // Bus();
    Bus(string new_num, int new_carry);
    void leave(Park *park1);
};

// Bus::Bus() : carry_num(0) {}
Bus::Bus(string new_num, int new_carry) : Automobile(new_num), carry_num(new_carry) {}
void Bus::leave(Park *park1)
{
    park1->leavePark(this, 2);
}


int main()
{
    int N = 0;
    cout << "请输入停车位数量：";
    cin >> N; // 输入停车位数量，此处输入2

    Park *park = new Park(N); // 创建一个停车场对象

    Car car1("鲁B-12345", "奥迪A6"); // 创建轿车对象
    car1.enter(park);                // car1进入停车场，分配停车位

    Truck truck("鲁B-23456", 15); // 创建卡车对象
    truck.enter(park);            // truck进入停车场，分配车位

    car1.leave(park); // car1离开停车场，缴纳停车费

    Bus bus("鲁B-34567", 50); // 创建公交车对象
    bus.enter(park);          // bus进入停车场，分配车位

    /* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park->showInfo();

    Car car2("鲁B-45678", "宝马320"); // 创建轿车对象
    car2.enter(park);
    // car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配

    bus.leave(park);   // bus离开停车场，缴纳停车费
    truck.leave(park); // truck离开停车场，缴纳停车费

    /* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park->showInfo();
    delete park;

    return 0;
}
