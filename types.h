#include <Arduino.h>

using ProtoHandler = void (*)(const uint8_t* buffer, int length);

using VoidCallback = std::function<void()>;
