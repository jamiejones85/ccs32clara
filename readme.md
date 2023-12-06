
# ccs32clara

STM32 talks with QCA7005 homeplug modem

## News / Change History / Functional Status

### 2023-12-06 Charging works on ABB triple charger and Compleo
The liboi port has been tested inside the CCS-to-CHAdeMO adapter and successfully charged a few kWh on said chargers

### 2023-08-03 Charging works on public Alpitronic charger

With the STM32F103RE on the Foccci board, the light-bulb-demo-charging on Alpitronic hypercharger worked on the first attempt.
Pictures here: https://openinverter.org/forum/viewtopic.php?p=59821#p59821

### 2023-07-18 Charging loop reached

Using the NUCLEO F303RE development board, the STM32 talks via SPI to the QCA7005 on the Ioniq CCM. The ccs32clara reaches the charging
loop, and shows the charging progress on the serial console in the Cube IDE.

## Todos
- [x] Implement TCP retry to compensate for single lost packets
- [ ] Takeover latest state machine updates from pyPLC
- [x] Control the CP line and the contactor outputs
- [x] Add CAN
- [x] Migrate to STM32F103RE, which is planned for the foccci board
- [ ] (much more)

## Build Environment

- arm-none-eabi-gcc
- The main.c is generated by the DeviceConfigurationTool, based on the .ioc file.
- Controller: STM32F103RE (and STM32F303RE on NUCLEO-F303RE evaluation board)

## Cross References

* The Hyundai Ioniq/Kona Charge Control Module (CCM): https://github.com/uhi22/Ioniq28Investigations/tree/main/CCM_ChargeControlModule_PLC_CCS
* The ccs32berta "reference project" (which uses an ESP32, talking via SPI to a QCA7005: https://github.com/uhi22/ccs32berta
* The ccs32 "reference project" (which uses ethernet instead of SPI, hardware is an ESP32 WT32-ETH01): https://github.com/uhi22/ccs32
* Hardware board which integrates an STM32, QCA7005 and more: https://github.com/uhi22/foccci
* pyPLC as test environment: https://github.com/uhi22/pyPLC
* Discussion on openinverter forum: https://openinverter.org/forum/viewtopic.php?t=3727
* Similar project discussed on SmartEVSE github: https://github.com/SmartEVSE/SmartEVSE-3/issues/25#issuecomment-1608227152

## Compiling
You will need the arm-none-eabi toolchain: https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
The only external depedencies are libopencm3 and libopeninv. You can download and build this dependency by typing

`make get-deps`

Now you can compile by typing

`make`

And upload it to your board using a JTAG/SWD adapter, the can-updater.py script or the esp32 web interface
