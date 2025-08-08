/*
L'algoritmo BFS permette, dato un grafo G=(V,E) ed un nodo s in G.V di calcolare per ogni altro nodo il percorso minimo costruendo un albero di tipo breath-tree in cui la radice è s.
*/

// Funzione di appoggio che restituisce tutti i nodi adiacenti 
// in un grafo G di un determiniinato nodo v
function *adj(G, v){
  for(let u of G.E){
    if(u[0] == v.val) {
      yield G.V.filter((value) => {
        if(value.val == u[1]) return value
      })[0]
    }
  }
}

function BFS(G, s){
  // Come prima cosa inizializzo tutti i nodi con il valore 
  // d a Infinito, questo valore indica la distanza dalla radice del nodo
  // intesa come archi che vanno attraversati. In più inizializzo anche il nodo 
  // predecessore p a null (p indica appunto il predecessore una volta costruito l'albero)
  for(let v of G.V){
    // Tutti i nodi vengono inizilizzati in modo uguale tranne s, che viene inizlializzato
    // con una distanza d di 0
    if(v.val == s.val) v.d = 0
    else v.d = Infinity
    v.p = null;
  }

  // Iniziliazzo la coda dei nodi da dover visitare con s 
  var Q = [s]

  // Scorro la lista finchè non sarà vuota
  while(Q.length != 0){

    // Estraggo il primo elemento e controllo tutti i suoi nodi adiacenti
    var u = Q.shift()
    for(let v of adj(G,u)){
      // Se uno dei suoi adiacenti ha il valore distanza a Infinito vuol dire che il nodo
      // è bianco e quindi non è mai stato visitato, a quelo punto allora inizializzo la sua
      // distanza e il suo predecessore, in più lo aggiungo alla lista dei nodi da controllare
      // quindi lo faccio diventare Grigio
      if(v.d == Infinity){
        v.d = u.d + 1
        v.p = u.val
        Q.push(v)
      }
    }
  }
}

// Algoritmo esegue la creazione del breadth-tree in O(V+E)


G = {V: [{val: "r"},{val: "s"}, {val: "v"}, {val: "t"}, {val: "x"}, {val: "u"}, {val: "y"}, {val:"w"}],
    E: [["r","s"], ["s","r"], ["v","r"], ["r","v"], ["s","w"], ["w","s"], ["w","t"], ["t","w"],
       ["t","x"], ["x","t"], ["x","y"], ["y","x"], ["u","y"], ["y","u"], ["t","u"], ["u","t"], ["w","x"], ["x","w"]]}



BFS(G, {val:"s", d:0, p:null})
console.log(G)