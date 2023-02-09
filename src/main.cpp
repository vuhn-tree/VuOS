
#include <M5EPD.h>
#include "./resources/ImageResource.h"

M5EPD_Canvas canvas(&M5.EPD);
void Shutdown();

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
  Shutdown();
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

void Shutdown() {
    log_d("Now the system is shutting down.");
    M5.EPD.Clear();
    M5.EPD.WritePartGram4bpp(92, 182, 356, 300, ImageResource_logo_356x300);
    M5.EPD.UpdateFull(UPDATE_MODE_GC16);
    M5.EPD.UpdateFull(UPDATE_MODE_GC16);                                   
    // SaveSetting();
    delay(600);
    M5.disableEPDPower();
    M5.disableEXTPower();
    M5.disableMainPower();
    esp_deep_sleep_start();
    while (1)
        ;
}