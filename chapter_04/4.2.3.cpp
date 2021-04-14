#include <iomanip>
#include <iostream>
using namespace std;
int i;

class Commodity
{
private:
    string name;
    double price;
    double num;

public:
    Commodity(){} // key_point：默认构造函数的创建
    Commodity(string name, double price, double num);

    string getName();
    double getPrice();
    double getNum();

    void printInfo();
};

Commodity::Commodity(string name, double price, double num): 
    name(name), price(price), num(num){}

string Commodity::getName()
{
    return name;
}
double Commodity::getPrice()
{
    return price;
}   
double Commodity::getNum()
{
    return num;
}

void Commodity::printInfo()
{
    cout << std::left << setw(15) << this->name << " ";
    cout << std::right << setw(5) << this->price << " ";
    cout << std::right << setw(4) << this->num << endl;
}


class Cart
{ 
public:
    Cart(Commodity ite[]);
    void addItem(Commodity iterm);
    void checkout();
    void printInvoice();

private:
    Commodity iterms[20];
    int n;
};

Cart::Cart(Commodity it[])
{
    n = 0;
    for (i = 0; i < 20; i++)
    {
        iterms[i] = it[i];
    }
}

void Cart::addItem(Commodity iterm)
{
    iterms[n] = iterm;
    n++;
}

void Cart::checkout()
{
    double all_price = 0;
    for (i = 0; i < n; i++)
    {
        all_price += iterms[i].getPrice() * iterms[i].getNum();
    }

    cout << "您需要支付" << all_price << "元" << endl;
}

void Cart::printInvoice()
{
    cout << std::left << setw(20) << "名称 ";
    cout << std::right << setw(5) << "金额 ";
    cout << std::right << setw(3) <<"数量"<< endl;
    for ( i = 0; i < n; i++)
    {
        iterms[i].printInfo();
    }
}

int main()
{
    Commodity tShirt("Tshirt", 79, 2);      // 创建服装对象，名称、价格、数量
    Commodity suit("suit", 1099, 1);        // 套装
    Commodity hat("hat", 129, 3);           // 帽子
    Commodity tv("tv set", 4899, 1);        // 创建家电对象，名称、价格、数量
    Commodity ac("air condition", 5280, 1); // 空调

    // Commodity ite[2]={Commodity("null", 0,0), Commodity("null", 0,0)};
    Commodity ite[20];

    Cart myCart(ite);
    // 将商品添加到购物车
    myCart.addItem(tShirt);
    myCart.addItem(suit);
    myCart.addItem(hat);
    myCart.addItem(tv);
    myCart.addItem(ac);

    myCart.checkout();     // 购物车商品结算，显示顾客需要支付的总金额
    myCart.printInvoice(); // 将购物清单输出到显示器上

    return 0;
}