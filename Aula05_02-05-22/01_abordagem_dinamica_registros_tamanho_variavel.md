# ABORDAGEM DINÂMICA PARA REGISTROS DE TAMANHO VARIÁVEL

*   Como cada registro possui um tamanho, é necessário armazenar o seu tamanho no início de cada registro
    *   É necessário que a lista armazene não o RRN, mas o _byte offset_
    *   Por conta disso, a lista utilizada **não** pode ser tratada como uma pilha:
        *   o dado a ser armazenado no campo deletado precisa ser do _tamanho certo_ (grande o suficiente)
        *   isto significa fazer uma busca na lista até encontrar um campo com um tamanho grande o suficiente para se armazernar o dado novo.
    *   como a  lista funciona desta forma, um algoritmo de inserção sofisticado não é necessário:
        *   Se não for encontrado um campo com tamanho grande o suficiente, ele é inserido ao final

