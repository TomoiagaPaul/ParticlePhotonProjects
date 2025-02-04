int leds[] = {D1, D2, D3};

void wave(const char *event, const char *data){
    Serial.println(data);
    
    if (String(data) == "wave"){
        for(int i = 0; i < arraySize(leds); i++){
            digitalWrite(leds[i], HIGH);
            delay(100);
            digitalWrite(leds[i], LOW);
        }
        delay(800);
        for(int i = arraySize(leds); i >= 0; i--){
            digitalWrite(leds[i], HIGH);
            delay(100);
            digitalWrite(leds[i], LOW);
        }
    }else if (String(data) == "pat"){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < arraySize(leds); j++)
                digitalWrite(leds[j], HIGH);
            delay(200);
            for(int j = 0; j < arraySize(leds); j++)
                digitalWrite(leds[j], LOW);
            delay(200);
        }
    }
}

void setup() {
    Serial.begin(9600);
    
    
    
    for(int i = 0; i < arraySize(leds); i++)
        pinMode(leds[i], OUTPUT);
    
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", wave);
}

void loop() {
}
