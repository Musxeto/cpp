/*     dtff, b/w Classes & Sturcturs:
Members of a class are private by default but 
 Members of structures are public by default
so there is a security difference between them*/












#include<iostream>
using namespace std;
struct character {
  int power_lvl;
  string attack_name;
};
int main() {
character goku;
goku.power_lvl = 90000;
goku.attack_name = "Ka Me Ha ME ha	";


cout << goku.power_lvl << "\n";
cout << goku.attack_name << "\n";

character eren;
eren.power_lvl = 567;
eren.attack_name = "Go2daMoon";


cout << eren.power_lvl << "\n";
cout << eren.attack_name << "\n";
return 0;
}
