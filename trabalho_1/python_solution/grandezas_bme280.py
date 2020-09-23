import smbus2
import bme280
import RPi_I2C_driver
import time

porta_i2c = 1
endereco = 0x76
bus = smbus2.SMBus(porta_i2c)

calibracao_parametros = bme280.load_calibration_params(bus, endereco)

newlcd = RPi_I2C_driver.lcd()


while True:
	dado = bme280.sample(bus, endereco, calibracao_parametros)
	
	newlcd.lcd_clear()
	newlcd.lcd_display_string("T: " + str(round(dado.temperature, 2)) + " U: " + str(round(dado.humidity, 2)), 1)
	newlcd.lcd_display_string("P: " + str(round(dado.pressure, 2)) + "  LM", 2)
	
	time.sleep(1)
	
'''
print("ID: " + str(dado.id))
print("Data/HR: " + str(dado.timertamp))
'''

print("T: " + str(dado.temperature) + " U: " + str(dado.humidity) + " P: " + str(dado.pressure))

