#ifndef uw
#define uw

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class uno_wifi  {
public:
  //Constructor
  uno_wifi(bool displayMsg);

  //Methods
  void begin(long baudRate);
  String serialGet();
  bool serialSend(String message, bool confirmationRequest=false);

  //Constants
  const String CONFIRMATION = "OK";

private:
  bool _msg;
  bool data_in;

};
#endif
