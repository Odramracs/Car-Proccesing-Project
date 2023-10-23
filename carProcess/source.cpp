//-----------------------------------------
#include "linkedList.h" //This is the linkedList class
#include "fstream"
//-----------------------------------------
using namespace std;  //Define the namespace.

int car::CERTIFIED_counter = 0;
int car::NEW_counter = 0;
int car::USED_counter = 0;

int main() {
  //A list to maintain only the cars of an specific status in the db
  linkedList* carList = new linkedList();

  int status_of_interest;//USED = 10, NEW = 20, CERTIFIED = 30
  cin >> status_of_interest;

  char helper[1000];
  cin.getline(helper, sizeof(helper));//clear the input buffer;

  //Read the input file with only the cars matching the status_of_interest
  int N = carList->readCarsDB("cars_db2.txt", (STATUS)status_of_interest);
  //If there is an error or the file is empty
  if (N <= 0)
      return N;

  //Cout the number of cars in the input file matching the status_of_interest
  cout <<"There are " << N << " of STATUS " << status_of_interest <<  endl;

  //Read the model name
  char carModelCString[1000];
  cin.getline(carModelCString, sizeof(carModelCString));

  node* car_model = carList->findNodeByModel(carModelCString);
  if (car_model != nullptr) {
      car_model->print();
      carList->removeNode(car_model);
  }

  int year_of_interest;
  cin >> year_of_interest;
  carList->printByYear(year_of_interest);

  cout << "Now there are " << carList->size() << " of STATUS " << status_of_interest << endl;

  return 0;
}