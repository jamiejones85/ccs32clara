

#include "ccs32_globals.h"

uint16_t checkpointNumber;

/* Helper functions */

void setCheckpoint(uint16_t newcheckpoint) {
    checkpointNumber = newcheckpoint;
    Param::SetInt(Param::checkpoint, newcheckpoint);
}

void addToTrace(enum Module module, const char * s) {
   if (Param::GetInt(Param::logging) & module)
      printf("[%d] %s\r\n", rtc_get_ms(), s);
   // canbus_addStringToTextTransmitBuffer(mySerialPrintOutputBuffer); /* print to the CAN */
}

void showAsHex(uint8_t *data, uint16_t len, const char *description) {
   int i;
   /*printf("%s (%d bytes): ", description, len);
   for (i=0; i<len; i++) {
       printf("%02x ", data[i]);
   }*/
}

void sanityCheck(const char *hint) {
    /* todo: check the canaries, config registers, maybe stack, ... */
}

