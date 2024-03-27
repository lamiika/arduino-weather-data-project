/******************************************************************************
 * File: ./Software.h
 * Requires: Keypad.h LCD.h NET.h Utils.h
 ******************************************************************************/
namespace Software
{
    void VARstats(void)
    {
        LCD::Clear();
        LCD::Print("WindDirection:"); 
        LCD::SetCursor(0,1);
        LCD::Print("  Value: "); 
        LCD::Print( WindDirection::Value() ); 
        LCD::Print(" deg"); 
        LCD::SetCursor(0,2);
        LCD::Print("WindSpeed:"); 
        LCD::SetCursor(0,3);
        LCD::Print("  Value: "); 
        LCD::Print( WindSpeed::Value() ); 
        LCD::Print(" m/s");
    }

    void IPstats(void)
    {
        LCD::Clear();
        LCD::Print("IP ");     LCD::Print(NET::ip);
        LCD::SetCursor(0,1);    
        LCD::Print("GW ");     LCD::Print(NET::gw);
        LCD::SetCursor(0,2);
        LCD::Print("DNS ");    LCD::Print(NET::dns);
        LCD::SetCursor(0,3);
        LCD::Print("MASK ");   LCD::Print(NET::subnet);
    }

    void HWstats(void)
    {
        LCD::Clear();
        LCD::Print( NET::Status::Hardware() );
        LCD::SetCursor(0,1);
        LCD::Print( NET::Status::Link() );
        LCD::SetCursor(0,2);
        LCD::Print("MAC ");     LCD::Print(NET::mac2string());
        LCD::SetCursor(0,3);
    }

    void Bootmessage(void)
    {
        LCD::Clear();
        LCD::Print("Arduino Boot Online");
    }

    void Default(void)
    {
        LCD::Clear();
        LCD::Print("Unmapped key");
    }

    inline void Init(void)
    {
        for(uint8_t i=0 ; i < Keypad::num_keys ; i++)
            Keypad::AttachKeyHandler(i,Default);

        Keypad::AttachKeyHandler(16,Bootmessage);

        Keypad::AttachKeyHandler( KEY(STAR) ,VARstats);
        Keypad::AttachKeyHandler( KEY(A) ,IPstats);
        Keypad::AttachKeyHandler( KEY(B) ,HWstats);
    }
}