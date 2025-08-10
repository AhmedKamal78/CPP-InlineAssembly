#include <iostream>
using namespace std;

#include "ConsoleUtils.h"
ConsoleUtils utils;


// InlineAssembly
//============================================================================================
/*
    INTRODUCTION TO INLINE ASSEMBLY IN MSVC (32-BIT ONLY)

    This program demonstrates how to embed basic x86 assembly code within a C++ program
    using the __asm keyword. Note that inline assembly using __asm is only supported in
    32-bit (x86) builds of Visual Studio — it does NOT work in 64-bit (x64) mode.

    KEY CONCEPTS:

    1. REGISTERS:
       The CPU has general-purpose registers used for operations. Here are a few:
        - EAX, EBX, ECX, EDX : 32-bit general-purpose registers
        - BX is the lower 16 bits of EBX, and often used in legacy or partial-width operations
        - EAX is commonly used for arithmetic results

    2. BASIC ALU OPERATION:
       ALU (Arithmetic Logic Unit) performs operations like addition, subtraction, etc.
       In this example, we use:
         - `add eax, ebx` to perform integer addition
         - `cmp eax, ebx` to compare two values

    3. FLAGS:
       Most ALU operations affect the FLAGS (EFLAGS) register, which includes:
        - ZF (Zero Flag)    : Set if result is zero (used for equality)
        - CF (Carry Flag)   : Set if there's unsigned overflow
        - OF (Overflow Flag): Set if signed overflow occurs
        - SF (Sign Flag)    : Set if result is negative
       Conditional jumps like `je` (jump if equal) rely on these flags.

    4. CMP AND CONDITIONAL JUMP:
       `cmp eax, ebx` sets the flags based on (eax - ebx), without changing either register.
       `je label` jumps if the values are equal (i.e., Zero Flag is set).

    5. DATA WIDTH:
       We demonstrate mixing 32-bit and 16-bit registers using `bx` (part of `ebx`) for practice.

    The program adds two integers, compares them, and sets a C++ flag if they're equal.
    All operations are done using x86 assembly embedded within the C++ function.
*/


void InlineAssembly() {
     int a = 10;
     int b = 10;
     int sum = 0;
     int isEqual = 0;  // Will be set to 1 if a == b

    __asm {
        mov eax, a;        // Load variable 'a' into EAX
        mov ebx, b;        // Load variable 'b' into EBX
        add eax, ebx;      // Add EAX and EBX, result in EAX
        mov sum, eax;      // Store result from EAX into C++ variable 'sum'

        mov eax, a;        // Reload 'a' into EAX for comparison
        cmp eax, ebx;      // Compare EAX with EBX (sets flags)
        //je equalLabel;     // Jump to label if equal (ZF = 1)

        xor bx, bx;        // Clear BX register (16-bit version of EBX)
        
        //--- following line has error
        //mov bx, b;       // Load lower 16 bits of 'b' into BX (demonstration)
        // 
        //--- way around to fix error
        mov eax, b;        // load full 32 - bit 'b' into eax
        mov bx, ax;        // move lower 16 bits of eax into bx

        //xor bx, bx;        // Clear BX register (16-bit version of EBX)
        //mov bx, b;         // Load lower 16 bits of 'b' into BX (demonstration)
    //    jmp doneLabel;     // Skip the 'equal' label if not equal

    //equalLabel:
    //    mov isEqual, 1;    // Set flag in C++ variable if a == b

    //doneLabel:
    }

     cout << "Sum is: " << sum << endl;
     cout << "Are a and b equal? " << (isEqual ? "Yes" : "No") << endl;

     cout << "1 last change";
}


//*****************************************
//					MAIN
//*****************************************
int main(int argc, char* argv[])
{
#pragma region header
	//--- setup console utils   
	utils.enableVirtualTerminal();
	utils.setBackgroundColor(ConsoleColor::Blue);
	utils.clearConsole();

	//--- show app title
	utils.setForegroundColor(ConsoleColor::BrightWhite);
	cout << "+-------------------------------+\n";
	cout << "| Console App Networking??????  |\n";
	cout << "+-------------------------------+\n\n";
#pragma endregion


	//--- App BODY --------------------------------
    InlineAssembly();
	//---------------------------------------------


#pragma region footer
	//--- show credits
	utils.setForegroundColor(ConsoleColor::White);
	std::cout << std::endl;
	utils.showCredits();

	system("pause");
	// this is a better way to avoid unnec instructions when debugger finishes
	// we also select this option ==> Tools->Options->Debugging->Automatically close the console when debugging stops.

	//--- exit console
	return 0;
#pragma endregion
}