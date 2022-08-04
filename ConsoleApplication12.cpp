#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

//キャラクター能力
vector<int> PA{ 100, 50, 10 };
vector<int> PB{ 200, 30, 50 };

//キャラクターのクラス
struct monster {
	string name;
	int HP;
	int ATK;
	int DEF;
	vector<int> parameter;
};

vector<int> parameter1;
vector<int> parameter2;
string name1;
string name2;


//キャラクター選択の関数
void CharacterSelect1(string Characterchoice) {
	if (Characterchoice == "A") {
		name1 = "Attacker";
		parameter1 = PA;
	}

	else if (Characterchoice == "B") {
		name1 = "Blocker";
		parameter1 = PB;
	}

	else {
		cout << "予期せぬエラーが発生しました" << endl;
		cout << "始めからやり直してください" << endl;
	}
}

void CharacterSelect2(string Charactername) {
	if (Charactername == "A") {
		name2 = "Attacker";
		parameter2 = PA;
	}

	else if (Charactername == "B") {
		name2 = "Blocker";
		parameter2 = PB;
	}

	else {
		cout << "予期せぬエラーが発生しました" << endl;
		cout << "始めからやり直してください" << endl;
	}
}

//対戦終了かどうかの判断するために必要な関数
int HPcompare(int x, int y) {
	int HPlower = 0;
	if (x > y) {
		 HPlower= y;
	}
	else {
		HPlower = x;
	}
	return HPlower;
}

// ダメージ計算の関数
int damegecf(int x, int y){
	int z = 0;
	z = x * (100 - y) / 100;
	return z;
}

//プログラム本体
int main() {
	string choice1;
	string choice2;
	int HP1 = 0, HP2 = 0;
	int ATK1 = 0, ATK2 = 0;
	int DEF1 = 0, DEF2 = 0;
	int HPcheck = 0;
	int command = 0;
	int damege = 0;
	random_device rnd;
	uniform_int_distribution<unsigned> distl(1, 3);

	monster player1;
	player1.name;
	player1.parameter;

	monster player2;
	player2.name;
	player2.parameter;

	//キャラクター選択
	//Player1
	cout << "あなたが使うモンスターはどっち？(AかBを入力)" << endl;
	cout << "A:攻撃性能高" << endl;
	cout << "B:防御性能高" << endl;
	cin >> choice1;
	CharacterSelect1(choice1);
	player1.name = name1;
	player1.parameter = parameter1;
	cout << name1 << endl;
	cout << "HP, ATK, DEF," << endl;
	for (auto it = player1.parameter.begin(); it != player1.parameter.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl << endl;


	//player2
	cout << "相手が使うモンスターはどっち？(AかBを入力)" << endl;
	cin >> choice2;
	CharacterSelect2(choice2);
	player2.name = name2;
	player2.parameter = parameter2;
	cout << name2 << endl;
	cout << "HP, ATK, DEF," << endl;
	for (auto it = player2.parameter.begin(); it != player2.parameter.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl << endl;

	//パラメーター確定
	HP1 = player1.parameter[0];
	HP2 = player2.parameter[0];
	ATK1 = player1.parameter[1];
	ATK2 = player2.parameter[1];
	DEF1 = player1.parameter[2];
	DEF2 = player2.parameter[2];

	//対戦のプログラム
	cout << "'777'入力で対戦スタート" << endl;
	int startflag;
	cin >> startflag;
	switch (startflag){

	    case 777:
			HPcheck = HPcompare(HP1, HP2);
			while (HPcheck > 0) {
				cout << endl;
				cout << "player1" << endl << "HP:" << HP1 << endl << "攻撃力:" << ATK1 << endl << "防御力:" << DEF1 << endl << endl;
				cout << "player2" << endl << "HP:" << HP2 << endl << "攻撃力:" << ATK2 << endl << "防御力:" << DEF2 << endl << endl;

				//player1の行動決定
				cout << "player1のターン" << endl;
				cout << "コマンドを入力してください" << endl;
				cout << "1:攻撃" << endl << "2:ためる" << endl << "3:守る" << endl;
				cin >> command;
				switch(command) {
				case 1:
					cout << player1.name << "は攻撃した！" << endl;
					damege = damegecf(ATK1, DEF2);
					if (damege > 0) {
						HP2 = HP2 - damege;
						cout << damege << "のダメージ" << endl;
					}
					else {
						HP2 = HP2 - 1;
						cout << 1 << "のダメージ" << endl;
					}
					break;

				case 2:
					cout << player1.name << "は攻撃の準備をしている" << endl;
					ATK1 = ATK1 * 1.5;
					break;

				case 3:
					cout << player1.name << "は攻撃を耐えようとしている" << endl;
					DEF1 = DEF1 + 10;
					break;

				default:
					cout << player1.name << "は命令をきかなかった" << endl;
					break;
				}

				//player2の行動決定
				cout << endl;
				cout << "player2のターン" << endl;
				command = distl(rnd);
				switch (command) {
				case 1:
					cout << player2.name << "は攻撃した!" << endl;
					damege = damegecf(ATK2, DEF1);
					if (damege > 0) {
						HP1 = HP1 - damege;
						cout << damege << "のダメージ" << endl;
					}
					else {
						HP1 = HP1 - 1;
						cout << 1 << "のダメージ" << endl;
					}
					break;

				case 2:
					cout << player2.name << "は攻撃の準備をしている" << endl;
					ATK2 = ATK2 * 1.5;
					break;

				case 3:
					cout << player2.name <<  "は攻撃を耐えようとしている" << endl;
					DEF2 = DEF2 + 10;
					break;
				}

				//HPの0か否かの判定
				HPcheck = HPcompare(HP1, HP2);
			}

			//戦闘終了
			cout << endl;
			if (HP1 > 0) {
				cout << player2.name << "が倒れた!" << endl;
				cout << "player1の" << player1.name << "の勝利!" << endl;
			}
			else {
				cout << player1.name << "が倒れた!" << endl;
				cout << "player2の" << player2.name << "の勝利, 残念！" << endl;
			}
			 
			break;

	    default:
			cout << "プログラム終了" << endl;
		    break;
	}
}
