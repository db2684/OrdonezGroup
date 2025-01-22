#include <iostream>

#include "G4RunManager"
#include "G4UImanager"
#include "G4VisManager"
#include "G4VisExecutive"
#include "G4UIExecutive"


#include "construction.hh"
#include "Physics.hh"

int main(int argc, char** argv)
{
    G4Runmanager *runManager = new G4RunManager

    runManager->SetUserInitailization(new MyDetectorConstruction());
    runManager->SetUserInitailization(new MyPhysicsList());
    runManager->SetUserInitailization(new MyActionInitialization());


    runManager->Initailize();

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    visManager->Initialize();

    G4UImanager *UImanager =G4UImanager::GetUIpointer();

    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true")
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");

    ui->SessionStart();

    return 0;

}
