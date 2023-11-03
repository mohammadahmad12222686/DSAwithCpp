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

    public boolean deleteEmployee(int id) {
        for (Employee employee : employees) {
            if (employee.getId() == id) {
                employees.remove(employee);
                return true;
            }
        }
        return false;
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
    private static PayrollSystem payrollSystem;

    public static void main(String[] args) {
        payrollSystem = new PayrollSystem();
        payrollSystem.loadEmployeeData(DATA_FILE);

        JFrame frame = new JFrame("Payroll Management System");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JTextField idField = new JTextField(10);
        JTextField nameField = new JTextField(10);
        JTextField hoursWorkedField = new JTextField(10);
        JTextField hourlyRateField = new JTextField(10);

        JButton addHourlyEmployeeButton = new JButton("Add Hourly Employee");
        JButton displayEmployeesButton = new JButton("Display Employees");
        JButton deleteEmployeeButton = new JButton("Delete Employee");
        JButton saveDataButton = new JButton("Save Employee Data");

        frame.add(new JLabel("ID: "));
        frame.add(idField);
        frame.add(new JLabel("Name: "));
        frame.add(nameField);
        frame.add(new JLabel("Hours Worked: "));
        frame.add(hoursWorkedField);
        frame.add(new JLabel("Hourly Rate: "));
        frame.add(hourlyRateField);
        frame.add(addHourlyEmployeeButton);
        frame.add(displayEmployeesButton);
        frame.add(deleteEmployeeButton);
        frame.add(saveDataButton);

        addHourlyEmployeeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int id = Integer.parseInt(idField.getText());
                    String name = nameField.getText();
                    double hoursWorked = Double.parseDouble(hoursWorkedField.getText());
                    double hourlyRate = Double.parseDouble(hourlyRateField.getText());

                    Employee hourlyEmployee = new HourlyEmployee(id, name, hoursWorked, hourlyRate);
                    payrollSystem.addEmployee(hourlyEmployee);

                    idField.setText("");
                    nameField.setText("");
                    hoursWorkedField.setText("");
                    hourlyRateField.setText("");

                    JOptionPane.showMessageDialog(frame, "Hourly Employee added successfully!");
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Invalid input. Please enter valid data.");
                }
            }
        });

        displayEmployeesButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                List<Employee> employees = payrollSystem.getEmployees();
                StringBuilder employeeInfo = new StringBuilder("Employees:\n");

                for (Employee employee : employees) {
                    employeeInfo.append(employee.toString()).append("\n");
                }

                JTextArea textArea = new JTextArea(10, 30);
                textArea.setText(employeeInfo.toString());
                textArea.setEditable(false);

                JScrollPane scrollPane = new JScrollPane(textArea);
                JOptionPane.showMessageDialog(frame, scrollPane, "Employee List", JOptionPane.INFORMATION_MESSAGE);
            }
        });

        deleteEmployeeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int id = Integer.parseInt(idField.getText());
                    boolean deleted = payrollSystem.deleteEmployee(id);

                    if (deleted) {
                        JOptionPane.showMessageDialog(frame, "Employee deleted successfully!");
                    } else {
                        JOptionPane.showMessageDialog(frame, "Employee with ID " + id + " not found.");
                    }

                    idField.setText("");
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a valid ID.");
                }
            }
        });

        saveDataButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                payrollSystem.saveEmployeeData(DATA_FILE);
                JOptionPane.showMessageDialog(frame, "Employee data saved successfully!");
            }
        });

        frame.setVisible(true);
    }
}
