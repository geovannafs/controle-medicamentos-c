💊 Sistema de Controle de Medicamentos em C

Um sistema simples, modular e 100% multiplataforma desenvolvido via terminal (Console) para o gerenciamento de estoque de medicamentos. O projeto foi desenvolvido para a disciplina de Estrutura de Dados.

---

📋 Funcionalidades

* **Cadastrar Medicamento:** Adiciona um novo item informando seu nome e a quantidade inicial em estoque.
* **Atualizar Estoque:** Busca um medicamento cadastrado pelo nome exato e sobrescreve a quantidade disponível.
* **Listar Medicamentos:** Exibe uma tabela formatada contendo o ID, Nome e a Quantidade de todos os itens registrados.
* **Trava de Segurança:** Limite estrutural configurado via macro (`#define`) para armazenar até 100 itens.

---

🧠 Destaques Técnicos e Boas Práticas

Este projeto foi reescrito focando em **padrões sólidos da linguagem C**:

* **Portabilidade Universal (Cross-Platform):** Substituição do clássico `fflush(stdin)` pela função customizada `limparBuffer()`. Isso elimina o *Undefined Behavior* (comportamento indefinido) de leitura de teclado, garantindo que o sistema rode perfeitamente tanto no **Windows** quanto no **Linux** e **macOS**.
* **Estruturas de Dados (`struct`):** Agrupamento de dados heterogêneos sob o tipo `med`.
* **Ponteiros e Passagem por Referência:** Manipulação direta dos endereços de memória (`med *m`) para otimização da alteração de dados.
* **Sanitização de Strings:** Uso de `fgets` combinado com `strcspn` para capturar nomes compostos e remover a quebra de linha residual (`\n`).

---
