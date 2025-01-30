import 'package:flutter/material.dart';
import './login.dart';
import './marketPage.dart';

class HomePage extends StatefulWidget {
  @override
  homePage createState() => homePage();
}

class homePage extends State<HomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Container(
      width: MediaQuery.of(context).size.width,
      height: MediaQuery.of(context).size.height,
      padding: const EdgeInsets.all(20),
      decoration: const BoxDecoration(color: Colors.white),
      child: Column(mainAxisAlignment: MainAxisAlignment.center, children: [
        Image.asset('assets/images/UAIRRIOR.png', scale: 13, height: 100),
        const SizedBox(height: 200),
        Row(mainAxisAlignment: MainAxisAlignment.center, children: [
          IconButton(
            icon: const Icon(Icons.shopping_cart),
            onPressed: () {
              Navigator.push(context,
                  MaterialPageRoute(builder: (context) => MarketPage()));
            },
            color: Colors.blue,
            iconSize: 50.0,
          ),
          const SizedBox(width: 50),
          IconButton(
            onPressed: () {
              Navigator.push(
                  context, MaterialPageRoute(builder: (context) => Login()));
            },
            icon: const Icon(Icons.exit_to_app),
            color: Colors.blue,
            iconSize: 50.0,
          )
        ])
      ]),
    ));
  }
}
