/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;
import javax.swing.JFileChooser;

/**
 *
 * @author Howtoon
 */
public class Client{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String fileName;    // Name of CSV File to be parsed
        double salaryLimit = 0;    // Salary limit to be calculated
        boolean isDone = false;     //boolean for controlling whether input is complete or not
        Scanner file = null;         //Scanner to read the data from the file
        Scanner kb = new Scanner(System.in);    //Scanner for keyboard input
        ArrayList<Employee> allEmployees = new ArrayList<>();
        HashMap<String, ArrayList<Employee>> groups = new HashMap<>(); //Key value pair to organize lists of employees by role
        double totalSalary = 0;


        do{
            System.out.print("Enter the absolute path of the CSV file\nOr press <Enter> to browse and select a file:");
            fileName = kb.nextLine();       // Get the absolute path of the CSV File
            if (fileName.compareToIgnoreCase("")==0) //if the user presses enter with no input, the file chooser dialog will open
            {
                JFileChooser chooser = new JFileChooser();
                int returnVal = chooser.showOpenDialog(null);
                if(returnVal == JFileChooser.APPROVE_OPTION) {
                    fileName = chooser.getSelectedFile().getAbsolutePath();
                    System.out.println("You selected: " +
                    chooser.getSelectedFile().getName());
                    isDone = true;
                }
                else{
                    System.out.println("You chose to cancel. Goodbye.");
                    System.exit(0);
                }
            }
            try{
                file = new Scanner(new File(fileName));
                isDone = true;  //the file path was valid
            }
            catch(FileNotFoundException e)
            {
                System.out.println("File "+ fileName + " Not Found.");
            }
        }
        while(!isDone);
        isDone = false;
        do{
            System.out.print("\nEnter the salary limit: ");   //promt the user for input
            try{
                salaryLimit = Double.parseDouble(kb.nextLine());
                isDone = true;  //the salary limit was valid
            }
            catch(Exception e)      //if an error is made when entering the salary limit
            {
                //error message
                System.out.println("You did not enter a valid numerical value, Please try again.");
            }
        }
        while(!isDone);
        
        while(file.hasNextLine())
        {
            String data = file.nextLine();  //get the next line from the CSV file
            StringTokenizer tokens = new StringTokenizer(data, ",");    //create a tokenizer to read the CSV line
            String name = tokens.nextToken();   //first entry should be the name
            String dob = tokens.nextToken();    //then date of birth
            double salary = Double.parseDouble(tokens.nextToken()); //then the annual salary
            totalSalary += salary;      //add the new salary to the total of all salaries
            String role = tokens.nextToken();   //then the role of the new employee
            Employee newGuy = new Employee(name, dob, salary, role);    //create the new employee object
            allEmployees.add(newGuy);   //add the new employee to the master list of employees
            if (groups.containsKey(newGuy.getRole()))   // if the role of this employee already exists
            {
                groups.get(newGuy.getRole()).add(newGuy);   //add the new guy to the existing list
            }
            else    //if the role does not exist
            {
                ArrayList<Employee> newList = new ArrayList<>();    //create a new list
                newList.add(newGuy);
                groups.put(newGuy.getRole(), newList);          //put the new list into the map of roles using the new role as the key
            }
        }
        
        System.out.print("\n\nThe total salary for all employees is:\n");

        printTotals(totalSalary);       //prints the totals based on time breakdown (year, month, day, etc.)
        
        System.out.println("The total salary per role:\n");
        
        for (Map.Entry<String, ArrayList<Employee>> entry : groups.entrySet()) 
        {
            double total = 0;       //tally variable
            for (Employee i : entry.getValue()) //iterate over the array
            {
                total += i.getSalary();     //tally up the total
            }
            
            System.out.print(entry.getKey() + ":\n");   //print the name of the role
            printTotals(total);     //prints the totals based on time breakdown (year, month, day, etc.)
        }
        
        System.out.println("These are all groupings of employees whose sum of annual salary\n are as close to the salary limit (without going over)");
        printAllSets(allEmployees, salaryLimit);  //prints all the sets that are possible without going over and without being able to add more employees
    }
    
    /**
     * Prints the largest possible sets of employees without going over budget
     * @param allEmployees
     * @param salaryLimit 
     */
    private static void printAllSets(ArrayList<Employee> allEmployees, double salaryLimit)
    {
        HashSet<HashSet<Employee>> setsOfEmployees = new HashSet<>();   //create a master set of sets
        for (int i = 0; i<allEmployees.size(); i++) //start from the first position
        {   
            ArrayList<Employee> set = new ArrayList<>();    //set to build on
            ArrayList<Employee> compSet = new ArrayList<>();    //set to compare to
            int total = 0;                                      //tally variable
            if (allEmployees.get(i).getSalary() <= salaryLimit)  //check if the element being tested can be added
            {
                set.add(allEmployees.get(i));           //add it to the set
                total += allEmployees.get(i).getSalary();   //add to the tally
            }
            else            //if it cannot be added, goto the next element
            {
                continue;
            }
            compSet.addAll(allEmployees);           //create the comparison set
            compSet.remove(allEmployees.get(i));    //remove the element that is being tested from the comparison set
            int k = i+1;                            //start at the next element (this is the index variable)
            for (int j = 0; j < compSet.size(); j++) {  //compare the test element to all other elements
                if (k > compSet.size() - 1)         //if the end of the array is reached, start at the beginning
                {
                    k = 0;          
                }
                if (total + compSet.get(k).getSalary() <= salaryLimit)  //check if the comparison element can be added
                {
                    set.add(compSet.get(k));        //add the comarison element
                    if (setsOfEmployees.contains(new HashSet<>(set)))     //check if the master set of sets already contains this set
                    {
                        set.remove(compSet.get(k));     //if the master set of sets already contains this set, then remove the last entry and move on
                    }
                    else
                    {
                        total += compSet.get(k).getSalary();        //add to the tally the total
                        compSet.remove(compSet.get(k));         //remove the variable that has been added so it does not get compared again
                        j--;        //decrement the counter variable to account for the removed element
                    }
                }
                k++;        //increment the index variable
            }
            if (!setsOfEmployees.contains(new HashSet<>(set)))
            {
                boolean isSubset = false;       //set a boolean to test for subsets
                for (HashSet<Employee> masterSet : setsOfEmployees) //interate through the master set of sets
                {
                    if (masterSet.containsAll(set)) //check if the new set is a sub set of another set
                    {
                        isSubset = true;
                    }
                }
                if (!isSubset)      //if it is not a subset of another set, then add it to the master set of sets
                {
                    setsOfEmployees.add(new HashSet<>(set));
                    System.out.println(set);    //print the set because it is unique
                }
            }
        }
    }
    
    /**
     * Prints the break down from annual salary to monthly, weekly, daily, etc.
     * @param total 
     */
    private static void printTotals(double total)
    {
        System.out.print("per year\t");
        System.out.printf("%.2f\n",total);

        System.out.print("per month\t");
        System.out.printf("%.2f\n",(total/12));

        System.out.print("per week\t");
        System.out.printf("%.2f\n",(total/52));

        System.out.print("per day\t\t");
        System.out.printf("%.2f\n",(total/(52*5)));

        System.out.print("per hour\t");
        System.out.printf("%.2f\n",(total/(52*5*8)));

        System.out.print("per minute\t");
        System.out.printf("%.2f\n\n",(total/(52*5*8*60)));
    }
    
    /**
     * Employee object hold ass information about an employee
     */
    private static class Employee
    {
        private String name;    //Employee's name
        private String dob;     //date of birth
        private double salary;  //annual salary
        private String role;    //role in the company

        /**
         * Creates an employee object
         * @param name
         * @param dob
         * @param salary
         * @param role 
         */
        public Employee(String name, String dob, double salary, String role)
        {
            this.name = name;
            this.dob = dob;
            this.salary = salary;
            this.role = role;
        }
        
        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getDob() {
            return dob;
        }

        public void setDob(String dob) {
            this.dob = dob;
        }

        public double getSalary() {
            return salary;
        }

        public void setSalary(double salary) {
            this.salary = salary;
        }

        public String getRole() {
            return role;
        }

        public void setRole(String role) {
            this.role = role;
        }
        
        @Override
        public String toString()
        {
            return role + " " + name + " " + salary; 
        }
    }
}
