#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Dynamixel Dxl(1);

void setup()
{
  Dxl.begin(3);

  Dxl.wheelMode(1);
  Dxl.wheelMode(2);
}

void loop()
{
  char arr[10] = {};
  int cnt = 0;

  while (SerialUSB.available())
  {
    arr[cnt] = (char)SerialUSB.read();
    cnt++;
  }

  int rot = 0;
  int init_size = strlen(arr);
  char delim[] = ",";
  char *ptr = strtok(arr, delim);
  
  int check = 0;
  int a = 0;

  while (ptr != NULL)
  {
    if (a == 0)
      check = atoi(ptr);
    if (a == 1)
    {
      rot = atoi(ptr);
    }
    ptr = strtok(NULL, delim);
    a++;
  }
  

  if (check==1)
  {
    Dxl.writeWord(1, 32, 2046);
    Dxl.writeWord(2, 32, 2046);
    SerialUSB.println("up");
    delay(10 * rot);
    Dxl.writeWord(1, 32, 0);
    Dxl.writeWord(2, 32, 0);
  }

  if (check==2)
  {
    Dxl.writeWord(1, 32, 1023);
    Dxl.writeWord(2, 32, 1023);
    SerialUSB.println("down");
    delay(10 * rot);
    Dxl.writeWord(1, 32, 0);
    Dxl.writeWord(2, 32, 0);
  }
  check=0;
  rot=0;
}
