#include "MLX90614.h"
int fBodyTempture;
/* MLAX90614 Correction function */
void MLAX90614_ReviseTempture(int lFd)
{
    /* Emissivity correction, MLAX90614 generally defaults to 1, the emissivity of the human body is 0.95 */
    wiringPiI2CWriteReg16 (lFd, MLX90614_REVISE_ADDR, MLX90614_REVISE_EMISSIVITY);  
}

/* MLAX90614 temperature reading */
void MLAX90614_ReadTempture(int lFd)
{
	fBodyTempture = 0.0;  //Body temperature
    float fEnvTempture = 0.0;   //Ambient temperature value
    int lBodyRegData = 0;       //Body temperature register value
    int lEnvRegData = 0;        //Ambient temperature register value
    /* Read body and ambient temperature register value */
    lBodyRegData = wiringPiI2CReadReg16(lFd, MLX90614_REG_BODYDATA);
    lEnvRegData = wiringPiI2CReadReg16(lFd, MLX90614_REG_ENVIRONMENTDATA);
    printf("Body reg data is %d\n", lBodyRegData);
    printf("Environment reg data is %d\n", lEnvRegData);

    /* Convert body and ambient temperature register value into actual temperature value */
    fBodyTempture = ((float)(lBodyRegData)*0.02)-273.15;
    fEnvTempture = ((float)(lEnvRegData)*0.02)-273.15;
    printf("Body tempture is %f\n", fBodyTempture);
    printf("Environment tempture is %f\n", fEnvTempture);
}

int sensor()//int argc, char **argv)
{ 
    int lFd = 0;
    /* Initialize all GPIO pins of Raspberry Pi*/
    wiringPiSetup();
    /* Start the Raspberry Pi I2C interface */
    lFd = wiringPiI2CSetup(MLX90614_ADDRESS);
    if(0 > lFd)
    {
        printf("wiringPiI2CSetup failed !\n");
        return lFd;
    }
    /* MLAX90614 correction */
    MLAX90614_ReviseTempture(lFd);

 //   while (1)
 //   {
	MLAX90614_ReadTempture(lFd);
 //       delay(1000);
 //   }
    
    return  0;
   // MLAX90614_ReadTempture(lFd); 
}
