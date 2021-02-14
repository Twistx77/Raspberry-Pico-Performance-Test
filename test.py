from machine import Pin, ADC, PWM, UART, I2C
import utime

LED_PIN = 25

led = Pin(LED_PIN, Pin.OUT)
marker = Pin(10, Pin.OUT)

led.value(0)
marker.value(0)

utime.sleep(2)

led = Pin(LED_PIN, Pin.OUT)
marker = Pin(10, Pin.OUT)

#Mark start of tests
led.value(1)
marker.value(1)

utime.sleep(1)

led.value(0)
marker.value(0)

utime.sleep(0.25)


##### Test GPIO #####

#Mark start
led.value(1)
marker.value(1)

out = Pin(1, Pin.OUT)

for i in range(1000000):
    out.value(1)
    out.value(0)

#Mark end    
marker.value(0)
led.value(0)

utime.sleep(0.1)


##### Test ADC #####

#Mark start
led.value(1)
marker.value(1)

adcPin = ADC(4)

for i in range(25000):
    adcPin.read_u16() 

#Mark end    
marker.value(0)
led.value(0)

utime.sleep(0.1)


##### Test PWM #####

#Mark start
led.value(1)
marker.value(1)

pwmPin = PWM(Pin(1))

for i in range(200000):
    pwmPin.duty_u16(i) 

#Mark end    
marker.value(0)
led.value(0)

utime.sleep(0.1)

##### Test UART #####

#Mark start
led.value(1)
marker.value(1)

uart = UART(0, 115200)

for i in range(50):
    uart.write(' Testing!\n')

#Mark end    
marker.value(0)
led.value(0)


utime.sleep(0.1)

##### Test I2C (MPU6050) a#####

#Mark start
led.value(1)
marker.value(1)

i2c = I2C(1, scl=Pin(19), sda=Pin(18), freq=400000)

for i in range(500):
    i2c.readfrom_mem(0x68, 0x75, 1)

#Mark end    
marker.value(0)
led.value(0)


utime.sleep(0.1)



##### Test Addition/Substraction #####

#Mark start
led.value(1)
marker.value(1)

result = 0;

for i in range(10000):
    result = result + 452135.324
    result = result - 324544.434 

#Mark end    
marker.value(0)
led.value(0)


utime.sleep(0.1)

##### Test Multiplication #####

#Mark start
led.value(1)
marker.value(1)

result = 1.0213

for i in range(10000):
    result =  result * 3.14159

#Mark end    
marker.value(0)
led.value(0)

utime.sleep(0.1)
##### Test Division #####

#Mark start
led.value(1)
marker.value(1)

result = 314321432143.235

for i in range(10000):
    result = result / 3.14159 

#Mark end    
marker.value(0)
led.value(0)


utime.sleep(0.1)

##### Test Bitwise operations #####

#Mark start
led.value(1)
marker.value(1)

result2 = 1254546
result3 = 4578846

for i in range(500000):
    result2 = (result3 >> 3) | result2 ^ (result3 << 2)

#Mark end    
marker.value(0)
led.value(0)

utime.sleep(0.1)

#Mark end of tests
led.value(1)
marker.value(1)

sleep_ms((result2+result3)/1000)
