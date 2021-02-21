#ifndef gvar_h
#define gvar_h

#define TFT_DC 4
#define TFT_CS 15
#define TFT_MOSI 23
#define TFT_CLK 18
#define TFT_RST 2
#define TFT_MISO 19

#define SD_CS 5
#define SD_MOSI 23
#define SD_MISO 19
#define SD_CLK 18

#define WIDTH 240
#define HEIGHT 320

#define JoyY 34
#define JoyX 33


WiFiUDP ntpUDP;
// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
//hardware
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

const int debounce = 200;
unsigned long int time2 = 0;
boolean xState = false;
boolean yState = false;

int xCounter = 0;
int yCounter = 0;

int counter;

int cityCounter = 0;
int xVal;
int yVal;

double citySelect[3] = {HEIGHT * 0.72, HEIGHT * 0.78, HEIGHT * 0.84};
double triX[3] = {WIDTH * 0.49, WIDTH * 0.46, WIDTH * 0.62};
double triY[3] = {HEIGHT * 0.55, HEIGHT * 0.57, HEIGHT * 0.69};

int stage = 0;

//포인터와 문자열
// const char ssid[] = "TP-Link_F1F2";
// const char password[] = "85510432";
const char *ssid = "somhouse";
const char *password = "som1234*";

//timver variables
volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

//weather api
String openWeatherMapApiKey = "47aa0d42dbefc369c88bfa78a0e42e47";

String city[4] = {"Seoul", "Ansan", "Daegu", "Jeju"};
String countryCode = "KR";

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;
String jsonBuffer;

String temp[4];
String tempMax[4];
String tempMin[4];
String humidity[4];
String windSpeed[4];
String all[4];

int yValue = 0;
int xValue = 0;

unsigned long lastUpdate = 0;

#endif
