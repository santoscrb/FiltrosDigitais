#include<filtrosDigitaisCRB.h>
Mediana valor;
void setup() {
  valor.setDimension(10); //Dimensao entre 1 e 15
  Serial.begin(9600);
}

void loop() {
  int x = random(1000);
  float filtrado = valor.update(x);
  Serial.print(x);
  Serial.print("\t");
  Serial.println(filtrado);
  delay(400);
}
