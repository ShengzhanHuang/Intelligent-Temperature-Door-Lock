#include "MLX90614.h"
int fBodyTempture;
/* MLAX90614�������� */
void MLAX90614_ReviseTempture(int lFd)
{
    /* �����ʽ�����  MLAX90614һ��Ĭ����1�� ����ķ�����Ϊ0.95 */
    wiringPiI2CWriteReg16(lFd, MLX90614_REVISE_ADDR, MLX90614_REVISE_EMISSIVITY);
}

/* MLAX90614�¶ȶ�ȡ */
void MLAX90614_ReadTempture(int lFd)
{
    float fBodyTempture = 0.0;  //�����¶�ֵ
    float fEnvTempture = 0.0;   //�����¶�ֵ
    int lBodyRegData = 0;       //�����¶ȼĴ���ֵ
    int lEnvRegData = 0;        //�����¶ȼĴ���ֵ
    /* ��ȡ���弰�����¶ȼĴ���ֵ */
    lBodyRegData = wiringPiI2CReadReg16(lFd, MLX90614_REG_BODYDATA);
    lEnvRegData = wiringPiI2CReadReg16(lFd, MLX90614_REG_ENVIRONMENTDATA);
    //printf("Body reg data is %d\n", lBodyRegData);
    //printf("Environment reg data is %d\n", lEnvRegData);

    /* �����弰�����¶ȼĴ���ֵ�����ʵ���¶�ֵ */
    fBodyTempture = ((float)(lBodyRegData) * 0.02) - 273.15;
    fEnvTempture = ((float)(lEnvRegData) * 0.02) - 273.15;
    printf("Body tempture is %f\n", fBodyTempture);
    printf("Environment tempture is %f\n", fEnvTempture);
}

int sensor(int argc, char** argv)
{
    int lFd = 0;
    /* ��ʼ����ݮ������GPIO����*/
    wiringPiSetup();
    /* ������ݮ��I2C�ӿ� */
    lFd = wiringPiI2CSetup(MLX90614_ADDRESS);
    if (0 > lFd)
    {
        printf("wiringPiI2CSetup failed !\n");
        return lFd;
    }
    /* MLAX90614���� */
    MLAX90614_ReviseTempture(lFd);

    //   while (1)
    //   {
     //      MLAX90614_ReadTempture(lFd);
    //       delay(1000);
    //   }

    return  0;
    // MLAX90614_ReadTempture(lFd); 
}