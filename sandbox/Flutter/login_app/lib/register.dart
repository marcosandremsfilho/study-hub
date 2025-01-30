import 'package:flutter/material.dart';
import './login.dart';

class Register extends StatefulWidget {
  @override
  _RegisterState createState() => _RegisterState();
}

class _RegisterState extends State<Register> {
  final emailController = TextEditingController();
  final passwordController = TextEditingController();
  final confirmPasswordController = TextEditingController();
  final formKey = GlobalKey<FormState>();

  bool isPassWordVisible = true;
  bool isConfirmPassWordVisible = true;

  bool teste(String pass, String confirmPass) {
    if (pass == confirmPass) {
      return true;
    }
    return false;
  }

  @override
  void initState() {
    emailController.text = '';
    passwordController.text = '';
    confirmPasswordController.text = '';
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        resizeToAvoidBottomInset: false,
        body: Container(
            width: MediaQuery.of(context).size.width,
            height: MediaQuery.of(context).size.height,
            padding: const EdgeInsets.all(20),
            child: Form(
                key: formKey,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Image.asset('assets/images/UAIRRIOR.png',
                        scale: 13, height: 100),
                    TextFormField(
                      controller: emailController,
                      keyboardType: TextInputType.emailAddress,
                      decoration: const InputDecoration(
                          labelText: 'Email', prefixIcon: Icon(Icons.email)),
                    ),
                    const SizedBox(height: 10),
                    TextFormField(
                      obscureText: isPassWordVisible,
                      autocorrect: false,
                      controller: passwordController,
                      decoration: InputDecoration(
                        labelText: 'Senha',
                        prefixIcon: const Icon(Icons.lock),
                        suffixIcon: IconButton(
                          icon: isPassWordVisible
                              ? const Icon(Icons.visibility)
                              : const Icon(Icons.visibility_off),
                          onPressed: () {
                            setState(() {
                              isPassWordVisible = !isPassWordVisible;
                            });
                          },
                        ),
                      ),
                    ),
                    const SizedBox(height: 10),
                    TextFormField(
                        obscureText: isConfirmPassWordVisible,
                        autocorrect: false,
                        controller: confirmPasswordController,
                        decoration: InputDecoration(
                          labelText: 'Repetir Senha',
                          prefixIcon: const Icon(Icons.lock),
                          suffixIcon: IconButton(
                            icon: isConfirmPassWordVisible
                                ? const Icon(Icons.visibility)
                                : const Icon(Icons.visibility_off),
                            onPressed: () {
                              setState(() {
                                isConfirmPassWordVisible =
                                    !isConfirmPassWordVisible;
                              });
                            },
                          ),
                        ),
                        validator: ((value) {
                          if (passwordController.text !=
                              confirmPasswordController.text) {
                            return 'Senhas não compativeis';
                          }
                          return null;
                        })),
                    const SizedBox(height: 10),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: [
                        SizedBox(
                          width: 100,
                          child: ElevatedButton(
                              style: ElevatedButton.styleFrom(
                                backgroundColor: Colors.blue,
                                foregroundColor: Colors.white,
                              ),
                              onPressed: () {
                                if (formKey.currentState!.validate()) {
                                  ScaffoldMessenger.of(context)
                                      .showSnackBar(const SnackBar(
                                    content: Text("Cadastro feito com sucesso"),
                                    backgroundColor: Colors.green,
                                  ));
                                } else {
                                  ScaffoldMessenger.of(context)
                                      .showSnackBar(const SnackBar(
                                    content: Text("Senhas não compatíveis"),
                                    backgroundColor: Colors.red,
                                  ));
                                }
                              },
                              child: const Text('Register')),
                        ),
                        const SizedBox(width: 10),
                        SizedBox(
                          width: 100,
                          child: ElevatedButton(
                              style: ElevatedButton.styleFrom(
                                backgroundColor: Colors.blue,
                                foregroundColor: Colors.white,
                              ),
                              onPressed: () {
                                Navigator.push(
                                    context,
                                    MaterialPageRoute(
                                        builder: (context) => Login()));
                              },
                              child: const Text('Cancel')),
                        ),
                      ],
                    )
                  ],
                ))));
  }
}
