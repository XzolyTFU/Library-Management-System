# Library System v2

## 1. Kompilieranweisungen

Dieses Projekt verwendet C++17. Zum Kompilieren und Ausführen kann das bereitgestellte Makefile verwendet werden.

### Schritte:

1. Projektverzeichnis öffnen:
cd library-system-v2

2. Kompilieren:
make

3. Programm ausführen:
make run

4. Objektdateien und Binärdateien löschen:
make clean

---

## 2. Unterschiede zu Aufgabenblatt 4a

- Smart Pointer: Alle Medienobjekte werden jetzt mit std::unique_ptr oder std::shared_ptr verwaltet. Alte Rohpointer (new/delete) wurden entfernt.
- Library: Nutzt std::vector<std::unique_ptr<Media>> statt eines dynamischen Arrays Media**. Destruktor muss keine Objekte mehr löschen.
- Hilfsfunktionen: createBook, createDVD, createMagazine und createReferenceBook verwenden std::make_unique statt new.
- Playlists: DVDs werden mit std::shared_ptr gespeichert, sodass mehrere Playlists dieselbe DVD referenzieren können.
- Author-Book: Bidirektionale Beziehung implementiert mit std::shared_ptr (Author → Book) und std::weak_ptr (Book → Author), wodurch zyklische Referenzen vermieden werden.
- MediaCollection & RAII: Move-Semantik unterstützt, Copy-Konstruktoren gelöscht. ScopedLogger verwendet RAII zum automatischen Logging.

---

## 3. Beantwortung aller “Beantworten Sie schriftlich”-Fragen

### Aufgabe 1 – Library mit unique_ptr

- Warum braucht der Destruktor keinen Code mehr?  
  Der std::vector<std::unique_ptr<Media>> löscht die enthaltenen Objekte automatisch, sobald der Vector zerstört wird. Daher muss man keine manuelle Speicherfreigabe mehr durchführen.

- Was passiert, wenn man versucht unique_ptr zu kopieren?  
  unique_ptr ist nicht kopierbar, da es exklusiven Besitz repräsentiert. Ein Kopierversuch führt zu einem Kompilierfehler. Besitz muss per std::move übertragen werden.

- Warum verwendet man std::make_unique statt new?  
  std::make_unique ist sicherer, weniger fehleranfällig und verhindert Speicherlecks, weil das Objekt sofort in einen unique_ptr eingebunden wird.

### Aufgabe 2 – Shared Ownership mit shared_ptr

- Wann verwendet man shared_ptr statt unique_ptr?  
  Wenn mehrere Objekte denselben Besitz an einem dynamischen Objekt teilen sollen und es erst gelöscht wird, wenn alle Besitzer verschwunden sind.

- Was ist der Overhead von shared_ptr?  
  shared_ptr verwendet eine Referenzzählung, die zusätzlichen Speicher und minimale Rechenzeit beim Kopieren oder Zerstören kostet.

- Was passiert bei zyklischen Referenzen?  
  Bei reinem shared_ptr kann eine zyklische Referenz zu Speicherlecks führen, da die Referenzzählung nie 0 wird. Daher wird in solchen Fällen weak_ptr verwendet.

### Aufgabe 3 – Weak Pointer

- Warum verwendet man weak_ptr statt shared_ptr für die Rückrichtung?  
  Um zyklische Referenzen zu verhindern. weak_ptr hält keine Besitzrechte, verhindert also Memory Leaks.

- Wie prüft man, ob ein weak_ptr noch gültig ist?  
  Mit der Methode expired(). Gibt true zurück, wenn das referenzierte Objekt bereits zerstört wurde.

- Was macht lock()?  
  lock() gibt einen shared_ptr zurück, wenn das Objekt noch existiert. Ist es zerstört, liefert lock() einen null shared_ptr.

### Aufgabe 4 – Move-Semantik und RAII

- Was ist der Unterschied zwischen Move und Copy?  
  Copy erstellt eine neue Kopie der Ressourcen, Move überträgt die Ressourcen auf ein anderes Objekt und hinterlässt das Quellobjekt in einem leeren, gültigen Zustand.

- Was bedeutet “moved-from state”?  
  Das Objekt existiert weiterhin, hat aber keine nutzbaren Ressourcen mehr. Es ist gültig, aber “leer”.

- Warum ist RAII wichtig für Exception Safety?  
  RAII stellt sicher, dass Ressourcen automatisch freigegeben werden, auch wenn eine Exception geworfen wird. Dadurch wird Speicherlecks und undefiniertes Verhalten vorgebeugt.
