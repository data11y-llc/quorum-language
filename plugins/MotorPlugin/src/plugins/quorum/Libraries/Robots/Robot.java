/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package plugins.quorum.Libraries.Robots;

/**
 *
 * @author sahana
 */

import cbccore.create.CreateConnectException;
import java.util.logging.Level;
import java.util.logging.Logger;
import cbccore.Device;

public class Robot {
    public java.lang.Object $me = null;
    
    cbccore.create.Create r = null;
    cbccore.create.CliffState c;
    cbccore.create.CreateConnectException e;
    
    private int rightCliff;
    private int rightFrontCliff;
    private int leftCliff;
    private int leftFrontCliff;
    private int rightCliffAmount;
    private int rightFrontCliffAmount;
    private int leftCliffAmount;
    private int leftFrontCliffAmount;
            
    public void SetConnection() //throws CreateConnectException
    {
        try {
            r = new cbccore.create.Create();
            r.connect();
        } catch (CreateConnectException ex) {
            Logger.getLogger(Robot.class.getName()).log(Level.SEVERE, null, ex);
          
        }
        c = new cbccore.create.CliffState(rightCliff, rightFrontCliff, leftCliff, leftFrontCliff, rightCliffAmount, rightFrontCliffAmount, leftCliffAmount, leftFrontCliffAmount);
       
        RuntimeException runtimeException = new RuntimeException("Compiled Code");
        
    }

    public void Disconnect()
    {              
        r.disconnect();
    }
 
    public void StopWheels()
    {
        r.stop();
    }
    
    public void MoveStraight(int speed)
    {
        r.driveStraight(speed);
    }
    
    public void MoveStraight(int speed, double distance)
    {
        //distance = distance * 1000;
        while(r.getDistance() < distance)
            r.driveStraight(speed);
    }
    
    public void MoveWithRightLeftSpeed(int rspeed, int lspeed)
    {
        r.driveDirect(rspeed, lspeed);
    }
    
     public void MoveAsCurve(int speed, int radius)
    {
        r.drive(speed, radius);
    }
    
    public int TurnLeft(int angle, int speed) //work on this angle part     
    {
        int initialangle = r.getAngle(); 
        angle = (int)(angle * 2.64);
        int i = angle * -1;
        r.driveDirect(angle, i);
        return (r.getAngle() - initialangle);
    }
    
    public int TurnRight(int angle, int speed)  //work on this angle part   
    {
        int initialangle = r.getAngle(); 
        angle = (int)(angle * 2.64);
        int i = angle * -1;
        r.driveDirect(i, angle);
        return (r.getAngle() - initialangle);
    }
    
    public boolean IsLeftBumperpressed(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_lbump(lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
   
    public boolean IsRightBumperpressed(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_rbump(lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public boolean IsCenterWheelDropped(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_cwdrop (lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public boolean IsLeftWheelDropped(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_lwdrop(lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public boolean IsRightWheelDropped(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_rwdrop (lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public void TurnClockwise(int speed)
    {
        r.spinCW(speed);
    }
    
    public void TurnCounterClockwise(int speed)
    {
        r.spinCCW(speed);
    }
    
    public int IsLeftSensorTriggered()
    {
        return c.getLeftCliff();
    }
    
    public int IsRightSensorTriggered()
    {
        return c.getRightCliff();
    }
    
    public int IsLeftFrontSensorTriggered()
    {
        return c.getLeftFrontCliff();
    }
    
    public int IsRightFrontSensorTriggered()
    {
        return c.getRightFrontCliff();
    }
}
    
    
    
    
    /*cbccore.low.Create r; 
     
    public void SetConnection() 
    {
        r = new cbccore.low.Create();
        r.create_connect();
        //if (create_connect == 0)
          //  System.out.println("Connection successfull.");
        //else
          //  System.out.println("Not Connected.");
    }
    
    public void Disconnect()
    {              
        r.create_disconnect();
    }
 
    public void StopWheels()
    {
        r.create_stop();
    }
    
    public void MoveStraight(int speed)
    {
        r.create_drive_straight(speed);
    }
    
    public void MoveAsCurve(int speed, int radius)
    {
        r.create_drive(speed, radius);
    }
    
    public void RotateClockwise(int speed)
    {
        r.create_spin_CW(speed);
    }
    
    public void RotateCounterClockwise(int speed)
    {
        r.create_spin_CCW(speed);
    }
    
    public int IsLeftSensorTriggered(float lag)
    {
        return r.get_create_lcliff(lag);
    }
    
    public int IsRightSensorTriggered(float lag)
    {
        return r.get_create_rcliff(lag);
    }
    
    public int IsLeftFrontSensorTriggered(float lag)
    {
        return  r.get_create_lfcliff(lag);
    }
    
    public int IsRightFrontSensorTriggered(float lag)
    {
        return r.get_create_lfcliff(lag);
    }
    
    public int IsLeftBumperPressed(float lag)
    {   
        return r.get_create_lbump(lag);
    }
    
    public int IsRighttBumperPressed(float lag)
    {   
        return r.get_create_rbump(lag);
    }
}*/



//cbccore.create.Create r;
//cbccore.create.CliffState c;
    //cbccore.create.CreateConnectException e;
    
    /*private int rightCliff;
    private int rightFrontCliff;
    private int leftCliff;
    private int leftFrontCliff;
    private int rightCliffAmount;
    private int rightFrontCliffAmount;
    private int leftCliffAmount;
    private int leftFrontCliffAmount;*/
            
    /*public void SetConnection() //throws CreateConnectException
    {
        try {
            r = new cbccore.create.Create();
        } catch (CreateConnectException ex) {
            Logger.getLogger(Robot.class.getName()).log(Level.SEVERE, null, ex);
          
    }
        c = new cbccore.create.CliffState(rightCliff, rightFrontCliff, leftCliff, leftFrontCliff, rightCliffAmount, rightFrontCliffAmount, leftCliffAmount, leftFrontCliffAmount);
        try {
            r.connect();
        } catch (CreateConnectException ex) {
            Logger.getLogger(Robot.class.getName()).log(Level.SEVERE, null, ex);
        }
        RuntimeException runtimeException = new RuntimeException("Compiled Code");
        //r.driveDirect(250, 250);
    }*/
/*
 public void Disconnect()
    {              
        r.disconnect();
    }
 
    public void StopWheels()
    {
        r.stop();
    }
    
    public void MoveStraight(int speed)
    {
        r.driveStraight(speed);
    }
    
    public void MoveAsCurve(int speed, int radius)
    {
        r.drive(speed, radius);
    }
    
    public void RotateClockwise(int speed)
    {
        r.spinCW(speed);
    }
    
    public void RotateCounterClockwise(int speed)
    {
        r.spinCCW(speed);
    }
    
    public int IsLeftSensorTriggered()
    {
        return c.getLeftCliff();
    }
    
    public int IsRightSensorTriggered()
    {
        return c.getRightCliff();
    }
    
    public int IsLeftFrontSensorTriggered()
    {
        return c.getLeftFrontCliff();
    }
    
    public int IsRightFrontSensorTriggered()
    {
        return c.getRightFrontCliff();
    }
}

 */