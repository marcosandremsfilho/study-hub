const int pinThermistor = A1;

const double B = 4050.0;  // Beta, tal informação pode ser encontrada no datasheet
const double R25 = 22000.0; // Valor da resistencia do thermistor quando o mesmo se encontra em 25ºC
const double T25 = 273.0 + 25.0; // Faz a conversão dos 25ºC para Kelvin somando 273
const double Rx = R25 * exp(-B/T25); 

const double vcc = 5.0; // Tensão do circuito
const double R = 10000.0; // Valor do resistor em série com o termistor

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  double t = analogRead(A1);
  double v = (vcc*t)/1024.0; // Faz se uma regra de 3 simples para encontrar a queda de tensão
  double RT = (vcc*R)/v - R;  // Calcula-se a queda de tensão no thermistor afim de encontrar a resistencia do termistor

  double temperatura = B/ log(RT/Rx); // Essa é a equação para converter a resistencia na temperatura que o sensor se encontra

  Serial.print("Temperatura em Kelvin: ");
  Serial.print (temperatura); // Mostra a temperatura no terminal em Kelvin
  Serial.println(" K");
  Serial.print("Temperatura em Graus: ");
  Serial.print (temperatura - 273.0); // Mostra a temperatura no terminal subtraindo 273 para mostrar a temperatura em graus Celsius
  Serial.println(" ºC");
}
