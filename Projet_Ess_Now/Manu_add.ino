void contonManu(int x) {
  switch (x) {
    case 0:
      Home();
      break;
    case 1:
      Time();
      break;
    case 2:
      Creator();
      break;
    case 3:
      Settings();
      break;
    case 4:
      Sleep();
      break;
  }
}

void Home() {
  p.SF(7);
  p.oled(76, 18, "Home");
  p.show();
  p.SF(2);
  //delay(500);

  while(!btn(3));
  while(btn(3));
}

void Time() {
  //p.show();
  p.SF(7);
  p.oled(76, 18, "Home");
  p.show();
  p.SF(2);

  while(!btn(3));
  while(btn(3));
}

void Creator() {
  //p.show();
  p.SF(7);
  p.oled(76, 18, "Home");
  p.show();
  p.SF(2);

  while(!btn(3));
  while(btn(3));
}

void Setoled_Settings(int x, int y) {
  drawMenu(T1);

  p.SF(1);
  p.oled(73, 9, "Settings");
  //p.show();
  p.SF(8);
  p.set(75, 20);
  p.oled("Anm :"); // H, M, L, N
  p.move(29, 0);
  if(mode[0] == 1) {
    p.oled("H");
  }else if(mode[0] == 2) {
    p.oled("M");
  }else if(mode[0] == 3) {
    p.oled("L");
  }else if(mode[0] == 4) {
    p.oled("N");
  }
  p.move(-29, 0);

  p.move(0, 12);
  p.oled("LED :");
  p.move(29, 0);
  if(mode[1] == 1) {
    p.oled("N");
    outD(4, 1);
  }else if(mode[1] == 0) {
    p.oled("F");
    outD(4, 0);
  }
  p.move(-29, 0);

  p.Pixel(x, y, x, y + 7);
  p.Pixel(x+1, y, x+1, y + 7);

  p.show();
}

void Settings() {
  while(!btn(3)) {
    Setoled_Settings(72, 13 + b);

    if (btn(2) && j != 1) {
      if(mode[0] != 4) {
        for (int i = 0; i >= -12; i -= mode_0[mode[0]]) {   // ✅ แก้ i++ 
          Setoled_Settings(72, (13 + b) - i);
          p.show();
          //delayMicroseconds(500);
        }
      }
      b += 12;
      j++;

      while(btn(2));
    }
    else if (btn(0) && j != 0) {
      if(mode[0] != 4) {
        for (int i = 0; i <= 12; i += mode_0[mode[0]]) {   // ✅ แก้ i++ 
          Setoled_Settings(72, (13 + b) - i);
          p.show();
          //delayMicroseconds(500);
        }
      }
      b -= 12;
      j--;

      while(btn(0));
    }
    
    if(btn(1)) {
      if(j == 0) {
        mode[0] = mode[0] + 1;
        if(mode[0] == 5) {
          mode[0] = 1;
        }
      }else if(j == 1) {
        mode[1] = !mode[1];
      }
      while(btn(1));
    }
  }
  //while(!btn(3));
  while(btn(3));
}

void Sleep() {

  p.clear();
  p.oled(1, 12, "Sleep...");
  p.show();

  while(!btn(3));
  while(btn(3));
}