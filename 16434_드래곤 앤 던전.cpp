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
	// ���� ������, �ʱ���ݷ� ����
	cin >> N >> oirgin_atk;

	// ������ ���� �Է�
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
					// ������ ü��,���ݷ� ����� ü��,���ݷ��� ���Ͽ� ��簡 ���ϼ��ִٸ�, ����� ü�� ���ҽ�Ŵ.
					H_curHP -= max((unsigned long long)0, (countKill(roomArr[i].getHp(), H_atk) - 1)) * roomArr[i].getAtk();
				}
				else {
					// ���� �� ���ٸ� ���� ����
					dead = true;
				}
				if (dead == true) {
					// ��簡 ������� �ּ� MIN ���� MIDDLE ������ �ٲ�
					H_minHP = middle;
					dead = false;
					break;
				}
			}
			else {
				// �����
				H_curHP = min(H_curHP + roomArr[i].getHp(), middle);
				H_atk = H_atk + roomArr[i].getAtk();
			}
			if (i + 1 == N) {
				// ���濡 �����Ͽ���, ���ָ� �������� : MAX���� MIDDLE������ �ٲ�
				H_maxHP = middle;
			}
		}
	}
	cout << middle << endl;
}
// ��簡 �׾����� ���� ������, ����� ���ݷ��� �ʱ�ȭ��Ų��.
void setByOrigin() {
	for (int i = 0; i < N; i++) {
		roomArr[i] = originArr[i];
	}
	H_atk = oirgin_atk;
}

// ü�°� ���ݷ��� ���Ͽ� ��������ؾ� �ϴ����� ����
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