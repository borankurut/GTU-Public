
#include <syscalls.h>
 
using namespace myos;
using namespace myos::common;
using namespace myos::hardwarecommunication;
 
SyscallHandler::SyscallHandler(InterruptManager* interruptManager, uint8_t InterruptNumber)
:    InterruptHandler(interruptManager, InterruptNumber  + interruptManager->HardwareInterruptOffset())
{
}

SyscallHandler::~SyscallHandler()
{
}

void SyscallHandler::addTaskManager(TaskManager* taskManager){tm = taskManager;}


void printf(char*);
void printfDec(common::int32_t num);

uint32_t SyscallHandler::HandleInterrupt(uint32_t esp)
{
    CPUState* cpu = (CPUState*)esp;

    switch(cpu->eax)
    {
		case SYSCALL::FORK:
			printf("syscall fork called\n");
			tm->Fork(cpu);
			break;

		case SYSCALL::WAITPID:
			printf("syscall waitpid called\n");
			cpu->eax = tm->WaitPid(cpu->ebx);
	        esp = (uint32_t)tm->Schedule((CPUState*)esp); // call schedular after wait.
			break;

		case SYSCALL::EXECVE:
			printf("syscall execve called\n");
			esp = (uint32_t) tm->ChangeCurrentTask(cpu->ebx);
			break;

		case SYSCALL::PRINT:
			printf((char*)cpu->ebx);
			break;

		case SYSCALL::GETPID:
			cpu->eax = tm->GetPid();
			break;

		case SYSCALL::EXIT:
			tm->Exit();
			esp = (uint32_t)tm->Schedule((CPUState*) esp);
			break;

        default:
            break;
    }
    
    return esp;
}

