uint8_t led_pin[6] = {10, 9, 8, 7, 6, 5};
uint8_t count_led = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) pinMode(led_pin[count_pin], OUTPUT);
  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);
}

void loop() {
  while(count_led < sizeof(led_pin)) {
    digitalWrite(led_pin[count_led], 1);
    delay(300);
    count_led++;
  }
  count_led = 0;
  for(uint8_t count_pin = 0; count_pin < sizeof(led_pin); count_pin++) digitalWrite(led_pin[count_pin], 0);
  delay(300);
}
