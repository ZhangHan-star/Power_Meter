#include "VOFA.h"
#include "TCP.h"
#include "lwip/sockets.h"
#include "string.h"

union VOFA_Data
{
  float data1[10];
  unsigned char data2[44];
}data;

union VOFA_Data data;


void VOFA_TCP_Send(float a,float b,float c,float d,float e,float f,float g,float h,float j,float k,char *datasend)
{
  unsigned char i=0;
  data.data1[i++]=a;
  data.data1[i++]=b;
  data.data1[i++]=c;
  data.data1[i++]=d;
  data.data1[i++]=e;
  data.data1[i++]=f;
  data.data1[i++]=g;
  data.data1[i++]=h;
  data.data1[i++]=j;
  data.data1[i++]=k;
  data.data2[40]=0x00;
  data.data2[41]=0x00;
  data.data2[42]=0x80;
  data.data2[43]=0x7f;
  memcpy(datasend,&data,44);
  // send(0,(char*)&data,44,0);
  // ESP_LOGI( "vofa");//打印接收到的数组
}


