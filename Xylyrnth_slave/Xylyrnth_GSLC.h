//<File !Start!>
// FILE: [Xylyrnth_GSLC.h]
// Created by GUIslice Builder version: [0.17.b34]
//
// GUIslice Builder Generated GUI Framework File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<File !End!>

#ifndef _GUISLICE_GEN_H
#define _GUISLICE_GEN_H

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "GUIslice.h"
#include "GUIslice_drv.h"

// Include any extended elements
//<Includes !Start!>
// Include extended elements
#include "elem/XRingGauge.h"
#include "elem/XSlider.h"
#include "elem/XTogglebtn.h"
//<Includes !End!>

// ------------------------------------------------
// Headers and Defines for fonts
// Note that font files are located within the Adafruit-GFX library folder:
// ------------------------------------------------
//<Fonts !Start!>
#if !defined(DRV_DISP_TFT_ESPI)
  #error E_PROJECT_OPTIONS tab->Graphics Library should be Adafruit_GFX
#endif
#include <TFT_eSPI.h>
#include "Seven_Segment18pt7b.h"
#include "Seven_Segment20pt7b.h"
//<Fonts !End!>

// ------------------------------------------------
// Defines for resources
// ------------------------------------------------
//<Resources !Start!>
//<Resources !End!>

// ------------------------------------------------
// Enumerations for pages, elements, fonts, images
// ------------------------------------------------
//<Enum !Start!>
enum {E_PG_MAIN,E_PG2,E_PG3,E_PG4,E_PG5};
enum {E_ELEM_BOX1,E_ELEM_BOX2,E_ELEM_BOX3,E_ELEM_BTN_FREQUENCY
      ,E_ELEM_BTN_FREQUENCY_RTN,E_ELEM_BTN_HAPTICS
      ,E_ELEM_BTN_HAPTICS_RTN,E_ELEM_BTN_SETTINGS
      ,E_ELEM_BTN_SETTINGS_RTN,E_ELEM_BTN_THRESHOLD
      ,E_ELEM_BTN_THRESHOLD_RTN,E_ELEM_FREQUENCY,E_ELEM_RINGGAUGE2
      ,E_ELEM_SLIDER_FREQUENCY,E_ELEM_SLIDER_HAPTICS
      ,E_ELEM_SLIDER_THRESHOLD,E_ELEM_TEXT22,E_ELEM_TEXT23
      ,E_ELEM_TEXT24,E_ELEM_TEXT9,E_ELEM_TEXT_ALERT
      ,E_ELEM_TEXT_FREQUENCY_COUNT,E_ELEM_TEXT_HZ,E_ELEM_THRESHOLD
      ,E_ELEM_TITLE_FREQUENCY,E_ELEM_TITLE_HAPTICS
      ,E_ELEM_TITLE_SETTINGS,E_ELEM_TITLE_THRESHOLD
      ,E_ELEM_TOGGLE_HAPTICS};
// Must use separate enum for fonts with MAX_FONT at end to use gslc_FontSet.
enum {E_BUILTIN10X16,E_BUILTIN15X24,E_BUILTIN20X32,E_BUILTIN5X8
      ,E_SEVEN_SEGMENT18,E_SEVEN_SEGMENT20,MAX_FONT};
//<Enum !End!>

// ------------------------------------------------
// Instantiate the GUI
// ------------------------------------------------

// ------------------------------------------------
// Define the maximum number of elements and pages
// ------------------------------------------------
//<ElementDefines !Start!>
#define MAX_PAGE                5

#define MAX_ELEM_PG_MAIN 5 // # Elems total on page
#define MAX_ELEM_PG_MAIN_RAM MAX_ELEM_PG_MAIN // # Elems in RAM

#define MAX_ELEM_PG2 5 // # Elems total on page
#define MAX_ELEM_PG2_RAM MAX_ELEM_PG2 // # Elems in RAM

#define MAX_ELEM_PG3 6 // # Elems total on page
#define MAX_ELEM_PG3_RAM MAX_ELEM_PG3 // # Elems in RAM

#define MAX_ELEM_PG4 6 // # Elems total on page
#define MAX_ELEM_PG4_RAM MAX_ELEM_PG4 // # Elems in RAM

#define MAX_ELEM_PG5 7 // # Elems total on page
#define MAX_ELEM_PG5_RAM MAX_ELEM_PG5 // # Elems in RAM
//<ElementDefines !End!>

// ------------------------------------------------
// Create element storage
// ------------------------------------------------
gslc_tsGui                      m_gui;
gslc_tsDriver                   m_drv;
gslc_tsFont                     m_asFont[MAX_FONT];
gslc_tsPage                     m_asPage[MAX_PAGE];

//<GUI_Extra_Elements !Start!>
gslc_tsElem                     m_asPage1Elem[MAX_ELEM_PG_MAIN_RAM];
gslc_tsElemRef                  m_asPage1ElemRef[MAX_ELEM_PG_MAIN];
gslc_tsElem                     m_asPage2Elem[MAX_ELEM_PG2_RAM];
gslc_tsElemRef                  m_asPage2ElemRef[MAX_ELEM_PG2];
gslc_tsElem                     m_asPage3Elem[MAX_ELEM_PG3_RAM];
gslc_tsElemRef                  m_asPage3ElemRef[MAX_ELEM_PG3];
gslc_tsElem                     m_asPage4Elem[MAX_ELEM_PG4_RAM];
gslc_tsElemRef                  m_asPage4ElemRef[MAX_ELEM_PG4];
gslc_tsElem                     m_asPage5Elem[MAX_ELEM_PG5_RAM];
gslc_tsElemRef                  m_asPage5ElemRef[MAX_ELEM_PG5];
gslc_tsXRingGauge               m_sXRingGauge2;
gslc_tsXSlider                  m_sXSlider2;
gslc_tsXSlider                  m_sXSlider3;
gslc_tsXTogglebtn               m_asXToggle1;
gslc_tsXSlider                  m_sXSlider5;

#define MAX_STR                 100

//<GUI_Extra_Elements !End!>

// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Element References for direct access
//<Extern_References !Start!>
extern gslc_tsElemRef* m_pElemAlertTxt;
extern gslc_tsElemRef* m_pElemOutTxtFreq;
extern gslc_tsElemRef* m_pElemXRingGauge2;
extern gslc_tsElemRef* m_pFrequency;
extern gslc_tsElemRef* m_pHapticDuration;
extern gslc_tsElemRef* m_pSliderFrequency;
extern gslc_tsElemRef* m_pSliderHaptics;
extern gslc_tsElemRef* m_pSliderThreshold;
extern gslc_tsElemRef* m_pThreshold;
extern gslc_tsElemRef* m_pToggleHaptics;
//<Extern_References !End!>

// Define debug message function
static int16_t DebugOut(char ch);

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY);
bool CbCheckbox(void* pvGui, void* pvElemRef, int16_t nSelId, bool bState);
bool CbDrawScanner(void* pvGui,void* pvElemRef,gslc_teRedrawType eRedraw);
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbListbox(void* pvGui, void* pvElemRef, int16_t nSelId);
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos);
bool CbSpinner(void* pvGui, void *pvElemRef, int16_t nState, void* pvData);
bool CbTickScanner(void* pvGui,void* pvScope);

// ------------------------------------------------
// Create page elements
// ------------------------------------------------
void InitGUIslice_gen()
{
  gslc_tsElemRef* pElemRef = NULL;

  if (!gslc_Init(&m_gui,&m_drv,m_asPage,MAX_PAGE,m_asFont,MAX_FONT)) { return; }

  // ------------------------------------------------
  // Load Fonts
  // ------------------------------------------------
//<Load_Fonts !Start!>
    if (!gslc_FontSet(&m_gui,E_BUILTIN10X16,GSLC_FONTREF_PTR,NULL,2)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN15X24,GSLC_FONTREF_PTR,NULL,3)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN20X32,GSLC_FONTREF_PTR,NULL,4)) { return; }
    if (!gslc_FontSet(&m_gui,E_BUILTIN5X8,GSLC_FONTREF_PTR,NULL,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_SEVEN_SEGMENT18,GSLC_FONTREF_PTR,&Seven_Segment18pt7b,1)) { return; }
    if (!gslc_FontSet(&m_gui,E_SEVEN_SEGMENT20,GSLC_FONTREF_PTR,&Seven_Segment20pt7b,1)) { return; }
//<Load_Fonts !End!>

//<InitGUI !Start!>
  gslc_PageAdd(&m_gui,E_PG_MAIN,m_asPage1Elem,MAX_ELEM_PG_MAIN_RAM,m_asPage1ElemRef,MAX_ELEM_PG_MAIN);
  gslc_PageAdd(&m_gui,E_PG2,m_asPage2Elem,MAX_ELEM_PG2_RAM,m_asPage2ElemRef,MAX_ELEM_PG2);
  gslc_PageAdd(&m_gui,E_PG3,m_asPage3Elem,MAX_ELEM_PG3_RAM,m_asPage3ElemRef,MAX_ELEM_PG3);
  gslc_PageAdd(&m_gui,E_PG4,m_asPage4Elem,MAX_ELEM_PG4_RAM,m_asPage4ElemRef,MAX_ELEM_PG4);
  gslc_PageAdd(&m_gui,E_PG5,m_asPage5Elem,MAX_ELEM_PG5_RAM,m_asPage5ElemRef,MAX_ELEM_PG5);

  // NOTE: The current page defaults to the first page added. Here we explicitly
  //       ensure that the main page is the correct page no matter the add order.
  gslc_SetPageCur(&m_gui,E_PG_MAIN);
  
  // Set Background to a flat color
  gslc_SetBkgndColor(&m_gui,GSLC_COL_RED_DK2);

  // -----------------------------------
  // PAGE: E_PG_MAIN
  
  
  // create E_ELEM_BTN_SETTINGS button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_SETTINGS,E_PG_MAIN,
    (gslc_tsRect){60,270,120,40},(char*)"Settings",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);

  // Create ring gauge E_ELEM_RINGGAUGE2 
  static char m_sRingText2[11] = "";
  pElemRef = gslc_ElemXRingGaugeCreate(&m_gui,E_ELEM_RINGGAUGE2,E_PG_MAIN,&m_sXRingGauge2,
          (gslc_tsRect){25,25,190,190},
          (char*)m_sRingText2,11,E_BUILTIN5X8);
  gslc_ElemXRingGaugeSetValRange(&m_gui, pElemRef, 0, 22000);
  gslc_ElemXRingGaugeSetVal(&m_gui, pElemRef, 0); // Set initial value
  gslc_ElemXRingGaugeSetThickness(&m_gui,pElemRef, 20);
  gslc_ElemXRingGaugeSetAngleRange(&m_gui,pElemRef, 235, 250, true);
  gslc_ElemXRingGaugeSetColorActiveFlat(&m_gui,pElemRef, GSLC_COL_GREEN_DK2);
  gslc_ElemXRingGaugeSetColorInactive(&m_gui,pElemRef, GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_GREEN_DK2,GSLC_COL_BLACK);
  m_pElemXRingGauge2 = pElemRef;
  
  // Create E_ELEM_TEXT_FREQUENCY_COUNT runtime modifiable text
  static char m_sDisplayText5[8] = "0";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_FREQUENCY_COUNT,E_PG_MAIN,(gslc_tsRect){59,93,121,33},
    (char*)m_sDisplayText5,8,E_SEVEN_SEGMENT18);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_RED_DK2,GSLC_COL_BLACK);
  m_pElemOutTxtFreq = pElemRef;
  
  // Create E_ELEM_TEXT_HZ text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_HZ,E_PG_MAIN,(gslc_tsRect){102,145,36,24},
    (char*)"Hz",0,E_BUILTIN15X24);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // Create E_ELEM_TEXT_ALERT runtime modifiable text
  static char m_sDisplayText25[6] = " ";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT_ALERT,E_PG_MAIN,(gslc_tsRect){60,201,120,32},
    (char*)m_sDisplayText25,6,E_BUILTIN20X32);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  m_pElemAlertTxt = pElemRef;

  // -----------------------------------
  // PAGE: E_PG2
  
  
  // Create E_ELEM_TITLE_SETTINGS text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_SETTINGS,E_PG2,(gslc_tsRect){24,20,192,32},
    (char*)"Settings",0,E_BUILTIN20X32);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // create E_ELEM_BTN_THRESHOLD button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_THRESHOLD,E_PG2,
    (gslc_tsRect){60,91,120,40},(char*)"Threshold",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // create E_ELEM_BTN_FREQUENCY button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_FREQUENCY,E_PG2,
    (gslc_tsRect){60,151,120,40},(char*)"Frequency",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // create E_ELEM_BTN_HAPTICS button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_HAPTICS,E_PG2,
    (gslc_tsRect){60,211,120,40},(char*)"Haptics",0,E_BUILTIN10X16,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // create E_ELEM_BTN_SETTINGS_RTN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_SETTINGS_RTN,E_PG2,
    (gslc_tsRect){90,290,60,20},(char*)"Return",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);

  // -----------------------------------
  // PAGE: E_PG3
  
  
  // Create E_ELEM_TITLE_THRESHOLD text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_THRESHOLD,E_PG3,(gslc_tsRect){12,29,216,32},
    (char*)"Threshold",0,E_BUILTIN20X32);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_TEAL,GSLC_COL_BLACK);
  
  // create E_ELEM_BTN_THRESHOLD_RTN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_THRESHOLD_RTN,E_PG3,
    (gslc_tsRect){172,290,60,20},(char*)"Back",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
   
  // Create E_ELEM_BOX1 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX1,E_PG3,(gslc_tsRect){20,205,200,38});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_WHITE,GSLC_COL_WHITE);

  // Create slider E_ELEM_SLIDER_THRESHOLD 
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_ELEM_SLIDER_THRESHOLD,E_PG3,&m_sXSlider2,
          (gslc_tsRect){30,209,180,30},0,140,40,10,false);
  gslc_ElemXSliderSetStyle(&m_gui,pElemRef,false,GSLC_COL_TEAL,10,10,GSLC_COL_BLACK);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_WHITE,GSLC_COL_BLACK);
  m_pSliderThreshold = pElemRef;
  
  // Create E_ELEM_THRESHOLD runtime modifiable text
  static char m_sDisplayText7[4] = "40";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_THRESHOLD,E_PG3,(gslc_tsRect){91,114,62,39},
    (char*)m_sDisplayText7,4,E_SEVEN_SEGMENT20);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_RED_DK2,GSLC_COL_BLACK);
  m_pThreshold = pElemRef;
  
  // Create E_ELEM_TEXT22 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT22,E_PG3,(gslc_tsRect){160,124,36,24},
    (char*)"dB",0,E_BUILTIN15X24);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: E_PG4
  
  
  // Create E_ELEM_TITLE_FREQUENCY text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_FREQUENCY,E_PG4,(gslc_tsRect){12,28,216,32},
    (char*)"Frequency",0,E_BUILTIN20X32);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // create E_ELEM_BTN_FREQUENCY_RTN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_FREQUENCY_RTN,E_PG4,
    (gslc_tsRect){170,290,60,20},(char*)"Back",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
   
  // Create E_ELEM_BOX2 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX2,E_PG4,(gslc_tsRect){20,205,200,38});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_WHITE,GSLC_COL_WHITE);

  // Create slider E_ELEM_SLIDER_FREQUENCY 
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_ELEM_SLIDER_FREQUENCY,E_PG4,&m_sXSlider3,
          (gslc_tsRect){30,209,180,30},0,22,2,10,false);
  gslc_ElemXSliderSetStyle(&m_gui,pElemRef,false,GSLC_COL_TEAL,10,10,GSLC_COL_BLACK);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_WHITE,GSLC_COL_BLACK);
  m_pSliderFrequency = pElemRef;
  
  // Create E_ELEM_FREQUENCY runtime modifiable text
  static char m_sDisplayText8[3] = "2";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_FREQUENCY,E_PG4,(gslc_tsRect){103,117,35,39},
    (char*)m_sDisplayText8,3,E_SEVEN_SEGMENT20);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_RED_DK2,GSLC_COL_BLACK);
  m_pFrequency = pElemRef;
  
  // Create E_ELEM_TEXT23 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT23,E_PG4,(gslc_tsRect){154,126,54,24},
    (char*)"kHz",0,E_BUILTIN15X24);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);

  // -----------------------------------
  // PAGE: E_PG5
  
  
  // Create E_ELEM_TITLE_HAPTICS text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TITLE_HAPTICS,E_PG5,(gslc_tsRect){36,28,168,32},
    (char*)"Haptics",0,E_BUILTIN20X32);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  
  // create E_ELEM_BTN_HAPTICS_RTN button with text label
  pElemRef = gslc_ElemCreateBtnTxt(&m_gui,E_ELEM_BTN_HAPTICS_RTN,E_PG5,
    (gslc_tsRect){170,290,60,20},(char*)"Back",0,E_BUILTIN5X8,&CbBtnCommon);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_BLACK);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_WHITE,GSLC_COL_WHITE,GSLC_COL_GRAY_DK2);
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetFrameEn(&m_gui,pElemRef,false);
  
  // Create toggle button E_ELEM_TOGGLE_HAPTICS
  pElemRef = gslc_ElemXTogglebtnCreate(&m_gui,E_ELEM_TOGGLE_HAPTICS,E_PG5,&m_asXToggle1,
    (gslc_tsRect){182,84,35,20},GSLC_COL_WHITE,GSLC_COL_GREEN,GSLC_COL_RED,
    true,true,&CbBtnCommon);
  m_pToggleHaptics = pElemRef;
   
  // Create E_ELEM_BOX3 box
  pElemRef = gslc_ElemCreateBox(&m_gui,E_ELEM_BOX3,E_PG5,(gslc_tsRect){20,218,200,38});
  gslc_ElemSetRoundEn(&m_gui, pElemRef, true);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_WHITE,GSLC_COL_WHITE);

  // Create slider E_ELEM_SLIDER_HAPTICS 
  pElemRef = gslc_ElemXSliderCreate(&m_gui,E_ELEM_SLIDER_HAPTICS,E_PG5,&m_sXSlider5,
          (gslc_tsRect){30,222,180,30},0,10,1,10,false);
  gslc_ElemXSliderSetStyle(&m_gui,pElemRef,false,GSLC_COL_TEAL,10,10,GSLC_COL_BLACK);
  gslc_ElemXSliderSetPosFunc(&m_gui,pElemRef,&CbSlidePos);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_BLACK,GSLC_COL_WHITE,GSLC_COL_BLACK);
  m_pSliderHaptics = pElemRef;
  
  // Create E_ELEM_TEXT9 runtime modifiable text
  static char m_sDisplayText9[3] = "1";
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT9,E_PG5,(gslc_tsRect){102,133,35,37},
    (char*)m_sDisplayText9,3,E_SEVEN_SEGMENT20);
  gslc_ElemSetTxtAlign(&m_gui,pElemRef,GSLC_ALIGN_MID_MID);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
  gslc_ElemSetCol(&m_gui,pElemRef,GSLC_COL_GRAY,GSLC_COL_RED_DK2,GSLC_COL_BLACK);
  m_pHapticDuration = pElemRef;
  
  // Create E_ELEM_TEXT24 text label
  pElemRef = gslc_ElemCreateTxt(&m_gui,E_ELEM_TEXT24,E_PG5,(gslc_tsRect){155,141,54,24},
    (char*)"sec",0,E_BUILTIN15X24);
  gslc_ElemSetFillEn(&m_gui,pElemRef,false);
  gslc_ElemSetTxtCol(&m_gui,pElemRef,GSLC_COL_WHITE);
//<InitGUI !End!>

//<Startup !Start!>
  gslc_GuiRotate(&m_gui, 0);
//<Startup !End!>

}

#endif // end _GUISLICE_GEN_H
