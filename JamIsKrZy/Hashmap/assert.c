#include <stdio.h>
#include "Hashmap.h"
#include <stdbool.h>

int main(int argc, char const *argv[])
{   
    char *location[] = {
        "Dalugan", "Farwen", "Neilhem", "Mortis", "Malsut", "Yuhmers"
    };
    size_t location_count = sizeof(location)/sizeof(location[0]);

    char response[255];
    int choice = 0;
    bool flag = true;

    ChainedHashMap *map = new_chained_hashmap(sizeof(int), 15);

    for (int i = 0; i < location_count; i++)
    {
        insert_hashmap(map, location[i], &i);
    }
    

    while (flag)
    {   
        printf("-------------------------------------------\n");
        printf("[1]-Insert | [2]-Get | [3] -END\n");
        printf("Pick: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            
            printf("Insert Key: ");
            scanf(" %[^\n]s", response);
            printf("Insert Value: ");
            scanf(" %d", &choice);

            if(insert_hashmap(map, response, &choice)){
                printf("Successfully added\n");
            } else {
                printf("There was an issue!\n");
            }


            break;
        case 2:
            
            printf("Insert Key: ");
            scanf(" %[^\n]s", response);

            int *n = get_value_hashmap(map, response);
            if(n != NULL){
                printf("The key value is: %d\n", *n);
            } else {
                printf("Key does not contain a value\n");
            }

            break;
        
        default:
            flag = false;
            break;
        }


    }

    free_hashmap(map);
    
    return 0;
}
