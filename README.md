# mcu_homework1_rotaryencoder_with_u8g2
arduino esp32 wokwi rotaryencoder u8g2 ssd1306 oled panel
mcu: arduino esp32
sim: wokwi
peripherals: rotary encoder, u8g2 ssd1306 oled(irl sh1106 was used instead) -> todo: change u8g2 config to sh1106 version in full buffer mode

used interrupt signals because rotary encoder had conflict with u8g2
im assuming its because rotary encoder was not utterly detected before the execution at the time had left
error occured shows 0-1-1-0 in a consecutive clockwise, if without using interrupt

##notable refs and forums
`Rotary encoder stops working in combination with U8G2 lib` in arduino forum
`Interrupts 中斷處理介紹篇(上)` in ithelp
