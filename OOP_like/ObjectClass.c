#include "ObjectClass.h"
#include <stdio.h>





static Reaction get_emotion(double meter){
    if(meter > 5){
        return Angry;
    } else if (meter > 4){
        return Sad;
    } else if (meter > 3){
        return Unsatisfied;
    } else if (meter > 2){
        return Happy;
    } else {
        return Satisfied;
    }
}

void worker_check_in(FactoryWorker *worker_ref){
    if(worker_ref->energy < 5) return;

    worker_ref->is_working = true;
    worker_ref->energy -= 0.1;
    worker_ref->EmotionMeter += 0.2;
}

void worker_check_out(FactoryWorker *worker_ref){
    worker_ref->is_working = false;
    worker_ref->energy -= 0.1;
    worker_ref->EmotionMeter -= 0.5;
}

bool worker_is_working(FactoryWorker *worker_ref){
    worker_ref->EmotionMeter += 0.01;
    worker_ref->energy -= 0.1;
    
    return worker_ref->is_working;
}

Reaction worker_recieve_allowance(FactoryWorker *worker_ref , Money allowance_amount){
    worker_ref->pocket_money += allowance_amount;

    return get_emotion(worker_ref->EmotionMeter);
}

Reaction worker_do_side_hustle(
    FactoryWorker *worker_ref, 
    Money reward, 
    OutputResult (*side_work)(Money *money_ref)
){
    if(worker_ref->energy < 4.5) return Tired;

    if(side_work(&worker_ref->pocket_money) == Success){
        worker_ref->pocket_money += reward;
        worker_ref->EmotionMeter -= 0.3;
    } else {
        worker_ref->EmotionMeter += 0.5;
    }

    worker_ref->EmotionMeter +=3;
    worker_ref->energy -= 4.5;

    return get_emotion(worker_ref->EmotionMeter);
}

void worker_do_work(FactoryWorker *worker_ref){
    if(worker_ref->energy < 3.5) return;
    if(!worker_ref->is_working) return;
    
    worker_ref->energy -= 3.5;
    worker_ref->EmotionMeter += 2.5;

    return;
}

void worker_request_favor(
    FactoryWorker *worker_ref, 
    OutputResult (*do_this)()
){

}

void worker_sleep(FactoryWorker *worker_ref){
    if(worker_ref->is_working) return;

    worker_ref->energy = 10;
    worker_ref->EmotionMeter = 0;

    printf("Worker is sleeping...\n");

    return;
}


struct FactoryWorkerMethods defaultFactoryWorkerMethods = {
    .check_in = worker_check_in,
    .check_out = worker_check_out,
    .do_side_hustle = worker_do_side_hustle,
    .do_work = worker_do_work,
    .is_working = worker_is_working,
    .recieve_allowance = worker_recieve_allowance,
    .request_favor = worker_request_favor,
    .sleep = worker_sleep,
};

FactoryWorker new_factory_worker(){
    FactoryWorker worker = {
        .EmotionMeter = 0,
        .energy = 10,
        .is_working = false,
        .pocket_money = 500,
        .methods = defaultFactoryWorkerMethods
    };

    return worker;
}