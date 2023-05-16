let mic;
let shapeType;

function setup() {
  createCanvas(1000, 1000);
  colorMode(HSB, 360, 100, 100, 1);
  mic = new p5.AudioIn();
  mic.start();
  shapeType = 0;
}

function draw() {
  background(0);
  noFill();

  translate(width / 2, height / 2);

  // Get the current input level from the microphone
  let level = mic.getLevel();

  for (let i = 0; i < 200; i++) {
    push();

    // Rotate the shape based on the input level
    let rotation = sin(frameCount + i) * 150 * level;
    rotate(rotation);

    // Determine the shape based on the current time
    let shapeSize = map(level, 0, 1, 50 + sin(frameCount/50)*50, 500 - i * 2);
    let shapeAngle = map(level, 0, 1, 0, 2 * PI);
    let shapeX = cos(frameCount / 50 + i) * 200;
    let shapeY = sin(frameCount / 50 + i) * 200;
    let shapeColor = color(map(sin(frameCount / 200), -1, 1, 220, 360), map(sin(frameCount / 100), -1, 1, 30, 70), map(sin(frameCount / 50), -1, 1, 30, 80));

    switch (shapeType) {
      case 0:
        // Draw a rectangle
        strokeWeight(map(level, 0, 1, 2, 20));
        stroke(shapeColor);
        rectMode(CENTER);
        rect(shapeX, shapeY, shapeSize, shapeSize, 50 + i / 2);
        break;
      case 1:
        // Draw a circle
        strokeWeight(map(level, 0, 1, 2, 20));
        stroke(shapeColor);
        ellipseMode(CENTER);
        ellipse(shapeX, shapeY, shapeSize, shapeSize);
        break;
      case 2:
        // Draw a triangle
        strokeWeight(map(level, 0, 1, 2, 20));
        stroke(shapeColor);
        triangle(shapeX, shapeY, shapeX + shapeSize, shapeY + shapeSize, shapeX - shapeSize, shapeY + shapeSize);
        break;
      case 3:
        // Draw a line
        strokeWeight(map(level, 0, 1, 2, 20));
        stroke(shapeColor);
        line(shapeX, shapeY, shapeX + shapeSize, shapeY + shapeSize);
        break;
      default:
        break;
    }

    pop();
  }

}