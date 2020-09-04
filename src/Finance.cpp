#include "Finance.h"
#include<iostream>

Finance::Finance()
{
    //ctor
}

Finance::Finance(double stipend, double sales, double bail, double lease, double maintenance, double food, double salary, double edu, double laundry, double misc, char* qName):govStipend(stipend), salesRev(sales), bail(bail), lease(lease), maintenance(maintenance), food(food), salaryCost(salary), eduCost(edu), laundryCost(laundry), misc(misc), quarterName(qName)
{

}

//getters
double Finance::getStipend()
{
    return govStipend;
}

double Finance::getSales()
{
    return salesRev;
}

double Finance::getBail()
{
    return bail;
}

double Finance::getLease()
{
    return lease;
}

double Finance::getMaintenance()
{
    return maintenance;
}

double Finance::getFood()
{
    return food;
}

double Finance::getSalary()
{
    return salaryCost;
}

double Finance::getEdu()
{
    return eduCost;
}

double Finance::getLaundry()
{
    return laundryCost;
}

double Finance::getMisc()
{
    return misc;
}

char* Finance::getQuarter()
{
    return quarterName;
}

void Finance::getInfo()
{
    std::cout<<"Quarter: "<<Finance::getQuarter()<<std::endl;
    std::cout<<"Government sanctioned stipend: "<<Finance::getStipend()<<std::endl;
    std::cout<<"Revenue from Sales: "<<Finance::getSales()<<std::endl;
    std::cout<<"Revenue collected from bail: "<<Finance::getBail()<<std::endl;
    std::cout<<"Lease: "<<Finance::getLease()<<std::endl;
    std::cout<<"Maintenance cost: "<<Finance::getMaintenance()<<std::endl;
    std::cout<<"Food cost: "<<Finance::getFood()<<std::endl;
    std::cout<<"Personnel Salary cost: "<<Finance::getSalary()<<std::endl;
    std::cout<<"Prisoner education cost: "<<Finance::getEdu()<<std::endl;
    std::cout<<"Prisoner laundry cost: "<<Finance::getLaundry()<<std::endl;
    std::cout<<"Misc cost: "<<Finance::getMisc()<<std::endl;
}


//setters
void Finance::setStipend(double stipend)
{
    govStipend = stipend;
}

void Finance::setSales(double sales)
{
    salesRev = sales;
}

void Finance::setBail(double bailAmount)
{
    bail = bailAmount;
}

void Finance::setLease(double leaseAmount)
{
    lease = leaseAmount;
}

void Finance::setMaintenance(double maintAmount)
{
    maintenance = maintAmount;
}

void Finance::setFood(double foodAmount)
{
    food = foodAmount;
}

void Finance::setSalary(double salaryAmount)
{
    salaryCost = salaryAmount;
}

void Finance::setEdu(double eduAmount)
{
    eduCost = eduAmount;
}

void Finance::setLaundry(double laundryAmount)
{
    laundryCost = laundryAmount;
}

void Finance::setMisc(double miscAmount)
{
    misc = miscAmount;
}

void Finance::setQuarter(char* qName)
{
    quarterName = qName;
}

void Finance::setInfo(double stipend, double sales, double bailAmount, double leaseAmount, double maintAmount, double foodAmount, double salaryAmount, double eduAmount, double laundryAmount, double miscAmount, char* qName)
{
    Finance::setStipend(stipend);
    Finance::setSales(sales);
    Finance::setBail(bailAmount);
    Finance::setLease(leaseAmount);
    Finance::setMaintenance(maintAmount);
    Finance::setFood(foodAmount);
    Finance::setSalary(salaryAmount);
    Finance::setEdu(eduAmount);
    Finance::setLaundry(laundryAmount);
    Finance::setMisc(miscAmount);
    Finance::setQuarter(qName);
}
