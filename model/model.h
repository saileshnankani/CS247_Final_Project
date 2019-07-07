#include<vector>
#include "../locations/location.h"

// Model or one of these class's fields should observe if any Location's player's health is 0,
// Or one of these should inform the model the game is over.
class Model
{
private:
    bool isGameOver;
    std::vector<Location> locations;

    // Can also be an integer:
    Location *currentLocation; // As a pointer, is always valid since the 'locations' vector lives as long as the model

public:
    // ACCESSORS ==========================================================
    bool getIsGameOver();

    // OTHER MODEL OPERATIONS =============================================
    
    // Location state are the fields of Location.
    // The game 'iterates' by updating the state of the current location;
    // as iterations happen, the data in the current Location changes.
    void updateCurrentLocationState();
};