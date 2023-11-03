import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

// Employee class
class Employee {
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

    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Salary: $" + salary;
    }
}

// PayrollSystem class
class PayrollSystem {
    private List<Employee> employees;

    public PayrollSystem() {
        employees = new ArrayList<>();
    }

    public void addEmployee(int id, String name, double salary) {
        employees.add(new Employee(id, name, salary));
    }

    public List<Employee> getEmployees() {
        return employees;
    }
}

public class PayrollManagementSystem {
    public static void main(String[] args) {
        PayrollSystem payrollSystem = new PayrollSystem();

        // Create a basic Swing GUI
        JFrame frame = new JFrame("Payroll Management System");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JTextField idField = new JTextField(10);
        JTextField nameField = new JTextField(10);
        JTextField salaryField = new JTextField(10);

        JButton addButton = new JButton("Add Employee");
        JButton displayButton = new JButton("Display Employees");

        frame.add(new JLabel("ID: "));
        frame.add(idField);
        frame.add(new JLabel("Name: "));
        frame.add(nameField);
        frame.add(new JLabel("Salary: "));
        frame.add(salaryField);
        frame.add(addButton);
        frame.add(displayButton);

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int id = Integer.parseInt(idField.getText());
                    String name = nameField.getText();
                    double salary = Double.parseDouble(salaryField.getText());

                    payrollSystem.addEmployee(id, name, salary);

                    // Clear input fields
                    idField.setText("");
                    nameField.setText("");
                    salaryField.setText("");

                    JOptionPane.showMessageDialog(frame, "Employee added successfully!");
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Invalid input. Please enter valid data.");
                }
            }
        });

        displayButton.addActionListener(new ActionListener() {
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

        frame.setVisible(true);
    }
}
