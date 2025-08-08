// ----------- COUNTING-SORT -----------

/**Ordino un array sfruttando delle proprietà degli elementi da ordinare.

INPUT Array A di n interi compresi tra 1 e k: ∀0 < j ≤ n . A[j] ∈ [1..k]
OUTPUT Array A ordinato (non in place = usiamo una copia) */

function countingSort(A,k){

  //Creo un array "d'appoggio" di lunghezza pari 
  //al valore massimo che un elemento in A può avere
  //e lo inizializzo tutto a 0
  var C = new Array(k)
  for(var i=1; i<=k; i++) C[i] = 0 // Teta(k)

  //vado a segniare in C quanti elementi di ogni valore
  // (fra [1,k]) esistono in A. In posizione C[0] valore 1
  // C[1] valore 2 ecc..
  var j = 1
  for(j = 0; j<A.length; j++) C[A[j]] += 1 //Teta(n)

  // rinizializo j a 0 utilizzandolo come contatore
  // per aggiornare gli elementi in A
  j = 0

  // per ogni numero nel range [1,k] vado a riaggiungerlo
  // in A in ordine (aggiungo prima tutti gli 1 poi tutti
  // i 2 ecc..)
  for(var z = 1; z<=k; z++){ //Teta(n)
    for(var v = 0; v<C[z]; v++){
      A[j] = z
      j++
    }
  }
  return A
}
//console.log(countingSort([2,3,1,5,1,4],5))
/**
 * COSTO TOTALE (sia migliore che peggiore) ==> Teta(2n + k) ==> Teta(n + k)
 */



/** 
 * COUNTING-SORT ELEMENTI COMPLESSI 
 * Se A contiene elementi più complessi di interi in B perdiamo le associazioni e teniamo solo le chiavi.
 * Quella di seguito è una variante di countig-sort che risolve questo problema.
 * 
 * Inoltre questo COUNTING SORT ha la proprietà della stabilità cioè se nell'array di partenza abbiam un
 * elemento A[i] = A[j] con i<j anche nell'array ordinato verrà mantenuto l'ordinamento fra elementi uguali
*/

function countingSort2(A,k){
  // Inizializziamo l'array di appoggio che conterrà il numero di volte
  // che è presente una certa key
  var C = new Array(k)
  for(var i=0; i<=k; i++) C[i] = 0
  for(var j=0; j<A.length; j++) C[A[j].key] += 1

  // Aggiungiamo per ogni valore il numero di elementi precendenti
  // questo serve per dire quanti elementi prima ci sono
  for(var i=1; i<=k; i++) C[i] = C[i] + C[i-1]

  // Creiamo un nuovo array inserendo ogni elemento nella posizione giusta
  // facendolo scalare in base a quanti elementi prima ci sono
  // Questo è possibili perchè abbiamo fatto l'operazione prima
  var B = []
  for(j=A.length-1; j>=0; j--){
    B[C[A[j].key]-1] = A[j]
    C[A[j].key]--
  }
  return B
}

console.log(countingSort2([{key:2},{key:4},{key:3},{key:3},{key:3},{key:2},{key:3},{key:1}],5))

/**
 * ESEMPIO CON [2,4,3,3,3,2,3,1]:
 * 
 * 1. C = [1,2,4,1,0] B=[]
 * 2. Facciamo il ciclo for per aggiungere in ogni posizione quanti elementi precedono:
 *    [1,3,4,1,0] => [1,3,7,1,0] => [1,3,7,8,0] => [1,3,7,8,8]
 * 
 * Questo vuol dire che inseriremo l'elemento con valore 1 alla posizione 1 (indice 0)
 * mentre i 3 elementi con valore 2 nel seguente modo: il primo nella posizione 3 il secondo 2
 * (non verrà inserito un terzo perchè inseriamo scorredndo l'array principale)
 * 
 * 3. Infatti nel for finale succederà questo:
 *         _ 
 *    C = [1,3,7,8,8] B = [1, , , , , , , ] (A[i] = 1)
 *             _
 *    C = [0,3,7,8,8] B = [1, , , , , ,3, ] (A[i] = 3)
 *           _
 *    C = [0,3,6,8,8] B = [1, ,2, , , ,3, ] (A[i] = 2)
 * 
 *    .....
 */