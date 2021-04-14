#include <iomanip>
#include <iostream>
using namespace std;
int i;

class CD
{
public:
    CD(string name, string songs[]);
    string getSinger();        // 获得歌手的名称
    string getSong(int index); // 获得某首歌的歌名
    void listSongs();          // 列出CD的内容

    // CD(CD &cd);

private:
    string singer;   // 歌手的名字。
    string songs[6]; // 每张专辑6首歌的名字。
};

CD::CD(string name, string son[])
{
    singer = name;
    for ( i = 0; i < 6; i++)
    {
        songs[i] = son[i];
    }
}

string CD::getSinger()
{
    return singer;
}

string CD::getSong(int index)
{
    return songs[index];
}

void CD::listSongs()
{
    cout << "Singer:" << singer << endl;
    for ( i = 0; i < 6; i++)
    {
        cout << i + 1 << "." << songs[i] << endl;
    }
}

// CD::CD(CD &cd)
// {
//     singer = cd.singer;
//     for ( i = 0; i < 6; i++)
//     {
//         songs[i] = cd.songs[i];
//     }
// }

class CDPlayer
{
public:
    CDPlayer();

    void showMenu();

    /*插入CD. void insertCD(CD* cd)，形参是指向CD对象的指针。如果CDPlayer中已经有CD，提示先取出CD；如果CDPlayer中没有CD，显示插入了哪位歌星的CD。*/
    void insertCD(CD *cd);

    /*弹出CD. CD *ejectCD()，返回值是指向该CD对象的指针。如果CDPlayer中已经有CD，显示弹出了哪位歌星的CD，返回该CD的指针；如果CDPlayer中没有CD，提示CDPlayer中没有CD，返回NULL。*/
    CD *ejectCD();
    
    /*播放CD。如果CDPlayer中已经有CD，显示正在播放哪位歌星的CD，并打印CD中歌曲的清单；如果CDPlayer中没有CD，显示CDPlayer中没有CD，并提示用户插入CD。*/
    void play();

private:
    /* 插入CDPlayer中的CD，它是指向CD对象的指针。
    没有CD时，为null。使用指针，很好地模拟 了CD对象不是播放器的一部分，播放器只是读取放入其中的CD的内容。*/
    CD *cd;
    bool cdIn; // CDPlayer中是否已经插入CD
};

CDPlayer::CDPlayer()
{
    cd = NULL;
    cdIn = 0;
}

void CDPlayer::showMenu()
{
    cout << "*********************************" << endl;
    cout << "*  1.播放CD                     *" << endl;
    cout << "*  2.插入CD                     *" << endl;
    cout << "*  3.弹出CD                     *" << endl;
    cout << "*  0.关机                       *" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

void CDPlayer::insertCD(CD *cd)
{
    if (cdIn == 1)
    {
        cout << "请先取出CD！" << endl;
    }
    else
    {
        cout << "插入了" << cd->getSinger() << "的CD......" << endl;
        this->cd = cd;  // 注意要让CDPlayer的指针对象 也指向传入的cd指针
        cd->listSongs();
        cdIn = 1;
    }
}

CD* CDPlayer::ejectCD()
{
    if (cdIn == 1)
    {
        cout << "弹出了" << cd->getSinger() << "的CD......" << endl;
        cdIn = 0;
        return cd;
    }
    else
    {
        return NULL;
    }
}

void CDPlayer::play()
{
    if (cdIn == 0)
    {
        cout << "Please insert CD first." << endl;
    }
    else
    {
        cout << "正在播放" << cd->getSinger() << "的CD......" << endl;
        cd->listSongs();
    }
}


int main()
{
    string name;
    string songs[6];

    cout << "制造CD......" << endl;
    // 输入歌手名字
    cout << "  Singer's Name: " << endl;
    cin >> name; // 输入：周杰伦

    // 输入该歌手的六首歌名（青花瓷、菊花台、双节棍等）
    for (int i = 0; i < 6; i++)
    {
        cout << "  song" << (i + 1) << "#: ";
        cin >> songs[i];
    }

    CD cd(name, songs); //制造CD
    cd.listSongs();     //显示CD的内容
    CDPlayer player;    //制造CDplayer
    player.showMenu();  //生成播放机的按钮

    /* 播放 */
    player.play(); //打印：Please insert CD first
    /* 插入CD */
    player.insertCD(&cd); //打印：插入了周杰伦的CD......
    /* 播放 */
    player.play();    //打印：正在播放周杰伦的CD......
    player.ejectCD(); //打印：弹出了周杰伦的CD......

    /* 另造一张CD，歌手和歌的录入省略。*/
    // string name2;
    // string songs2[6]= {"hah", "sddsd", "sada", "suui", "dddd", "11123"};
    // name2 = "ello";
    
    // CD cd2(name2, songs2);
    // player.insertCD(&cd2);
    // player.play();

    return 0;
}
