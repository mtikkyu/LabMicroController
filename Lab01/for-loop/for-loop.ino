uint8_t led_pin[6] = {10, 9, 8, 7, 6, 5};

void setup() {
  Serial.begin(115200);

  delay(1000);

  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) pinMode(led_pin[count_pin], OUTPUT);
  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);

}

void loop() {
  for(uint8_t count_led = 0; count_led <= sizeof(led_pin); count_led++) {
    digitalWrite(led_pin[count_led], 1);
    delay(300);
  }
  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);
  delay(300);
}
