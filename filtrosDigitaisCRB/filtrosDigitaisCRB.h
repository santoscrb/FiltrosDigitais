/*
By, Santos CRB Soft, 2023
Version 2.1
OLDER: V 2.0, 2022
OLDER: V 1.2, 2021
OLDER: V 1.0, 2018
*/
#ifndef _filtrosDigitais_SantosCRB 
#define _filtrosDigitais_SantosCRB
#include <Arduino.h>

#define ORDEM_VETOR 15 //Mudar aqui se quiser reduzir o tamanho dos vetores
//------------------
//------------------
class Mediana
{
public:
  Mediana();
  ~Mediana();
  //void setup()
  void setDimension(byte dimension);
  //void loop()
  double update(double value);
  double value();
private:
  void OrdenaCrescente();
  double mediana;
  byte _dimension;
  byte _ponteiro;
  double _vetor[ORDEM_VETOR];
  double Vcrescente[ORDEM_VETOR];
  boolean _isFirstRun;
};
//------------------
//------------------
class FPB
{
public:
  FPB();                //construtor
  ~FPB();               //destrutor
  //void setup()
  void setAlpha(double alpha);
  //void loop()
  double update(double value);
  double value();
private:
  double _alpha;
  boolean _isFirstRun;
  double _prevX;
};
//------------------
//------------------
class MediaMovel
{
public:
  MediaMovel();
  ~MediaMovel();
  //void setup()
  void setDimension(byte dimension);
  //void loop()
  double update(double value);
  double value();
private:
  byte _dimension;
  byte _ponteiro;
  double _vetor[ORDEM_VETOR];
  boolean _isFirstRun;
  double media;
};
//------------------
//------------------
class KF
{
public:
  KF();
  ~KF();
  //void setup()
  void setA(double value);
  void setQ(double value);
  void setH(double value);
  void setX(double value);
  void setR(double value);
  void setP(double value);
  //void loop()
  double update(double value);
private:
  double A;  // transicao de estado
  double H;  // Relaciona a variavel estado com a medição
  double Q;  // ruido do sistema
  double R;  // ruido do sensor
  double x;  // valor inicial da variavel estado
  double P;  // covariancia de erro inicial
  double xp; // predição da variavel estado
  double Pp; // predição da covariancia do erro
  double k;  // ganho de kalman
};
#endif
