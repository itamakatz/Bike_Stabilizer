void serialEvent(){

	DEBUG_FUNC_FLOW("check_key()");

	if (Serial.available() > 0) {

		DEBUG_FUNC_FLOW("check_key() - after if (Serial.available() > 0)");
		
		// read ascii char and convert to int representation
        char incoming_serial_char = Serial.read();

        switch (incoming_serial_char) {
            case 'H':
            case 'h':
				Serial.println(F("1 - Gyro Calicration"));
				Serial.println(F("2 - Calibrate values to zero"));
				Serial.println(F("3 - Run sixDOF_setup again"));
                return;
            case 'm':
            case 'M':
                if (Serial.available() > 0) {
                    // read ascii char and convert to int representation
                    int incoming_serial = Serial.read() - '0';
                    while(Serial.available() > 0){
                        incoming_serial = incoming_serial * 10 + int(Serial.read() - '0');
                    }
                    Serial.println("Move Servo:" + String(incoming_serial));

                    Move_Servo(incoming_serial);
                }

                return;
        }

		int incoming_serial =  (int) (incoming_serial_char - '0');
		
		DEBUG_PRINT("check_key() - incoming_serial is ");
		DEBUG_PRINT_VAL(incoming_serial);

		switch (incoming_serial) {
			case 1:
				s6DoF_object.calibrate();
				Serial.println(F("Gyro calibrated"));
				break;
			case 2:
				s6DoF_object.set_zero();
				Serial.println(F("Calibrated values to zero"));
				break;
			case 3:
				s6DoF_object.sixDOF_setup((float)0.1);
				Serial.println(F("Run sixDOF_setup again"));
				break;
			default:
				Serial.println(F("Error - input key not legal"));
		}
	}

	if (Serial.available() > 0) {

		// read ascii char and convert to int representation
		int incoming_serial = Serial.read() - '0';
		while(Serial.available() > 0){
			incoming_serial = incoming_serial * 10 + int(Serial.read() - '0');
		}
		Serial.println("Number Entered:" + String(incoming_serial));
	}
}