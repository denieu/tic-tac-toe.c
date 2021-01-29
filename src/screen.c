/*---------------------------
  Includes
---------------------------*/
#include "../include/main.h"

/*---------------------------
  Variables and constants
---------------------------*/
type_screenState screenState = {0};
type_gameState gameScreenState = {0};

/*---------------------------
  Functions
---------------------------*/
void setCurrentScreen(enum_screens newScreen) {
  screenState.currentScreen = newScreen;
}

enum_screens getCurrentScreen(){
  return screenState.currentScreen;
}

void setCurrentScreenState(int newValue) {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      screenState.menuScreenState = newValue;
      break;

    case CONFIG_SCREEN:
      screenState.configScreenState = newValue;
      break;

    case PLAY_SCREEN:
      screenState.playScreenState = newValue;
      break;

    case ONLINE_SCREEN:
      screenState.onlineScreenState = newValue;
      break;

    case SERVER_SCREEN:
      screenState.serverScreenState = newValue;
      break;

    case CLIENT_SCREEN:
      screenState.clientScreenState = newValue;
      break;

    default:
      break;
  }
}

int getCurrentScreenState() {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return screenState.menuScreenState;
      break;

    case CONFIG_SCREEN:
      return screenState.configScreenState;
      break;

    case PLAY_SCREEN:
      return screenState.playScreenState;
      break;

    case ONLINE_SCREEN:
      return screenState.onlineScreenState;
      break;

    case SERVER_SCREEN:
      return screenState.serverScreenState;
      break;

    case CLIENT_SCREEN:
      return screenState.clientScreenState;

    default:
      return 0;
      break;
  }
}

int getCurrentScreenFirstvalue() {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return MENU_FIRST_VALUE;
      break;

    case CONFIG_SCREEN:
      return CONFIG_FIRST_VALUE;
      break;

    case PLAY_SCREEN:
      return PLAY_FIRST_VALUE;
      break;

    case ONLINE_SCREEN:
      return ONLINE_FIRST_VALUE;
      break;

    case SERVER_SCREEN:
      return SERVER_FIRST_VALUE;
      break;

    case CLIENT_SCREEN:
      return SERVER_FIRST_VALUE;
      break;

    default:
      return 0;
      break;
  }
}

int getCurrentScreenLastvalue() {
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      return MENU_LAST_VALUE;
      break;

    case CONFIG_SCREEN:
      return CONFIG_LAST_VALUE;
      break;

    case PLAY_SCREEN:
      return PLAY_LAST_VALUE;
      break;

    case ONLINE_SCREEN:
      return ONLINE_LAST_VALUE;
      break;

    case SERVER_SCREEN:
      return SERVER_LAST_VALUE;
      break;

    case CLIENT_SCREEN:
      return SERVER_LAST_VALUE;
      break;

    default:
      return 0;
      break;
  }
}

void setGameScreenState(type_gameState newGameScreenState){
  gameScreenState = newGameScreenState;
}

void gotoxy( int x, int y )
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setCursor(enum_cursorState cursorState){
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = cursorState;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void configScreenSize(){
  CONSOLE_SCREEN_BUFFER_INFO screenInfo = {0};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);

  screenState.screenSize = screenInfo.dwMaximumWindowSize;
}

int calcPreSpaces(int discount){
  int spaces = ((screenState.screenSize.X - discount) / 2);
  return spaces;
}

char preSpaces[1000];
const char* genPreSpaces(int spaces){
  memset(preSpaces, 0, sizeof(preSpaces));
  memset(preSpaces, ' ', spaces);
  return preSpaces;
}

void printMenuScreen(){
  unsigned char prints[3] = {0};
  prints[0] = getCurrentScreenState() == MENU_PLAY ? 1 : 0;
  prints[1] = getCurrentScreenState() == MENU_CONFIG ? 1 : 0;
  prints[2] = getCurrentScreenState() == MENU_EXIT ? 1 : 0;

  printf("\n\n");
  printf("%s%s Play %s\n", genPreSpaces(calcPreSpaces(sizeof("    Play    "))), prints[0] == 1 ? "-->" : "   ", prints[0] == 1 ? "<--" : "   ");
  printf("%s%s Configs %s\n", genPreSpaces(calcPreSpaces(sizeof("    Configs    "))), prints[1] == 1 ? "-->" : "   ", prints[1] == 1 ? "<--" : "   ");
  printf("%s%s Exit %s\n", genPreSpaces(calcPreSpaces(sizeof("    Exit    "))), prints[2] == 1 ? "-->" : "   ", prints[2] == 1 ? "<--" : "   ");
}

void printConfigScreen(){
  unsigned char prints[1] = {0};
  prints[0] = getCurrentScreenState() == CONFIG_RETURN ? 1 : 0;

  printf("\n\n");
  printf("%s%s Return %s\n", genPreSpaces(calcPreSpaces(sizeof("    Return    "))), prints[0] == 1 ? "-->" : "   ", prints[0] == 1 ? "<--" : "   ");
}

void printPlayScreen(){
  unsigned char prints[5] = {0};
  prints[0] = getCurrentScreenState() == PLAY_PVP ? 1 : 0;
  prints[1] = getCurrentScreenState() == PLAY_PVC ? 1 : 0;
  prints[2] = getCurrentScreenState() == PLAY_CVC ? 1 : 0;
  prints[3] = getCurrentScreenState() == PLAY_ONLINE ? 1 : 0;
  prints[4] = getCurrentScreenState() == PLAY_RETURN ? 1 : 0;

  printf("\n\n");
  printf("%s%s PvP %s\n", genPreSpaces(calcPreSpaces(sizeof("    PVP    "))), prints[0] == 1 ? "-->" : "   ", prints[0] == 1 ? "<--" : "   ");
  printf("%s%s PvC %s\n", genPreSpaces(calcPreSpaces(sizeof("    PVC    "))), prints[1] == 1 ? "-->" : "   ", prints[1] == 1 ? "<--" : "   ");
  printf("%s%s CvC %s\n", genPreSpaces(calcPreSpaces(sizeof("    CVC    "))), prints[2] == 1 ? "-->" : "   ", prints[2] == 1 ? "<--" : "   ");
  printf("%s%s Online %s\n", genPreSpaces(calcPreSpaces(sizeof("    Online    "))), prints[3] == 1 ? "-->" : "   ", prints[3] == 1 ? "<--" : "   ");
  printf("%s%s Return %s\n", genPreSpaces(calcPreSpaces(sizeof("    Return    "))), prints[4] == 1 ? "-->" : "   ", prints[4] == 1 ? "<--" : "   ");
}

void printGameScreen(){
  int boardSpace = calcPreSpaces(sizeof("---+---+---"));

  printf("\n");
  printf("%sPress ESC to quit", genPreSpaces(calcPreSpaces(sizeof("Press ESC to quit"))));
  printf("\n\n");
  printf("%sCurrent Player: %c", genPreSpaces(calcPreSpaces(sizeof("Current Player:  "))), gameScreenState.playerSymbol[gameScreenState.currentPlayer]);
  printf("\n\n");
  printf("%s %c | %c | %c \n", genPreSpaces(boardSpace), gameScreenState.currentBoard[0][0], gameScreenState.currentBoard[0][1], gameScreenState.currentBoard[0][2]);
  printf("%s---+---+---\n", genPreSpaces(boardSpace));
  printf("%s %c | %c | %c \n", genPreSpaces(boardSpace), gameScreenState.currentBoard[1][0], gameScreenState.currentBoard[1][1], gameScreenState.currentBoard[1][2]);
  printf("%s---+---+---\n", genPreSpaces(boardSpace));
  printf("%s %c | %c | %c \n", genPreSpaces(boardSpace), gameScreenState.currentBoard[2][0], gameScreenState.currentBoard[2][1], gameScreenState.currentBoard[2][2]);

  if(gameScreenState.gameType == GAME_CVC)
    printf("\n\n%sPress any key to next turn\n", genPreSpaces(calcPreSpaces(sizeof("Press any key to next turn"))));
}

void printWinnerScreen(){
  printf("\n\n");
  if(gameScreenState.gameWinner == WINNER_TOE){
    printf("%sToe", genPreSpaces(calcPreSpaces(sizeof("sToe"))));
  }
  else {
    printf("%sPlayer %c wins", genPreSpaces(calcPreSpaces(sizeof("Player X wins"))), gameScreenState.playerSymbol[gameScreenState.gameWinner - 1]);
  }
}

void printOnlineScreen(){
  unsigned char prints[5] = {0};
  prints[0] = getCurrentScreenState() == ONLINE_SERVER ? 1 : 0;
  prints[1] = getCurrentScreenState() == ONLINE_CLIENT ? 1 : 0;
  prints[2] = getCurrentScreenState() == ONLINE_RETURN ? 1 : 0;

  printf("\n\n");
  printf("%s%s Server %s\n", genPreSpaces(calcPreSpaces(sizeof("    SERVER    "))), prints[0] == 1 ? "-->" : "   ", prints[0] == 1 ? "<--" : "   ");
  printf("%s%s Client %s\n", genPreSpaces(calcPreSpaces(sizeof("    Client    "))), prints[1] == 1 ? "-->" : "   ", prints[1] == 1 ? "<--" : "   ");
  printf("%s%s Return %s\n", genPreSpaces(calcPreSpaces(sizeof("    Return    "))), prints[2] == 1 ? "-->" : "   ", prints[2] == 1 ? "<--" : "   ");
}

void printServerScreen(){
  unsigned char prints[1] = {0};
  prints[0] = getCurrentScreenState() == SERVER_RETURN ? 1 : 0;

  printf("\n\n");
  printf("%s%s Return %s\n", genPreSpaces(calcPreSpaces(sizeof("    Return    "))), prints[0] == 1 ? "-->" : "   ", prints[0] == 1 ? "<--" : "   ");
}

void printClientScreen(){
  unsigned char prints[1] = {0};
  prints[0] = getCurrentScreenState() == CLIENT_RETURN ? 1 : 0;

  printf("\n\n");
  printf("%s%s Return %s\n", genPreSpaces(calcPreSpaces(sizeof("    Return    "))), prints[0] == 1 ? "-->" : "   ", prints[0] == 1 ? "<--" : "   ");
}

void printCurrentScreen() {
  configScreenSize();

  system("cls");
  switch (screenState.currentScreen){
    case MENU_SCREEN:
      printMenuScreen();
      break;

    case CONFIG_SCREEN:
      printConfigScreen();
      break;

    case PLAY_SCREEN:
      printPlayScreen();
      break;

    case GAME_SCREEN:
      printGameScreen();
      break;

    case WINNER_SCREEN:
      printWinnerScreen();
      break;

    case ONLINE_SCREEN:
      printOnlineScreen();
      break;

    case SERVER_SCREEN:
      printServerScreen();
      break;

    case CLIENT_SCREEN:
      printClientScreen();
      break;

    default:
      break;
  }
}
