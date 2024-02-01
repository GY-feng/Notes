#ifdef __BUZZER_H
#define __BUZZER_H
void Buzzer_Init_GPIOB(uint16_t PIN);
void Buzzer_ON_GPIOB(uint16_t PIN);
void Buzzer_OFF_GPIOB(uint16_t PIN);
void Buzzer_Turn_GPIOB(uint16_t PIN);//调用的时候，状态取反
#endif