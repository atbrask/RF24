## ATtiny84 / avr-libc driver for nRF24L01(+) 2.4GHz Wireless Transceiver

### Motivation for this fork
I needed a way to interface with the popular nRF chips with an ATtiny84. The
best way to achieve this was to stand on the shoulders of giants and modify
the well-known RF24 Arduino library to fit my purposes.

### Differences compared to other versions of the RF24 library
The ATtiny84 is a much more limited platform than an Arduino is. Therefore,
I have changed a few things to make the library smaller and more lean:

* Removed all dependencies to Arduino libs. I use straight avr-libc instead.
* Removed all printf calls for serial debugging. I don't have a UART anyway.
* Added USI-based SPI functionality. The ATtiny84 lacks proper SPI support.

I have tried to keep the changes as uninvasive as possible. Apart from the
points above, the code should work exactly as before. However, I have
removed the tests and examples, as they make little sense in my use case.

The resulting library works flawlessly and uses very little resources.

### Notes
Remember to define F_CPU before including this library.

For more information about the original RF24 project, please refer to:

* [Documentation Main Page](http://maniacbug.github.com/RF24)
* [RF24 Class Documentation](http://maniacbug.github.com/RF24/classRF24.html)
* [Source Code](https://github.com/maniacbug/RF24)
* [Downloads](https://github.com/maniacbug/RF24/archives/master)
* [Chip Datasheet](http://www.nordicsemi.com/files/Product/data_sheet/nRF24L01_Product_Specification_v2_0.pdf)

/atbrask

