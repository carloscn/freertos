/* Hello World Example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "FreeRTOS.h"
#include "task.h"
#include "hello.h"
#include "serial.h"

// #define     HELLO_TASK_PRIO         1
// #define     HELLO_STACK_SIZE        128

//TaskHandle_t HelloTask_Handle;
xComPortHandle *comHandle;

static void hello_task(void *pvParameters)
{
    (void)pvParameters;
    comHandle = xSerialPortInitMinimal(115200, 25);
    vSerialPutString(comHandle, "hello world\n", 12);
    //printf("hello world\n");
    while (1) {
        vTaskDelay(1000 / portTICK_RATE_MS);
        //printf("hello world\n");
        vSerialPutString(comHandle, "carlos's hello world loop\n", 27);
    }
}

void hello_entry()
{
    // xTaskCreate((TaskFunction_t)hello_task,
    //             (const char *)"hello_world task",
    //             (uint16_t) HELLO_STACK_SIZE,
    //             (void *) NULL,
    //             (UBaseType_t)HELLO_TASK_PRIO,
    //             (TaskHandle_t *)&HelloTask_Handle);
    // vTaskStartScheduler();
    hello_task(NULL);
}
