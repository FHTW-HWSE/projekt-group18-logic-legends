# projekt-group18-logic-legends
projekt-group18-logic-legends created by GitHub Classroom

### Projektbeteiligte: Wen Ting Xu, Yasar Sert, Jakob Gridl, Samuel Bißmann

***Projektbeschreibung:***

HWSE Projekt
Dieses Programm ist ein Patientenmanagementsystem für eine Notaufnahme in einem Krankenhaus. 
Es priorisiert Patienten basierend auf der Art ihrer Ankunft und weist ihnen Sitzplätze zu, um die Nachverfolgung von Sitznachbarn zu ermöglichen. 
Das Programm kann folgende Aufgaben ausführen:
- Hinzufügen von Patienten, die selbstständig in die Notaufnahme gekommen sind.
- Hinzufügen von Patienten, die durch einen Krankenwagen in die Notaufnahme gekommen sind.
- Entfernen eines Patienten durch eine erfolgreiche Behandlung. Dies muss nach der definierten Priorisierung erfolgen.
- Nachträgliches Abfragen, welche Sitzpartner ein Patient hat. Sollte kein Sitzplatz zugewiesen worden sein, sind keine Sitzpartner zurück zu geben.
- Das Programm verfügt über ein User Interface für die einfache Verwaltung von Patienten und Sitzplätzen. Es gibt 25 Sitzplätze in einem 5x5 Muster, und zwischen den Sitzreihen ist genug Platz, um eine Nachverfolgung von Sitznachbarn zu vermeiden.
**Status**
Das System kann sich in folgenden Status befinden:
Hauptmenü - Wartet auf Eingabe
Regulärer Patient einfügen - Ein regulärer Patient wird in die Warteschlange eingefügt
Priorität Patient einfügen - Ein Priorität Patient wird in die Warteschlange eingefügt
Patient aufrufen - Der erste Patient in der Warteschlange wird angezeigt und entfernt
Sitznachbarn ausgeben - Die Sitznachbarn eines Patienten werden ausgegeben

## User Stories
### User Story 1: Regulären Patienten Sitzplatz zuweisen
Als Portier*in des Krankenhauses möchte ich Patienten, die selbst kommen in die Warteschlange aufnehmen können, damit sie einen Sitzplatz zugewiesen bekommen.

**Requirements:**

- Patient kann über eine Eingabemaske in die Warteschlange aufgenommen werden (System wechselt in den Status “Regulärer Patient einfügen”)
- Wenn der Patient erfolgreich in die Warteschlange aufgenommen wurde, wird eine Sitzplatznummer vom System ausgegeben
- Nach erfolgreicher Ausgabe eines Sitzplatzes wartet das System auf neue Eingabe

**Akzeptanzkriterien:**

- Given: das System befindet sich im Hauptmenü und wartet auf eine Eingabe <br/>
  When: der User gibt den Befehl, Patienten in die Warteschlange hinzuzufügen, ein <br/>
  Then: der Patient wird zur Warteschlange hinzugefügt <br/>
- Given: ein Patient wird in die Warteschlange hinzugefügt <br/>
  When: der Patient wird erfolgreich in die Warteschlange aufgenommen <br/>
  Then: eine Sitzplatznummer wird vom System ausgegeben <br/>
- Given: ein Patient wird in die Warteschlange hinzugefügt <br/>
  When: der Patient kann nicht in die Warteschlange hinzugefügt werden <br/>
  Then: eine Fehlermeldung wird ausgegeben <br/>
- Given: ein Patient soll zur Warteschlange hinzugefügt werden <br/>
  When: der Patient wurde zur Warteschlange hinzugefügt oder eine Fehlermeldung wurde ausgegeben <br/>
  Then: das System kehrt in das Hauptmenü zurück <br/>

### User Story 2: Patient mit Priorität hinzufügen
Als Portier*in des Krankenhauses möchte ich einen Patienten, der mit der Rettung kommt, in die Prioritätswarteschlange hinzufügen können, damit dieser vorgereiht aufgerufen werden kann.

**Requirements:**

Patient kann über die Eingabemaske in die Prioritätswarteschlange aufgenommen werden (System wechselt in den Status “Priorität Patient einfügen”)
Wenn der Patient erfolgreich in die Warteschlange aufgenommen wurde, wird KEINE Sitzplatznummer vom System ausgegeben, es wird lediglich eine Bestätigung ausgegeben, dass der Patient hinzugefügt wurde
Das System wartet nach erfolgreicher Ausgabe der Bestätigung auf neue Eingabe (System befindet sich im Status “Hauptmenü”)

**Akzeptanzkriterien:**

- Given: das System befindet sich im Hauptmenü und wartet auf eine Eingabe <br/>
When: der User gibt den Befehl ein, den Patienten mit Priorität in die Prioritätswarteschlange hinzufügen <br/>
Then: der Patient wird zur Prioritätswarteschlange hinzugefügt <br/>
- Given: ein Patient wird in die Prioritätswarteschlange hinzugefügt <br/>
When: der Patient wird erfolgreich in die Prioritätswarteschlange aufgenommen <br/>
Then: eine Erfolgsmeldung aber keine Sitzplatznummer wird ausgegeben <br/>
- Given: ein Patient wird in die Prioritätswarteschlange hinzugefügt <br/>
When: der Patient wird nicht erfolgreich in die Prioritätswarteschlange aufgenommen <br/>
Then: eine Fehlermeldung wird ausgegeben <br/>
- Given: ein Patient soll zur Prioritätswarteschlange hinzugefügt werden <br/>
When: eine Erfolgs- oder Fehlermeldung wurde ausgegeben <br/>
Then: das System kehrt in das Hauptmenü zurück <br/>

### User Story 3: Patient aufrufen
Als Ärztin/Arzt möchte ich  im User Interface sehen, wer als nächstes an der Reihe ist, um die Person aufrufen und aus der Warteschlange entfernen zu können.

Requirements:
Nach Eingabe des Befehls zum Aufrufen eines Patienten wird dessen Name im User Interface hervorgehoben angezeigt und er wird aus der Warteschlange entfernt (System wechselt in den Status “Patient aufrufen”)
Die Daten des aufgerufenen Patienten (Name, Zeitraum des Aufenthalts und Sitznachbarn) werden in einem File gespeichert.
Der Patient befindet sich nach dem entfernen nicht mehr in der Warteschlange, der nächste Patient wird nun stattdessen im User Interface angezeigt (System befindet sich im Status “Hauptmenü”)

Akzeptanzkriterien:
Given: das System befindet sich im Hauptmenü und wartet auf eine Eingabe
When: der User gibt den Befehl ein, den nächsten Patienten aufzurufen
Then: der Name des nächsten Patienten wird hervorgehoben im User Interface angezeigt und der Patient wird aus der Warteschlange entfernt und befindet sich nicht länger in der Warteschlange
Given: ein Patient wird aufgerufen
When: der Patient wurde erfolgreich aus der Warteschlange entfernt
Then: das System kehrt in den Status “Hauptmenü” zurück und der nächste Patient wird im User Interface angezeigt, außerdem werden die Daten des entfernten Patienten in einem File gespeichert

### User Story 4: Sitznachbarn ermitteln
Als Beauftragter für ansteckende Krankheiten möchte ich mir die Namen aller Sitznachbarn eines Patienten ausgeben lassen können, um ein Contact-Tracing zu ermöglichen.

Requirements:
Nach Eingabe des Befehls zum Ausgeben der Sitznachbarn und des Namen des betreffenden Patienten soll eine Liste mit den Namen der Sitznachbarn ausgegeben werden. (System wechselt in den Status “Sitznachbarn ausgeben”)
Die Daten der Patienten wurden in einem File gespeichert, dass zum ermitteln der Sitznachbarn ausgelesen wird
Wurde dem Patienten kein Sitzplatz zugeordnet (Priorität Patienten) werden keine Sitznachbaren ausgegeben
Nach erfolgreicher Ausgabe wartet das System auf eine neue Eingabe (System befindet sich im Status “Hauptmenü”)

Akzeptanzkriterien:
Given: das System befindet sich im Hauptmenü
When: der Befehl für das Ausgeben der Sitznachbarn wird eingegeben
Then: eine Eingabeaufforderung fragt nach dem Namen des Betroffenen
Given: das System fragt nach dem Namen des gewünschten Patienten
When: es wird ein korrekter Name eingegeben
Then: das System gibt eine Liste mit den Namen der Personen aus, neben denen der Betroffene gesessen ist
Given: das System fragt nach dem Namen des gewünschten Patienten
When: es wird ein ungültiger Name eingegeben oder dem Patienten wurde kein Sitzplatz zugewiesen
Then: eine Fehlermeldung wird ausgegeben
Given: es wurde nach den Sitznachbarn eines Patienten gefragt
When: es wurde erfolgreich eine Liste mit Namen oder eine Fehlermeldung ausgegeben
Then: das System kehrt wieder in den Status “Hauptmenü” zurück


## Requirements
### Funktionale Requirements
- Es muss ein User Interface implementiert werden.
- Ein Patient kann über die Eingabemaske in die Warteschlange aufgenommen werden.
- Wenn der Patient erfolgreich in die Warteschlange aufgenommen wurde, wird eine Sitzplatznummer vom System ausgegeben.
- Nach erfolgreicher Ausgabe eines Sitzplatzes wartet das System auf eine neue Eingabe.
- Ein Patient kann über die Eingabemaske in die Prioritätswarteschlange aufgenommen werden.
- Wenn der Patient erfolgreich in die Prioritätswarteschlange aufgenommen wurde, wird KEINE Sitzplatznummer vom System ausgegeben, es wird lediglich eine Bestätigung ausgegeben, dass der Patient hinzugefügt wurde.
- Das System wartet nach erfolgreicher Ausgabe der Bestätigung, dass der Patient in die Prioritätswarteschlange hinzugefügt wurde, auf neue Eingabe
- Nach Eingabe des Befehls zum Aufrufen eines Patienten wird dessen Name im User Interface hervorgehoben angezeigt und er wird aus der Warteschlange entfernt.
- Die Daten des aufgerufenen Patienten (Name, Zeitraum des Aufenthalts und Sitznachbarn) werden in einem File gespeichert.
- Der Patient befindet sich nach dem Entfernen nicht mehr in der Warteschlange, der nächste Patient wird nun stattdessen im User Interface angezeigt.
- Nach Eingabe des Befehls zum Ausgeben der Sitznachbarn und des Namen des betreffenden Patienten soll eine Liste mit den Namen der Sitznachbarn ausgegeben werden.
- Wurde dem Patienten kein Sitzplatz zugeordnet (Priorität Patienten), werden keine Sitznachbaren ausgegeben.
- Nach erfolgreicher Ausgabe der Sitznachbarn wartet das System auf eine neue Eingabe

### Nicht-Funktionale Requirements
- Das System soll Antworten in Echtzeit liefern.
- Es soll ein intuitives User-Interface bereitgestellt werden.
- Der Benutzer soll durch Eingabe von Befehlen zur gewünschten Seite navigieren können.
- Unplausible Eingaben rufen einen Fehler hervor.
- Nach Eingabe eines Befehls wird die Historie des Terminals gelöscht, sodass immer nur das Resultat des letzten Befehls sichtbar ist.

### Constraints
- Abgabe der Requirements bis zum 28.03
- Das Projekt darf nur in C geschrieben werden
- Die Projektabgabe erfolgt bis zum 13.06
- Das Projekt muss mit Hilfe von GitHub bearbeitet werden.
- Die Projektarbeit kann nicht frei gewählt werden
- Als Build System soll Cmake verwendet werden



