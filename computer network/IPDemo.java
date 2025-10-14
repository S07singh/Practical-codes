import java.net.*;
import java.util.*;

public class IPDemo {
    public static void main(String[] args) {
        String host;
        Scanner ch = new Scanner(System.in);
        System.out.print("1. Enter Host Name\n2. Enter IP Address\nChoice = ");
        int choice = ch.nextInt();
        ch.nextLine(); // consume leftover newline

        if (choice == 1) {
            System.out.print("\nEnter host name: ");
            host = ch.nextLine();
            try {
                InetAddress address = InetAddress.getByName(host);
                System.out.println("IP Address: " + address.getHostAddress());
                System.out.println("Host Name : " + address.getHostName());
                System.out.println("Host + IP : " + address.toString());
            } catch (UnknownHostException ex) {
                System.out.println("Could not find " + host);
            }
        } else {
            System.out.print("\nEnter IP address: ");
            host = ch.nextLine();
            try {
                InetAddress address = InetAddress.getByName(host);
                System.out.println("Host Name : " + address.getHostName());
                System.out.println("IP Address: " + address.getHostAddress());
                System.out.println("Host + IP : " + address.toString());
            } catch (UnknownHostException ex) {
                System.out.println("Could not find " + host);
            }
        }
    }
}
