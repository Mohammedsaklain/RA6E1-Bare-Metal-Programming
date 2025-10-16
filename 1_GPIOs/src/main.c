#include "main.h"

int main(void)
{
  PORT_Pin_Init(PORT4, 7, OUTPUT);  /* LED2 at P407 as OUTPUT */
  PORT_Pin_Init(PORT2, 5, INPUT);   /* User Switch (S1) at P205 as INPUT */
  uint16_t state;

  while (1){
    state = PORT_Pin_Read(PORT2, 5);
    if (state == 0){  /* Initially the Pin is PULLED-UP, When User presses, then goes to Zero*/
      for (int i = 0; i < 9000; i++){}
      state = PORT_Pin_Read(PORT2, 5);
      if (state == 0){
        PORT_Pin_Toggle(PORT4, 7);
      }
    }
  }
  return 0;
}
