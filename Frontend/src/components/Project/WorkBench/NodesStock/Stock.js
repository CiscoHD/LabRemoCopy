//ACTUADORES
import DcMotor from "./Actuadores/DcMotor";
import DcMotorx2 from "./Actuadores/DcMotorx2";
import ServoMotor from "./Actuadores/ServoMotor";
import Selenoide from "./Actuadores/Selenoide";

//LUMINOSOS
import RGB from "./Luminosos/RGB";
import Contador from "./Luminosos/Contador";
import DisplayIC2 from "./Luminosos/DisplayIC2";

//SENSORES
import LDR from "./Sensores/LDR";
import AHT10 from "./Sensores/AHT10";
import S_AHT20_BMP280 from "./Sensores/S_AHT20_BMP280";
import S_DC_INA219 from "./Sensores/S_DC_INA219";
import S_GY302 from "./Sensores/S_GY302";
import S_RGB_TCS34725 from "./Sensores/S_RGB_TCS34725";
import S_DS3231_RTC from "./Sensores/S_DS3231_RTC";


//PROGRAMABLES
import Arduino from "./Programables/Arduino";
import ZedBoard from "./Programables/ZedBoard";
import Esp32 from "./Programables/Esp32";
import RaspberryPi5 from "./Programables/RaspberryPi5"; 

//AUXILIAR
import T from "./Auxiliar/T";

export default {
  //ACTUADORES
  DcMotor: DcMotor,
  DcMotorx2: DcMotorx2,
  ServoMotor: ServoMotor,
  Selenoide: Selenoide,

  //LUMINOSOS
  RGB: RGB,
  Contador: Contador,
  DisplayIC2: DisplayIC2,

  //SENSORES
  LDR: LDR,
  AHT10: AHT10,
  S_AHT20_BMP280 : S_AHT20_BMP280,
  S_DC_INA219 : S_DC_INA219,
  S_GY302 : S_GY302, 
  S_RGB_TCS34725 : S_RGB_TCS34725,
  S_DS3231_RTC : S_DS3231_RTC,
  //PROGRAMABLES
  Arduino: Arduino,
  Esp32: Esp32,
  ZedBoard: ZedBoard,
  RaspberryPi5: RaspberryPi5,

  //AUXILIAR
  T: T,
};