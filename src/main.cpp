#include <mbed.h>
#include <C12832.h>

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);

int main()
{
    //int counter = 0;
    AnalogIn  left(A0);
    AnalogIn right(A1);

    /**lcd.cls();
    lcd.rect(0,0,127,31,1);
    lcd.locate(2,3);
    lcd.printf("LCD basics");
    lcd.locate(2,21);
    lcd.printf("%d.%d.%d", MBED_MAJOR_VERSION, MBED_MINOR_VERSION,
     MBED_PATCH_VERSION);
    while(counter < 10)
    {   // this is the third thread
      lcd.locate(2,12);
      lcd.printf("counter: %09d", counter);
      counter += 1;
      wait_ms(200);
    }

    lcd.cls();
    lcd.locate(0,0);
    lcd.printf("Max number of columns: %i", lcd.columns());
    lcd.locate(0,9);
    lcd.printf("Max number of rows: %i", lcd.rows());
    wait(2);

    while(1)
    {
      lcd.cls();
      lcd.locate(0,0);
      lcd.printf("Left dial %f \n",  left.read() );
      lcd.locate(0,9);
      lcd.printf("Right dial %f \n", right.read() );
      wait( 1.0 );
    }

    lcd.cls();
    lcd.line(0, 0, lcd.width(), lcd.height(), 1);
    wait_ms(500);
    lcd.line(0, lcd.height(), lcd.width(), 0, 1);
    wait_ms(500);
    lcd.rect(0, 0, lcd.width(), lcd.height(), 1);
    wait(2);**/

    lcd.locate(0, 0);
    lcd.printf("L: ");
    lcd.rect(10, 0, 110, 5, 1);

    lcd.locate(0, 9);
    lcd.printf("R: ");
    lcd.rect(10, 9, 110, 14, 1);

    while(true)
    {
      float lWidth = (left.read()*100) + 10;
      float rWidth = (right.read()*100) + 10;

      lcd.fillrect(10, 0, lWidth, 5, 1);
      lcd.fillrect(lWidth-1, 1, 109, 4, 0);

      lcd.fillrect(10, 9, rWidth, 14, 1);
      lcd.fillrect(rWidth-1, 10, 109, 13, 0);

      /**lcd.locate(0,18);
      lcd.printf("L: %f   R: %f", lWidth, rWidth);
      wait_ms(100);**/
    }

}
