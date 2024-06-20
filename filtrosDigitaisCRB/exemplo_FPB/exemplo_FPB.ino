#include<filtrosDigitaisCRB.h>
FPB valor;
void setup() {
  Serial.begin(9600);
  valor.setAlpha(0.9); //Faixa de valores: 0< alpha < 1
}

void loop() {
  int x = random(1000);
  float filtrado = valor.update(x);
  Serial.print(x);
  Serial.print("\t");
  Serial.println(filtrado);
  delay(400);
}
