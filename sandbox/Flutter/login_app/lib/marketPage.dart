import 'package:flutter/material.dart';
import './addProductPageAra.dart';
import './marketPageArea.dart';
import './marketProfilePage.dart';

class MarketPage extends StatefulWidget {
  @override
  marketPage createState() => marketPage();
}

class marketPage extends State<MarketPage> {
  int selectedIndex = 0;

  final List<Widget> screens = [
    MarketPageArea(),
    AddProductPageArea(),
    MarketProfilePage(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: screens[selectedIndex],
      bottomNavigationBar: BottomNavigationBar(
          items: const <BottomNavigationBarItem>[
            BottomNavigationBarItem(
              icon: Icon(Icons.home),
              label: 'Market',
            ),
            BottomNavigationBarItem(
              icon: Icon(Icons.add_box_rounded),
              label: 'Add Item',
            ),
            BottomNavigationBarItem(
              icon: Icon(Icons.person),
              label: 'Profile',
            )
          ],
          currentIndex: selectedIndex,
          selectedItemColor: Colors.blue,
          onTap: onItemTapped),
    );
  }

  void onItemTapped(int index) {
    setState(() {
      selectedIndex = index;
    });
  }
}
