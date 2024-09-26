#ifndef __DISPLAY_H__
#define __DISPLAY_H__

void Delay(unsigned int xms);
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0};
void Nixie(unsigned char Location,Number);
unsigned char ScanKey();
unsigned char  LoneScanKey();
#endif