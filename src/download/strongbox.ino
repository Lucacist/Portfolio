// Déclaration des fonctions
void mA1();
void mA2();
void mA3();
void mA4();
void mA5();
void nS1();
void nS2();
void nS3();
void nS4();
void nS5();
int chiffrer(long m, int e);
int cleAgent(String x);
int modexp(long a, int e, int n);

// Constantes pour les lettres et les numéros d'agent
String lettresAgent[] = {"A", "B", "C", "D", "E", "F", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q"};
int numerosAgent[] = {0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("Identifiez-vous:");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  String z;
  Serial.println("Donnez le modele de la carte (M01, MO2, ..., MO8):");
  while (Serial.available() == 0) {}
  z = Serial.readString();

  if (z == "MO1") {
    delay(2000);
    Serial.println("Vous avez choisi le modele " + z);
    delay(2000);
    nS1();
  } else if (z == "MO2") {
    delay(2000);
    Serial.println("Vous avez choisi le modele " + z);
    delay(2000);
    nS4();
  } else if (z == "MO3" || z == "MO4") {
    delay(2000);
    Serial.println("Vous avez choisi le modele " + z);
    delay(2000);
    nS2();
  } else if (z == "MO5" || z == "MO6") {
    delay(2000);
    Serial.println("Vous avez choisi le modele " + z);
    delay(2000);
    nS3();
  } else if (z == "MO8" || z == "MO7") {
    delay(2000);
    Serial.println("Vous avez choisi le modele " + z);
    delay(2000);
    nS5();
  } else {
    Serial.println("Modele de carte non valide.");
  }
}

void mA1() {
  int reponses;
  Serial.println("Vous allez devoir repondre au QCM suivant:");
  delay(2000);
  Serial.println("Quel agent devons-nous remplacer lors d'une mission prioritaire car il est malade?");
  delay(1000);
  Serial.println("1. Agent M");
  Serial.println("2. Agent R");
  Serial.println("3. Arnold");
  while (Serial.available() == 0) {}
  reponses = Serial.parseInt();
  
  if (reponses == 1) {
    delay(1000);
    Serial.println("Bonne reponse.");
    delay(1000);
    Serial.println("Qui avons-nous du remplacer lors de ses vacances?");
    delay(1000);
    Serial.println("1. Arnold");
    Serial.println("2. Agent M");
    Serial.println("3. Arnold M");
    while (Serial.available() == 0) {}
    reponses = Serial.parseInt();
    
    if (reponses == 2) {
      delay(1000);
      Serial.println("Bonne reponse.");
      delay(1000);
      Serial.println("A qui appartenait l'artefact?");
      delay(1000);
      Serial.println("1. Arnold");
      Serial.println("2. Vincent");
      Serial.println("3. Agent M");
      while (Serial.available() == 0) {}
      reponses = Serial.parseInt();
      
      if (reponses == 2) {
        // Autre action
      } else {
        delay(1000);
        Serial.println("Erreur d'authentification, le systeme est bloque.");
        digitalWrite(3, HIGH);
        while (1) {}
      }
    } else {
      delay(1000);
      Serial.println("Erreur d'authentification, le systeme est bloque.");
      digitalWrite(3, HIGH);
      while (1) {}
    }
  } else {
    delay(1000);
    Serial.println("Erreur d'authentification, le systeme est bloque.");
    digitalWrite(3, HIGH);
    while (1) {}
  }
}

void mA2() {
  Serial.println("Identifiez-vous:");
  
  while (Serial.available() == 0) {}
  
  if (Serial.available() > 0) {
    char x = Serial.read();
    String xString = String(x);
    xString.toUpperCase();
  
    if (xString >= "A" && xString <= "Q") {
      long m = random(2881L);
      int e = cleAgent(xString);
      int c = chiffrer(m, e);
      
      Serial.print("message à dechiffrer : ");
      Serial.println(c);
      Serial.println("Attendez la saisie de Mp");
      
      while (Serial.available() == 0) {}
      int mp = Serial.parseInt();
      
      if (m == mp) {
        // Authentification réussie, autre action
      } else {
        Serial.println("Erreur d'authentification, le systeme est bloque.");
        digitalWrite(3, HIGH);
        while (1) {}
      }
    } else {
      Serial.println("Caractère invalide. Entrez une lettre de A à Q.");
      Serial.println("Erreur d'authentification, le systeme est bloque.");
      digitalWrite(3, HIGH); 
      while (1) {}
    }
  }
}

void mA3() {
  bool oeil;
  Serial.println("Placez votre oeil correctement (t ou f) :");
  while (Serial.available() == 0) {}
  oeil = Serial.read() == 't';
  if (oeil == true) {
    // Autre action
  } else {
    Serial.println("L'oeil n'a pas ete reconnu, le systeme est bloque.");
    digitalWrite(3, HIGH);
    while (1) {}
  }
}

void mA4() {
  bool empreinte;
  Serial.println("Placez votre doigt correctement sur le dispositif de scan (true ou false) :");
  while (Serial.available() == 0) {}
  empreinte = Serial.read() == 't';
  if (empreinte == true) {
    // Autre action
  } else {
    Serial.println("Empreinte non reconnue, le systeme est bloque.");
    digitalWrite(3, HIGH);
    while (1) {}
  }
}

void mA5() {
  Serial.println("Entrez votre lettre d'agent (A, B, C, ..., P, Q) :");
  while (Serial.available() == 0) {}
  String lettreAgent = Serial.readString();

  for (int i = 0; i < sizeof(lettresAgent) / sizeof(lettresAgent[0]); i++) {
    if (lettreAgent == lettresAgent[i]) {
      Serial.println("Entrez votre numero d'agent :");
      while (Serial.available() == 0) {}
      int numeroAgent = Serial.parseInt();

      if (numeroAgent == numerosAgent[i]) {
        // Authentification réussie, autre action
      } else {
        Serial.println("Attention : Tentative d'intrusion.");
      }
      break;
    } 
    else if (i == sizeof(lettresAgent) / sizeof(lettresAgent[0]) - 1) {
      Serial.println("Lettre d'agent invalide.");
      digitalWrite(3, HIGH);
    }
  }
}

void nS1() {
  mA1();
  delay(2000);
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000);
  mA3();
  delay(2000);
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH);
  while (1) {}
}

void nS2() {
  mA1();
  delay(2000);
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000);
  mA4();
  delay(2000);
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH);
  while (1) {}
}

void nS3() {                                                                                            
  mA5();
  delay(2000);
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000);                                                                                                              //....//
  mA2();
  delay(2000);
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH);
  while (1) {}
}

void nS4() {
  mA2();
  delay(2000);
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000);
  mA3();
  delay(2000);
  Serial.println("Bravo, vous avez passe la deuxieme securite du coffre.");
  delay(2000);
  mA4();
  delay(2000);
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH);
  while (1) {}
}

void nS5() {
  mA1();
  delay(2000);
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000);
  mA2();
  delay(2000);
  Serial.println("Bravo, vous avez passe la deuxieme securite du coffre.");
  delay(2000);                                                                                                                    //....//
  mA3();
  delay(2000);
  Serial.println("Bravo, vous avez passe la troisieme securite du coffre.");
  delay(2000);
  mA5();
  delay(2000);
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH);
  while (1) {}
}

int chiffrer(long m, int e) {
  int n = 43 * 67;
  int c = modexp(m, e, n);
  return c;
}

int cleAgent(String x) {
  int e;

  if (x == "A") {
    e = 601;
  } else if (x == "B") {
    e = 619;
  } else if (x == "C") {
    e = 631;
  } else if (x == "D") {
    e = 641;
  } else if (x == "E") {
    e = 647;
  } else if (x == "F") {
    e = 653;
  } else if (x == "H") {
    e = 661;
  } else if (x == "I") {
    e = 673;
  } else if (x == "J") {
    e = 691;
  } else if (x == "K") {
    e = 701;
  } else if (x == "L") {
    e = 733;
  } else if (x == "M") {
    e = 739;
  } else if (x == "N") {
    e = 751;
  } else if (x == "O") {
    e = 797;
  } else if (x == "P") {
    e = 809;
  } else if (x == "Q") {
    e = 811;
  }

  return e;
}

int modexp(long a, int e, int n) {
  int r;

  if (e < 0) {
    Serial.println("Cas non géré");
    exit(-1);
  }
  if (a == 0 || n == 1) {
    r = 0;
  } else {
    r = 1;
    while (e > 0) {
      r = (r * (a % n)) % n;
      e = e - 1;
    }
  }

  return r;
}