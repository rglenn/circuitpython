 /*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Lucian Copeland for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/obj.h"
#include "py/mphal.h"
#include "stm32f4/pins.h"
#include "stm32f4/periph.h"

// I2C

I2C_TypeDef * mcu_i2c_banks[3] = {I2C1, I2C2, I2C3};

const mcu_i2c_sda_obj_t mcu_i2c_sda_list[7] = {
    I2C_SDA(1, 4, &pin_PB07),
    I2C_SDA(1, 4, &pin_PB09),
    I2C_SDA(2, 9, &pin_PB09),
    I2C_SDA(2, 9, &pin_PB03),
    I2C_SDA(3, 4, &pin_PC09),
    I2C_SDA(3, 9, &pin_PB04),
    I2C_SDA(3, 9, &pin_PB08)
};

const mcu_i2c_scl_obj_t mcu_i2c_scl_list[4] = {
    I2C_SCL(1, 4, &pin_PB06),
    I2C_SCL(1, 4, &pin_PB08),
    I2C_SCL(2, 4, &pin_PB10),
    I2C_SCL(3, 4, &pin_PA08)
};

// SPI

SPI_TypeDef * mcu_spi_banks[5] = {SPI1, SPI2, SPI3, SPI4, SPI5};

const mcu_spi_sck_obj_t mcu_spi_sck_list[15] = {
    SPI(1, 5, &pin_PA05),
    SPI(1, 5, &pin_PB03),
    SPI(2, 5, &pin_PB10),
    SPI(2, 5, &pin_PB13),
    SPI(2, 5, &pin_PC07),
    SPI(2, 5, &pin_PD03),
    SPI(3, 6, &pin_PB03),
    SPI(3, 7, &pin_PB12),
    SPI(3, 6, &pin_PC10),
    SPI(4, 6, &pin_PB13),
    SPI(4, 5, &pin_PE02),
    SPI(4, 5, &pin_PE12),
    SPI(5, 6, &pin_PB00),
    SPI(5, 6, &pin_PE02),
    SPI(5, 6, &pin_PE12)
};

const mcu_spi_mosi_obj_t mcu_spi_mosi_list[14] = {
    SPI(1, 5, &pin_PA07),
    SPI(1, 5, &pin_PB05),
    SPI(2, 5, &pin_PB15),
    SPI(2, 5, &pin_PC03),
    SPI(3, 6, &pin_PB05),
    SPI(3, 6, &pin_PC12),
    SPI(3, 5, &pin_PD06),
    SPI(4, 5, &pin_PA01),
    SPI(4, 5, &pin_PE06),
    SPI(4, 5, &pin_PE14),
    SPI(5, 6, &pin_PA10),
    SPI(5, 6, &pin_PB08),
    SPI(5, 6, &pin_PE06),
    SPI(5, 6, &pin_PE14)
};

const mcu_spi_miso_obj_t mcu_spi_miso_list[12] = {
    SPI(1, 5, &pin_PA06),
    SPI(1, 5, &pin_PB04),
    SPI(2, 5, &pin_PB14),
    SPI(2, 5, &pin_PC02),
    SPI(3, 6, &pin_PB04),
    SPI(3, 6, &pin_PC11),
    SPI(4, 6, &pin_PA11),
    SPI(4, 5, &pin_PE05),
    SPI(4, 5, &pin_PE13),
    SPI(5, 6, &pin_PA12),
    SPI(5, 6, &pin_PE05),
    SPI(5, 6, &pin_PE13)
};

const mcu_spi_nss_obj_t mcu_spi_nss_list[12] = {
    SPI(1, 5, &pin_PA04),
    SPI(1, 5, &pin_PA15),
    SPI(2, 5, &pin_PB09),
    SPI(2, 5, &pin_PB12),
    SPI(3, 6, &pin_PA04),
    SPI(3, 6, &pin_PA15),
    SPI(4, 6, &pin_PB12),
    SPI(4, 5, &pin_PE04),
    SPI(4, 5, &pin_PE11),
    SPI(5, 6, &pin_PB01),
    SPI(5, 6, &pin_PE04),
    SPI(5, 6, &pin_PE11)
};

//UART, Etc

//Timers
//TIM6 and TIM7 are basic timers that are only used by DAC, and don't have pins
TIM_TypeDef * mcu_tim_banks[14] = {TIM1, TIM2, TIM3, TIM4, TIM5, NULL, NULL, NULL, TIM9, TIM10,
                                    TIM11, NULL, NULL, NULL};

const mcu_tim_pin_obj_t mcu_tim_pin_list[44] = {
    TIM(2,1,1,&pin_PA00),
    TIM(5,2,1,&pin_PA00),
    TIM(2,1,2,&pin_PA01),
    TIM(5,2,2,&pin_PA01),
    TIM(2,1,3,&pin_PA02),
    TIM(5,2,3,&pin_PA02),
    TIM(2,1,4,&pin_PA03),
    TIM(5,2,4,&pin_PA03),
    TIM(9,3,1,&pin_PA02),
    TIM(9,3,2,&pin_PA03),
    TIM(3,2,1,&pin_PA06),
    TIM(3,2,2,&pin_PA07),
    TIM(1,1,1,&pin_PA08),
    TIM(1,1,2,&pin_PA09),
    TIM(1,1,3,&pin_PA10),
    TIM(1,1,4,&pin_PA11),
    TIM(2,1,1,&pin_PA15),
    TIM(3,2,3,&pin_PB00),
    TIM(3,2,4,&pin_PB01),
    TIM(2,1,2,&pin_PB03),
    TIM(3,2,1,&pin_PB04),
    TIM(3,2,2,&pin_PB05),
    TIM(4,2,1,&pin_PB06),
    TIM(4,2,2,&pin_PB07),
    TIM(4,2,3,&pin_PB08),
    TIM(10,2,1,&pin_PB08),
    TIM(4,2,4,&pin_PB09),
    TIM(11,2,1,&pin_PB09),
    TIM(2,1,3,&pin_PB10),
    TIM(3,2,1,&pin_PC06),
    TIM(3,2,2,&pin_PC07),
    TIM(3,2,3,&pin_PC08),
    TIM(3,2,4,&pin_PC09),
    TIM(4,2,1,&pin_PD12),
    TIM(4,2,2,&pin_PD13),
    TIM(4,2,3,&pin_PD14),
    TIM(4,2,4,&pin_PD15),
    TIM(9,3,1,&pin_PE05),
    TIM(9,3,2,&pin_PE06),
    TIM(1,1,1,&pin_PE09),
    TIM(1,1,2,&pin_PE11),
    TIM(1,1,3,&pin_PE13),
    TIM(1,1,4,&pin_PE14),
};

