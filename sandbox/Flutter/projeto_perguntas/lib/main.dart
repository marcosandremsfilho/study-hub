import 'package:flutter/material.dart';
import './questao.dart';
import './resposta.dart';

void main() => runApp(const PerguntaApp());

class _PerguntaAppState extends State<PerguntaApp> {
  var _perguntaSelecionada = 0;

   final List<Map<String, Object>> _perguntas = const [
      {
        'texto': 'Qual é a sua cor favorita?',
        'Respostas': ['Preto', 'Vermelho', 'Azul', 'Branco'],
      },
      {
        'texto': 'Qual é o seu animal favorito?',
        'Respostas': ['Coelho', 'Cobra', 'Elefante', 'Leão'],
      },
      {
        'texto': 'Qual é o seu instrutor favorito?',
        'Respostas': ['Maria', 'João', 'Leo', 'Pedro'],
      }
    ];

  void _responder() {
    if(temPerguntaSelecionada) {
      setState(() {
      _perguntaSelecionada++;
    });
    }
  }

  bool get temPerguntaSelecionada {
    return _perguntaSelecionada < _perguntas.length;
  }

  @override
  Widget build(BuildContext context) {
   
  
  List <String> respostas = temPerguntaSelecionada
  ? _perguntas[_perguntaSelecionada] ['Respostas'] as List <String>
  : [ ];
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Perguntas'),
        ),
        body: temPerguntaSelecionada 
        ? Column(
          children: [
            Questao(_perguntas[_perguntaSelecionada]['texto'] as String),
            ...respostas.map((texto) => Resposta(texto, _responder)).toList(),
          ],
        )
        : const Center(
          child: Text(
            'Parabéns!',
            style: TextStyle(fontSize: 28),
          ),
        ),
      ),
    );
  }
}

class PerguntaApp extends StatefulWidget {
  const PerguntaApp({super.key});

  @override
  _PerguntaAppState createState() {
    return _PerguntaAppState();
  }
}
