#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char index_html[] PROGMEM = { 
  #include "www_h/index.html.h" 
  };
void handleRoot() { server.send(200, "text/html", index_html, sizeof(index_html)); }

const char style_css[] PROGMEM = { 
  #include "www_h/style.css.h" 
  };
void handleCSS() { server.send(200, "text/css", style_css, sizeof(style_css)); }

const char favicon_png[] PROGMEM = { 
  #include "www_h/favicon.png.h" 
  };
void handleFavicon() { server.send(200, "image/png", favicon_png, sizeof(favicon_png)); }

const char skunk_svg[] PROGMEM = { 
  #include "www_h/skunk.svg.h" 
  };
void handleSVGIcon() { server.send(200, "image/svg+xml", skunk_svg, sizeof(skunk_svg)); }

const char cache_manifest[] PROGMEM = { 
  #include "www_h/cache.manifest.h" 
  };
void handleCacheM() { server.send(200, "text/cache-manifest", cache_manifest, sizeof(cache_manifest)); }

void handleSensors() {
  server.send(
    200, "application/json", 
    String("{\"temperature\": ") + temperature + 
    ", \"pressure\": " + pressure + 
    ", \"humidity\": " + humidity + 
    ", \"uptime\": " + millis() + 
    ", \"voltage\": " + battery_voltage +
    ", \"pm25\": " + pm25 +
    "}");
}

void setup_web() {
  Serial.println("[www] Setting up endpoints...");
  server.on("/", handleRoot);
  server.on("/index.html", handleRoot);
  server.on("/style.css", handleCSS);
  server.on("/favicon.png", handleFavicon);
  server.on("/skunk.svg", handleSVGIcon);
  server.on("/cache.manifest", handleCacheM);
  server.on("/sensors/", handleSensors);
  server.begin();
  Serial.println("[www] Server running on port 80");
}