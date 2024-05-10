#include "esphome.h"
#include "zb_device.h"
#include "zbesp_runtime.h"

#define TAG "my_custom_component"

class ZbDeviceComponent : public Component {
public:
  ZbDeviceComponent(uint8_t deviceType) {
    m_device = new ZbDevice(deviceType); 
  }
  
  void setup() override
  {
  }
  
  void loop() override
  {
  }
  
//private:
  ZbDevice *m_device;
};

class ZbEndpointComponent : public Component {
public:
  ZbEndpointComponent(ZbDeviceComponent *device, uint8_t id, uint16_t profileId, uint16_t deviceId) {
    m_endpoint = new ZbEndpoint(*(device->m_device), id, profileId, deviceId);
  }
  
  void setup() override
  {
  }
  
  void loop() override
  {
  }
  
//private:
  ZbEndpoint *m_endpoint;
};

class ZbClusterComponent : public Component {
public:
  ZbClusterComponent(ZbEndpointComponent *endpoint, uint16_t id, uint8_t role) {
    m_cluster = new ZbCluster(*(endpoint->m_endpoint), id, role);
  }
  
  void setup() override
  {
  }
  
  void loop() override
  {
  }
  
//private:
  ZbCluster *m_cluster;
};

class ZbBasicClusterComponent : public Component {
public:
  ZbBasicClusterComponent(ZbEndpointComponent *endpoint, char *manufacturerName, char *modelIdentifier, uint8_t applicationVersion, uint8_t powerSource) {
    m_cluster = new ZbBasicCluster(*(endpoint->m_endpoint), manufacturerName, modelIdentifier, applicationVersion, powerSource);
  }
  
  void setup() override
  {
  }
  
  void loop() override
  {
  }
  
//private:
  ZbBasicCluster *m_cluster;
};

void ZbAttribute_StateChanged(ZbAttribute *za, uint8_t *data);

class ZbAttributeComponent : public Component {
public:
  ZbAttributeComponent(ZbClusterComponent *cluster, uint16_t id, int32_t value) {
    m_attr = new ZbAttribute(*(cluster->m_cluster), id, value);
    m_attr->setUserPtr(this);
    m_attr->onValueChanged(ZbAttribute_StateChanged);
    m_sensor = NULL;
  }
  
  void setValue(uint32_t value)
  {
    m_attr->setValue(value);
  }
  
  void registerSensor(esphome::template_::TemplateSensor *sensor) {
    m_sensor = sensor;
  }
  
  esphome::template_::TemplateSensor *getSensor()
  {
    return m_sensor;
  }
  
  void setup() override
  {
  }
  
  void loop() override
  {
  }
  
//private:
  ZbAttribute *m_attr;
  esphome::template_::TemplateSensor *m_sensor;
};

void ZbAttribute_StateChanged(ZbAttribute *za, uint8_t *data)
{
  //ESP_LOGI(TAG, "ZbAttribute_StateChanged");
  ZbAttributeComponent *attr = (ZbAttributeComponent *) (za->getUserPtr());
  assert(attr);
  esphome::template_::TemplateSensor *ts = attr->getSensor();
  if (ts) {
    ts->publish_state(*data);
    ESP_LOGI(TAG, "ts->publish_state %d", *data);
  }
}

class ZbRuntimeComponent : public Component {
public:
  ZbRuntimeComponent() {
    m_runtime = new EspZbRuntime();
  }
  
  void init(ZbDeviceComponent *device, bool appendMandatories = false) {
    m_runtime->init(*(device->m_device), appendMandatories);
  }
  
  void setup() override
  { 
    m_runtime->start();
  }
  
  void loop() override
  {
  }
  
//private:
  EspZbRuntime *m_runtime;
};
