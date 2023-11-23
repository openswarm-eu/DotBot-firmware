# DotBot: easy-to-use micro-robot for education and research purposes

[![CI][ci-badge]][ci-link]
[![Documentation][doc-badge]][doc-link]
[![License][license-badge]][license-link]

## Overview

This repository contains the source code for firmwares usable with the DotBot
hardware.

<div align="center">

![DotBot demo](doc/sphinx/_static/images/03app_dotbot.gif)

</div>

## Related projects

The DotBots ecosystem provides Python
[PyDotBot](https://github.com/DotBots/PyDotBot) to interacts with a nRF DK board
used a gateway.

The DotBots hardware design are published on GitHub at
[https://github.com/DotBots/DotBot-harware](https://github.com/DotBots/DotBot-hardware).

## Building firmwares

The source code of the different applications available in this repository can be built using
[SEGGER Embedded Studio for ARM](https://www.segger.com/downloads/embedded-studio).
In SEGGER embedded studio, use the package manager
(available in menu Tools > Package manager) to install the CMSIS 5 CMSIS-CORE,
CMSIS-DSP and nRF packages.

For details on SEGGER Embedded Studio, read the
[online documentation](https://studio.segger.com/index.htm?https://studio.segger.com/home.htm).

## Flashing firmwares

All DotBots and DKs are based on Nordic Semiconductors microcontrollers, so
we recommend that you use Nordic programming tools to flash firmwares:

- [nRF Command Line Tools](https://infocenter.nordicsemi.com/topic/ug_nrf_cltools/UG/cltools/nrf_command_line_tools_lpage.html)
- [nRF Connect Programmer](https://infocenter.nordicsemi.com/topic/ug_nc_programmer/UG/nrf_connect_programmer/ncp_introduction.html)

[ci-badge]: https://github.com/DotBots/DotBot-firmware/workflows/CI/badge.svg
[ci-link]: https://github.com/DotBots/DotBot-firmware/actions?query=workflow%3ACI+branch%3Amain
[doc-badge]: https://readthedocs.org/projects/dotbot-firmware/badge/?version=latest
[doc-link]: https://dotbot-firmware.readthedocs.io/en/latest
[license-badge]: https://img.shields.io/github/license/DotBots/DotBot-firmware
[license-link]: https://github.com/DotBots/dotbot-firmware/blob/main/LICENSE.txt
