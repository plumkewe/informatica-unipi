// ----------- RAIDIX-SORT -----------

/**
 * Ordinare un Array di interi andando ad ordinare le singole cifre. Esempio:
 * 1094 - 986 - 234 - 125 - 1120 ==> ordino prima 1-//-//-//-1 poi 0-9-2-1-1 ecc..
 * 
 * è necessario, per far si che funzioni questo algoritmo, che le singoli cifre vengano
 * ordinae con una algoritmo di ordinamento che non cambi le posizioni di due elementi uguali
 * questa tipologia di algorimtmo si chiamo "algoritmo di ordinamento stabile".
 */


/** IMPLEMENTAZIONE NON VISTA A LEZIONE !!! */

function getMax(A){
  var max = -Infinity
  for(let i of A){
    if(max < i.toString().length) 
      max = i.toString().length
  }
  return max
}

function getPosition(n,p){
  return Math.floor(Math.abs(n) / (10 ** p)) % 10
}


function radixSort(arr) {
    const max = getMax(arr); // Teta(n)

    for (let i = 0; i < max; i++) { // min = 1 / max = +Infinity ==> Teta(max)

        // creo un array di 10 elementi vuoto
        let buckets = Array.from({ length: 10 }, () => [ ])

        for (let j = 0; j < arr.length; j++) { //Teta(n)
          buckets[getPosition(arr[ j ], i)].push(arr[ j ]);
        }
        arr = [ ].concat(...buckets);
    }
    return arr
}

// CALCOLO COSTO ==> n + max*n ==> Teta(n) (dipende da valore di max)
console.log(radixSort([4, 57, 7, 3, 933]))