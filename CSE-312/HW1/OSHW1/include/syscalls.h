 
#ifndef __MYOS__SYSCALLS_H
#define __MYOS__SYSCALLS_H

#include <common/types.h>
#include <hardwarecommunication/interrupts.h>
#include <multitasking.h>

namespace myos
{
    
    class SyscallHandler : public hardwarecommunication::InterruptHandler
    {
        
    public:
        SyscallHandler(hardwarecommunication::InterruptManager* interruptManager, myos::common::uint8_t InterruptNumber);
        ~SyscallHandler();
        
        virtual myos::common::uint32_t HandleInterrupt(myos::common::uint32_t esp);

		void addTaskManager(TaskManager *tm);

	private:
		TaskManager* tm; //this is added to handle syscalls that need task manager.
    };
}

/*syscall numbers in enum.*/
enum SYSCALL{FORK = 2, WAITPID = 7, EXECVE = 59, PRINT = 4, GETPID = 39, EXIT = 1};


#endif
