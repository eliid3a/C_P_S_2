/******
 * MODELO: C_P_S_2
 
   Control de apertura de puerta para sotano
   para control de acceso de puertas de Olan de Mexico
   ---- Programa para arduino nano Puerta Olan
   Version: 2.2  11/07/2019
   by eliid3a@gmail.com
      
*******/
  //INPUT_PULLUP
int B_P_A = 2; // Boton puerta a
int B_P_B = 3; // Boton de puerta desde b
int B_S_E = 4; // Boton salida emergencia
int S_P_A = 5; // Sensor puerta A
int S_P_G = 6; // Sensor puerta grande

  //OUTPUT
int S_PUERTA = 8; // Salida de puerta
int S_S_A = 9; // Salida de sensor A
int S_S_G = 10; //Salida de sensor G

int state1;
int state2;
int state3;
int state4;
int state5;

void setup() {
  // INPUT_PULLUP
  pinMode(B_P_A, INPUT_PULLUP);
  pinMode(B_P_B, INPUT_PULLUP);
  pinMode(B_S_E, INPUT_PULLUP);
  pinMode(S_P_A, INPUT_PULLUP);
  pinMode(S_P_G, INPUT_PULLUP);
  // OUTPUT
  pinMode(S_PUERTA, OUTPUT); //salida a chapa A
  pinMode(S_S_A, OUTPUT);
  pinMode(S_S_G, OUTPUT);
  
}


void loop() {
    
  boton_pa();
  sensor_pa();
  sensor_pg();  

}


void boton_pa(){
  state1 = digitalRead(B_P_A);  // Si se toca el boton de puerta A abre puerta A
  state2 = digitalRead(B_P_B);  // Si se toca el boton desde bodega abre puerta A
  state3 = digitalRead(B_S_E);  // si se toca el botn emergencia abre puerta A
  
  if(state1 == LOW || state2 == LOW || state3 == LOW){
    digitalWrite(S_PUERTA, LOW);
  }  else{
    digitalWrite(S_PUERTA, HIGH);
  }
}



void sensor_pa(){ // Si se activa sensor de puerta abierta activa luz
  state4 = digitalRead(S_P_A);
  if(state4 == LOW){
    digitalWrite(S_S_A, LOW);
  }  else{
    digitalWrite(S_S_A, HIGH);
  }
}



void sensor_pg(){ //Si se activa sensor de puerta Grande abierta activa luz
  state5 = digitalRead(S_P_G);
  if(state5 == LOW){
    digitalWrite(S_S_G, LOW);
  }  else{
    digitalWrite(S_S_G, HIGH);
  }
}
