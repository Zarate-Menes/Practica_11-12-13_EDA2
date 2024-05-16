/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Edgar
 */
 
//1 ejecuta este ejemplo tal cual
//2 ejecuta este ejemplo agregando la palabra syncronized 
package Ejemplo0;

    class Table{  
    
    synchronized void printTable(int n){        //agrega aqui la palabra synchronized
       for(int i=1;i<=5;i++){  
         System.out.println(n*i);  
         try{  
          Thread.sleep(400);  
         }catch(Exception e){System.out.println(e);}  
       }  
      
     }  
    }  
      
    class MyThread1 extends Thread{  
        Table t;  
        MyThread1(Table t){  
        this.t=t;  
        }  
        public void run(){  
            t.printTable(5);  
    }  
      
    }  
    class MyThread2 extends Thread{  
        Table t;  
        MyThread2(Table t){  
            this.t=t;  
        }  
        public void run(){  
            t.printTable(100);  
        }  
    }  
      
    public class Ejemplo0{  
        public static void main(String args[]){  
            Table obj = new Table();//only one object  
            MyThread1 t1=new MyThread1(obj);  
            MyThread2 t2=new MyThread2(obj);  
            t1.start();  
            t2.start();  
        }  
    }  
    

