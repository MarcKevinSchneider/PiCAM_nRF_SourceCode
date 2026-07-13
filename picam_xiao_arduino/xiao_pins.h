/*
 * Script function: Pin remap from nRF52840 Dongle (PCA10059) to Seeed XIAO nRF52840
 * ----------------------------------------------------------------
 * XIAO nRF52840 usable GPIO (avoid D6/D7 = UART, D4/D5 = I2C):
 *   D0, D1, D2, D3, D8, D9, D10
 */


#ifndef XIAO_PINS_H
#define XIAO_PINS_H

#define Pi_Enable_Pin   D0   // P0.02 -- drives Pi power MOSFET/load switch
#define GPS_Enable_Pin  D1   // P0.03 -- unused (no GPS), kept for compile compat

// PIN_WIRE_SDA = 4 (D4), PIN_WIRE_SCL = 5 (D5) per variant.h

/*
 * Battery voltage sensing -- confirmed from Seeed schematic + wiki:
 *
 *   READ_BAT_ENABLE = P0.14 (raw nRF52840 port pin number)
 *     Pull LOW  -> enables the 1510k/510k voltage divider on the battery line
 *     Pull HIGH -> disables divider (saves ~2.3uA)
 *     WARNING: never set HIGH while battery is charging -- P0.31 can be
 *     damaged if it exceeds its 3.6V input limit.
 *
 *   BATT_SENSE_PIN = PIN_VBAT (P0.31 / AIN7) -- ADC input after divider
 *
 *   Scale: adcCounts * (3.0 / 4096.0) * (1510.0 / 510.0)
 */
#define BATT_SENSE_PIN    PIN_VBAT  // P0.31 / AIN7
#define READ_BAT_ENABLE   14        // P0.14 -- raw pin number

#endif // XIAO_PINS_H
