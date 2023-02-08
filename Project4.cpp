/*
 * EE312 Simple CRM Project
 *
 * YOUR INFO HERE!
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;
Customer inventory1;



/* clear the inventory and reset the customer database to empty */
void reset(void) {
    inventory1.bottles = 0;
    inventory1.diapers = 0;
    inventory1.rattles = 0;
    for(int i = 0; i < num_customers;i++){
        customers[i].bottles = 0;
        customers[i].diapers = 0;
        customers[i].rattles = 0;
        StringDestroy(&customers[i].name);
    }
    num_customers = 0;
}

void processSummarize() {
    int x;
    int y;
    int z;
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n", inventory1.bottles, inventory1.diapers,inventory1.rattles);
    printf("we have had a total of %d different customers\n", num_customers);
    int maxBottles = 0;
    int maxDiapers = 0;
    int maxRattles = 0;
    for(int i = 0; i < num_customers;i++) {
        if (customers[i].bottles > maxBottles) {
            x = i;
            maxBottles = customers[i].bottles;
        }
        if (customers[i].diapers > maxDiapers) {
            y = i;
            maxDiapers = customers[i].diapers;
        }
        if (customers[i].rattles > maxRattles) {
            z = i;
            maxRattles = customers[i].rattles;
        }
    }
    if(maxBottles > 0) {
        printf("%s has purchased the most Bottles (%d)\n", customers[x].name.ptr, customers[x].bottles);
    }
    else {
        printf("no one has purchased any Bottles\n");
    }
    if(maxDiapers > 0){
        printf("%s has purchased the most Diapers (%d)\n", customers[y].name.ptr, customers[y].diapers);
    }
    else {
        printf("no one has purchased any Diapers\n");
    }
    if(maxRattles > 0) {
        printf("%s has purchased the most Rattles (%d)\n", customers[z].name.ptr, customers[z].rattles);
    }
    else {
        printf("no one has purchased any Rattles\n");

    }

}

void processPurchase() {
    String bottles =  StringCreate("Bottles");
    String diapers = StringCreate("Diapers");
    String rattles = StringCreate("Rattles");
    String in;
    String in2;
    int in3;

    readString(&in);
    readString(&in2);
    readNum(&in3);
    int a = 0;
    for(int i = 0; i < num_customers && a == 0;i++){
        if(StringIsEqualTo(&customers[i].name, &in)){
            a = 1;
            if(StringIsEqualTo(&bottles, &in2)){
                if(in3 > inventory1.bottles){
                    printf("Sorry %s, we only have %d Bottles\n",in.ptr, inventory1.bottles);
                }
                else {
                    inventory1.bottles -= in3;
                    customers[i].bottles += in3;
                }
            }
            if(StringIsEqualTo(&diapers, &in2)){
                if(in3 > inventory1.diapers){
                    printf("Sorry %s, we only have %d Diapers\n",in.ptr, inventory1.diapers);
                }
                else {
                    inventory1.diapers -= in3;
                    customers[i].diapers += in3;
                }
            }
            if(StringIsEqualTo(&rattles, &in2)){
                if(in3 > inventory1.rattles){
                    printf("Sorry %s, we only have %d Rattles\n",in.ptr, inventory1.rattles);
                }
                else {
                    inventory1.rattles -= in3;
                    customers[i].rattles += in3;
                }
            }
        }
    }
    if(a == 0){
        if(StringIsEqualTo(&bottles, &in2)){
            if(in3 > inventory1.bottles){
                printf("Sorry %s, we only have %d Bottles\n",in.ptr, inventory1.bottles);
            }
            else {
                customers[num_customers].name = StringDup(&in);
                inventory1.bottles = inventory1.bottles - in3;
                customers[num_customers].bottles += in3;
                num_customers++;
            }
        }
        if(StringIsEqualTo(&diapers, &in2)){
            if(in3 > inventory1.diapers){
                printf("Sorry %s, we only have %d Diapers\n",in.ptr, inventory1.diapers);
            }
            else {
                customers[num_customers].name = StringDup(&in);
                inventory1.diapers = inventory1.diapers - in3;
                customers[num_customers].diapers += in3;
                num_customers++;
            }
        }
        if(StringIsEqualTo(&rattles, &in2)){
            if(in3 > inventory1.rattles){
                printf("Sorry %s, we only have %d Rattles\n",in.ptr, inventory1.rattles);
            }
            else {
                customers[num_customers].name = StringDup(&in);
                inventory1.rattles = inventory1.rattles - in3;
                customers[num_customers].rattles += in3;
                num_customers++;
            }
        }
    }
    StringDestroy(&bottles);
    StringDestroy(&diapers);
    StringDestroy(&rattles);
    StringDestroy(&in); //this is causing the problem
    StringDestroy(&in2); //this is causing the problem

}

void processInventory() {
    String bottles =  StringCreate("Bottles");
    String diapers = StringCreate("Diapers");
    String rattles = StringCreate("Rattles");

    String in;
    int in2;
    readString(&in);
    readNum(&in2);
    if(StringIsEqualTo(&bottles, &in)){
        inventory1.bottles += in2;
    }
    else if(StringIsEqualTo(&diapers, &in)){
        inventory1.diapers += in2;
    }
    else {
        inventory1.rattles += in2;
    }
    StringDestroy(&bottles);
    StringDestroy(&diapers);
    StringDestroy(&rattles);
    StringDestroy(&in);


}