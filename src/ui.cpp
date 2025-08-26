#include "vex.h"
#include "robot-config.h"

using namespace vex;

class UserInterface {
public:
  // screen variables
  int screenID = 0;
  int lastPressed[2] = 0;

  // arrays
  bool select[20] = { 0 };
  int temps[20] = { 0 };
  int selected[6] = { 0 };

  // other variables
  uint8_1 autoID = 0;
  bool multi = false;
  int Y1 = 30;
  int Y2 = 150;
  int x = 40;
  int y = 85;
  int N1 = 30;
  int N2 = 115;
  int N3 = 150;
  int N4 = 235;
  int e = 10;
  int a = 50;
  int motorID = 0;

  /*
  screen printing
  order:
  0: main menu
  1: motor temperature viewer
  2: motor movement selector (single or multi motor mode)
  3: motor diagnostics
  4: settings menu
  */

  // universial functions
  void checkLastPressed() {
    if (Brain.Screen.pressing()) {
      lastPressed[0] = Brain.Screen.xPosition();
      lastPressed[1] = Brain.Screen.yPosition();
    } else {
      lastPressed[0] = 0;
      lastPressed[1] = 0;
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // screen 0
  void mainMenu() {
    Brain.Screen.printAt(175, 30, "M0T0R INTERACT");
    Brain.Screen.printAt(0, 230, "v0.0.7, Build 215");
    Brain.Screen.drawRectangle(50, 50, 170, 50);
    Brain.Screen.drawRectangle(250, 50, 170, 50);
    Brain.Screen.drawRectangle(50, 150, 170, 50);
    Brain.Screen.drawRectangle(250, 150, 170, 50);
    Brain.Screen.printAt(80, 80, "Temp Viewer");
    Brain.Screen.printAt(260, 80, "Movement Select");
    Brain.Screen.printAt(80, 180, "Diagnostics");
    Brain.Screen.printAt(290, 180, "Auto Select");
  }

  // screen 0 buttons
  void mainMenuButton() {
    checkLastpressed();
    
    if ((xPressed >= 50 && xPressed <= 220) && (yPressed >= 50 && yPressed <= 100))
      screenID = 1;
    if ((xPressed >= 250 && xPressed <= 420) && (yPressed >= 50 && yPressed <= 100))
      screenID = 2;
    if ((xPressed >= 50 && xPressed <= 200) && (yPressed >= 150 && yPressed <= 200))
      screenID = 3;
    if ((xPressed >= 250 && xPressed <= 420) && (yPressed >= 150 && yPressed <= 200))
      screenID = 5;
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // screen 1
  void motorTemperatureViewer() {
    setTemps();
    Brain.Screen.print("Temperature Viewer");
    for (int i = 0; i < 21; i++) {
      setColor(temps[i]);
      printBox(i);
    }
  }

  // screen 1 buttons
  void motorTemperatureViewerButton() {
    if (Brain.Screen.pressing())
      screenID = 0;
  }

  // get temps from the motors
  void setTemps() {
    temps[0] = Motor1.temperature(celsius);
    temps[1] = Motor2.temperature(celsius);
    temps[2] = Motor3.temperature(celsius);
    temps[3] = Motor4.temperature(celsius);
    temps[4] = Motor5.temperature(celsius);
    temps[5] = Motor6.temperature(celsius);
    temps[6] = Motor7.temperature(celsius);
    temps[7] = Motor8.temperature(celsius);
    temps[8] = Motor9.temperature(celsius);
    temps[9] = Motor10.temperature(celsius);
    temps[10] = Motor11.temperature(celsius);
    temps[11] = Motor12.temperature(celsius);
    temps[12] = Motor13.temperature(celsius);
    temps[13] = Motor14.temperature(celsius);
    temps[14] = Motor15.temperature(celsius);
    temps[15] = Motor16.temperature(celsius);
    temps[16] = Motor17.temperature(celsius);
    temps[17] = Motor18.temperature(celsius);
    temps[18] = Motor19.temperature(celsius);
    temps[19] = Motor20.temperature(celsius);
  }
  
  // pen recolor by temps
  // @param temp - the recorded temperature of a motor
  void setColor(int temp) {
    if (temp > 0 && temp <= 9) {
      Brain.Screen.setFillColor("#231a9c");
    } else if (temp >= 10 && temp <= 19) {
      Brain.Screen.setFillColor(blue);
    } else if (temp >= 20 && temp <= 29) {
      Brain.Screen.setFillColor(cyan);
    } else if (temp >= 30 && temp <= 39) {
      Brain.Screen.setFillColor(green);
    } else if (temp >= 40 && temp <= 49) {
      Brain.Screen.setFillColor(yellow);
    } else if (temp >= 50 && temp <= 59) {
      Brain.Screen.setFillColor("#ffco4b");
    } else if (temp >= 60 && temp <= 69) {
      Brain.Screen.setFillColor(orange);
    } else if (temp >= 70 && temp <= 79) {
      Brain.Screen.setFillColor("#ff754b");
    } else if (temp >= 80 && temp <= 89) {
      Brain.Screen.setFillColor(red);
    } else if (temp >= 90 && temp <= 100) {
      Brain.Screen.setFillColor(purple);
    } else {
      Brain.Screen.setFillColor("#7d7d7d");
    }
  }

  // visual temperature printer
  // @param motorID - number ID of the specified motor, corralates to its own box
  void printBox(int motorID) {
    switch(motorID) {
      case 0:
        Brain.Screen.drawRectangle(10, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(20, Y1 + 45, "%d", temps[0]);
        Brain.Screen.setPenColor(white);
        break;
      case 1:
        Brain.Screen.drawRectangle(55, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(65, Y1 + 45, "%d", temps[1]);
        Brain.Screen.setPenColor(white);
        break;
      case 2:
        Brain.Screen.drawRectangle(100, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(110, Y1 + 45, "%d", temps[2]);
        Brain.Screen.setPenColor(white);
        break;
      case 3:
        Brain.Screen.drawRectangle(145, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(155, Y1 + 45, "%d", temps[3]);
        Brain.Screen.setPenColor(white);
        break;
      case 4:
        Brain.Screen.drawRectangle(190, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(200, Y1 + 45, "%d", temps[4]);
        Brain.Screen.setPenColor(white);
        break;
      case 5:
        Brain.Screen.drawRectangle(235, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(245, Y1 + 45, "%d", temps[5]);
        Brain.Screen.setPenColor(white);
        break;
      case 6:
        Brain.Screen.drawRectangle(280, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(290, Y1 + 45, "%d", temps[6]);
        Brain.Screen.setPenColor(white);
        break;
      case 7:
        Brain.Screen.drawRectangle(325, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(335, Y1 + 45, "%d", temps[7]);
        Brain.Screen.setPenColor(white);
        break;
      case 8:
        Brain.Screen.drawRectangle(370, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(380, Y1 + 45, "%d", temps[8]);
        Brain.Screen.setPenColor(white);
        break;
      case 9:
        Brain.Screen.drawRectangle(415, Y1, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(425, Y1 + 45, "%d", temps[9]);
        Brain.Screen.setPenColor(white);
        break;
      case 10:
        Brain.Screen.drawRectangle(10, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(20, Y2 + 45, "%d", temps[10]);
        Brain.Screen.setPenColor(white);
        break;
      case 11:
        Brain.Screen.drawRectangle(55, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(65, Y2 + 45, "%d", temps[11]);
        Brain.Screen.setPenColor(white);
        break;
      case 12:
        Brain.Screen.drawRectangle(100, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(110, Y2 + 45, "%d", temps[12]);
        Brain.Screen.setPenColor(white);
        break;
      case 13:
        Brain.Screen.drawRectangle(145, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(155, Y2 + 45, "%d", temps[13]);
        Brain.Screen.setPenColor(white);
        break;
      case 14:
        Brain.Screen.drawRectangle(190, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(200, Y2 + 45, "%d", temps[14]);
        Brain.Screen.setPenColor(white);
        break;
      case 15:
        Brain.Screen.drawRectangle(235, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(245, Y2 + 45, "%d", temps[15]);
        Brain.Screen.setPenColor(white);
        break;
      case 16:
        Brain.Screen.drawRectangle(280, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(290, Y2 + 45, "%d", temps[16]);
        Brain.Screen.setPenColor(white);
        break;
      case 17:
        Brain.Screen.drawRectangle(325, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(335, Y2 + 45, "%d", temps[17]);
        Brain.Screen.setPenColor(white);
        break;
      case 18:
        Brain.Screen.drawRectangle(370, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(380, Y2 + 45, "%d", temps[18]);
        Brain.Screen.setPenColor(white);
        break;
      case 19:
        Brain.Screen.drawRectangle(415, Y2, x, y);
        Brain.Screen.setPenColor(black);
        Brain.Screen.printAt(425, Y2 + 45, "%d", temps[19]);
        Brain.Screen.setPenColor(white);
        break;
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // screen 2
  void motorMovementSelector() {
    Brain.Screen.print("Movement Selector");
    for (int i = 1; i < 21; i++) {
      printBox(i, select[i]);
    }

    // back to main menu button
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(220, 120, 40, 30);
    Brain.Screen.printAt(235, 140, "X");
  }

  void motorMovementSelectorButton() {
    checkLastPressed();

    // back to main menu button
    if ((xPressed >= 220 && xPressed <= 260) && (yPressed >= 120 && yPressed <= 150)) {
      screenID = 0;
    }

    // main motor buttons
    for (int i = 0; i < 9; i++) {
      if ((xPressed >= e && xPressed <= a) && (yPressed >= N1 && yPressed <= N2)) {
        select[i + 1] = !select[i + 1];
      }
      e = e + 45;
      a = a + 45;
    }
    e = 10;
    a = 50;
    for (int j = 10; j < 20; j++) {
      if ((xPressed >= e && xPressed <= a) && (yPressed >= N3 && yPressed <= N4)) {
        select[j + 1] = !select[j + 1];
      }
      e = e + 45;
      a = a + 45;
    }
    e = 10;
    a = 50;
  }

  void printBox(int motorID, bool selected) {
    switch(motorID) {
      case 1:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(10, Y1, x, y);
        Brain.Screen.printAt(20, Y1 + 45, "1");
        break;
      case 2:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(55, Y1, x, y);
        Brain.Screen.printAt(65, Y1 + 45, "2");
        break;
      case 3:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(100, Y1, x, y);
        Brain.Screen.printAt(110, Y1 + 45, "3");
        break;
      case 4:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(145, Y1, x, y);
        Brain.Screen.printAt(155, Y1 + 45, "4");
        break;
      case 5:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(190, Y1, x, y);
        Brain.Screen.printAt(200, Y1 + 45, "5");
        break;
      case 6:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(235, Y1, x, y);
        Brain.Screen.printAt(245, Y1 + 45, "6");
        break;
      case 7:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(280, Y1, x, y);
        Brain.Screen.printAt(290, Y1 + 45, "7");
        break;
      case 8:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(325, Y1, x, y);
        Brain.Screen.printAt(335, Y1 + 45, "8");
        break;
      case 9:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(370, Y1, x, y);
        Brain.Screen.printAt(380, Y1 + 45, "9");
        break;
      case 10:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(415, Y1, x, y);
        Brain.Screen.printAt(425, Y1 + 45, "10");
        break;
      case 11:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(10, Y2, x, y);
        Brain.Screen.printAt(20, Y2 + 45, "11");
        break;
      case 12:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(55, Y2, x, y);
        Brain.Screen.printAt(65, Y2 + 45, "12");
        break;
      case 13:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(100, Y2, x, y);
        Brain.Screen.printAt(110, Y2 + 45, "13");
        break;
      case 14:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(145, Y2, x, y);
        Brain.Screen.printAt(155, Y2 + 45, "14");
        break;
      case 15:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(190, Y2, x, y);
        Brain.Screen.printAt(200, Y2 + 45, "15");
        break;
      case 16:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(235, Y2, x, y);
        Brain.Screen.printAt(245, Y2 + 45, "16");
        break;
      case 17:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(280, Y2, x, y);
        Brain.Screen.printAt(290, Y2 + 45, "17");
        break;
      case 18:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(325, Y2, x, y);
        Brain.Screen.printAt(335, Y2 + 45, "18");
        break;
      case 19:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(370, Y2, x, y);
        Brain.Screen.printAt(380, Y2 + 45, "19");
        break;
      case 20:
        if (selected) {
          Brain.Screen.setFillColor(green);
          Brain.Screen.setPenColor(black);
        } else {
          Brain.Screen.setFillColor("#7d7d7d");
          Brain.Screen.setPenColor(white);
        }
        Brain.Screen.drawRectangle(415, Y2, x, y);
        Brain.Screen.printAt(425, Y2 + 45, "20");
        break;
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // screen 3
  void motorDiagnosticsSelector() {
    Brain.Screen.setPenColor(white);
    Brain.Screen.print("Diagnostics Selector");
    Brain.Screen.setFillColor("#7d7d7d");
    for (int i = 0; i < 21; i++) {
      printButton(i);
    }
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(420, 2, 40, 20);
    Brain.Screen.printAt(435, 15, "X");
    Brain.Screen.setFillColor(black);
  }

  void motorDiagnosticsSelectorButton() {
    checkLastPressed();

    // stolen from movement selector with some mods lol
    for (int i = 0; i < 9; i++) {
      if ((lastPressed[0] >= e && lastPressed[0] <= a) && (lastPressed[1] >= N1 && lastPressed[1] <= N2))
        screenID = 4;
        Brain.Screen.print("%i", screenID);
      e = e + 45;
      a = a + 45;
    }
    e = 10;
    a = 50;
    for (int j = 10; j < 20; j++) {
      if ((lastPressed[0] >= e && lastPressed[0] <= a) && (lastPressed[1] >= N3 && lastPressed[1] <= N4))
        screenID = 4;
        Brain.Screen.print("%i", screenID);
      e = e + 45;
      a = a + 45;
    }
    e = 10;
    a = 50;

    if ((lastPressed[0] >= 420 && lastPressed[0] <= 460) && (lastPressed[1] >= 2 && lastPressed[1] <= 22))
      screenID = 0;
  }

  void printButton(int motorID) {
    switch(motorID) {
      case 1:
        Brain.Screen.drawRectangle(10, Y1, x, y);
        Brain.Screen.printAt(20, Y1 + 45, "1");
        break;
      case 2:
        Brain.Screen.drawRectangle(55, Y1, x, y);
        Brain.Screen.printAt(65, Y1 + 45, "2");
        break;
      case 3:
        Brain.Screen.drawRectangle(100, Y1, x, y);
        Brain.Screen.printAt(110, Y1 + 45, "3");
        break;
      case 4:
        Brain.Screen.drawRectangle(145, Y1, x, y);
        Brain.Screen.printAt(155, Y1 + 45, "4");
        break;
      case 5:
        Brain.Screen.drawRectangle(190, Y1, x, y);
        Brain.Screen.printAt(200, Y1 + 45, "5");
        break;
      case 6:
        Brain.Screen.drawRectangle(235, Y1, x, y);
        Brain.Screen.printAt(245, Y1 + 45, "6");
        break;
      case 7:
        Brain.Screen.drawRectangle(280, Y1, x, y);
        Brain.Screen.printAt(290, Y1 + 45, "7");
        break;
      case 8:
        Brain.Screen.drawRectangle(325, Y1, x, y);
        Brain.Screen.printAt(335, Y1 + 45, "8");
        break;
      case 9:
        Brain.Screen.drawRectangle(370, Y1, x, y);
        Brain.Screen.printAt(380, Y1 + 45, "9");
        break;
      case 10:
        Brain.Screen.drawRectangle(415, Y1, x, y);
        Brain.Screen.printAt(425, Y1 + 45, "10");
        break;
      case 11:
        Brain.Screen.drawRectangle(10, Y2, x, y);
        Brain.Screen.printAt(20, Y2 + 45, "11");
        break;
      case 12:
        Brain.Screen.drawRectangle(55, Y2, x, y);
        Brain.Screen.printAt(65, Y2 + 45, "12");
        break;
      case 13:
        Brain.Screen.drawRectangle(100, Y2, x, y);
        Brain.Screen.printAt(110, Y2 + 45, "13");
        break;
      case 14:
        Brain.Screen.drawRectangle(145, Y2, x, y);
        Brain.Screen.printAt(155, Y2 + 45, "14");
        break;
      case 15:
        Brain.Screen.drawRectangle(190, Y2, x, y);
        Brain.Screen.printAt(200, Y2 + 45, "15");
        break;
      case 16:
        Brain.Screen.drawRectangle(235, Y2, x, y);
        Brain.Screen.printAt(245, Y2 + 45, "16");
        break;
      case 17:
        Brain.Screen.drawRectangle(280, Y2, x, y);
        Brain.Screen.printAt(290, Y2 + 45, "17");
        break;
      case 18:
        Brain.Screen.drawRectangle(325, Y2, x, y);
        Brain.Screen.printAt(335, Y2 + 45, "18");
        break;
      case 19:
        Brain.Screen.drawRectangle(370, Y2, x, y);
        Brain.Screen.printAt(380, Y2 + 45, "19");
        break;
      case 20:
        Brain.Screen.drawRectangle(415, Y2, x, y);
        Brain.Screen.printAt(425, Y2 + 45, "20");
        break;
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // screen 4 -- skipping development, auto selector takes priority - 7-30-25

  void motorDiagnosticsViewer(int motorID) {
    Brain.Screen.print("Diagnostics Viewer - Motor %d", motorID);
    Brain.Screen.drawRectangle(0, 25, 480, 239);
    Brain.Screen.drawLine(0, 130, 480, 130);
    Brain.Screen.drawLine(240, 25, 240, 240);
    Brain.Screen.drawLine(120, 25, 120, 240);
    Brain.Screen.drawLine(360, 25, 360, 240);
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(420, 2, 40, 20);
    Brain.Screen.printAt(435, 15, "X");
    Brain.Screen.setFillColor(black);
  }

  // list of items to include
  // voltage
  // current
  // wattage
  // applied torque
  // current velocity
  // current position
  // current temperature
  // efficiency

  void motorDiagnosticsViewerButton() {
    checkLastPressed();
    if ((lastPressed[0] >= 420 && lastPressed[0] <= 460) && (lastPressed[1] >= 2 && lastPressed[1] <= 22))
      screenID = 4;
      Brain.Screen.print(lastPressed[0]);
      Brain.Screen.print(lastPressed[1]);
  }

  void printDiagnostics(int motorID) {
    switch(motorID) {
      case 12:
        break;
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // screen 5
  
  void autoSelectorMenu() {
    Brain.Screen.print("Auto Selector");
    Brain.Screen.drawRectangle(50, 100, 100, 100);
    Brain.Screen.drawRectangle(300, 100, 100, 100);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.printAt(80, 160, "<<");
    Brain.Screen.printAt(330, 160, ">>");
    Brain.Screen.setFont(monoM);
    Brain.Screen.drawRectangle(170, 140, 120, 50);
    Brain.Screen.printAt(175, 170, "Update File");
    
    switch(autoID) {
      case 1:
        Brain.Screen.printAt(100, 50, "Current Auton Selected: test");
        break;
      case 2:
        Brain.Screen.printAt(100, 50, "Current Auton Selected: test 2");
        break;
      default:
        Brain.Screen.printAt(100, 50, "Current Auton Selected: ERROR");
        break;
    }

    void autoSelectorMenuButton() {
    checkLastPressed();

    if ((lastPressed[0] >= 50 && lastPressed[0] <= 150) && (lastPressed[1] >= 100 && lastPressed[1] <= 200)) {
      autoID++;
      if (autoID == 3)
        autoID = 1;
    } else if ((lastPressed[0] >= 300 && lastPressed[0] <= 400) && (lastPressed[1] >= 100 && lastPressed[1] <= 200)) {
      autoID--;
      if (autoID == 0)
        autoID = 2;
    } else if ((lastPressed[0] >= 170 && lastPressed[0] <= 290) && (lastPressed[1] >= 140 && lastPressed[1] <= 190)) {
      autoSelectorMenuUpdateFile();
      Brain.Screen.setPenColor(green);
      Brain.Screen.printAt(400, 270, "Saved!");
      Brain.Screen.setPenColor(white);
      wait(1, sec);
    }
  }

  void autoSelectorMenuUpdateFile() {
    Brain.SDcard.savefile("e.txt", &autoID, 1);
  }

  void autoSelectorMenuUpdateLine() {
    Brain.SDcard.loadfile("e.txt", &autoID, 1);
  }
};

