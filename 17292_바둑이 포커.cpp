#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<pair<int, char> > vec;
class Card {
public:
     int n1, n2, cond1, cond2, cond3, cond4;
     char c1, c2;

     Card(int n1, char c1, int n2, char c2) {
          this->n1 = n1;
          this->n2 = n2;
          this->c1 = c1;
          this->c2 = c2;
          this->cond1 = 0;
          this->cond2 = -1;
          this->cond3 = -1;
          this->cond4 = 0;

          if (this->c1 == this->c2) cond1 = 1;
          cond2 = max(this->n1, this->n2);
          cond3 = min(this->n1, this->n2);
          if (this->n1 > this->n2) {
               if (this->c1 == 'b')
                    this->cond4 = 1;
               else
                    this->cond4 = 0;
          }
          else {
               if (c2 == 'b')
                    this->cond4 = 1;

               else
                    this->cond4 = 0;
          }
     }

     Card() {}

     bool operator < (const Card & b) const {
          if (this->cond1 == b.cond1 && this->cond2 == b.cond2 && this->cond3 == b.cond3) {
               return this->cond4 > b.cond4;
          }
          else if (this->cond1 == b.cond1 && this->cond2 == b.cond2) {
               return this->cond3 > b.cond3;
          }
          else if (this->cond1 == b.cond1) {
               return this->cond2 > b.cond2;
          }
          else {
               return this->cond1 > b.cond1;
          }
     }
};

int main() {
     vector<Card> vec1;
     vector<Card> vec2;
     vector<Card> vec3;
     for (int i = 0; i < 6; i++) {
          char num_tmp;
          char color;
          char dump;
          cin >> num_tmp >> color;
          if (num_tmp == 'a') {
               vec.push_back({ 10,color });
          }
          else if (num_tmp == 'b') {
               vec.push_back({ 11,color });
          }
          else if (num_tmp == 'c') {
               vec.push_back({ 12,color });
          }
          else if (num_tmp == 'd') {
               vec.push_back({ 13,color });
          }
          else if (num_tmp == 'e') {
               vec.push_back({ 14,color });
          }
          else if (num_tmp == 'f') {
               vec.push_back({ 15,color });
          }
          else {
               int num = (int)num_tmp - '0';
               vec.push_back({ num,color });
          }
          if (i != 5) {
               cin >> dump;
          }
     }



     for (int i = 0; i < vec.size(); i++) {
          for (int j = i + 1; j < vec.size(); j++) {
               if (vec[i].first + 1 == vec[j].first) {
                    vec1.push_back(Card(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
               }
               else if (vec[j].first + 1 == vec[i].first) {
                    vec1.push_back(Card(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
               }
               else if (vec[j].first == 15 && vec[i].first == 1) {
                    vec1.push_back(Card(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
               }
               else if (vec[i].first == 15 && vec[j].first == 1) {
                    vec1.push_back(Card(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
               }
               else if (vec[i].first == vec[j].first) {
                    vec2.push_back(Card(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
               }
               else {
                    vec3.push_back(Card(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
               }
          }
     }



     std::sort(vec1.begin(), vec1.end());
     std::sort(vec2.begin(), vec2.end());
     std::sort(vec3.begin(), vec3.end());

     for (int i = 0; i < vec1.size(); i++)
          cout << hex << vec1[i].n1 << vec1[i].c1 << hex << vec1[i].n2 << vec1[i].c2 << "\n";

     for (int i = 0; i < vec2.size(); i++)
          cout << hex << vec2[i].n1 << vec2[i].c1 << hex << vec2[i].n2 << vec2[i].c2 << "\n";

     for (int i = 0; i < vec3.size(); i++)
          cout << hex << vec3[i].n1 << vec3[i].c1 << hex << vec3[i].n2 << vec3[i].c2 << "\n";

     return 0;

}