#include<filtrosDigitaisCRB.h>

Mediana vx;
float x;
uint8_t i=0;
uint8_t vetor[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6};
void setup() {
  Serial.begin(9600);
  vx.setDimension(5);
}

void loop() {
  x = vx.update(vetor[i++]);
  if(i==15){
    i=0;
  }
  Serial.println(String(i)+"\t"+String(vetor[i])+"\t"+String(x));
  delay(1000);
}
