/*
 * Scheduler.c
 *
 *  Created on: Nov 18, 2024
 *      Author: ADMIN
 */

#include "Scheduler.h"


sTasks	SCH_tasks_G[SCH_MAX_TASKS];

uint8_t  current_index_task = 0;

void SCH_Init(void){}

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY / TICK;
		SCH_tasks_G[current_index_task].Period = PERIOD / TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}


void SCH_Update(void){
	button_reading();
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].Delay > 0){
			SCH_tasks_G[i].Delay--;
		}
		else{
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Period == 0){
				SCH_Delete(i);
			}
		}
	}
}

void SCH_Delete(uint32_t ID){
	if(ID == current_index_task){
		SCH_tasks_G[ID].pTask = 0x0000;
		SCH_tasks_G[ID].Delay = 0;
		SCH_tasks_G[ID].Period = 0;
		SCH_tasks_G[ID].RunMe = 0;
	}

	else{
		for(int i = ID + 1; i <= current_index_task; i++){
			SCH_tasks_G[i-1].pTask = SCH_tasks_G[i].pTask;
			SCH_tasks_G[i-1].Delay = SCH_tasks_G[i].Delay;
			SCH_tasks_G[i-1].Period = SCH_tasks_G[i].Period;
			SCH_tasks_G[i-1].RunMe = SCH_tasks_G[i].RunMe;
		}
	}
	current_index_task--;
}
