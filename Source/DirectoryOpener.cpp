/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DirectoryOpener.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DirectoryOpener::DirectoryOpener ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label.reset (new juce::Label ("new label",
                                  TRANS("Input File")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (26, 24, 80, 24);

    fileBrowse.reset (new juce::TextButton ("fileBrowse"));
    addAndMakeVisible (fileBrowse.get());
    fileBrowse->setButtonText (TRANS("Browse"));
    fileBrowse->addListener (this);

    fileBrowse->setBounds (32, 96, 150, 24);

    filePath.reset (new juce::TextEditor ("filePath"));
    addAndMakeVisible (filePath.get());
    filePath->setMultiLine (false);
    filePath->setReturnKeyStartsNewLine (false);
    filePath->setReadOnly (false);
    filePath->setScrollbarsShown (true);
    filePath->setCaretVisible (true);
    filePath->setPopupMenuEnabled (true);
    filePath->setText (juce::String());

    filePath->setBounds (32, 56, 416, 24);

    label2.reset (new juce::Label ("new label",
                                   TRANS("Folder to Process")));
    addAndMakeVisible (label2.get());
    label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (juce::Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label2->setBounds (32, 160, 150, 24);

    folderPath.reset (new juce::TextEditor ("folderPath"));
    addAndMakeVisible (folderPath.get());
    folderPath->setMultiLine (false);
    folderPath->setReturnKeyStartsNewLine (false);
    folderPath->setReadOnly (false);
    folderPath->setScrollbarsShown (true);
    folderPath->setCaretVisible (true);
    folderPath->setPopupMenuEnabled (true);
    folderPath->setText (juce::String());

    folderPath->setBounds (32, 192, 408, 24);

    folderBrowse.reset (new juce::TextButton ("folderBrowse"));
    addAndMakeVisible (folderBrowse.get());
    folderBrowse->setButtonText (TRANS("Browse"));
    folderBrowse->addListener (this);

    folderBrowse->setBounds (32, 240, 150, 24);

    btnProcess.reset (new juce::TextButton ("btnProcess"));
    addAndMakeVisible (btnProcess.get());
    btnProcess->setButtonText (TRANS("Process"));
    btnProcess->addListener (this);

    btnProcess->setBounds (32, 296, 150, 24);


    //[UserPreSize]
    captions.clear();
    
    filePath->setText("");
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DirectoryOpener::~DirectoryOpener()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    fileBrowse = nullptr;
    filePath = nullptr;
    label2 = nullptr;
    folderPath = nullptr;
    folderBrowse = nullptr;
    btnProcess = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DirectoryOpener::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DirectoryOpener::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DirectoryOpener::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == fileBrowse.get())
    {
        //[UserButtonCode_fileBrowse] -- add your button handler code here..
        fileBrowser();
        //[/UserButtonCode_fileBrowse]
    }
    else if (buttonThatWasClicked == folderBrowse.get())
    {
        //[UserButtonCode_folderBrowse] -- add your button handler code here..
        folderBrowser();
        //[/UserButtonCode_folderBrowse]
    }
    else if (buttonThatWasClicked == btnProcess.get())
    {
        //[UserButtonCode_btnProcess] -- add your button handler code here..
        process();
        //[/UserButtonCode_btnProcess]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DirectoryOpener::folderBrowser()
{
    juce::FileChooser myChooser("Choose a directory...", juce::File("/Users/swarsys/Documents/GitHub"), "*.cpp,*.txt,*.h", true);
    
    if (myChooser.browseForDirectory())
    {
        auto result = myChooser.getURLResult();
        folderPath->setText (result.getLocalFile().getFullPathName());
    }
}

void DirectoryOpener::fileBrowser()
{
    juce::FileChooser myChooser ("Please select the file you want to load...",
                                 juce::File("/Users/swarsys/Documents/GitHub"),
                                 "*.cpp,*.txt,*.h");
    if (myChooser.browseForFileToOpen())
    {
        juce::File ourFile (myChooser.getResult());
        filePath->setText (ourFile.getFullPathName());
        
        // import captions already parsed
        captions.clear();
        
        juce::StringArray lines;
        ourFile.readLines(lines);
        
        for (juce::String line : lines) {
            int p = line.indexOf(" =");
            //jassert(p > 0);
            if (p > 0) {
                captions.add(line.substring(0, p));
            }
        }
    }
}

void DirectoryOpener::process()
{
    if (folderPath->getText().isNotEmpty())
    {
        processFolder();
    }

}

void DirectoryOpener::processFolder()
{
    juce::File f(filePath->getText());
    if( !f.existsAsFile() )
    {
        auto result = f.create();
        if( !result.wasOk() )
        {
            DBG( "failed creating file!" );
            jassertfalse; //pause so we can see the error message
            return;  //bail
        }
    }

    juce::DirectoryIterator itr(folderPath->getText(), true,"*.cpp, *.h, *.txt");
    while (itr.next())
    {
        int fir = 0, sec = 0;
        juce::File theFileItFound (itr.getFile());
        juce::String wholeFile = theFileItFound.loadFileAsString();
        fir = wholeFile.indexOf("TRANS(");
        while (fir > 1)
        {
            sec = wholeFile.indexOf(fir,")");
            juce::String fetched = wholeFile.substring(fir + 6, sec ).trim();
            while (!fetched.endsWith("\"")) {
                sec = wholeFile.indexOf(sec + 1, ")");
                jassert(sec > fir);
                fetched = wholeFile.substring(fir + 6, sec ).trim();
            }
            if (!captions.contains(fetched))
            {
                captions.add(fetched);
                
                f.appendText(fetched + " = " + fetched + "\n");
            }
            fir = wholeFile.indexOf(sec, "TRANS(");
        }
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DirectoryOpener" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="ae6304902a0d0a15" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="26 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Input File" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="fileBrowse" id="8178dc14ae8cf506" memberName="fileBrowse"
              virtualName="" explicitFocusOrder="0" pos="32 96 150 24" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="filePath" id="1950047376058bda" memberName="filePath" virtualName=""
              explicitFocusOrder="0" pos="32 56 416 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="c3d30e54c478b91d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="32 160 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Folder to Process" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="folderPath" id="61e01c3abafb8ba4" memberName="folderPath"
              virtualName="" explicitFocusOrder="0" pos="32 192 408 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="folderBrowse" id="30caf8f36f6a13a" memberName="folderBrowse"
              virtualName="" explicitFocusOrder="0" pos="32 240 150 24" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="btnProcess" id="c3c9bb914095809" memberName="btnProcess"
              virtualName="" explicitFocusOrder="0" pos="32 296 150 24" buttonText="Process"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

