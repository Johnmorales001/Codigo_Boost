void setPWMDutyRaw(uint8_t duty_0_255) {
  OCR0A = duty_0_255;
}

// Ajusta el ciclo útil en porcentaje 0–100
void setPWMDutyPercent(uint8_t percent) {
  if (percent > 100) percent = 100;
  uint16_t val = (uint16_t)percent * 255 / 100;
  OCR0A = (uint8_t)val;
}

void setup() {
  pinMode(6, OUTPUT);

  TCCR0A = 0;
  TCCR0B = 0;

  TCCR0A = _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);

  TCCR0B = _BV(CS00);

  TIMSK0 &= ~_BV(TOIE0);

  setPWMDutyPercent(62);
}

void loop() {

}