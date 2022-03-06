/*
void func(void)
{
    // lcd.clear();
    //  oled.home();
    lcd.setCursor(1, 1);
    lcd.print(F("Press to ret"));
    uint8_t asd = 0;

    // enc.tick();

    while (1)
    {
        asd = constrain(asd, 0, 59);
        enc.tick();
        if (enc.left())
            if (asd > 0)
                (asd--);
        if (enc.right())
            (asd++);
        lcd.setCursor(10, 1);
        if (asd < 10)
            lcd.print(0);
        lcd.print(asd);
        Serial.println(asd);
        if (enc.click())
            Serial.println("Запомнил");
        if (enc.held())
            return; // return возвращает нас в предыдущее меню
    }
}
void menu()
{
    if (enc.right() or enc.left())
    {                                                       
        enc.counter = constrain(enc.counter, 0, ITEMS - 1); 
    }

    while (1)
    { // lcd.print(pointer);
        lcd.setCursor(0, 1);
        lcd.print(">");
        enc.tick();
        if (enc.counter == 0)
            lcd.print(F("Date and Time  "));
        else if (enc.counter == 1)
            lcd.print(F("Podogrev pola  "));
        else if (enc.counter == 2)
            lcd.print(F("Podsvetka      "));
        else if (enc.counter == 3)
            lcd.print(F("Otkrytie okna  "));
        else if (enc.counter == 4)
        {
            lcd.print(F("Poliv          "));
            if (enc.click())
                func();
        }
        else if (enc.counter == 5)
            lcd.print(F("Monitoring     "));
        else if (enc.counter == 6)
        {
            lcd.print(F("Press to return"));

            if (enc.click())
                // lcd.clear();
                return; // return возвращает нас в предыдущее меню
        }
        if (enc.held())
            return; // retu
        // Serial.println(pointer);
        if (enc.click())
        { // Нажатие на ОК - переход в пункт меню
            switch (enc.counter)
            { // По номеру указателей располагаем вложенные функции (можно вложенные меню)
            case 0:
                func();
                break; // По нажатию на ОК при наведении на 0й пункт вызвать функцию
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
                // И все остальные
            }
        }
    }
}
*/