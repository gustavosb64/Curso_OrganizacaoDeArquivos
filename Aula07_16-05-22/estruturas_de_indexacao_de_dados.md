## Estruturas de indexação de dados

* **Heurística 80/20**
    * _Oracle_: 
        * até 10% dos dados: **índice**
        * 90%+: **busca sequencial**

* **Arquivos de dados vs arquivos de índices**

### Arquivos de dados

### Arquivos de índice

* **Cabeçalho:** Dois campos
    * _Índice de busca_
    * _RRN/offset_

### Observações

* **Passos da inserção:**
    * 1) inserir no arquivo de dados
    * 2) inserir no arquivo de índices
    * 3) ordenar o arquivo de índices
     
* **Passos da remoção:**
    * 1) busca o valor a ser removido no arquivo de índices
    * 2) lê onde está o dado e remove o índice do arquivo de índices (lembrete: o arquivo de índices ainda está na RAM)
    * 3) ordenar o arquivo de índices

* O arquivo de índices deve ser carregado em memória primária para trabalhar com maior eficiência

