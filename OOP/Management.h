#include "CareerEmployee.h"
#include "ContractualEmployee.h"
#include "List.cpp"

class Management {
private:
    //List<Empl
    Management() {}
    Management(Management const&);
    void operator=(Management const&);
    bool suitableName(string, string);
    List<Employee*> employees;

public:
    static Management& getInstance() {
        static Management instance;
        return instance;
    }
    int getSize();
    void insert(Employee*);
    void showAll();
    void showTypeEmployee(string);
    void searchByName(string);
    void updateByID(string, Date);
    void deleteByOrder(int);
};