
#include <multitasking.h>

void printf(char *);

using namespace myos;
using namespace myos::common;

void printfDec(int32_t decimal);
void sleep(float seconds);

Task::Task(){}

Task::Task(GlobalDescriptorTable *gdt, void entrypoint()){
    cpustate = (CPUState*)(stack + 4096 - sizeof(CPUState));
    cpustate -> eax = 0;
    cpustate -> ebx = 0;
    cpustate -> ecx = 0;
    cpustate -> edx = 0;

    cpustate -> esi = 0;
    cpustate -> edi = 0;
    cpustate -> ebp = 0;
   
    cpustate -> eip = (uint32_t)entrypoint;
    cpustate -> cs = gdt->CodeSegmentSelector();
    cpustate -> eflags = 0x202;

	waiting_child_pid = -1;
}

Task::~Task()
{
}

        
TaskManager::TaskManager()
{
    numTasks = 0;
    currentTask = -1;
	newPid = 1;
}

TaskManager::~TaskManager()
{
}

CPUState* TaskManager::ChangeCurrentTask(uint32_t entrypoint){
    tasks[currentTask].cpustate = (CPUState*)(tasks[currentTask].stack + 4096 - sizeof(CPUState));
	CPUState* cpustate = tasks[currentTask].cpustate;
    cpustate -> eax = 0;
    cpustate -> ebx = 0;
    cpustate -> ecx = 0;
    cpustate -> edx = 0;

    cpustate -> esi = 0;
    cpustate -> edi = 0;
    cpustate -> ebp = 0;
   
    cpustate -> eip = entrypoint;
    cpustate -> cs = gdt->CodeSegmentSelector();
    cpustate -> eflags = 0x202;
	tasks[currentTask].state = Task::READY;
	return cpustate;
}

bool TaskManager::AddTask(Task* task)
{
    if(numTasks >= 256)
        return false;

	tasks[numTasks].pid = newPid++; 
	tasks[numTasks].p_pid = 0;
	tasks[numTasks].state = Task::READY;
	tasks[numTasks].waiting_child_pid = task->waiting_child_pid;

    tasks[numTasks].cpustate = (CPUState*)(tasks[numTasks].stack + 4096 - sizeof(CPUState));

	CPUState* cpustate = tasks[numTasks].cpustate;

    cpustate -> eax = task->cpustate->eax;
    cpustate -> ebx = task->cpustate->ebx;
    cpustate -> ecx = task->cpustate->ecx;
    cpustate -> edx = task->cpustate->edx;

    cpustate -> esi = task->cpustate->esi;
    cpustate -> edi = task->cpustate->edi;
    cpustate -> ebp = task->cpustate->ebp;
   
    cpustate -> eip = task->cpustate->eip;
    cpustate -> cs = task->cpustate->cs;
    cpustate -> eflags = task->cpustate->eflags; 

	numTasks++;

    return true;
}

CPUState* TaskManager::Schedule(CPUState* cpustate)
{
	printf("Schedular is called\n");
	// PrintTasks(tasks, numTasks);
	printf("\n");

    if(numTasks <= 0)
        return cpustate;
    
    if(currentTask >= 0)
        tasks[currentTask].cpustate = cpustate;


	// stop the current process.
	if((tasks[currentTask].state != Task::BLOCKED) && (tasks[currentTask].state != Task::TERMINATED))
		tasks[currentTask].state = Task::READY; // maybe some checks here.


	// (the quanta is the time between hardware timer interrupts)
	// Searches the next ready process.
	do{
		++currentTask;

		if(currentTask >= numTasks)
			currentTask %= numTasks;

	}while(tasks[currentTask].state != Task::READY || tasks[currentTask].waiting_child_pid != -1);
	// I added the second check in while loop to pass the processes that are waiting for its child to finish.

	tasks[currentTask].state = Task::RUNNING;

    return tasks[currentTask].cpustate;
}

    
/*All print functions here are for debug purposes.*/

void TaskManager::PrintState(CPUState * state){
		printf("State:");
		printf(", eax: "); printfDec(state->eax); 
		printf(", ebx: "); printfDec(state->ebx);
		printf(", ecx: "); printfDec(state->ecx);
		printf(", edx: "); printfDec(state->edx);

		printf(", esi: "); printfDec(state->esi);
		printf(", edi: "); printfDec(state->edi);
		printf(", ebp: "); printfDec(state->ebp);

		printf("\n error: "); printfDec(state->error);

		printf(", eip: "); printfDec(state->eip);
		printf(", cs: "); printfDec(state->cs);
		printf(", eflags: "); printfDec(state->eflags);
		printf(", esp: "); printfDec(state->esp);
		printf(", ss: "); printfDec(state->ss);

		printf("\n");
}

void TaskManager::PrintTask(Task * task){
	//PrintState(task->cpustate);
	printf("pid:"); printfDec(task->pid);
	printf(", p_pid:"); printfDec(task->p_pid);
	printf(", waiting pid: "); printfDec(task->waiting_child_pid);
	printf(", state:"); printfDec(task->state);
}

void TaskManager::PrintTasks(Task tasks[256], uint32_t numTasks){
	for(uint32_t i = 0; i < numTasks; ++i){
		printf("task:");
		printfDec(i);
		printf(": ");
		PrintTask(&tasks[i]);
		printf(", ");
	}
}

uint32_t TaskManager::GetPid(){
	return tasks[currentTask].pid;
}

uint32_t TaskManager::GetParrentPid(){
	return tasks[currentTask].p_pid;
}

uint32_t TaskManager::WaitPid(uint32_t pid){
	// todo: check this before in the syscall to prevent scheduler from scheduling the next task even when WaitPid fails.
	if(TaskFromPid(pid)->state == Task::TERMINATED)
		return -1;

	tasks[currentTask].waiting_child_pid = pid;
	return pid;
}

void TaskManager::Exit(){
	Task* current = &tasks[currentTask];

	Task* parent = TaskFromPid(current->p_pid);

	if(current->p_pid != 0){
		Task* parent = TaskFromPid(current->p_pid);

		if(parent == nullptr){
			printf("Can't find parent in exit.\n");
		}

		if(parent->waiting_child_pid == current->pid)
			parent->waiting_child_pid = -1;
	}
	current->state = Task::TERMINATED;
}

Task* TaskManager::TaskFromPid(uint32_t pid){
	for(int i = 0; i < numTasks; ++i){
		Task* taskP = &tasks[i];
		if(taskP->pid == pid)
			return taskP;
	}
	return nullptr;
}



void TaskManager::Fork(CPUState* cpuState){
    if(numTasks >= 256){
		cpuState->eax = -1;
        return;
	}
	Task * parent = &tasks[currentTask];
	Task * child = &tasks[numTasks];

 
    child->state = Task::READY;
    child->p_pid = parent->pid;
    child->pid = newPid++;
	child->waiting_child_pid = -1;

    for (int i = 0; i < sizeof(parent->stack); i++)
    {
        child->stack[i]=parent->stack[i];
    }

    uint32_t parentCpuStackOffset = (uint32_t)cpuState - (uint32_t) (parent->stack);
    child->cpustate = (CPUState*)(((uint32_t) (child->stack)) + parentCpuStackOffset);
	
	uint32_t spOffset = (uint32_t)(parent->stack) - (uint32_t) (cpuState);
	child->cpustate->esp = (uint32_t) (child->stack) + spOffset;

    child->cpustate->eax = 0;
	cpuState->eax = child->pid;
    numTasks++;
}

void TaskManager::addGdt(GlobalDescriptorTable* gdtToAdd){gdt = gdtToAdd;}

GlobalDescriptorTable* TaskManager::getGdt(){return gdt;}


