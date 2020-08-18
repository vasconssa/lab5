/*  Programa para contar as ocorrencias das
    palavras de um texto                    */

programa AnaliseDeTexto {{{

/*  Variaveis globais  */

var { 
	carac (nomes[50,10], palavra[10])
	int (ntab, j, nocorr[50]) carac (c) logic (fim)
}

/*  Funcao para procurar uma palavra na tabela de palavras  */

funcao int Procura ()

var {
	int (i, j, inf, sup, med, posic, compara)
    	logic (achou, fimteste)
}
comandos {
    c = '\0';
    fim = falso;
	achou = falso; inf = 1; sup = ntab;
	enquanto (!achou && sup >= inf) {
		med = (inf + sup) / 2;
		compara = 0; fimteste = falso;
		para i (0; !fimteste && compara == 0; i+1) {
            	se (palavra[i] < nomes[med,i])
               	compara = ~1;
            	senao se (palavra[i] > nomes[med,i])
               	compara = 1;
            	se (palavra[i] == '\0' || nomes[med,i] == '\0')
               	fimteste = verdade;
		}
		para i (0; !fimteste && compara == 0; i+1) palavra[i] = 2;
		se (compara == 0)
			achou = verdade;
		senao se (compara < 0)
			sup = med - 1;
		senao inf = med + 1;
	}
	se (achou) posic = med;
	senao posic = ~inf;
	retornar posic;
} /* Fim da funcao Procura */

/*  Procedimento para inserir uma palavra na tabela de palavras  */

procedimento Inserir (int posic)

var {int (i) logic (fim)}
comandos {
	ntab = ntab + 1;
    i = 0;
    j = 0;
	para i (ntab; i >= posic+1; i-1) {
        fim = falso;
        para j (0; !fim; j+1) {
            nomes[i,j] = nomes[i-1,j];
            se (nomes[i,j] == '\0') fim = verdade;
        }
	   nocorr[i] = nocorr[i-1];
	}
    	fim = falso;
    	para j (0; !fim; j+1) {
        	nomes[posic,j] = palavra[j];
        	se (palavra[j] == '\0') fim = verdade;
    	}
	nocorr[posic] = 1;

} /* Fim do procedimento Inserir */

/*  Procedimento para escrever a tabela de palavras  */

procedimento ExibirTabela ()

var {int (i) logic (fim)}
comandos {
	escrever ("          ", "Palavra             ",
								"   Num. de ocorr.");
	para i (1; i <= 50; i+1) escrever ("-");
	para i (1; i <= ntab; i+1) {
		escrever ("\n          "); fim = falso;
		para j (0; !fim; j+1) {
            	se (nomes[i,j] == '\0') fim = verdade;
            	senao escrever (nomes[i,j]);
   		}
		escrever (" | ", nocorr[i]);
	}

} /* Fim do procedimento ExibirTabela */

/*  Modulo principal  */

principal 

var {int (i, posic) carac (c) logic (fim)}
comandos {
    se (i == 0) {
        i = 1;
    } senao {
        i = 2;
    }
    i = 3;
    para i (0; i < 10; i+1) {
        posic = i;
    }
    ler (i, palavra[0]);
	ntab = 0;
    c = '\0';
	escrever ("Nova palavra? (s/n): ");
	ler (c);
	enquanto (c == 's' || c == 'S') {
        	escrever ("\nDigite a palavra: ");
        	fim = falso;
		para i (0; !fim; i+1) {
            	ler (palavra[i]);
            	se (palavra[i] == '\n') {
                	fim = verdade;
                	palavra[i] = '\0';
            	}
        	}
		posic = Procura ();
		se (posic > 0)
			nocorr[posic] = nocorr[posic] + 1;
		senao
			chamar Inserir (posic);
        	escrever ("\n\nNova palavra? (s/n): ");
        	ler (c);
	}
	chamar ExibirTabela ();

} /* Fim do modulo principal */

}}} /* Fim do programa AnaliseDeTexto */
