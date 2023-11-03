import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

class User {
    private String username;
    private String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}

class Admin {
    private String username;
    private String password;

    public Admin(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}

// Abstract class for Transport
abstract class Transport {
    private String name;
    private String route;

    public Transport(String name, String route) {
        this.name = name;
        this.route = route;
    }

    public String getName() {
        return name;
    }

    public String getRoute() {
        return route;
    }

    public abstract String displayInfo();
}

// Bus class that extends Transport
class Bus extends Transport {
    private int capacity;

    public Bus(String name, String route, int capacity) {
        super(name, route);
        this.capacity = capacity;
    }

    public int getCapacity() {
        return capacity;
    }

    @Override
    public String displayInfo() {
        return "Bus: " + getName() + ", Route: " + getRoute() + ", Capacity: " + getCapacity();
    }
}

// Train class that extends Transport
class Train extends Transport {
    private String type;

    public Train(String name, String route, String type) {
        super(name, route);
        this.type = type;
    }

    public String getType() {
        return type;
    }

    @Override
    public String displayInfo() {
        return "Train: " + getName() + ", Route: " + getRoute() + ", Type: " + getType();
    }
}

// TransportEnquirySystem class
class TransportEnquirySystem {
    private List<Transport> transports;

    public TransportEnquirySystem() {
        transports = new ArrayList<>();
    }

    public void addTransport(Transport transport) {
        transports.add(transport);
    }

    public List<Transport> getTransports() {
        return transports;
    }
}

public class TransportEnquiryManagementSystem {
    private static List<User> users;
    private static List<Admin> admins;
    private static String currentUser;

    public static void main(String[] args) {
        users = new ArrayList<>();
        admins = new ArrayList<>();
        loadUsersAndAdmins();

        // Create a basic Swing GUI for user and admin
        JFrame frame = new JFrame("Transport Enquiry System");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JButton adminLoginButton = new JButton("Admin Login");
        JButton userLoginButton = new JButton("User Login");

        frame.add(adminLoginButton);
        frame.add(userLoginButton);

        adminLoginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (adminLogin()) {
                    // Admin is authenticated, open admin panel
                    openAdminPanel();
                } else {
                    JOptionPane.showMessageDialog(frame, "Admin authentication failed.");
                }
            }
        });

        userLoginButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (userLogin()) {
                    // User is authenticated, open user panel
                    openUserPanel();
                } else {
                    JOptionPane.showMessageDialog(frame, "User authentication failed.");
                }
            }
        });

        frame.setVisible(true);
    }

    private static void loadUsersAndAdmins() {
        // Load user and admin information from a file (e.g., users.txt and admins.txt)
        // Format: username,password
        // Read the file and populate the users and admins lists.
    }

    private static boolean adminLogin() {
        String adminUsername = JOptionPane.showInputDialog("Admin Username:");
        String adminPassword = JOptionPane.showInputDialog("Admin Password:");
        
        for (Admin admin : admins) {
            if (admin.getUsername().equals(adminUsername) && admin.getPassword().equals(adminPassword)) {
                currentUser = adminUsername;
                return true;
            }
        }
        return false;
    }

    private static boolean userLogin() {
        String userUsername = JOptionPane.showInputDialog("User Username:");
        String userPassword = JOptionPane.showInputDialog("User Password:");
        
        for (User user : users) {
            if (user.getUsername().equals(userUsername) && user.getPassword().equals(userPassword)) {
                currentUser = userUsername;
                return true;
            }
        }
        return false;
    }

    private static void openUserPanel() {
        // Implement user panel functionality
        // Allow users to inquire about transport information
        // Display transport details, allow user actions, etc.
    }

    private static void openAdminPanel() {
        // Implement admin panel functionality
        // Allow admins to manage transport information
        // Add, edit, delete transport details, etc.
    }
}
