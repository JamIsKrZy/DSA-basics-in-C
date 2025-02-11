#include <stdio.h>
#include "ObjectClass.h"


OutputResult the_side_work(Money *money_ref){
    if(*money_ref < 500) return Blocked;

    printf(" -- Worker just wasted 500 money :( \n -- Does not know to invest in life\n");
    *money_ref -= 500;
    return Failed; 
}

OutputResult the_side_work_2(Money *money_ref){
    if(*money_ref < 250) return Blocked;

    printf(" -- Won lotto :D, 600 money\n");
    *money_ref += 600;
    return Success; 
}


int main(int argc, char const *argv[])
{
    //Instantiate an object
    FactoryWorker worker = new_factory_worker();

    worker.methods.check_in(&worker);
    while (worker.methods.is_working(&worker))
    {   
        printf("Worker energy: %.2f\n", worker.energy);
        if(worker.energy < 8) {
            
            worker.methods.check_out(&worker);
            break;
        };

        printf("Worker working...\n");
    }
    worker.methods.recieve_allowance(&worker, 750);

    worker.methods.do_side_hustle(&worker, 1000, the_side_work);

    worker.methods.sleep(&worker);

    worker.methods.do_side_hustle(&worker, 600, the_side_work_2);
    
    return 0;
}
