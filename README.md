# Reflex Gunsight Reticle

Code intended to control an Arduino (or Arduino adjacent) board to light up an OLED display. The point of impact is also adjustable by 3 buttons, two for left/right and up/down movement and one to switch the adjusting axis.

**This code is intended for use with OLED screens that are 128x64 and powered by SSD1306 over I2C/SPI**

Idea based on this video, where the author created another gunsight but used gyro stabilization for theirs. Feel free to repurpose this code for your own aiming purposes. It was created with configurability in mind so users can change the pins, dimensions, and images it uses. Be sure to update the calibration numbers to make sure your new reticle is centered. 