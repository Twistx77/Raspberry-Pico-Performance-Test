#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"

const uint LED_PIN = 25;
uint32_t i;
double result;

int main() {
    
    gpio_init(LED_PIN);
    gpio_init(10);
        
    
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(10, GPIO_OUT);
    
   
    // Mark start of tests
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    sleep_ms(1000);
    
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0); 
    
    sleep_ms(100);
   
 
    
    /// Test GPIO ///
    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    gpio_init(1);
    gpio_set_dir(1, GPIO_OUT);    
    
    for (i=0 ;i<1000000; i++)
    {
    	gpio_put(1, 1);
    	gpio_put(1, 0);	
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0); 
   
    
    sleep_ms(100);
    
    
    /// Test ADC ///    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    stdio_init_all();    
    
    adc_init();
    
    adc_gpio_init(26);
    
    adc_select_input(0);        
    
    for (i=0 ;i<25000; i++)
    {
    	adc_read();
    }   
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0); 
        
    sleep_ms(100);
    
    
    //// Test PWM ///
    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);

    gpio_set_function(1, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(1);    
    pwm_clear_irq(pwm_gpio_to_slice_num(1));    
    pwm_config config = pwm_get_default_config();    
    pwm_init(slice_num, &config, true);

    for (i=0 ;i<200000; i++)
    {
	pwm_set_gpio_level(1, i);    	
    } 

    // Mark end
    gpio_put(10, 0);
   gpio_put(LED_PIN, 0);
    
    
    sleep_ms(100);
    
    
    
    ///// Test UART ////
    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    uart_init(uart0, 115200);    
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    
    for (i=0 ;i<50; i++)
    {
    	uart_puts(uart0, " Testing!\n");
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0);  
    
    sleep_ms(100);
    
    
    /// Test I2C ///
    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    i2c_init(i2c1, 400000);
    gpio_set_function(18, GPIO_FUNC_I2C);
    gpio_set_function(19, GPIO_FUNC_I2C);
    gpio_pull_up(18);
    gpio_pull_up(19);
    
    uint8_t buffer[2];
    uint8_t  reg = 0x75;
    
    for (i=0 ;i<500; i++)
    {
    	i2c_write_blocking(i2c1, 0x68, &reg, 1, true); 
    	i2c_read_blocking(i2c1, 0x68, buffer, 1, false);
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0);   
    
    
    sleep_ms(100);
    
    
    /// Test Addition / Substraction ///
     
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    uint32_t result = 0; 
    
    for (i=0 ;i<10000; i++)
    {
    	result = result + 452135.324;
    	result = result -324544.434;  	
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0); 
   
    sleep_ms(result); // Use result to avoid optimization
    
    sleep_ms(100);
    
    
    
    ///// Test Multiplication ////
        
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    uint8_t result = 1.0213;
    
    for (i=0 ;i<10000; i++)
    {
    	result = result * 3.14159;  	
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0);     
      
    sleep_ms(result); // Use result to avoid optimization
      
    sleep_ms(100);  
        
    
    
    /// Test Division ///    
    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    uint32_t result = 314321432143.235;    
    
    for (i=0 ;i<10000; i++)
    {
    	result /= 3.14159;    	    	
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0);
    
    sleep_ms(result); // Use result to avoid optimization
    
    sleep_ms(100);  
    
    /// Test Bitwise operations ///
    
    // Mark start
    gpio_put(LED_PIN, 1);
    gpio_put(10, 1);
    
    uint32_t result2 = 1254546;
    uint32_t result3 = 4578846;    
    
    for (i=0 ;i<500000; i++)
    {
    	result2 = (result3 >> 3) | result2 ^ (result3 << 2);     	 		
    }
    
    // Mark end
    gpio_put(10, 0);
    gpio_put(LED_PIN, 0);
    
    sleep_ms(result2+result3); // Use result to avoid optimization
    
    sleep_ms(100);
   
    // Mark end
    gpio_put(10, 1);
    gpio_put(LED_PIN, 1);
   
}
