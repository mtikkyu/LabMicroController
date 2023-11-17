uint8_t led_pin[6] = {10, 9, 8, 7, 6, 5};

String input_string;
String led_mode;
String led_flag = "Resume";

int8_t count_led = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  for (uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) pinMode(led_pin[count_pin], OUTPUT);
  for (uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);

  while (!Serial.available());
}

void loop() {
  while (1) {
    if (Serial.available()) {
      input_string = Serial.readStringUntil('\n');

      if (input_string == "pause" || input_string == "PAUSE" || input_string == "Pause" || input_string == "resume" || input_string == "RESUME" || input_string == "Resume") {
        led_flag = input_string;
        Serial.print("Mode : "); Serial.println(led_flag);
      }
      else {
        led_mode = input_string;
        Serial.print("Mode : "); Serial.println(led_mode);
      }
    }

    if (led_flag == "pause" || led_flag == "PAUSE" || led_flag == "Pause") return;
    else if (led_flag == "resume" || led_flag == "RESUME" || led_flag == "Resume") {

      digitalWrite(led_pin[count_led], 1);
      delay(200);

      if (led_mode == "left" || led_mode == "LEFT" || led_mode == "Left") {
        count_led++;
        if (count_led >= sizeof(led_pin)) {
          count_led = 0;
          for (uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);
          delay(200);
        }
      }
      else if (led_mode == "right" || led_mode == "RIGHT" || led_mode == "Right") {
        count_led--;
        if (count_led < 0) {
          count_led = sizeof(led_pin);
          for (uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);
          delay(200);
        }
      }
      else Serial.println("Error!");
    }
  }
}
