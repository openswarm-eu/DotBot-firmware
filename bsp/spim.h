#ifndef __SPIM_H
#define __SPIM_H

/**
 * @defgroup    bsp_spim SPI Master
 * @ingroup     bsp
 * @brief       Control the SPIM peripheral
 *
 * @{
 * @file
 * @author Alexandre Abadie <alexandre.abadie@inria.fr>
 * @copyright Inria, 2024-present
 * @}
 */

#include <stdint.h>
#include <stdlib.h>
#include <nrf.h>
#include "gpio.h"

/// SPIM frequency register values (must be left shifted by 6)
#define DB_SPIM_FREQ_125K (0x02000000)  ///< 125 kHz
#define DB_SPIM_FREQ_250K (0x04000000)  ///< 250 kHz
#define DB_SPIM_FREQ_500K (0x08000000)  ///< 500 kHz
#define DB_SPIM_FREQ_1M   (0x10000000)  ///< 1 MHz
#define DB_SPIM_FREQ_2M   (0x20000000)  ///< 2 MHz
#define DB_SPIM_FREQ_4M   (0x40000000)  ///< 4 MHz
#define DB_SPIM_FREQ_8M   (0x80000000)  ///< 8 MHz
#define DB_SPIM_FREQ_16M  (0x0A000000)  ///< 16 MHz
#define DB_SPIM_FREQ_32M  (0x14000000)  ///< 32 MHz

/// SPIM pin configuration
typedef struct {
    const gpio_t *mosi;  ///< Master Out Slave In
    const gpio_t *miso;  ///< Master In Slave Out
    const gpio_t *sck;   ///< Clock
} db_spim_conf_t;

/// SPIM mode
typedef enum {
    DB_SPIM_MODE_0 = 0,  ///< CPOL = 0 (Active High), CPHA = 0 (Leading)
    DB_SPIM_MODE_1,      ///< CPOL = 0 (Active High), CPHA = 1 (Trailing)
    DB_SPIM_MODE_2,      ///< CPOL = 1 (Active Low), CPHA = 0 (Leading)
    DB_SPIM_MODE_3       ///< CPOL = 1 (Active Low), CPHA = 1 (Trailing)
} db_spim_mode_t;

/**
 * @brief Initialize the SPIM peripheral
 *
 * @param[in] conf      pointer to configuration struct
 */
void db_spim_init(const db_spim_conf_t *conf);

/**
 * @brief Begin transmission on SPIM
 *
 * @param[in]   cs      Pointer to the chip select pin
 * @param[in]   mode    SPI mode
 * @param[in]   freq    SPI clock frequency
 */
void db_spim_begin(const gpio_t *cs, db_spim_mode_t mode, uint32_t freq);

/**
 * @brief End transmission on SPIM
 *
 * @param[in]   cs      Pointer to the chip select pin
 */
void db_spim_end(const gpio_t *cs);

/**
 * @brief Read bytes from one register
 *
 * @param[out]  out     Pointer to the output byte array
 * @param[in]   in      Pointer to the in byte array
 * @param[in]   len     Length of the bytes to transfer
 */
void db_spim_transfer(const void *out, void *in, size_t len);

#endif
