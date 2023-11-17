uint8_t led_pin[6] = {10, 9, 8, 7, 6, 5};
uint8_t count_led = 0;

void setup() {
  Serial.begin(115200);

  delay(1000);

  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) pinMode(led_pin[count_pin], OUTPUT);
  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);

}

void loop() {
  if(count_led == 0) {
    digitalWrite(led_pin[0], 0);
    digitalWrite(led_pin[1], 0);
    digitalWrite(led_pin[2], 0);
    digitalWrite(led_pin[3], 0);
    digitalWrite(led_pin[4], 0);
    digitalWrite(led_pin[5], 0);
  }
  else if(count_led == 1) {
    digitalWrite(led_pin[0], 1);
    digitalWrite(led_pin[1], 0);
    digitalWrite(led_pin[2], 0);
    digitalWrite(led_pin[3], 0);
    digitalWrite(led_pin[4], 0);
    digitalWrite(led_pin[5], 0);
  }
  else if(count_led == 2) {
    digitalWrite(led_pin[0], 1);
    digitalWrite(led_pin[1], 1);
    digitalWrite(led_pin[2], 0);
    digitalWrite(led_pin[3], 0);
    digitalWrite(led_pin[4], 0);
    digitalWrite(led_pin[5], 0);
  }
  else if(count_led == 3) {
    digitalWrite(led_pin[0], 1);
    digitalWrite(led_pin[1], 1);
    digitalWrite(led_pin[2], 1);
    digitalWrite(led_pin[3], 0);
    digitalWrite(led_pin[4], 0);
    digitalWrite(led_pin[5], 0);
  }
  else if(count_led == 4) {
    digitalWrite(led_pin[0], 1);
    digitalWrite(led_pin[1], 1);
    digitalWrite(led_pin[2], 1);
    digitalWrite(led_pin[3], 1);
    digitalWrite(led_pin[4], 0);
    digitalWrite(led_pin[5], 0);
  }
  else if(count_led == 5) {
    digitalWrite(led_pin[0], 1);
    digitalWrite(led_pin[1], 1);
    digitalWrite(led_pin[2], 1);
    digitalWrite(led_pin[3], 1);
    digitalWrite(led_pin[4], 1);
    digitalWrite(led_pin[5], 0);
  }
  else if(count_led == 6) {
    digitalWrite(led_pin[0], 1);
    digitalWrite(led_pin[1], 1);
    digitalWrite(led_pin[2], 1);
    digitalWrite(led_pin[3], 1);
    digitalWrite(led_pin[4], 1);
    digitalWrite(led_pin[5], 1);
  }

  count_led++;
  if(count_led > sizeof(led_pin)) count_led = 0;
  delay(300);
}
