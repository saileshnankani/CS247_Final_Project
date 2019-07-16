#ifndef MODEL_H_
#define MODEL_H_

#include <vector>
#include <string>
#include <memory>
#include "../locations/location.h"
#include "../view/view.h"
#include "../characters/levels/level.h"
#include "../characters/levels/easyLevel.h"
#include "../characters/levels/mediumLevel.h"
#include "../characters/levels/hardLevel.h"
#include "../controller/controller.h"
#include "../controller/action.h"

// Model or one of these class's fields should observe if any Location's player's health is 0,
// Or one of these should inform the model the game is over.
class Model
{
private:
    bool isGameOver;
    std::vector<Location*> locations;
    std::vector<std::string> locationNames;
    Location *currentLocation;
    std::unique_ptr<Level> level;
    std::vector<std::unique_ptr<View>> views;
    std::unique_ptr<Controller> control; 

public:
    bool getIsGameOver();
    Model();
    
    // Location state are the fields of Location.
    // The game 'iterates' by updating the state of the current location;
    // as iterations happen, the data in the current Location changes.
    void updateCurrentLocationState(Action a);
  
    void initializeLocations();

    void initializeEasyLevel();
    void initializeMediumLevel();
    void initializeHardLevel();
    void initializeLevel(char levelChar);

    void addView(std::unique_ptr<View> v);
    void replaceView(std::unique_ptr<View> v);
    void addController(std::unique_ptr<Controller> v);
    bool hasController();
    Action getAction();
    
    Location* getCurrentLocation();
    void setNextLocation();
    void displayViews();
    bool getTeleportationStatus(Action a);
    bool staticNcurses = false;
    bool staticGraphic = false;
};

#endif