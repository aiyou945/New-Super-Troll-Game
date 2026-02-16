//version: v1.0.0
#include<bits/stdc++.h>
#include<Windows.h>
#define blue 1
#define green 2
#define red 4
#define purple 5
#define yellow 6
#define white 7
#define gray 8
#define light_blue 9
#define light_green 10
#define light_red 12
#define light_purple 13
#define light_yellow 14
#define sky 11
#define S_O_H STD_OUTPUT_HANDLE
#define scolor SetConsoleTextAttribute 
#define KEY_DOWN(vk) ((GetAsyncKeyState(vk) & 0x8000) ? 1 : 0)
#define KEY_UP(vk) ((GetAsyncKeyState(vk) & 0x8000) ? 0 : 1)
#define MOUSE_DOWN ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) ? 1 : 0)
using namespace std;
typedef long long ll;
const string C_O_I_N = "gaedkl35nw~)+Eb12,mfr*&./Q";
const string CN1 = "0abcdefg";
const string ac_SET = "0123456789ABCDEF";
const string shop_SET = "0123456789";
void colorclear(HANDLE handle){
	scolor(handle,white);
}
void pause(){
	system("pause>nul");
}
void wait(double num){
	Sleep(num * 1000);
}
void cls(){
	system("cls");
}
void qd(HWND hWnd){
	MessageBox(hWnd,"该功能暂未实现,敬请期待!","敬请期待",MB_OK | MB_ICONERROR);
	return ;
}
void logon(HANDLE handle){
	scolor(handle,light_yellow);
	cout << "新";
	colorclear(handle);
	cout << "·";
	scolor(handle,red);
	cout << "超";
	scolor(handle,yellow);
	cout << "坑";
	scolor(handle,green);
	cout << "小";
	scolor(handle,blue);
	cout << "游";
	scolor(handle,purple);
	cout << "戏" << endl;
	colorclear(handle);
}
void logo(HANDLE handle){
	scolor(handle,(6 << 4) | 14);
	cout << "◎";
	scolor(handle,(6 << 4) | 13);
	cout << "新";
	scolor(handle,(6 << 4) | 0);
	cout << "·";
	scolor(handle,(6 << 4) | 1);
	cout << "超";
	scolor(handle,(6 << 4) | 3);
	cout << "坑";
	scolor(handle,(6 << 4) | 14);
	cout << "小";
	scolor(handle,(6 << 4) | 3);
	cout << "游";
	scolor(handle,(6 << 4) | 1);
	cout << "戏";
	cout << "◎" << endl;
	scolor(handle,(4 << 4) | 7);
	cout << "祝大家2026马年快乐!" << endl;
	colorclear(handle);
} 
char ac_change(int* ac){
	int S = 0;
	for(int i = 0;i < 3;i++){
		if(ac[i] == 1) S += (1 << i);
	}
	return ac_SET[S % ac_SET.size()];
}
void char_change(char ch,int* ac,HANDLE handle){
	int state = ac_SET.find(toupper(ch));
	if(state == string::npos){
		scolor(handle,light_red);
		cout << "读入数据错误,请检查你的输入" << endl;
		wait(1);
		state = 0;
		colorclear(handle);
	}
	for(int i = 0;i < 3;i++){
		ac[i] = (state & (1 << i)) ? 1 : 0;
	}
}
char shop_change(int* shop){
	int S = 0;
	for(int i = 0;i < 2;i++){
		if(shop[i] == 1) S += (1 << i);
	}
	return shop_SET[S % shop_SET.size()];
}
string out(int coin,int zj1,int* ac,int* shop){
	string str = "";
	char a = coin / 10;
	for(int i = 0;i < 26;i++){
		if(i == a){
			str += C_O_I_N[i];
			break;
		}
	}
	str += CN1[zj1];
	int sum = 0;
	for(int i = 0;i < 2;i++){
		sum += ac[i];
	}
	str += ac_change(ac);
	str += shop_change(shop);
	return str;
}
int in_coin(string in){
	int coin = 0;
	for(int i = 0;i < 26;i++){
		if(in[0] == C_O_I_N[i]){
			coin = i * 10;
			break;
		}
	}
	return coin;
}
bool Ctrl_E(){
    return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && 
           (GetAsyncKeyState('E') & 0x8000);
}
bool exit(){
	return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && 
           (GetAsyncKeyState('Z') & 0x8000);
}
bool GUN_W(){
	return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && 
		   (GetAsyncKeyState('W') & 0x8000);
}
bool GUN_A(){
	return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && 
		   (GetAsyncKeyState('A') & 0x8000);
}
bool GUN_S(){
	return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && 
		   (GetAsyncKeyState('S') & 0x8000);
}
bool GUN_D(){
	return (GetAsyncKeyState(VK_CONTROL) & 0x8000) && 
		   (GetAsyncKeyState('D') & 0x8000);
}
