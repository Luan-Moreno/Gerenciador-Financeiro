# Gerenciador Financeiro

- Este projeto é um gerenciador financeiro desenvolvido em C para o segundo semestre do curso de Ciência da Computação no Centro Universitário FEI.
- O sistema tem como objetivo fornecer uma solução para o controle financeiro pessoal, incluindo funcionalidades de poupança, controle de receitas e despesas, e relatórios detalhados.

## Funcionalidades
1. Poupança

    - Descrição: Simula uma poupança com uma taxa de 0.2% de aumento diário, dividida em 5 opções:
   
        1. Investimento Inicial: Realiza o depósito inicial, salvando os dados em poupanca.txt.
        2. Adicionar Fundos: Adiciona valores ao investimento inicial, atualizando o arquivo.
        3. Verificar Saldo: Mostra o saldo atual com o incremento diário.
        4. Sacar Dinheiro: Permite sacar dinheiro do investimento.
        5. Menu Principal: Retorna ao menu principal.

3. Saldo Atual

   - Descrição: Calcula o saldo atual da conta geral, excluindo a poupança, com base em dados salvos em saldo.txt.

4. Cadastro de Receitas e Gastos

    - Descrição: Registra receitas e gastos com valor, descrição, data e categoria.
    - Valores negativos são usados para gastos.
    - Os dados são armazenados em cadastro.txt no formato binário.

5. Relatório de Movimentação Anual

    - Descrição: Converte o arquivo binário de cadastro em um relatório anual, salvo em cadastroanual.txt.

6. Relatório de Movimentação Mensal

    - Descrição: Cria um relatório mensal dividido em categorias e tipos de movimentação, salvo em cadastromensal.txt.

7. Saída

    - Descrição: Encerra o programa.

Requisitos

    Formato de Data: O sistema aceita apenas o formato dd-mm-aa. Outros formatos podem causar falhas.
