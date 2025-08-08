// ----------- QUICK-SORT -----------

/**
 * Ordinare un array di interi tramte l'algoritrmo di Quicksort che applica il principio
 * del devide et impera in maniera simile al merge-sort.
 */

function partition(A,p,r){ // COSTO: Teta(n)
  // Salvo l'utlimo elemento della partizione che voglio 
  // dividere nuovamente
  var x = A[r]

  // Inizializzo l'indice di dove terminaerà la prima
  // partizione nuova
  var i = p-1

  //Scorro tutti gli elementi della partizione
  for(let j = p; j<r; j++){

    //Controllo per ogni elemento se è inferore all'ultimo
    //questo ci serve perchè in tal caso lo voglio "buttare" nella
    //nuova partizione di sinistra (essendo che in questa nuova
    //partizione ci saranno tutti elementi < di x e x sara il separatore)
    if(A[j] <= x){

      //aumento di 1 l'indice di dove verrà fatta terminare la nuova
      //partizione visto che poi ci butterò dentro A[j]
      i++
      [A[i],A[j]] = [A[j],A[i]]
    }
  }
  //in fine sposto l'utlimo elemento alla fine della partizione di sinistra 
  //che ho creato con il delimitatore i e restituisco la sua posizione
  [A[i+1],A[r]] = [A[r],A[i+1]]
  return i+1
}

function quickSort(A,start,end){
  if(start<end){
    var pivot = partition(A,start,end)
    quickSort(A,start,pivot-1)
    quickSort(A,pivot+1,end)
  }
}


var A
A = [1,2,3,4,5,6,7,8] // caso peggiore 1
A = [8,7,6,5,4,3,2,1] // caso peggiore 2

/**
 * In questi due casi peggiori si creerà per ogni partition
 * una partizione vuota ed una con tutti gli elementi
 */

A = [2,5,7,8,1,4,5,3]
quickSort(A,0,A.length-1)
console.log(A)

