// #define CS_USE_NIMBLE
// To change the BLE device name modify the file:
// .\Arduino\libraries\Control_Surface\src\MIDI_Interfaces\BLEMIDI.hpp
// ( at line 22-> constexpr const char *BLE_MIDI_NAME = "Control Surface (BLE)"; )


#include <Arduino.h>
#include <BLEMidi.h>
#include <Control_Surface.h>
#include <MIDI_Interfaces/BluetoothMIDI_Interface.hpp>

// ---------------------------END -------------------- //

BluetoothMIDI_Interface MIDI_BLE;
HardwareSerialMIDI_Interface MIDI_SERIAL = Serial;
// USBMIDI_Interface midi_usb;

MIDI_PipeFactory<2> pipes;

void setup() {
  MIDI_BLE.ble_settings.initiate_security = true;
  MIDI_BLE.setName("MIDI Adapter");
  MIDI_BLE >> pipes >> MIDI_SERIAL;
  MIDI_BLE << pipes << MIDI_SERIAL;
  MIDI_SERIAL.begin();
  MIDI_BLE.begin();

  // appleMidi();
}

const MIDIAddress address{ MIDI_Notes::C[4], Channel_1 };
const uint8_t velocity = 0x7F;

// const bool testNotes = false;
// #define BOOT_BUTTON_PIN = 0;
void loop() {
  MIDI_BLE.update();
  MIDI_SERIAL.update();


  // if (testNotes) {
  //   MIDI_BLE.sendNoteOn(address, velocity);
  //   delay(200);
  //   MIDI_BLE.sendNoteOff(address, velocity);
  //   delay(500);
  // }
}
