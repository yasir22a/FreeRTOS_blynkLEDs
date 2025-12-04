FreeRTOS 5-LED Multi-Tasking Project

Description

This project demonstrates the implementation of FreeRTOS on the ESP32 microcontroller to control 5 LEDs simultaneously using independent tasks.

Unlike standard sequential programming, this project leverages the ESP32's dual-core architecture to run tasks concurrently. It features a single reusable task function (BlinkTask) that dynamically adapts its behavior based on parameters passed during task creation, demonstrating efficient code architecture and the "Don't Repeat Yourself" (DRY) principle.

Key Features

Parameterized Tasks: Uses xTaskCreate with pvParameters to pass the specific GPIO pin number to a single generic function, avoiding code duplication.

Priority Scheduling: The Red LED task is assigned a higher priority (4) than the others (1) to demonstrate FreeRTOS preemption and task importance.

Independent Timing: Each LED operates on its own dedicated timeline using non-blocking vTaskDelay:

🔴 Red: 5000ms period

🟢 Green: 4000ms period

🔵 Blue: 3000ms period

🟡 Yellow: 2000ms period

⚪ White: 1000ms period

Efficient Logic: Uses toggle logic (ledState = !ledState) for clean state management.

------Prerequisites & Setup--------

To compile and run this project, you need:

IDE: Visual Studio Code with the PlatformIO extension, or the standard Arduino IDE.

Board: An ESP32 Development Board (e.g., ESP32 DevKit V1).

Required Libraries: The code relies only on the standard Arduino and FreeRTOS libraries, which are built into the ESP32 Board Manager installation.


Note: For simulation, you can copy the contents of the diagram.json file provided in the repository directly into Wokwi.
