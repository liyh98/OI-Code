#include <bits/stdc++.h>
using namespace std;

string s;
string brand[6]={"xiaomi","vivo","oppo","huawei","apple","samsung"};
int main() {
	
	while (1) {
		getline(cin, s);
		int len=(int)s.length();
		if (s=="END") break;
		for (int i=0;i<len;i++) {
			if (s[i]>='A'&&s[i]<='Z') s[i]+='a'-'A';
		}
		bool mflag=0;
		for (int i=0;i<len;i++) {
			for (int j=1;j<6;j++) {
				bool flag=1;
				for (int k=0;k<(int)brand[j].length();k++) {
					if (s[i+k]!=brand[j][k]) {
						flag=0;
						break;
					}
				}
				if (flag) {
					mflag =1;
					break;
				}
			}
			if (mflag) break;
		}
		puts(mflag?"So Happy!":"So Sad!");
	}
	return 0;
}
