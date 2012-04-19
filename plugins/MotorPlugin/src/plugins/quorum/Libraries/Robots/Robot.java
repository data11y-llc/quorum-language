/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package plugins.quorum.Libraries.Robots;

/**
 *
 * @author sahana
 */

import cbccore.create.Create;
import cbccore.create.CreateConnectException;
import java.util.logging.Level;
import java.util.logging.Logger;
import cbccore.Device;

public class Robot {
    public java.lang.Object $me = null;
    
    cbccore.create.Create r = null;
    //cbccore.create.CliffState c;
    //cbccore.create.CreateConnectException e;
   // cbccore.create.Create.Mode m;
                    
    /*enum Mode {
        Full, Passive, Safe, Off;
    };*/
    
    private int rightCliff;
    private int rightFrontCliff;
    private int leftCliff;
    private int leftFrontCliff;
    private int rightCliffAmount;
    private int rightFrontCliffAmount;
    private int leftCliffAmount;
    private int leftFrontCliffAmount;
            
    public void Connect() 
    {
        try {
            r = new cbccore.create.Create();
            r.connect();
        } catch (CreateConnectException ex) {
            Logger.getLogger(Robot.class.getName()).log(Level.SEVERE, null, ex);
          
        }
        //c = new cbccore.create.CliffState(rightCliff, rightFrontCliff, leftCliff, leftFrontCliff, rightCliffAmount, rightFrontCliffAmount, leftCliffAmount, leftFrontCliffAmount);
       
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
    
    public void MoveStraight(double speed)
    {
        int speed_int = (int)(speed * 500);
        r.driveStraight(speed_int);
    }
    
    public void MoveStraight(double speed, double distance)
    {
        int speed_int = (int)(speed * 500);
        distance = distance * 1000;
        while(r.getDistance() < distance)
            r.driveStraight(speed_int);
    }
    
    public void MoveWheels(double rightspeed, double leftspeed)
    {
        int rspeed =(int)(rightspeed * 500);
        int lspeed =(int)(leftspeed * 500);
        r.driveDirect(rspeed, lspeed);
    }
    
     public void MoveInCirle(double speed, double radius)
    {
        int radius_int = (int) (radius * 1000);
        int speed_int = (int)(speed * 500);
        r.drive(speed_int, radius_int);
    }
    
    public void TurnLeft(double turn, double speed)     
    {   
        int speed_int = (int)(speed * 500);
        int angle = (int)(turn * 360);
        int finalangle = Device.getLowCreateController().get_create_total_angle(0) + angle;
        int speedneg = speed_int * -1;
        while (Device.getLowCreateController().get_create_total_angle(0) < finalangle)
	{
           r.driveDirect(speed_int, speedneg);
        }
    }
    
    public void TurnRight(double turn, double speed)     
    {
        int speed_int = (int)(speed * 500);
        int angle = (int)(turn * 360);
        int finalangle = Device.getLowCreateController().get_create_total_angle(0) - angle;
        int speedneg = speed_int * -1;
        while (Device.getLowCreateController().get_create_total_angle(0) > finalangle)
	{
           r.driveDirect(speedneg, speed_int);
        }
    }
    
    public boolean IsLeftBumperTriggered(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_lbump(lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
   
    public boolean IsRightBumperTriggered(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_rbump(lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public boolean IsCenterWheelTriggered(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_cwdrop (lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public boolean IsLeftWheelTriggered(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_lwdrop(lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public boolean IsRightWheelTriggered(double lag)
    {
        float lag1 = (float)lag;
        int value = Device.getLowCreateController().get_create_rwdrop (lag1);
        if (value == 0)
            return false;
        else
            return true;
    }
    
    public void TurnClockwise(double speed)
    {
        int speed_int = (int)(speed * 500);
        r.spinCW(speed_int);
    }
    
    public void TurnCounterClockwise(double speed)
    {
        int speed_int = (int)(speed * 500);
        r.spinCCW(speed_int);
    }
    
    public boolean IsLeftSensorTriggered()
    {
        //c.getLeftCliff()
        if ( Device.getLowCreateController().get_create_lcliff(0.1f) == 1)
            return true;
        else
            return false;
    }
    
    public boolean IsRightSensorTriggered()
    {
        //c.getRightCliff();
        if (Device.getLowCreateController().get_create_rcliff(0.1f) == 1)
            return true;
        else
            return false;
    }
    
    public boolean IsLeftFrontSensorTriggered()
    {
        //c.getLeftFrontCliff()
        if (Device.getLowCreateController().get_create_lfcliff(0.1f) == 1)
            return true;
        else
            return false;
    }
    
    public boolean IsRightFrontSensorTriggered()
    {
        //c.getRightFrontCliff();
        if ( Device.getLowCreateController().get_create_rfcliff(0.1f) == 1)
            return true;
        else
            return false;
    }
    
    public int GetTotalAngle()
    {
       return Device.getLowCreateController().get_create_total_angle(0);
    }
    
    public void SetTotalAngle(int angle)
    {
       Device.getLowCreateController().set_create_total_angle(angle);
    }
    
    public double GetTotalDistance()
    {
       double distance = (double) (r.getDistance()/1000);
       return distance;
    }
      
    public void SetTotalDistance(double distance)
    {
       int distance_int = (int)(distance * 1000); 
       Device.getLowCreateController().set_create_distance(distance_int);
    }
    
    public void RunDemo(int demo)
    {
        r.demo(demo);
    }
    
    public double GetMaximumSpeed()
    {
        return 0.5;
    }
    
    public void TurnOff()
    {
        r.setMode(Create.Mode.Off);
    }

    public void TurnSafety(boolean on)
    {
        if (on == true)
            r.setMode(Create.Mode.Safe);
        else
            r.setMode(Create.Mode.Full);
    }
    
    public int GetMode()
    {
        return Device.getLowCreateController().get_create_mode(0.1f);
    }
    
    public void IsWallDetected(double lag)
    {
        float lag_float = (float) lag;
        Device.getLowCreateController().get_create_wall(lag_float);
    }
    
    public double GetSpeed(double lag) 
    {
        float lag_float = (float) lag;
        int speed_int = Device.getLowCreateController().get_create_requested_velocity(lag_float);
        double speed = (double)(speed_int/500);
        return speed;
    }
    
    public double GetRightWheelSpeed(double lag) 
    {
        float lag_float = (float) lag;
        int rspeed_int = Device.getLowCreateController().get_create_requested_right_velocity(lag_float);
        double rspeed = (double)(rspeed_int/500);
        return rspeed;
    }
    
    public double GetLeftWheelSpeed(double lag) 
    {
        float lag_float = (float) lag;
        int lspeed_int = Device.getLowCreateController().get_create_requested_left_velocity(lag_float);
        double lspeed = (double)(lspeed_int/500);
        return lspeed;
    }
    
    public int GetRightSensorValue()
    {
        return Device.getLowCreateController().get_create_rcliff_amt(0.1f);
    }
    
    public int GetRightFrontSensorValue()
    {
        return Device.getLowCreateController().get_create_rcliff_amt(0.1f);
    }
    
    public int GetLeftSensorValue()
    {
        return Device.getLowCreateController().get_create_rcliff_amt(0.1f);
    }
    
    public int GetLeftFrontSensorValue()
    {
        return Device.getLowCreateController().get_create_rcliff_amt(0.1f);
    }
}
    
      /* public void SetAdvanceLed(boolean on)
    {
       r.advanceLed(on);
    }
        
    public void SetPowerLed(int color, int brightness)
    {
        r.powerLed(color, brightness);
    }
    
    public void SetPlayLed(boolean on)
    {
        r.playLed(on);
    }
    
    public void PlaySong(int num)
    {
        r.playSong(num);
    }
    
    public void LoadSong(int num)
    {
        r.loadSong(num);
    }
    
    //public void SetMode(Mode m)
    
    public void SetMode(int mode)
    {
        if (mode == 0)
            r.setMode(Create.Mode.Off);
        if (mode == 1)
            r.setMode(Create.Mode.Passive);
            //Device.getLowCreateController().create_passive();
        if (mode == 2)
            r.setMode(Create.Mode.Safe);
            //Device.getLowCreateController().create_safe();
        if (mode == 3)
            r.setMode(Create.Mode.Full);
            //Device.getLowCreateController().create_full();
    }
    
    public int GetMode()
    {
        int cmode = 0;
        cbccore.create.Create.Mode mode = r.getMode();
        
        if (mode == Create.Mode.Off)
            cmode = 0;
        if (mode == Create.Mode.Passive)
            cmode = 1;
        if (mode == Create.Mode.Safe)
            cmode =  2;
        if (mode == Create.Mode.Full)
            cmode = 3;
        
        return cmode;
    }*/
    
    
        /*int angle = (int)(turn * 360);
        int finalangle = r.getAngle() + angle;
        if(finalangle > 359)
        {
            finalangle = finalangle - 359;
        } 
        int speedneg = speed * -1;
        while (r.getAngle() != finalangle)
	{
           r.driveDirect(speed, speedneg);
        }*/
        /*int angle = (int)(turn * 360);
        int finalangle = Device.getLowCreateController().get_create_total_angle(0f) + angle;
        int speedneg = speed * -1;
        while (Device.getLowCreateController().get_create_total_angle(0f) < finalangle)
	{
           r.driveDirect(speed, speedneg);
        }*/
    
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