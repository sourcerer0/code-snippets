#include <stdlib.h>
#include <stdio.h>

#define M 8191
// Tamanho da tabela.

#define hash(v, M) (v % M)
// Transforma uma chave v em um índice no intervalo 0..M-1.

typedef char *string;

typedef struct {
   int    chave;
   string valor;
} tipoObjeto;

// Definição de um nó das listas de colisões.
typedef struct STnode *link;
struct STnode {
   tipoObjeto obj; 
   link       next;
} ;

link *tab;
tipoObjeto objetonulo;

void STinit() 
{ 
   int h;
   tab = malloc(M * sizeof (link));
   for (h = 0; h < M; h++) 
      tab[h] = NULL; 
}

// Insere obj na tabela de símbolos.
//
void STinsert(tipoObjeto obj) 
{ 
   int h, v;
   v = obj.chave;
   h = hash(v, M);
   link novo = malloc(sizeof (link));
   novo->obj = obj;
   novo->next = tab[h];
   tab[h] = novo;
}

// Devolve um objeto cuja chave é v. Se tal objeto não existe,
// a função devolve um objeto fictício com chave nula.
//
tipoObjeto STsearch(int v) 
{ 
   link t;
   int h;
   h = hash(v, M);
   for (t = tab[h]; t != NULL; t = t->next){
       if (t->obj.chave == v) break;
   }
   if (t != NULL) return t->obj;
   return objetonulo;
}

int main(){
    objetonulo.chave = 12;
    objetonulo.valor = "hello world";

    STinit();
    STinsert(objetonulo);

    tipoObjeto obj = STsearch(12);
    printf("%s\n", obj.valor);
}
