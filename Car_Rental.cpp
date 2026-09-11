#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

int getValidInt(int minValue, int maxValue){
    int value;
    while(true){
        cin>>value;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Invalid input! Enter a number: "<<endl;
        }
        else if(value < minValue || value > maxValue){
            cout<<"Invalid input! Enter a value between"<<minValue<<"and"<<maxValue<<":";
        }
        else{
            return value;
        }
    }
}

float getValidFloat(){
    float value;
    while(true){
        cin >> value;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number: ";
        }
        else if(value <= 0){
            cout << "Invalid input! Value must be greater than 0: ";
        }
        else{
            return value;
        }
    }
}

bool validYear(string year){
    if(year.length() != 4){
        return false;
    }
    for(int i = 0; i < year.length(); i++){
        if(year[i] < '0' || year[i] > '9'){
            return false;
        }
    }
    int y = stoi(year);
    if(y < 1886 || y > 2026){
        return false;
    }

    return true;
}

bool validCNIC(string CNIC){
    if(CNIC.length() != 13){
        return false;
    }
    for(int i = 0; i < CNIC.length(); i++){
        if(CNIC[i] < '0' || CNIC[i] > '9'){
            return false;
        }
    }

    return true;
}

class Car{
private:
    string carID, company, model, year, color, numberPlate, type;
    float rentPerday;
    bool isAvailable = true;

public:
    Car(string carID, string company, string model, string year, string color, string numberPlate, string type, float rentPerday, bool isAvailable = true){
        
        this->carID = carID;
        this->company = company;
        this->model = model;
        this->year = year;
        this->color = color;
        this->numberPlate = numberPlate;
        this->type = type;
        this->rentPerday = rentPerday;
        this->isAvailable = isAvailable;
    }

    void displayCarInfo(){
        cout<<"\n";
        cout<<"CarID       : "<<carID<<endl
            <<"Company     : "<<company<<endl
            <<"Model       : "<<model<<endl
            <<"Model Year  : "<<year<<endl
            <<"Color       : "<<color<<endl
            <<"Number Plate: "<<numberPlate<<endl
            <<"Type        : "<<type<<endl
            <<"Rent        : "<<rentPerday<<endl;

        if(isAvailable == true){
            cout<<"Car is Available!"<<endl;
        }
        else{
            cout<<"Car is Rented!"<<endl;
        }
    }
    
    void markAsRented(){
        isAvailable = false;
        cout<<"The Car is Rented!"<<endl;
    }

    void markAvailable(){
        isAvailable = true;
        cout<<"\nThe Car is Available now"<<endl;
    }

    bool getAvailability(){
        return isAvailable;
    }

    string getCarID(){
        return carID;
    }

    float getRentPerDay(){
        return rentPerday;
    }

    string getCarCompany(){
        return company;
    }

    string getCarModel(){
        return model;
    }

    string getNumberPlate(){
        return numberPlate;
    }

    string getCarType(){
        return type;
    }
    string getCarColor(){
        return color;
    }
    string getModelYear(){
        return year;
    }
};


class Customer{
private:
    string customerID, name, CNIC;

public:
    Customer(string customerID, string name, string CNIC){
        this->customerID = customerID;
        this->name = name;
        this->CNIC = CNIC;
    }
    
    void displayCustomerInfo(){
        cout<<"\n";
        cout<<"Customer ID: "<<customerID<<endl
            <<"Name       : "<<name<<endl
            <<"CNIC       : "<<CNIC<<endl;
    }

    string getCustomerID(){
        return customerID;
    }

    string getCNIC(){
        return CNIC;
    }

    string getname(){
        return name;
    }
};


class Rental{
private:
    string rentalID, carID, customerID;
    float totalRent;
    int rentDays;

public:
    Rental(string carID, string customerID, string rentalID, int rentDays, float totalRent){ 
        this->rentalID = rentalID;
        this->rentDays = rentDays;
        this->carID = carID;
        this->customerID = customerID;
        this->totalRent = totalRent;
    }

    string getcustomerID(){
        return customerID;
    }
    string getrentalID(){
        return rentalID;
    }
    string getcarID(){
        return carID;
    }
    int getrentDays(){
        return rentDays;
    }
    float gettotalRent(){
        return totalRent;
    }

    void displayRentalInfo(){
        cout<<"\n\nRental ID:       "<<rentalID<<endl
            <<"Car ID:          "<<carID<<endl
            <<"Customer ID:     "<<customerID<<endl
            <<"Rental Days:     "<<rentDays<<endl
            <<"Total Rent:      "<<totalRent<<endl;
    }
};


class RentalSystem{
private:
    vector<Car> cars;
    vector<Customer> customers;
    vector<Rental> rentals;
    int nextRentalID = 101;

public:

    RentalSystem(){
        loadCars();
        loadCustomers();
        loadRentals();
    }
    
    void saveCars(){
        ofstream Writefile("cars.txt");
        for(int i=0; i<cars.size(); i++){
             Writefile<<cars[i].getCarID() << "|"
             <<cars[i].getCarCompany() << "|"
             <<cars[i].getCarModel() << "|"
             <<cars[i].getModelYear() << "|"
             <<cars[i].getCarColor() << "|"
             <<cars[i].getNumberPlate() << "|"
             <<cars[i].getCarType() << "|"
             <<cars[i].getRentPerDay() << "|"
             <<cars[i].getAvailability() << endl;
        }
    }

    void loadCars(){
      ifstream Readfile("cars.txt");
      if(!Readfile){
        return;
      }
      string carID, company, model, year, color, numberPlate, type;
      string rentPerDay, availability;

      while( getline(Readfile, carID, '|') ){
             getline(Readfile, company, '|');
             getline(Readfile, model, '|');
             getline(Readfile, year, '|');
             getline(Readfile, color, '|');
             getline(Readfile, numberPlate, '|');
             getline(Readfile, type, '|');
             getline(Readfile, rentPerDay, '|');
             getline(Readfile, availability);

            float rent = stof(rentPerDay);
            bool isAvailable = stoi(availability);

            Car C(carID, company, model, year, color, numberPlate, type, rent, isAvailable);
            cars.push_back(C);
      }
      Readfile.close();
    }
    
    void saveCustomers(){
        ofstream Writefile("customers.txt");
        for(int i=0; i<customers.size(); i++){
             Writefile<<customers[i].getCustomerID() << "|"
             <<customers[i].getname() << "|"
             <<customers[i].getCNIC() << "|" << endl;
        }
    }

    void loadCustomers(){
      ifstream Readfile("customers.txt");
      if(!Readfile){
        return;
      }
      string customerID, name, CNIC;
      while( getline(Readfile, customerID, '|') ){
             getline(Readfile, name, '|');
             getline(Readfile, CNIC, '|');

            Customer Cust(customerID, name, CNIC);
            customers.push_back(Cust);
      };
      Readfile.close();
    }

    void saveRentals(){
        ofstream Writefile("rentals.txt");
        for(int i=0; i<rentals.size(); i++){
             Writefile<<rentals[i].getcarID() << "|"
             <<rentals[i].getcustomerID() << "|"
             <<rentals[i].getrentalID() << "|"
             <<rentals[i].getrentDays() << "|"
             <<rentals[i].gettotalRent() << "|"<<endl;
        }
    }

    void loadRentals(){
    ifstream Readfile("rentals.txt");

    if(!Readfile){
        return;
    }
    string carID, customerID, rentalID, rentDays, totalRent;

    while(getline(Readfile, carID, '|')){
        getline(Readfile, customerID, '|');
        getline(Readfile, rentalID, '|');
        getline(Readfile, rentDays, '|');
        getline(Readfile, totalRent, '|');

        int days = stoi(rentDays);
        float total_Rent = stof(totalRent);

        Rental rental(carID, customerID, rentalID, days, total_Rent);
        rentals.push_back(rental);

        int ID = stoi(rentalID.substr(1));
        if(ID >= nextRentalID){
            nextRentalID = ID + 1;
        }
    }
    Readfile.close();
}    
    
    void addCar(){
      string carID, company, model, year, color, numberPlate, type;
      float rentPerDay;

      cout<<"Enter Car ID:           ";
      cin>>carID;

      bool duplicateID = false;
      for(int i=0; i<cars.size(); i++){
          if(carID == cars[i].getCarID()){
              duplicateID = true;
              break;
          }
      }

      while(duplicateID){
          cout<<"Car ID already exists! Enter a different Car ID: ";
          cin>>carID;

          duplicateID = false;
          for(int i=0; i<cars.size(); i++){
              if(carID == cars[i].getCarID()){
                  duplicateID = true;
                  break;
              }
          }
      }

      cout<<"Enter Car Company:      ";
      cin.ignore();
      getline(cin, company);
      cout<<"Enter Car Model:        ";
      cin.ignore();
      getline(cin, model);
      cout<<"Enter Car Model's Year: ";
      cin>>year;
      while(!validYear(year)){
          cout<<"Invalid year! Enter a 4-digit year between 1886 and 2026: ";
          cin>>year;
      }
      cout<<"Enter Car Color:        ";
      cin>>color;
      cout<<"Enter Car Number Plate: ";
      cin.ignore();
      getline(cin, numberPlate);

      bool duplicatePlate = false;
      for(int i=0; i<cars.size(); i++){
          if(numberPlate == cars[i].getNumberPlate()){
              duplicatePlate = true;
              break;
          }
      }

      while(duplicatePlate){
          cout<<"Number Plate already exists! Enter a different Number Plate: ";
          cin>>numberPlate;

          duplicatePlate = false;
          for(int i=0; i<cars.size(); i++){
              if(numberPlate == cars[i].getNumberPlate()){
                  duplicatePlate = true;
                  break;
              }
          }
      }

      cout<<"Enter Car Type:         ";
      cin>>type;
      cout<<"Enter Rent Per Day:     ";
      rentPerDay = getValidFloat();

      Car C(carID, company, model, year, color, numberPlate, type, rentPerDay);

      cars.push_back(C);   
      saveCars();   
      cout<<"\nCar Added Successfully!"<<endl<<endl;
    }
    
    void rentCar(){
        string rentingCustomer;
        cout<<"\nEnter Customer ID: ";
        cin>>rentingCustomer;
        bool found = false;

        for(int i=0; i<customers.size(); i++){
            if(rentingCustomer == customers[i].getCustomerID()){
                found = true;
                cout<<"Customer Details"<<endl;
                cout<<"-------------------------"<<endl<<endl;
                cout<<"Customer ID:        "<<customers[i].getCustomerID()<<endl
                    <<"Customer Name:      "<<customers[i].getname()<<endl
                    <<"Custome CNIC:       "<<customers[i].getCNIC()<<endl;
            }
        }
        if(found == false){
            cout<<"No Customer Found!"<<endl;
            return;
        }
        found = false;
        string CarID;
        cout<<"\nEnter Car ID: ";
        cin>>CarID;
        int rentdays;
        string rentalID;

        for(int i=0; i<cars.size(); i++){
            if(CarID == cars[i].getCarID()){
            found = true;
            if(cars[i].getAvailability()){
                rentalID = "R" + to_string(nextRentalID);

                cout<<"Enter Number of Rental Days: ";
                rentdays = getValidInt(1, 2147483647);

                float totalRent = cars[i].getRentPerDay()*rentdays;

                Rental rental(CarID, rentingCustomer, rentalID, rentdays, totalRent);
                rentals.push_back(rental);

                nextRentalID++;
                saveRentals();
                cars[i].markAsRented();
                saveCars();
                cout<<"\nRental ID: "<<rentalID<<endl;
            }
            
            else{
                cout<<"Car is Already Rented!"<<endl;
            }
        }
    }

        if(found == false){
            cout << "Car Not Found!" << endl;
        }
    }  

    void returnCar(){
        string rentalID;
        cout<<"\nEnter Rental ID: ";
        cin>>rentalID;

        bool found = false;

        for(int i=0; i<rentals.size(); i++){
            if(rentalID == rentals[i].getrentalID()){

                found = true;
                if(!cars[i].getAvailability()){
                    cout<<"Car Returned Successfully!";
                    cars[i].markAvailable();
                    saveCars();
                } 
                else{
                    cout<<"Car is Already Available!"<<endl;
                }
            }
        }
        if(found == false){
                cout << "Car Not Found!" << endl;
        }
    }

    void displayRental(){
    
    if(rentals.empty()){
    cout << "No Rental Found!" << endl;
    return;
    }

    string todisplayrental;
    cout<<"Enter Rental ID: ";
    cin>>todisplayrental;
    
    bool found = false;

    for(int i=0; i<rentals.size(); i++){
        if(todisplayrental == rentals[i].getrentalID()){
           found = true;
            cout << "\n\n====================================";
            cout << "\n           RENTAL SLIP";
            cout << "\n====================================";

            cout << "\n\nRental ID:        " << rentals[i].getrentalID();
            cout << "\nRental Days:      " << rentals[i].getrentDays();
            cout << "\nTotal Rent:       " << rentals[i].gettotalRent();

            for(int j=0; j<customers.size(); j++){
              if(rentals[i].getcustomerID() == customers[j].getCustomerID()){
                cout << "\n\n-------- CUSTOMER DETAILS --------";
                cout << "\nCustomer ID:      " << customers[j].getCustomerID();
                cout << "\nName:             " << customers[j].getname();
                cout << "\nCNIC:             " << customers[j].getCNIC();
            }
        }

            for(int j=0; j<cars.size(); j++){
              if(rentals[i].getcarID() == cars[j].getCarID()){
                cout << "\n\n----------- CAR DETAILS -----------";
                cout << "\nCar ID:           " << cars[j].getCarID();
                cout << "\nCompany:          " << cars[j].getCarCompany();
                cout << "\nModel:            " << cars[j].getCarModel();
                cout << "\nNumber Plate:     " << cars[j].getNumberPlate();
            }
        }
        cout << "\n\n====================================\n";
        }
    }
    if(found == false){
        cout<<"\nRental not Found!"<<endl;
    }
}
    
    void displayCars(){

    if(cars.empty()){
        cout<<"No Cars Found!"<<endl;
        return;
    }

    cout << "\n";
    cout << "============================================================================================================\n";
    cout << left
         << setw(8)  << "Car ID"
         << setw(12) << "Company"
         << setw(15) << "Model"
         << setw(8)  << "Year"
         << setw(12) << "Color"
         << setw(15) << "Number Plate"
         << setw(12) << "Type"
         << setw(12) << "Rent/Day"
         << setw(12) << "Status"
         << "\n";
    cout << "============================================================================================================\n";

    for(int i=0; i<cars.size(); i++){

        cout << left
             << setw(8)  << cars[i].getCarID()
             << setw(12) << cars[i].getCarCompany()
             << setw(15) << cars[i].getCarModel()
             << setw(8)  << cars[i].getModelYear()
             << setw(12) << cars[i].getCarColor()
             << setw(15) << cars[i].getNumberPlate()
             << setw(12) << cars[i].getCarType()
             << setw(12) << cars[i].getRentPerDay()
             << setw(12) << (cars[i].getAvailability() ? "Available" : "Rented")
             << "\n";
    }

    cout << "============================================================================================================\n";
}

    void searchCar(){

    string type;
    cout<<"\nEnter Car Type: ";
    cin>>type;

    bool found = false;

    cout << "\n";
    cout << "================================================================================\n";
    cout << left
         << setw(10) << "Car ID"
         << setw(15) << "Company"
         << setw(15) << "Model"
         << setw(12) << "Year"
         << setw(15) << "Number Plate"
         << setw(12) << "Rent/Day"<<endl;
    cout << "================================================================================\n";

    for(int i=0; i<cars.size(); i++){
        if(type == cars[i].getCarType() && cars[i].getAvailability()){
            found = true;
            cout << left
                 <<setw(10)<<cars[i].getCarID()
                 <<setw(15)<<cars[i].getCarCompany()
                 <<setw(15)<<cars[i].getCarModel()
                 <<setw(12)<<cars[i].getModelYear()
                 <<setw(15)<<cars[i].getNumberPlate()
                 <<setw(12)<<cars[i].getRentPerDay()<<endl;
        }
    }
    cout << "================================================================================\n";
    if(found == false){
        cout<<"No "<<type<<" Found!"<<endl;
    }
} 

    void addCustomer(){
        string customerID, name, CNIC;
        cout<<"Enter Customer ID:        ";
        cin>>customerID;

        bool duplicateID = false;
        for(int i=0; i<customers.size(); i++){
            if(customerID == customers[i].getCustomerID()){
                duplicateID = true;
                break;
            }
        }
        while(duplicateID){
            cout<<"Customer ID already exists! Enter a different Customer ID: ";
            getline(cin, customerID);

            duplicateID = false;
            for(int i=0; i<customers.size(); i++){
                if(customerID == customers[i].getCustomerID()){
                    duplicateID = true;
                    break;
                }
            }
        }
        cout<<"Enter Customer Name:      ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Customer CNIC:      ";
        cin>>CNIC;

        while(!validCNIC(CNIC)){
            cout<<"Invalid CNIC! Enter exactly 13 digits: ";
            cin>>CNIC;
        }
        bool duplicateCNIC = false;
        for(int i=0; i<customers.size(); i++){
            if(CNIC == customers[i].getCNIC()){
                duplicateCNIC = true;
                break;
            }
        }
        while(duplicateCNIC){
            cout<<"CNIC already exists! Enter a different CNIC: ";
            cin>>CNIC;
            while(!validCNIC(CNIC)){
                cout<<"Invalid CNIC! Enter exactly 13 digits: ";
                cin>>CNIC;
            }

            duplicateCNIC = false;
            for(int i=0; i<customers.size(); i++){
                if(CNIC == customers[i].getCNIC()){
                    duplicateCNIC = true;
                    break;
                }
            }
        }
        Customer Cust(customerID, name, CNIC);
        customers.push_back(Cust);      
        saveCustomers();
        cout<<"\nCustomer Added Successfully!"<<endl<<endl;
    }

    void displayCustomers(){
    if(customers.empty()){
        cout<<"No Customers Found!"<<endl;
        return;
    }
    cout<<"\n======================================================\n";
    cout<<left
         <<setw(15) << "Customer ID"
         <<setw(25) << "Name"
         <<setw(20) << "CNIC"<<endl;
    cout<<"======================================================\n";
    for(int i=0; i<customers.size(); i++){
        cout<<left
            <<setw(15) << customers[i].getCustomerID()
            <<setw(25) << customers[i].getname()
            <<setw(20) << customers[i].getCNIC()<<endl;
    }
    cout << "======================================================\n";
}

    void searchCustomer(){
        string CNIC;
        cout<<"\nEnter Customer CNIC: ";
        cin>>CNIC;
        while(!validCNIC(CNIC)){
            cout<<"Invalid CNIC! Enter exactly 13 digits: ";
            cin>>CNIC;
        }

        bool found = false;

        for(int i=0; i<customers.size(); i++){
            if(CNIC == customers[i].getCNIC()){

                found = true;
                cout<<"\nCustomer Details"<<endl<<endl;
                cout<<"-------------------------";

                cout<<"\nCustomer ID:        "<<customers[i].getCustomerID()<<endl
                    <<"Customer Name:      "<<customers[i].getname()<<endl
                    <<"Custome CNIC:       "<<customers[i].getCNIC()<<endl;
            }
        }
        if(found == false){
            cout<<"No Customer Found!"<<endl;
        }
    }
};


int main(){
   int choice;
   RentalSystem R;
   
   cout<<"========== CAR RENTAL SYSTEM =========="<<endl<<endl;
   do{
   cout<<"\n===== Main Menu ====="<<endl;
   cout<< "1. Add Car"<<endl
       << "2. Display All Cars"<<endl
       << "3. Search Available Car"<<endl
       << "4. Add Customer"<<endl
       << "5. Display All Customers"<<endl
       << "6. Search Customer"<<endl
       << "7. Rent a Car"<<endl
       << "8. Return a Car"<<endl
       << "9. Display Rental Slip"<<endl
       << "10. Exit"<<endl<<endl;
    
   cout<<"Enter your Choice: ";
   choice = getValidInt(1, 10);

    switch (choice){
    case 1:
        R.addCar();
        break;
    case 2:
        R.displayCars();
        break;
    case 3:
        R.searchCar();
        break;
    case 4:
        R.addCustomer();
        break;
    case 5:
        R.displayCustomers();
        break;
    case 6:
        R.searchCustomer();
        break;
    case 7:
        R.rentCar();
        break;
    case 8:
        R.returnCar();
        break;
    case 9:
        R.displayRental();
        break;
    case 10:
        cout<<"Exiting Car Rental System.....";
        break;
    default:
        cout<<"\nEnter Valid Input!"<<endl;
        break;
    }
}while(choice!=10);

}