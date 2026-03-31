⚔️ War Estruturado - Fase de Ataque
Um simulador de combate por turnos baseado no jogo de tabuleiro WAR, desenvolvido em Linguagem C. O projeto foca em conceitos avançados de programação estruturada, como manipulação de memória e ponteiros.

📋 Sobre o Projeto
O programa permite que um usuário gerencie um mapa dinâmico de territórios. Cada território possui um nome, uma cor de exército e uma quantidade de tropas. O objetivo é simular a fase de ataque, onde territórios de cores diferentes podem batalhar pela posse de terras vizinhas.

Principais Funcionalidades:
Criação Dinâmica de Mapa: O usuário define quantos territórios deseja no início da execução.

Sistema de Combate: Simulação baseada em dados (1 a 6) para atacante e defensor.

Conquista de Territórios: Se o atacante vencer, o território defensor muda de cor e recebe metade das tropas do conquistador.

Validações de Regras: Impede ataques entre territórios da mesma cor ou ataques a si mesmo.

🛠️ Tecnologias e Conceitos Aplicados
O código foi construído utilizando os seguintes pilares da linguagem C:

Structs (Estruturas): Utilizadas para agrupar as propriedades de cada território (nome, cor, tropas).

Alocação Dinâmica (calloc): O mapa não tem tamanho fixo; a memória é requisitada ao sistema operacional durante a execução, baseada na escolha do usuário.

Ponteiros: Uso intensivo de ponteiros para passagem de parâmetros em funções, garantindo que as alterações (como perda de tropas ou mudança de cor) persistam na memória principal.

Modularização: O código é dividido em funções específicas (cadastrar, exibir, atacar, liberarMemoria) para facilitar a manutenção.

Gerenciamento de Memória: Implementação da função free() para garantir que toda a memória alocada seja devolvida ao sistema ao fechar o jogo.

🚀 Como Executar
Pré-requisitos:
Compilador C (GCC, Clang ou o próprio MSVC do Visual Studio).

Ambiente Windows (devido ao uso da biblioteca <windows.h> para tratamento de UTF-8).

Passo a Passo:
Clone este repositório ou copie o arquivo .c.

Abra o projeto no Visual Studio.

Certifique-se de que o arquivo está salvo com a codificação UTF-8 com BOM (para evitar erros de acentuação).

Compile e execute (F5).

🎮 Como Jogar
Configuração: Informe o número de territórios (ex: 3).

Cadastro: Digite o nome (ex: Brasil), a cor (ex: Verde) e as tropas (ex: 10).

Ataque: * Observe o número (ID) de cada território no mapa exibido.

Escolha o número do atacante e do defensor.

O sistema sorteará os dados e aplicará as consequências da vitória ou derrota automaticamente.

Finalização: Digite 0 para sair e liberar a memória do sistema.

📄 Licença
Este projeto foi desenvolvido para fins educacionais. Sinta-se à vontade para estudar, modificar e compartilhar.

Desenvolvido com ☕ e C.
