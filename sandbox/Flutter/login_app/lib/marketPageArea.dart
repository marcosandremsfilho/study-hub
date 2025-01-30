import 'package:flutter/material.dart';

class MarketPageArea extends StatefulWidget {
  @override
  marketPageArea createState() => marketPageArea();
}

class marketPageArea extends State<MarketPageArea> {
  int selectedIndex = 0;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Container(
      decoration: const BoxDecoration(color: Colors.green),
    ));
  }
}
