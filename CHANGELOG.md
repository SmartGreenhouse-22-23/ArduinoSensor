## 1.0.0 (2023-01-24)


### Features

* **ArduinoMsg:** Start implement communication between arduino and esp ([250026d](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/250026d75ad99746b2fd1203e2f93c22ad1f80e0))
* **Esp:** add esp and arduino communication ([6ec3b97](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/6ec3b976663b805098cdc0d1a5695635976e1906))
* **ESP:** add files to handle message receiving via seriale and sending via mqtt ([2441106](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/2441106079a2e0fe61f99344fab6104630e238b6))
* **esp:** send data from the esp ([1123dd5](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/1123dd54ea470f9d146036ccbf041a52459b1215))
* **LampAndAlarm:** Implement lamp and alarm sensor ([09737ad](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/09737adaef1dede3a509a58be6734725189a9e36))
* **ListenerTask:** add listener to handle received messages ([b24e955](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/b24e9553d0b5b911cb4991e081b2ce6f14f7c027))
* modify callback method to send message to arduino, don't WORK ([62fa4bd](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/62fa4bd497d35c23f677a5c5b9705ea4bd6b81b6))
* **Photoresistor:** implement photoresistor sensor ([f379570](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/f379570e2607d44db6701910b78c35ea5c96190e))
* **Scheduler:** add task sensing and scheduler to handle it ([fb2062c](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/fb2062c72ec7af759b27087d0ad004ed2a4d0443))
* **SoilMoisture:** add file for managing soil moisture sensor measuraments ([501695a](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/501695a863a211d03782bc2410371d4d5d38d36d))
* **TempAndHumidity:** Implement DHT11 air temperature and humidity sensor ([bccc21c](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/bccc21cd55bba95b1901a0881fd3f990b1d867c2))
* **Ventilation:** implement ventilation module ([4ae0b36](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/4ae0b36b12d5d061eea2b683e5aea8e54ecc87cc))


### Bug Fixes

* correct lamp pin caused by timer used pin ([0beba70](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/0beba70d7d7c2ad1cfe9c2029ab544d0542e179e))
* correct term_lamp pin caused by timer used pin in order to manage also its brightness ([a0cc5bf](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/a0cc5bf89c0478f1504fa64a01015be28be4820d))
* fix include libraries declaration ([996308d](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/996308d338cf738101b320c8f68b1a068573056c))
* fix method signature in file .ino ([f765e41](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/f765e4145b8cfe952cc5de86850fe9afff772f3d))
* fix rebase conflicts ([21d4602](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/21d46022822d6a3859649bc649ed9906e5666f94))
* fix setup method ([9d5996f](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/9d5996fc7dcdbc9fde521ac172221772287ca20a))
* fix value returned from soil moisture sensor ([6bb1fd0](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/6bb1fd02ac47a2c56e2b7fbb3eaef685e0d20f57))
* fix water pomp activation ([4a7b456](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/4a7b4561cd55127bbf8b403c063c6332cfc4a156))
* fix water pomp behaviour ([43d60e5](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/43d60e5e7980c5b89c531c4f78168ffa9cc72247))
* fix waterpomp initialization ([60c8852](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/60c88520a7c64e3b01442da4e0db458e4968afea))
* **listenerTask:** fix manage temperature topic ([a8d7c22](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/a8d7c224767bf3a3cda4d30a406fdee05ceb62ab))
* **messages:** fix message sending to esp ([f7e78ef](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/f7e78efd4aac4bc60175208d9fd3edcd67a6316b))
* removed wrong line ([309e63b](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/309e63b38a63d3bf49f6065af02ee4f30fcaf36f))
* **SensingTask:** fix type missmatch ([e9a0df6](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/e9a0df6fe852c532dd484a12e1f30e8f3aaed301))
* **ventilation:** change ventilation pin ([d8239d6](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/d8239d6157d9a2e3f586eaf2ca7d0c7371f61bab))
* **ventilation:** fix fan pin direction ([af2aa0b](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/af2aa0b7601543570e596c37ed42e1aefecdf0d8))


### General maintenance

* create template arduino project ([91ca19e](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/91ca19e75b98312e1284c76acb7a0896a3230312))
* **README:** write todo on readme ([d4cccea](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/d4cccead6bcee95babffac68ffc89942866e8ec6))


### Refactoring

* refactor code ([22e8b16](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/22e8b163e3026c9ac6089a3977f946cf571743ab))


### Documentation

* add documentation to arduino.ino ([f984f6d](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/f984f6db40734eb1982530f41d4fde04ef59b900))
* add documentation to Environment and Light interfaces and implementations ([13bd76f](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/13bd76f4a302cbcb319a0797abce855c2758d9c3))
* add documentation to EspProject.ino file ([f335e74](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/f335e742cadf4d91f317b6bb73968a31352a45bf))
* add documentation to public functions ([600fa22](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/600fa22e8a1b29f753a630c14413733ab1e4fb0c))
* add documentation to some file of the project ([b759ddb](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/b759ddbdc9fb9aa74fd58db6e87d5c62539b3334))
* add README.md ([386d2a1](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/386d2a1dd11b3bbd760834171daa29e834d4d3f8))


### Build and continuous integration

* ad action to compile Arduino sketch ([3d3234a](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/3d3234a9e491dc713f7183ddf527a76d9925a4f9))
* add json configuration for new steps in the workflow ([682533b](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/682533b16de9896c009ef2ececdd64b051e089a9))
* change indentation in file yaml ([553d74b](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/553d74b6e56472ac46290d2d22872a58dfdc8e23))
* set Arduino project as working directory and add library ([ed2ba53](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/ed2ba536fa7e0b455b350c0d7ba4e6944e3c0169))
* setted action for compiling esp project ([f66f328](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/f66f328a6b0c81f3b10ff2c9dbea71e717971ed8))
* update dependency job ([22cb899](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/22cb8996825640090c8a46daabc4ba6398fc00ae))
* update dependency job ([b9d60cd](https://github.com/SmartGreenhouse-22-23/ArduinoSensor/commit/b9d60cd9d1b57fd1ecd6fbe5ef0da5f5cee46d72))
