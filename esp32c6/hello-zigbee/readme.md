### Пример прошивки ESPHome для Zigbee-устройств на базе ESP32-C6 ###
Пример предназначен для демонстрации  принципиальной возможности сборки в ESPHome прошивки для Zigbee-устройств на базе ESP32-C6 или ESP32-H2.
Прошивка содержит минимальные функции лампочки.

Пример использует кастомные компоненты, являющиеся обертками над [Zigbee-классами для ESP32-C6/H2](https://github.com/Muk911/zigbee/tree/main/esp32c6/zblc).
В дальнейшем планируется преобразовать кастомный компонент ESPHome во внешний компонент ESPHome и избавиться от костылей для передачи значений в виде шаблонных сенсоров.

#### Сборка прошивки ####
Взято из [примера от luar123](https://github.com/luar123/esphome_zb_sensor?tab=readme-ov-file#build-esphome-zigbee-sensor).
После первой сборки, заканчивающейся ошибкой, необходимо:
- скопировать файл idf_component.yml в папку .esphome/build/hello-zigbee/src/
- добавить следующие строки в файл .esphome/build/zb-sensor/sdkconfig.hello-zigbee
```
CONFIG_ZB_ENABLED=y
CONFIG_ZB_RADIO_NATIVE=y
CONFIG_ZB_ZED=y
ZB_ED_ROLE=y
```
