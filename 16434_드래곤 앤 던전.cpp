#include <iostream>
#include <algorithm>
using namespace std;

class Room {
private:
	unsigned long long  info;
	unsigned long long  atk;
	unsigned long long  hp;
public:
	Room() {}
	Room(unsigned long long  info, unsigned long long  atk, unsigned long long  hp) {
		this->info = info;
		this->atk = atk;
		this->hp = hp;
	}
	unsigned long long  getInfo() {
		return this->info;
	}
	unsigned long long  getAtk() {
		return this->atk;
	}
	unsigned long long  getHp() {
		return this->hp;
	}
	void setHp(unsigned long long hp) {
		this->hp = hp;
	}
};

Room roomArr[123456];
Room originArr[123456];
unsigned long long H_maxHP, H_minHP, H_curHP, H_atk, middle, oirgin_atk, data1, data2, data3, N;
void setByOrigin();
unsigned long long countKill(unsigned long long, unsigned long long);
Room tempRoom;

int main() {
	// 방의 갯수와, 초기공격력 설정
	cin >> N >> oirgin_atk;

	// 던전의 정보 입력
	for (int i = 0; i < N; i++) {
		cin >> data1 >> data2 >> data3;
		tempRoom = Room(data1, data2, data3);
		originArr[i] = tempRoom;
	}

	H_maxHP = 1000000000000;
	H_minHP = 0;
	bool dead = false;
	while (H_minHP +1 < H_maxHP) {
		setByOrigin();
		middle = (H_maxHP + H_minHP) / 2;
		H_curHP = middle;
		dead = false;
		//cout << "-------------------------------" << endl;
		//cout << " MAX : " << H_maxHP << endl;
		//cout << " MIN : " << H_minHP << endl;
		//cout << " middle " << middle << endl;
		//cout << "-------------------------------" << endl;
 		for (int i = 0; i < N; i++) {
			if (roomArr[i].getInfo() == 1) {
				if (countKill(H_curHP, roomArr[i].getAtk()) >= countKill(roomArr[i].getHp(), H_atk)) {
					// 몬스터의 체력,공격력 용사의 체력,공격력을 비교하여 용사가 죽일수있다면, 용사의 체력 감소시킴.
					H_curHP -= max((unsigned long long)0, (countKill(roomArr[i].getHp(), H_atk) - 1)) * roomArr[i].getAtk();
				}
				else {
					// 죽일 수 없다면 용사는 죽음
					dead = true;
				}
				if (dead == true) {
					// 용사가 죽은경우 최소 MIN 값을 MIDDLE 값으로 바꿈
					H_minHP = middle;
					dead = false;
					break;
				}
			}
			else {
				// 물약방
				H_curHP = min(H_curHP + roomArr[i].getHp(), middle);
				H_atk = H_atk + roomArr[i].getAtk();
			}
			if (i + 1 == N) {
				// 끝방에 도달하였고, 공주를 구했을때 : MAX값을 MIDDLE값으로 바꿈
				H_maxHP = middle;
			}
		}
	}
	cout << middle << endl;
}
// 용사가 죽었을때 방의 정보와, 용사의 공격력을 초기화시킨다.
void setByOrigin() {
	for (int i = 0; i < N; i++) {
		roomArr[i] = originArr[i];
	}
	H_atk = oirgin_atk;
}

// 체력과 공격력을 비교하여 몇번공격해야 하는지를 리턴
unsigned long long countKill(unsigned long long health, unsigned long long attack) {
	if (health - attack <= 0) {
		return 1;
	}
	else {
		if (health % attack == 0) {
			return health / attack;
		}
		else {
			return health / attack + 1;
		}
	}
}