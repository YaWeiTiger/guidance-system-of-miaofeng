#include"flashdata.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>
#include"class.h"
#include"algorithm.h"
using namespace std;
extern Graph* G;
extern Path p;
void flash()
{
    //44个节点
    std::vector<string> names{};
    names.push_back(qstrTostr("入口"));//0
    names.push_back(qstrTostr("玫瑰画餐厅"));//1
    names.push_back(qstrTostr("红色背篓餐饮部"));//2
    names.push_back(qstrTostr("石涧溪水"));//3
    names.push_back(qstrTostr("坡坡餐厅"));//4
    names.push_back(qstrTostr("云上石屋"));//5
    names.push_back(qstrTostr("玫瑰亭"));//6
    names.push_back(qstrTostr("农耕文化园"));//7
    names.push_back(qstrTostr("杏树林"));//8
    names.push_back(qstrTostr("清风亭"));//9
    names.push_back(qstrTostr("龙天观遗址"));//10
    names.push_back(qstrTostr("蓄水池观景台"));//11
    names.push_back(qstrTostr("秋风亭服务区"));//12
    names.push_back(qstrTostr("层林观景台"));//13
    names.push_back(qstrTostr("大杏树休息区"));//14
    names.push_back(qstrTostr("百年黄栌观景台"));//15
    names.push_back(qstrTostr("百年黄栌服务区"));//16
    names.push_back(qstrTostr("鹰虎石"));//17
    names.push_back(qstrTostr("山间芦苇"));//18
    names.push_back(qstrTostr("青杨林"));//19
    names.push_back(qstrTostr("琵琶石"));//20
    names.push_back(qstrTostr("好汉岩"));//21
    names.push_back(qstrTostr("鹰嘴岩服务区"));//22
    names.push_back(qstrTostr("鹰嘴岩"));//23
    names.push_back(qstrTostr("点将台"));//24
    names.push_back(qstrTostr("古泉"));//25
    names.push_back(qstrTostr("塔院"));//26
    names.push_back(qstrTostr("宝金山玉虚宫"));//27
    names.push_back(qstrTostr("卫生间1"));//28
    names.push_back(qstrTostr("卫生间2"));//29
    names.push_back(qstrTostr("卫生间3"));//30
    for (int i = 1; i <= 13; i++)
    {
        string s1= qstrTostr("岔路口");
        string s2 =to_string(i);
        names.push_back(s1+s2);
    }//31-43
    srand(time(0));
    //人数
    vector<int> people{};
    for (int i = 0; i < names.size()-16; i++)
    {
        people.push_back(rand()%5000);
    }
    for (int i = 0; i < 3; i++)
    {
        people.push_back(rand() % 100);
    }
    for (int i = 0; i < 13; i++)
    {
        people.push_back(rand() % 1000);
    }
    people[0] = rand() % 500;
    //是否开放
    vector<int> isOpen{};
    for (int i = 0; i < names.size()-13; i++)
    {
        isOpen.push_back(rand() % 2);
    }
    for (int i = 0; i < 13; i++)
    {
        isOpen.push_back(1);
    }
    isOpen[0] = 1;
    //热度排行
    vector<int> hotRank{};
    hotRank.push_back(0);
    int a[27];
        for (int i = 1; i <= 27; i++) {
            a[i - 1] = i;
        }
        //生成1-27的随机序列
        srand(time(0));
        for (int i = 0; i < 27; i++) {
            int j = rand() % 27;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        for (int i = 0; i < 27; i++) {
           hotRank.push_back(a[i]);
        }
    for (int i = 0; i < 16; i++)
    {
        hotRank.push_back(0);
    }


    //边的数量
    vector<int> edgeNum{};
    edgeNum.push_back(1);
    edgeNum.push_back(1);
    edgeNum.push_back(1);
    edgeNum.push_back(1);
    for (int i = 0; i < 24; i++)
    {
        edgeNum.push_back(2);
    }
    edgeNum.push_back(2);
    edgeNum.push_back(4);
    edgeNum.push_back(1);

    edgeNum.push_back(4);
    edgeNum.push_back(3);
    edgeNum.push_back(3);
    edgeNum.push_back(3);
    edgeNum.push_back(3);
    edgeNum.push_back(4);
    edgeNum.push_back(3);
    edgeNum.push_back(5);
    edgeNum.push_back(4);
    edgeNum.push_back(3);
    edgeNum.push_back(3);
    edgeNum.push_back(4);
    edgeNum.push_back(3);

    //邻接点和边权
    vector<vector<int>> sets{};
    for (int i = 0; i < names.size(); i++)
    {
        vector<int> v{};
        sets.push_back(v);
    }

    sets[0].push_back(43);
    sets[0].push_back(303);

    sets[1].push_back(43);
    sets[1].push_back(252);

    sets[2].push_back(42);
    sets[2].push_back(192);

    sets[3].push_back(41);
    sets[3].push_back(318);

    sets[4].push_back(39);
    sets[4].push_back(144);
    sets[4].push_back(5);
    sets[4].push_back(120);

    sets[5].push_back(4);
    sets[5].push_back(120);
    sets[5].push_back(38);
    sets[5].push_back(315);

    sets[6].push_back(39);
    sets[6].push_back(420);
    sets[6].push_back(38);
    sets[6].push_back(318);

    sets[7].push_back(8);
    sets[7].push_back(198);
    sets[7].push_back(38);
    sets[7].push_back(582);


    sets[8].push_back(36);
    sets[8].push_back(246);
    sets[8].push_back(7);
    sets[8].push_back(198);

    sets[9].push_back(38);
    sets[9].push_back(378);
    sets[9].push_back(10);
    sets[9].push_back(309);

    sets[10].push_back(9);
    sets[10].push_back(309);
    sets[10].push_back(11);
    sets[10].push_back(414);

    sets[11].push_back(10);
    sets[11].push_back(414);
    sets[11].push_back(37);
    sets[11].push_back(177);

    sets[12].push_back(40);
    sets[12].push_back(198);
    sets[12].push_back(35);
    sets[12].push_back(207);

    sets[13].push_back(35);
    sets[13].push_back(183);
    sets[13].push_back(33);
    sets[13].push_back(153);

    sets[14].push_back(34);
    sets[14].push_back(171);
    sets[14].push_back(32);
    sets[14].push_back(210);

    sets[15].push_back(29);
    sets[15].push_back(147);
    sets[15].push_back(16);
    sets[15].push_back(123);

    sets[16].push_back(15);
    sets[16].push_back(123);
    sets[16].push_back(17);
    sets[16].push_back(207);

    sets[17].push_back(16);
    sets[17].push_back(207);
    sets[17].push_back(37);
    sets[17].push_back(117);

    sets[18].push_back(19);
    sets[18].push_back(213);
    sets[18].push_back(29);
    sets[18].push_back(147);

    sets[19].push_back(31);
    sets[19].push_back(90);
    sets[19].push_back(18);
    sets[19].push_back(213);

    sets[20].push_back(31);
    sets[20].push_back(216);
    sets[20].push_back(29);
    sets[20].push_back(375);

    sets[21].push_back(31);
    sets[21].push_back(174);
    sets[21].push_back(22);
    sets[21].push_back(150);

    sets[22].push_back(21);
    sets[22].push_back(150);
    sets[22].push_back(23);
    sets[22].push_back(156);

    sets[23].push_back(22);
    sets[23].push_back(156);
    sets[23].push_back(28);
    sets[23].push_back(102);

    sets[24].push_back(28);
    sets[24].push_back(120);
    sets[24].push_back(25);
    sets[24].push_back(501);

    sets[25].push_back(24);
    sets[25].push_back(501);
    sets[25].push_back(26);
    sets[25].push_back(195);

    sets[26].push_back(25);
    sets[26].push_back(195);
    sets[26].push_back(27);
    sets[26].push_back(186);

    sets[27].push_back(26);
    sets[27].push_back(186);
    sets[27].push_back(35);
    sets[27].push_back(849);

    sets[28].push_back(24);
    sets[28].push_back(120);
    sets[28].push_back(23);
    sets[28].push_back(102);

    sets[29].push_back(20);
    sets[29].push_back(375);
    sets[29].push_back(18);
    sets[29].push_back(147);
    sets[29].push_back(32);
    sets[29].push_back(375);
    sets[29].push_back(15);
    sets[29].push_back(147);

    sets[30].push_back(33);
    sets[30].push_back(84);

    sets[31].push_back(21);
    sets[31].push_back(174);
    sets[31].push_back(32);
    sets[31].push_back(492);
    sets[31].push_back(19);
    sets[31].push_back(90);
    sets[31].push_back(20);
    sets[31].push_back(216);

    sets[32].push_back(31);
    sets[32].push_back(492);
    sets[32].push_back(14);
    sets[32].push_back(210);
    sets[32].push_back(29);
    sets[32].push_back(375);

    sets[33].push_back(30);
    sets[33].push_back(84);
    sets[33].push_back(13);
    sets[33].push_back(153);
    sets[33].push_back(34);
    sets[33].push_back(132);

    sets[34].push_back(33);
    sets[34].push_back(132);
    sets[34].push_back(36);
    sets[34].push_back(234);
    sets[34].push_back(14);
    sets[34].push_back(171);

    sets[35].push_back(27);
    sets[35].push_back(849);
    sets[35].push_back(12);
    sets[35].push_back(207);
    sets[35].push_back(13);
    sets[35].push_back(183);

    sets[36].push_back(34);
    sets[36].push_back(234);
    sets[36].push_back(39);
    sets[36].push_back(366);
    sets[36].push_back(8);
    sets[36].push_back(246);
    sets[36].push_back(37);
    sets[36].push_back(642);

    sets[37].push_back(17);
    sets[37].push_back(117);
    sets[37].push_back(36);
    sets[37].push_back(642);
    sets[37].push_back(11);
    sets[37].push_back(177);

    sets[38].push_back(9);
    sets[38].push_back(378);
    sets[38].push_back(7);
    sets[38].push_back(582);
    sets[38].push_back(6);
    sets[38].push_back(318);
    sets[38].push_back(5);
    sets[38].push_back(315);
    sets[38].push_back(42);
    sets[38].push_back(195);

    sets[39].push_back(36);
    sets[39].push_back(366);
    sets[39].push_back(40);
    sets[39].push_back(165);
    sets[39].push_back(4);
    sets[39].push_back(144);
    sets[39].push_back(6);
    sets[39].push_back(420);

    sets[40].push_back(39);
    sets[40].push_back(165);
    sets[40].push_back(12);
    sets[40].push_back(198);
    sets[40].push_back(41);
    sets[40].push_back(183);

    sets[41].push_back(40);
    sets[41].push_back(183);
    sets[41].push_back(3);
    sets[41].push_back(318);
    sets[41].push_back(42);
    sets[41].push_back(291);

    sets[42].push_back(38);
    sets[42].push_back(195);
    sets[42].push_back(41);
    sets[42].push_back(291);
    sets[42].push_back(2);
    sets[42].push_back(192);
    sets[42].push_back(43);
    sets[42].push_back(405);

    sets[43].push_back(42);
    sets[43].push_back(405);
    sets[43].push_back(0);
    sets[43].push_back(303);
    sets[43].push_back(1);
    sets[43].push_back(252);

    //坐标
    vector<int> x{};
    vector<int> y{};

    x.push_back(1104);
    y.push_back(505);

    x.push_back(966);
    y.push_back(410);

    x.push_back(993);
    y.push_back(324);

    x.push_back(963);
    y.push_back(279);

    x.push_back(772);
    y.push_back(298);

    x.push_back(797);
    y.push_back(335);

    x.push_back(776);
    y.push_back(389);

    x.push_back(692);
    y.push_back(417);
    //
    x.push_back(652);
    y.push_back(365);

    x.push_back(797);
    y.push_back(481);

    x.push_back(709);
    y.push_back(530);

    x.push_back(578);
    y.push_back(494);

    x.push_back(757);
    y.push_back(212);

    x.push_back(633);
    y.push_back(237);

    x.push_back(505);
    y.push_back(262);

    x.push_back(403);
    y.push_back(410);

    x.push_back(442);
    y.push_back(412);

    x.push_back(494);
    y.push_back(458);

    x.push_back(352);
    y.push_back(332);

    x.push_back(281);
    y.push_back(328);
    //
    x.push_back(258);
    y.push_back(365);

    x.push_back(248);
    y.push_back(254);

    x.push_back(199);
    y.push_back(261);

    x.push_back(156);
    y.push_back(239);

    x.push_back(137);
    y.push_back(202);

    x.push_back(296);
    y.push_back(158);

    x.push_back(358);
    y.push_back(140);

    x.push_back(413);
    y.push_back(165);

    x.push_back(123);
    y.push_back(238);

    x.push_back(382);
    y.push_back(367);

    x.push_back(597);
    y.push_back(221);

    x.push_back(280);
    y.push_back(300);
    //
    x.push_back(437);
    y.push_back(259);

    x.push_back(584);
    y.push_back(240);

    x.push_back(560);
    y.push_back(276);

    x.push_back(689);
    y.push_back(216);

    x.push_back(638);
    y.push_back(286);

    x.push_back(528);
    y.push_back(473);

    x.push_back(880);
    y.push_back(390);

    x.push_back(753);
    y.push_back(250);

    x.push_back(808);
    y.push_back(250);

    x.push_back(858);
    y.push_back(281);

    x.push_back(931);
    y.push_back(342);

    x.push_back(1046);
    y.push_back(423);

    //写入文件
    fstream f;
    f.open("data.txt", ios::out);
    f << names.size() << "\n";
    for (int i = 0; i < names.size(); i++)
    {
        f << names[i] << " " << people[i] << " " << isOpen[i] << " " <<hotRank[i]<<" "<< edgeNum[i];
        for (int j = 0; j < sets[i].size(); j++)
        {
            f << " " << sets[i][j];
        }
        f << " "<<x[i] << " " << y[i]<<"\n";
    }
    f.close();
    delete G;
    G = create_();

}
