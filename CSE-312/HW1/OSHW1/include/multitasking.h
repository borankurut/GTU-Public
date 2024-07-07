 
#ifndef __MYOS__MULTITASKING_H
#define __MYOS__MULTITASKING_H

#include <common/types.h>
#include <gdt.h>

namespace myos
{
    
    struct CPUState
    {
        common::uint32_t eax;
        common::uint32_t ebx;
        common::uint32_t ecx;
        common::uint32_t edx;

        common::uint32_t esi;
        common::uint32_t edi;
        common::uint32_t ebp;

        /*
        common::uint32_t gs;
        common::uint32_t fs;
        common::uint32_t es;
        common::uint32_t ds;
        */
        common::uint32_t error;

        common::uint32_t eip;
        common::uint32_t cs;
        common::uint32_t eflags;
        common::uint32_t esp;
        common::uint32_t ss;        
    } __attribute__((packed));
    
    
    class Task
    {
    friend class TaskManager;

	enum State {BLOCKED, READY, RUNNING, TERMINATED};

    private:
        common::uint8_t stack[4096]; // 4 KiB
									 
        CPUState* cpustate;

		State state = READY; //todo: set this after some checks?

		common::uint32_t pid;
		common::uint32_t p_pid;
		common::uint32_t waiting_child_pid;
    public:
        Task(GlobalDescriptorTable *gdt, void entrypoint());
		Task();
        ~Task();
    };
    
    
    class TaskManager
    {
    private:
        Task tasks[256];
        int numTasks;
        int currentTask;
		int newPid;
		GlobalDescriptorTable* gdt;
		Task* TaskFromPid(common::uint32_t pid);

    public:
        TaskManager();
        ~TaskManager();
        bool AddTask(Task* task);
		common::uint32_t AddTask(void entrypoint());
		bool AddTask(GlobalDescriptorTable* gdt, void entrypoint());
        CPUState* Schedule(CPUState* cpustate);

		//for debug purpose print functions.
		void PrintState(CPUState * state);
		void PrintTask(Task * task);
		void PrintTasks(Task tasks[256], common::uint32_t numTasks);

		//getpid returns the pid number of the currentTask.
		common::uint32_t GetPid();
		common::uint32_t GetParrentPid();
		void Fork(CPUState* cpustate);
		common::uint32_t WaitPid(common::uint32_t pid);
		void Exit();
		CPUState* ChangeCurrentTask(common::uint32_t entrypoint);

		void CopyTask(Task* to, const Task* from);
		void CopyTaskOffset(Task* to, const Task* from, common::uint32_t offset);
		void CopyCpuState(CPUState* to, CPUState* from);
		void addGdt(GlobalDescriptorTable* gdtToAdd);
		GlobalDescriptorTable* getGdt();
    };
}


#endif
