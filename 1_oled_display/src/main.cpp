
/*********
  Complete project details at https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/
connect GND to GND, VDD to 5V, SCK to A5, SDA to A4
i have 0.96Inch 128x64 OLED screen
*********/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// declare all user defined functions. Only needed in Platform IO, not essential in Arduino IDE

// an image in bitmap format
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };


void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever. this code is an infinite loop
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen. This is the buffer content meaning the Adafruit logo is displayed on the screen.
  // the logo is installed in the library, you can change it to your own logo
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(64, 32, WHITE);// 64 is column# and 32 is row# of the pixel
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();

// 64 is column# and 32 is row# where the image will be shown, 16 is width and 16 is height of the bitmap
  display.drawBitmap(64, 32, logo_bmp, 16,16, WHITE);
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();

  display.setTextSize(2); // can take 1 to 8
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Welcome to Xperio   Learning");
  display.display(); 
}

void loop() {
}