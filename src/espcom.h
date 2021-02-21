#ifndef espcom_h
#define espcom_h
typedef struct struct_message
{
  int x;
  int y;
} struct_message;

struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  memcpy(&myData, incomingData, sizeof(myData));
  xVal = myData.x;
  yVal = myData.y;
  initButton();
}

#endif // !espnow_h
