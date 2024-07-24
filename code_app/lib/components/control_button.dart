import 'package:flutter/material.dart';
import 'dart:math';

class ControlButton extends StatelessWidget {
  final double externalDiameter;
  final double internalDiameter;
  final Color dividerColor;
  final double elevation;
  final Color externalColor;
  final Color internalColor;
  final Color sideColor;
  final VoidCallback mainAction;
  final VoidCallback up;
  final VoidCallback down;
  final VoidCallback left;
  final VoidCallback right;
  final VoidCallback middle;
  final VoidCallback plus;
  final VoidCallback minus;

  ControlButton({
    required this.externalDiameter,
    required this.internalDiameter,
    required this.dividerColor,
    required this.elevation,
    required this.externalColor,
    required this.internalColor,
    required this.sideColor,
    required this.mainAction,
    required this.up,
    required this.down,
    required this.left,
    required this.right,
    required this.middle,
    required this.plus,
    required this.minus,
  });

  @override
  Widget build(BuildContext context) {
    final double buttonDiameter = externalDiameter / 4;

    return Container(
      width: externalDiameter,
      height: externalDiameter,
      child: Stack(
        alignment: Alignment.center,
        children: [
          // External Circle
          Container(
            width: externalDiameter,
            height: externalDiameter,
            decoration: BoxDecoration(
              color: externalColor,
              shape: BoxShape.circle,
              boxShadow: [
                BoxShadow(
                  color: Colors.black26,
                  blurRadius: elevation,
                ),
              ],
            ),
            child: CustomPaint(
              painter: ControlButtonPainter(dividerColor: dividerColor),
            ),
          ),
          // Internal Circle (Main Action)
          GestureDetector(
            onTap: mainAction,
            child: Container(
              width: internalDiameter,
              height: internalDiameter,
              decoration: BoxDecoration(
                color: internalColor,
                shape: BoxShape.circle,
              ),
              child: Center(
                child: ElevatedButton(
                  onPressed: middle,
                  child: Text('Stop'),
                  style: ElevatedButton.styleFrom(
                    shape: CircleBorder(),
                    padding: EdgeInsets.all(24),
                    fixedSize: Size(internalDiameter, internalDiameter),
                    backgroundColor: internalColor,
                    surfaceTintColor: internalColor,
                  ),
                ),
              ),
            ),
          ),
          // Up, Down, Left, Right, plus, minus Buttons
          _buildButton("Forward", up, 270, buttonDiameter),
          _buildButton("Right", right, 0, buttonDiameter),
          _buildButton("Backward", down, 90, buttonDiameter),
          _buildButton("Left", left, 180, buttonDiameter),
          _buildSideButton("+", plus, 315, buttonDiameter),
          _buildSideButton("-", minus, 225, buttonDiameter),
        ],
      ),
    );
  }

  Widget _buildButton(String text, VoidCallback onTap, double angle, double buttonDiameter) {
    final double radians = angle * pi / 180;

    return Positioned(
      left: externalDiameter / 2 + cos(radians) * (externalDiameter / 2 - buttonDiameter / 2) - buttonDiameter / 2,
      top: externalDiameter / 2 + sin(radians) * (externalDiameter / 2 - buttonDiameter / 2) - buttonDiameter / 2,
      child: GestureDetector(
        onTap: onTap,
        child: Container(
          width: buttonDiameter,
          height: buttonDiameter,
          decoration: BoxDecoration(
            color: externalColor,
            shape: BoxShape.circle,
          ),
          child: Center(child: Text(text)),
        ),
      ),
    );
  }

  Widget _buildSideButton(String text, VoidCallback onTap, double angle, double buttonDiameter) {
    final double radians = angle * pi / 180;

    return Positioned(
      left: externalDiameter / 2 + cos(radians) * (externalDiameter / 2 - buttonDiameter / 2) - buttonDiameter / 2,
      top: externalDiameter / 2 + sin(radians) * (externalDiameter / 2 - buttonDiameter / 2) - buttonDiameter / 2,
      child: GestureDetector(
        onTap: onTap,
        child: Container(
          width: buttonDiameter,
          height: buttonDiameter,
          decoration: BoxDecoration(
            color: sideColor,
            shape: BoxShape.circle,
          ),
          child: Center(child: Text(text)),
        ),
      ),
    );
  }
}

class ControlButtonPainter extends CustomPainter {
  final Color dividerColor;

  ControlButtonPainter({required this.dividerColor});

  @override
  void paint(Canvas canvas, Size size) {
    final Paint paint = Paint()
      ..color = dividerColor
      ..strokeWidth = 2.0
      ..style = PaintingStyle.stroke;

    final double radius = size.width / 2;
    final Offset center = Offset(radius, radius);

    for (int i = 0; i < 4; i++) {
      final double angle = (360 / 4) * i - 45; // Start the first line at -45 degrees
      final double radians = angle * pi / 180;
      final double x = radius + cos(radians) * radius;
      final double y = radius + sin(radians) * radius;
      canvas.drawLine(center, Offset(x, y), paint);
    }
  }

  @override
  bool shouldRepaint(CustomPainter oldDelegate) {
    return false;
  }
}
