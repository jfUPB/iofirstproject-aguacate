void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        WAIT_TIMEOUT
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan
    // su valor entre llamadas a task1)
    static uint32_t lasTime = 0;

    // Constantes

    constexpr uint32_t INTERVAL = 1000;
    constexpr uint8_t button1Pin = 12;
    constexpr uint8_t button2Pin = 13;
    constexpr uint8_t button3Pin = 32;
    constexpr uint8_t ledRed = 14;
    constexpr uint8_t ledGreen = 25;
    constexpr uint8_t ledBlue = 26;
    constexpr uint8_t ledYellow = 27;

    // MÁQUINA de ESTADOS

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        pinMode(button1Pin, INPUT_PULLUP);
        pinMode(button2Pin, INPUT_PULLUP);
        pinMode(button3Pin, INPUT_PULLUP);
        pinMode(ledRed, OUTPUT);
        pinMode(ledGreen, OUTPUT);
        pinMode(ledBlue, OUTPUT);
        pinMode(ledYellow, OUTPUT);
        lasTime = millis();
        task1State = Task1States::WAIT_TIMEOUT;

        break;
    }
    case Task1States::WAIT_TIMEOUT:
    {
        uint8_t btn1State = digitalRead(button2Pin);
        uint8_t btn2State = digitalRead(button2Pin);
        uint8_t btn3State = digitalRead(button3Pin);
        uint32_t currentTime = millis();

        // Evento 1:
        if ((currentTime - lasTime) >= INTERVAL)
        {
            lasTime = currentTime;
            printf("btn1: %d,btn2: %d, btn3: %d, btn4: %d\n", btn2State, btn3State);
        }

        // Evento 2
        if (btn2State == LOW && btn3State == LOW)
        {
            digitalWrite(ledRed, HIGH);
            digitalWrite(ledBlue, LOW);
            digitalWrite(ledYellow, LOW);
            digitalWrite(ledGreen, LOW);
            Serial.println("Se encendio el LED 14");
        }
            
        // Evento 3
        if (btn2State == LOW && btn3State == HIGH)
        {
            digitalWrite(ledGreen, HIGH);
            digitalWrite(ledBlue, LOW);
            digitalWrite(ledRed, LOW);
            digitalWrite(ledYellow, LOW);
            Serial.println("Se encendio el LED 25");
        }
            
        // Evento 4
        if (btn2State == HIGH && btn3State == LOW)
        {
            digitalWrite(ledBlue, HIGH);
            digitalWrite(ledYellow, LOW);
            digitalWrite(ledRed, LOW);
            digitalWrite(ledGreen, LOW);
            Serial.println("Se encendio el LED 26");
        }
            
        // Evento 5
        if (btn2State == HIGH && btn3State == HIGH)
        {
            digitalWrite(ledYellow, HIGH);
            digitalWrite(ledBlue, LOW);
            digitalWrite(ledRed, LOW);
            digitalWrite(ledGreen, LOW);
            Serial.println("Se encendio el LED 27");
        }
            
        if (btn1State == LOW)
        {
            digitalWrite(ledYellow, LOW);
        }
            

        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
