/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Jayden                                           */
/*    Created:      Sat Jun 07 2025                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Motor4               motor         4               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor7               motor         7               
// Motor8               motor         8               
// Motor9               motor         9               
// Motor10              motor         10              
// Motor11              motor         11              
// Motor12              motor         12              
// Motor13              motor         13              
// Motor14              motor         14              
// Motor15              motor         15              
// Motor16              motor         16              
// Motor17              motor         17              
// Motor18              motor         18              
// Motor19              motor         19              
// Motor20              motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
 
#include "vex.h"
#include "ui.cpp"
#include "movement.cpp"

using namespace vex;
UserInterface ui;
MotorMovement move;

// global variables
int add = 0;
bool isReverse = 0;
int speed = 0; // units is rpm

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(1) {
    switch(ui.screenID) {
      case 0:
        // main menu
        ui.mainMenu();
        ui.mainMenuButton();
        break;
      case 1: 
        // motor temp screen
        ui.motorTemperatureViewer();
        ui.motorTemperatureViewerButton();
        break;
      case 2:
        // motor movement selector (and its related adversaries)
        ui.motorMovementSelectorButton();
        ui.motorMovementSelector();

        // collect the selected motors
        for (int i = 0; i < 20; i++) {
          if (ui.select[i]) {
            if (ui.selected[0] > 0) {
              if (ui.selected[1] > 0) {
                if (ui.selected[2] > 0) {
                  if (ui.selected[3] > 0) {
                    if (ui.selected[4] > 0) {
                      ui.selected[5] = i;
                    } else {
                      ui.selected[4] = i;
                    }
                  } else {
                    ui.selected[3] = i;
                  }
                } else {
                  ui.selected[2] = i;
                }
              } else {
                ui.selected[1] = i;
              }
            } else {
              ui.selected[0] = i;
            }
          }
        }

        // add up the total amount of motors selected
        for (int i = 0; i < 20; i++) {
          if (ui.select[i]) {
            add = add + 1;
          }
        }

        speed = ui.speed;

        // depending on the number of selected motors, use a corrolating function and move the selected motors
        switch(add) {
          case 1:
            move.singleMotorMovement(ui.selected[0], isReverse, speed);
            break;
          case 2:
            move.multiMotorMovement(ui.selected[0], ui.selected[1], isReverse, speed);
            break;
          case 3:
            move.multiMotorMovement(ui.selected[0], ui.selected[1], ui.selected[2], isReverse, speed);
            break;
          case 4:
            move.multiMotorMovement(ui.selected[0], ui.selected[1], ui.selected[2], ui.selected[3], isReverse, speed);
            break;
          case 5:
            move.multiMotorMovement(ui.selected[0], ui.selected[1], ui.selected[2], ui.selected[3], ui.selected[4], isReverse, speed);
            break;
          case 6:
            move.multiMotorMovement(ui.selected[0], ui.selected[1], ui.selected[2], ui.selected[3], ui.selected[4], ui.selected[5], isReverse, speed);
            break;
        }

        add = 0;
        for (int i = 0; i < 5; i++) {
          ui.selected[i] = 0;
        }
        break;
      case 3:
        // motor stats or diagnostics screen SELECTOR
        ui.motorDiagnosticsSelector();
        break;
      case 4:
        // motor stats or diagnostics screen VIEWER
        ui.motorDiagnosticsViewer();
        break;
    }

    wait(200, msec);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.setFillColor(black);
    Brain.Screen.setPenColor(white);
  }

  return 0;
}
