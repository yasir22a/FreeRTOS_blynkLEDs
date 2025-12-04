/*
 * FreeRTOS 5 LED Blink Project
 * - Red : 5000ms
 * - Green : 4000ms
 * - Blue : 3000ms
 * - Yellow : 2000ms
 * - White : 1000ms
 */

// --- LED Pin Definitions ---
const int ledPin1 = 23; // Red
const int ledPin2 = 22; // Green
const int ledPin3 = 21; // Blue
const int ledPin4 = 19; // Yellow
const int ledPin5 = 18; // White

// --- Task Functions ---

void BlinkTask(void *pvParameters) {
  int pinNumber = (int)pvParameters; 
  uint8_t ledState = 0;

  pinMode(pinNumber, OUTPUT);

  int delayTime = 1000; // Default

  if (pinNumber == ledPin1) {
    delayTime = 5000; // Red: 5000ms
  } else if (pinNumber == ledPin2) {
    delayTime = 4000; // Green: 4000ms
  } else if (pinNumber == ledPin3) {
    delayTime = 3000; // Blue: 3000ms
  } else if (pinNumber == ledPin4) {
    delayTime = 2000; // Yellow: 2000ms
  } else if (pinNumber == ledPin5) {
    delayTime = 1000; // White: 1000ms
  }

  //The Infinite Loop
  for (;;) {
    digitalWrite(pinNumber, ledState);   // Set the LED to current state
    ledState = !ledState;                // Toggle state (0 becomes 1, 1 becomes 0)
    vTaskDelay(delayTime / portTICK_PERIOD_MS); // Wait for the duration
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting FreeRTOS Tasks...");

  // Task 1 (Red)
  xTaskCreate(BlinkTask, "RedTask", 1024, (void *)ledPin1, 1, NULL);

  // Task 2 (Green)
  xTaskCreate(BlinkTask, "GreenTask", 1024, (void *)ledPin2, 1, NULL);

  // Task 3 (Blue)
  xTaskCreate(BlinkTask, "BlueTask", 1024, (void *)ledPin3, 1, NULL);

  // Task 4 (Yellow)
  xTaskCreate(BlinkTask, "YellowTask", 1024, (void *)ledPin4, 1, NULL);

  // Task 5 (White)
  xTaskCreate(BlinkTask, "WhiteTask", 1024, (void *)ledPin5, 1, NULL);
}

void loop() {
}
