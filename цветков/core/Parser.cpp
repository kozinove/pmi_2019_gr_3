#include "Parser.h"
void Parser::showst(){

int g = 0;
for (int j = 0; j < Q; j++) {
	cout << s[j] << endl;

	}
}
void Parser::toList(CList L) {
	int i = Q;

	int x = 0, y = 0, z = 0;
	for (int j = 0; j < i; j++) {
		int g = 0;
		string stx = "";
		string sty = "";
		string stz = "";
		string sta = "";
		if ((s[j][g] < 48) && (s[j][g] > 57))
			throw - 1;
		
		
		
		
		
		while( ((s[j][g] != '*') && (s[j][g] != 'x'))) {

			sta += s[j][g];
			g++;
		}
		if (sta == "") { sta = '1'; }
		g = 0;
		while (s[j][g] != '\0') {

			if (s[j][g] == 'x') { 


				if (((s[j][g + 1] < 48) || (s[j][g + 1] > 57))&&(s[j][g + 1] != '^')) {
					stx += '1'; g++;
				continue; }
					


				if ((s[j][g + 2] >= 48) && (s[j][g + 2] <= 57)) {  
					 int t = 2;
					while ((s[j][g + t] > 48) && (s[j][g + t] < 57)) { 
						stx += s[j][g + t];
						t++; }

				}
				else throw - 1;

				
			}

			if (s[j][g] == 'y') {

				if ((s[j][g + 1]<48)|| (s[j][g + 1] > 57) && (s[j][g + 1] != '^')) {
					sty += '1'; g++;
					continue;
				}
				if ((s[j][g + 2] >= 48) && (s[j][g + 2] <= 57)) {
					int t = 2;
					while ((s[j][g + t] > 48) && (s[j][g + t] < 57)) {
						sty += s[j][g + t];
						t++;
					}

				}
				else throw - 1;


			}
			if (s[j][g] == 'z') {

				if ((s[j][g + 1] < 48) || (s[j][g + 1] > 57) && (s[j][g + 1] != '^')) {
					stz += '1'; g++;
					continue;
				}
				if ((s[j][g + 2] >= 48) && (s[j][g + 2] <= 57)) {
					int t = 2;
					while ((s[j][g + t] > 48) && (s[j][g + t] < 57)) {
						stz += s[j][g + t];
						t++;
					}

				}
				else throw - 1;


			}


			g++;
		}
		int a = atoi(sta.c_str());
		int x = atoi(stx.c_str());
		int y = atoi(sty.c_str());
		int z = atoi(stz.c_str());
		L.addF(a, x, y, z);

	}

}