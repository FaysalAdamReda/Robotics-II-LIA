#include <PS4Controller.h>
#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define CENTER_X 2
#define CENTER_Y -2
#define DEADZONE 3

class PS4CarController {
  public:
    PS4CarController();
    void init();
    void update();
    void sendValuesOverI2C(byte mappedAngle);
    static void staticNotify();
    static void staticOnConnect();
    static void staticOnDisConnect();

  private:
    unsigned long lastTimeStamp;
    int x_center;
    int y_center;
    int deadzone;
    void notify();
    void onConnect();
    void onDisConnect();
    static PS4CarController* instance;
};
