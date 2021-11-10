#include <Arduino_FreeRTOS.h>

const int red_led = 10;
const int green_led = 11;
const int blue_led = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  digitalWrite(blue_led, LOW);
  delay(3000);
  
  xTaskCreate(red,     "Red",   100, NULL, 3, NULL);
  xTaskCreate(green,   "Green", 100, NULL, 2, NULL);
  xTaskCreate(red,     "Blue",  100, NULL, 1, NULL);
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void red(void* pvParameters){
  while(1){

  digitalWrite(red_led, LOW);
  vTaskDelay(2000/portTICK_PERIOD_MS);
  digitalWrite(red_led, HIGH);
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
  }
  
void green(void* pvParameters){
  while(1){

  digitalWrite(green_led, LOW);
  vTaskDelay(4000/portTICK_PERIOD_MS);
  digitalWrite(green_led, HIGH);
  vTaskDelay(4000/portTICK_PERIOD_MS);

  }
}

 void blue(void* pvParameters){
  while(1){

  digitalWrite(blue_led, LOW);
  vTaskDelay(4000/portTICK_PERIOD_MS);
  digitalWrite(blue_led, HIGH);
  vTaskDelay(4000/portTICK_PERIOD_MS);
  }  
  
 }
