uint8_t led_pin[6] = {10, 9, 8, 7, 6, 5};

String input_string;
uint8_t led_number = 0;
String led_state;
bool check_in = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  for (uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) pinMode(led_pin[count_pin], OUTPUT);
  for (uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);
}

void loop() {
  if (Serial.available()) {
    check_in = 1;
    input_string = Serial.readStringUntil(' ');
    led_number = input_string.toInt();

    input_string = Serial.readStringUntil('\n');
    led_state = input_string;

    if (led_state == "on" || led_state == "ON") {
      digitalWrite(led_pin[led_number - 1], 1);
    }
    else if (led_state == "off" || led_state == "OFF") {
      digitalWrite(led_pin[led_number - 1], 0);
    }
    else {
      if (check_in == 0) {
        Serial.print("LED : ");
        Serial.print(led_number);
        Serial.print(" ");
        Serial.println(led_state);
      }
      else {
        Serial.println("Error!");
        check_in = 0;
      }
    }
  }
}
