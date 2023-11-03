import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

// Abstract class for Employee
abstract class Employee {
    private int id;
    private String name;
    private double salary;

    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public abstract double calculatePay();

    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Salary: $" + salary;
    }
}

// Derived class HourlyEmployee
class HourlyEmployee extends Employee {
    private double hoursWorked;
    private double hourlyRate;

    public HourlyEmployee(int id, String name, double hoursWorked, double hourlyRate) {
        super(id, name, 0);
        this.hoursWorked = hoursWorked;
        this.hourlyRate = hourlyRate;
    }

    @Override
    public double calculatePay() {
        return hoursWorked * hourlyRate;
    }

    @Override
    public String toString() {
        return super.toString() + ", Pay: $" + calculatePay();
    }
}

// PayrollSystem class
class PayrollSystem {
    private List<Employee> employees;

    public PayrollSystem() {
        employees = new ArrayList<>();
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public List<Employee> getEmployees() {
        return employees;
    }

    public void saveEmployeeData(String fileName) {
        try (FileOutputStream fos = new FileOutputStream(fileName);
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(employees);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void loadEmployeeData(String fileName) {
        try (FileInputStream fis = new FileInputStream(fileName);
             ObjectInputStream ois = new ObjectInputStream(fis)) {
            employees = (List<Employee>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

public class PayrollManagementSystem {
    private static final String DATA_FILE = "employee_data.dat";
    private static String currentUserRole;

    public static void main(String[] args) {
        JFrame loginFrame = new JFrame("Login");
        loginFrame.setSize(300, 150);
        loginFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        loginFrame.setLayout(new FlowLayout());

        JRadioButton adminButton = new JRadioButton("Admin");
        JRadioButton userButton = new JRadioButton("User");
        ButtonGroup roleRadioGroup = new ButtonGroup();
        roleRadioGroup.add(adminButton);
        roleRadioGroup.add(userButton);

        JTextField nameField = new JTextField(10);
        JPasswordField passwordField = new JPasswordField(10);
        JButton loginButton = new JButton("Login");

        loginFrame.add(new JLabel("Select Role:"));
        loginFrame.add(adminButton);
        loginFrame.add(userButton);
        loginFrame.add(new JLabel("Name: "));
        loginFrame.add(nameField);
        loginFrame.add(new JLabel("Password: "));
        loginFrame.add(passwordField);
        loginFrame.add(loginButton);

        loginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (adminButton.isSelected()) {
                    if (nameField.getText().equals("admin") && new String(passwordField.getPassword()).equals("admin")) {
                        currentUserRole = "Admin";
                        loginFrame.dispose();
                        openAdminPanel();
                    } else {
                        JOptionPane.showMessageDialog(loginFrame, "Admin authentication failed.");
                    }
                } else if (userButton.isSelected()) {
                    if (nameField.getText().equals("user") && new String(passwordField.getPassword()).equals("user")) {
                        currentUserRole = "User";
                        loginFrame.dispose();
                        openUserPanel();
                    } else {
                        JOptionPane.showMessageDialog(loginFrame, "User authentication failed.");
                    }
                }
            }
        });

        loginFrame.setVisible(true);
    }

    private static void openUserPanel() {
        JFrame userFrame = new JFrame("User Panel");
        userFrame.setSize(600, 400);
        userFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create user-specific GUI components and actions here
        // For example, you can display user details and leave request options

        userFrame.setVisible(true);
    }

    private static void openAdminPanel() {
        JFrame adminFrame = new JFrame("Admin Panel");
        adminFrame.setSize(600, 400);
        adminFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create admin-specific GUI components and actions here
        // For example, you can add buttons for adding employees and handling leave requests

        adminFrame.setVisible(true);
    }
}
