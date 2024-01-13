//g++ 5_task.cpp -o 5_task
//Metelkin Maksim -> V = (int('E') + int('A')) % 8 -> 6 "FlyingObject"

#include <iostream>
#include <string>
using namespace std;


class FlyingObject 
{
private:
    string name;
    double speed;
    static int flyingObjectsCount;

public:
    FlyingObject(const string& name, double speed) : name(name), speed(speed) {
        flyingObjectsCount++;
    }

    static int getFlyingObjectsCount()
    {
        return flyingObjectsCount;
    }

    const string& getName() const {
        return name;
    }

    double getSpeed() const {
        return speed;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setSpeed(double newSpeed) {
        speed = newSpeed;
    }

    virtual void takeOff() const {
        cout << getName() << " is taking off." << endl;
    }

    virtual void fly() const {
        cout << getName() << " is flying at a speed of " << getSpeed() << " units." << endl;
    }

    virtual void land() const {
        cout << getName() << " is landing." << endl;
    }

    virtual void displayInfo() const {
        cout << "FlyingObject: " << getName() << ", Speed: " << getSpeed() << endl;
    }
};

int FlyingObject::flyingObjectsCount = 0;

class Airplane : public FlyingObject {
public:

    Airplane(const string& name, double speed) : FlyingObject(name, speed) {}

    void takeOff() const override {
        cout << getName() << " is taking off like an airplane." << endl;
    }

    void fly() const override {
        cout << getName() << " is flying in the sky like an airplane." << endl;
    }

    void land() const override {
        cout << getName() << " is landing like an airplane." << endl;
    }

    static int getMaxPassengerCapacity() {
        return 300;
    }

    void displayInfo() const override {
        cout << "Airplane: " << getName() << ", Speed: " << getSpeed() << ", Max Passenger Capacity: " << getMaxPassengerCapacity() << endl;
    }
};

class PassengerPlane : public Airplane {
public:
    PassengerPlane(const string& name, double speed) : Airplane(name, speed) {}

    static int getMaxPassengerCapacity() {
        return 500;
    }

    void displayInfo() const override {
        cout << "PassengerPlane: " << getName() << ", Speed: " << getSpeed() << ", Max Passenger Capacity: " << getMaxPassengerCapacity() << endl;
    }
};

class FighterJet : public Airplane {
public:
    FighterJet(const string& name, double speed) : Airplane(name, speed) {}

    static int getMaxSpeed() {
        return 2000;
    }

    void displayInfo() const override {
        cout << "FighterJet: " << getName() << ", Speed: " << getSpeed() << ", Max Speed: " << getMaxSpeed() << endl;
    }
};

class CargoPlane : public Airplane {
public:
    CargoPlane(const string& name, double speed) : Airplane(name, speed) {}

    static double getMaxCargoCapacity() {
        return 5000.0;
    }

    void displayInfo() const override {
        cout << "CargoPlane: " << getName() << ", Speed: " << getSpeed() << ", Max Cargo Capacity: " << getMaxCargoCapacity() << endl;
    }
};

Airplane* findFastestAirplane(const vector<FlyingObject*>& flyingObjects) {
    Airplane* fastestAirplane = nullptr;
    double maxSpeed = 0.0;

    for (const auto& obj : flyingObjects) {
        Airplane* airplane = dynamic_cast<Airplane*>(obj);
        if (airplane && airplane->getSpeed() > maxSpeed) {
            maxSpeed = airplane->getSpeed();
            fastestAirplane = airplane;
        }
    }

    return fastestAirplane;
}

int main() {
    vector<FlyingObject*> flyingObjects;

    int numObjects;
    cout << "Enter the number of flying objects: ";
    cin >> numObjects;

    for (int i = 0; i < numObjects; ++i) {
        string objectName;
        double objectSpeed;

        cout << "Enter the name of flying object " << i + 1 << ": ";
        cin >> objectName;

        cout << "Enter the speed of flying object " << i + 1 << ": ";
        cin >> objectSpeed;

        int objectType;
        cout << "Select the type of flying object (1 - PassengerPlane, 2 - FighterJet, 3 - CargoPlane): ";
        cin >> objectType;

        FlyingObject* newObject = nullptr;

        switch (objectType) {
            case 1:
                newObject = new PassengerPlane(objectName, objectSpeed);
                break;
            case 2:
                newObject = new FighterJet(objectName, objectSpeed);
                break;
            case 3:
                newObject = new CargoPlane(objectName, objectSpeed);
                break;
            default:
                cout << "Invalid object type. Creating a default FlyingObject." << endl;
                newObject = new FlyingObject(objectName, objectSpeed);
                break;
        }

        flyingObjects.push_back(newObject);
    }

    int passengerPlaneCount = 0;
    int fighterJetCount = 0;
    int cargoPlaneCount = 0;

    cout << endl << endl;

    for (const auto& obj : flyingObjects) {
        if (dynamic_cast<PassengerPlane*>(obj) != nullptr) {
            passengerPlaneCount++;
        }

        if (dynamic_cast<FighterJet*>(obj) != nullptr) {
            fighterJetCount++;
        }

        if (dynamic_cast<CargoPlane*>(obj) != nullptr) {
            cargoPlaneCount++;
        }

        obj->displayInfo();
    }

    cout << endl << endl;
    
    cout << "Number of FlyingObjects: " << FlyingObject::getFlyingObjectsCount() << endl;
    cout << "\tNumber of PassengerPlanes: " << passengerPlaneCount << endl;
    cout << "\tNumber of FighterJets: " << fighterJetCount << endl;
    cout << "\tNumber of CargoPlanes: " << cargoPlaneCount << endl;

    Airplane* fastestAirplane = findFastestAirplane(flyingObjects);

    if (fastestAirplane != nullptr) {
        cout << "\nFastest Airplane:\n";
        fastestAirplane->displayInfo();
    } else {
        cout << "\nNo Airplane found.\n";
    }

    for (auto obj : flyingObjects) {
        delete obj;
    }

    return 0;
}