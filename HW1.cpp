#include <iostream>
#include <string>
#include "cstdlib"
#include <stdio.h>


using namespace std;

short stringToArray(string t, int ar[]) {

	int i = 0;

	while (true) {
		if (t.length() == 4) {
			t = t.substr(1, 3);			
			ar[i] = atoi(t.c_str());
			i++;
			break;
			
		}
		else if (t.length() < 4) {
			ar[i] = atoi(t.c_str());
			i++;
			break;
		}
		else { //everything else
			string ttt = t.substr(t.length() - 3, 3);
			t = t.substr(0, t.length() - 4);
			ar[i] = atoi(ttt.c_str());
			i++;
		}
	}
	return i;
}

string padString(string s) {
	for (int i = s.length(); i < 3; i++) s = "0" + s;
	return s;
}

string bigAdd(string a1s, string a2s) {
	int a1[100], a2[100], a1c, a2c, c = 0, ct = 0, carry = 0;
	char buf[4] = "000";
	string t = "";

	a1c = stringToArray(a1s, a1);
	a2c = stringToArray(a2s, a2);
	

	while (true) {
		if ((c < a1c) && (c < a2c)) { //blocks from both
			ct = a1[c] + a2[c] + carry;
			if (ct >= 1000) {
				ct = ct - 1000;
				carry = 1;
			}
			else carry = 0;
			sprintf(buf, "%d", ct);
			t = padString(string(buf)) + t;
			c++;
			if ((c < a1c) || (c < a2c)) t = "," + t; //check if last, if not, add comma
		}
		else if (c < a1c) { //blocks just from a1c
			ct = a1[c] + carry;
			if (ct >= 1000) {
				ct -= 1000;
				carry = 1;
			}

			else carry = 0;
			sprintf(buf, "%d", ct);
			t = padString(string(buf)) + t;
			c++;
			if ((c < a1c) || (c < a2c)) t = "," + t; //check if last, if not, add comma
		}
		else if (c < a2c) { //blocks just from a1c
			ct = a2[c] + carry;
			if (ct >= 1000) {
				ct -= 1000;
				carry = 1;
			}
			else carry = 0;
			sprintf(buf, "%d", ct);
			t = padString(string(buf)) + t;
			c++;
			if ((c < a1c) || (c < a2c)) t = "," + t; //check if last, if not, add comma
		}
		else if (carry) {
			t = padString(string(buf));
			t = "1," + t;
			break;
		}
		else break;
	}
	while(t.substr(0,1).compare("0") == 0){
		t = t.substr(1,t.length() - 1);
	}

	return t;

}

int main() {
	string a1s, a2s;
	
	cout << "First number: ";
	cin >> a1s;

	cout << "Second number: ";
	cin >> a2s;

	
	cout << "The Sum is: "<<bigAdd(a1s, a2s) << endl;
	


	return 0;
}