#include <iostream>
#include <list>

using namespace std;

class taxi {
private:
  string id; 
  string fio; 
  bool available;

public:
  bool operator == (const taxi& s) const { return id == s.id; } 
  bool operator != (const taxi& s) const { return !operator==(s); }
  taxi(string i, string f, bool a) {
    this->id = i;
    this->fio = f;
    this->available = a; 
  }

  void getInfo() {
    cout << "Гос номер такси: " << this->id << endl;
    cout << "ФИО водителя такси: " << this->fio << endl;
    cout << "Статус такси: " << ((this->available) ? "в парке" : "в поездке") << endl;
  }

  string getID() { return this->id; }

  bool getAvailability() { return this->available; }
  void setAvailability(bool a) { this->available = a; }
};



list<taxi> inPark;
list<taxi> inWorking;


int goToPark(string s) { 

  for (auto i : inWorking) {
    if (i.getID() == s) {
      if (i.getAvailability())
        return 0;

      i.setAvailability(1);
      inWorking.remove(i);
      inPark.push_back(i);

      return 1;
    }
  }
  return 0; 

}

int goToWorking(string s) { 

  for (auto i : inPark) {
    if (i.getID() == s) {
      if (!i.getAvailability())
        return 0; 

      i.setAvailability(0);
      inPark.remove(i);
      inWorking.push_back(i);

      return 1;
    }
  }
  return 0; 

}

void getInfo(string s) {
  for (auto i : inPark) {
    if (i.getID() == s) {
      i.getInfo();
      return;
    }
  }
  for (auto i : inWorking) {
    if (i.getID() == s) {
      i.getInfo();
      return;
    }
  }

  cout << "Такого авто НЕ существует!" << endl;
}

int main()
{
  setlocale(0, "ru");

  cout << "Сколько хотим заспавнить авто?: ";
  int c; 
  cin >> c;
  cout << endl;

  string id; string f; bool a;

  for (int i = 0; i != c; i++) {
    cout << "Введите номер авто: ";
    cin >> id;
    cout << "Введите Ф.И.О владельца авто: ";
    cin >> f;
    cout << "Находится ли авто на стоянке? (1/0): ";
    cin >> a;
    cout << endl << endl;

    if (a)
      inPark.push_back(taxi(id, f, a));
    else
      inWorking.push_back(taxi(id, f, a));
  }
  string s;
  bool choose;

X:
  cout << endl << endl;
  cout << "Какое такси ищем? (номер): ";
  cin >> s;

  cout << endl << endl;
  getInfo(s);

  cout << endl;
  cout << "Будем заказывать это такси?(1/0) : ";
  bool choose2;
  cin >> choose;
  cout << endl;
  if (!choose)
    goto X; 

  if (!goToWorking(s)) {
    cout << "Данный авто не находится на парковке! Нужно вернуть его в парк? (1/0): ";
    cin >> choose2;
    if (choose2) {
    goToPark(s);
    }
    goto X;
  }


  
  cout << "Работают: " << endl;
  for (auto i : inWorking)
    cout << i.getID() << endl;


  cout << endl << endl << endl;

  
  cout << "Ожидают: " << endl;
  for (auto i : inPark)
    cout << i.getID() << endl;

  goto X;
}