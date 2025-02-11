#ifndef OBJECT_CLASS_H
#define OBJECT_CLASS_H

#include <stdlib.h>
#include <stdbool.h>

// Just for return result handling
typedef enum {
    Success,
    Failed,
    Blocked
} OutputResult;

// For emtion meter of the worker
typedef enum{
    Satisfied,
    Happy,
    Unsatisfied,
    Sad,
    Angry,
    Tired
} Reaction;

typedef unsigned long Money;

typedef struct FactoryWorker FactoryWorker;

struct FactoryWorkerMethods{
    
    void (*check_in)(FactoryWorker *worker_ref);
    void (*check_out)(FactoryWorker *worker_ref);
    bool (*is_working)(FactoryWorker *worker_ref);


    // In python its like "recieve_allowance(self, allowance: int)" , so as others
    Reaction (*recieve_allowance)(FactoryWorker *worker_ref , Money allowance_amount);

    Reaction (*do_side_hustle)(FactoryWorker *worker_ref, Money reward, OutputResult (*side_work)(Money *money_ref));

    void (*do_work)(FactoryWorker *worker_ref);
    void (*request_favor)(FactoryWorker *worker_ref, OutputResult (*do_this)());
    void (*sleep)(FactoryWorker *worker_ref);
};

// Object Class 
typedef struct FactoryWorker{
    // Close to zero is happy til 5 is Angry - baseed on enum Reaction
    double EmotionMeter;
    Money pocket_money;

    //from 1 to 10;
    double energy;
    bool is_working;

    
    //implementing Methods - it can be like an interface(Java)
    struct FactoryWorkerMethods methods; 
} FactoryWorker;

// declard as Global vriable


FactoryWorker new_factory_worker();




#endif