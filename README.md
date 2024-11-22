# GreenTrack - Monitoramento de Produção e Armazenamento de Hidrogênio Verde

## Descrição do Projeto
A **GreenTrack** é uma solução inovadora desenvolvida para monitorar em tempo real o processo de produção e armazenamento de hidrogênio verde. Utilizando a plataforma ESP32 e sensores, a solução integra dispositivos IoT com comunicação MQTT para garantir a segurança e eficiência da produção, prevenindo falhas operacionais e acidentes.

## Objetivo
A solução visa resolver os desafios encontrados na produção e armazenamento de hidrogênio verde, principalmente no que se refere à eletrolise da água, controle de temperatura e vazamentos de CO₂. A **GreenTrack** oferece um sistema de monitoramento inteligente baseado em sensores, conectado a um dashboard, e com alertas via WhatsApp.


## Funcionalidades
- **Monitoramento em tempo real**: Uso de sensores para medir temperatura (DHT22) e fluxo de hidrogênio (LDR).
- **Manutenção preditiva**: Análise de dados para identificar falhas potenciais e sugerir manutenções.
- **Alertas automatizados**: Envio de alertas sobre falhas e anomalias para o dashboard e via WhatsApp.
- **Dashboard inteligente**: Interface visual para acompanhar as métricas e status dos sistemas de produção e armazenamento.


## Requisitos

### Hardware
- **ESP32**
- **Sensor de temperatura DHT22**
- **Sensor de luminosidade LDR**
- **Comunicação MQTT**

### Software
- **ESP32** para programação do ESP32
- **Broker MQTT** (ex: HiveMQ)
- **Biblioteca MQTT** para ESP32 (PubSubClient)
- **Plataforma de desenvolvimento para dashboard** (Node-RED)
- **WhatsApp API** para envio de alertas

## Como Usar

### Configuração do Hardware:
1. Conecte o DHT22 ao ESP32 para medir a temperatura.
2. Conecte o LDR ao ESP32 para monitorar o fluxo de hidrogênio.

### Configuração do Software:
1. Abra o código fonte no Arduino IDE e carregue no ESP32.
2. Configure o broker MQTT e os tópicos para comunicar os dados dos sensores.

### Dashboard:
1. Crie um dashboard utilizando ferramentas como **Node-RED** ou **Grafana** para visualizar as medições em tempo real.

### Monitoramento e Alertas:
1. Configure alertas automáticos via **WhatsApp API** para receber notificações em caso de falhas.

## Link para Simulação Wokwi
[Clique aqui para acessar a simulação Wokwi](https://wokwi.com/projects/414748088999110657)

![image](https://github.com/user-attachments/assets/1b5865f0-e46e-4b02-8246-74fb7ee5fc41)


## Resultados Esperados e Impacto
A **GreenTrack** tem como objetivo reduzir os custos de monitoramento em até 80% e diminuir falhas e acidentes de produção em 69%. Com um sistema de monitoramento eficiente, espera-se melhorar a segurança do processo de produção e armazenamento de hidrogênio verde, tornando-o mais sustentável e escalável.

## Conclusão
A **GreenTrack** é uma solução essencial para garantir o monitoramento seguro da produção e armazenamento de hidrogênio verde. Ao integrar **IoT** e **MQTT**, o projeto proporciona uma forma mais eficiente de gerenciar o processo, prevenindo falhas, aumentando a segurança e contribuindo para a sustentabilidade do setor.

## Licença
Este projeto está licenciado sob a **Licença MIT**. Veja o arquivo `LICENSE` para mais informações.

## Alunos
- Alexia Ramalho - 558385
- Hellen Silva - 559008
- Lorenzo Acquesta - 557397
