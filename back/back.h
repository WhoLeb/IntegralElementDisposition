#include <array>
#include <unordered_map>
#include <vector>


struct coordinates
{
    int x, y;
};

struct connection
{
    int initial, final;
    std::string name;
    std::vector<coordinates> path;
};

class integral_element
{
public:
    integral_element(int x, int y)
        : coords({x, y}){};

    coordinates coords;
    std::string name;
    std::vector<connection> connections;
};

class Schema
{
public:
    Schema(int x, int y)
        : dimentions_x(x), dimentions_y(y){};

    int dimentions_x, dimentions_y;
    std::vector<integral_element> elements;
    std::vector<std::vector<int>> schema_map;

    void clear_map();
};

void Schema::clear_map()
{
    for(auto i: schema_map)
        for(auto j: i)
            j = 0;
}

class Back
{
public:
    Schema *read_file(std::string filename);
    int write_file(Schema);

    Schema genetic_update(Schema*);

private:
    int A_star(Schema*, connection);
};