import 'package:flutter/material.dart';
import './login.dart';
import 'package:http/http.dart' as http;

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Login(),
    );
  }
}

var darkTheme = ThemeData(
  primarySwatch: Colors.red,
  brightness: Brightness.dark,
);

var lightTheme = ThemeData(
  primarySwatch: Colors.blue,
  brightness: Brightness.dark,
);
