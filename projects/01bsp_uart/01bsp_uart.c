/**
 * @file 01bsp_uart.c
 * @author Alexandre Abadie <alexandre.abadie@inria.fr>
 * @brief This is a short example of how to use the UART API.
 *
 * @copyright Inria, 2022
 *
 */
#include <nrf.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "gpio.h"
#include "uart.h"

//=========================== defines ==========================================

#define DB_UART_MAX_BYTES (64U)  ///< max bytes in UART receive buffer

typedef struct {
    uint8_t buffer[DB_UART_MAX_BYTES];  ///< buffer where message received on UART is stored
    uint8_t pos;                        ///< current position in the UART buffer
} uart_vars_t;

//=========================== variables ========================================

static const gpio_t _rx_pin    = { .pin = 9, .port = 0 };
static const gpio_t _tx_pin    = { .pin = 10, .port = 0 };
static uart_vars_t  _uart_vars = { 0 };

//=========================== callbacks ========================================

static void uart_callback(uint8_t byte) {
    _uart_vars.buffer[_uart_vars.pos] = byte;
    _uart_vars.pos++;
    if (byte == '\n' || _uart_vars.pos == DB_UART_MAX_BYTES - 1) {
        db_uart_write(_uart_vars.buffer, _uart_vars.pos);
        _uart_vars.pos = 0;
    }
}

//=========================== main =============================================

/**
 *  @brief The program starts executing here.
 */
int main(void) {
    db_board_init();
    db_uart_init(&_rx_pin, &_tx_pin, 1000000, &uart_callback);

    while (1) {
        __WFE();
    }

    // one last instruction, doesn't do anything, it's just to have a place to put a breakpoint.
    __NOP();
}