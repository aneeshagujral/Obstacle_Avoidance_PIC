#define ir1 PORTB.B6

#define ir2 PORTB.B7

#define ir3 PORTD.B7

#define m11 PORTB.B0

#define m12 PORTB.B1

#define e1 PORTB.B2

#define m21 PORTB.B3

#define m22 PORTB.B4

#define e2 PORTB.B5

void init()

{

      TRISB.B6=1;    //ir1 (left) as input

      TRISB.B7=1;    //ir2 (centre) as input

      TRISD.B7=1;    // ir3 (right) as input

      TRISB.B0=0;    // m11 as output

      TRISB.B1=0;    // m12 as output

      TRISB.B2=0;    // e1 as output

      TRISB.B3=0;    // m21 as output

      TRISB.B4=0;    //m22 as output

      TRISB.B5=0;    // e2 as output

}

void forward()

{

 m11=1;

 m12=0;

 m21=1;

 m22=0;

 e1=1;

 e2=1;

}

void back()

{

 m11=0;

 m12=1;

 m21=0;

 m22=1;

 e1=1;

 e2=1;

}

void right()

{

 m11=1;

 m12=0;

 m21=0;

 m22=0;

 e1=1;

 e2=0;

}

void left()

{

 m11=0;

 m12=0;

 m21=1;

 m22=0;

 e1=0;

 e2=1;

}

void stop()

{

           m11=0;

           m12=0;

           e1=0;

           m21=0;

           m22=0;

           e2=0;

}

 void main()

 {

 init();

  while(1)

  {

   if((ir1==0) && (ir2==0) && (ir3==0))

           {

           forward();

           }

   else if((ir1==0) && (ir2==0) && (ir3==1))

           {

           forward();

           }

   else if((ir1==0) && (ir2==1) && (ir3==0))

 {

           back();

           Delay_ms(700);

           stop();

           Delay_ms(1500);

           right();

           Delay_ms(700);

 }

  else if((ir1==0) && (ir2==1) && (ir3==1))

 {

           back();

           Delay_ms(700);

           stop();

           Delay_ms(1500);

           left();

           Delay_ms(700);

 }

  else if((ir1==1) && (ir2==0) && (ir3==0))

           {

           forward();

           }

  else if((ir1==1) && (ir2==0) && (ir3==1))

           {

           forward();

           }

  else if((ir1==1) && (ir2==1) && (ir3==0))

 {

           back();

           Delay_ms(700);

           stop();

           Delay_ms(1500);

           right();

           Delay_ms(700);

 }

  else if( (ir1==1) && (ir2==1) && (ir3==1))

{

           back();

           Delay_ms(700);

           stop();

 }

 else

 {

 forward();

 }

 }

 }