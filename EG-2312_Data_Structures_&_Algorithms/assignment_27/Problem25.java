//---------------------------------------------------------
// Dr. Art Hanna
// Problem #25
// Problem25.java
//---------------------------------------------------------
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.*;

//---------------------------------------------------------
public class Problem25
//---------------------------------------------------------
{
   public static void main(String[] args)
   {
      GUI gui = new GUI();

      gui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      gui.setSize(800,800);
      gui.setVisible(true);
   }
}

//---------------------------------------------------------
class POINT
//---------------------------------------------------------
{
   public int x;
   public int y;
}

//---------------------------------------------------------
class SEGMENT
//---------------------------------------------------------
{
   public POINT p1;
   public POINT p2;
}

//---------------------------------------------------------
class GUI extends JFrame
//---------------------------------------------------------
{
   final int M = 10;
   final int R = 10;
   final int W = 700;
   final int H = 700;

   MyPanel drawingPanel;
   double SIZEX;
   double SIZEY;
   int n;
   int s;
   ArrayList<POINT> points = new ArrayList<POINT>();
   ArrayList<SEGMENT> segments = new ArrayList<SEGMENT>();

   //-------------------------------------------------------
   public GUI()
   //-------------------------------------------------------
   {
      super("Chapter #25 (red points and green convex hull)");

//-------------------------------------
// Input file record formats are...
//           11111111112222
// 012345678901234567890123
// XXX.X XXX.X              SIZEX SIZEY
// XXXX                     n
// XXX.X XXX.X              x y         (1st point's coordinates)
// ...                      x y         (n-1) point records
// XXXX                     s
// XXX.X XXX.X  XXX.X XXX.X x1 y1 x2 y2 (1st segment's 2 end-points)
// ...                      x1 y1 x2 y2 (s-1) segment records
//-------------------------------------

      try
      {
         FileReader reader = new FileReader("Problem25.out");
         BufferedReader bufferedReader = new BufferedReader(reader);
      
         String line;

      // Input SIZEX,SIZEY
         line = bufferedReader.readLine();
         SIZEX = Double.parseDouble(line.substring( 0, 4).trim());
         SIZEY = Double.parseDouble(line.substring( 6,10).trim());

      // Input n
         line = bufferedReader.readLine();
         n = Integer.parseInt(line.substring( 0, 4).trim());

      // Input points[i], i in [ 1,n ]
         for (int i = 1; i <= n; i++)
         {
            POINT pi = new POINT();

            line = bufferedReader.readLine();
            pi.x = TranslateX(Double.parseDouble(line.substring( 0, 4).trim()));
            pi.y = TranslateY(Double.parseDouble(line.substring( 6,10).trim()));
            points.add(pi);
         }

      // Input s
         line = bufferedReader.readLine();
         s = Integer.parseInt(line.substring( 0, 4).trim());

      // Input segments[i], i in [ 1,s ]
         for (int i = 1; i <= s; i++)
         {
            SEGMENT si = new SEGMENT();
            si.p1 = new POINT();
            si.p2 = new POINT();

            line = bufferedReader.readLine();
            si.p1.x = TranslateX(Double.parseDouble(line.substring( 0, 4).trim()));
            si.p1.y = TranslateY(Double.parseDouble(line.substring( 6,10).trim()));
            si.p2.x = TranslateX(Double.parseDouble(line.substring(13,17).trim()));
            si.p2.y = TranslateY(Double.parseDouble(line.substring(19,23).trim()));
            segments.add(si);
         }
         reader.close();
      
      } 
      catch (IOException e)
      {
         e.printStackTrace();
      }

      setLayout( null );

      drawingPanel = new MyPanel();
      drawingPanel.setBounds(M,M,W+2*M,H+2*M);
      add(drawingPanel);
   }

   //-------------------------------------------------------
   private int TranslateX(double x)
   //-------------------------------------------------------
   {
      return( (int) (M + x*(W/SIZEX)) );
   }

   //-------------------------------------------------------
   private int TranslateY(double y)
   //-------------------------------------------------------
   {
      return( (int) (M + (SIZEY-y)*(H/SIZEY)) );
   }

   //-------------------------------------------------------
   class MyPanel extends JPanel
   //-------------------------------------------------------
   {
      public void paintComponent(Graphics g)
      {
         super.paintComponent(g);

      // Draw red points
         g.setColor(Color.red);
         for (int i = 1; i <= n; i++)
         {
            POINT pi = points.get(i-1);

            g.fillOval(pi.x-R/2,pi.y-R/2,R,R);
         }

      // Draw green segments
         g.setColor(Color.green);
         for (int i = 1; i <= s; i++)
         {
            SEGMENT si = segments.get(i-1);

            g.drawLine(si.p1.x,si.p1.y,si.p2.x,si.p2.y);
         }
      }
   }
}
