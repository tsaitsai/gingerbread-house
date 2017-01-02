/* Eric Tsai, github.com/tsaitsai
 * gingerbread house, 2016 Dec 31
 * remember to modify ssid and passcode for wifi
 * and mqtt broker IP address
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


/* PIN OUT
Snowman = GPIO2 / D4
Roof Light = GPIO5 / D1
Tree light=  GPIO15/D8
Door Servo = GPIO13 / D7
*/

// Neopixel WS2812
#define PINSNOWMAN           2    //GPIO2 = D4

#define PINROOF        5  //GPIO5 = D1
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      36   //snowman
#define NUMPIXELS_ROOF 8

Adafruit_NeoPixel snowman = Adafruit_NeoPixel(NUMPIXELS, PINSNOWMAN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel roof = Adafruit_NeoPixel(NUMPIXELS_ROOF, PINROOF, NEO_GRB + NEO_KHZ800);


#define PINS_TREE           15    //GPIO15 = D8
#define NUMPIXELS_TREE 		5
Adafruit_NeoPixel tree = Adafruit_NeoPixel(NUMPIXELS_TREE, PINS_TREE, NEO_GRB + NEO_KHZ800);

/*
#define PINS_REEF           4    //GPIO4 = D2
#define NUMPIXELS_REEF 		5
Adafruit_NeoPixel reef = Adafruit_NeoPixel(NUMPIXELS_REEF, PINS_REEF, NEO_GRB + NEO_KHZ800);
*/

int delayval = 10; // delay for half a second
int color = 0;  //red, green, blue
int brightness = 0;


//globals for managing color
int RGB_snow_red = 0;
int RGB_snow_green = 0;
int RGB_snow_blue = 0;
int RGB_tree_red = 0;
int RGB_tree_green = 0;
int RGB_tree_blue = 0;
int MQRGB_snow_red = 20;
int MQRGB_snow_green = 0;
int MQRGB_snow_blue = 0;
int MQRGB_tree_red = 0;
int MQRGB_tree_green = 0;
int MQRGB_tree_blue = 0;
int flag_snow_new = 0;

uint8_t snow_current_color_r = 0;
uint8_t snow_current_color_g = 0;
uint8_t snow_current_colorg_b = 0;

// Update these with values suitable for your network.
const char* ssid = "yourssid";
const char* password = "yourpassword";
const char* mqtt_server = "192.168.2.58";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

/*
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10 = 1;
static const uint8_t SDA = 4;
static const uint8_t SCL = 5;
static const uint8_t LED_BUILTIN = 16;
static const uint8_t BUILTIN_LED = 16;
 */





//servo pin
int servoFace = 13; //pin D7 = 13, gingerbread door servo



long servo_time = 0;
long time_snowman = 0;
long time_roof = 0;
long time_tree = 0;
int led_count_snowman = 0;
int led_count_snowman_max = 18;
int led_count_roof = 0;
int led_count_roof_max = 8;
int led_count_tree = 0;
int led_count_tree_max = 7;

//servo for front door
Servo myservo_face;
int myservo_face_pos = 0;
const int myservo_face_min = 50;    //opened door
const int myservo_face_max = 180;  //closed door
int myservo_face_target = 0;




//callback
bool flag_manual = 0;


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address is is: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();


    
  
  char message_buff[60]; //payload string
  // create string for payload
  int i=0;
  for(i=0; i<length; i++)
  {
    message_buff[i] = payload[i];
  }
  message_buff[i] = '\0';  //terminate buffer string class eol
  String msgString = String(message_buff);



  //LED color MQTT topics---------------------------------
  //-----------  MQTT Topic for Red RGB value "mq_snow_red" -----------------
  if (strcmp(topic,"mq_snow_red")==0)
  {
    MQRGB_snow_red = round(msgString.toInt());
    flag_snow_new = 1;
  }//end red


  //-----------  MQTT Topic for Red RGB value "mq_snow_green" -----------------
  if (strcmp(topic,"mq_snow_green")==0)
  {
    MQRGB_snow_green = round(msgString.toInt());
    flag_snow_new = 1;
  }//end green


  //-----------  MQTT Topic for Red RGB value "mq_snow_blue" -----------------
  if (strcmp(topic,"mq_snow_blue")==0)
  {
    MQRGB_snow_blue = round(msgString.toInt());
    flag_snow_new = 1;
  }//end blue



  //------  OpenHAB UI PB open request
  if (strcmp(topic,"req_door_open")==0)
  {
    Serial.println("openhab UI open request");
    myservo_face_target   = myservo_face_min;
    // snowman.Color takes RGB values, from 0,0,0 up to 255,255,255

    
    for (int i=0; i<24; i++)
    {
      snowman.setPixelColor(i, snowman.Color(0,0,30)); // Moderately bright green color.

      //snowman.show(); // This sends the updated pixel color to the hardware.
    }
    
    snowman.show(); // This sends the updated pixel color to the hardware.
    roof.setPixelColor(0, roof.Color(5,5,0)); // Moderately bright green color.
    roof.show(); // This sends the updated pixel color to the hardware.
    Serial.println("green");
    myservo_face.attach(servoFace);
  }//end if Openhab UI open request

  
  //------  OpenHAB UI PB close request
  if (strcmp(topic,"req_door_close")==0)
  {
    Serial.println("openhab UI close request");
      myservo_face_target   = myservo_face_max;
      // snowman.Color takes RGB values, from 0,0,0 up to 255,255,255

      
      for (int i=0; i<24; i++)
      {
        snowman.setPixelColor(i, snowman.Color(25,25,30)); // Moderately bright green color.

        //snowman.show(); // This sends the updated pixel color to the hardware.
      }
      snowman.show(); // This sends the updated pixel color to the hardware.
      
      
      roof.setPixelColor(0, roof.Color(0,5,5)); // Moderately bright green color.
      
      roof.show(); // This sends the updated pixel color to the hardware.
      Serial.println("green");

    myservo_face.attach(servoFace);
  }//end if Openhab UI close request


  if ( (strcmp(topic,"50C51C570B00")==0) || (strcmp(topic,"747E0C570B00")==0) || (strcmp(topic,"BE710C570B00")==0))
  {
    Serial.println("is 50C51C570B00 face");

    if  ((char)payload[0] == '1')
    {
      myservo_face_target   = myservo_face_max;
      // snowman.Color takes RGB values, from 0,0,0 up to 255,255,255

      
      for (int i=0; i<36; i++)
      {
        snowman.setPixelColor(i, snowman.Color(0,25,30)); // Moderately bright green color.

        //snowman.show(); // This sends the updated pixel color to the hardware.
      }
      snowman.show(); // This sends the updated pixel color to the hardware.
      
      
      roof.setPixelColor(0, roof.Color(0,2,0)); // Moderately bright green color.
      
      roof.show(); // This sends the updated pixel color to the hardware.
      Serial.println("green");
    }
    else
    {
      myservo_face_target  = myservo_face_min;
      // snowman.Color takes RGB values, from 0,0,0 up to 255,255,255

      
      for (int i=0; i<36; i++)
      {
        snowman.setPixelColor(i, snowman.Color(25,0,30)); // Moderately bright green color.
      }
      snowman.show(); // This sends the updated pixel color to the hardware.
      
      roof.setPixelColor(0, roof.Color(2,0,0)); // Moderately bright green color.
      roof.show(); // This sends the updated pixel color to the hardware.
      
      Serial.println("red");
    }
    myservo_face.attach(servoFace);
  }//end if face MAC address

  flag_manual = 1;




}//end call back

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    //if (client.connect(clientId.c_str())) {
    if (client.connect("memq")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe

      client.subscribe("BE710C570B00");   //BLE module MAC address
      client.subscribe("req_door_open");
      client.subscribe("req_door_close");
      
      client.subscribe("mq_snow_red");
      client.subscribe("mq_snow_green");
      client.subscribe("mq_snow_blue");

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);


  //servo
  myservo_face.attach(servoFace);


  snowman.begin(); // This initializes the NeoPixel library.
  roof.begin(); // This initializes the NeoPixel library.
  tree.begin();
}//end setup

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();


  //servo control
  if (now - servo_time > 90)
  {
    servo_time = now;

    
    if (myservo_face_pos < myservo_face_target - 6)     // 30 < 30 - 9
    {
      myservo_face_pos = myservo_face_pos + 5;
    }
    else if (myservo_face_pos > myservo_face_target + 6) // 20 > 15+9
    {
      myservo_face_pos = myservo_face_pos - 5;
    }
    //check max/min
    
    if (myservo_face_pos > myservo_face_max )
    {
      myservo_face_pos = myservo_face_max ;
    }
    else if (myservo_face_pos < myservo_face_min )
    {
      myservo_face_pos = myservo_face_min ;
    }
    
    //myservo_face.write(myservo_face_target);
    myservo_face.write(myservo_face_pos);

    if ( (myservo_face_pos < (myservo_face_target + 6)) && (myservo_face_pos > (myservo_face_target - 6)) )
    {
      myservo_face.detach();
    }

    
  }//end if servo_time


  //snow man LED
  if (now - time_snowman > 100)
  {
    time_snowman = now;

    switch (led_count_snowman) {
        case 1:
          snowman.setPixelColor(0, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(23, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 2:
          snowman.setPixelColor(1, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(22, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 3:
          snowman.setPixelColor(2, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(21, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 4:
          snowman.setPixelColor(3, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(20, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 5:
          snowman.setPixelColor(4, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(19, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 6:
          snowman.setPixelColor(5, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(18, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 7:
          snowman.setPixelColor(6, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(17, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 8:
          snowman.setPixelColor(7, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(16, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 9:
          snowman.setPixelColor(8, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(15, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 10:
          snowman.setPixelColor(9, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(14, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 11:
          snowman.setPixelColor(10, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(13, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 12:
          snowman.setPixelColor(11, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(12, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 13:
          snowman.setPixelColor(24, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(35, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 14:
          snowman.setPixelColor(25, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(34, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 15:
          snowman.setPixelColor(26, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(33, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 16:
          snowman.setPixelColor(27, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(32, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 17:
          snowman.setPixelColor(28, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(31, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        case 18:
          snowman.setPixelColor(29, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          snowman.setPixelColor(30, snowman.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
          break;
        default: 
          // if nothing else matches, do the default
          // default is optional
        break;
      }
    
    snowman.show();
    led_count_snowman = led_count_snowman + 1;
    if (led_count_snowman > 25)
    {
      led_count_snowman = 0;
      //for (int i=0; i<24; i++)
      for (int i=0; i<36; i++)
      {
        snowman.setPixelColor(i, snowman.Color(0,0,0)); // Moderately bright green color.
      }
      snowman.show();
    }
  }//end snowman


  //roof LED
  if (now - time_roof > 450)
  {
    time_roof = now;
    roof.setPixelColor(led_count_roof, roof.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
    roof.show();
    led_count_roof = led_count_roof + 1;
    if (led_count_roof > led_count_roof_max)
    {
      led_count_roof = 0;
      for (int i=0; i<led_count_roof_max; i++)
      {
        roof.setPixelColor(i, roof.Color(0,0,0)); // Moderately bright green color.
      }
      roof.show();
    }
  }//end roof LED

  //tree LED (inside the house)
  if (now - time_tree > 300)
  {
    time_tree = now;
    tree.setPixelColor(led_count_tree, tree.Color(MQRGB_snow_red,MQRGB_snow_green,MQRGB_snow_blue));
    tree.show();
    led_count_tree = led_count_tree + 1;
    if (led_count_tree > led_count_tree_max)
    {
      led_count_tree = 0;
      for (int i=0; i<led_count_tree_max; i++)
      {
        tree.setPixelColor(i, tree.Color(0,0,0)); // back to off
      }
      roof.show();
    }
  }//end tree LED

} //end loop
  

