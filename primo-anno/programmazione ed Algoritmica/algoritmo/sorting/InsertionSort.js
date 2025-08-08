// ----------- INSERTION-SORT -----------

/* 
Dato un array A di n elementi, si vuole ottenere un array ordinato, cioè 
A[0] ≤ A[1] ≤ . . . ≤ A[n − 1]. 

Proprietà: al termine del passo j-esimo dell’algoritmo l’elemento j-esimo viene inserito al posto giusto e i primi j elementi sono ordinati
*/

function insertionSort(A){
  var i = 0, k = 0                                        // Teta(1)  

  for(var j=1; j<A.length; j++){                          // (n - 1)
    // Salviamo l'attuale valore da ordinare 
    k = A[j]

    // Impostiamo l'idice al valore a quello prima
    // di quello del valore in k (ricorda che da 0 
    // a j-1 i valori sono ordinati dai giri 
    // prima dell'algoritmo)
    i = j-1 

    // Inserisco il valore di k nel posto giusto  
    // finchè non abbiamo visto tutto l'array [0,k-1].
    // Se (i>=0) ed il valore nella cella è maggiore di
    // k (A[i] > k) spostiamo i valori più grandi 
    // (A[i]) avanti di uno (A[i]).               
    while(i >= 0 && A[i] > k){                             // #1    
      // spostiamo con l'elemento più grande nella
      // posizione di k                           
      A[i+1] = A[i]                               

      // ci spostiamo per vedere l'elemento dopo  
      // (quello prima nell'array)                
      i--   
    }

    // Alla fine avremo spostato tutti i valori avanti e lasciato
    // uno spazio vuoto dove inseriremo k
    A[i+1] = k
  }
  return A
}

/** Possiamo vedere questo algorimo come quando andiamo ad ordinare
 * le carte da gioco in mano, partiamo da sinistra e spostiamo ogni carta 
 * indietro finchè non si trova in ordine, quando quindi passiamo alla carta
 * dopo quello prima sono già ordinate.
 */

/* 
 * #1: ∑_{da j=1 a n-1} Tj  (somma di tutti i giri del while per ogni elemento j) 
 * dove Tj è il numero di i volte che valuto la condizione del while al passo j-esimo 
*/

/*
 * CASO PESSIMO: L'array è ordinato in maniera descrescente quindi per ogni elemento del while dovrà
 * fare giri pari alla sua posizione - 1 (Esempio pos:3 farà 2-1-0, pos:7 farà 6-5-4-3-2-1).
 * 
 * Esempio: prendiamo n=5
 * 0 + 0-1 + 0-1-2 + 0-1-2-3 + 0-1-2-3-4 
 * 
 * Se facciamo un conto (vedi libro) abbiamo che l'algoritmo fa:
 * kn^2 + n + k giri (dove k è una costante). Quindi alla fine il caso pessimo è Teta(n^2)
 * 
 * 
 * CASO OTTIMO: L'array è già ordinato quindi l'algoritmo entrerà nel ciclo for e farà n giri
 * senza entrare mai nel while. Quindi alla fine il caso ottimo è Teta(n)
 */