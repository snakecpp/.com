#include <iostream>
#include"newlib.h"
#define MAX 100
using namespace std;
int sl = 3; 
void vetuong();
void khoitaoran(int toadox[], int toadoy[]);
void xoadulieucu(int toadox[],int toadoy[]);
void veran(int toadox[], int toadoy[]);
void xulyran(int toadox[], int toadoy[], int x, int y, int& xpt, int& ypt);
void them(int a[], int x);
void xoa(int a[], int vt);
bool ktrantucanduoi(int toadox[], int toadoy[]);
bool ktranchamtuong(int x0, int y0);
bool ktran(int toadox[], int toadoy[]); 
void taophanthuong(int& xpt, int& ypt, int toadox[], int toadoy[]);
bool ktrandelenphanthuong(int xpt, int ypt, int toadox[], int toadoy[]);
bool ktrananphanthuong(int xpt, int ypt, int x0, int y0);
void HideConsoleCursor();
//========ham main - ham xu ly chinh============

int main()
{  
	
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	vetuong();
	khoitaoran(toadox,toadoy);
	veran(toadox, toadoy);
	HideConsoleCursor();
	//=====kiem tra va tao phan thuong====
	srand(time(NULL));
	int xpt = 0, ypt = 0;
	//tao phan thuong
	taophanthuong(xpt, ypt, toadox, toadoy);
	int x = 30, y = 13;//dinh hinh vi tri can di chuyen cho ran
	int check = 2;
	while (gameover == false)
	{
		//system("cls");
		//backspace
		xoadulieucu(toadox, toadoy);
		//check=0:cham bien tren di xuong
		//check=1; cham bien duoi di len
		//check =2: cham bien trai qua phai
		//check=3:cham bien phai qua trai
		//==========dieu khien
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0)//dilen
				{
					check = 1;
				}
				else if (kitu == 80 && check != 1)//di xuong
				{
					check = 0;
				}
				else if (kitu == 77 && check != 3)//qua phai
				{
					check = 2;
				}
				else if (kitu == 75 && check != 2)//qua trai
				{
					check = 3;
				}
			}
		}
		//thuc hien di chuyen
		if (check == 0) {
			y++;//di xuong
		}
		else if (check == 1) {
			y--;//di len
		}
		else if (check == 2) {
			//qua phai
			x++;
		}
		else if (check == 3) {
			x--;//qua trai
		}
		xulyran(toadox, toadoy, x, y,xpt,ypt);
		//kiem tra
		gameover = ktran(toadox, toadoy);
		Sleep(300);
	}
	
	
	_getch();
	return 0;
}
void ve_tuong_tren()
{
	int x = 10, y = 1;
	while (x <= 50)
	{
		gotoXY(x, y);
		cout << char(240);
		x++;
	}


}
void vetuongduoi() {
	int x = 10, y = 26;
	while (x <= 50) 
	{
		gotoXY(x, y);
		cout << char(240);
		x++;
	}
}
void vetuongtrai() {
	int x = 10, y = 1;
while (y <= 26)
{
	gotoXY(x, y);
	cout << char(240);
	
	y++;
}
 }
 void vetuongphai() {
	 int x = 50, y = 1;
	 while (y <= 26)
	 {
		 gotoXY(x, y);
		 cout << char(240);
		
		 y++;

	 }
 }
 void vetuong() {
	 SetColor(12);
	 vetuongduoi();
	 ve_tuong_tren();
	 vetuongphai();
	 vetuongtrai();
 }
 void khoitaoran(int toadox[], int toadoy[])
 {
	 //snake 1
	 int x = 30, y = 13;
	 for (int i = 0; i < sl; i++)
	 {
		 toadox[i] = x;
		 toadoy[i] = y;
		 x--;
	 }
	
 }
 void veran(int toadox[], int toadoy[])
 {
	 for (int i = 0; i < sl; i++) {
		 gotoXY(toadox[i], toadoy[i]);
		 if (i == 0) {
cout << char(233);
		 }
		 else {
		 cout << "o";
		 }
	 }
	

 }
 void xoadulieucu(int toadox[], int toadoy[]) {
	 for (int i = 0; i < sl; i++) {
		 gotoXY(toadox[i], toadoy[i]);
		 cout << " ";
	 }
 }
 void xulyran(int toadox[], int toadoy[], int x, int y,int &xpt, int &ypt) {
	 //b1 them toa do moi vao dau mang
	 them(toadox, x);
	 them(toadoy, y);
	 if (ktrananphanthuong(xpt, ypt, toadox[0], toadoy[0]) == false) 
	 {
		//b2 xoa toa do cuoi mang
		 xoa(toadox, sl - 1);
		 xoa(toadoy, sl - 1);
	 }
	 else {
		 taophanthuong(xpt, ypt, toadox, toadoy);

	 }
	 
	 //b3 ve ran
	 veran(toadox, toadoy);
	 

 }
 void them(int a[], int x) {
	 for (int i = sl; i > 0; i--) {
		 a[i] = a[i - 1];
	 }
	 a[0] = x;
	 sl++;
 }
 void xoa(int a[], int vt) {
	 for (int i = vt; i < sl; i++) {
		 a[i] = a[i + 1];
	 }
	 sl--;
 }
 bool ktranchamtuong(int x0, int y0)
 {
	 if (y0 == 1 && (x0 >= 10 && x0 <= 50))//ran cham tuong tren
	 {
		 return true;//gameover
	 }
	 else if (y0 == 26 && (x0 >= 10 && x0 <= 50))//ran cham tuong duoi
	 {
		 return true;
	 }
	 else if (x0 == 10 && (y0 >= 1 && y0 <= 26))//ran cham tuong trai
	 {
		 return true;
	 }
	 else if (x0 == 50 && (y0 >= 1 && y0 <= 26))//ran cham tuong phai
	 {
		 return true;
	 }
	 return false;
 }
 bool ktrantucanduoi(int toadox[], int toadoy[])
 {
	 for (int i = 1; i < sl; i++) {
		 if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		 {
			 return true; //game over
		 }
	 }
	 return false;
 }
 bool ktran(int toadox[], int toadoy[])
 {
	 bool kt1 = ktrantucanduoi(toadox, toadoy);//gameover = true
	 bool kt2 = ktranchamtuong(toadox[0], toadoy[0]);//gameover = false
	 if (kt1 == true || kt2 == true) {
		 return true;//gameover 
	 }
	 return false;
 }
 void taophanthuong(int& xpt, int& ypt, int toadox[], int toadoy[])
 {

	 do {
		 //11<=xpt<=49
		 xpt = rand() % (49 - 11 + 1) + 11;
		 //2<=ypt<=25
		 ypt = rand() % (25 - 2 + 1) + 2;
	 } while (ktrandelenphanthuong(xpt, ypt, toadox, toadoy) == true);
	 int i = rand() % (15 - 1 + 1) + 1;
	 SetColor(12);
	 gotoXY(xpt, ypt);
	 cout << "$";
	 SetColor(7);//mautrang
 }
 bool ktrandelenphanthuong(int xpt, int ypt, int toadox[], int toadoy[])
 {
	 for (int i = 0; i < sl; i++) {
		 if ((xpt == toadox[i]) && (ypt == toadoy[i])) {

			 return true;//ran de len phan thuong
		 }
	 }
	 return false;
 }
 bool ktrananphanthuong(int xpt, int ypt, int x0, int y0) {
	 if ((x0 == xpt) && (y0 == ypt)){
	 return true; //ran an qua
	 }
	 return false;

}
 void HideConsoleCursor()
 {
	 HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	 CONSOLE_CURSOR_INFO     cursorInfo;

	 GetConsoleCursorInfo(out, &cursorInfo);
	 cursorInfo.bVisible = 0;
	 SetConsoleCursorInfo(out, &cursorInfo);
 }