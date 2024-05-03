#include "esphome.h"

static const char *TAG = "test_comp";

class TestComponent : public Component {
public:
  void setup() override {
    ESP_LOGI(TAG, "*** setup()");    
  }
  
  void loop() override {
  }
};
