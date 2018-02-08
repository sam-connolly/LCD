#include <mbed.h>
#include <C12832.h>

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);

int main()
{
    int counter = 0;
    
    lcd.cls();
    lcd.rect(0,0,127,31,1);
    lcd.locate(2,3);
    lcd.printf("LCD basics");
    while(true) {   // this is the third thread
      lcd.locate(2,12);
      lcd.printf("counter: %09d", counter);
      counter += 1;
      wait_ms(200);
    }
}
