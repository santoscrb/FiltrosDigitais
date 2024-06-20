#include<filtrosDigitaisCRB.h>
KF valor;
void setup() {
  Serial.begin(9600);
  valor.setA(1); 
  valor.setQ(0); 
  valor.setH(1); 
  valor.setR(4); 
  valor.setP(6); 
  valor.setX(100); //Valor estimado inicial
}

void loop() {
  int x = random(1000);
  float filtrado = valor.update(x);
  Serial.print(x);
  Serial.print("\t");
  Serial.println(filtrado);
  delay(400);
}
