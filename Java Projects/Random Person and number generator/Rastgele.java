/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Paket;

/**
*
* @author Emrullah
* @since 25/04/2020
* rastgeleleği sağlıyan fonksiyon
*/
public class Rastgele {
    
       static long a = System.currentTimeMillis();
    
        public int rastgele(int limit){
         
           a = (a * 125) % 2796203;
           return (int) ((a % limit) + 1);
        }   
        
}
