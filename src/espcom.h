#ifndef espcom_h
#define espcom_h

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  memcpy(&send, incomingData, sizeof(send));
  check = send.check;
  if (check == 1)
  {
    xVal = send.x;
    yVal = send.y;
    initButton();
  }
}

#endif // !espnow_h
