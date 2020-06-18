#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*在行後注記標上  "//*"  的部分為維持程式用，與我負責部分無關*/
/*玩家人數：Size  ;  玩家名單：vector<string>N  ;  Pass：掠過這局  ;  Out：破產  ;  darkCard(玩家編號)：玩家暗牌*/

int Size = 4;	//*
int Ones = 100;	//目前賭注

int Allo = 0;	//目前賭注加總
bool Pass = 0;	//false 繼續，ture 為放棄	//*
bool Out = 0;	//false 繼續，ture 為破產	//*
vector<string> N;	//Name List	//*
vector<int> H;	//Have List (各人擁有籌碼)

//player:玩家編號
string darkCard(int player) { cout << player << "'s DarkCard"; }	//*

//下注(第一人)
void act0(int player, vector<string> N, bool Pass, bool Out) {
	int x = 0;  //動作選項輸入
	int seen, one, z, oth = 0;  //計數用變數

	do {	//若選擇看按牌，看完後重新選擇
		if (Out == true) {  	//是否已破產
			cout << "玩家\"" << N[player] << "\"已破產出局\n\tPass" << endl;
		}else {
			if (Pass == true) {     //是否已棄權
				cout << "玩家\"" << N[player] << "\"已在此局棄權\n\tPass" << endl;
			}else {     //執行動作提問
				cout << "Its \"" << N[player] << "\"'s turn!" << endl << endl << "是否下注？\n1.下注\n2.查看暗牌\n3.棄權" << endl;
				do{ //若選擇輸入錯誤，重新選擇
					cin >> x;
					cout << endl;

					switch (x) {        //動作選項
					case 1:	//1.下注
						cout << "請輸入下注籌碼(最少100)：";
						do {	//重來 while Ones worn
							cin >> one;
							if (one > 100 && one <= H[player]) {    //所下注的值過百且在支付能力內
								Ones = one;     //將下注記下以備加注
								z = 0;  //計數用變數：下注成功
							}else {     //下注違規
								if (one < 100 && one > H[player])
									cout << "下注籌碼最少100，並且下注籌碼應在可負擔範圍內！" << endl << "玩家擁有籌碼 " << H[player] << "，下注籌碼 " << one << "，下注不成立！" << endl << "\t請重新下注：";
								else if (one < 100 && one <= H[player])
									cout << "下注籌碼最少100！" << endl << "玩家下注籌碼 " << one << "，下注不成立！" << endl << "\t請重新下注：";
								else if (one > 100 && one > H[player])
									cout << "下注籌碼應在可負擔範圍內！" << endl << "玩家擁有籌碼 " << H[player] << "，下注籌碼 " << one << "，下注不成立！" << endl << "\t請重新下注：";

								z = 1;      //計數用變數：下注失敗
							}
						} while (z == 1);//重來 while Ones worn
						H[player] -= one;   //支付籌碼
						Allo += one;    //目前勝者所得(總下注量
						//宣告下注完成
						cout << "玩家\"" << N[player] << "\"下注" << one << "，剩餘籌碼" << H[player] << endl;
						break;

					case 3:	//DarkCard
						cout << "查看玩家\"" << N[player] << "\"的暗牌(輸入\"0\"顯示暗牌，\"-1\"取消)" << endl;
						do {	//See DarkCard
							cin >> seen;
							if (seen == 0)	//引入暗牌！!!*
								cout << "玩家" << N[player] << "的暗牌：" << darkCard(player) << endl;
							else if(seen == -1)
								seen = 0;
							else
								cout << "輸入錯誤！查看玩家\"" << N[player] << "\"的暗牌(輸入\"0\"顯示暗牌，\"-1\"取消)" << endl;
						} while (seen != 0);
						break;

					case 3:	//Pass
						Out = 0;
						cout << "玩家\"" << N[player] << "\"在此局棄權\n\tPass" << endl;
						break;

					default:	//Other
						oth = 1;
						break;

					}//end switch
				} while (oth = 1);//R while chose worn
			}//end if pass
		}//end if out
	} while (x == 2);//R while darkCard
}//End act0 下注


//跟注 & 加注
void act(int player, vector<string> N, bool Pass, bool Out) {
	int x = 0;
	int seen, one, z, oth = 0;

	do {	//R while darkCard
		if (Out == true) {	//Pass or Out
			cout << "玩家\"" << N[player] << "\"已破產出局\n\tPass" << endl;
		}else {
			if (Pass == true) {
				cout << "玩家\"" << N[player] << "\"已在此局棄權\n\tPass" << endl;
			}else {
				cout << "It's" << "'s turn!" << endl << endl << "是否跟注？\n1.跟注\n2.加注\n3.查看暗牌\n4.棄權" << endl;
				do{//R while chose(x) worn / Ones worn
					cin >> x;
					cout << endl;

					switch (x){
					case 1:	//跟注
						if (H[player] > Ones) {
							H[player] -= Ones;
							Allo += Ones;
							cout << "玩家\"" << N[player] << "\"下注" << one << "，剩餘籌碼" << H[player] << endl;
							z = 0;
						}else {
							if (one > 100 && one > H[player])
								cout << "下注籌碼應在可負擔範圍內！" << endl << "玩家擁有籌碼 " << H[player] << "，下注籌碼 " << one << "，下注不成立！" << endl;
							z = 1;
						}
						break;

					case 2:	//加注
						cout << "玩家\"" << N[player] << "\"要求加注" << endl << "請輸入下注籌碼(輸入-1取消加注)：";
						z = 1;
						do {	//R while Ones wone
							cin >> one;
							if (one != -1) {
								if (one > Ones && one <= H[player]) {
									Ones = one;
									z = 0;
								}else {
									if (one < Ones && one > H[player]) {
										cout << "下注籌碼應大於原本下注(" << Ones << ")，並且下注籌碼應在可負擔範圍內！" << endl << "玩家擁有籌碼 " << H[player] << "，下注籌碼 " << one << "，下注不成立！" << endl << "\t請重新下注：" << endl;
									}
									else if (one < Ones && one <= H[player]) {
										cout << "下注籌碼應大於原本下注(" << Ones << ")！" << endl << "玩家下注籌碼 " << one << "，下注不成立！" << endl << "\t請重新下注：" << endl;
									}
									else if (one > Ones && one > H[player]) {
										cout << "下注籌碼應在可負擔範圍內！" << endl << "玩家擁有籌碼 " << H[player] << "，下注籌碼 " << one << "，下注不成立！" << endl << "\t請重新下注：" << endl;
									}
									z = 1;
								}
							}else if (one == -1)
								z = 2;
						} while (z == 1);//R while Ones wone
						if (z == 0) {
							H[player] -= one;
							Allo += one;
							cout << "玩家\"" << N[player] << "\"下注" << one << "，剩餘籌碼" << H[player] << endl;
							break;
						}else if(one == -1)
							break;

					case 3:	//DarkCard
						cout << "查看玩家\"" << N[player] << "\"的暗牌(輸入\"0\"顯示暗牌，\"-1\"取消)" << endl;
						do {	//See DarkCard
							cin >> seen;
							if (seen == 0)	//引入暗牌！!!*
								cout << "玩家" << N[player] << "的暗牌：" << darkCard(player) << endl;
							else if(seen == -1)
								seen = 0;
							else
								cout << "輸入錯誤！查看玩家\"" << N[player] << "\"的暗牌(輸入\"0\"顯示暗牌，\"-1\"取消)" << endl;
						} while (seen != 0);
						break;

					case 4:	//Pass
						Out = 0;
						cout << "玩家\"" << N[player] << "\"在此局棄權\n\tPass" << endl;
						break;

					default:	//other
						oth = 1;
						break;

					}//end switch
				} while (oth = 1 || z == 1);//R while chose(x) worn / Ones worn
			}//end Pass
		}//End Out
	} while (x == 3);//R while darkCard
}//End act 跟注&加注



int main() {

	cout << "Number of Playre:" << endl;
	cin >> Size;


	N.assign(Size, 0);	/*0w0*/
	for (int i = 0; i < Size; i++)
		N[i] = "player" + i;

	int Player;	//*
	cout << "Player's Name:" << endl;
	for (int i = 0; i < Size; i++){
		cout << "Player " << i << " :";
		cin >> Player;
		cout << endl;
	}cout << endl;

	cout << "Player List:" << endl;
	for (int i = 0; i < Size; i++)
		cout << "Player " << i << " :" << N[i];


	H.assign(Size, 3000);	/*！！！ 0w0 0w0 0w0 0w0 ！！！*/
}
