/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Edgar
 */
package Ejemplo2;

import java.io.*; 
import java.util.*; 
  
class Sender 
{ 
    public void send(String msg) 
    { 
        System.out.println("Sending\t"  + msg ); 
        try
        { 
            Thread.sleep(1000); 
        } 
        catch (Exception e) 
        { 
            System.out.println("Thread  interrupted."); 
        } 
        System.out.println("\n" + msg + "Sent"); 
    } 
} 
  
class ThreadedSend extends Thread 
{ 
    private String msg; 
    Sender  sender; 
  

    ThreadedSend(String m,  Sender obj) 
    { 
        msg = m; 
        sender = obj; 
    } 
  
    public void run() 
    { 

        synchronized(sender) 
        { 
            sender.send(msg); 
        } 
    } 
} 
  
public class Syncro 
{ 
    public static void main(String args[]) 
    { 
        Sender snd = new Sender(); 
        ThreadedSend S1 = new ThreadedSend( " Mensaje 1 " , snd ); 
        ThreadedSend S2 = new ThreadedSend( " Mensaje 2 " , snd ); 
  
        S1.start(); 
        S2.start(); 
  
        try
        { 
            S1.join(); 
            S2.join(); 
        } 
        catch(Exception e) 
        { 
            System.out.println("Interrupted"); 
        } 
    } 
} 
    
    
    

