#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main()
{
    //showing avaible variables
    printf("Which variable to check\n");
    printf("-------------------------------------\n");
    printf("1. name\n");            //robot name
    printf("2. battery\n");         //battery charge status
    printf("3. temperature\n");     //showing temperature in celcius degree
    printf("4. velocity\n");        //robot velocity
    printf("5. status\n");          //robot status(exploring/sampling/returning/idle)
    printf("6. size\n");            //showing size of each variable
    printf("7. values\n\n");        //showing max and min values of battery, temperature and velocity

    //declaring variables
    int intSize;
    unsigned int battery_status, speed, maxBattery = 100, minBattery = 0, maxSpeed = 30, minSpeed = 0;
    float temp = -13.34, floatSize, deciSpeed, maxTemp = 150, minTemp = -150;
    char robot_name[20] = "C3PO", robot_status[20] = "Exploring", choose[30], charSize;

    //checking which variable were choosen
    do
    {
        //choosing variable
        scanf_s("%s", choose, 20);

        if (strcmp(choose, "name") == 0)
        {
            printf("%s", robot_name);
            break;
        }
        //showing battery status
        else if (strcmp(choose, "battery") == 0)
        {
            srand(time(NULL));
            battery_status = rand() % 100 + 1; //random battery charge status
            printf("%d", battery_status);
            printf("%%\n");
            break;
        }
        //showing temperature
        else if (strcmp(choose, "temperature") == 0)
        {
            printf("Temperature is: ");
            printf("%g", temp);
            printf("*C\n");
            printf("Do you want to convert celcius to kelvin degrees? yes/no\n");
            scanf_s("%s", choose, 20);
            //C degrees to K degrees
            if (strcmp(choose, "yes") == 0)
            {
                printf("%g", temp + 273.15);
                printf("*K\n");
                break;
            }
            //converting temperature to absolute value
            else if (strcmp(choose, "no") == 0)
            {
                printf("Do you want to convert the temperature value to its absolute value? yes/no\n");
                scanf_s("%s", choose, 20);
                if (strcmp(choose, "yes") == 0)
                {
                    printf("Absolute value is ");
                    printf("%g", fabs(temp));
                    break;
                }
            }
        }
        //showing velocity
        else if (strcmp(choose, "velocity") == 0)
        {
            srand(time(NULL));
            speed = rand() % 29 + 1;
            printf("Velocity is: ");
            printf("%d", speed);
            printf(" km/h\n");
            printf("Do you want to displaying the velocity in decimal notation and scientific notation? yes/no\n");
            scanf_s("%s", choose, 20);
            //velocity in decimal and scientific notation
            if (strcmp(choose, "yes") == 0)
            {
                //decimal notation
                printf("Velocity in decimal notation: ");
                deciSpeed = speed;
                printf("%f", deciSpeed);
                printf("\n");
                //scientific notation
                printf("Velocity in scientific notation: ");
                printf("%E", deciSpeed);
                printf("\n");
                break;
            }
            else
                return 0;
        }
        //showing robot status
        else if (strcmp(choose, "status") == 0)
        {
            printf("%s\n", robot_status);
            printf("Do you want to change the status? yes/no\n");
            scanf_s("%s", choose, 20);
            //changing status
            if (strcmp(choose, "yes") == 0)
            {
                printf("Select a status (exploring/samplingreturning/idle");
                scanf_s("%s\n", robot_status);
                printf("%s\n", robot_status);
            }
            else
                break;
        }
        //showing variables size
        else if (strcmp(choose, "size") == 0)
        {
            printf("Size of int: %zu bytes\n", sizeof(intSize));
            printf("Size of float: %zu bytes\n", sizeof(floatSize));
            printf("Size of char: %zu byte\n", sizeof(charSize));
            break;
        }
        //showing max and min values
        else if (strcmp(choose, "values") == 0)
        {
            printf("Min value of battery status: %d\n", minBattery);
            printf("Max value of battery status: %d\n", maxBattery);

            printf("Min value of temperature: %g\n", minTemp);
            printf("Max value of temperature: %g\n", maxTemp);

            printf("Min value of velocity: %d\n", minSpeed);
            printf("Max value of velocity: %d\n", maxSpeed);
            break;
        }
        //non of option choosen
        else
            printf("There is no such a variable. Try again.\n");
    }
    while (choose != "name","battery","temperature","velocity","status","size","values");

    return 0;
}
