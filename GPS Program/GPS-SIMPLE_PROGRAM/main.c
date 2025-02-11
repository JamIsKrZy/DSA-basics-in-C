#include <stdio.h>
#include <string.h>
#include "../Hashmap/Hashmap.h"
#include "../Graph/AdjacencyList.h"

void connect_Locations(); //Graph, char* location1, char* location2

struct PointEdge{
    size_t weight;
    char *to_location;
};

struct LocationPoint{
    char *location;
    struct PointEdge *edges;
    size_t edgeCount;
};

void setup_data(AdjListGraph **graph, ChainedHashMap *map){
    struct PointEdge ItPark_edge[] = {
        {27, "Ayala Center"}, {10, "Waterfront Cebu"}, {41, "UC Banilad"}, {48, "UP Cebu"},
        {94, "SM City"}
    };
    struct PointEdge UPCebu_edge[] = {
        {18, "Ayala Center"}, {48, "It Park"}
    };
    struct PointEdge AyalaCenter_edge[] = {
        {18, "UP Cebu"}, {19, "Waterfront Cebu"},
        {29, "Cebu Provincial Capitol"}, {39, "Ludo Memorial Park"}
    };
    struct PointEdge UCBanilad_edge[] = {
       {48, "It Park"}, {121, "SM City"}
    };
    struct PointEdge Waterfront_edge[] = {
        {10, "It Park"}, {19, "Ayala Center"}
    };
    struct PointEdge SMCity_edge[] = {
        {94, "It Park"}, {36, "Ludo Memorial Park"}, {121, "UC Banilad"},
    };
    struct PointEdge ProvCapitol_edge[] = {
        {31, "Chong Hua Hospital"}, {29, "Ayala Center"}
    };
    struct PointEdge ChongHua_edge[] = {
        {31, "Cebu Provincial Capitol"}, {45, "Abellana National School"},
        {66, "USC South"}
    };
    struct PointEdge Abellana_edge[] = {
        {7, "Emall"}, {48, "Ludo Memorial Park"}, {45, "Chong Hua Hospital"}
    };
    struct PointEdge LudoPark_edge[] = {
        {48, "Abellana National School"}, {39, "Ayala Center"}, {36, "SM City"} 
    };
    struct PointEdge USC_edge[] = {
        {41, "Emall"}, {66, "Chong Hua Hospital"}, {73, "CITU"} 
    };
    struct PointEdge Emall_edge[] = {
        {15, "USC South"}, {7, "Abellana National School"}, {18, "USJR Main"}
    };
    struct PointEdge USJR_edge[] = {
        {18, "Emall"}
    };
    struct PointEdge CITU_edge[] = {
        {73, "USC South"}, {69, "SM Seaside"}
    };
    struct PointEdge SMSeaside_edge[] = {
        {69, "CITU"}, {431, "SM City"}
    };

    const struct LocationPoint location[] = { // 15 location
        {"It Park", ItPark_edge, 5}, 
        {"UP Cebu", UPCebu_edge, 2}, 
        {"Ayala Center", AyalaCenter_edge, 4}, 
        {"UC Banilad", UCBanilad_edge, 2},
        { "Waterfront Cebu", Waterfront_edge, 2},
        {"SM City", SMCity_edge, 3}, 
        {"Cebu Provincial Capitol", ProvCapitol_edge, 2}, 
        {"Chong Hua Hospital", ChongHua_edge, 3}, 
        {"Ludo Memorial Park", LudoPark_edge, 3}, 
        {"Abellana National School", Abellana_edge, 3},
        {"USC South", USC_edge, 3}, 
        {"Emall", Emall_edge, 3}, 
        {"USJR Main", USJR_edge, 1},
        {"CITU", CITU_edge, 2},
        {"SM Seaside", SMSeaside_edge, 2},
    };
    size_t location_count = sizeof(location)/sizeof(location[0]);
    *graph = new_adjListGraph(location_count);

    for (size_t i = 0; i < location_count; i++)
    {
        insert_hashmap(map, location[i].location, &i);
    }

    for (size_t i = 0; i < location_count; i++)
    {
        size_t edges_len = location[i].edgeCount;
        printf("%s[Vertix ID: %ld] has %ld Edges\n", location[i].location, i,edges_len);

        size_t *to_vertix;
        
        for (size_t j = 0; j < edges_len; j++)
        {   
            to_vertix = get_value_hashmap(map, location[i].edges[j].to_location);
            printf("Added Edges from \"%s\"[Vertix ID: %ld] to \"%s\"[Vertix ID: %ld]\n", location[i].location, i,location[i].edges[j].to_location, *to_vertix);
            add_direct_edge(*graph, i, *to_vertix, location[i].edges[j].weight);
        }
    }
}


int main(int argc, char const *argv[])
{   
    ChainedHashMap *map = new_chained_hashmap(sizeof(size_t), 30);
    AdjListGraph *graph = NULL;
    setup_data(&graph, map);

    char response[255];
  
    
    while (1)
    {
        printf("Keyword: ");
        scanf(" %[^\n]s", response);

        size_t *n = get_value_hashmap(map, response);
        if(!strcmp(response, "QUIT")){
            break;
        }
        if (n)
        {
            printf("Vertex ID: %ld\n", *n);
        } else {
            printf("Something Wrong!\n");
        }
        
    }
    

    //Give out 10 location points

    //Put it in hashmap to identify their indexes
    free_hashmap(map);
    free_adjListGraph(graph);
    return 0;
}
