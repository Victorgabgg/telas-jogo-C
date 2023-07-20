#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define ESC    	27

int GlbLar, GlbAlt;
int GlbBtnLar, GlbBtnAlt;

void TelaInicial();
void Creditos();
void Jogo();
void Tutorial();
void Gameover();


int main() {
  GlbLar = 1126.0;
  GlbAlt = 633.0;
  GlbBtnLar = 250;
  GlbBtnAlt = 80;

  initwindow(GlbLar, GlbAlt, "Empire Ablaze", 10, 10);
  TelaInicial();

  closegraph();
  return(0);
}

void TelaInicial() {
  bool Fim = false;
  int pg = 1;
  POINT P;
  HWND janela;
  
  bool btnJogarSelecionado = false; 
  bool btnCreditosSelecionado = false; 
  bool btnSairSelecionado = false;
  bool btnTutorialSelecionado = false;
  //bool btnGameoverSelecionado = false;

  int tam;
  void *Fundo;
  void *btnJogar, *btnJogarSel;
  void *btnCreditos, *btnCreditosSel;
  void *btnSair, *btnSairSel;
  void *btnTutorial, *btnTutorialSel;
  

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\telainicial.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);


  cleardevice();
  tam = imagesize(0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  btnJogar = malloc(tam);
  readimagefile(".\\imagens\\btnjogar.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogar);
  btnJogarSel = malloc(tam);
  readimagefile(".\\imagens\\btnjogarsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogarSel);


  btnTutorial = malloc(tam);
  readimagefile(".\\imagens\\btntutorial.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnTutorial);
  btnTutorialSel = malloc(tam);
  readimagefile(".\\imagens\\btntutorialsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnTutorialSel);
  
  
  btnCreditos = malloc(tam);
  readimagefile(".\\imagens\\btncreditos.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditos);
  btnCreditosSel = malloc(tam);
  readimagefile(".\\imagens\\btncreditossel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditosSel);
  btnSair = malloc(tam);
  readimagefile(".\\imagens\\btnsair.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSair);
  btnSairSel = malloc(tam);
  readimagefile(".\\imagens\\btnsairsel.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSairSel);
  
  
  janela = GetForegroundWindow(); 
  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    if (btnJogarSelecionado)
      putimage(700, 200, btnJogarSel, COPY_PUT); 
    else
      putimage(700, 200, btnJogar, COPY_PUT);
      
    if (btnTutorialSelecionado)
      putimage(700, 300, btnTutorialSel, COPY_PUT);
    else
      putimage(700, 300, btnTutorial, COPY_PUT);
      
    if (btnCreditosSelecionado)
      putimage(700, 400, btnCreditosSel, COPY_PUT);
    else
      putimage(700, 400, btnCreditos, COPY_PUT);
    if (btnSairSelecionado)
      putimage(700, 500, btnSairSel, COPY_PUT);
    else
      putimage(700, 500, btnSair, COPY_PUT);
    setvisualpage(pg);
    
    if (GetCursorPos(&P)) 
      if (ScreenToClient(janela, &P)) { 
  
        btnJogarSelecionado = false; 
        if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 200 <= P.y && P.y <= 200+GlbBtnAlt-1)
          btnJogarSelecionado = true;
          
          btnTutorialSelecionado = false; 
        if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 300 <= P.y && P.y <= 300+GlbBtnAlt-1)
          btnTutorialSelecionado = true;
          
        btnCreditosSelecionado = false; 
        if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 400 <= P.y && P.y <= 400+GlbBtnAlt-1)
          btnCreditosSelecionado = true;
        btnSairSelecionado = false; 
        if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 500 <= P.y && P.y <= 500+GlbBtnAlt-1)
          btnSairSelecionado = true;
         
        if(GetKeyState(VK_LBUTTON)&0x80) {

          if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 200 <= P.y && P.y <= 200+GlbBtnAlt-1)
            Jogo();
            
           else if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 300 <= P.y && P.y <= 300+GlbBtnAlt-1)
            Tutorial(); 
            
          else if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 400 <= P.y && P.y <= 400+GlbBtnAlt-1)
            Creditos();
            
          else if (5 <= P.x && P.x <= 5+GlbBtnLar-1 && 5 <= P.y && P.y <= 5+GlbBtnAlt-1)
          	Gameover();

          else if (700 <= P.x && P.x <= 700+GlbBtnLar-1 && 500 <= P.y && P.y <= 500+GlbBtnAlt-1)
            Fim = true;
        }
      }
  }  
}

void Creditos() {
  void *btnsim, *btnnao; 
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\creditos.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
    }
  }
}

void Tutorial() {
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\tutorials.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
    }
  }
}


void Gameover() {
  POINT P;
  HWND janela;
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;
  void *btnsim, *btnnao; 

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\gameover.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  
  
  //Lendo
  cleardevice();
  btnsim = malloc(tam);
  readimagefile(".\\imagens\\yes.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnsim);
  btnsim = malloc(tam);
  readimagefile(".\\imagens\\yes.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnsim);
  
  
  btnnao = malloc(tam);
  readimagefile(".\\imagens\\no.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnnao);
  btnnao = malloc(tam);
  readimagefile(".\\imagens\\no.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnnao);
  



 janela = GetForegroundWindow(); 
  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
	    setactivepage(pg);
	    putimage(0, 0, Fundo, COPY_PUT);
	    putimage(300, 450, btnsim, COPY_PUT); 
	    putimage(570, 450, btnnao, COPY_PUT); 
	    setvisualpage(pg);

	      
	//Pegar o clique (Não funcionando)	
	if (GetCursorPos(&P)) 
      if (ScreenToClient(janela, &P)) { 
      if(GetKeyState(VK_LBUTTON)&0x80) {
      	 if (300 <= P.x && P.x <= 300+GlbBtnLar-1 && 450 <= P.y && P.y <= 450+GlbBtnAlt-1)
      	 Jogo();

   		else if (570 <= P.x && P.x <= 570+GlbBtnLar-1 && 450 <= P.y && P.y <= 450+GlbBtnAlt-1)
    		Fim = true;
    }}
    }
  }


void Jogo() {
  int pg = 1;
  char tecla = 0;
  char s[50];
  int  x, y, raio;
  double passox, passoy;
  x = 100;
  y = 100;
  raio = 18; 
  passox = 3;
  passoy = 1;
  strcpy(s, "pressione Esc para Sair");

  while(tecla != ESC) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);

    cleardevice();
    setcolor(RGB(255, 50, 50));
    rectangle(10, 10, GlbLar-11, GlbAlt-31);

    setfillstyle(1, YELLOW);
    setcolor (YELLOW);
    fillellipse(x, y, raio, raio);

    setbkcolor(RGB(75, 75, 75));
    setcolor(RGB(255, 155, 155));
    outtextxy(12, GlbAlt-25, s);

    setvisualpage(pg);

    x = x + passox; 
    if (x <= 10+raio || x >= GlbLar-31-raio) 
      passox = -passox;
    y = y + passoy;
    if (y <= 10+raio || y >= GlbAlt-31-raio)
      passoy = -passoy;

    delay(5);

    fflush(stdin);
    if (kbhit())
      tecla = getch();   
  }
}
