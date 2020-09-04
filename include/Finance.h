#ifndef FINANCE_H
#define FINANCE_H


class Finance
{
    protected:
        double govStipend;  // monthly gov sanctioned stipend that is the fixed amount
        double salesRev;
        double bail;
        double lease;
        double maintenance;
        double food;
        double salaryCost;
        double eduCost;
        double laundryCost;
        double misc;
        char* quarterName;
    public:
        // ctors
        Finance();
        Finance(double stipend, double sales, double bail, double lease, double maintenance, double food, double salary, double edu, double laundry, double misc, char *qName);

        //getters
        double getStipend();
        double getSales();
        double getBail();
        double getLease();
        double getMaintenance();
        double getFood();
        double getSalary();
        double getEdu();
        double getLaundry();
        double getMisc();
        char* getQuarter();
        void getInfo();

        //setters
        void setStipend(double stipend);
        void setSales(double sales);
        void setBail(double bailAmount);
        void setLease(double leaseAmount);
        void setMaintenance(double maintAmount);
        void setFood(double foodAmount);
        void setSalary(double salaryAmount);
        void setEdu(double eduAmount);
        void setLaundry(double laundryAmount);
        void setMisc(double miscAmount);
        void setQuarter(char* qName);
        void setInfo(double stipend, double sales, double bailAmount, double leaseAmount, double maintAmount, double foodAmount, double salaryAmount, double eduAmount, double laundryAmount, double miscAmount, char* qName);

};

#endif // FINANCE_H
