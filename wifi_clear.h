#pragma once
#include "esp_log.h"
#include "nvs.h"
#include "esp_wifi.h"

inline void disable_wifi_autoconnect() {
  esp_err_t err = esp_wifi_set_auto_connect(false);
  if (err != ESP_OK) {
    ESP_LOGW("wifi_clear", "Failed to disable WiFi auto-connect: %s", esp_err_to_name(err));
  } else {
    ESP_LOGI("wifi_clear", "WiFi auto-connect disabled");
  }

  err = esp_wifi_disconnect();
  if (err != ESP_OK) {
    ESP_LOGW("wifi_clear", "Failed to disconnect WiFi: %s", esp_err_to_name(err));
  }

  err = esp_wifi_stop();
  if (err != ESP_OK) {
    ESP_LOGW("wifi_clear", "Failed to stop WiFi: %s", esp_err_to_name(err));
  }
}

// Clears persisted WiFi state before normal connection logic runs again.
inline void clear_wifi_credentials() {
  ESP_LOGW("wifi_clear", "clear_wifi_credentials() invoked");

  disable_wifi_autoconnect();

  nvs_handle_t nvs_handle;
  esp_err_t err = nvs_open("nvs.net80211", NVS_READWRITE, &nvs_handle);
  if (err != ESP_OK) {
    ESP_LOGW("wifi_clear", "Failed to open NVS handle: %s", esp_err_to_name(err));
  } else {
    err = nvs_erase_all(nvs_handle);
    if (err != ESP_OK) {
      ESP_LOGW("wifi_clear", "Failed to erase WiFi NVS namespace: %s", esp_err_to_name(err));
    } else {
      err = nvs_commit(nvs_handle);
      if (err != ESP_OK) {
        ESP_LOGW("wifi_clear", "Failed to commit WiFi NVS erase: %s", esp_err_to_name(err));
      } else {
        ESP_LOGI("wifi_clear", "WiFi credentials erased from NVS namespace");
      }
    }

    nvs_close(nvs_handle);
  }

  err = esp_wifi_restore();
  if (err != ESP_OK) {
    ESP_LOGW("wifi_clear", "esp_wifi_restore failed: %s", esp_err_to_name(err));
  } else {
    ESP_LOGI("wifi_clear", "ESP WiFi stack restored to defaults");
  }

  ESP_LOGW("wifi_clear", "clear_wifi_credentials() completed");
}

