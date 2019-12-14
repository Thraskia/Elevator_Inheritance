# Elevator_Inheritance
Τα αρχεία της άσκησης είναι:
main.cpp
building.h
floor.h
groundfloor.h
entrancearea.h
office.h
elevator.h
pg.h
visitor.h

Οδηγίες μεταγλώττισης:
g++ main.cpp -o main

Οδηγίες εκτέλεσης:
./main

Χρησιμοποιούνται οι εξής δομές:
visitors[Κ]:Ένας πίνακας που περιέχει δείκτες σε
αντικείμενα της κλάσης Visitor
queueGF: Ουρά που περιέχει (δείκτες σε επισκέπτες)
τους επισκέπτες που βρίσκονται στο ισόγειο
queueELevator: Ουρά που περιέχει δείκτες στους
επισκέπτες που βρίσκονται στο ασανσέρ
queueDeletedVisitors: Ουρά που περιέχει τους επισκέπτες
που θα βγουν από το κτήριο
qArea: Ουρά με τους επισκέπτες που βρίσκονται
στον χώρο εισόδου
queueInOffices: Oυρά με τους επισκέπτες που
βρίσκονται στα γραφεία.

main.cpp:

Tο project απαρτίζεται συνολικά από 9 αρχεία(ένα
.cpp αρχείο και 8 .h αρχεία).
Έχουν οριστεί οι εξής κλάσεις: Building, Elevator,
GroundFloor, Floor, Visitor, Office, EntranceArea, Queue and Node
Αρχικά, στην main παίρνουμε τα N,Nf,Ng,No,Nl,K,L από την
γραμμή εντολών και με την βοήθεια της atoi(<cstdlib>)
τα μετατρέπουμε αριθμούς

Στην συνέχεια αρχικοποιούμε τον counter: end=0, το end
μας δείχνει την θέση του τελευταίου
visitor(γνωρίζουμε σε ποιο visitor του πίνακα visitors
εχουμε σταματήσει - δηλαδή μέχρι ποιον visitor
έχουμε τοποθετήσει στο κτήριο).

Στη συνέχεια δημιουργούμε 1 Building και
δημιουργούμε δυναμικά 4 αντικείμενα της
κλάσης Floor, 4 αντικείμενα της κλάσης EntranceArea, 1
αντικείμενο της κλάσης GroundFloor, 1 αντικείμενο
της κλάσης Elevator. Τα οποία τα δημιουργούμε
ελέγχωντας ότι τα ορίσματα που μας δόθηκαν
από την γραμμή εντολών είναι ορθά. Σε
περίπτωση που δεν είναι σωστά τερματίζει το
πρόγραμμα επιστρέφοντας.

Ακολουθεί η δημιοιυργία Κ αντικειμένων
(Visitor*)που είναι δείκτες σε αντικείμενα της
κλάσης Visitor. Για κάθε τέτοιο αντικείμενο
δημιουργείται ένας τυχαίος αριθμός γραφείου
και ορόφου, αρχικοποιώντας κατάλληλα μέσω του
constructor αντίστοιχα τα μέλη του. Οι δείκτες που
δημιουργούνται και δείχνουν σε αντικείμενα
τύπου Visitor αποθηκεύονται σε ένα πίνακα
Κ-θέσεων τον visitors.

Συνεχίζουμε, ορίζοντας 2 ουρές την queueGF και την
queueElevator στην queueGF βάζουμε (δείκτες σε)
επισκέπτες που μπορούν να εισέλθουν στο
ισόγειο, ενώ στην queueElevator αυτούς που μπορούν
να εισέλθουν στο ασανσέρ.

Στη συνέχεια ξεκινάει η βασική λειτουργία του
προγραμματος. Το loop που έχουμε εκτελείται
L-φορες με βάση τους κύκλους λειτουργίας του
ασανσέρ, το αν υπάρχουν επισκέπτες στον
πίνακα και όσο το κτήριο χωράει επισκέπτες:
1) Ελέγχουμε αν οι επισκέπτες μπορούν να μπουν
στο κτήριο και στη συνέχεια στο ισόγειο, αν
μπουν τους βάζουμε στην ουρά του ισογείου,
εκτελείται η wait και τους δίνει αριθμό
προτεραιότητας ενώ επίσης αυξάνουμε τον counter
end. ΤΟ count χρησιμοποιεαι για τον ίδιο σκοπό.
2) Ελέγχουμε αν οι επισκέπτες που είναι στο
ισόγειο μπορούν να μπουν στο ασανσερ, αν
μπορούν τους αφαιρούμε από την ουρά του
ισογείου και τους προσθέτουμε στην ουρά του
ασανσερ.
3) Ταξινομούμε στην ουρά του ασανσέρ με βάση
τον όροφο που πηγαίνει ο κάθε επισκέπτης, έτσι
στην αρχή είναι αυτοί που πηγαίνουν στον 1ο,
στη συνέχεια αυτοί που πηγαίνουν στον 3 κοκ.
4) Τέλος ξεκινάει η λειτουργία του ασανσέρ,
όπως αυτή θα περιγραφεί παρακάτω.

Elevator.h:

Περιέχει την κλάση Elevator. H κλάση αυτή
αποτελείται από την χωρητικότητα του
ασανσέρ(Nl), τον τρέχον αριθμό επισκεπτών του
ασανσέρ και τον αριθμό του επισκέπτη που
ελέγχουμε.

Ο constructor αρχικοποιεί το Nl,το no_visitors εκτυπώνει
ένα μήνυμα.

Υπάρχουν συναρτήσεις που επιστρέφουν τα data
members και που αυξομειώνουν τα data members.

Η Enter ελέγχει αν ο επισκέπτης μπορεί να μπει
στο ασανσέρ και αν μπορεί αυξάνει το no_visitors,
εκτυπώνει μήνυμα και επιστρέφει 1 αλλιώς
επιστρέφει 0

Η Stop_Up ελέγχει αν χωράνε επισκέπτες στον όροφο
και εφόσον υπάρχουν επισκέπτες στο ασανσερ
που πηγαίνουν στον όροφο, ελέγχει το γραφείο
στο οποίο πηγαίνουν και αν χωράνε σ'αυτό τους
προσθέτει στην ουρά των γραφείων και τους
αφαιρεί από την ουρά του ασανσέρ. Αλλιώς
ελέγχει αν υπάρχει χώρος στον χώρο εισόδου
και τους τοποθετεί στην ουρά του χώρου
εισόδου(qArea) και τους αφαιρεί από την ουρά του
ασανσερ, αν δεν υπάρχει παραμένουν στο
ασανσερ. Αν δεν υπάρχουν επισκέπτες που να
πηγαίνουν στον όροφο, η συνάρτηση επιστρέφει.

Η Stop_Down παίρνει τους επισκέπτες από την λίστα
των γραφείων(οι οποίοι είναι τυχαία
τοποθετημένοι) και αν υπάρχει χώρος στο
ασανσερ τους αφαιρεί από την λίστα των
γραφείων, μειώνει τον counter του ορόφου και του
γραφείου, αυξάνει τον counter του ασανσέρ και τον
τοποθετεί στην ουρά του ασανσερ queueDeletedVisitors.
Επιπλέον, παίρνει επισκέπτες από τον χώρο
εισόδου και τους τοποθετεί στα γραφεία(αν
χωράνε και αν υπάρχουν).

Η Empty_All εκτελείται όταν το ασανσερ έχει φτάσει
στο ισόγειο, βγάζει τους επισκέπτες από το
κτήριο αφαιρώντας τους από την ουρά
queueDeletedVisitors, εκτυπώνοντας τα ανάλογα μηνύματα
και επιστρέφει τον αριθμό των επισκεπτών που
έβγαλε από το κτήριο για να μειώσουμε ανάλογα
τον counter(no_visitors) του Building.

Τέλος υπάρχει ο destructor που εμφανίζει μήνυμα
όταν καταστραφεί το ασανσέρ. 

Building.h:

Περιέχει την κλάση Building. Η κλάση αυτή
αποτελείται από 4δείκτες σε αντικείμενα της
κλάσης Floor, από την χωρητικότητα του κτηρίο(N),
τον τρέχον αριθμό επισκεπτών του κτηρίου, 1
δείκτη σε αντικείμενο της κλάσης GroundFloor και 1
δείκτη σε αντικείμενο της κλάσης Elevator.

Ο constructor αρχικοποιεί το N,το no_visitors εκτυπώνει
ένα μήνυμα.

ΈΧει συναρτήσεις που αυξομειώνουν τα data members
και που τα αρχικοποιούν.

Η Enter έλέγχει αν μπορεί ένας επισκέπτης να
εισέλθει στο κτήριο και κατ'επέκταση στο
ισόγειο, αυξάνοντας τους counters και
εκτυπώνοντας το κατάλληλο μήνυμα.

Η ElevatorOperate περιέχει την εκτέλεση της
λειτουργίας του ασανσερ σε 1 κύκλο
λειτουργίας του.

Τέλος, ο destructor που εμφανίζει μήνυμα οταν
καταστραφεί το κτήριο.

entrancearea.h:

Περιέχει την κλάση EntranceArea. Η κλάση αυτή
αποτελείται από την χωρητικότητα του χώρου
εισόδου(Nl), τον τρέχον αριθμό επισκεπτών του
και μία ουρά που περιέχει του επισκέπτες που
βρίσκονται στο χώρο εισόδου.

Ο constructor αρχικοποιεί το Nl,το no_visitors εκτυπώνει
ένα μήνυμα.

Η Enter έλέγχει αν μπορεί ένας επισκέπτης να
εισέλθει στον χώρο εισόδου, αυξάνοντας τους
counters και εκτυπώνοντας το κατάλληλο μήνυμα.

ΈΧει συναρτήσεις που αυξομειώνουν τα data members
και που τα αρχικοποιούν.

Τέλος, ο destructor που εμφανίζει μήνυμα οταν
καταστραφεί ένας χώρος εισόδου.

floor.h:

Περιέχει την κλάση Floor. Η κλάση αυτή
αποτελείται από την χωρητικότητα του
ορόφου(Nf), έναν αύξοντα αριθμό ορόφου, τον
τρέχον αριθμό επισκεπτών του,μία ουρά που
περιέχει του επισκέπτες που βρίσκονται στα
γραφεία, ένα δείκτη σε χώρο εισόδου και ένα
πίνακα με δείκτες σε γραφεία.

Ο constructor αρχικοποιεί το Nl,το no_visitors εκτυπώνει
ένα μήνυμα.

Η Enter έλέγχει αν μπορεί ένας επισκέπτης να
εισέλθει στον όροφο, αυξάνοντας τους counters και
εκτυπώνοντας το κατάλληλο μήνυμα.

ΈΧει συναρτήσεις που αυξομειώνουν τα data members
και που τα αρχικοποιούν.

Τέλος, ο destructor που εμφανίζει μήνυμα οταν
καταστραφεί ένας όροφος

groundfloor.h:

Περιέχει την κλάση GroundFloor. Η κλάση αυτή
αποτελείται από την χωρητικότητα του
iσογείου(Nγ),τον τρέχον αριθμό επισκεπτών του
και το waiting number.

Ο constructor αρχικοποιεί το Ng,το no_visitors, το waiting_number
και εκτυπώνει ένα μήνυμα.

Η Enter έλέγχει αν μπορεί ένας επισκέπτης να
εισέλθει στο ισόγειο, αυξάνοντας τους counters
και εκτυπώνοντας το κατάλληλο μήνυμα.

ΈΧει συναρτήσεις που αυξομειώνουν τα data members
και που τα αρχικοποιούν.

Η Wait δίνει αριθμό προτεραιότητας στον
επισκέπτη, εκτυπώνει μήνυμα και επιστρέφει
τον αριθμό προτεραιότητας.

Τέλος, ο destructor που εμφανίζει μήνυμα οταν
καταστραφεί το ισόγειο.

οffice.h:

Περιέχει την κλάση Office. Η κλάση αυτή
αποτελείται από την χωρητικότητα του
γραφείου(Nο),τον τρέχον αριθμό επισκεπτών του
και τον αριθμό του γραφείου(αναγνωριστικό
γραφείου office_number)

Ο constructor αρχικοποιεί το No,το no_visitors, το office_number
και εκτυπώνει ένα μήνυμα.

Η Enter έλέγχει αν μπορεί ένας επισκέπτης να
εισέλθει στο γραφείο, αυξάνοντας τους counters
και εκτυπώνοντας το κατάλληλο μήνυμα.

ΈΧει συναρτήσεις που αυξομειώνουν τα data members
και που τα επιστρέφουν.

Τέλος, ο destructor που εμφανίζει μήνυμα οταν
καταστραφεί ένα γραφείο.

visitor.h:

Περιέχει την κλάση Visitor. Η κλάση αυτή
αποτελείται από no_office(αριθμός του γραφείου
που πηγαίνει), no_floor(αριθμός του ορόφου που
πηγαίνει), priority_number(αριθμό προτεραιότητας)

Ο constructor αρχικοποιεί τα data members και εκτυπώνει
ένα μήνυμα.

ΈΧει συναρτήσεις που αυξομειώνουν τα data members
και που τα επιστρέφουν.

pg.h

Περιέχει το struct Νode και την κλάση Queue.
Υλοποιείται με λίστα. Έχει constructor που
αρχικοποιεί τους Node της ουράς καθώς και ένα
legth που κρατά το μέγεθος της ουράς.

Η returnData επιστρέφει δείκτη σε Visitor που είναι τα
περιεχόμενα(data) του κόμβου που βρίσκεται στην
θέση position της ουράς  

H Size επιστρέφει το μέγεθος της ουράς.

Η insert προσθέτει κόμβο στο τέλος της ουράς και
τον αρχικοποιεί με βάση αυτό που δέχεται.

Η Sort ταξινομεί την ουρά κατά αύξουσα σειρά και
με βάση τους ορόφους.

Η delet() διαγράφει τον 1ο κόμβο της ουράς ενώ η
specialDelete() διαγράφει τον κόμβο που βρίσκεται
στην θέση position της ουράς

Τέλος, η display() εκτυπώνει τα περιεχόμενα της
ουράς.
