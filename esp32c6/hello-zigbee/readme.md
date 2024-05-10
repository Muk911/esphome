### Пример прошивки ESPHome для Zigbee-устройства на базе ESP32-C6 ###
#### Сборка прошивки ####
Взято из [примера luar123](https://github.com/luar123/esphome_zb_sensor?tab=readme-ov-file#build-esphome-zigbee-sensor).
После первой сборки, заканчивающейся ошибкой, необходимо:
- скопировать файл idf_component.yml в папку .esphome/build/hello-zigbee/src/
- добавить следующие строки в файл .esphome/build/zb-sensor/sdkconfig.hello-zigbee
CONFIG_ZB_ENABLED=y
CONFIG_ZB_RADIO_NATIVE=y
CONFIG_ZB_ZED=y
ZB_ED_ROLE=y
