#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> vec[2018];

int main() {
	vec[1967].push_back("DavidBowie");
	vec[1969].push_back("SpaceOddity");
	vec[1970].push_back("TheManWhoSoldTheWorld");
	vec[1971].push_back("HunkyDory");
	vec[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	vec[1973].push_back("AladdinSane");
	vec[1973].push_back("PinUps");
	vec[1974].push_back("DiamondDogs");
	vec[1975].push_back("YoungAmericans");
	vec[1976].push_back("StationToStation");
	vec[1977].push_back("Low");
	vec[1977].push_back("Heroes");
	vec[1979].push_back("Lodger");
	vec[1980].push_back("ScaryMonstersAndSuperCreeps");
	vec[1983].push_back("LetsDance");
	vec[1984].push_back("Tonight");
	vec[1987].push_back("NeverLetMeDown");
	vec[1993].push_back("BlackTieWhiteNoise");
	vec[1995].push_back("1.Outside");
	vec[1997].push_back("Earthling");
	vec[1999].push_back("Hours");
	vec[2002].push_back("Heathen");
	vec[2003].push_back("Reality");
	vec[2013].push_back("TheNextDay");
	vec[2016].push_back("BlackStar");

	int N;
	cin >> N;
	int cnt;
	int a, b;
	bool nothing;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		nothing = true;
		cnt = 0;
		for (int i = a; i <= b; i++) {
			cnt += vec[i].size();
		}
		cout << cnt << "\n";
		for (int i = a; i <= b; i++) {
			for (const auto & x : vec[i]) {
				cout << i << " " << x << "\n";
				nothing = false;
			}
		}
	
		
	}
}