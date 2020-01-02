#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> arr[9][9];

void addConfirm(int i, int j, int data);
pair<int, int> checkBound(int i, int j);
int myflag[9][9] = { 0 , };
int comfirm = 0;
int main() {
	
	// 9 x 9 배열만드는데
	// 각배열에는 1~9까지 담겨져있는 배열이있음
	string str;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int z = 0; z < 9; z++) {
				arr[i][j].push_back(z + 1);
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			myflag[i][j] = 0;
		}
	}
	/*for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << " [" << i << "][" << j << "] : {";
			for (const auto &x : arr[i][j]) {
				cout << " " << x << " ";
			}
			cout << "}" << endl;
		}
	}*/

	//for (int i = 0; i < 9; i++) {
	//	cin >> str;
	//	for (int j = 0; j < 9; j++) {
	//		if (str.at(j) != '0') {
	//			addConfirm(i, j, (int)str.at(j) - 48);
	//		}
	//	}
	//}
	int data;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> data;
			if (data != 0) {
				addConfirm(i, j, data);
			}
		}
	}
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;
	cout << " &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& " << endl;

	bool find = false;
	bool midAdd = false;
	pair<int, int> minIndex = { -1,-1 };
	while (comfirm < 81) {
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				if (myflag[row][col] == 0) {
					if (arr[row][col].size() == 1) {
						midAdd = true;
						minIndex = { row, col };
						cout << " !! size == 1인데 확정안된거 발견 : [ " << row << " ][ " << col << " ] 의 사이즈 : " << arr[row][col].size() << endl;
						break;
					}
					else {
						if (find == false) {
							minIndex = { row, col };
							find = true;
						}
						else {
							if (arr[minIndex.first][minIndex.second].size() > arr[row][col].size()) {
								minIndex = { row,col };
							}
						}
					}
				}
			}
			if (midAdd == true) {
				break;
			}
			else {
				continue;
			}
		}

		addConfirm(minIndex.first, minIndex.second, arr[minIndex.first][minIndex.second].at(0));
		find = false;
		midAdd = false;
		minIndex = { -1,-1 };
	}




	//while (comfirm < 81) {
	//	for (int row = 0; row < 9; row++) {
	//		for (int col = 0; col < 9; col++) {
	//			if (arr[row][col].size() == 1 && flag[row][col] == 0) {
	//				addConfirm(row, col, arr[row][col].at(0));
	//			}
	//		}
	//	}
	//}
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (arr[row][col].size() == 0) {
				cout << "* ";
			}
			else {
				cout << arr[row][col].at(0) << " ";
			}
		}
		cout << endl;
	}

	//cout << "comfimr : " << comfirm << endl;
	//for (int row = 0; row < 9; row++) {
	//	for (int col = 0; col < 9; col++) {
	//		cout << " [" << row << "][" << col << "] : {";
	//		for (const auto &x : arr[row][col]) {
	//			cout << " " << x << " ";
	//		}
	//		cout << "}" << endl;
	//	}
	//}
}

void addConfirm(int i, int j, int data) {
	
		//for (int row = 0; row < 9; row++) {
		//	for (int col = 0; col < 9; col++) {
		//		cout << "[" << row << "][" << col << "] : {";
		//		for (const auto &x : arr[row][col]) {
		//			cout << " " << x << " ";
		//		}
		//		cout << "}" << endl;
		//	}
		//}
		//cout << "Flag : ";
		//for (int row = 0; row < 9; row++) {
		//	for (int col = 0; col < 9; col++) {
		//		cout << flag[row][col] << " ";
		//	}
		//	cout << endl;
		//}
		arr[i][j].clear();
		arr[i][j].push_back(data);
		comfirm++;
		pair<int, int> start = checkBound(i, j);
		for (int row = start.first; row < start.first + 3; row++) {
			for (int col = start.second; col < start.second + 3; col++) {
				if (row != i && col != j) {
					int index = 0;
					for (const auto &x : arr[row][col]) {
						if (x == data) {
							arr[row][col].erase(arr[row][col].begin() + index);
							//if (arr[row][col].size() == 1 && flag[row][col] != 1)
							//	addConfirm(row, col, arr[row][col].at(0));
							break;
						}
						index++;
					}
				}
			}
		}
		for (int row = 0; row < 9; row++) {
			if (row != i) {
				int index = 0;
				for (const auto &x : arr[row][j]) {
					if (x == data) {
						arr[row][j].erase(arr[row][j].begin() + index);
						//if (arr[row][j].size() == 1 && flag[row][j] == 0)
						//	addConfirm(row, j, arr[row][j].at(0));
						break;
					}
					index++;
				}
			}
		}
		for (int col = 0; col < 9; col++) {
			if (col != j) {
				int index = 0;
				for (const auto &x : arr[i][col]) {
					if (x == data) {
						arr[i][col].erase(arr[i][col].begin() + index);
						//if (arr[i][col].size() == 1 && flag[i][col] == 0)
						//	addConfirm(i, col, arr[i][col].at(0));
						break;
					}
					index++;
				}
			}
		}
		cout << " ------------------------------- " << endl;
		cout << " 확정된곳 : [ " << i << " ][ " << j << " ]" << endl;
		cout << " com firm : " << comfirm << endl;
		cout << " ------------------------------- " << endl;
		myflag[i][j] = 1;
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				if (arr[row][col].size() == 0) {
					cout << "* ";
				}
				else if (arr[row][col].size() == 1 && myflag[row][col] == 1) {
					cout << arr[row][col].at(0) << " ";
				}
				else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
		cout << " ------------------------------- " << endl;
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				cout << " [" << row << "][" << col << "] : {";
				for (const auto &x : arr[row][col]) {
					cout << " " << x << " ";
				}
				cout << "}" << "\t\t\t\t\t\t|| myFlag : " << myflag[row][col] << "|| size :" << arr[row][col].size() << endl;
			}
		}
}

pair<int, int> checkBound(int i, int j) {
	if (i <= 2) {
		if (j <= 2) {
			return { 0,0 };
		}
		else if (j <= 5) {
			return  { 0,3 };
		}
		else if (j <= 8) {
			return  { 0,6 };
		}
	}
	else if (i <= 5) {
		if (j <= 2) {
			return  { 3,0 };
		}
		else if (j <= 5) {
			return  { 3,3 };
		}
		else if (j <= 8) {
			return  { 3,6 };
		}
	}
	else if (i <= 8) {
		if (j <= 2) {
			return { 6,0 };
		}
		else if (j <= 5) {
			return { 6,3 };
		}
		else if (j <= 8) {
			return { 6,6 };
		}
	}
}