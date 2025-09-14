#include <UOS.h>

int xy = 0;
int T1 = 30;
bool Manu_on = 0;
int b = 0;
int j = 0;

int intmanu(int y) {
  int x = (-(y * y) * 0.01) + 50;
  return x;
}

int t = 4; // ความยาว manu
// 30 - (10 * t)
// สมมติว่ามี array เมนูเก็บข้อความไว้
const char* manu[] = { // (30 + (-1 * t)) / 10 // สูตรหาเมนู
  "Home",
  "Time",
  "Creator",
  "Settings",
  "Sleep"
};

int mode[2] = {
  2,
  0
};

int mode_0[5] = {
  0,
  1,
  3,
  6,
  0
};

// ฟังก์ชันแสดงเมนู
void drawMenu(int T1) {
  p.SF(2);
  int xy = -(50 - T1);

  p.clear();
  p.set(2, 7);

  for (int i = 0; i <= t; i++) {
    int rt = intmanu(xy);             // คำนวณตำแหน่ง x
    p.set(rt - 30, xy + 30);          // ตั้งตำแหน่ง
    p.oled(manu[i]);                  // แสดงข้อความเมนู
    xy += 10;                         // เลื่อนลง
  }

  if(!Manu_on) {
    p.Pixel(1, 5, 5, 5); // .....
    p.Pixel(1, 6, 7, 6); // .......
    p.Pixel(1, 7, 9, 7); // .........
    p.Pixel(1, 8, 7, 8); // .......
    p.Pixel(1, 9, 5, 9); // .....
  }else {
    for(int i = 0; i <= 128; i++) {
      p.Pixel(70, i);
    }
  }

  // p.oled(95, 12, T1);
  // p.move(0, 12);
  // p.oled(btn(1));
  // p.move(0, 12);
  // p.oled(btn(2));

  //p.show(); // แสดงผลจริงบน OLED
}

void setup() {
  // put your setup code here, to run once:
  p.b(115200, 1106);

  p.text("Hello!!");

  p.SF(2);
  p.clear();
  p.oled(2, 7, "!Hello ESP!");
  p.show();

  delay(1000);

}

void loop() {

  // p.clear();
  // p.set(2, 7);
  // p.oled(!DRead(0, 3));
  // p.move(9, 0);
  // p.oled(!DRead(1, 3));
  // p.move(9, 0);
  // p.oled(!DRead(2, 3));
  // p.move(9, 0);
  // p.oled(!DRead(3, 3));
  // p.show();

  // p.clear();
  // p.set(2, 7);
  // xy = -(50 - T1);

  // for(int i = 0; i <= 10; i++) {
  //   //p.move(0, 12);
  //   int rt = intmanu(xy);
  //   p.set(rt-30, xy+30);
  //   p.oled(manu[i]);

  //   xy += 10;
  // }

  // for(int i = -64; i <= 64; i++) {
  //   int rt = intmanu(i);
  //   p.Pixel(rt-30, i+30);
  // }

  drawMenu(T1);
  p.show();

  //delay(50);

  if (btn(2) || T1 > 30) {              // ปุ่มเลื่อนขึ้น
    if(mode[0] != 4) {
        for (int i = 0; i >= -10; i -= mode_0[mode[0]]) {   // ✅ แก้ i++  
        drawMenu(T1 + i);
        p.show();
        //delayMicroseconds(500);
      }
    }
    T1 -= 10;
    while(btn(2));
  }
  else if (btn(0) || T1 < 30 - (10 * t)) {         // ปุ่มเลื่อนลง
    if(mode[0] != 4) {
        for (int i = 0; i <= 10; i += mode_0[mode[0]]) {   // ✅ แก้ i++ 
        drawMenu(T1 + i);
        p.show();
        //delayMicroseconds(500);
      }
    }
    T1 += 10;
    while(btn(0));
  }
  
  if(btn(1)) {
    while(btn(1));
    Manu_on = 1;
    drawMenu(T1);
    p.show();
    // p.show();
    // delay(1000);
    
    contonManu((30 + (-1 * T1)) / 10);
    p.SF(2);

    Manu_on = 0;
  }

  // put your main code here, to run repeatedly:
  // outD(8, 1);
  // delay(100);
  // outD(8, 0);
  // delay(100);
}
