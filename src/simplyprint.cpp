#include <Arduino.h>
#include <simplyprint.h>
#include <init.h>

#include <HTTPClient.h>
#include <ArduinoJson.h>

#include <arduino_secrets.h>

#define printer_id 18491
#define printer_name "Prusa i3 MK3 - Magasin P315"
#define printer_state "printing"

#define printer2_id 21937
#define printer2_name "Prusa i3 MK3 - P402"
#define printer2_state "paused"

int arreter_impression()
{
    return 0;
}

int ask_printer_name()
{
    HTTPClient http;

    // Spécification de l'URL
    http.begin("https://api.simplyprint.io/12305/printers/Get");

    // Ajout des headers
    http.addHeader("accept", "application/json");
    http.addHeader("X-API-KEY", API_KEY);

    // Envoyer la requête POST
    int httpResponseCode = http.POST("{}");

    // Vérifier la réponse
    if (httpResponseCode > 0)
    {
        String response = http.getString();
        // Serial.println("Réponse du serveur: " + response);

        // Parse de la réponse JSON
        const size_t capacity = 10 * JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(2) + 1024;
        DynamicJsonDocument doc(capacity);
        deserializeJson(doc, response);

        // Vérifier le statut
        if (doc["status"] == true)
        {
            JsonArray data = doc["data"];

            // Parcourir les objets dans "data"
            for (JsonObject printerObj : data)
            {
                const char *printerName = printerObj["printer"]["name"];
                const char *printerState = printerObj["printer"]["state"];
                int printerID = printerObj["id"];
                Serial.print("Nom de l'imprimante : ");
                Serial.print(printerName);
                Serial.print(" [");
                Serial.print(printerState);
                Serial.println("]");
                Serial.print(" [");
                Serial.print(printerID);
                Serial.println("]");
                //         if(printerObj["printer"]["name"] == printer_name){
                //           if(printerObj["printer"]["state"] == printer_state){
                //             digitalWrite(LED_BUILTIN, HIGH);
                //           } else {
                //             digitalWrite(LED_BUILTIN, LOW);
                //           }
                //         }
                if (printerObj["id"] == printer_id)
                {
                    if (printerObj["printer"]["state"] == printer_state)
                    {
                        //digitalWrite(LED_BUILTIN, HIGH);
                    }
                    else
                    {
                        //digitalWrite(LED_BUILTIN, LOW);
                    }
                }
            }
        }
        else
        {
            Serial.println("Erreur lors de la requête POST: " + String(httpResponseCode));
        }
    }
    return 0;
}