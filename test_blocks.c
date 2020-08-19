programa TesteCodInt {{{
    var {
        int (vetor[50, 50])
    }

    funcao int testaOperacoesSimples () 
        var {int (i, j) real (a, b) logic (v, f)}
        comandos {
            v = verdade;
            f = falso;
            v = !f;
            f = !v;
            v = v || f;
            f = v && f;
            i = 0;
            j = 2;
            i = i + j;
            j = i * i + j;
            a = 2.5;
            b = 2.5;
            a = a + b*a;
            v = a > b;
            f = a < b;
            vetor[i, j] = i + j;
            escrever(a, b, i, j, vetor[i, j]);

            retornar i;
        }

    procedimento testePara() 
        var { int (i, a, n) }
        comandos {
            a = 0;
            n = 50;
            para i (0; i <= n; i+1) {
                a = i;
                vetor[i, a] = n - a;
            }
        }
    

    procedimento testeParaDuplo() 
        var { int (i, j, a, n) }
        comandos {
            a = 0;
            n = 50;
            ler(n);
            para i (0; i <= n; i+1) {
                para j (0; j <= n; j+1) {
                    a = i + i*j;
                    vetor[i, j] = a;
                }
            }
        }
    

    procedimento testeSeSenao() 
        var {int (a, b) logic (v, f)}
        comandos {
            a = 1;
            b = 2;
            v = verdade;
            f = falso;
            ler(a, b, vetor[a * a + b, b]);
            se (v == verdade) {
                a = b;
            }

            se (v == falso) {
                b = a;
                a = 2 + b * 2;
            } senao {
                a = b;
            }
        }
    

    procedimento testeEnquanto() 
        var {int (a, b) logic (v, f)}
        comandos {
            enquanto (v == verdade || f == falso) {
                a = a + b;
                v = a > b;
                f = (a * b) < b;
            }
        }
    

    procedimento testeRepetir() 
        var {int (a, b) logic (v, f)}
        comandos {
            repetir {
                a = a + b;
                v = a > b;
                f = (a * b) < b;
            } enquanto (v == verdade || f == falso);
        }
    

    principal

    var {int (a)}
    comandos {
        a = testaOperacoesSimples();
        chamar testeEnquanto();
        chamar testePara();
        chamar testePara();
        chamar testeParaDuplo();
        chamar testeRepetir();
        chamar testeSeSenao();
    }
}}}
