Exemplo de Contagem Multithreaded
Descrição
Este programa em C demonstra uma abordagem multithreaded para incrementar um contador compartilhado utilizando threads POSIX (pthread). Cada thread executa um número fixo de incrementos e depois adiciona seu ID de thread ao contador.

Explicação do Código
O código cria várias threads que incrementam um contador compartilhado de forma segura usando mutexes para sincronização. Cada thread executa a função work, onde realiza os incrementos e adiciona seu ID ao contador compartilhado.

Observações

Sincronização: O uso de pthread_mutex_lock e pthread_mutex_unlock garante que apenas uma thread por vez possa modificar o contador compartilhado.
Saída: Cada thread imprime suas contribuições incrementais para o contador durante a execução.
Resultado Final: Após todas as threads concluírem a execução, o programa exibe o valor final do contador.
Este exemplo demonstra como implementar e gerenciar a concorrência entre threads em C usando a biblioteca POSIX para garantir a consistência e segurança dos dados compartilhados.
