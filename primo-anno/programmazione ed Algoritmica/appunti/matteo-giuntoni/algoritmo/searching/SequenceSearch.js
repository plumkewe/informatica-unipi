// ----------- SEQUENCE-SEARCH -----------

/* Dato un elemento (o chiave) k, determinare se esiste all’interno di un array A di n
elementi. Se l’elemento esiste, si restituisce la sua posizione, altrimenti -1.
Soluzione con ricerca sequenziale.*/

function seqSearch(k,A){
  var i = 0                       // costo: 1
  var trovato = false             // costo: 1

  //Scorro le posizioni dell’array fino a quando non trovo la chiave k oppure supero il limite
  //dimensionale dell’array. Se raggiungo i==n vuol dire che non trovo la chiave nell’array.

  while(i < n && !trovato){       //
    if(A[i] == k) trovato = true  // costo: n
    else i++                      //
  }

  if(i==n) return -1              // costo: 1
  else return i                   // costo: 1
}

// Costo totale:
//  - Caso peggiore               n + 4 = O(n)
//  - Caso miglire                Tau(1) 
//    k contenuto della prima cella di A, while eseguito una volta, quindi il tempo costate a 1

// lim_{n→∞} n + 4 = lim_{n→∞} n + c = lim_{n→∞} n 
// posso ignorare tutte le costianti (operazioni di cost o unitario)