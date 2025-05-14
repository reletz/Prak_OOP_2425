public class IPhone extends Device {
    private int batteryLevel;
    
    // Set battery level to 100 on initialization
    public IPhone() {
        super("IPhone");
        this.batteryLevel = 100;
    }
    
    @Override
    // If the battery level is 0, print out "IPhone battery is depleted" return
    // If the device is not connected, print out "IPhone is not connected" return
    // If the device is connected and the battery level is greater than 0, print out "IPhone is nearby! Distance: <batteryLevel> meters away" 
    // and decrease the battery level by 10
    public void locate() {
        if (batteryLevel == 0) {
            System.out.println("IPhone battery is depleted");
            return;
        }
        if (!isConnected()) {
            System.out.println("IPhone is not connected");
            return;
        }
        System.out.println("IPhone is nearby! Distance: " + batteryLevel + " meters away");
        batteryLevel -= 10;
        if (batteryLevel <  0) batteryLevel = 0;
    }
    
    @Override
    // If the battery level is 0, print out "IPhone battery is depleted" return
    // If the device is not connected, print out "IPhone is not connected" return
    // If the device is connected and the battery level is greater than 0, print out "IPhone: *LOUD BEEPING*"
    // and decrease the battery level by 20
    public void makeSound() {
        if (batteryLevel == 0) {
            System.out.println("IPhone battery is depleted");
            return;
        }
        if (!isConnected()) {
            System.out.println("IPhone is not connected");
            return;
        }
        System.out.println("IPhone: *LOUD BEEPING*");
        batteryLevel -= 20;
        if (batteryLevel <  0) batteryLevel = 0;
    }
    
    // Set the battery level to 100
    // Print out "IPhone charged to 100%"
    public void charge() {
        batteryLevel = 100;
        System.out.println("IPhone charged to 100%");
    }
}