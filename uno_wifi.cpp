#include <uno_wifi.h>

uno_wifi::uno_wifi(bool displayMsg = true) {
	//Instantiate anything her
	_msg = displayMsg;
}

void uno_wifi::begin(long baudRate = 115200) {
	// Serial.begin(baudRate);
	Serial.begin(baudRate);
	if (_msg)  {
		Serial.println("Library sucessfully loaded");
	}
}

String uno_wifi::serialGet()  {
	String recv;
	while (Serial.available()) {    //while / if serial data
		char c = Serial.read();     //read it
		if (c == '~') {       //start recv on ~
			data_in = true;
			recv = "";
			continue;         //read again
		} else if (data_in && c == '|') { //finish recv on  |
			data_in = false;
			return recv;
		} else if (data_in) {
			recv += c;
		} else {
			//do nothing, as we don't care unless it's between ~ and |
		}
		delay(1);
	}
}

bool uno_wifi::serialSend(String message, bool confirmationRequest/*=false*/) {
	String msg = "~";
	msg.concat(message);
	msg.concat("|");
	Serial.print(msg);
	delay(1);
	if (confirmationRequest) {
		while (!(serialGet() == CONFIRMATION)) {
			delay(1);
		}
		delay(1);
		return 1;
	};
}
