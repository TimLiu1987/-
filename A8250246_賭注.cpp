#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*�b���`�O�ФW  "//*"  �������������{���ΡA�P�ڭt�d�����L��*/
/*���a�H�ơGSize  ;  ���a�W��Gvector<string>N  ;  Pass�G���L�o��  ;  Out�G�}��  ;  darkCard(���a�s��)�G���a�t�P*/

int Size = 4;	//*
int Ones = 100;	//�ثe��`

int Allo = 0;	//�ثe��`�[�`
bool Pass = 0;	//false �~��Ature �����	//*
bool Out = 0;	//false �~��Ature ���}��	//*
vector<string> N;	//Name List	//*
vector<int> H;	//Have List (�U�H�֦��w�X)

//player:���a�s��
string darkCard(int player) { cout << player << "'s DarkCard"; }	//*

//�U�`(�Ĥ@�H)
void act0(int player, vector<string> N, bool Pass, bool Out) {
	int x = 0;  //�ʧ@�ﶵ��J
	int seen, one, z, oth = 0;  //�p�ƥ��ܼ�

	do {	//�Y��ܬݫ��P�A�ݧ��᭫�s���
		if (Out == true) {  	//�O�_�w�}��
			cout << "���a\"" << N[player] << "\"�w�}���X��\n\tPass" << endl;
		}else {
			if (Pass == true) {     //�O�_�w���v
				cout << "���a\"" << N[player] << "\"�w�b�������v\n\tPass" << endl;
			}else {     //����ʧ@����
				cout << "Its \"" << N[player] << "\"'s turn!" << endl << endl << "�O�_�U�`�H\n1.�U�`\n2.�d�ݷt�P\n3.���v" << endl;
				do{ //�Y��ܿ�J���~�A���s���
					cin >> x;
					cout << endl;

					switch (x) {        //�ʧ@�ﶵ
					case 1:	//1.�U�`
						cout << "�п�J�U�`�w�X(�̤�100)�G";
						do {	//���� while Ones worn
							cin >> one;
							if (one > 100 && one <= H[player]) {    //�ҤU�`���ȹL�ʥB�b��I��O��
								Ones = one;     //�N�U�`�O�U�H�ƥ[�`
								z = 0;  //�p�ƥ��ܼơG�U�`���\
							}else {     //�U�`�H�W
								if (one < 100 && one > H[player])
									cout << "�U�`�w�X�̤�100�A�åB�U�`�w�X���b�i�t��d�򤺡I" << endl << "���a�֦��w�X " << H[player] << "�A�U�`�w�X " << one << "�A�U�`�����ߡI" << endl << "\t�Э��s�U�`�G";
								else if (one < 100 && one <= H[player])
									cout << "�U�`�w�X�̤�100�I" << endl << "���a�U�`�w�X " << one << "�A�U�`�����ߡI" << endl << "\t�Э��s�U�`�G";
								else if (one > 100 && one > H[player])
									cout << "�U�`�w�X���b�i�t��d�򤺡I" << endl << "���a�֦��w�X " << H[player] << "�A�U�`�w�X " << one << "�A�U�`�����ߡI" << endl << "\t�Э��s�U�`�G";

								z = 1;      //�p�ƥ��ܼơG�U�`����
							}
						} while (z == 1);//���� while Ones worn
						H[player] -= one;   //��I�w�X
						Allo += one;    //�ثe�Ӫ̩ұo(�`�U�`�q
						//�ŧi�U�`����
						cout << "���a\"" << N[player] << "\"�U�`" << one << "�A�Ѿl�w�X" << H[player] << endl;
						break;

					case 3:	//DarkCard
						cout << "�d�ݪ��a\"" << N[player] << "\"���t�P(��J\"0\"��ܷt�P�A\"-1\"����)" << endl;
						do {	//See DarkCard
							cin >> seen;
							if (seen == 0)	//�ޤJ�t�P�I!!*
								cout << "���a" << N[player] << "���t�P�G" << darkCard(player) << endl;
							else if(seen == -1)
								seen = 0;
							else
								cout << "��J���~�I�d�ݪ��a\"" << N[player] << "\"���t�P(��J\"0\"��ܷt�P�A\"-1\"����)" << endl;
						} while (seen != 0);
						break;

					case 3:	//Pass
						Out = 0;
						cout << "���a\"" << N[player] << "\"�b�������v\n\tPass" << endl;
						break;

					default:	//Other
						oth = 1;
						break;

					}//end switch
				} while (oth = 1);//R while chose worn
			}//end if pass
		}//end if out
	} while (x == 2);//R while darkCard
}//End act0 �U�`


//��` & �[�`
void act(int player, vector<string> N, bool Pass, bool Out) {
	int x = 0;
	int seen, one, z, oth = 0;

	do {	//R while darkCard
		if (Out == true) {	//Pass or Out
			cout << "���a\"" << N[player] << "\"�w�}���X��\n\tPass" << endl;
		}else {
			if (Pass == true) {
				cout << "���a\"" << N[player] << "\"�w�b�������v\n\tPass" << endl;
			}else {
				cout << "It's" << "'s turn!" << endl << endl << "�O�_��`�H\n1.��`\n2.�[�`\n3.�d�ݷt�P\n4.���v" << endl;
				do{//R while chose(x) worn / Ones worn
					cin >> x;
					cout << endl;

					switch (x){
					case 1:	//��`
						if (H[player] > Ones) {
							H[player] -= Ones;
							Allo += Ones;
							cout << "���a\"" << N[player] << "\"�U�`" << one << "�A�Ѿl�w�X" << H[player] << endl;
							z = 0;
						}else {
							if (one > 100 && one > H[player])
								cout << "�U�`�w�X���b�i�t��d�򤺡I" << endl << "���a�֦��w�X " << H[player] << "�A�U�`�w�X " << one << "�A�U�`�����ߡI" << endl;
							z = 1;
						}
						break;

					case 2:	//�[�`
						cout << "���a\"" << N[player] << "\"�n�D�[�`" << endl << "�п�J�U�`�w�X(��J-1�����[�`)�G";
						z = 1;
						do {	//R while Ones wone
							cin >> one;
							if (one != -1) {
								if (one > Ones && one <= H[player]) {
									Ones = one;
									z = 0;
								}else {
									if (one < Ones && one > H[player]) {
										cout << "�U�`�w�X���j��쥻�U�`(" << Ones << ")�A�åB�U�`�w�X���b�i�t��d�򤺡I" << endl << "���a�֦��w�X " << H[player] << "�A�U�`�w�X " << one << "�A�U�`�����ߡI" << endl << "\t�Э��s�U�`�G" << endl;
									}
									else if (one < Ones && one <= H[player]) {
										cout << "�U�`�w�X���j��쥻�U�`(" << Ones << ")�I" << endl << "���a�U�`�w�X " << one << "�A�U�`�����ߡI" << endl << "\t�Э��s�U�`�G" << endl;
									}
									else if (one > Ones && one > H[player]) {
										cout << "�U�`�w�X���b�i�t��d�򤺡I" << endl << "���a�֦��w�X " << H[player] << "�A�U�`�w�X " << one << "�A�U�`�����ߡI" << endl << "\t�Э��s�U�`�G" << endl;
									}
									z = 1;
								}
							}else if (one == -1)
								z = 2;
						} while (z == 1);//R while Ones wone
						if (z == 0) {
							H[player] -= one;
							Allo += one;
							cout << "���a\"" << N[player] << "\"�U�`" << one << "�A�Ѿl�w�X" << H[player] << endl;
							break;
						}else if(one == -1)
							break;

					case 3:	//DarkCard
						cout << "�d�ݪ��a\"" << N[player] << "\"���t�P(��J\"0\"��ܷt�P�A\"-1\"����)" << endl;
						do {	//See DarkCard
							cin >> seen;
							if (seen == 0)	//�ޤJ�t�P�I!!*
								cout << "���a" << N[player] << "���t�P�G" << darkCard(player) << endl;
							else if(seen == -1)
								seen = 0;
							else
								cout << "��J���~�I�d�ݪ��a\"" << N[player] << "\"���t�P(��J\"0\"��ܷt�P�A\"-1\"����)" << endl;
						} while (seen != 0);
						break;

					case 4:	//Pass
						Out = 0;
						cout << "���a\"" << N[player] << "\"�b�������v\n\tPass" << endl;
						break;

					default:	//other
						oth = 1;
						break;

					}//end switch
				} while (oth = 1 || z == 1);//R while chose(x) worn / Ones worn
			}//end Pass
		}//End Out
	} while (x == 3);//R while darkCard
}//End act ��`&�[�`



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


	H.assign(Size, 3000);	/*�I�I�I 0w0 0w0 0w0 0w0 �I�I�I*/
}
