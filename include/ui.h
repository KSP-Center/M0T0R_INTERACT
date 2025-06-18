class UserInterface {
public:
  // screen variables
  int screenID;
  int xPressed;
  int yPressed;
  int lastPressed[2];

  // arrays
  bool select[20];
  int temps[20];
  int selected[6];

  // other variables
  int speed;
  int Y1;
  int Y2;
  int x;
  int y;
  int N1;
  int N2;
  int N3;
  int N4;
  int e;
  int a;

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
  void checkLastPressed();

  // screen 0
  void mainMenu();
  void mainMenuButton();

  // screen 1
  void motorTemperatureViewer();
  void motorTemperarureViewerButton();
  void setTemps();
  void setColor(float temp);
  void printBox(int motorID);

  // screen 2
  void motorMovementSelector();
  void motorMovementSelectorButton();
  void printBox(int motorID, bool selected);

  void motorDiagnosticsSelector(); // screen 3
  void motorDiagnosticsViewer(); // screen 4
  void settingsMenu(); // screen 5
};
