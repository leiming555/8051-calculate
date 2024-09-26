#include <REGX52.H>
#include <INTRINS.H>
#include "display.h"
void main()
{
  char num1, num2, num3, num4, press, k1, k2;
  int sum, f1, f2, f3;
  num1 = 66, num2 = 66;
  Nixie(1, 10);
  num1 = ScanKey();
  //Nixie(2,num1);
  while(1)
    {
      Nixie(2, num1);
      P0 = 0;
      Nixie(1, 10);
      press = lScanKey();
      if(press == 25)
        {
          while(1)
            {
              Nixie(2, num1);
              P0 = 0;
              Nixie(1, 10);
              press = lScanKey();

              if(press != 25)
                {
                  num2 = ScanKey();
                  break;
                }
            }
          break;
        }
    }

  while(1)
    {
      Nixie(1, num1);
      P0 = 0;
      Nixie(2, num2);
      P0 = 0;
      press = lScanKey();

      if(press == 11)		//运算符“+”
        {
          while(1)
            {
              Nixie(1, 0);
              P0 = 0;
              Nixie(2, 0);
              P0 = 0;
              press = lScanKey();

              if(press == 25)
                {
                  while(1)
                    {
                      Nixie(2, 0);
                      P0 = 0;
                      Nixie(1, 0);
                      P0 = 0;
                      press = lScanKey();

                      if(press != 25)
                        {
                          num3 = ScanKey();		//输入第二组运算数
                          break;
                        }
                    }

                  break;
                }
            }

          while(1)
            {
              Nixie(2, num3);
              P0 = 0;
              Nixie(1, 10);
              press = lScanKey();

              if(press == 25)
                {
                  while(1)
                    {
                      Nixie(2, num3);
                      P0 = 0;
                      Nixie(1, 10);
                      press = lScanKey();

                      if(press != 25)				//反复扫描，直到按下第三个数字的手指松开后
                        {
                          num4 = ScanKey();
                          break;
                        }
                    }

                  break;
                }
            }

          break;
        }
    }

  while(1)
    {
      Nixie(1, num3);
      P0 = 0;
      Nixie(2, num4);
      P0 = 0;
      press = lScanKey();

      if(press == 12)
        {
          k1 = num1 * 10 + num2;
          k2 = num3 * 10 + num4;
          sum = k1 + k2;
          f1 = sum / 100, f2 = (sum / 10) % 10, f3 = sum % 10;

          while(1)
            {
              Nixie(1, f1);
              P0 = 0;
              Nixie(2, f2);
              P0 = 0;
              Nixie(3, f3);
              P0 = 0;
            }
        }
    }
}