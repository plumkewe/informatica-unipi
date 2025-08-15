// ----------- SELECTION-SORT -----------

/* Dato un array A di n elementi, si vuole ottenere un array ordinato, cioè
A[0] ≤ A[1] ≤ . . . ≤ A[n − 1]. 

Proprietà: al termine del passo j-esimo dell’algoritmo i primi j elementi di A sono 
ordinati e contengono i j elementi più piccoli di A
*/

function selectionSort(A){
  var j = 0, min = 0  // Teta(1)

  // scorro tutti gli elementi dell'array
  for(var i = 0; i<A.length; i++){ // Teta(n)

    // setto la posizione dell'elemento minimo 
    // all'emento dove ci si trova ora
    min = i

    // questo ciclo permette di controllare se
    // esistono elemento più piccoli (trova il minimo)
    // e salvo la posizione in min
    for(j=i+1; j<A.length; j++){ // n-j (con j=pos dell'elemnto corrente)
      if(A[j] < A[min]) min = j
    }

    // scabio l'elemento attuale con il minimo trovato
    // se non è stato trovato nessun elemento più piccolo
    // scambia con se stesso
    [A[i], A[min]] = [A[min], A[i]] // Teta(1)
  }

  return A
}

/**
 * COSTO TOTALE:
 * Questo for è farà n-1 giri per il primo elemento, n-2 per il secondo e così via fino a 0
 * per l'ultimo. Quindi il costo totale sarà uguale a: 
 * ==> ∑_{da i=1 a n} - 1 -n = (n(n - 1) / 2) - 1 - n 
 * ==> semplificato in termini di cresceza delle funzione = Teta(n^2)
 */
 