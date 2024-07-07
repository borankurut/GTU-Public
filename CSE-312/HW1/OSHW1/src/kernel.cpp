
#include <common/types.h>
#include <gdt.h>
#include <memorymanagement.h>
#include <hardwarecommunication/interrupts.h>
#include <syscalls.h>
#include <hardwarecommunication/pci.h>
#include <drivers/driver.h>
#include <drivers/keyboard.h>
#include <drivers/mouse.h>
#include <drivers/vga.h>
#include <drivers/ata.h>
#include <gui/desktop.h>
#include <gui/window.h>
#include <multitasking.h>

#include <drivers/amd_am79c973.h>


// #define GRAPHICSMODE


using namespace myos;
using namespace myos::common;
using namespace myos::drivers;
using namespace myos::hardwarecommunication;
using namespace myos::gui;

void printf(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t x=0,y=0;

    for(int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= 80)
        {
            x = 0;
            y++;
        }

        if(y >= 25)
        {
            for(y = 0; y < 25; y++)
                for(x = 0; x < 80; x++)
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void sleep(float seconds){
		for(uint32_t i = 0; i < (uint32_t)(999999.0 * seconds); ++i)
			for(uint32_t j = 0; j < 999; ++j);
}

int32_t random(){
	int32_t time;
	asm("rdtsc": "=A"(time));

	time *= time; 
    time /= 100; 
    return (int32_t)(time % 10000); 
}

// basic function to print decimal numbers.
// store the numbers while dividing by 10 and reverse string

void printfDec(int32_t decimal){
    int i = 0;
    bool isNegative = false;
	char str[16];

    if (decimal < 0) {
        isNegative = true;
        decimal = -decimal;
    }

    do {
        str[i++] = decimal % 10 + '0';
        decimal /= 10;
    } while (decimal != 0);

    if (isNegative) {
        str[i++] = '-';
    }

    int j = 0;
    char temp;
    for (j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    str[i] = '\0';
	printf(str);
}

void printfHex(uint8_t key)
{
    char* foo = "00";
    char* hex = "0123456789ABCDEF";
    foo[0] = hex[(key >> 4) & 0xF];
    foo[1] = hex[key & 0xF];
    printf(foo);
}
void printfHex16(uint16_t key)
{
    printfHex((key >> 8) & 0xFF);
    printfHex( key & 0xFF);
}
void printfHex32(uint32_t key)
{
    printfHex((key >> 24) & 0xFF);
    printfHex((key >> 16) & 0xFF);
    printfHex((key >> 8) & 0xFF);
    printfHex( key & 0xFF);
}





class PrintfKeyboardEventHandler : public KeyboardEventHandler
{
public:
    void OnKeyDown(char c)
    {
        char* foo = " ";
        foo[0] = c;
        printf(foo);
    }
};

class MouseToConsole : public MouseEventHandler
{
    int8_t x, y;
public:
    
    MouseToConsole()
    {
        uint16_t* VideoMemory = (uint16_t*)0xb8000;
        x = 40;
        y = 12;
        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                            | (VideoMemory[80*y+x] & 0xF000) >> 4
                            | (VideoMemory[80*y+x] & 0x00FF);        
    }
    
    virtual void OnMouseMove(int xoffset, int yoffset)
    {
        static uint16_t* VideoMemory = (uint16_t*)0xb8000;
        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                            | (VideoMemory[80*y+x] & 0xF000) >> 4
                            | (VideoMemory[80*y+x] & 0x00FF);

        x += xoffset;
        if(x >= 80) x = 79;
        if(x < 0) x = 0;
        y += yoffset;
        if(y >= 25) y = 24;
        if(y < 0) y = 0;

        VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0x0F00) << 4
                            | (VideoMemory[80*y+x] & 0xF000) >> 4
                            | (VideoMemory[80*y+x] & 0x00FF);
    }
    
};



// system calls.

uint32_t sysFork(){
    asm("int $0x80" :: "a" (SYSCALL::FORK));
}

uint32_t sysWaitPid(uint32_t pid){
	if(pid < 0)
		return -1;

    asm("int $0x80" :: "a" (SYSCALL::WAITPID), "b" (pid));
}


void sysExecve(void entrypoint()){
	asm("int $0x80" : : "a" (SYSCALL::EXECVE), "b" ((uint32_t)entrypoint));
}

void sysPrintf(char* str)
{
	asm("int $0x80" : : "a" (SYSCALL::PRINT), "b" (str));
}

void sysPrintfDec(int decimal)
{
    int i = 0;
    bool isNegative = false;
	char str[16];

    if (decimal < 0) {
        isNegative = true;
        decimal = -decimal;
    }

    do {
        str[i++] = decimal % 10 + '0';
        decimal /= 10;
    } while (decimal != 0);

    if (isNegative) {
        str[i++] = '-';
    }

    int j = 0;
    char temp;
    for (j = 0; j < i / 2; j++) {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }

    str[i] = '\0';
	asm("int $0x80" : : "a" (SYSCALL::PRINT), "b" (str));
}

uint32_t sysGetPid()
{
	asm("int $0x80" :: "a" (SYSCALL::GETPID));
}

void sysExit()
{
	asm("int $0x80" ::  "a" (SYSCALL::EXIT));
}

/* Tasks for testing */

void taskTestGetPid(){

		uint32_t forkReturn = sysFork();

		if(forkReturn == 0){
			printf("I'm the child and my pid is");
			uint32_t pid = sysGetPid();
			printfDec(pid);
			printf("\n\n");
			while(true);
		}

		else{
			printf("I'm the parent and my pid is");
			uint32_t pid = sysGetPid();
			printfDec(pid);
			printf("\n\n");
			while (true);
		}
}

/*---------------------------------------------------------------------------------*/

void taskPrintExecve(){
	printf("I'm the process that is going to be used in execve.\n");
	while(true){
		printf("From execve\n");
		sleep(0.5);
	}
}
void taskTestExecve(){
	sysPrintf("I'm the process to test execve. I'm going to fork and my child is going to be executing something else.\n");
	int32_t forkReturn = sysFork();

	if(forkReturn == 0){
		sysExecve(taskPrintExecve);
	}
	while(true){
		sysPrintf("Original\n");
		sleep(0.5);
	}
}

/*---------------------------------------------------------------------------------*/

void taskTestFork(){
	sysPrintf("I'm the process to test fork, I am going to fork and my child will fork too.\n");
	sysPrintf("We will be printing our pids and forkReturn values.\n");
	sleep(1);

	uint32_t forkReturnParent = sysFork();

	if(forkReturnParent == 0){
		sysPrintf("Hello, I'm the child process, and my pid is: ");
		sysPrintfDec(sysGetPid());
		sysPrintf("\n I'm going to fork again and print child from now on.\n");

		uint32_t forkReturnChild = sysFork();

		if(forkReturnChild == 0){
			sysPrintf("Hello, I'm the grand child process, and my pid is: ");
			sysPrintfDec(sysGetPid());
			sysPrintf("\n I'm going to print grand child from now on.\n");

			while(true){
				sysPrintf("Grand Child pid: ");
				sysPrintfDec(sysGetPid());
				sysPrintf(", forkReturnParent: ");
				sysPrintfDec(forkReturnParent);
				sysPrintf(", forkReturnChild: ");
				sysPrintfDec(forkReturnChild);
				sysPrintf("\n");
				sleep(0.5);
			}
		}

		else{
			while(true){
				sysPrintf("Child pid: ");
				sysPrintfDec(sysGetPid());
				sysPrintf(", forkReturnParent: ");
				sysPrintfDec(forkReturnParent);
				sysPrintf(", forkReturnChild: ");
				sysPrintfDec(forkReturnChild);
				sysPrintf("\n");
				sleep(0.5);
				sysExit();
			}
		}
	}

	else{
		sysPrintf("Hello, I'm the parent process, and my pid is: ");
		sysPrintfDec(sysGetPid());
		sysPrintf("\n I'm going to print parent from now on.\n");
		
		sysWaitPid(forkReturnParent);

		while(true){
			sysPrintf("Parent pid: ");
			sysPrintfDec(sysGetPid());
			sysPrintf(", forkReturnParent: ");
			sysPrintfDec(forkReturnParent);
			sysPrintf("\n");
			sleep(0.5);
		}
	}

}

/*---------------------------------------------------------------------------------*/

void taskTestWaitPid(){
	sysPrintf("Hello, I'm the process to test waitpid.\n");
	sysPrintf("I'm going to create 2 processes by forking and wait my children to finish.\n");

	int32_t f1 = sysFork();
	int32_t f2 = -1;

	int32_t ch1 = -1;
	int32_t ch2 = -1;


	if(f1 != 0)
		f2 = sysFork();

	if(f1 == 0 && f2 == -1){
		for(uint32_t i = 0; i < 25; ++i){
			sysPrintf("I'm the first child and I'm sleeping...\n");
			sysPrintf("\n");

			sleep(0.5);
		}
		sysPrintf("I'm the first child and I'm finished.\n");
		sysExit();
	}

	else if(f2 == 0){
		for(uint32_t i = 0; i < 10; ++i){
			sysPrintf("I'm the second child and I'm sleeping...\n");
			sleep(0.5);
		}
		sysPrintf("I'm the second child and I'm finished.\n");
		sysExit();
	}

	else{ 
		//parent
		ch1 = sysWaitPid(f1);
		ch2 = sysWaitPid(f2);
	}

	while(true){
		sysPrintf("All my children finished (-1 means I tried to wait it when it is done executing already).\n");
		sysPrintf("\n(");
		sysPrintf("ch1 was: ");
		sysPrintfDec(ch1);
		sysPrintf(", ch2 was: ");
		sysPrintfDec(ch2);
		sysPrintf(")\n");
		sleep(0.5);
	}
}




void collatzSequence() {
	int32_t r = random();

	if(r < 0)
		r *= -1;
	if(r == 0)
		r = 1;

	int n = r % 100;

    if (n <= 0) {
        sysPrintf("Input must be a positive integer.\n");
        return;
    }

    sysPrintf("Collatz sequence for ");
	sysPrintfDec(n);
	sysPrintf(" is: ");
    
    while (n != 1) {
		sysPrintfDec(n);
		sysPrintf(" ");
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    sysPrintf("1\n"); 
	sleep(0.5);
				   
   	sysExit();
}




void longRunningProgram() {
	sysPrintf("Process id: ");
	sysPrintfDec(sysGetPid());
	sysPrintf("\n");


    int n = 9999;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        
        for (int j = 0; j < n; ++j) {
            result += i * j;
        }
    }
    
    sleep(1.5);
    sysPrintf("result: ");
    sysPrintfDec(result);
    sysPrintf("\n");
    sysExit();
}

void initialTask(){
	int32_t pids[6];

    for(int32_t i = 0; i < 6; i++) {
		if(i%2 == 0){
			pids[i] = sysFork();
			if(pids[i] == 0){
				sysPrintf("Forked and executing collatz..\n");
				sysPrintf("Pid is: ");
				sysPrintfDec(sysGetPid());
				sysPrintf("\n");
				sysExecve(collatzSequence);
				sleep(0.5);
			}
		}
		else{
			pids[i] = sysFork();
			if(pids[i] == 0){
				sysPrintf("Forked and executing long running program..\n");
				sysPrintf("Pid is: ");
				sysPrintfDec(sysGetPid());
				sysPrintf("\n");
				sysExecve(longRunningProgram);
				sleep(0.5);
			}
		}
    }

	for(int32_t i = 0; i < 6; ++i){
		sysWaitPid(pids[i]);
	}

	while(true){
		sysPrintf("Processes have finished. \n");
		sleep(0.5);
	}

}


/* KERNEL */

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}



extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*multiboot_magic*/)
{
    printf("Kernel Main is started.\n");

    GlobalDescriptorTable gdt;
    
    
    uint32_t* memupper = (uint32_t*)(((size_t)multiboot_structure) + 8);
    size_t heap = 10*1024*1024;
    MemoryManager memoryManager(heap, (*memupper)*1024 - heap - 10*1024);
    
   
    void* allocated = memoryManager.malloc(1024);
   
    TaskManager taskManager;
	taskManager.addGdt(&gdt);

    Task task1(&gdt, initialTask);
    // Task task2(&gdt, taskB);

    taskManager.AddTask(&task1);
//    taskManager.AddTask(&task2);

    
    InterruptManager interrupts(0x20, &gdt, &taskManager);
    SyscallHandler syscalls(&interrupts, 0x80);
	syscalls.addTaskManager(&taskManager);
    
    
    #ifdef GRAPHICSMODE
        Desktop desktop(320,200, 0x00,0x00,0xA8);
    #endif
    
    DriverManager drvManager;
    
        #ifdef GRAPHICSMODE
            KeyboardDriver keyboard(&interrupts, &desktop);
        #else
            PrintfKeyboardEventHandler kbhandler;
            KeyboardDriver keyboard(&interrupts, &kbhandler);
        #endif
        drvManager.AddDriver(&keyboard);
        
    
        #ifdef GRAPHICSMODE
            MouseDriver mouse(&interrupts, &desktop);
        #else
            MouseToConsole mousehandler;
            MouseDriver mouse(&interrupts, &mousehandler);
        #endif
        drvManager.AddDriver(&mouse);
        
        PeripheralComponentInterconnectController PCIController;
        PCIController.SelectDrivers(&drvManager, &interrupts);

        #ifdef GRAPHICSMODE
            VideoGraphicsArray vga;
        #endif
        
        drvManager.ActivateAll();

    #ifdef GRAPHICSMODE
        vga.SetMode(320,200,8);
        Window win1(&desktop, 10,10,20,20, 0xA8,0x00,0x00);
        desktop.AddChild(&win1);
        Window win2(&desktop, 40,15,30,30, 0x00,0xA8,0x00);
        desktop.AddChild(&win2);
    #endif


    /*
    printf("\nS-ATA primary master: ");
    AdvancedTechnologyAttachment ata0m(true, 0x1F0);
    ata0m.Identify();
    
    printf("\nS-ATA primary slave: ");
    AdvancedTechnologyAttachment ata0s(false, 0x1F0);
    ata0s.Identify();
    ata0s.Write28(0, (uint8_t*)"http://www.AlgorithMan.de", 25);
    ata0s.Flush();
    ata0s.Read28(0, 25);
    
    printf("\nS-ATA secondary master: ");
    AdvancedTechnologyAttachment ata1m(true, 0x170);
    ata1m.Identify();
    
    printf("\nS-ATA secondary slave: ");
    AdvancedTechnologyAttachment ata1s(false, 0x170);
    ata1s.Identify();
    // third: 0x1E8
    // fourth: 0x168
    */
    
    
    amd_am79c973* eth0 = (amd_am79c973*)(drvManager.drivers[2]);
    eth0->Send((uint8_t*)"Hello Network", 13);
        

    interrupts.Activate();


    while(1)
    {
        #ifdef GRAPHICSMODE
            desktop.Draw(&vga);
        #endif
    }
}
