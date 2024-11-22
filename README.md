# GreenTrack - Monitoramento de Produção e Armazenamento de Hidrogênio Verde

### Descrição do Projeto
A **GreenTrack** é uma solução inovadora desenvolvida para monitorar em tempo real o processo de produção e armazenamento de hidrogênio verde. Utilizando ESP32 e sensores, a solução integra dispositivos IoT com comunicação MQTT para garantir a segurança e eficiência da produção, prevenindo falhas operacionais e acidentes. Além disso, emite alertas via WhatsApp para melhorar a comunicação e aumentar a eficiência.

## Objetivo
A solução visa resolver os desafios encontrados na produção e armazenamento de hidrogênio verde, principalmente no que se refere à eletrolise da água, controle de temperatura e vazamentos de CO₂. A **GreenTrack** oferece um sistema de monitoramento inteligente baseado em sensores, conectado a um dashboard, e com alertas via WhatsApp.


## Funcionalidades
- **Monitoramento em tempo real**: Uso de sensores para medir temperatura (DHT22) e fluxo de hidrogênio (LDR).
- **Manutenção preditiva**: Análise de dados para identificar falhas potenciais e sugerir manutenções.
- **Alertas automatizados**: Envio de alertas sobre falhas e anomalias para o dashboard e via WhatsApp.
- **Dashboard inteligente**: Interface visual para acompanhar as métricas e status dos sistemas de produção e armazenamento.


## Requisitos

## Componentes
- **ESP32** 
- **Sensor de temperatura DHT22** (representando o Termoapar)
- **Sensor de luminosidade LDR** (representando o Fluxômetro)
- **Jumpers** 

## Dependências
- *C++*
- *IoT (Internet das Coisas)*
- *Software Wokwi*
- *Node-RED*
- *Servidor Protocolo MQTT*
- *CallMeBot API* 

   
## Como Usar

## Instruções de Uso
1. Instale o [Node-RED](https://nodered.org/docs/getting-started/local).
2. Configure o  [MQTT](https://www.hivemq.com/demos/websocket-client/?) no Node-RED para receber os dados dos tópicos.
3. Execute o projeto no Wokwi e conecte ao servidor HiveMQ.

## Requisitos
- ESP32 com conectividade WiFi
- Conhecimento básico em Node-RED e MQTT
- Acesso ao servidor MQTT [HiveMQ](https://www.hivemq.com/demos/websocket-client/?)


## Fluxo Node-RED
![image](https://github.com/user-attachments/assets/a75bd9a5-6da4-4479-a01e-c8a41843045b)

### Monitoramento e Alertas:

1. **Configure alertas automáticos via CallMeBot API** para receber notificações em caso de falhas.

2. **Obtenha a chave da API (apikey) do bot antes de usar a API:**

3. Adicione o número de telefone **+34 644 95 42 75** aos seus contatos telefônicos (nomeie como preferir).

4. Envie a seguinte mensagem para o novo contato criado:  
   **"I allow callmebot to send me messages"** (usando o WhatsApp).

5. Aguarde até receber a mensagem:  
   **"API Activated for your phone number. Your APIKEY is 123123"** do bot.

A mensagem do WhatsApp do bot conterá a chave de API necessária para enviar mensagens usando a API. Após receber a confirmação, você poderá enviar mensagens de texto usando a API.

6. **Configuração de alerta no Node-RED:**

   Após configurar a chave de API, você pode usar o seguinte código no Node-RED para enviar alertas quando a temperatura ultrapassar o limite:
![image](https://github.com/user-attachments/assets/a6a0085a-e9bf-4b60-8527-627951380b36)

Substitua os seguintes campos:

SEU_NUMERO_DE_TELEFONE: Coloque o seu número de telefone com o código do país (exemplo: +55 11 12345678).

SEU_APIKEY: Substitua pela chave de API que você recebeu do bot.

Isso permitirá que o seu sistema envie automaticamente alertas via WhatsApp sempre que a temperatura ultrapassar o limite definido.
![image](https://github.com/user-attachments/assets/700f234b-8b8b-440f-a1e0-d7e62cf65331)



##  Simulação Wokwi
[Clique aqui para acessar a simulação Wokwi](https://wokwi.com/projects/414748088999110657)

![image](https://github.com/user-attachments/assets/1b5865f0-e46e-4b02-8246-74fb7ee5fc41)


## Resultados Esperados e Impacto
A **GreenTrack** tem como objetivo reduzir os custos de monitoramento em até 80% e diminuir falhas e acidentes de produção em 69%. Com um sistema de monitoramento eficiente, espera-se melhorar a segurança do processo de produção e armazenamento de hidrogênio verde, tornando-o mais sustentável e escalável.

## Conclusão
A **GreenTrack** é uma solução essencial para garantir o monitoramento seguro da produção e armazenamento de hidrogênio verde. Ao integrar **IoT** e **MQTT**, o projeto proporciona uma forma mais eficiente de gerenciar o processo, prevenindo falhas, aumentando a segurança e contribuindo para a sustentabilidade do setor.

## Alunos
- Alexia Ramalho - 558385
- Hellen Silva - 559008
- Lorenzo Acquesta - 557397
