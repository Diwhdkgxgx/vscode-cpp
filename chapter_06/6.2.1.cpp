// -----程序设计基本思路-----
// 1.随机生成n个游客，并随机生成每个游客的目的地、是否跟团、行李数量
// 2.固定生成5个旅行团，但随机生成每个团的目的地
// 3.将有跟团意愿的游客按照相同的目的地分配进旅行团
// 4.如果没有与该游客目的地一样的旅行团，或者有相同目的地的团但是已经满人了，将这些游客设置为自由行
// 5.输出

#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int i;

// 目的地：枚举类型
enum Destination
{
    DomesticShort,
    DomesticLong,
    International
};

// 各类汇总
class Luggage;
class Passenger;
class freeman;
class Team;
class TravelAgent;
class Ticket;
class TicketOffice;

// 行李类
class Luggage
{
private:
    string name;

public:
    // TODO: 默认构造函数
    Luggage(){}
    Luggage(string Lug_name);
    
    string getLuggageName();
};

Luggage::Luggage(string Lug_name)
{
    name = Lug_name;
}
string Luggage::getLuggageName()
{
    return name;
}

// 乘客类
class Passenger // 姓名，行李个数
{
private:
    string name;
    int trip_way; // 0跟团， 1自由行
    double pay_ticket;
    double pay_luggage;
    double pay_all;
    int destination; // 0本地短途 1本地长途 2国外长途
    int luggage_num;
    Luggage luggages[3];
    int isInTeam;

public:
    // Passenger(){}
    // Passenger(string new_name, int lug_num);
    Passenger();

    void setName(string new_name);
    void setLuggageNum(int num);
    string getPassengerName();
    void changeTripWay(int way); //更换旅行方式
    int getTripWay(); // 获取旅行方式
    
    void calculateTicket(double ticket_fee); // 计算票价
    void calculateLuggage(double luggage_fee); // 计算行李钱
    void calculateAllCost(); // 计算总花费
    double getTicketCost(); // 获得票钱
    double getLuggageCost(); // 获得行李钱
    double getAllCost(); // 获得总花费

    int getLuggageNum(); // 获得行李数
    Luggage getLuggage(int n); // 获取单个行李

    void changeDestination(int d); // 更换目的地
    int getDestination(); // 获取目的地

    void setInTeam();
    int getInteam();
};

Passenger::Passenger() 
{
    name = "haha";
    luggage_num = 0;
    isInTeam = 0;

    // 将生成对应的行李，并放入行李数组
    for ( i = 0; i < luggage_num; i++)
    {
        string a;
        std::string s = std::to_string(i + 1); // c++int string类型转换
        a = name + "0" + s;
        
        Luggage new_Luggages(a);
        luggages[i] = new_Luggages;
    }

    trip_way = 1;// 默认自由行
    pay_ticket = 0;
    pay_luggage = 0;
    destination = 0; // 默认短途
}
void Passenger::setName(string new_name)
{
    name = new_name;
}
void Passenger::setLuggageNum(int num)
{
    // 将生成对应的行李，并放入行李数组
    for ( i = 0; i < num; i++)
    {
        string a;
        std::string s = std::to_string(i + 1); // c++int string类型转换
        a = name + "0" + s;
        
        Luggage new_Luggages(a);
        luggages[i] = new_Luggages;
    }
    luggage_num = num;
}
string Passenger::getPassengerName()
{
    return name;
}
void Passenger::changeTripWay(int way)
{
    trip_way = way;
}
int Passenger::getTripWay()
{
    return trip_way;
}
void Passenger::calculateTicket(double ticket_fee)
{
    pay_ticket = ticket_fee;
}
void Passenger::calculateLuggage(double luggage_fee)
{
    pay_luggage = luggage_fee;
}
void Passenger::calculateAllCost()
{
    pay_all = pay_ticket + pay_luggage;
}
double Passenger::getTicketCost()
{
    return pay_ticket;
}
double Passenger::getLuggageCost()
{
    return pay_luggage;
}
double Passenger::getAllCost()
{
    return pay_all;
}
int Passenger::getLuggageNum()
{
    return luggage_num;
}
Luggage Passenger::getLuggage(int n)
{
    return luggages[n];
}
void Passenger::changeDestination(int d)
{
    destination = d;
}
int Passenger::getDestination()
{
    return destination;
}
void Passenger::setInTeam()
{
    isInTeam = 1;
}
int Passenger::getInteam()
{
    return isInTeam;
}

// 自由行人类
class freeman
{
private:
    int freeman_num;
    Passenger free_passengers[62];

public:
    freeman(){}
    freeman(Passenger new_freeman);
    void addFreeman(Passenger new_freeman);
    double getFreemanNum();
    Passenger getFreeman(int n);
};

freeman::freeman(Passenger new_freeman)
{
    freeman_num = 0;
    free_passengers[freeman_num] = new_freeman;
}
void freeman::addFreeman(Passenger new_freeman)
{
    freeman_num++;
    free_passengers[freeman_num] = new_freeman;
}
double freeman::getFreemanNum()
{
    return freeman_num;
}
Passenger freeman::getFreeman(int n )
{
    return free_passengers[n];
}

// 旅行团类
class Team
{
private:
    int name;
    int destination;
    double all_cost;
    int passenger_num;
    Passenger passengers[6];

public:
    // Team(){}
    Team();

    void setPassenger(Passenger p);
    void setDestination(int new_destination);
    void addPassenger(Passenger p);
    int getDestination();
    void caculateAllCost();
    double getAllCost();
    int getPassengerNum();
    Passenger getPassengers(int n); // TODO:不确定是否可行
};

Team::Team()
{
    name = 0;
    destination = 0;
    passenger_num = 0;
    all_cost = 0;
}
void Team::setPassenger(Passenger p)
{
    passengers[passenger_num] = p;
    passenger_num++;
}
void Team::setDestination(int new_destination)
{
    destination = new_destination;
}
void Team::addPassenger(Passenger p)
{
    passengers[passenger_num - 1] = p;
    passenger_num++;
}
int Team::getDestination()
{
    return destination;
}
void Team::caculateAllCost()
{
    for ( i = 0; i < passenger_num; i++)
    {
        all_cost += (passengers[i].getTicketCost() + passengers[i].getLuggageCost());
    }
}
double Team::getAllCost()
{
    return all_cost;
}
int Team::getPassengerNum()
{
    return passenger_num;
}
Passenger Team::getPassengers(int n)
{
    return passengers[n];
}

// 旅行社类
class TravelAgency
{
private:
    Team Teams[5];
    int team_num;

public:
    TravelAgency(){}
    TravelAgency(Team new_team);
    void addNewTeam(Team new_team);
    Team getTeam(int n);
};

TravelAgency::TravelAgency(Team new_team)
{
    team_num = 0;
    Teams[team_num] = new_team;
}
void TravelAgency::addNewTeam(Team new_team)
{
    team_num++;
    Teams[team_num] = new_team;
}
Team TravelAgency::getTeam(int n)
{
    return Teams[n];
}

// 票类
class Ticket
{
private:
    double home_short_trip_ticket;
    double home_long_journey_ticket;
    double abroad_long_journey_ticket;
    double luggage_fee;

public:
    Ticket();
    // double getHomeShortFee();
    // double getHomeLongFee();
    // double getAbroadLongFee();
    double getLuggageFee(int destination, int lug_num);
    double getTicketFee(int destination);
};

Ticket::Ticket()
{
    home_short_trip_ticket = 10;
    home_long_journey_ticket = 100;
    abroad_long_journey_ticket = 500;
    luggage_fee = 100;
}
// double Ticket::getHomeShortFee()
// {
//     return home_short_trip_ticket;
// }
// double Ticket::getHomeLongFee()
// {
//     return home_long_journey_ticket;
// }
// double Ticket::getAbroadLongFee()
// {
//     return abroad_long_journey_ticket;
// }
double Ticket::getLuggageFee(int destination, int lug_num)
{
    if (destination == 2 && lug_num > 2)
    {
        return (lug_num - 2) * luggage_fee;
    }
    else
    {
        return 0;
    }
}
double Ticket::getTicketFee(int destination)
{
    if (destination == 0)
    {
        return home_short_trip_ticket;
    }
    else if (destination == 1)
    {
        return home_long_journey_ticket;
    }
    else if (destination == 2)
    {
        return abroad_long_journey_ticket;
    }
    else
    {
        return 0;
    }
}

// 售票处类
class TicketOffice
{
private:
    // TODO: 完成售票处类，考虑是否与添加游客类数组
    double home_short_free_turnover;
    double home_long_free_turnover;
    double abroad_free_turnover;
    double home_short_team_turnover;
    double home_long_team_turnover;
    double abroad_team_turnover;

public:
    TicketOffice();
    void caculateHomeShortFree(double cost);
    void caculateHomeLongFree(double cost);
    void caculateAbroadFree(double cost);
    void caculateHomeShortTeam(double cost);
    void caculateHomeLongTeam(double cost);
    void caculateAbroadTeam(double cost);

    double getHomeShortFree();
    double getHomeLongFree();
    double getAbroadFree();
    double getHomeShortTeam();
    double getHomeLongTeam();
    double getAbroadTeam();
    
};

TicketOffice::TicketOffice()
{
    home_short_free_turnover = 0;
    home_long_free_turnover = 0;
    abroad_free_turnover = 0;
    home_short_team_turnover = 0;
    home_long_team_turnover = 0;
    abroad_team_turnover = 0;
}

void TicketOffice::caculateHomeShortFree(double cost)
{
    home_short_free_turnover += cost;
}
void TicketOffice::caculateHomeLongFree(double cost)
{
    home_long_free_turnover += cost;
}
void TicketOffice::caculateAbroadFree(double cost)
{
    abroad_free_turnover += cost;
}
void TicketOffice::caculateHomeShortTeam(double cost)
{
    home_short_team_turnover += cost;
}
void TicketOffice::caculateHomeLongTeam(double cost)
{
    home_long_team_turnover += cost;
}
void TicketOffice::caculateAbroadTeam(double cost)
{
    abroad_team_turnover += cost;
}

double TicketOffice::getHomeShortFree()
{
    return home_short_free_turnover;
}
double TicketOffice::getHomeLongFree()
{
    return home_long_free_turnover;
}
double TicketOffice::getAbroadFree()
{
    return abroad_free_turnover;
}
double TicketOffice::getHomeShortTeam()
{
    return home_short_team_turnover;
}
double TicketOffice::getHomeLongTeam()
{
    return home_long_team_turnover;
}
double TicketOffice::getAbroadTeam()
{
    return abroad_team_turnover;
}

// 随机数生成函数
int ramdon(int max)
{
    int a;
    // srand(time(NULL));
    srand(static_cast<unsigned>(time(NULL)));
    a = rand() % max; // max = 3   0 1 2
    return a;
}

// 62个姓名生成函数a-z A-Z 0-9
void nameBrith(string names[], int k)
{
    srand(static_cast<unsigned>(time(NULL)));
    
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        names[i] = ch;
        i++;
        k = i;
    }
    for ( char ch = 'a'; ch <= 'z'; ch++)
    {
        names[k] = ch;
        i++;
        k = i;
    }
    for ( char ch = '0'; ch <= '9'; ch++)
    {
        names[k] = ch;
        i++;
        k = i;
    }
}

// passenger_num个旅客生成函数 
void passengerBirth(Passenger passengers[], int passengers_num, string names[], int names_num, Ticket tickets)
{
    //生成游客 需要姓名和行李数
    int ii, jj, j;
    int A[100]; // 记录是否重复
    // 生成名字不同的passenger_num个乘客 和 随机个行李
    for (ii = 0; ii < passengers_num; ii++)
    {
        A[ii] = rand()%names_num;
        // A[ii] = 1;
        passengers[ii].setName(names[A[ii]]); // 生成不重复的名字
        passengers[ii].setLuggageNum(rand()%3 + 1); //生成随机行李个数
        passengers[ii].changeTripWay(rand()%2); // 生成跟团还是自由行
        passengers[ii].changeDestination(rand()%3); // 生成目的地
        passengers[ii].calculateTicket(tickets.getTicketFee(passengers[ii].getDestination())); //计算该游客的票价
        passengers[ii].calculateLuggage(tickets.getLuggageFee(passengers[ii].getDestination(), passengers[ii].getLuggageNum())); // 计算该游客的行李钱
        passengers[ii].calculateAllCost(); // 计算该游客的所有花费
        for (jj = 0; jj < ii; jj++)
        {
            if (A[ii] == A[jj])
            {
                ii--;
                break;
            }
        }
    }
}

// 旅行团目的地随机生成 与 游客分配 并 算每个旅行团的花费 函数
void passengerInTeams(Passenger passengers[], Team Teams[], TicketOffice *ticketoffice01, int passengers_num, int *gftrnum)
{
    // 确定自由行还是旅行团 旅行团必须有5个，每个最多6人。
    int t = 0;
    // 先随机为5个团分别设置目的地。
    // 并记录每个目的地有几个团。储存在 d0 d1 d2
    int d0 = 0, d1 = 0, d2 = 0; // 记录有几个团
    int copy_d0 = 0, copy_d1 = 0, copy_d2 = 0; // 记录有几个团

    int des0[5] = {0}, des1[5] = {0}, des2[5] = {0}; // 存储团队序号
    int t0 = 0, t1 = 0, t2 = 0; // 记录该目的地团是第几位
    int a;
    for (i = 0; i < 5; i++)
    {
        a = rand() % 3;
        if ( a == 0)
        {
            d0++;
            copy_d0 = d0;
            des0[t0] = i;
            t0++;
        }
        else if ( a == 1)
        {
            d1++;
            copy_d1 = d1;
            des1[t1] = i;
            t1++;
        }
        else if ( a == 2)
        {
            d2++; // 1 2 3  // d2 和 t2差1
            copy_d2 = d2;
            des2[t2] = i; // 1 3
            t2++; // 0 1 2
        }
        // 设置团队目的地
        Teams[i].setDestination(a);
    }
    

    // TODO: 添加判断之前的团人数是否已满，若不是可以加入之前的团队。
    // 1.目的地一致 2.团没有满人就加进去 3如果团满人了就加入目的地相同的另一个团，若没有目的地相同的团了就不加入。

    for ( i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getTripWay() == 0 && passengers[i].getInteam() == 0)  // 判断是否跟团游和是否已经成团
        {
            if ( passengers[i].getDestination() == 0) // 分目的地情况
            {
                if (d0 != 0) // 如果该目的地有团，按顺序加入某一团
                {
                    (*gftrnum)++; // 跟团人数增加  （*gftrnum）++ 才代表指针所指的数字加一
                    Teams[des0[copy_d0 - t0]].setPassenger(passengers[i]); // 把旅客加进这个团
                    passengers[i].setInTeam(); // 设置该旅客已成团
                    (*ticketoffice01).caculateHomeShortTeam(passengers[i].getAllCost()); // 把跟团游客的花费加入售票处
                    
                    if (Teams[des0[copy_d0 - t0]].getPassengerNum() == 6 ) //该团已经满人，换到下一个团
                    {
                        d0--; // 0目的地团数量减去1
                        t0--; // 储存位置的也减去 1
                    }
                }
                else if (d0 == 0) // 如果已经没有与该游客目的地相同的团，则将游客设置为自由行“1”
                {
                    passengers[i].changeTripWay(1);
                }
            }

            else if ( passengers[i].getDestination() == 1) // 分目的地情况
            {
                if (d1 != 0) // 如果该目的地有团，按顺序加入某一团
                {
                    (*gftrnum)++; // 跟团人数增加
                    Teams[des1[copy_d1 - t1]].setPassenger(passengers[i]); // 把旅客加进这个团
                    passengers[i].setInTeam(); // 设置该旅客已成团

                    (*ticketoffice01).caculateHomeLongTeam(passengers[i].getAllCost());
                    if (Teams[des1[copy_d1 - t1]].getPassengerNum() == 6) //该团已经满人，换到下一个团
                    {
                        d1--; // 0目的地团数量减去1
                        t1--; // 储存位置的也减去 1
                    }
                }
                else if (d1 == 0) // 如果已经没有与该游客目的地相同的团，则将游客设置为自由行“1”
                {
                    passengers[i].changeTripWay(1);
                }
            }
            
            else if ( passengers[i].getDestination() == 2) // 分目的地情况
            {
                if (d2 != 0) // 如果该目的地有团，按顺序加入某一团
                {
                    (*gftrnum)++; // 跟团人数增加
                    Teams[des2[copy_d2 - t2]].setPassenger(passengers[i]); // 把旅客加进这个团
                    passengers[i].setInTeam(); // 设置该旅客已成团
                    (*ticketoffice01).caculateAbroadTeam(passengers[i].getAllCost());

                    if (Teams[des2[copy_d2 - t2]].getPassengerNum() == 6 ) //该团已经满人，换到下一个团
                    {
                        d2--; // 2目的地团数量减去1
                        t2--; // 储存位置的也减去 1
                    }
                }
                else if (d2 == 0) // 如果已经没有与该游客目的地相同的团，则将游客设置为自由行“1”
                {
                    passengers[i].changeTripWay(1);
                }
            }
            
        }
        else 
        {
            if (passengers[i].getDestination() == 0)
            {
                (*ticketoffice01).caculateHomeShortFree(passengers[i].getAllCost());
            }
            else if (passengers[i].getDestination() == 1)
            {
                (*ticketoffice01).caculateHomeLongFree(passengers[i].getAllCost());
            }
            else if (passengers[i].getDestination() == 2)
            {
                (*ticketoffice01).caculateAbroadFree(passengers[i].getAllCost());
            }
        }
    }
}

// 输出旅客自述函数
void passengersSay(Passenger passengers[], int num)
{
    for ( i = 0; i < num; i++)
    {
        // 输出姓名
        cout << "我是乘客" << passengers[i].getPassengerName() << "，";
        // 输出旅行方式
        if (passengers[i].getTripWay() == 1)
        {
            cout << "选择自由行，";
        }
        else
        {
            cout << "报名旅行社，";
        }

        // 输出目的地
        if (passengers[i].getDestination() == 0)
        {
            cout << "国内短途，";
        }
        else if (passengers[i].getDestination() == 1)
        {
            cout << "国内长途，";
        }
        else if (passengers[i].getDestination() == 2)
        {
            cout << "国际游，  ";
        }
        // 输出行李编号
        int j;
        if (passengers[i].getLuggageNum() == 0)
        {
            cout << "不携带行李，";
        }
        else 
        {
            cout << "行李编号是";
            for (j = 0; j < passengers[i].getLuggageNum(); j++)
            {
                cout << passengers[i].getLuggage(j).getLuggageName();
                cout << "、";
            }
        }
        // 输出票价
        cout << "买票需要付"<< passengers[i].getTicketCost() << "元";
        // 输出行李托运费
        if (passengers[i].getLuggageCost() == 0)
        {
            cout << "。" << endl;
        }
        else 
        {
            cout << "，行李托运费" << passengers[i].getLuggageCost() << "元。" << endl;
        }

    }
}

// 旅行社报名输出函数
void travelAgentSale(Team Teams[], int gftrnum)
{
    
    // int team_num = 0;
    cout << "旅行社开始报名。" << endl;

    // for ( i = 0; i < 5; i++)
    // {
    //     if( Teams[i].getPassengerNum() != 0 )
    //     {
    //         team_num++;
    //     }
    // }

    cout << "旅行社共计安排了" << 5 << "个旅行团，" << "共计" << gftrnum << "人报名。" << endl;

    cout << "出行的目的地分别是：";
    
    
    int count = 0;
    for (i = 0; i < 5; i++)
    {   
        // 输出目的地
        if (Teams[i].getDestination() == 0)
        {
            cout << "国内短途，";
        }
        else if ( Teams[i].getDestination() == 1)
        {
            cout << "国内长途，";
        }
        else if (Teams[i].getDestination() == 2)
        {
            cout << "国际游，";
        }
    }
    cout << endl;

    cout << "每个旅游团的人数分别是：";
    for ( i = 0; i < 5; i++)
    {
        cout << Teams[i].getPassengerNum() << ",";
    }
    cout << endl;

    int ii;
    cout << "每个旅行团需支付的票价分别是：";
    for ( ii = 0; ii < 5; ii++)
    {
        Teams[ii].caculateAllCost();
        cout << Teams[ii].getAllCost() << "元, ";
    }
    cout << endl;
    

}

// 售票处售票输出函数
void ticketOfficeSale(Passenger passengers[], TicketOffice ticketoffice01, int passengers_num)
{
    // 输出售票处
    cout << "售票处开始售票" << endl;
    cout << "售票结束，营业额统计信息如下：" << endl;

    cout << "国内短途自由行" << ticketoffice01.getHomeShortFree() << "元，乘客姓名：";
         for ( i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getDestination() == 0 && passengers[i].getTripWay() == 1)
        {
            cout << "乘客" << passengers[i].getPassengerName() << " ";
        }
    }
    cout << endl;

    cout << "国内长途自由行" << ticketoffice01.getHomeLongFree() << "元，乘客姓名：";
    for (i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getDestination() == 1 && passengers[i].getTripWay() == 1)
        {
            cout << "乘客" << passengers[i].getPassengerName() << " ";
        }
    }
    cout << endl;

    cout << "国际游自由行" << ticketoffice01.getAbroadFree() << "元，乘客姓名：";
         for ( i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getDestination() == 2 && passengers[i].getTripWay() == 1)
        {
            cout << "乘客" << passengers[i].getPassengerName() << " ";
        }
    }
    cout << endl;

    cout << "国内短途团购" << ticketoffice01.getHomeShortTeam()<< "元，乘客姓名：";
         for ( i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getDestination() == 0 && passengers[i].getTripWay() == 0)
        {
            cout << "乘客" << passengers[i].getPassengerName() << " ";
        }
    }
    cout << endl;
    cout << "国内长途团购" << ticketoffice01.getHomeLongTeam() << "元，乘客姓名：";
         for ( i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getDestination() == 1 && passengers[i].getTripWay() == 0)
        {
            cout << "乘客" << passengers[i].getPassengerName() << " ";
        }
    }
    cout << endl;
    cout << "国际游团购" << ticketoffice01.getAbroadTeam() << "元，乘客姓名：";
         for ( i = 0; i < passengers_num; i++)
    {
        if (passengers[i].getDestination() == 2 && passengers[i].getTripWay()== 0)
        {
            cout << "乘客" << passengers[i].getPassengerName() << " ";
        }
    }
    cout << endl;
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    i = 0;
    int ii, jj, j;
    Ticket tickets;
    TicketOffice ticketoffice01;
    
    // 生成名字数组
    string names[100];
    int names_num = 62;
    nameBrith(names, names_num);

    // 生成passener_num个游客
    Passenger passengers[100];
    int passengers_num;
    passengers_num = (1 + ramdon(62)); // 随机一共有多少个旅客
    // passengers_num = 10; 
    passengerBirth(passengers, passengers_num, names, names_num, tickets);

    // 测试是否准确
    // passengersSay(passengers, passengers_num);
    // cout << "---------------------" << endl;
    
    // 生成5个旅行团
    Team Teams[5];
    int ziyznum = 0;  // 自由行游客数量
    int gftrnum = 0; // 跟团游客数量
    int team_num = 0; // 旅行团数量

    // 随机确定5个旅行团位置，并将游客送入每个团。
    passengerInTeams(passengers, Teams, &ticketoffice01, passengers_num, &gftrnum);  // 注意这里类和整型数字要用指针传递

    // ------------开始输出---------- //
    // 乘客自述
    passengersSay(passengers, passengers_num);
    cout << "一共有" << passengers_num << "名游客" << endl;
    cout << endl;

    // 旅行社报名
    travelAgentSale(Teams, gftrnum);
    cout << endl;

    // 售票处售票
    ticketOfficeSale(passengers, ticketoffice01, passengers_num);
    cout << endl;
    return 0;
}