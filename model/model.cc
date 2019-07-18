#include "model.h"
#include "../view/standard.h"
#include "../controller/controller.h"
#include "../controller/action.h"
#include <vector>
#include <string>
#include <iostream>
#include "../characters/player_impl.h"
#include "../characters/interviewer.h"

using namespace std;

bool Model::getIsGameOver()
{
    return Player::isDead() || (Interviewer::Interview::getNumberOfInterviewsFailed() >= 1);
}

void Model::updateCurrentLocationState(Action a)
{
    currentLocation->updateState(a);
}

void Model::initializeLocations()
{
    vector<string> locationNames{"mc", "tatham", "california"};

    for (auto str : locationNames)
    {
        // shared_ptr for later
        Location *newLocation = new Location(str, *level);
        locations.push_back(newLocation);
        if (str == "mc")
        {
            currentLocation = newLocation;
        }
    }
}

void Model::initializeEasyLevel()
{
    level = make_unique<EasyLevel>();
}

void Model::initializeMediumLevel()
{
    level = make_unique<MediumLevel>();
}

void Model::initializeHardLevel()
{
    level = make_unique<HardLevel>();
}

void Model::initializeLevel(char levelChar)
{
    while (true)
    {
        switch (levelChar)
        {
        case 'E':
            initializeEasyLevel();
            return;
        case 'M':
            initializeMediumLevel();
            return;
        case 'H':
            initializeHardLevel();
            return;
        default:
            // TODO: change this to a proper output stream
            std::cout << "Invalid input. Please enter E, M, or H." << std::endl;
            cin >> levelChar;
        }
    }
}

//TODO: probably make it so that isGameOver can be set to false/true some time.
Model::Model()
{
}

Model::~Model() {}

void Model::addView(std::unique_ptr<View> v)
{
    views.emplace_back(std::move(v));
}

void Model::replaceView(std::unique_ptr<View> v)
{
    views.pop_back();
    views.emplace_back(std::move(v));
}

Location *Model::getCurrentLocation()
{
    return currentLocation;
}

void Model::displayViews()
{
    for (auto &view : views)
    {
        view->updateView();
    }
}

void Model::addController(std::unique_ptr<Controller> c)
{
    control = std::move(c);
}
bool Model::hasController()
{
    return control != nullptr;
}

Action Model::getAction()
{
    return control->getAction();
}

bool Model::getTeleportationStatus(Action a)
{
    return currentLocation->isNextTileTeleporter(a);
}

void Model::setNextLocation()
{
    if (currentLocation->getName() == "mc")
    {
        // go to tatham as our next location
        currentLocation = locations[1];
    }
    else
    {
        // go to california as our next location
        currentLocation = locations[2];
    }
}