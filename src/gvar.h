#ifndef gvar_h
#define gvar_h

#define TFT_DC 4
#define TFT_CS 15
#define TFT_RST 2

#define WIDTH 240
#define HEIGHT 320

#define JoyY 34
#define JoyX 33

enum cityNum{SEOUL,ANSAN,DAEGU,JEJU};

WiFiUDP ntpUDP;

//hardware
// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

const int debounce = 200;
unsigned long int time2 = 0;

boolean xState = false;
boolean yState = false;

int xCounter = 0;
int yCounter = 0;

int counter = 0;
int cityCounter = 0;

int xVal;
int yVal;

const double citySelect[3] = {HEIGHT * 0.72, HEIGHT * 0.78, HEIGHT * 0.84};

const double tri[2][3] = {{WIDTH * 0.49, WIDTH * 0.46, WIDTH * 0.62}, {HEIGHT * 0.55, HEIGHT * 0.57, HEIGHT * 0.69}};
double const (*triP)[3] = tri;

int stage = 0;

//포인터와 문자열
const char ssid[] = "TP-Link_F1F2";
const char password[] = "85510432";

//timver variables
volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

//weather api
const String openWeatherMapApiKey = "47aa0d42dbefc369c88bfa78a0e42e47";

const String city[4] = {"SEOUL", "ANSAN", "DAEGU", "JEJU"};
String const *cityP = city;

const String countryCode = "KR";

unsigned long lastTime[4] = {0};
unsigned long timerDelay = 000;
String jsonBuffer;


typedef struct httpInfo 
{
String temp[4];
String humidity[4];
String windSpeed[4];
String all[4];
}httpInfo;

httpInfo httpinfo;

boolean check;

typedef struct struct_message
{
    int check;
    int x;
    int y;
    boolean refresh = true;
} struct_message;

struct_message send;

#endif
