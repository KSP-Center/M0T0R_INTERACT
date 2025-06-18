#include "vex.h"
#include "robot-config.h"

class MotorMovement {
public:
  // spin the motor specified
  void move(int motorID, bool Reverse, float speed) {
    switch(motorID) {
      case 1:
        Motor1.setVelocity(speed, rpm);
        if (Reverse) {
          Motor1.spin(reverse);
        } else {
          Motor1.spin(forward);
        }
        break;
      case 2:
        Motor2.setVelocity(speed, rpm);
        if (Reverse) {
          Motor2.spin(reverse);
        } else {
          Motor2.spin(forward);
        }
        break;
      case 3:
        Motor3.setVelocity(speed, rpm);
        if (Reverse) {
          Motor3.spin(reverse);
        } else {
          Motor3.spin(forward);
        }
        break;
      case 4:
        Motor4.setVelocity(speed, rpm);
        if (Reverse) {
          Motor4.spin(reverse);
        } else {
          Motor4.spin(forward);
        }
        break;
      case 5:
        Motor5.setVelocity(speed, rpm);
        if (Reverse) {
          Motor5.spin(reverse);
        } else {
          Motor5.spin(forward);
        }
        break;
      case 6:
        Motor6.setVelocity(speed, rpm);
        if (Reverse) {
          Motor6.spin(reverse);
        } else {
          Motor6.spin(forward);
        }
        break;
      case 7:
        Motor7.setVelocity(speed, rpm);
        if (Reverse) {
          Motor7.spin(reverse);
        } else {
          Motor7.spin(forward);
        }
        break;
      case 8:
        Motor8.setVelocity(speed, rpm);
        if (Reverse) {
          Motor8.spin(reverse);
        } else {
          Motor8.spin(forward);
        }
        break;
      case 9:
        Motor9.setVelocity(speed, rpm);
        if (Reverse) {
          Motor9.spin(reverse);
        } else {
          Motor9.spin(forward);
        }
        break;
      case 10:
        Motor10.setVelocity(speed, rpm);
        if (Reverse) {
          Motor10.spin(reverse);
        } else {
          Motor10.spin(forward);
        }
        break;
      case 11:
        Motor11.setVelocity(speed, rpm);
        if (Reverse) {
          Motor11.spin(reverse);
        } else {
          Motor11.spin(forward);
        }
        break;
      case 12:
        Motor12.setVelocity(speed, rpm);
        if (Reverse) {
          Motor12.spin(reverse);
        } else {
          Motor12.spin(forward);
        }
        break;
      case 13:
        Motor13.setVelocity(speed, rpm);
        if (Reverse) {
          Motor13.spin(reverse);
        } else {
          Motor13.spin(forward);
        }
        break;
      case 14:
        Motor14.setVelocity(speed, rpm);
        if (Reverse) {
          Motor14.spin(reverse);
        } else {
          Motor14.spin(forward);
        }
        break;
      case 15:
        Motor15.setVelocity(speed, rpm);
        if (Reverse) {
          Motor15.spin(reverse);
        } else {
          Motor15.spin(forward);
        }
        break;
      case 16:
        Motor16.setVelocity(speed, rpm);
        if (Reverse) {
          Motor16.spin(reverse);
        } else {
          Motor16.spin(forward);
        }
        break;
      case 17:
        Motor17.setVelocity(speed, rpm);
        if (Reverse) {
          Motor17.spin(reverse);
        } else {
          Motor17.spin(forward);
        }
        break;
      case 18:
        Motor18.setVelocity(speed, rpm);
        if (Reverse) {
          Motor18.spin(reverse);
        } else {
          Motor18.spin(forward);
        }
        break;
      case 19:
        Motor19.setVelocity(speed, rpm);
        if (Reverse) {
          Motor19.spin(reverse);
        } else {
          Motor19.spin(forward);
        }
        break;
      case 20:
        Motor20.setVelocity(speed, rpm);
        if (Reverse) {
          Motor20.spin(reverse);
        } else {
          Motor20.spin(forward);
        }
        break;
    }
  }

  // single motor movement function
  // @param motorID - number ID of the specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motor are moving in said direction
  void singleMotorMovement(int motorID, bool reverse, float speed) {
    for (int i = 0; i < 19; i++) {
      if (i == motorID) {
        move(i, reverse, speed);
      }
    }
  }

  // multi motor movement function (2 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, bool reverse, float speed) {
    for (int i = 0; i < 19; i++) {
      if (i == motorID1 || motorID2) {
        move(i, reverse, speed);
      }
    }
  }

  // multi motor movement function (3 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, bool reverse, float speed) {
    for (int i = 0; i < 19; i++) {
      if (i == motorID1 || motorID2 || motorID3) {
        move(i, reverse, speed);
      }
    }
  }

  // multi motor movement function (4 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param motorID4 - number ID of the fourth specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, int motorID4, bool reverse, float speed) {
    for (int i = 0; i < 19; i++) {
      if (i == motorID1 || motorID2 || motorID3 || motorID4) {
        move(i, reverse, speed);
      }
    }
  }

  // multi motor movement function (5 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param motorID4 - number ID of the fourth specified motor
  // @param motorID5 - number ID of the fifth specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, int motorID4, int motorID5, bool reverse, float speed) {
    for (int i = 0; i < 19; i++) {
      if (i == motorID1 || motorID2 || motorID3 || motorID4 || motorID5) {
        move(i, reverse, speed);
      }
    }
  }

  // multi motor movement function (6 motor)
  // multi motor movement function (5 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param motorID4 - number ID of the fourth specified motor
  // @param motorID5 - number ID of the fifth specified motor
  // @param motorID6 - number ID of the sixth specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, int motorID4, int motorID5, int motorID6, bool reverse, float speed) {
    for (int i = 0; i < 19; i++) {
      if (i == motorID1 || motorID2 || motorID3 || motorID4 || motorID5 || motorID6) {
        move(i, reverse, speed);
      }
    }
  }
};