//
//  main.cpp
//  课设1
//
//  Created by HJ on 2017/12/12.
//  Copyright © 2017年 HJ. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include<functional>
using namespace std;

class Student{
private:
    string Name,Sex;
    int No;
    float English,Math,Programme,PE,Ave;
public:
    Student(){}
    Student(string name,string sex,float eng,float mat,float pro,float pe,int no,int ave):English(eng),Math(mat),Programme(pro),PE(pe),No(no){
        Name=name;
        Sex=sex;
        Ave=ave;
    }
    void DisPlay();
    void SetData();
    float Average();
    friend class Process_Data;
    /*比较函数申明成友元便于调用私有数据*/
    friend bool cmp_by_eng(Student ob1,Student ob2);
    friend bool cmp_by_mat(Student ob1,Student ob2);
    friend bool cmp_by_pro(Student ob1,Student ob2);
    friend bool cmp_by_pe(Student ob1,Student ob2);
    /******************************/
};
/*比较函数的前向引用申明*/
bool cmp_by_eng(Student ob1,Student ob2);
bool cmp_by_mat(Student ob1,Student ob2);
bool cmp_by_pro(Student ob1,Student ob2);
bool cmp_by_pe(Student ob1,Student ob2);
/********************/
void Student::DisPlay(){
    cout<<"#"<<No<<"-"<<Name<<"-"<<Sex<<"-"<<English<<"-"<<Math<<"-"<<Programme<<"-"<<PE<<"-"<<Ave<<"#"<<endl;
}
void Student::SetData(){
    cin>>No>>Name>>Sex>>English>>Math>>Programme>>PE;
}
float Student::Average(){
    Ave=(English+Math+Programme+PE)/4;
    return (English+Math+Programme+PE)/4;
}
class Process_Data{
protected:
    int Nums;
    float AveEnglish,AveMath,AveProgramme,AvePE;
    Student *Stu;
public:
    Process_Data(){}
    Process_Data(int _Nms):Nums(_Nms){
        Stu=new Student[_Nms];
        for (int i=0; i<_Nms; i++) {
            Stu[i].SetData();
        }
    }
    ~Process_Data(){delete Stu;}
    /*其它功能*/
    void Input();
    float Average();
    void Function_Object();
    /*********/
    /*实现查找信息功能*/
    void Find(int no);
    void Find(string name);
    /***************/
    /*按体育排序并输出文件*/
    void Sort_By_PE();
    void Output_By_PE();
    /*按编程排序并输出文件*/
    void Sort_By_Programme();
    void Output_By_Programme();
    /*按数学排序并输出文件*/
    void Sort_By_Math();
    void Output_By_Math();
    /*按英语排序并输出文件*/
    void Sort_By_English();
    void Output_By_English();
    /******************/
};
float Process_Data::Average(){
    float eng=0.0;
    float mat=0.0;
    float pro=0.0;
    float pe=0.0;
    float ave=0.0;
    for (int i=0; i<Nums; i++) {
        eng+=Stu[i].English;
        mat+=Stu[i].Math;
        pro+=Stu[i].Programme;
        pe+=Stu[i].PE;
        ave+=Stu[i].Average();
    }
    AveEnglish=eng/Nums;
    AveMath=mat/Nums;
    AveProgramme=pro/Nums;
    AvePE=pe/Nums;
    return ave/Nums;
}
/*排序函数，用STL实现*/
void Process_Data::Sort_By_English(){
    std::sort(Stu, Stu+Nums, cmp_by_eng);
}
void Process_Data::Sort_By_Math(){
    std::sort(Stu, Stu+Nums, cmp_by_mat);
}
void Process_Data::Sort_By_Programme(){
    std::sort(Stu, Stu+Nums, cmp_by_pro);
}
void Process_Data::Sort_By_PE(){
    std::sort(Stu, Stu+Nums, cmp_by_pe);
}
/*********************/
/*实现查找信息功能*/
void Process_Data::Find(int no){
    for (int i=0; i<Nums; i++){
        if (no==Stu[i].No) {
            Stu[i].DisPlay();
        }
    }
}
void Process_Data::Find(string name){
    for (int i=0; i<Nums; i++){
        if (name==Stu[i].Name) {
            Stu[i].DisPlay();
        }
    }
}
/*********************/
void Process_Data::Input(){
    ofstream Data("/Users/macbook/Desktop/student.dat.txt",ios::app);
    if (Data.is_open()) {
        for(int i=0; i<Nums; i++) {
            Data<<"Name:"<<Stu[i].Name<<" Sex:"<<Stu[i].Sex<<" No:"<<Stu[i].No<<" English:"<<Stu[i].English<<" Math:"<<Stu[i].Math<<" Programme:"<<Stu[i].Programme<<" PE:"<<Stu[i].PE<<endl;
        }
        Data.close();
    }else
        cout<<"#Failed to open the file#"<<endl;
}
/*按排序结果生成文件的函数*/
//按英文成绩排序
void Process_Data::Output_By_English(){
    ofstream Result_By_English("/Users/macbook/Desktop/English.txt",ios::app);
    if (Result_By_English.is_open()) {
        for (int i=0; i<Nums; i++) {
            Result_By_English<<"Name:"<<Stu[i].Name<<" Sex:"<<Stu[i].Sex<<" No:"<<Stu[i].No<<" English:"<<Stu[i].English<<" Math:"<<Stu[i].Math<<" Programme:"<<Stu[i].Programme<<" PE:"<<Stu[i].PE<<endl;
        }
        Result_By_English.close();
        cout<<"#The File Has Been Formed In The Desktop#"<<endl;
    }else
        cout<<"#Failed to open the file#"<<endl;
}
//按数学成绩排序
void Process_Data::Output_By_Math(){
    ofstream Result_By_Math("/Users/macbook/Desktop/Math.txt",ios::app);
    if (Result_By_Math.is_open()) {
        for (int i=0; i<Nums; i++) {
            Result_By_Math<<"Name:"<<Stu[i].Name<<" Sex:"<<Stu[i].Sex<<" No:"<<Stu[i].No<<" English:"<<Stu[i].English<<" Math:"<<Stu[i].Math<<" Programme:"<<Stu[i].Programme<<" PE:"<<Stu[i].PE<<endl;
        }
        Result_By_Math.close();
        cout<<"#The File Has Been Formed In The Desktop#"<<endl;
    }else
        cout<<"#Failed to open the file#"<<endl;
}
//按编程成绩排序
void Process_Data::Output_By_Programme(){
    ofstream Result_By_Pro("/Users/macbook/Desktop/Programme.txt",ios::app);
    if (Result_By_Pro.is_open()) {
        for (int i=0; i<Nums; i++) {
            Result_By_Pro<<"Name:"<<Stu[i].Name<<" Sex:"<<Stu[i].Sex<<" No:"<<Stu[i].No<<" English:"<<Stu[i].English<<" Math:"<<Stu[i].Math<<" Programme:"<<Stu[i].Programme<<" PE:"<<Stu[i].PE<<endl;
        }
        Result_By_Pro.close();
        cout<<"#The File Has Been Formed In The Desktop#"<<endl;
    }else
        cout<<"#Failed to open the file#"<<endl;
}
//按体育成绩排序
void Process_Data::Output_By_PE(){
    ofstream Result_By_PE("/Users/macbook/Desktop/PE.txt",ios::app);
    if (Result_By_PE.is_open()) {
        for (int i=0; i<Nums; i++) {
            Result_By_PE<<"Name:"<<Stu[i].Name<<" Sex:"<<Stu[i].Sex<<" No:"<<Stu[i].No<<" English:"<<Stu[i].English<<" Math:"<<Stu[i].Math<<" Programme:"<<Stu[i].Programme<<" PE:"<<Stu[i].PE<<endl;
        }
        Result_By_PE.close();
        cout<<"#The File Has Been Formed In The Desktop#"<<endl;
    }else
        cout<<"#Failed to open the file#"<<endl;
}
/*********************/
/*用于实现菜单功能*/
void Process_Data::Function_Object(){
    string _Name;
    int _No;
    int key;
    int Flag_Quit=1;
    cout<<"#Enter what you want#"<<endl;
    while(Flag_Quit){
        cin>>key;
        switch (key) {
            case 0:
                Flag_Quit=0;
                break;
            case 1:
                cout<<"#Enter The Name#"<<endl;
                cin>>_Name;
                Find(_Name);
                break;
            case 2:
                cout<<"#Enter The No#"<<endl;
                cin>>_No;
                Find(_No);
                break;
            case 3:
                Process_Data::Sort_By_English();
                Output_By_English();
                break;
            case 4:
                Process_Data::Sort_By_Math();
                Output_By_Math();
                break;
            case 5:
                Process_Data::Sort_By_Programme();
                Output_By_Programme();
                break;
            case 6:
                Process_Data::Sort_By_PE();
                Output_By_PE();
                break;
            default:
                break;
        }
        if (Flag_Quit) {
            cout<<"#Enter what you want#"<<endl;
        }
    }
}
/*********************/
/*用于显示菜单*/
void Meun_init(){
    cout<<"**********Nanjing Foresty University Student Achievement Management System**********"<<endl;
    cout<<"#This is an empty system,please put in the data......#"<<endl;
    cout<<"#First enter the number of the students#"<<endl;
    cout<<"#Second enter the information of these students#"<<endl;
    cout<<"#Format:No Name Sex English Math Programme PE#"<<endl;
}
void Menu_Object(){
    cout<<"**********Nanjing Foresty University Student Achievement Management System**********"<<endl;
    cout<<"1)Search by name"<<endl;
    cout<<"2)Search by No"<<endl;
    cout<<"3)Sort by English"<<endl;
    cout<<"4)Sort by Math"<<endl;
    cout<<"5)Sort by Programme"<<endl;
    cout<<"6)Sort by PE"<<endl;
    cout<<"#Press 0 to Quit The System#"<<endl;
    cout<<"#Now Please Enter The Key You Want#"<<endl;
    cout<<"**********Nanjing Foresty University Student Achievement Management System**********"<<endl;
}
void Menu_End(){
    cout<<"#Provide By Huangjian24#"<<endl;
    cout<<"#See You Next Time,Good Bye#"<<endl;
}
/*********************/
/*用于sort的比较函数*/
//英语
bool cmp_by_eng(Student ob1,Student ob2){
    return ob1.English>ob2.English;
}
//数学
bool cmp_by_mat(Student ob1,Student ob2){
    return ob1.Math>ob2.Math;
}
//编程
bool cmp_by_pro(Student ob1,Student ob2){
    return ob1.Programme>ob2.Programme;
}
//体育
bool cmp_by_pe(Student ob1,Student ob2){
    return ob1.PE>ob2.PE;
}
/*********************/
int main(int argc, const char * argv[]){
    Meun_init();
    int Number;
    cin>>Number;
    Process_Data *ob = new Process_Data(Number);
    ob->Input();
    Menu_Object();
    ob->Function_Object();
    Menu_End();
    return 0;
}






