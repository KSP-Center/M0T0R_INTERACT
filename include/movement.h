class MotorMovement {
public:

  void move(int motorID, bool Reverse, float speed);

  // single motor movement function
  // @param motorID - number ID of the specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motor are moving in said direction
  void singleMotorMovement(int motorID, bool reverse, float speed);

  // multi motor movement function (2 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, bool reverse, float speed);

  // multi motor movement function (3 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, bool reverse, float speed);

  // multi motor movement function (4 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param motorID4 - number ID of the fourth specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, int motorID4, bool reverse, float speed);

  // multi motor movement function (5 motor)
  // @param motorID1 - number ID of the first specified motor
  // @param motorID2 - number ID of the second specified motor
  // @param motorID3 - number ID of the third specified motor
  // @param motorID4 - number ID of the fourth specified motor
  // @param motorID5 - number ID of the fifth specified motor
  // @param reverse - indicator of the direction of movement
  // @param speed - how fast the motors are moving in said direction
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, int motorID4, int motorID5, bool reverse, float speed);

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
  void multiMotorMovement(int motorID1, int motorID2, int motorID3, int motorID4, int motorID5, int motorID6, bool reverse, float speed);
};