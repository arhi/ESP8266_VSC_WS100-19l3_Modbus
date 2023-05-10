#ifndef _SDM72DM_H_
#define _SDM72DM_H_

// All input registers are 4 bytes float
// Offset values for each input register (protocol 04, addresses start at 30000)

#define Phase1Volts                    0x0000    // V   Phase 1 line to neutral volts  
#define Phase2Volts                    0x0002    // V   Phase 2 line to neutral volts  
#define Phase3Volts                    0x0004    // V   Phase 3 line to neutral volts  
#define Phase1Current                  0x0006    // A   Phase 1 current  
#define Phase2Current                  0x0008    // A   Phase 2 current  
#define Phase3Current                  0x000A    // A   Phase 3 current  
#define Phase1ActivePower              0x000C    // W   Phase 1 active power  
#define Phase2ActivePower              0x000E    // W   Phase 2 active power  
#define Phase3ActivePower              0x0010    // W   Phase 3 active power  
#define Phase1ApparentPower            0x0012    // VA   Phase 1 apparent power  
#define Phase2ApparentPower            0x0014    // VA   Phase 2 apparent power  
#define Phase3ApparentPower            0x0016    // VA   Phase 3 apparent power  
#define Phase1ReactivePower            0x0018    // VAr   Phase 1 reactive power  
#define Phase2ReactivePower            0x001A    // VAr   Phase 2 reactive power  
#define Phase3ReactivePower            0x001C    // VAr   Phase 3 reactive power  
#define Phase1PowerFactor              0x001E    // None   Phase 1 power factor (1)  
#define Phase2PowerFactor              0x0020    // None   Phase 2 power factor (1)  
#define Phase3PowerFactor              0x0022    // None   Phase 3 power factor (1)  
#define AverageLineToNeutralVolts      0x002A    // V   Average line to neutral volts  
#define AverageLineCurrent             0x002E    // A   Average line current  
#define SumOfLineCurrents              0x0030    // A   Sum of line currents  
#define TotalSystemPower               0x0034    // W   Total system power  
#define TotalSystemVoltAmps            0x0038    // VA   Total system volt amps  
#define TotalSystemVAr                 0x003C    // VAr   Total system VAr  
#define TotalSystemPowerFactor         0x003E    // None   Total system power factor (1 )  
#define FrequencyOfSupplyVoltages      0x0046    // Hz   Frequency of supply voltages  
#define ImportActiveEnergy             0x0048    // kWh   Import active energy  
#define ExportActiveEnergy             0x004A    // kWh   Export active energy  
#define Line1ToLine2Volts              0x00C8    // V   Line 1 to Line 2 volts  
#define Line2ToLine3Volts              0x00CA    // V   Line 2 to Line 3 volts  
#define Line3ToLine1Volts              0x00CC    // V   Line 3 to Line 1 volts  
#define AverageLineToLineVolts         0x00CE    // V   Average line to line volts  
#define NeutralCurrent                 0x00E0    // A   Neutral current  
#define TotalActiveEnergy              0x0156    // kWh   Total active Energy (2)  
#define TotalReactiveEnergy            0x0158    // kVArh   Total reactive energy  
#define ResettableTotalActiveEnergy    0x0180    // kWh   resettable total active energy  
#define ResettableTotalReactiveEnergy  0x0182    // kVarh   Resettable total reactive energy  
#define ResettableImportActiveEnergy   0x0184    // kWh   resettable import active energy  
#define ResettableExportActiveEnergy   0x0186    // kWh   resettable export active energy  
#define NetkWh                         0x018C    // kWh   Net kWh (Import - Export)  
#define TotalImportActivePower         0x0500    // W   Total import active power  
#define TotalExportActivePower         0x0502    // W   Total export active power  


#endif // _SDM72DM_H_