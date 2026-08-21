#include <avr/io.h>
#include <util/delay.h>
#define AREF_MODE 0                          // dien ap tham chieu ngoai, dien ap tren chan Vref
#define AVCC_MODE (1 << REFS0)               // dung dien ap chan AVcc lam dien ap tham chieu
#define INT_MODE (1 << REFS1) | (1 << REFS0) // dung dien ap tham chieu noi 2.56V
#define ADC_VREF_TYPE AREF_MODE              // dinh nghia dien ap tham chieu
uint16_t ADC_val;
uint16_t read_adc(unsigned char adc_channel)
{ // chuong trinh con doc ADC theo tung channel
  ADMUX = adc_channel;
  ADCSRA |= (1 << ADSC);               // bat dau chuyen doi
  loop_until_bit_is_set(ADCSRA, ADIF); // cho den khi nao bit ADIF==1
  return ADCW;
}
void LED7_out(uint16_t val)
{
  uint16_t digits[4];
  for (uint8_t i = 0; i < 4; i++)
  {
    digits[3 - i] = val % 10;
    val /= 10;
  }
  PORTB = (digits[2] << 4) | digits[3]; // Chuc | Don
  PORTC = (digits[0] << 4) | digits[1]; // Nghin | Tram
}
int main(void)
{
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS2) | (1 << ADPS0); // enable ADC, khong dung interrupt
  ADMUX = ADC_VREF_TYPE;                                             // chon kieu dien ap tham chieu
  DDRB = 0xFF;                                                       // PORTB la output PORT, for LED
  DDRC = 0xFF;                                                       // PORTC la output PORT, for LED
  while (1)
  {
    ADC_val = read_adc(0);
    LED7_out(ADC_val);
    _delay_ms(100);
  }
}