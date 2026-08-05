#pragma once
// Forward-declares esp_wifi_restore at file scope so lambdas can call it without the full esp_wifi.h header
extern "C" esp_err_t esp_wifi_restore(void);
