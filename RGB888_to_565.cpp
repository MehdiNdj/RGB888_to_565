// Converts RGB888 colors to RGB565
// you need to implement it at the beginning of your TFT_eSPI.cpp file

uint16_t RGB888toRGB565(uint32_t color) {
    uint8_t r = (color >> 16) & 0xFF;
    uint8_t g = (color >> 8) & 0xFF;
    uint8_t b = (color) & 0xFF;
  
    uint16_t r5 = (r * 31 + 127) / 255; // Adding 127 allows to round up the number to avoid losing colors
    uint16_t g6 = (g * 63 + 127) / 255;
    uint16_t b5 = (b * 31 + 127) / 255;
  
    return (r5 << 11) | (g6 << 5) | b5;
  }
  
  // Declare your customized colors here, the ones below are used as samples
  uint16_t TFT_ELECTRICBLUE;
  uint16_t TFT_SALMONPINK;
  
  // Initialise your custom colors with their RGB888 colors as an arg.
  void initCustomColors() {
      TFT_ELECTRICBLUE = RGB888toRGB565(0x0080FF); // #0080FF (0, 128, 255)
      TFT_SALMONPINK = RGB888toRGB565(0xf59596); // #f59596 (30, 37, 18)
  }