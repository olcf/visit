// ***************************************************************************
//
// Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
// Produced at the Lawrence Livermore National Laboratory
// LLNL-CODE-400142
// All rights reserved.
//
// This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
// full copyright notice is contained in the file COPYRIGHT located at the root
// of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
//
// Redistribution  and  use  in  source  and  binary  forms,  with  or  without
// modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of  source code must  retain the above  copyright notice,
//    this list of conditions and the disclaimer below.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
//    documentation and/or other materials provided with the distribution.
//  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
// ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
// LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
// DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
// SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
// CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
// OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ***************************************************************************

package llnl.visit;


// ****************************************************************************
// Class: AppearanceAttributes
//
// Purpose:
//    This class contains the GUI/viewer appearance attributes.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Tue Jan 15 14:07:42 PST 2008
//
// Modifications:
//   
// ****************************************************************************

public class AppearanceAttributes extends AttributeSubject
{
    public AppearanceAttributes()
    {
        super(5);

        background = new String("#c0c0c0");
        foreground = new String("#000000");
        fontName = new String("Helvetica,12,-1,5,50,0,0,0,0,0");
        style = new String("motif");
        orientation = 0;
    }

    public AppearanceAttributes(AppearanceAttributes obj)
    {
        super(5);

        background = new String(obj.background);
        foreground = new String(obj.foreground);
        fontName = new String(obj.fontName);
        style = new String(obj.style);
        orientation = obj.orientation;

        SelectAll();
    }

    public boolean equals(AppearanceAttributes obj)
    {
        // Create the return value
        return ((background == obj.background) &&
                (foreground == obj.foreground) &&
                (fontName == obj.fontName) &&
                (style == obj.style) &&
                (orientation == obj.orientation));
    }

    // Property setting methods
    public void SetBackground(String background_)
    {
        background = background_;
        Select(0);
    }

    public void SetForeground(String foreground_)
    {
        foreground = foreground_;
        Select(1);
    }

    public void SetFontName(String fontName_)
    {
        fontName = fontName_;
        Select(2);
    }

    public void SetStyle(String style_)
    {
        style = style_;
        Select(3);
    }

    public void SetOrientation(int orientation_)
    {
        orientation = orientation_;
        Select(4);
    }

    // Property getting methods
    public String GetBackground() { return background; }
    public String GetForeground() { return foreground; }
    public String GetFontName() { return fontName; }
    public String GetStyle() { return style; }
    public int    GetOrientation() { return orientation; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(background);
        if(WriteSelect(1, buf))
            buf.WriteString(foreground);
        if(WriteSelect(2, buf))
            buf.WriteString(fontName);
        if(WriteSelect(3, buf))
            buf.WriteString(style);
        if(WriteSelect(4, buf))
            buf.WriteInt(orientation);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetBackground(buf.ReadString());
                break;
            case 1:
                SetForeground(buf.ReadString());
                break;
            case 2:
                SetFontName(buf.ReadString());
                break;
            case 3:
                SetStyle(buf.ReadString());
                break;
            case 4:
                SetOrientation(buf.ReadInt());
                break;
            }
        }
    }


    // Attributes
    private String background;
    private String foreground;
    private String fontName;
    private String style;
    private int    orientation;
}

