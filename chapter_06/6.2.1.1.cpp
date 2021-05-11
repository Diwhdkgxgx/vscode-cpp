#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Luggage;
class Passenger;
class Team;
class TicketOffice;
class Ticket;

enum TravelType
{
    Single,
    Team
};
enum Destination
{
    DomesticShort,
    DomesticLong,
    International
};

class Luggage
{
public:
    Luggage(string code = "") : code(code) {}

    void setLuggageCode(string code)
    {
        this->code = code;
    }

    string getLuggageCode()
    {
        return code;
    }

private:
    string code;
};

class Passenger
{
public:
    Passenger() {}

    Passenger(int travelTypeRand, int destinationRand, int luggageNumberRand)
    {
        string letter = "";
        if (count < 26)
        {
            letter += count + 'A'; // static_cast<char>(count + 'A');
        }
        else if (count < 52)
            letter += static_cast<char>(count - 26 + 'a');
        else if (count < 62)
            letter += static_cast<char>(count - 52 + '0');

        name = "乘客" + letter;
        travelType = static_cast<TravelType>(travelTypeRand % 2);
        destination = static_cast<Destination>(destinationRand % 3);
        luggageNum = luggageNumberRand % 4;

        for (int i = 0; i < luggageNum; i++)
        {
            char suffix = i + '1';
            luggages[i].setLuggageCode(letter + '0' + suffix);
        }

        count++;
    }

    Passenger(string name, TravelType travelType, Luggage luggages[], int luggageNum)
        : name(name), travelType(travelType), luggageNum(luggageNum)
    {
        for (int i = 0; i < luggageNum; i++)
            this->luggages[i] = luggages[i];

        count++;
    }

    void buyTicket(TicketOffice &office);
    Destination getDestination() { return destination; }

    TravelType getTravelType() { return travelType; }

    string getName() { return name; }

    int getLuggageNum() { return luggageNum; }

    Ticket *getTicket() { return ticket; }

    void setTicket(Ticket *ticket) { this->ticket = ticket; }

    void showInfo()
    {
        cout << "我是" << name << "，" << TRAVEL_TYPE_TEXT[travelType];
        cout << "，" << DESTINATION_TEXT[destination];
        cout << "，携带" << luggageNum << "件行李";

        if (luggageNum > 0)
        {
            cout << "，行李编号是";
            for (int i = 0; i < luggageNum; i++)
                cout << luggages[i].getLuggageCode() << "、";
            cout << "\b\b";
        }

        cout << "，买票需付" << FARE_TEXT[destination] << "。";

        if (destination == International && luggageNum > 2)
        {
            cout << "\b\b，行李托运费" << 100 * (luggageNum - 2) << "元。";
        }

        cout << endl;
    }

private:
    string getDestinationText()
    {
        return DESTINATION_TEXT[destination];
    }

    string getTravelTypeText()
    {
        return TRAVEL_TYPE_TEXT[travelType];
    }

    static const int MAX_LUGGAGE_NUM = 4;
    static int count;

    static const string TRAVEL_TYPE_TEXT[2];
    static const string DESTINATION_TEXT[3];
    static const string FARE_TEXT[3];
    static const int FARE[3];

    Luggage luggages[MAX_LUGGAGE_NUM];
    string name;
    TravelType travelType;
    Destination destination;
    int luggageNum;
    Ticket *ticket;
};

int Passenger::count = 0;
const string Passenger::TRAVEL_TYPE_TEXT[2] = {"选择自由出行", "报名旅行社"};
const string Passenger::DESTINATION_TEXT[3] = {"国内短途", "国内长途", "国际旅游"};
const string Passenger::FARE_TEXT[3] = {"1O元", "100元", "500元"};
const int Passenger::FARE[3] = {10, 100, 500};

class TravelTeam
{
public:
    TravelTeam(int destinationRand = 0) : count(0), teamFare(0)
    {
        destination = static_cast<Destination>(destinationRand % 3);
    }

    Destination getDestination() { return destination; }

    int getCount() { return count; }

    void setDestination(int destinationRand)
    {
        destination = static_cast<Destination>(destinationRand % 3);
    }

    bool addMember(Passenger &passenger)
    {
        if (count < MAX_PASSENGER_NUM)
        {
            passengers[count] = passenger;
            count++;
            return true;
        }
        else
            return false;
    }

    Passenger &getMember(int index)
    {
        return passengers[index];
    }

    bool isFull() { return count >= MAX_PASSENGER_NUM; }

    int getTeamFare() { return teamFare; }

    void setTeamFare(int teamFare) { this->teamFare = teamFare; }

private:
    static const int MAX_PASSENGER_NUM = 6;
    Destination destination;
    Passenger passengers[MAX_PASSENGER_NUM];
    int count;
    int teamFare;
};

class Ticket
{
public:
    void setTicket(Destination destination, double fare)
    {
        this->destination = destination;
        this->fare = fare;
    }

private:
    Destination destination;
    double fare;
};

class TravelAgency
{
public:
    TravelAgency(TravelTeam teams[], int size);
    bool registerMember(Passenger &passenger);
    void buyTicket(TicketOffice &office);
    void showInfo();

private:
    static const string DESTINATION_TYPE_TEXT[3];

    int teamNum;
    TravelTeam *teams;
};

const string TravelAgency::DESTINATION_TYPE_TEXT[3] = {"国内短途", "国内长途", "国际旅游"};

TravelAgency::TravelAgency(TravelTeam teams[], int size)
{
    teamNum = size;
    this->teams = teams;
}

bool TravelAgency::registerMember(Passenger &passenger)
{
    bool isSuccessful = false;

    for (int i = 0; i < teamNum; i++)
    {
        if (passenger.getDestination() == teams[i].getDestination())
        {
            if (!teams[i].isFull())
            {
                teams[i].addMember(passenger);
                isSuccessful = true;
                break;
            }
            else
                continue;
        }
    }

    return isSuccessful;
}

void TravelAgency::showInfo()
{
    int totalNum = 0;
    for (int i = 0; i < teamNum; i++)
    {
        totalNum += teams[i].getCount();
    }

    cout << "旅行社共计安排了5个旅行团，共计" << totalNum << "人报名。" << endl;
    cout << "出行的目的地分别是：";
    for (int i = 0; i < teamNum; i++)
    {
        cout << DESTINATION_TYPE_TEXT[teams[i].getDestination()] << "，";
    }
    cout << "\b\b；" << endl
         << "每个旅行团的人数分别是：";
    for (int i = 0; i < teamNum; i++)
    {
        cout << teams[i].getCount() << "，";
    }
    cout << "\b\b；" << endl
         << "每个旅行团需要支付的票价是：";
    for (int i = 0; i < teamNum; i++)
    {
        cout << teams[i].getTeamFare() << "，";
    }
    cout << "\b\b。" << endl;
}

class TicketOffice
{
public:
    TicketOffice(int ticketNum) : ticketNum(ticketNum), count(0), totalIncome(0)
    {
        tickets = new Ticket[ticketNum];
    }

    ~TicketOffice()
    {
        delete[] tickets;
    }

    void personalCharge(Passenger &passenger, int fare);
    int teamCharge(TravelTeam &team);
    void showInfo();

private:
    Ticket *tickets;
    int ticketNum;
    int count;
    double totalIncome;

    double personalIncome[3];
    double teamIncome[3];

    string personalPassengerNames[3];
    string teamPassengerNames[3];

    static const string DESTINATION_TYPE_TEXT[3];
    static const int FARE[3];
};

const string TicketOffice::DESTINATION_TYPE_TEXT[3] = {"国内短途", "国内长途", "国际旅游"};
const int TicketOffice::FARE[3] = {10, 100, 500};

void Passenger::buyTicket(TicketOffice &office)
{
    if (travelType == Single)
    {
        int fare = FARE[destination];
        if (destination == International && luggageNum > 2)
        {
            fare += 100 * (luggageNum - 2);
        }
        office.personalCharge(*this, fare);
    }
}

void TravelAgency::buyTicket(TicketOffice &office)
{
    for (int i = 0; i < teamNum; i++)
    {
        //int teamFare = FARE[teams[i].getDestination()] * teams[i].getCount();///
        int teamFare = office.teamCharge(teams[i]);
        teams[i].setTeamFare(teamFare);
    }
}

void TicketOffice::personalCharge(Passenger &passenger, int fare)
{
    Destination destination = passenger.getDestination();
    TravelType travelType = passenger.getTravelType();

    if (travelType == Single)
    {
        totalIncome += fare;

        personalIncome[destination] += fare;
        personalPassengerNames[destination] += passenger.getName() + "，";

        tickets[count].setTicket(destination, fare); // 为售票处的第count张票指定目的地、票价等信息
        passenger.setTicket(&tickets[count]);        // 把售票处的第count张票绑定到当前的乘客上

        count++;
    }
}

int TicketOffice::teamCharge(TravelTeam &team)
{
    Destination destination = team.getDestination();
    int baseFare = FARE[destination];

    int teamBaseFare = baseFare * team.getCount();
    int teamFare = teamBaseFare;
    teamIncome[destination] += teamBaseFare;
    totalIncome += teamBaseFare;

    for (int i = 0; i < team.getCount(); i++)
    {
        Passenger &passenger = team.getMember(i);
        int luggageFee = 0;

        teamPassengerNames[destination] += passenger.getName() + "，";
        if (destination == International && passenger.getLuggageNum() > 2)
        {
            luggageFee = 100 * (passenger.getLuggageNum() - 2);
            teamFare += luggageFee;
            teamIncome[destination] += luggageFee;
            totalIncome += luggageFee;
        }

        tickets[count].setTicket(destination, baseFare + luggageFee);
        passenger.setTicket(&tickets[count]);

        count++;
    }
    return teamFare;
}

void TicketOffice::showInfo()
{
    for (int i = 0; i < 3; i++)
    {
        cout << DESTINATION_TYPE_TEXT[i] << "自由行：" << setw(4) << personalIncome[i] << "元，乘客姓名：" << personalPassengerNames[i] << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << DESTINATION_TYPE_TEXT[i] << "团购：  " << setw(4) << teamIncome[i] << "元，乘客姓名：" << teamPassengerNames[i] << endl;
    }
    cout << "收入总计：" << totalIncome << "元。" << endl;
}

int main(int argc, char *argv[])
{
    const int MAX_PASSENGER_NUM = 62;
    const int MAX_TEAM_NUM = 5;

    srand(static_cast<unsigned>(time(NULL))); // 初始化随机数发生器
    int passengerNum = rand() % MAX_PASSENGER_NUM;
    cout << passengerNum << endl;

    Passenger **passengers = new Passenger *[passengerNum];
    for (int i = 0; i < passengerNum; i++)
    {
        int travelTypeRand = rand();
        int destinationRand = rand();
        int luggageNumberRand = rand();

        passengers[i] = new Passenger(travelTypeRand, destinationRand, luggageNumberRand);
        passengers[i]->showInfo();
    }

    cout << endl
         << "旅行社开始报名。" << endl;

    TravelTeam teams[MAX_TEAM_NUM];
    for (int i = 0; i < MAX_TEAM_NUM; i++)
    {
        teams[i].setDestination(rand());
    }
    TravelAgency agency(teams, MAX_TEAM_NUM);

    for (int i = 0; i < passengerNum; i++)
    {
        if (passengers[i]->getTravelType() == Team)
            agency.registerMember(*passengers[i]);
    }
    agency.showInfo();

    cout << endl
         << "售票处开始售票。" << endl;

    TicketOffice office(MAX_PASSENGER_NUM);

    for (int i = 0; i < passengerNum; i++)
        passengers[i]->buyTicket(office);

    agency.buyTicket(office);

    cout << "售票结束，营业额统计信息如下：" << endl;
    office.showInfo();

    for (int i = 0; i < passengerNum; i++)
        delete passengers[i];
    delete[] passengers;

    return 0;
}
