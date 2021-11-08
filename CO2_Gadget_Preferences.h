#include <Preferences.h>
Preferences preferences;

void printPreferences() {
  Serial.println("LOADED PREFERENCES FROM NVR:");
  Serial.printf("customCalibrationValue:%d\n", customCalibrationValue);
  Serial.printf("altidudeMeters:\t%d\n", altidudeMeters);
  Serial.printf("autoSelfCalibration:\t%s\n", ((autoSelfCalibration) ? "Enabled":"Disabled"));
  Serial.printf("co2OrangeRange:\t%d\n", co2OrangeRange);
  Serial.printf("co2RedRange:\t%d\n", co2RedRange);
  Serial.printf("TFTBrightness:\t%d\n", TFTBrightness);
  Serial.printf("activeBLE is:\t%s\n", ((activeBLE) ? "Enabled":"Disabled"));
  Serial.printf("activeWIFI:\t%s\n", ((activeWIFI) ? "Enabled":"Disabled"));
  Serial.printf("activeMQTT:\t%s\n", ((activeMQTT) ? "Enabled":"Disabled"));
  Serial.printf("rootTopic:\t%s\n", rootTopic.c_str());
  Serial.printf("mqttClientId:\t%s\n", mqttClientId.c_str());
  Serial.printf("mqttBroker:\t%s\n", mqttBroker.c_str());  
}
void initPreferences() {
  preferences.begin("CO2-Gadget", false);
  // preferences.clear(); // Remove all preferences
  customCalibrationValue = preferences.getUInt("customCalValue", 415);
  altidudeMeters = preferences.getUInt("altidudeMeters", 0);
  autoSelfCalibration = preferences.getBool("autoSelfCal", false);
  co2OrangeRange = preferences.getUInt("co2OrangeRange", 700);
  co2RedRange = preferences.getUInt("co2RedRange", 1000);
  TFTBrightness = preferences.getUInt("TFTBrightness", 100);
  activeBLE = preferences.getBool("activeBLE", true);
  activeWIFI = preferences.getBool("activeWIFI", false);
  activeMQTT = preferences.getBool("activeMQTT", false);
  rootTopic = preferences.getString("rootTopic", rootTopic);
  mqttClientId = preferences.getString("mqttClientId", mqttClientId);
  // String tempMQTTBroker = ""; 
  // strcpy(tempMQTTBroker, mqttBroker);
  // mqttBroker = preferences.getString("mqttBroker", mqttBroker).c_str();
  // tempMQTTBroker = preferences.getString("mqttBroker", mqttBroker).c_str();
  // tempMQTTBroker = preferences.getString("mqttBroker", mqttBroker);
  // tempMQTTBroker = preferences.getString("mqttBroker", String(mqttBroker));
  
  // mqttBroker = preferences.getString("mqttBroker", mqttBroker).c_str(); // Result in empty mqttBroker
  
  // string tempMQTTBroker(mqttBroker);
  // mqttBroker = tempMQTTBroker.c_str();
  mqttBroker = preferences.getString("mqttBroker", mqttBroker).c_str();
  Serial.printf("\nMQTT BROKER mqttBroker: %s\n\n", mqttBroker.c_str());
  
  // mqttBroker = preferences.getString("mqttBroker", mqttBroker);
  // mqttBroker = preferences.getString("mqttBroker", String(mqttBroker));
  // strcpy(mqttBroker, tempMQTTBroker);
  if (!activeWIFI) {
    activeMQTT = false; // If not WiFi active disable MQTT and save
    preferences.putBool("activeMQTT", activeMQTT);
  }
  preferences.end();
  printPreferences();
}

void putPreferences() {
  preferences.begin("CO2-Gadget", false);
  preferences.putUInt("customCalValue", customCalibrationValue);
  preferences.putUInt("altidudeMeters", altidudeMeters);
  preferences.putBool("autoSelfCal", autoSelfCalibration);
  preferences.putUInt("co2OrangeRange", co2OrangeRange);
  preferences.putUInt("co2RedRange", co2RedRange);
  preferences.putUInt("TFTBrightness", TFTBrightness);
  preferences.putBool("activeBLE", activeBLE);
  preferences.putBool("activeWIFI", activeWIFI);
  preferences.putBool("activeMQTT", activeMQTT);
  preferences.putString("rootTopic", rootTopic);
  preferences.putString("mqttClientId", mqttClientId);
  preferences.putString("mqttBroker", mqttBroker);
  preferences.end();
}