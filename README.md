# RGB888 to RB565 converter
Most of the HEX colors codes used are in **RGB888** format, which is not suitable for microcontrollers requiring smaller data color codes. A conversion to RGB565 is needed for them to show properly.

This code can be implemented in the **[TFT_eSPI library](__https://github.com/Bodmer/TFT_eSPI__)** or any other MCU program to add more customized colors without having to manually convert them.

## Implementation
Simply add the respective code blocks to your `TFT_eSPI.h` and `TFT_eSPI.cpp` files in the library.

## Adding a color
Declare your new colors as **uint16_t** in the `TFT_eSPI.cpp` file :
```cpp
uint16_t TFT_ELECTRICBLUE;
uint16_t TFT_SALMONPINK;
```
Then assign the function to your variable using the color code as an argument (_*add 0x to your color code*_)

```cpp
void initCustomColors() {
      TFT_ELECTRICBLUE = RGB888toRGB565(0x0080FF); // #0080FF (0, 128, 255)
      TFT_SALMONPINK = RGB888toRGB565(0xf59596); // #f59596 (30, 37, 18)
  }
```


Don't forget to declare the function in `TFT_eSPI.h` and add your new colors as ```extern uint16_t``` variables.
```cpp
uint16_t TFT_ELECTRICBLUE;
uint16_t TFT_SALMONPINK;
```