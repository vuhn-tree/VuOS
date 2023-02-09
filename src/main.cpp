
#include <M5EPD.h>

M5EPD_Canvas canvas(&M5.EPD);

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.EPD.SetRotation(180);
  M5.EPD.Clear(true); // Clear the screen.
  M5.RTC.begin();     // Init the RTC.


  char buf[100];
  sprintf(buf, "Hello World!");

  canvas.createCanvas(960, 540);
  canvas.setTextSize(88);
  canvas.fillCanvas(0);

  canvas.drawString(buf, 50, 50);
  canvas.pushCanvas(0, 0, UPDATE_MODE_DU4); // Update the screen.
}

void loop() {
  // put your main code here, to run repeatedly:
  // char buf[130];
  // sprintf(buf, "hello world");
  // int centerX = (960 / 2) - (canvas.textWidth(buf) / 2);
  // int centerY = (540 / 2) - (canvas.fontHeight() / 2);
  // canvas.drawString(buf, centerX, centerY);
  // canvas.pushCanvas(0, 0, UPDATE_MODE_A2);
}