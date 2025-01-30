import 'package:flutter/material.dart';
import './questao.dart';
import './resposta.dart';

class Questionario extends StatelessWidget {
  final List<Map<String, Object>> perguntas;
  final int perguntaSelecionada;
  final void Function(int) quandoresponder;

  const Questionario(
      {required this.perguntas,
      required this.perguntaSelecionada,
      required this.quandoresponder,
      super.key});

  bool get temPerguntaSelecionada {
    return perguntaSelecionada < perguntas.length;
  }

  @override
  Widget build(BuildContext context) {
    List<Map<String, Object>> respostas = temPerguntaSelecionada
        ? perguntas[perguntaSelecionada]['Respostas']
            as List<Map<String, Object>>
        : [];
    return Column(
      children: [
        Questao(perguntas[perguntaSelecionada]['texto'] as String),
        ...respostas.map((resp) {
          return Resposta(
              resp['texto'].toString(),
              () => quandoresponder(
                    int.parse(resp['pontuacao'].toString()),
                  ));
        }).toList(),
      ],
    );
  }
}
