#include<Arduino_FreeRTOS.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("This is setup function");
  delay(2000);
// Create three tasks with different priority
// Task-1 with Priority 1 (Lower) and dept of stack 100
// Task-2 with Priority 3 (Lower) and dept of stack 100
// Task-3 with Priority 2 (Higher) and dept of stack 100
  xTaskCreate(task1, "Task1", 200, NULL, 1, NULL);
  //xTaskCreate(task2, "Task2", 100, NULL, 3, NULL);
  xTaskCreate(task3, "Task3", 100, NULL, 2, NULL);
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void task1(void*pvParameters)
{while(1)
{
  Serial.println("Task-1 is running");
  vTaskDelay(2000/portTICK_PERIOD_MS);
   
}


}

//void task2(void* pvParameters)
//{while(1)
//{
//  Serial.println("Task-2 is running");
//  vTaskDelay(2000/portTICK_PERIOD_MS);
//   //delay(2000);
//}
//}


void task3(void* pvParameters)
{while(1)
{
  Serial.println("Task-3 is running");
  vTaskDelay(2000/portTICK_PERIOD_MS);
}
}

