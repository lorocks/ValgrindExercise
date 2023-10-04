#include <iostream>
#include <AnalogSensor.hpp>

int main()
{
    AnalogSensor lightSensor(5);
    std::cout << "Averaged sensor reading: " << lightSensor.Read() << std::endl;

    // The terminator variable is assigned a value to remove a conditional jump on unassigned value
    bool terminator = true;
    
    if( terminator )
    {
        std::cout << "DONE" << std::endl;
    }
    return 0;
}
