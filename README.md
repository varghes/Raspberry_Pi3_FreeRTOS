# FreeRTOS Raspberry Pi3  (BCM2837)

## Building

Get the compiler ,  gcc-arm-none-eabi-4_7-2013q3-20130916-win32.exe 
or download it from my google drive ,install it , when it asks environment variable , just skip it .

https://drive.google.com/open?id=1-0Cy-zFqS9TJBSg7oknKmI__W69GrhNu


C:\Program Files (x86)\GNU Tools ARM Embedded\4.7 2013q3\bin\gccvar.bat   run this , may be you can make a shortcut to desktop

move to the folder  ,my project files are copied in  D drive folder 

d:   'enter'
CD 'path'   'enter'
Type 'make' 


Linux/Mac users install suitable compiler & enter 'make'

FreeRTOS demo creates 2 Tasks , one controls  LED & other prints text. 

Connect to USB-UART to see task status 

attached working kernel.img image & bootloader files for hands on

Works only on Raspberry Pi3 or BCM2837 ....   
