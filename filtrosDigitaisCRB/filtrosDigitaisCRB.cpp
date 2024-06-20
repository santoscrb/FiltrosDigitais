/*
By, Santos CRB Soft, 2023
Version 2.1
OLDER: V 2.0, 2022
OLDER: V 1.2, 2021
OLDER: V 1.0, 2018
*/
#include "filtrosDigitaisCRB.h"
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//---------- Construtor
FPB::FPB()
{
  _isFirstRun = true;
  _alpha = 0.7;

}
//---------- Destrutor
FPB::~FPB()
{

}
//----------------------------------------------------------
void FPB::setAlpha(double alpha){
  _alpha = alpha;
}
//----------------------------------------------------------
double FPB::value(){
  return(_prevX);
}
//----------------------------------------------------------
double FPB::update(double value){
  double calc;
  if(_isFirstRun==true){
	_prevX= value;
	_isFirstRun = false;
  }
  calc = _alpha*_prevX + (1- _alpha)*value;
  _prevX = calc;
  value = _prevX;
  return(calc);
}
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//---------- Construtor
MediaMovel::MediaMovel()
{
  _isFirstRun = true;
  _dimension = 10;
  _ponteiro = 0;
  for(byte i=0;i<ORDEM_VETOR;i++){
    _vetor[i]=0;	  
  }
}
//---------- Destrutor
MediaMovel::~MediaMovel()
{
  
}
//----------------------------------------------------------
void MediaMovel::setDimension(byte dimension)
{
  _dimension = dimension;  
}
//----------------------------------------------------------
double MediaMovel::update(double value)
{
  if(_isFirstRun){
    _isFirstRun = false;	  
    for(byte i = 0;i<_dimension;i++){
	  _vetor[i] = value;
    }
	media = value;
  }
  else{
    _vetor[_ponteiro++]=value;
	if(_ponteiro==_dimension){
	  _ponteiro = 0;	
	}
	media = 0;
	for(byte i=0;i<_dimension;i++){
	  media+=_vetor[i];	
	}
	media/=_dimension;
  }  
  return(media);
}
//----------------------------------------------------------
double MediaMovel::value()
{
  return(media);
}
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//---------- Construtor
KF::KF()
{
  A = 1;
  H = 1;
  Q = 1;
  R = 1;
  x = 1;
  P = 1;
}
//---------- Destrutor
KF::~KF()
{
  
}
//----------------------------------------------------------
double KF::update(double value){
  xp= A*x; //                  Predição da variável
  Pp= A*P*A + Q;//             Predição da covariância do erro
  k= Pp*H/(H*Pp*H + R);//      Ganho de kalman 
  x= xp + k*(value - H*xp);//  Estimação da variável
  P=Pp - k*H*Pp; //            Cálculo da Covariância do erro
  return(x);
}
//----------------------------------------------------------
void KF::setA(double value){
  A = value;	
}
//----------------------------------------------------------
void KF::setH(double value){
  H = value;	
}
//----------------------------------------------------------
void KF::setQ(double value){
  Q = value;	
}
//----------------------------------------------------------
void KF::setR(double value){
  R = value;	
}
//----------------------------------------------------------
void KF::setX(double value){
  x = value;	
}
//----------------------------------------------------------
void KF::setP(double value){
  P = value;	
}
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------
//---------- Construtor
Mediana::Mediana()
{
  _isFirstRun = true;
  _dimension = 10;
  _ponteiro = 0;
  for(byte i=0;i<ORDEM_VETOR;i++){
    _vetor[i]=0;	  
  }
}
//---------- Destrutor
Mediana::~Mediana()
{
  
}
//----------------------------------------------------------
void Mediana::setDimension(byte dimension)
{
  _dimension = dimension;  
}
//----------------------------------------------------------
double Mediana::update(double value)
{
  if(_isFirstRun){
    _isFirstRun = false;	  
    for(byte i = 0;i<_dimension;i++){
	  _vetor[i] = value;
    }
	mediana = value;
  }
  else{
    _vetor[_ponteiro++]=value;
	if(_ponteiro==_dimension){
	  _ponteiro = 0;	
	}
    OrdenaCrescente();
    if(_dimension%2==0){
      mediana = (Vcrescente[_dimension/2-1]+Vcrescente[_dimension/2])/2;
    }else{
      mediana = Vcrescente[_dimension/2];
    }	  
  }  
  return(mediana);
}
//----------------------------------------------------------
double Mediana::value(){
  return(mediana); 	
}
//----------------------------------------------------------
void Mediana::OrdenaCrescente()
{
  for(uint8_t i=0;i<_dimension;i++){
    Vcrescente[i] = _vetor[i];
  }
  for(uint8_t i=0;i<_dimension;i++){
    for(uint8_t j=i+1;j<_dimension;j++){
      if(Vcrescente[i]>Vcrescente[j]){
        double aux = Vcrescente[i];
        Vcrescente[i] = Vcrescente[j];
        Vcrescente[j] = aux;
      }
    }
  }
}
