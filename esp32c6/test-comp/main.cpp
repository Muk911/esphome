// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
logger::Logger *logger_logger;
preferences::IntervalSyncer *preferences_intervalsyncer;
Component *testcomp;
#include "test_comp.h"
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: test-comp
  //   build_path: /config/esphome/build/test-comp
  //   platformio_options:
  //     platform: https:github.com/platformio/platform-espressif32/archive/refs/tags/v6.6.0.zip
  //   includes:
  //   - test_comp.h
  //   friendly_name: ''
  //   area: ''
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2024.4.2
  App.pre_setup("test-comp", "", "", "", __DATE__ ", " __TIME__, false);
  // logger:
  //   level: INFO
  //   hardware_uart: UART0
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   logs: {}
  logger_logger = new logger::Logger(115200, 512);
  logger_logger->set_uart_selection(logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // esp32:
  //   board: esp32-c6-devkitc-1
  //   flash_size: 8MB
  //   partitions: partitions_zb.csv
  //   framework:
  //     version: 5.2.1
  //     sdkconfig_options:
  //       CONFIG_ESPTOOLPY_FLASHSIZE_8MB: y
  //       CONFIG_ZB_ENABLED: y
  //       CONFIG_ZB_ZED: y
  //       CONFIG_ZB_RADIO_NATIVE: y
  //       ZB_ED_ROLE: y
  //     advanced:
  //       ignore_efuse_mac_crc: false
  //     components: []
  //     source: ~3.50201.0
  //     platform_version: platformio/espressif32@5.4.0
  //     type: esp-idf
  //   variant: ESP32C6
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // external_components:
  //   - source:
  //       url: https:github.com/luar123/esphome.git
  //       ref: fix_logger
  //       type: git
  //     components:
  //     - logger
  //     refresh: 1d
  // custom_component:
  //   lambda: !lambda |-
  //     auto tc = new TestComponent();
  //     return {tc};
  //   components:
  //   - id: testcomp
  //   id: custom_component_customcomponentconstructor
  custom_component::CustomComponentConstructor custom_component_customcomponentconstructor = custom_component::CustomComponentConstructor([=]() -> std::vector<Component *> {
      #line 35 "/config/esphome/test-comp.yaml"
      auto tc = new TestComponent();
      return {tc};
  });
  testcomp = custom_component_customcomponentconstructor.get_component(0);
  testcomp->set_component_source("custom_component");
  App.register_component(testcomp);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
