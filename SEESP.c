#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

///#define p 0x50
// Letras de teclado tipo "Virtual-Key Codes" de Microsoft Windows.
#define a 0x41
#define e 0x45
#define i 0x49
#define o 0x4F
#define u 0x55
#define n 0x4E

// Símbolos de tipo "Virtual-Key Codes"" de Microsoft Windows.
#define inter VK_OEM_2 // El símbolo ?
#define excla 0x31 // La tecla en donde viene el ! ( o el 1 ).

// Letras minúsculas con acento en UNICODE.
#define aConAcentoUnicode 0x00E1
#define eConAcentoUnicode 0x00E9
#define iConAcentoUnicode 0x00ED
#define oConAcentoUnicode 0x00F3
#define uConAcentoUnicode 0x00FA
#define nConTildeUnicode  0x00F1
#define shiftDerecho VK_RSHIFT

// Letras mayúsculas con acento en UNICODE.
#define AConAcentoUnicode 0x00C1
#define EConAcentoUnicode 0x00C9
#define IConAcentoUnicode 0x00CD
#define OConAcentoUnicode 0x00D3
#define UConAcentoUnicode 0x00DA
#define NConTildeUnicode  0x00D1
#define shiftIzquierdo VK_LSHIFT

//Símbolos Unicode
#define interInicialUnicode 0x00BF // Signo de interrogación incial ¿
#define exclaInicialUnicode 0x00A1 // Signo de exclamación inicial ¡

HWND ventana;

int main(void)
{
    short keyState0; // Para el shift derecho
    short keyState1; // Para la á
    short keyState2; // Para la é
    short keyState3; // Para la í
    short keyState4; // Para la ó
    short keyState5; // Para la ú
    short keyState7; // Para la ñ
    short keyState8; // Para el ¿
    short keyState9; // Para el ¡
    
    short keyState6; // Para el shift izquierdo
    
    //bool isToggled; // indica si está activo o no algún botón.
    
    bool isDown0; // Para el shift derecho
    bool isDown1; // Para la á 
    bool isDown2; // Para la é
    bool isDown3; // Para la í
    bool isDown4; // Para la ó
    bool isDown5; // Para la ú
    bool isDown7; // Para la ñ
    bool isDown8; // Para el ¿
    bool isDown9; // Para el ¡
        
    bool isDown6; // Para el shift izquierdo
    
    ventana = GetForegroundWindow();
    ShowWindow(ventana, SW_HIDE);
    while(1)
    {
        // Verificacion de parámetros.
        keyState0 = GetKeyState(shiftDerecho);
        keyState1 = GetKeyState(a);
        keyState2 = GetKeyState(e);
        keyState3 = GetKeyState(i);
        keyState4 = GetKeyState(o);
        keyState5 = GetKeyState(u);        
        keyState7 = GetKeyState(n);
        keyState8 = GetKeyState(inter);
        keyState9 = GetKeyState(excla);
        
        keyState6 = GetKeyState(shiftIzquierdo);
        
        ///keyState3 = GetKeyState(p);
        
        // Para que no se quede presionada la tecla, que no se esté leyendo
        // siempre.
        isDown0 = keyState0 & 0x8000; // Para el shiftDerecho
        isDown1 = keyState1 & 0x8000;
        isDown2 = keyState2 & 0x8000;
        isDown3 = keyState3 & 0x8000;
        isDown4 = keyState4 & 0x8000;
        isDown5 = keyState5 & 0x8000;
        isDown7 = keyState7 & 0x8000;
        isDown8 = keyState8 & 0x8000;
        isDown9 = keyState9 & 0x8000;
                
        isDown6 = keyState6 & 0x8000; // Para el shiftIzquierdo
        
        //isToggled = keyState1 & 1;
         
        if(isDown0 && !isDown6) // Para el shiftDerecho
        {
           if(isDown1) // Para la letra a
           {
              Sleep(100); // Para que solo poner una vez lo de abajo.
              ///printf("Se ha presionado la letra a.\n");
           
              // Simulate a key press
              keybd_event( VK_BACK,
                          0x45,
                          KEYEVENTF_EXTENDEDKEY | 0,
                          0 );

              // Simulate a key release
              keybd_event( VK_BACK,
                          0x45,
                          KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                          0);
           
              KEYBDINPUT kb = {0};
              INPUT Input = {0};

              // down
              kb.wScan = aConAcentoUnicode;
              kb.dwFlags = KEYEVENTF_UNICODE;
              Input.type = INPUT_KEYBOARD;
              Input.ki = kb;
              SendInput(1,&Input,sizeof(Input));

              // up
              kb.wScan = aConAcentoUnicode;
              kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
              Input.type = INPUT_KEYBOARD;
              Input.ki = kb;
              SendInput(1,&Input,sizeof(Input));
            }
            else if(isDown2) // Para la letra e
            {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = eConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = eConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
            }
            
            else if(isDown3) // Para la letra i
            {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = iConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = iConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
            }
            else if(isDown4) // Para la letra o
            {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = oConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = oConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
            }
            else if(isDown5) // Para la letra u
            {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = uConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = uConAcentoUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
           
            }
            else if(isDown7) // Para la letra ñ
            {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = nConTildeUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = nConTildeUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
           
            }
        }
        else if(isDown6) // Para el shiftIzquierdo
        {
           if(isDown8) // Para la letra ¿
           {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = interInicialUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = interInicialUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
           
           }
           if(isDown9) // Para la letra ¡
           {
               Sleep(100); // Para solo poner una vez lo de abajo.
               ///printf("Se ha presionado la letra a.\n");
           
               // Simulate a key press
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | 0,
                           0 );

               // Simulate a key release
               keybd_event( VK_BACK,
                           0x45,
                           KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                           0);
           
               KEYBDINPUT kb = {0};
               INPUT Input = {0};

               // down
               kb.wScan = exclaInicialUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE;
               Input.type = INPUT_KEYBOARD;
               Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));

               // up
               kb.wScan = exclaInicialUnicode;
               kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
               Input.type = INPUT_KEYBOARD;
	              Input.ki = kb;
               SendInput(1,&Input,sizeof(Input));
           
           }
           if(isDown0) // Para el shiftDerecho
           {
              if(isDown1) // Para la letra a
              {
                 Sleep(100); // Para solo poner una vez lo de abajo.
                 ///printf("Se ha presionado la letra a.\n");
           
                 // Simulate a key press
                 keybd_event( VK_BACK,
                             0x45,
                             KEYEVENTF_EXTENDEDKEY | 0,
                             0 );

                             // Simulate a key release
                 keybd_event( VK_BACK,
                             0x45,
                             KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                             0);
           
                 KEYBDINPUT kb = {0};
                 INPUT Input = {0};

                 // down
                 kb.wScan = AConAcentoUnicode;
                 kb.dwFlags = KEYEVENTF_UNICODE;
                 Input.type = INPUT_KEYBOARD;
                 Input.ki = kb;
                 SendInput(1,&Input,sizeof(Input));

                 // up
                 kb.wScan = AConAcentoUnicode;
                 kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
                 Input.type = INPUT_KEYBOARD;
                 Input.ki = kb;
                 SendInput(1,&Input,sizeof(Input));
              }
              else if(isDown2) // Para la letra e
              {
                 Sleep(100); // Para poner una vez lo de abajo.
                 ///printf("Se ha presionado la letra a.\n");
           
                 // Simulate a key press
                 keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | 0,
                              0 );

                 // Simulate a key release
                 keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                              0);
           
                 KEYBDINPUT kb = {0};
                 INPUT Input = {0};

                 // down
                 kb.wScan = EConAcentoUnicode;
                 kb.dwFlags = KEYEVENTF_UNICODE;
                 Input.type = INPUT_KEYBOARD;
                 Input.ki = kb;
                 SendInput(1,&Input,sizeof(Input));

                 // up
                 kb.wScan = EConAcentoUnicode;
                 kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
                 Input.type = INPUT_KEYBOARD;
	         Input.ki = kb;
	         SendInput(1,&Input,sizeof(Input));
               }
               else if(isDown3) // Para la letra i
               {
                  Sleep(100); // Para solo poner una vez lo de abajo.
                  ///printf("Se ha presionado la letra a.\n");
           
                  // Simulate a key press
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | 0,
                              0 );

                  // Simulate a key release
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                              0);
           
                  KEYBDINPUT kb = {0};
                  INPUT Input = {0};

                  // down
                  kb.wScan = IConAcentoUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE;
                  Input.type = INPUT_KEYBOARD;
                  Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));

                  // up
                  kb.wScan = IConAcentoUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
                  Input.type = INPUT_KEYBOARD;
                  Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));
               }
               else if(isDown4) // Para la letra o
               {
                  Sleep(100); // Para solo poner una vez lo de abajo.
                  ///printf("Se ha presionado la letra a.\n");
           
                  // Simulate a key press
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | 0,
                              0 );

                  // Simulate a key release
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                              0);
           
                  KEYBDINPUT kb = {0};
                  INPUT Input = {0};

                  // down
                  kb.wScan = OConAcentoUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE;
                  Input.type = INPUT_KEYBOARD;
                  Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));
                  
                  // up
                  kb.wScan = OConAcentoUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
                  Input.type = INPUT_KEYBOARD;
	          Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));
               }
               else if(isDown5) // Para la letra u
               {
                  Sleep(100); // Para solo poner una vez lo de abajo.
                  ///printf("Se ha presionado la letra a.\n");
           
                  // Simulate a key press
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | 0,
                              0 );

                  // Simulate a key release
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                              0);
           
                  KEYBDINPUT kb = {0};
                  INPUT Input = {0};

                  // down
                  kb.wScan = UConAcentoUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE;
                  Input.type = INPUT_KEYBOARD;
                  Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));

                  // up
                  kb.wScan = UConAcentoUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
                  Input.type = INPUT_KEYBOARD;
                  Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));
               }
               else if(isDown7) // Para la letra Ñ
               {
                  Sleep(100); // Para solo poner una vez lo de abajo.
                  ///printf("Se ha presionado la letra a.\n");
              
                  // Simulate a key press
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | 0,
                              0 );

                  // Simulate a key release
                  keybd_event( VK_BACK,
                              0x45,
                              KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                              0);
           
                  KEYBDINPUT kb = {0};
                  INPUT Input = {0};

                  // down
                  kb.wScan = NConTildeUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE;
                  Input.type = INPUT_KEYBOARD;
                  Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));

                  // up
                  kb.wScan = NConTildeUnicode;
                  kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
                  Input.type = INPUT_KEYBOARD;
	          Input.ki = kb;
                  SendInput(1,&Input,sizeof(Input));
               }
           }
        }
    }
}
