/**
@author William Tennis
@since 01/22/2015
@version 1.0
Purpose: Workshop_03
**/

import java.text.NumberFormat;
import java.util.Locale;
public class CurrencyConverter
{

   public static void main(String[] args)
   {
      double amountUSD=0;
      double amountEuros=0;
      double conversionRateUSDtoEuros=0;
      double conversionRateEurostoUSD=0;
      double priceOfPorscheUSD=105930;
      double priceOfBmwEuros=51972;
      
      conversionRateEurostoUSD=1.14;
      conversionRateUSDtoEuros=0.88;
      
      amountUSD=priceOfPorscheUSD*conversionRateUSDtoEuros;
      amountEuros=priceOfBmwEuros*conversionRateEurostoUSD;
     
      NumberFormat moneyFormatUSD=NumberFormat.getCurrencyInstance(Locale.US);
      NumberFormat moneyFormatEuros=NumberFormat.getCurrencyInstance(Locale.GERMANY);
      
      System.out.print ("A ");
      System.out.print (moneyFormatUSD.format(priceOfPorscheUSD));
      System.out.print (" Porsche costs ");
      System.out.println (moneyFormatEuros.format(amountEuros));
      System.out.print ("A ");
      System.out.print (moneyFormatEuros.format(priceOfBmwEuros));
      System.out.print (" BMW costs ");
      System.out.println (moneyFormatUSD.format(amountUSD));      
   }
}