// ----------- MERGE-SORT -----------

/**Ordinamento di un array di interi con ricorsione */

// Tramite questo algoritmo di sorting andiamo ad ordinare le due portizioni dell'array
// andando a creare un nuovo array e "popolandolo" di elementi. Per riempire il nuovo array
// confrontiamo ogni elemento della prima parte dell'array con ogni elemento della seconda
// finche non troviamo uno più grande, finchè ci sono elementi più piccoli aggiungiamo questi
// al risultato, qunado troviamo quello più grande aggiugiamo l'elemento che stavano paragonando
// al risultato ed ricominciamo guardando l'elemento successivo
/**
 * Esempio:
 * [4,7,8,13,17,21]        [4,7,8,13,17,21]         [4,7,8,13,17,21]
 *  |                 [2]    \               [2,4]     |              [2,4,5] ecc..
 * [2,5,12,20,35,68]       [2,5,12,20,35,68]        [2,5,12,20,35,68]
 */
function merge(array, sx, cen1, cen2, dx){ // Teta(n)
  //Inizializzo tutti gli indici      Teta(1)
  var sx_i = sx // indice per l'elemento che stiamo guardando nel sotto array di sinistra
  var dx_i = cen2 // indice per l'elemento che stiamo guardando nel sotto array di destra
  var union_i = sx // indice del nuovo array (dove bisogna aggiungere l'elemento)
  var result = [] // nuovo array

  // Continiamo ad iterare questa operazione finchè uno dei due array non arriva alla fine
  while(sx_i <= cen1 && dx_i <= dx){ // Teta(n/2) = Teta(n)
    // Se l'elemento del sottoarray di sinistra è più piccolo di quello di destra andiamo ad
    // aggiungere a result l'elemnto di sinistra ed portiamo sx_i alla posizione successiva
    // in caso contriario aggiungiamo l'elemendo di destra e portiamo dx_i all posizione dopo
    if(array[sx_i] <= array[dx_i]){
      result[union_i++] = array[sx_i++]
    }else{
      result[union_i++] = array[dx_i++]
    }
  }

  // Alla fine del ciclo uno dei due array sarà arrivato alla fine e questo vuol dire
  // che tutti i suoi elementi sono stati inserite nel nuovo array, mentre ci sarà nell'altro
  // array alcuni elementi che non sono stati inseriti, questo if controlla quale dei due array
  // non è terminato ed utilizza un while per aggiungere tutti i suoi elemtni a result
  if(sx_i == cen2){
    while(dx_i <= dx){ //Teta(n)
      result[union_i++] = array[dx_i++] 
    }
  }else{
    while(sx_i <= cen1){ //Teta(n)
      result[union_i++] = array[sx_i++] 
    } 
  }

  // Copio l'array orinato in reuslt in array
  for(let i=sx; i<=dx; i++){ //Teta(n)
    array[i] = result[i]
  }
}

function sort(array, start, end){
  // La ricorsione avviene finchè abbiamo un array di 
  // almeno due elementi quindi fine - inizio è almeno 1
  if((end - start) >= 1){
    // Troviamo il centro dell'array ed ipostiamo la fine del primo
    // array in cen1 e l'inizio del secondo in cen2 come cen1+1
    var cen1 = Math.floor((start + end)/2)
    var cen2 = cen1 + 1

    // Richiamo ricorsivamente l'algoritmo di sort per entrambi i sotto array
    // i quali andranno a richiamare l'algoritmo di sort n volte finche non 
    // "tocchiamo il fondo" con un array di dimensione 1
    sort(array, start, cen1)
    sort(array, cen2, end)

    // per ogni chiamata ricorsiva i due array vengono ordinati, visto che 
    // questa funzione viene chiamata dopo la ricorsione arriverà un array con la prima
    // parte ordinata [start,cen1] e pure la seconda [cen2, end] che verranno ordinate fra di loro
    merge(array, start, cen1, cen2, end)
  }
}

function merge_sort(array){
  sort(array, 0, array.length-1)
}

array = [7,4,21,17,12,9]
merge_sort(array)
console.log(array)

/**
 * Esempio con [7,4,21,17,12,9]:
 * 
 * 1. [7,4,21] [17,12,9]
 * 2. [7,4][21] [17,13][9]
 * 3. [7][4][21] [17][13][9]
 * 
 * 5. [7][4] ==> merge ==> [4,7, , , , ]
 * 6. [4,7][21] ==> merge ==> [4,7,21, , , ]
 * 7. [17][13] ==> merge ==> [ , , ,13,17, ]
 * 8. [13,17][9] ==> merge ==> [ , , ,9,13,17]
 * 9. [4,7,21] [9,13,17] ==> merge ==> [7,4,21,17,12,9]
 */

/**
 * CALCOLO COMPLESSITA:
 * 
 * L'operazione di merge ha un costo di Teta(n) dove n è la dimensione del sotto array
 * l'operazione verrà chiamata per ogni "divisione". esse possono essere viste come un albero
 *                      n
 *                     / \
 *                 n/2     n/2
 *                 / \     /  \
 *              n/4  n/4  n/4  n/4
 *           ...  ... ... ... ... ...
 * 
 * In totale verrà eseguito il merge per ogni livello (altezza dell'albero) che è log(n) 
 * (questo perchè l'altezza di un albero di calcola facendo appunto h=log(f) dove f è il 
 * numero di foglie che in questo caso è n perchè le foglie sono tutte partizioni dell'array
 * con ogni singolo elemento).
 * 
 * Risulta quindi che il merge viene eseguito log(n) quindi il caso pessimo è nlog(n)
 */                          