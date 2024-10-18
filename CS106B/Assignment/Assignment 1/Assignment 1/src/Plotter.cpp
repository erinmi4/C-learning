#include "Plotter.h"
#include "strlib.h"
#include<iostream>
#include "vector.h"
#include<string>
using namespace std;

//默认的初始化地址
#define STATEX 0
#define STATEY 0

int presentX = STATEX;
int presentY = STATEY;
bool validPen; //false说明笔抬起来了，True说明笔落下了。


void moveabs(int endX, int endY,PenStyle info) {
    drawLine(presentX, presentY, endX, endY, info);
}

void moverel(int endX, int endY,PenStyle info) {
    drawLine(presentX, presentY, presentX + endX, presentY + endY, info);
}

void pendown() {
    validPen = true;
}

void penup() {
    validPen = false;
}

//通过读取文本，实现绘画instruction
void runPlotterScript(istream& input) {
    //初始化绘图仪
    PenStyle style = { 1, "black" }; // Everything is initialized
    penup();
    //读入文本
    for (string line; getline(input, line);) {
        Vector<string> res = stringSplit(line,' ');
        string instruction = toLowerCase(res[0]);
        //根据长度和内容区分是哪一类指令
        if (res.size() == 3) {
            if (validPen) {
                //@source:https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/
                int endX = stoi(res[1]);
                int endY = stoi(res[2]);
                if (instruction == "moveabs") {
                    moveabs(endX,endY,style);
                    presentX = endX;  // 对于 moveabs
                    presentY = endY;
                }
                else {
                    moverel(endX,endY,style);
                    presentX += endX;  // 对于 moverel
                    presentY += endY;
                }
            }
        }
        else {
            if (instruction == "penup") {
                penup();
            }
            else {
                pendown();
            }
        }
    }
}

