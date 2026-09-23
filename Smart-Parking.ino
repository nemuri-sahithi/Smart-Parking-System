#include <LiquidCrystal.h>

// Initialize LCD with pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define Pins for Ultrasonic Sensors
// You can use the same pin for Trig and Echo if using the 3-pin sensor in Tinkercad
// Or separate pins if using the 4-pin HC-SR04. Here we define separate for clarity
// but use the same number to save pins if you wire them together or use the 3-pin lib logic.
// For standard 4-pin HC-SR04, connect Trig and Echo to these Digital Pins:
const int slot1Pin = 8; 
const int slot2Pin = 9; 
const int slot3Pin = 10;

long duration;
int distance;
int freeSlots = 3;

void setup() {
  lcd.begin(16, 2); // Start LCD
  lcd.print("Smart Parking");
  delay(2000);
  lcd.clear();
}

long readDistance(int pin) {
  // Function to read distance from a 3-pin or 4-pin sensor setup on one digital pin
  // If using 4-pin sensor, connect BOTH Trig and Echo to the 'pin' defined above
  // OR update this code to use separate pins for Trig/Echo.
  
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pin, HIGH); // Send 10us pulse
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  
  pinMode(pin, INPUT);   // Read the echo
  return pulseIn(pin, HIGH);
}

void loop() {
  freeSlots = 3; // Reset count
  
  // --- Check Slot 1 ---
  long duration1 = readDistance(slot1Pin);
  int dist1 = duration1 * 0.034 / 2; // Convert to cm
  
  // --- Check Slot 2 ---
  long duration2 = readDistance(slot2Pin);
  int dist2 = duration2 * 0.034 / 2;
  
  // --- Check Slot 3 ---
  long duration3 = readDistance(slot3Pin);
  int dist3 = duration3 * 0.034 / 2;

  // Check occupancy (Threshold 100cm)
  bool s1_occupied = (dist1 < 100);
  bool s2_occupied = (dist2 < 100);
  bool s3_occupied = (dist3 < 100);

  // Calculate Free Slots
  if(s1_occupied) freeSlots--;
  if(s2_occupied) freeSlots--;
  if(s3_occupied) freeSlots--;

  // Display on LCD
  lcd.setCursor(0, 0);
  if(freeSlots == 0) {
    lcd.print("Parking Full!   ");
  } else {
    lcd.print("Free Slots: ");
    lcd.print(freeSlots);
    lcd.print("   "); // Clear trailing characters
  }

  // Optional: Show specific slot status on bottom row
  lcd.setCursor(0, 1);
  lcd.print(s1_occupied ? "S1:X " : "S1:O "); // X = Occupied, O = Open
  lcd.print(s2_occupied ? "S2:X " : "S2:O ");
  lcd.print(s3_occupied ? "S3:X " : "S3:O ");

  delay(500); // Update every half second
}
