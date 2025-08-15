// ----------- BINARY-SEARCH -----------

/* Dato un elemento (o chiave) k, determinare se esiste all’interno di un array ORDINATO A
di n elementi. Se l’elemento esiste, si restituisce la sua posizione, altrimenti -1.
Soluzione con ricerca binaria. */

function binSearch(k,A){
  var pos = -1                                            // costo: 1              
  var sx = 0                                              // costo: 1
  var dx = A.length-1                                     // costo: 1   

  while(sx <= dx && pos == -1){                           //
    // Vado a calcolare il centro dell'array              //
    const cen = Math.floor((sx + dx)/2)                   //
                                                          //
    //l'elemento si trova al centro si salva              // costo: log n #1
    if(A[cen] == k) pos = cen                             //
    //l'elemento è miniore ci si sposa sulla desta        //
    else if(k < A[cen]) dx = cen-1                        //
    //l'elemento è maggiore ci si sposa sulla sinistra    //
    else sx = cen+1                                       //
  }

  return pos                                              // costo: 1
}

// Costo algoritmo:
// - Caso pessimo                             O(log(n)) and Omega(log(n)) ==> Tau(log(n))
// - Caso ottimo                              Tau(1) - caso in cui k è nel centro

/** #1: Il costo è log n perchè: ad ogni giro del while il contronto fra k e A[cen] può dare 3 risposte:
 *      - k <  A[cen]
 *      - k == A[cen]
 *      - k > A[cen]
 * Ogni confronto apre 3 vie e dopo i confronti il numeri di vie aprte è 3^i. Le possibili soluzioni sono n+1 
 * (grandezza dell'array + caso in cui k non c'è).
 * 3^i >= n+1 > n ==> i = log_3 (n+1) ==> Omega(log n)
 * */
