#pragma once
#include "nvs.h"
#include "esp_wifi.h"

// Clears WiFi credentials from NVS by erasing station SSID and password keys
inline void clear_wifi_credentials() {
  nvs_handle_t nvs_handle;
  esp_err_t err = nvs_open("nvs.net80211", NVS_READWRITE, &nvs_handle);
  if (err != ESP_OK) {
    ESP_LOGW("wifi_clear", "Failed to open NVS handle: %s", esp_err_to_name(err));
    return;
  }
  
  nvs_erase_key(nvs_handle, "sta_ssid");
  nvs_erase_key(nvs_handle, "sta_passwd");
  nvs_erase_key(nvs_handle, "sta_bssid");
  nvs_commit(nvs_handle);
  nvs_close(nvs_handle);
  
  ESP_LOGI("wifi_clear", "WiFi credentials erased from NVS");
  esp_wifi_disconnect();
}

