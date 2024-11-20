#include <Arduino.h>
#include <init.h>
#include <arduino_secrets.h>
#include <WiFi.h>
#include "esp_wpa2.h"  
#include <board_mapping.h>

#define LED_BUILTIN 13

#define RxU1 17 // Rx UART1
#define TxU1 18 // Tx UART1
#define B01 8
#define B02 7
#define B03 6
#define B04 5
#define B05 4

// Fonction d'initialisation des GPIO
int initialisationBroches(void)
{
    // Configuration des broches
    // pinMode(GPIO_B1, INPUT); // Exemple
    //pinMode(LED_BUILTIN, OUTPUT);
    //digitalWrite(LED_BUILTIN, LOW);
    pinMode(B01, INPUT);
    pinMode(B02, INPUT);
    pinMode(B03, INPUT);
    pinMode(B04, INPUT);
    pinMode(B05, INPUT);

    

  return 0;
}

// Fonction d'initialisation de l'UART
int initialisationSerie(void)
{
  //Serial.setPins(GPIO_UART_TX, GPIO_UART_RX);
  Serial.begin(115200);
  printf("\r\n\r\nPort serie 115200\r\n");
  return 0;
}

// Fonction d'initialisation du Wifi
int initialisationWifi(void)
{
   // Connexion au réseau wifi sécurisé avec identifiant et mot de passe
  WiFi.begin(SECRET_SSID, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);

  // Attendre la connexion au réseau wifi
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(SECRET_SSID); // print the network name (SSID)
    delay(2000);
  }

  // Afficher les informations de connexion
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
  Serial.print("SSID : ");
  Serial.println(WiFi.SSID());
  return 0;
}