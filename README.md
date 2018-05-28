# Lichtschalter

Im Prinzip ist das nichts anderes als eine Funkfernbedienung, getarnt als Lichtschalter.
Dieser kann ein 433Mhz Signal an eine Funksteckdose senden um diese An und Auszuschalten.

## allgemeine Funktionsweise

Jedes mal wenn der Taster betätigt wird, sendet der ATTiny ein Signal. 
Abwechselnd An und Aus. In der zwischenzeit schläft er um Strom zu sparen. 
Das Signal ist ein typisches 433Mhz Signal welches verwendet wird um Funksteckdosen 
An und Auszuschalten.

## Vorrausetzung

* ATTiny45
* 433Mhz sender
* Battery 3-5V
* Taster
* 220 Ohm Widerstand

## Projektablauf

Als erstes muss der Attiny mit dem Sourcecode geflash werden. Danach kann dieser verlötet und/ oder verbaut werden.

### ATTiny45 flashen

... mehr dazu unter [flash](https://github.com/bens-beacon/light-switch/tree/master/flash)

### Schaltplan

... mehr dazu unter [circuit_diagramms](https://github.com/bens-beacon/light-switch/tree/master/circuit_diagramms)
