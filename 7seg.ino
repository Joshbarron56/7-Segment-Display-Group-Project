
void setup() {


}

void loop() {
  
  int A=0;
  int B=0;
  int C=0;
  int D=0;

  int G1,G2,G3,G4,G5,G6,G7;
  int x3=0, x4=0, x5=0, x6=0, x7=0;
  pinMode(8, INPUT);
  pinMode(9, INPUT); 
  pinMode(10, INPUT);
  pinMode(11, INPUT); 
  D=digitalRead(8);
  C=digitalRead(9);
  B=digitalRead(10);
  A=digitalRead(11);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  G1=nand2(!B,D);
  G2=nand2(!C,D);
  G3=nand2(A,!C);
  G4=nand3(B,C,!D);
  G5=nand2(C,D);
  G6=nand2(B,C);
  G7=nand2(A,D);
  x3=nand4(G1, G2, G3, G4);
  x4=nand2(G1, G2);
  x5=nand3(G1, G3, G5);
  x6=nand4(!A, B, G4, G2);
  x7=nand4(G6, G2, G3, G7);
  digitalWrite(1,nand2((!B), (!C)));
  digitalWrite(2,nand3((!A), (!C), D));
  digitalWrite(3,x3);
  digitalWrite(4,x4);
  digitalWrite(5,x5);
  digitalWrite(6,x6);
  digitalWrite(7,x7);
  delay(100);

/* Below are the NAND gate funtions that I created and call above to do the logic.
 *  the number after the nand refers to the number of inputs.
*/
  
}
int nand2(int I1, int I2){
  if(I1==1&&I2==1)
    return 0;
  else
    return 1;
}
int nand3(int I1, int I2, int I3){
  if(I1==1&&I2==1&&I3==1)
    return 0;
  else
    return 1;
}
int nand4(int I1, int I2, int I3, int I4){
  if(I1==1&&I2==1&&I3==1&&I4==1)
    return 0;
  else
    return 1;
}
