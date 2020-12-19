// TODO
#define trigPin 8
#define echoPin 9
#define minLevel 5
//#define maxLevel 15
#define relayPin  6
//#define tiempo_riego 2*60*1000UL
//#define dia 24*60*60*1000UL

unsigned long hour = 60*60*1000UL;
unsigned long watering_time = 2*60*1000UL;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  //sensor.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

// turn the LED on (HIGH is the voltage level)
void led_on() {
  digitalWrite(LED_BUILTIN, HIGH);   
  }

// turn the LED off by making the voltage LOW
void led_off () {
  digitalWrite(LED_BUILTIN, LOW);    
  }

void relay_on () {
  digitalWrite(relayPin, HIGH);
  }

void relay_off () {
  digitalWrite(relayPin, LOW);
  }

// return distance (cm) to water surface
float get_distance() {
  long duration;
  float distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
  }

void loop() {
  /*
  led_on();
  delay(1000);
  led_off();
  delay(1000);
  */

  float distance = get_distance();
  Serial.println(distance); 

  if ( distance > minLevel ) {
    Serial.println("distance > minLevel"); 
    led_on();
    relay_on();
    Serial.println("pump.enable()"); 
    delay(watering_time);
    led_off();
    relay_off();
    Serial.println("pump.disable()"); 
    }
  else {
    Serial.println("distance <= minLevel"); 
    led_off();
    relay_off();
    }
    

  // waiting 24h. dirty hack to delay for 1d without integer overflow
  int j = 0;
  while (j<24) {
    delay(hour);
    j++;
    }
  
  
  Serial.print("distance: "  );
  Serial.println(distance); 
}
