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
double citySelect[3] = {HEIGHT * 0.72, HEIGHT * 0.78, HEIGHT * 0.84};
double triX[3] = {WIDTH * 0.48, WIDTH * 0.46, WIDTH * 0.62};
double triY[3] = {HEIGHT * 0.55, HEIGHT * 0.57, HEIGHT * 0.69};


//포인터와 문자열
// const char ssid[] = "TP-Link_F1F2";
// const char password[] = "85510432";
const char *ssid = "TP-Link_F1F2";
const char *password = "85510432";

//timver variables
volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

//weather api
String openWeatherMapApiKey = "47aa0d42dbefc369c88bfa78a0e42e47";

String city[3] = {"Ansan", "Daegu", "Seoul"};
String countryCode = "KR";

unsigned long lastTime = 0;
unsigned long timerDelay = 10000;
String jsonBuffer;

int yValue = 0;
int xValue = 0;

#endif
