#include <iostream>
#include <string>
#include <vector>

// Base Parent Class
class SmartDevice {
protected:
    std::string deviceName;

public:
    SmartDevice(std::string name) : deviceName(name) {}
    
    // Virtual function to enable runtime polymorphism
    virtual void performAction() {
        std::cout << deviceName << " is processing a generic command." << std::endl;
    }
    
    // Virtual destructor for safe memory cleanup
    virtual ~SmartDevice() {}
};

// Derived Class 1: Overrides performAction
class SmartLight : public SmartDevice {
public:
    SmartLight(std::string name) : SmartDevice(name) {}
    
    void performAction() override {
        std::cout << "[Light Control]: " << deviceName << " is turning ON and setting brightness to 80%." << std::endl;
    }
};

// Derived Class 2: Overrides performAction
class SmartThermostat : public SmartDevice {
public:
    SmartThermostat(std::string name) : SmartDevice(name) {}
    
    void performAction() override {
        std::cout << "[Climate Control]: " << deviceName << " is adjusting temperature to 22°C." << std::endl;
    }
};

int main() {
    std::cout << "--- Runtime Polymorphism Demonstration ---" << std::endl;
    
    // Create base class pointers pointing to derived class objects
    SmartDevice* light = new SmartLight("Living Room Bulb");
    SmartDevice* thermostat = new SmartThermostat("Nest Thermostat");
    
    // Demonstrate polymorphism using base class pointer execution
    std::cout << "\nExecuting commands via Base Class Pointers:" << std::endl;
    light->performAction();       // Calls SmartLight's overridden function
    thermostat->performAction();  // Calls SmartThermostat's overridden function
    
    // Clean up dynamic memory
    delete light;
    delete thermostat;
    
    return 0;
}
